/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "ScriptedGossip.h"
#include "MotionMaster.h"
#include "GameObject.h"
#include "Transport.h"
#include "DarkmoonIsland.h"
#include "AchievementMgr.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "DarkmoonIsland.h"
#include "Player.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "WorldSession.h"
#include "Item.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "GameEventMgr.h"
#include "AchievementPackets.h"
#include "DB2HotfixGenerator.h"
#include "DB2Stores.h"
#include "CellImpl.h"
#include "ChatTextBuilder.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Language.h"
#include "Mail.h"
#include "ObjectMgr.h"
#include "RBAC.h"
#include "StringConvert.h"
#include "World.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SharedDefines.h"
#include "ObjectAccessor.h"
#include "TemporarySummon.h"
#include <sstream>

enum JESSICA_GOSSIP
{
    GOSSIP_BUTTON_1 = 13012,
    GOSSIP_BUTTON_1_ID = 0,
    GOSSIP_BUTTON_2 = 13012,
    GOSSIP_BUTTON_2_ID = 1,
    GOSSIP_BUTTON_3 = 13013,
    GOSSIP_BUTTON_3_ID = 0,
};

// 54485 - Jessica Rogers
class npc_jessica_rogers : public CreatureScript
{
public:
    npc_jessica_rogers() : CreatureScript("npc_jessica_rogers") { }

    struct npc_jessica_rogersAI : public ScriptedAI
    {
        npc_jessica_rogersAI(Creature* creature) : ScriptedAI(creature) { }

        bool OnGossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            AddGossipItemFor(player, GOSSIP_BUTTON_1, GOSSIP_BUTTON_1_ID, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 18284, me->GetGUID());

            if (player->GetQuestStatus(QUEST_TARGET_TURTLE) == QUEST_STATUS_INCOMPLETE)
            {
                AddGossipItemFor(player, GOSSIP_BUTTON_2, GOSSIP_BUTTON_2_ID, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                SendGossipMenuFor(player, 53027, me->GetGUID());
            }

            player->PlayerTalkClass->SendGossipMenu(player->GetGossipTextId(me), me->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);

            switch (action)
            {
            case GOSSIP_ACTION_INFO_DEF + 1:
                AddGossipItemFor(player, GOSSIP_BUTTON_3, GOSSIP_BUTTON_3_ID, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                if (player->HasItemCount(ITEM_DARKMOON_TOKEN))
                {
                    CloseGossipMenuFor(player);

                    player->DestroyItemCount(ITEM_DARKMOON_TOKEN, 1, true);
                    player->RemoveAurasByType(SPELL_AURA_MOUNTED);

                    player->AddAura(SPELL_RINGTOSS_ENABLE, player);
                    player->SetPower(POWER_ALTERNATE_POWER, 10);

                    return true;
                }
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                AddGossipItemFor(player, GOSSIP_BUTTON_1, GOSSIP_BUTTON_1_ID, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                AddGossipItemFor(player, GOSSIP_BUTTON_2, GOSSIP_BUTTON_2_ID, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                break;
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_jessica_rogersAI(creature);
    }
};

// spell - 101695
class spell_ring_toss : public SpellScriptLoader
{
public:
    spell_ring_toss() : SpellScriptLoader("spell_ring_toss") {}

    class spell_ring_toss_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ring_toss_SpellScript);

        SpellCastResult CheckRequirement()
        {
            if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Player* player = GetCaster()->ToPlayer();

            WorldLocation* loc = GetHitDest();

            Creature* dubenko = caster->FindNearestCreature(54490, 100.0f, true);

            if (dubenko && dubenko->IsWithinDist2d(loc, 1.2f))
            {
                if (dubenko->HasAura(SPELL_RINGTOSS_TURTLE_CIRCLE_1))
                {
                    if (dubenko->HasAura(SPELL_RINGTOSS_TURTLE_CIRCLE_2))
                        dubenko->CastSpell(dubenko, SPELL_RINGTOSS_TURTLE_CIRCLE_3, true);
                    else
                        dubenko->CastSpell(dubenko, SPELL_RINGTOSS_TURTLE_CIRCLE_2, true);
                }
                else
                    dubenko->CastSpell(dubenko, SPELL_RINGTOSS_TURTLE_CIRCLE_1, true);

                caster->CastSpell(dubenko, SPELL_RINGTOSS_HIT, false);
            }

            if (player)
            {
                if (player->GetReqKillOrCastCurrentCount(QUEST_TARGET_TURTLE, 54495) >= 3)
                    player->RemoveAurasDueToSpell(SPELL_RINGTOSS_ENABLE);
            }            
        }
                        

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_ring_toss_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnCheckCast += SpellCheckCastFn(spell_ring_toss_SpellScript::CheckRequirement);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_ring_toss_SpellScript();
    }
};

// at_target_turtle - 7338
class at_target_turtle : public AreaTriggerScript
{
public:
    at_target_turtle() : AreaTriggerScript("at_target_turtle") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
    {
        if (!player->IsGameMaster())
            player->CastSpell(player, 109972, true);
        return true;
    }
};

void AddSC_darkmoon_ring_toss()
{
    new npc_jessica_rogers();
	new spell_ring_toss();
	new at_target_turtle();
};
