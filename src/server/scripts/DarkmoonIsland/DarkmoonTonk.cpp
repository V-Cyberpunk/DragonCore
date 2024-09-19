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
#include "ScriptedCreature.h"
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
#include "TemporarySummon.h"
#include "Vehicle.h"
#include <sstream>
#include <G3D/Quat.h>

enum eSpells
{
    SPELL_PROGRESS_BAR = 102178,
    SPELL_SUMMON_TONK = 100752,
};

enum TonkCommander
{
    EVENT_TONKCOMMANDER_START_GAME_1 = 1,
    EVENT_TONKCOMMANDER_START_GAME_2 = 2,
    EVENT_TONKCOMMANDER_START_GAME_3 = 3,
    EVENT_TONKCOMMANDER_FINISH_GAME  = 4,
    EVENT_TONKCOMMANDER_PLAYER_POS   = 5,
};

#define TONK_TARGET_POSITION_COUNT 33

const Position tonkTargetPositions[TONK_TARGET_POSITION_COUNT] = {
    {-4145.988770f, 6290.719727f, 13.116899f, 0.499545f},
    {-4137.421387f, 6289.625977f, 13.116899f, 1.210661f},
    {-4133.106934f, 6296.116699f, 13.116899f, 2.729411f},
    {-4139.067383f, 6300.952148f, 13.116899f, 0.894536f},
    {-4139.654297f, 6305.813477f, 13.116899f, 0.671786f},
    {-4143.446777f, 6308.530762f, 13.116899f, 2.021786f},
    {-4148.482910f, 6308.563965f, 13.116899f, 0.614411f},
    {-4147.683105f, 6300.739258f, 13.116899f, 0.972161f},
    {-4145.276855f, 6304.266602f, 13.116899f, 0.972161f},
    {-4142.250000f, 6312.737793f, 13.116899f, 0.297161f},
    {-4137.417480f, 6316.265137f, 13.116899f, 6.023472f},
    {-4133.054688f, 6318.007813f, 13.116899f, 5.348472f},
    {-4127.991211f, 6313.178223f, 13.116899f, 2.551661f},
    {-4125.186035f, 6313.233398f, 13.116899f, 3.395411f},
    {-4122.878418f, 6307.192383f, 13.116899f, 3.395411f},
    {-4126.788574f, 6306.019043f, 13.116899f, 2.274911f},
    {-4124.875977f, 6300.727051f, 13.116899f, 3.176036f},
    {-4123.939941f, 6299.044434f, 13.116899f, 2.328911f},
    {-4126.655762f, 6294.246094f, 13.116899f, 2.328911f},
    {-4129.494141f, 6294.895020f, 13.116899f, 1.205036f},
    {-4131.038086f, 6292.043457f, 13.116899f, 2.575286f},
    {-4135.638184f, 6288.404785f, 13.116899f, 1.750661f},
    {-4137.863770f, 6292.131836f, 13.116899f, 1.075661f},
    {-4137.863770f, 6297.746094f, 13.116899f, 1.755162f},
    {-4135.811523f, 6302.905762f, 13.116517f, 1.755162f},
    {-4133.516113f, 6307.136719f, 13.116517f, 1.755162f},
    {-4143.302246f, 6310.689941f, 13.116517f, 0.573911f},
    {-4148.054688f, 6297.366211f, 13.116712f, 5.652222f},
    {-4139.401855f, 6294.312500f, 13.116712f, 0.047411f},
    {-4119.912109f, 6299.708496f, 13.116712f, 4.221162f},
    {-4120.738281f, 6306.735352f, 13.116712f, 3.097287f},
    {-4125.261719f, 6317.238281f, 13.116712f, 3.154662f},
    {-4135.285645f, 6321.727539f, 13.116712f, 4.992911f}
};

class npc_finlay_coolshot : public CreatureScript
{
public:
    npc_finlay_coolshot() : CreatureScript("npc_finlay_coolshot") { }

    struct npc_finlay_coolshotAI : public ScriptedAI
    {
        npc_finlay_coolshotAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        bool Active;

        void Reset()
        {
            Active = false;
        }

