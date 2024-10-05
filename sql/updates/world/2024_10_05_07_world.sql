SET @CGUID := 0;
SELECT @CGUID := MAX(guid) FROM creature;
SELECT @CGUID := @CGUID+1;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+19;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID+0, 198122, 2444, 13644, 13715, '0', 0, 19783, 0, -1, 0, 0, 3247.607666015625, 756.07989501953125, 169.0995025634765625, 1.501373052597045898, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Overflowing Rapids - Difficulty: 0)
(@CGUID+1, 198132, 2444, 13644, 13715, '0', 0, 19783, 0, -1, 0, 0, 3247.522705078125, 779.96356201171875, 172.2866668701171875, 4.715946197509765625, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Overflowing Rapids - Difficulty: 0)
(@CGUID+2, 198117, 2444, 13644, 13731, '0', 0, 19778, 0, -1, 0, 0, 1072.0521240234375, -268.44964599609375, 418.880706787109375, 4.976108074188232421, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Hatchery Observatory - Difficulty: 0)
(@CGUID+3, 198100, 2444, 13644, 13731, '0', 0, 19778, 0, -1, 0, 0, 1079.720458984375, -304.75, 432.521484375, 1.778982400894165039, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Hatchery Observatory - Difficulty: 0)
(@CGUID+4, 198100, 2444, 13644, 13729, '0', 0, 19777, 0, -1, 0, 0, 2274.572998046875, 148.796875, 195.3450927734375, 5.262511253356933593, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Crumbling Life Archway - Difficulty: 0)
(@CGUID+5, 198116, 2444, 13644, 13729, '0', 0, 19777, 0, -1, 0, 0, 2286.928955078125, 128.6493072509765625, 186.825592041015625, 2.291139841079711914, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Crumbling Life Archway - Difficulty: 0)
(@CGUID+6, 198100, 2444, 13644, 13711, '0', 0, 19782, 0, -1, 0, 0, 2887.343017578125, 90.3524322509765625, 469.69970703125, 0.360764145851135253, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Concord Observatory - Difficulty: 0)
(@CGUID+7, 198121, 2444, 13644, 13711, '0', 0, 19782, 0, -1, 0, 0, 2903.99658203125, 96.63541412353515625, 467.5977783203125, 3.594461917877197265, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Concord Observatory - Difficulty: 0)
(@CGUID+8, 198120, 2444, 13644, 13716, '0', 0, 19781, 0, -1, 0, 0, 2413.40966796875, 643.38018798828125, 341.713623046875, 2.987755775451660156, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: The Overflowing Spring - Difficulty: 0)
(@CGUID+9, 198100, 2444, 13644, 13716, '0', 0, 19781, 0, -1, 0, 0, 2383.4375, 643.55731201171875, 352.99786376953125, 6.277276039123535156, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: The Overflowing Spring - Difficulty: 0)
(@CGUID+10, 198118, 2444, 13644, 13738, '0', 0, 19779, 0, -1, 0, 0, 1976.8021240234375, 1180.032958984375, 555.330322265625, 3.16737675666809082, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Obsidian Observatory - Difficulty: 0)
(@CGUID+11, 198129, 2444, 13644, 13738, '0', 0, 19779, 0, -1, 0, 0, 1955.46875, 1184.2760009765625, 564.42950439453125, 6.086855411529541015, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Obsidian Observatory - Difficulty: 0)
(@CGUID+12, 198100, 2444, 13644, 13709, '0', 0, 19784, 0, -1, 0, 0, 4333.23779296875, 86.80034637451171875, 192.1732635498046875, 2.472563982009887695, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Life-Binder Conservatory - Difficulty: 0)
(@CGUID+13, 198123, 2444, 13644, 13709, '0', 0, 19784, 0, -1, 0, 0, 4309.43603515625, 105.6197891235351562, 181.252838134765625, 5.897611618041992187, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Life-Binder Conservatory - Difficulty: 0)
(@CGUID+14, 198100, 2444, 13644, 13939, '0', 0, 19774, 0, -1, 0, 0, 3347.796142578125, -1171.109375, 381.924468994140625, 5.546568870544433593, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Wingrest Embassy - Difficulty: 0)
(@CGUID+15, 198099, 2444, 13644, 13939, '0', 0, 19774, 0, -1, 0, 0, 3363.5625, -1185.407958984375, 377.625518798828125, 2.314867973327636718, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Wingrest Embassy - Difficulty: 0)
(@CGUID+16, 198100, 2444, 13644, 13724, '0', 0, 19776, 0, -1, 0, 0, 2535.411376953125, -1160.37158203125, 393.954833984375, 5.772128105163574218, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Skytop Observatory - Difficulty: 0)
(@CGUID+17, 198115, 2444, 13644, 13724, '0', 0, 19776, 0, -1, 0, 0, 2557.145751953125, -1172.55908203125, 386.020477294921875, 2.936239480972290039, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Skytop Observatory - Difficulty: 0)
(@CGUID+18, 198100, 2444, 13644, 13734, '0', 0, 19780, 0, -1, 0, 0, 567.0382080078125, 2730.23876953125, 290.5853271484375, 0.323687583208084106, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067), -- Hope Kite (Area: Apex Canopy - Difficulty: 0)
(@CGUID+19, 198119, 2444, 13644, 13734, '0', 0, 19780, 0, -1, 0, 0, 586.857666015625, 2736.887939453125, 286.4337158203125, 3.685349941253662109, 120, 0, 0, 35235, 0, NULL, NULL, NULL, NULL, "", NULL, 47067); -- Hope Kite (Area: Apex Canopy - Difficulty: 0)

UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry` IN (198099, 198115, 198116, 198117, 198118, 198119, 198120, 198121, 198122, 198123); -- Hope Kite
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=16777216, `AIName` = 'SmartAI' WHERE `entry`IN (198129, 198100, 198132); -- Hope Kite

DELETE FROM `creature_template_addon` WHERE `entry` IN (198129, 198100, 198132);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(198132, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 198129 (Hope Kite)
(198129, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 198100 (Hope Kite)
(198100, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 198132 (Hope Kite)

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (198129, 198100, 198132);
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(198129, 1, 0, 0, NULL),
(198100, 1, 0, 0, NULL),
(198132, 1, 0, 0, NULL);

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (19774, 19776, 19777, 19778, 19779, 19780, 19781, 19782, 19783, 19784);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(19774, 'Cosmetic - See Hope Kite at Wingrest Embassy'),
(19776, 'Cosmetic - See Hope Kite at Skytop Observatory'),
(19777, 'Cosmetic - See Hope Kite at Crumbling Life Archway'),
(19778, 'Cosmetic - See Hope Kite at Hatchery Observatory'),
(19779, 'Cosmetic - See Hope Kite at Obsidian Observatory'),
(19780, 'Cosmetic - See Hope Kite at Apex Canopy'),
(19781, 'Cosmetic - See Hope Kite at The Overflowing Spring'),
(19782, 'Cosmetic - See Hope Kite at Concord Observatory'),
(19783, 'Cosmetic - See Hope Kite at Overflowing Rapids'),
(19784, 'Cosmetic - See Hope Kite at Life-Binder Conservatory');

DELETE FROM `phase_area` WHERE `AreaId` = 13644 AND `PhaseId` IN (19774, 19776, 19777, 19778, 19779, 19780, 19781, 19782, 19783, 19784);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(13644, 19774, 'See Hope Kite at Wingrest Embassy'),
(13644, 19776, 'See Hope Kite at Skytop Observatory'),
(13644, 19777, 'See Hope Kite at Crumbling Life Archway'),
(13644, 19778, 'See Hope Kite at Hatchery Observatory'),
(13644, 19779, 'See Hope Kite at Obsidian Observatory'),
(13644, 19780, 'See Hope Kite at Apex Canopy'),
(13644, 19781, 'See Hope Kite at The Overflowing Spring'),
(13644, 19782, 'See Hope Kite at Concord Observatory'),
(13644, 19783, 'See Hope Kite at Overflowing Rapids'),
(13644, 19784, 'See Hope Kite at Life-Binder Conservatory');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (19774, 19776, 19777, 19778, 19779, 19780, 19781, 19782, 19783, 19784) AND `SourceEntry` = 13644;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 19774, 13644, 0, 0, 47, 0, 72096, 64, 0, 1, 'Apply Phase 19774 if Quest 72096 is not rewarded'),
(26, 19776, 13644, 0, 0, 47, 0, 72097, 64, 0, 1, 'Apply Phase 19776 if Quest 72097 is not rewarded'),
(26, 19777, 13644, 0, 0, 47, 0, 72098, 64, 0, 1, 'Apply Phase 19777 if Quest 72098 is not rewarded'),
(26, 19778, 13644, 0, 0, 47, 0, 72099, 64, 0, 1, 'Apply Phase 19778 if Quest 72099 is not rewarded'),
(26, 19779, 13644, 0, 0, 47, 0, 72100, 64, 0, 1, 'Apply Phase 19779 if Quest 72100 is not rewarded'),
(26, 19780, 13644, 0, 0, 47, 0, 72101, 64, 0, 1, 'Apply Phase 19780 if Quest 72101 is not rewarded'),
(26, 19781, 13644, 0, 0, 47, 0, 72102, 64, 0, 1, 'Apply Phase 19781 if Quest 72102 is not rewarded'),
(26, 19782, 13644, 0, 0, 47, 0, 72103, 64, 0, 1, 'Apply Phase 19782 if Quest 72103 is not rewarded'),
(26, 19783, 13644, 0, 0, 47, 0, 72104, 64, 0, 1, 'Apply Phase 19783 if Quest 72104 is not rewarded'),
(26, 19784, 13644, 0, 0, 47, 0, 72105, 64, 0, 1, 'Apply Phase 19784 if Quest 72105 is not rewarded');

DELETE FROM `quest_template` WHERE `ID` IN (72096, 72097, 72098, 72099, 72100, 72101, 72102, 72103, 72104, 72105);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardItem1`, `RewardAmount1`, `RewardItem2`, `RewardAmount2`, `RewardItem3`, `RewardAmount3`, `RewardItem4`, `RewardAmount4`, `ItemDrop1`, `ItemDropQuantity1`, `ItemDrop2`, `ItemDropQuantity2`, `ItemDrop3`, `ItemDropQuantity3`, `ItemDrop4`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemQuantity1`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemID2`, `RewardChoiceItemQuantity2`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemID3`, `RewardChoiceItemQuantity3`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemID4`, `RewardChoiceItemQuantity4`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemID5`, `RewardChoiceItemQuantity5`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardFactionID1`, `RewardFactionValue1`, `RewardFactionOverride1`, `RewardFactionCapIn1`, `RewardFactionID2`, `RewardFactionValue2`, `RewardFactionOverride2`, `RewardFactionCapIn2`, `RewardFactionID3`, `RewardFactionValue3`, `RewardFactionOverride3`, `RewardFactionCapIn3`, `RewardFactionID4`, `RewardFactionValue4`, `RewardFactionOverride4`, `RewardFactionCapIn4`, `RewardFactionID5`, `RewardFactionValue5`, `RewardFactionOverride5`, `RewardFactionCapIn5`, `RewardFactionFlags`, `RewardCurrencyID1`, `RewardCurrencyQty1`, `RewardCurrencyID2`, `RewardCurrencyQty2`, `RewardCurrencyID3`, `RewardCurrencyQty3`, `RewardCurrencyID4`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
(72096, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '[Hidden Tracker] Remove Hope Kite Phase', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0),
(72097, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '[Hidden Tracker] Remove Hope Kite Phase', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0),
(72098, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '[Hidden Tracker] Remove Hope Kite Phase', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0),
(72099, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '[Hidden Tracker] Remove Hope Kite Phase', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0),
(72100, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '[Hidden Tracker] Remove Hope Kite Phase', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0),
(72101, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '[Hidden Tracker] Remove Hope Kite Phase', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0),
(72102, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '[Hidden Tracker] Remove Hope Kite Phase', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0),
(72103, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '[Hidden Tracker] Remove Hope Kite Phase', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0),
(72104, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '[Hidden Tracker] Remove Hope Kite Phase', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0),
(72105, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '[Hidden Tracker] Remove Hope Kite Phase', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (198099, 198115, 198116, 198117, 198118, 198119, 198120, 198121, 198122, 198123);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(198099, 392674, 3, 0),
(198115, 392696, 3, 0),
(198116, 392711, 3, 0),
(198117, 392713, 3, 0),
(198118, 392715, 3, 0),
(198119, 392716, 3, 0),
(198120, 392717, 3, 0),
(198121, 392719, 3, 0),
(198122, 392720, 3, 0),
(198123, 392722, 3, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid` = -(@CGUID+1) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+1), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 392683, 0, 0, 0, 0, 0, 10, 0, 198122, 0, 0, 0, 0, 0, 0, 'Hope Kite - On Spawn - Cast spell Kite Rope [DNT] - to creature 198122');

DELETE FROM `smart_scripts` WHERE `entryorguid` = -(@CGUID+3) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+3), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 392683, 0, 0, 0, 0, 0, 10, 0, 198117, 0, 0, 0, 0, 0, 0, 'Hope Kite - On Spawn - Cast spell Kite Rope [DNT] - to creature 198117');

DELETE FROM `smart_scripts` WHERE `entryorguid` = -(@CGUID+4) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+4), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 392683, 0, 0, 0, 0, 0, 10, 0, 198116, 0, 0, 0, 0, 0, 0, 'Hope Kite - On Spawn - Cast spell Kite Rope [DNT] - to creature 198116');

DELETE FROM `smart_scripts` WHERE `entryorguid` = -(@CGUID+6) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+6), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 392683, 0, 0, 0, 0, 0, 10, 0, 198121, 0, 0, 0, 0, 0, 0, 'Hope Kite - On Spawn - Cast spell Kite Rope [DNT] - to creature 198121');

DELETE FROM `smart_scripts` WHERE `entryorguid` = -(@CGUID+9) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+9), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 392683, 0, 0, 0, 0, 0, 10, 0, 198120, 0, 0, 0, 0, 0, 0, 'Hope Kite - On Spawn - Cast spell Kite Rope [DNT] - to creature 198120');

DELETE FROM `smart_scripts` WHERE `entryorguid` = -(@CGUID+11) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+11), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 392683, 0, 0, 0, 0, 0, 10, 0, 198118, 0, 0, 0, 0, 0, 0, 'Hope Kite - On Spawn - Cast spell Kite Rope [DNT] - to creature 198118');

DELETE FROM `smart_scripts` WHERE `entryorguid` = -(@CGUID+12) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+12), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 392683, 0, 0, 0, 0, 0, 10, 0, 198123, 0, 0, 0, 0, 0, 0, 'Hope Kite - On Spawn - Cast spell Kite Rope [DNT] - to creature 198123');

DELETE FROM `smart_scripts` WHERE `entryorguid` = -(@CGUID+14) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+14), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 392683, 0, 0, 0, 0, 0, 10, 0, 198099, 0, 0, 0, 0, 0, 0, 'Hope Kite - On Spawn - Cast spell Kite Rope [DNT] - to creature 198099');

DELETE FROM `smart_scripts` WHERE `entryorguid` = -(@CGUID+16) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+16), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 392683, 0, 0, 0, 0, 0, 10, 0, 198115, 0, 0, 0, 0, 0, 0, 'Hope Kite - On Spawn - Cast spell Kite Rope [DNT] - to creature 198115');

DELETE FROM `smart_scripts` WHERE `entryorguid` = -(@CGUID+18) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+18), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 392683, 0, 0, 0, 0, 0, 10, 0, 198119, 0, 0, 0, 0, 0, 0, 'Hope Kite - On Spawn - Cast spell Kite Rope [DNT] - to creature 198119');
