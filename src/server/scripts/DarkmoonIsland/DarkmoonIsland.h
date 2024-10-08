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

#ifndef DARKMOON_ISLAND_H
#define DARKMOON_ISLAND_H

//QUEST
enum darkmoonIslandQuests
{
    QUEST_WHACK_A_GNOLL         = 29463,
    QUEST_FIREBIRDS_CHALLENGE   = 36481,
    QUEST_HUMANOID_CANNONBALL   = 29436,
    QUEST_TARGET_TURTLE         = 29455,
    QUEST_HE_SHOOTS_HE_SCORES   = 29438,
    QUEST_ITS_HAMMER_TIME       = 29463,
    QUEST_TONK_COMMANDER        = 29434,
};

//ITEMS
enum darkmoonIslandItems
{
    ITEM_DARKMOON_TOKEN         = 71083
};

//ACHIEVEMENT
enum darkmoonIslandAchievement
{
    ACHIEVEMENT_BLOOD_OF_ALYSRAZOR = 9252
};

//SPELLS
enum darkmoonIslandSpells
{
    SPELL_WHEE                  = 46668,

    // Firebirds Challenge spell
    WINGS_OF_FLAME_START        = 170819,
    WINGS_OF_FLAME_AURA         = 170820,
    BLAZING_RING                = 170823,
    SUMMON_RINGS_AT             = 170815,
    SLOW_FALL                   = 130,

};

enum darkmoonIslandGameObjects
{
    GOB_DARKMOON_CAROUSEL       = 216666
};

enum darkmoonIslandRingTossSpells
{
    SPELL_RINGTOSS_ENABLE = 102058,
    SPELL_RINGTOSS_TOSS = 101695,
    SPELL_RINGTOSS_HIT = 101699,
    SPELL_RINGTOSS_TURTLE_CIRCLE_1 = 101734,
    SPELL_RINGTOSS_TURTLE_CIRCLE_2 = 101736,
    SPELL_RINGTOSS_TURTLE_CIRCLE_3 = 101738,
    SPELL_RINGTOSS_KILL_CREDIT = 101807,
};

#endif
