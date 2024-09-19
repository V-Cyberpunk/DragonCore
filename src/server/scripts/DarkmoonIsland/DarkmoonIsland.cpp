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

// npc - 55089 55093 55397 55398 
class npc_fire_juggler_darkmoon : public CreatureScript
{
public:
    npc_fire_juggler_darkmoon() : CreatureScript("npc_fire_juggler_darkmoon") { }

    enum eNPC
    {
        SPELL_JUGGLE_TORCH_AURA = 46322, //  102905,
        EVENT_START_FIRE_JUGGLING = 101,
    };

    struct npc_fire_juggler_darkmoonAI : public ScriptedAI
    {
        npc_fire_juggler_darkmoonAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void Reset() override
        {
            events.Reset();
            events.ScheduleEvent(EVENT_START_FIRE_JUGGLING, 1s);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_FIRE_JUGGLING:
                {
                    if (!me->HasAura(SPELL_JUGGLE_TORCH_AURA))
                        me->AddAura(SPELL_JUGGLE_TORCH_AURA, me);
                    events.ScheduleEvent(EVENT_START_FIRE_JUGGLING, 3s);
                    break;
                }
                }
            }

            UpdateVictim();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_fire_juggler_darkmoonAI(creature);
    }
};

 // Whee! - 46668
class spell_darkmoon_carousel_whee : public SpellScriptLoader
{
public:
    spell_darkmoon_carousel_whee() : SpellScriptLoader("spell_darkmoon_carousel_whee") { }

    class spell_darkmoon_carousel_whee_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_darkmoon_carousel_whee_AuraScript);

        uint32 update;

        bool Validate(SpellInfo const* /*spell*/) override
        {
            update = 0;
            return true;
        }

        void OnUpdate(uint32 diff)
        {
            update += diff;

            if (update >= 5000)
            {
                if (Player* _player = GetCaster()->ToPlayer())
                {
                    if (Transport* transport = dynamic_cast<Transport*>(_player->GetTransport()))
                    {
                        if (transport->GetEntry() == GOB_DARKMOON_CAROUSEL)
                        {
                            if (Aura* aura = GetAura())
                            {
                                uint32 currentMaxDuration = aura->GetMaxDuration();
                                uint32 newMaxDurantion = currentMaxDuration + (5 * MINUTE * IN_MILLISECONDS);
                                newMaxDurantion = newMaxDurantion <= (60 * MINUTE * IN_MILLISECONDS) ? newMaxDurantion : (60 * MINUTE * IN_MILLISECONDS);

                                aura->SetMaxDuration(newMaxDurantion);
                                aura->SetDuration(newMaxDurantion);
                            }
                        }
                    }
                }

                update = 0;
            }
        }

        void Register() override
        {
            OnAuraUpdate += AuraUpdateFn(spell_darkmoon_carousel_whee_AuraScript::OnUpdate);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_darkmoon_carousel_whee_AuraScript();
    }
};

// To the Staging Area! - 101260
class spell_darkmoon_staging_area_teleport : public SpellScriptLoader
{
public:
    spell_darkmoon_staging_area_teleport() : SpellScriptLoader("spell_darkmoon_staging_area_teleport") { }

    class spell_darkmoon_staging_area_teleport_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_darkmoon_staging_area_teleport_SpellScript);

        bool Load() override
        {
            return GetCaster() != nullptr;
        }

        void RelocateDest(SpellEffIndex /*effIndex*/)
        {
            if (Player* caster = GetCaster()->ToPlayer())
            {
                switch (caster->GetMapId())
                {
                    case 974: //Darkmoon Island
                        if (caster->GetTeamId() == TEAM_HORDE)
                            GetHitDest()->WorldRelocate(WorldLocation(1, -1454.415894f, 207.967484f, -7.790083f, 0.689538f));
                        else
                            GetHitDest()->WorldRelocate(WorldLocation(0, -9517.5f, 82.3f, 59.51f, 2.92168f));
                        break;
                    default:
                        GetHitDest()->WorldRelocate(WorldLocation(974, -3618.669922f, 6315.669922f, 113.190002f, 3.204420f));
                        break;
                }
            }
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_darkmoon_staging_area_teleport_SpellScript::RelocateDest, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_darkmoon_staging_area_teleport_SpellScript();
    }
};

