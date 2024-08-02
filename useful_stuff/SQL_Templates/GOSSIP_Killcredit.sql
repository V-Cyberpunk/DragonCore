SET @ENTRY := 135438;
DELETE FROM smart_scripts WHERE source_type = 0 AND entryOrGuid = @ENTRY AND event_type=64;
UPDATE creature_template SET AIName = 'SmartAI', ScriptName = '' WHERE entry = @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, COMMENT) VALUES
(@ENTRY, 0, 2, 0, 64, 0, 100, 0, 0, 0, 0, 0, 33, @ENTRY, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player opened gossip - Gossip player: Give kill credit Kill Credit - Oathstone Chat (190899)');
DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = @ENTRY AND SourceId = 0;
UPDATE creature_template SET npcflag=3 WHERE entry = @ENTRY;
SET @ENTRY := 68331;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`)
SELECT @ENTRY, 999999999, 47936
FROM DUAL
WHERE NOT EXISTS (SELECT * FROM creature_template_gossip WHERE CreatureID = @ENTRY);