        void StartGame()
        {
            if (!Active)
            {
                events.ScheduleEvent(EVENT_TONKCOMMANDER_START_GAME_1, 0s);
                events.ScheduleEvent(EVENT_TONKCOMMANDER_START_GAME_2, 0s);
                events.ScheduleEvent(EVENT_TONKCOMMANDER_START_GAME_3, 0s);
                events.ScheduleEvent(EVENT_TONKCOMMANDER_FINISH_GAME, 60s);
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TONKCOMMANDER_START_GAME_1:
                    switch (urand(0, 16))
                    {
                    case 0:
                        me->SummonCreature(33081, -4141.6f, 6315.88f, 13.11f, 4.91587f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 1:
                        me->SummonCreature(33081, -4146.43f, 6309.72f, 13.11f, 5.9655f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 2:
                        me->SummonCreature(33081, -4143.39f, 6314.97f, 13.11f, 5.87662f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 3:
                        me->SummonCreature(33081, -4128.46f, 6312.61f, 13.11f, 0.0794366f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 4:
                        me->SummonCreature(33081, -4123.75f, 6305.47f, 13.11f, 3.03825f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 5:
                        me->SummonCreature(33081, -4136.6f, 6301.53f, 13.1176f, 1.45875f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 6:
                        me->SummonCreature(33081, -4139.58f, 6308.16f, 13.1176f, 1.04362f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 7:
                        me->SummonCreature(33081, -4142.23f, 6291.32f, 13.1167f, 0.986097f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 8:
                        me->SummonCreature(33081, -4136.95f, 6289.13f, 13.1167f, 1.68022f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 9:
                        me->SummonCreature(33081, -4126.09f, 6292.85f, 13.1167f, 2.36872f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 10:
                        me->SummonCreature(33081, -4139.19f, 6287.29f, 13.1167f, 1.47097f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 11:
                        me->SummonCreature(33081, -4148.21f, 6301.88f, 13.1165f, 0.0309724f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 12:
                        me->SummonCreature(33081, -4142.29f, 6299.38f, 13.1165f, 0.0309724f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 13:
                        me->SummonCreature(33081, -4124.66f, 6299.65f, 13.1165f, 2.8671f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 14:
                        me->SummonCreature(33081, -4133.37f, 6308.8f, 13.1165f, 1.07716f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 15:
                        me->SummonCreature(33081, -4132.44f, 6291.18f, 13.1165f, 2.16906f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 16:
                        me->SummonCreature(33081, -4137.18f, 6295.24f, 13.1165f, 4.25818f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    }
                    events.ScheduleEvent(EVENT_TONKCOMMANDER_START_GAME_1, 5s);
                    break;
                case EVENT_TONKCOMMANDER_START_GAME_2:
                    switch (urand(0, 16))
                    {
                    case 0:
                        me->SummonCreature(33081, -4141.6f, 6315.88f, 13.11f, 4.91587f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 1:
                        me->SummonCreature(33081, -4146.43f, 6309.72f, 13.11f, 5.9655f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 2:
                        me->SummonCreature(33081, -4143.39f, 6314.97f, 13.11f, 5.87662f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 3:
                        me->SummonCreature(33081, -4128.46f, 6312.61f, 13.11f, 0.0794366f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 4:
                        me->SummonCreature(33081, -4123.75f, 6305.47f, 13.11f, 3.03825f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 5:
                        me->SummonCreature(33081, -4136.6f, 6301.53f, 13.1176f, 1.45875f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 6:
                        me->SummonCreature(33081, -4139.58f, 6308.16f, 13.1176f, 1.04362f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 7:
                        me->SummonCreature(33081, -4142.23f, 6291.32f, 13.1167f, 0.986097f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 8:
                        me->SummonCreature(33081, -4136.95f, 6289.13f, 13.1167f, 1.68022f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 9:
                        me->SummonCreature(33081, -4126.09f, 6292.85f, 13.1167f, 2.36872f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 10:
                        me->SummonCreature(33081, -4139.19f, 6287.29f, 13.1167f, 1.47097f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 11:
                        me->SummonCreature(33081, -4148.21f, 6301.88f, 13.1165f, 0.0309724f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 12:
                        me->SummonCreature(33081, -4142.29f, 6299.38f, 13.1165f, 0.0309724f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 13:
                        me->SummonCreature(33081, -4124.66f, 6299.65f, 13.1165f, 2.8671f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 14:
                        me->SummonCreature(33081, -4133.37f, 6308.8f, 13.1165f, 1.07716f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 15:
                        me->SummonCreature(33081, -4132.44f, 6291.18f, 13.1165f, 2.16906f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 16:
                        me->SummonCreature(33081, -4137.18f, 6295.24f, 13.1165f, 4.25818f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    }
                    events.ScheduleEvent(EVENT_TONKCOMMANDER_START_GAME_2, 5s);
                    break;
                case EVENT_TONKCOMMANDER_START_GAME_3:
                    switch (urand(0, 16))
                    {
                    case 0:
                        me->SummonCreature(33081, -4141.6f, 6315.88f, 13.11f, 4.91587f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 1:
                        me->SummonCreature(33081, -4146.43f, 6309.72f, 13.11f, 5.9655f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 2:
                        me->SummonCreature(33081, -4143.39f, 6314.97f, 13.11f, 5.87662f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 3:
                        me->SummonCreature(33081, -4128.46f, 6312.61f, 13.11f, 0.0794366f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 4:
                        me->SummonCreature(33081, -4123.75f, 6305.47f, 13.11f, 3.03825f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 5:
                        me->SummonCreature(33081, -4136.6f, 6301.53f, 13.1176f, 1.45875f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 6:
                        me->SummonCreature(33081, -4139.58f, 6308.16f, 13.1176f, 1.04362f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 7:
                        me->SummonCreature(33081, -4142.23f, 6291.32f, 13.1167f, 0.986097f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 8:
                        me->SummonCreature(33081, -4136.95f, 6289.13f, 13.1167f, 1.68022f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 9:
                        me->SummonCreature(33081, -4126.09f, 6292.85f, 13.1167f, 2.36872f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 10:
                        me->SummonCreature(33081, -4139.19f, 6287.29f, 13.1167f, 1.47097f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 11:
                        me->SummonCreature(33081, -4148.21f, 6301.88f, 13.1165f, 0.0309724f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 12:
                        me->SummonCreature(33081, -4142.29f, 6299.38f, 13.1165f, 0.0309724f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 13:
                        me->SummonCreature(33081, -4124.66f, 6299.65f, 13.1165f, 2.8671f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 14:
                        me->SummonCreature(33081, -4133.37f, 6308.8f, 13.1165f, 1.07716f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 15:
                        me->SummonCreature(33081, -4132.44f, 6291.18f, 13.1165f, 2.16906f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    case 16:
                        me->SummonCreature(33081, -4137.18f, 6295.24f, 13.1165f, 4.25818f, TEMPSUMMON_TIMED_DESPAWN, 10s);
                        break;
                    }
                    events.ScheduleEvent(EVENT_TONKCOMMANDER_START_GAME_3, 5s);
                    break;
                case EVENT_TONKCOMMANDER_FINISH_GAME:
                    Active = false;
                    events.CancelEvent(EVENT_TONKCOMMANDER_START_GAME_1);
                    events.CancelEvent(EVENT_TONKCOMMANDER_START_GAME_2);
                    events.CancelEvent(EVENT_TONKCOMMANDER_START_GAME_3);
                    break;
                }
            }
        }

        bool OnGossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (player->GetQuestStatus(QUEST_TONK_COMMANDER) == QUEST_STATUS_INCOMPLETE)
                AddGossipItemFor(player, 13019, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            player->PlayerTalkClass->SendGossipMenu(player->GetGossipTextId(me), me->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, uint32 /*uiSender*/, uint32 /*action*/) override
        {
            if (player->HasItemCount(ITEM_DARKMOON_TOKEN))
            {
                CloseGossipMenuFor(player);

                player->DestroyItemCount(ITEM_DARKMOON_TOKEN, 1, true);
                player->RemoveAurasByType(SPELL_AURA_MOUNTED);
                player->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);

                player->AddAura(102178, player);
                player->SetImmuneToAll(true);
                player->SetPower(POWER_ALTERNATE_POWER, player->GetReqKillOrCastCurrentCount(QUEST_TONK_COMMANDER, 33081));

                if (Creature* summon = me->SummonCreature(54588, -4131.37f, 6317.32f, 13.11f, 4.31f, TEMPSUMMON_TIMED_DESPAWN, 60s))
                {
                    player->CastSpell(summon, 46598, false);
                    summon->ApplySpellImmune(102292, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NORMAL, true);
                }

                CAST_AI(npc_finlay_coolshot::npc_finlay_coolshotAI, me->AI())->StartGame();
                CAST_AI(npc_finlay_coolshot::npc_finlay_coolshotAI, me->AI())->Active = true;
            }

            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_finlay_coolshotAI(creature);
    }
};

// npc - 54642
class npc_darkmoon_enemy_tonk : public CreatureScript
{
public:
    npc_darkmoon_enemy_tonk() : CreatureScript("npc_darkmoon_enemy_tonk") {}

    struct npc_darkmoon_enemy_tonkAI : public ScriptedAI
    {
        npc_darkmoon_enemy_tonkAI(Creature* c) : ScriptedAI(c)
        {
            Reset();
        }

        ObjectGuid target;
        bool changePath;
        uint32 pathCheckTimer;
        uint32 targetCheckTimer;

        void Reset()
        {
            target.Clear();
            changePath = true;
            pathCheckTimer = 0;
            targetCheckTimer = 1000;
        }

        void MovementInform(uint32 /*type*/, uint32 id)
        {
            if (id == 0)
                changePath = true;
        }

        void UpdateAI(const uint32 diff)
        {
            if (pathCheckTimer != 0)
            {
                if (pathCheckTimer <= diff)
                {
                    target.Clear();
                    changePath = true;
                    pathCheckTimer = 0;
                }
                else
                    pathCheckTimer -= diff;
            }

            if (changePath)
            {
                if (me && me->IsAlive() && me->IsInWorld())
                {
                    uint8 point = urand(0, TONK_TARGET_POSITION_COUNT - 1);
                    me->GetMotionMaster()->MovePoint(0, tonkTargetPositions[point]);
                    changePath = false;
                }
            }

            if (targetCheckTimer <= diff)
            {
                if (!target)
                {
                    std::vector<Creature*> crList;
                    GetCreatureListWithEntryInGrid(crList, me, 54588, 4.5f);
                    for (auto& creature : crList)
                    {
                        if (creature->isInFront(me, M_PI/1.5f) && !creature->HasAura(102341))
                        {
                            target = creature->GetGUID();
                            me->StopMoving();
                            me->GetMotionMaster()->MoveIdle();
                            changePath = false;
                            me->SetFacingToObject(creature);
                            me->CastSpell(creature, 102341, TRIGGERED_FULL_MASK);
                            me->CastSpell(creature, 102227, false);
                            pathCheckTimer = 3000; // 2s spellcast + 1s delay
                            break;
                        }
                    }

                    if (!target)
                        targetCheckTimer = 1000;
                    else
                        targetCheckTimer = 2500;
                }
                else
                {
                    Unit* targetUnit = ObjectAccessor::GetUnit(*me, target);
                    if (targetUnit && targetUnit->IsWithinDist(me, 7.0f, true) && targetUnit->isInFront(me, M_PI/1.5f))
                    {
                        targetUnit->CastSpell(targetUnit, 100626, true);
                        me->DealDamage(me, targetUnit, (targetUnit->GetMaxHealth() / 2) + 1);
                    }
                    targetCheckTimer = 2000;
                }
            }
            else
                targetCheckTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* c) const
    {
        return new npc_darkmoon_enemy_tonkAI(c);
    }
};

// This is the spell the player can cancel (SPELL_OVERRIDE_ACTION : 102178)
class spell_tonk_override_action : public SpellScriptLoader
{
public:
    spell_tonk_override_action() : SpellScriptLoader("spell_tonk_override_action") { }

    class spell_tonk_override_action_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_tonk_override_action_AuraScript);

        bool Validate(SpellInfo const* /*entry*/) override
        {
            return true;
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();

            if (!target)
                return;

            target->SetPower(POWER_ALTERNATE_POWER, 0);
            target->CastSpell(target, 109976, true);
            target->SetImmuneToAll(false);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_tonk_override_action_AuraScript::OnRemove, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_tonk_override_action_AuraScript();
    }
};

class PositionCheck
{
public:
    PositionCheck(Unit* caster) : _caster(caster) {}

    bool operator()(WorldObject* unit)
    {
        bool isTooFar = _caster->GetDistance2d(unit) >= 2.5f;
        bool isNotInFront = !_caster->isInFront(unit, 90.0f);
        return isTooFar || isNotInFront;
    }

private:
    Unit* _caster;
};

// SPELL_SHOOT : 102292
class spell_tonk_shoot : public SpellScriptLoader
{
public:
    spell_tonk_shoot() : SpellScriptLoader("spell_tonk_shoot") { }

    class spell_tonk_shoot_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_tonk_shoot_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();

            if (!caster)
                return SPELL_CAST_OK;

            std::list<Creature*> targetList;
            caster->GetCreatureListWithEntryInGrid(targetList, 54642, 2.5f);
            caster->GetCreatureListWithEntryInGrid(targetList, 33081, 2.5f);

            targetList.remove_if(PositionCheck(GetCaster()));

            if (targetList.empty())
                return SPELL_CAST_OK;

            Creature* target = targetList.front();

            switch (target->GetEntry())
            {
            case 54642:
            {
                caster->CastSpell(caster, 110162, true);
                break;
            }
            case 33081:
            {
                caster->SetPower(POWER_ALTERNATE_POWER, (caster->GetPower(POWER_ALTERNATE_POWER) + 1));
                break;
            }
            }
            caster->Kill(caster, target);
            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_tonk_shoot_SpellScript::CheckCast);
        }

    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_tonk_shoot_SpellScript();
    }
};

// areatrigger - 7340
class at_tonks_zone : public AreaTriggerScript
{
public:
    at_tonks_zone() : AreaTriggerScript("at_tonks_zone") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
    {
        if (!player->IsGameMaster() && !player->HasAura(102178))
            player->CastSpell(player, 109976, true);
        return true;
    }
};

void AddSC_darkmoon_tonk()
{
    //npc
    new npc_finlay_coolshot();
    new npc_darkmoon_enemy_tonk();
    //spell
    new spell_tonk_override_action();
    new spell_tonk_shoot();
    //areatrigger
    new at_tonks_zone();
};
