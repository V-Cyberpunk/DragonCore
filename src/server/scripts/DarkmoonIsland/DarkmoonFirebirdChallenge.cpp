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
#include "SpellAuraEffects.h"
#include "ObjectAccessor.h"
#include "TemporarySummon.h"
#include <sstream>

const Position areatrigger_firebird_challenge_list[56] =
{
    {-4177.096f, 6412.299f, 53.74761f, 0.9677705f},
    {-4153.389f, 6421.354f, 49.73269f, 0.7785892f},
    {-4200.064f, 6404.912f, 49.83862f, 1.364654f},
    {-4123.092f, 6420.391f, 79.5131f, 0.5568334f},
    {-4000.738f, 6319.748f, 61.96915f, 6.056061f},
    {-4298.453f, 6435.71f, 99.74864f, 2.497026f},
    {-3976.156f, 6239.41f, 59.68959f, 5.777801f},
    {-4061.708f, 6240.754f, 55.67439f, 5.568335f},
    {-4417.354f, 6368.175f, 34.5676f, 3.138926f},
    {-4411.45f, 6469.171f, 37.86602f, 2.678885f},
    {-4416.028f, 6263.413f, 30.60862f, 3.605707f},
    {-4464.976f, 6074.34f, 56.51786f, 3.992603f},
    {-4384.887f, 6059.405f, 30.4877f, 4.191037f},
    {-4387.158f, 6218.971f, 85.1059f, 3.833803f},
    {-4278.502f, 6305.27f, 55.3745f, 3.864719f},
    {-4219.653f, 6288.33f, 56.897f, 4.564775f},
    {-4127.677f, 6190.193f, 87.08089f, 5.13686f},
    {-4204.17f, 6195.492f, 80.76868f, 4.73384f},
    {-4282.986f, 6089.893f, 74.05066f, 4.448216f},
    {-4327.917f, 6013.772f, 118.3816f, 4.385294f},
    {-4276.29f, 6004.999f, 98.62133f, 4.52588f},
    {-4152.132f, 6029.343f, 112.4916f, 4.875675f},
    {-3994.031f, 6130.03f, 143.9004f, 5.445213f},
    {-3888.948f, 6244.342f, 71.50654f, 5.914334f},
    {-3871.005f, 6321.215f, 78.78794f, 6.146299f},
    {-3931.849f, 6370.7f, 73.34687f, 0.01116927f},
    {-4015.245f, 6472.497f, 85.551f, 0.4986074f},
    {-3860.811f, 6494.958f, 97.87495f, 0.3516689f},
    {-4163.147f, 6539.726f, 78.76099f, 1.316605f},
    {-4265.304f, 6513.369f, 93.58659f, 1.946203f},
    {-4231.226f, 6586.085f, 93.67531f, 1.677328f},
    {-4162.233f, 6763.257f, 25.24334f, 1.455971f},
    {-4088.217f, 6675.956f, 53.79656f, 1.200647f},
    {-4319.019f, 6655.865f, 24.96414f, 1.93885f},
    {-3833.854f, 6670.972f, 60.10976f, 0.6814674f},
    {-3754.766f, 6475.822f, 64.21665f, 0.2344222f},
    {-3781.519f, 6438.263f, 61.80006f, 0.1642108f},
    {-3794.465f, 6427.009f, 69.57449f, 0.1426917f},
    {-3861.29f, 6380.367f, 55.15146f, 0.03677358f},
    {-3812.991f, 6369.193f, 118.9729f, 0.003991582f},
    {-4142.12f, 5947.434f, 119.1986f, 4.867595f},
    {-4196.168f, 5890.585f, 127.7626f, 4.7369f},
    {-4237.936f, 5942.774f, 117.577f, 4.641721f},
    {-4311.99f, 5950.87f, 104.305f, 4.467546f},
    {-4068.458f, 5933.453f, 115.6255f, 5.023079f},
    {-3969.863f, 5989.153f, 113.2228f, 5.273759f},
    {-3887.325f, 6097.111f, 116.1136f, 5.582238f},
    {-3817.255f, 6127.589f, 126.3984f, 5.732175f},
    {-3760.503f, 6175.529f, 123.6823f, 5.87761f},
    {-4149.393f, 6684.266f, 31.54233f, 1.388198f},
    {-3951.658f, 6719.8f, 37.38012f, 0.9418668f},
    {-4147.766f, 6777.004f, 32.39946f, 1.425039f},
    {-3792.443f, 6895.78f, 26.00098f, 0.9043181f},
    {-3740.898f, 6846.799f, 56.73854f, 0.7983093f},
    {-3777.356f, 6723.497f, 24.15144f, 0.6907824f},
    {-3880.603f, 6715.769f, 22.8216f, 0.8163199f}
};

//spell - quest 170823
//new speed - 170820
//spell starter - 170819

 /// Wings of Flame trigerred - 170820
class spell_darkmoon_firebird_challenge_check_trigger : public SpellScriptLoader
{
public:
    spell_darkmoon_firebird_challenge_check_trigger() : SpellScriptLoader("spell_darkmoon_firebird_challenge_check_trigger") { }

    class spell_darkmoon_firebird_challenge_allow_fly_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_darkmoon_firebird_challenge_allow_fly_AuraScript);

        void HandleRemove(AuraEffect const*, AuraEffectHandleModes)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::vector<AreaTrigger*> areatriggerlist = caster->GetAreaTriggers(170815);

            for (AreaTrigger* areatrigger : areatriggerlist)
                areatrigger->RemoveFromWorld();
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_darkmoon_firebird_challenge_allow_fly_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_darkmoon_firebird_challenge_allow_fly_AuraScript();
    }
};

/// Firebird Challenge - Wings of flame (trigger) 170819
class spell_darkmoon_firebird_challenge : public SpellScriptLoader
{
public:
    spell_darkmoon_firebird_challenge() : SpellScriptLoader("spell_darkmoon_firebird_challenge") { }

    class spell_darkmoon_firebird_challenge_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_darkmoon_firebird_challenge_AuraScript);


        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (aurEff->GetTickNumber() == 1)
            {
                for (uint8 i = 1; i < 56; ++i)
                    caster->CastSpell(areatrigger_firebird_challenge_list[i], 170815, true);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_darkmoon_firebird_challenge_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_darkmoon_firebird_challenge_AuraScript();
    }
};

void AddSC_darkmoon_firebird_challenge()
{
    //new spell_darkmoon_firebird_challenge_check_trigger();
    //new spell_darkmoon_firebird_challenge();
};
