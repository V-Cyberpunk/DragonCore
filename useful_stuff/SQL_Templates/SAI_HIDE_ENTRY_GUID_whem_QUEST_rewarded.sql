SET @ENTRY := 162542;
SET @GUID := 1075149;
SET @QUEST := 57261;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param7`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) 
VALUES(@QUEST,'5','11005','0','50','0','100','0','0','0','0','0','0','','47','0','0','0','0','0','0','0','10', @GUID , @ENTRY ,'0','0','0','0','0','0','On Quest accept - Self: Cast spell 82238 on Self');

SET @ENTRY := 166306;
SET @GUID := 583585;
SET @QUEST := 57261;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param7`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) 
VALUES(@QUEST,'5','11006','0','50','0','100','0','0','0','0','0','0','','47','0','0','0','0','0','0','0','10', @GUID , @ENTRY ,'0','0','0','0','0','0','On Quest accept - Self: Cast spell 82238 on Self');

