DELETE FROM `spell_proc` WHERE `SpellId` IN (387385);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(387385,0x00,5,0x00000000,0x00000040,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x10,0x0,0,0,0,0); -- Backlash

UPDATE `creature_template` SET `npcflag` = 128, `VerifiedBuild` = 56110 WHERE `entry` = 43694;

DELETE FROM `smart_scripts` WHERE `entryorguid`=61245 AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61245, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 118905, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Capacitor Totem - On Just Created - Self: Cast Spell 118905');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=61245;

DELETE FROM `spell_proc` WHERE `SpellId` IN (378075);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(378075,0x08,11,0x00000800,0x00000000,0x00000000,0x00000000,0x0,0x0,0x4,0x1,0x0,0x0,0x0,0,0,0,0); -- Thunderous Paws

DELETE FROM `spell_proc` WHERE `SpellId` IN (383192);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(383192,0x08,7,0x00000000,0x00000002,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x0,0x0,0x0,0,0,0,0); -- Grove Tending

DELETE FROM `spell_proc` WHERE `SpellId` IN (132158);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(132158,0x08,7,0x10000240,0x00000000,0x00000000,0x00000000,0x0,0x0,0x3,0x2,0x0,0x8,0x0,0,0,0,0); -- Nature's Swiftness

DELETE FROM `spell_proc` WHERE `SpellId` IN (343647);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(343647,0x00,7,0x00000000,0x08000400,0x00000000,0x00000000,0x0,0x0,0x4,0x1,0x1,0x2,0x0,0,0,0,0); -- Solstice

SET @TEL_ID := 4105;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+15;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,1003.15,3602.38,192.193,3.10705,860,'TheWanderingIsle'),
(@TEL_ID+1,739.462,3637.39,142.631,4.49721,860,'MandoriVillage'),
(@TEL_ID+2,1351.5,3374.61,125.649,1.97375,860,'TheDawningValley'),
(@TEL_ID+3,844.872,4401.16,237.269,1.60542,860,'TheWoodOfStaves'),
(@TEL_ID+4,1206.6,4263.88,222.736,0.105327,860,'FeFengVillage'),
(@TEL_ID+5,1043.43,4195.44,205.269,4.7117,860,'MorningBreezeVillage'),
(@TEL_ID+6,628.728,3922.98,81.7556,0.124933,860,'PoolOfThePaw'),
(@TEL_ID+7,321.424,3971.64,99.421,2.6877,860,'WreckOfTheSkyseeker'),
(@TEL_ID+8,403.316,3672.92,81.4312,0.845975,860,'PeiWuForest'),
(@TEL_ID+9,407.516,3284.52,73.2091,0.597012,860,'KiHanBrewery'),
(@TEL_ID+10,394.809,3072.58,75.579,0.151689,860,'TheRows'),
(@TEL_ID+11,623.996,3149.55,87.817,4.45175,860,'TheDaiLoFarmstead'),
(@TEL_ID+12,971.564,3015.68,105.719,6.06806,860,'TheSingingPools'),
(@TEL_ID+13,981.351,3603.05,193.114,3.11109,860,'TempleOfFiveDawns'),
(@TEL_ID+14,1416.67,3687.3,83.6041,4.62298,860,'WuSongVillage'),
(@TEL_ID+15,1469.91,3464.64,181.788,2.72073,860,'ShangXiTrainingGrounds');

UPDATE `phase_name` SET `ID`=20686 WHERE `ID`=26686;
UPDATE `phase_name` SET `ID`=20685 WHERE `ID`=26685;

DELETE FROM `spell_proc` WHERE `SpellId` IN (383192);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(383192,0x00,7,0x00000000,0x00000002,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x403,0x0,0x0,0,0,0,0); -- Grove Tending

DELETE FROM `spell_proc` WHERE `SpellId` IN (321377);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(321377,0x00,6,0x00000000,0x00000000,0x00400000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Prayer Circle