class item_darkmoon_faire_fireworks : public ItemScript
{
public:
    item_darkmoon_faire_fireworks() : ItemScript("item_darkmoon_faire_fireworks") { }

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        AchievementEntry const* AchievFireworksAlliance = sAchievementStore.LookupEntry(6030);
        AchievementEntry const* AchievFireworksHorde = sAchievementStore.LookupEntry(6031);

        if (player->GetTeam() == ALLIANCE)
        {
            player->CompletedAchievement(AchievFireworksAlliance);
            player->CastSpell(player, 103740, false);
        }
        else
        {
            player->CompletedAchievement(AchievFireworksHorde);
            player->CastSpell(player, 103740, false);
        }

        return true;
    }
};

// spells
class spell_gen_repair_damaged_tonk : public SpellScriptLoader
{
public:
    spell_gen_repair_damaged_tonk() : SpellScriptLoader("spell_gen_repair_damaged_tonk") {}

    class spell_gen_repair_damaged_tonk_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gen_repair_damaged_tonk_SpellScript);

        SpellCastResult CheckRequirement()
        {
            if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Player* player = GetCaster()->ToPlayer();
            Creature* target = GetHitCreature();

            if (!target)
                return;

            player->KilledMonsterCredit(54504, ObjectGuid::Empty);

            Position myPos = target->GetPosition();
            target->SummonCreature(55356, myPos, TEMPSUMMON_TIMED_DESPAWN, 30000ms);
            target->DespawnOrUnsummon();
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_gen_repair_damaged_tonk_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnCheckCast += SpellCheckCastFn(spell_gen_repair_damaged_tonk_SpellScript::CheckRequirement);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_gen_repair_damaged_tonk_SpellScript();
    }
};

class spell_gen_shoe_baby : public SpellScriptLoader
{
public:
    spell_gen_shoe_baby() : SpellScriptLoader("spell_gen_shoe_baby") {}

    class spell_gen_shoe_baby_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gen_shoe_baby_SpellScript);

        SpellCastResult CheckRequirement()
        {
            if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Player* player = GetCaster()->ToPlayer();
            player->KilledMonsterCredit(54510, ObjectGuid::Empty);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_gen_shoe_baby_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnCheckCast += SpellCheckCastFn(spell_gen_shoe_baby_SpellScript::CheckRequirement);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_gen_shoe_baby_SpellScript();
    }
};

class spell_cook_crunchy_frog : public SpellScriptLoader
{
public:
    spell_cook_crunchy_frog() : SpellScriptLoader("spell_cook_crunchy_frog") {}

    class spell_cook_crunchy_frog_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_cook_crunchy_frog_SpellScript);

        SpellCastResult CheckRequirement()
        {
            if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Player* player = GetCaster()->ToPlayer();
            player->AddItem(72058, 1);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_cook_crunchy_frog_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnCheckCast += SpellCheckCastFn(spell_cook_crunchy_frog_SpellScript::CheckRequirement);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_cook_crunchy_frog_SpellScript();
    }
};

enum InjuriedCarnieYells
{
    SAY_GREETINGS_1 = 0,
    SAY_GREETINGS_2 = 1,
    SAY_GREETINGS_3 = 2,
    SAY_GREETINGS_4 = 3,
    SAY_GREETINGS_5 = 4,
};

class spell_heal_injuried_carnie : public SpellScriptLoader
{
public:
    spell_heal_injuried_carnie() : SpellScriptLoader("spell_heal_injuried_carnie") {}

    class spell_heal_injuried_carnie_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_heal_injuried_carnie_SpellScript);

        SpellCastResult CheckRequirement()
        {
            if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void HandleHealPct(SpellEffIndex /*effIndex*/)
        {
            Player* player = GetCaster()->ToPlayer();
            Creature* target = GetHitCreature();

            player->KilledMonsterCredit(54518, ObjectGuid::Empty);

            if (!target)
                return;

            switch (urand(0, 4))
            {
            case 0:
                target->AI()->Talk(SAY_GREETINGS_1);
                target->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                target->GetMotionMaster()->MoveRandom(30);
                target->DespawnOrUnsummon(8000ms);
                break;
            case 1:
                target->AI()->Talk(SAY_GREETINGS_2);
                target->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                target->GetMotionMaster()->MoveRandom(30);
                target->DespawnOrUnsummon(8000ms);
                break;
            case 2:
                target->AI()->Talk(SAY_GREETINGS_3);
                target->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                target->GetMotionMaster()->MoveRandom(30);
                target->DespawnOrUnsummon(8000ms);
                break;
            case 3:
                target->AI()->Talk(SAY_GREETINGS_4);
                target->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                target->GetMotionMaster()->MoveRandom(30);
                target->DespawnOrUnsummon(8000ms);
                break;
            case 4:
                target->AI()->Talk(SAY_GREETINGS_5);
                target->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                target->GetMotionMaster()->MoveRandom(30);
                target->DespawnOrUnsummon(8000ms);
                break;
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_heal_injuried_carnie_SpellScript::HandleHealPct, EFFECT_0, SPELL_EFFECT_HEAL_PCT);
            OnCheckCast += SpellCheckCastFn(spell_heal_injuried_carnie_SpellScript::CheckRequirement);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_heal_injuried_carnie_SpellScript();
    }
};

class spell_put_up_darkmoon_banner : public SpellScriptLoader
{
public:
    spell_put_up_darkmoon_banner() : SpellScriptLoader("spell_put_up_darkmoon_banner") {}

    class spell_put_up_darkmoon_banner_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_put_up_darkmoon_banner_SpellScript);

        SpellCastResult CheckRequirement()
        {
            if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Player* player = GetCaster()->ToPlayer();
            player->KilledMonsterCredit(54545, ObjectGuid::Empty);

            if (Creature* loosestones = GetCaster()->FindNearestCreature(54545, 10.0f, true))
            {
                loosestones->SummonGameObject(179965, Position(loosestones->GetPositionX(), loosestones->GetPositionY(), loosestones->GetPositionZ(), loosestones->GetOrientation()), QuaternionData(), 0s);
                loosestones->DespawnOrUnsummon(30000ms);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_put_up_darkmoon_banner_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnCheckCast += SpellCheckCastFn(spell_put_up_darkmoon_banner_SpellScript::CheckRequirement);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_put_up_darkmoon_banner_SpellScript();
    }
};

class spell_darkmoon_deathmatch : public SpellScriptLoader
{
public:
    spell_darkmoon_deathmatch() : SpellScriptLoader("spell_darkmoon_deathmatch") {}

    class spell_darkmoon_deathmatch_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_darkmoon_deathmatch_SpellScript);

        SpellCastResult CheckRequirement()
        {
            if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            if (caster->GetPositionY() <= 6400.0f)
                caster->CastSpell(caster, 108919, false);
            else
                caster->CastSpell(caster, 108923, false);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_darkmoon_deathmatch_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            OnCheckCast += SpellCheckCastFn(spell_darkmoon_deathmatch_SpellScript::CheckRequirement);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_darkmoon_deathmatch_SpellScript();
    }
};

void AddSC_darkmoon_island()
{
    new npc_fire_juggler_darkmoon();

    new spell_darkmoon_carousel_whee();
    new spell_darkmoon_staging_area_teleport();

    new item_darkmoon_faire_fireworks();   

    new spell_gen_repair_damaged_tonk();
    new spell_gen_shoe_baby();
    new spell_cook_crunchy_frog();
    new spell_heal_injuried_carnie();
    new spell_put_up_darkmoon_banner();
    new spell_darkmoon_deathmatch();
};
