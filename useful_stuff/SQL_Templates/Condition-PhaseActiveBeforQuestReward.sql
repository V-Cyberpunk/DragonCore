SET @QUESTID :=  54951;
SET @NewPhase := '19837';
SET @NewPhaseName := 'Quest -Emergency First Aid A';
SET @PhaseArea := '10453';

INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(@NewPhase, @NewPhaseName);

INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(@PhaseArea, @NewPhase, @NewPhaseName);


INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, @NewPhase, @PhaseArea, 0, 0, 47, 0, @QUESTID, 1, 0, 0, @NewPhaseName);

UPDATE `quest_template_addon` SET ScriptName='SmartQuest' WHERE ID=@QUESTID

insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param7`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) 
values(@QUESTID,'5','0','0','47','0','100','0','0','0','0','0','0','','85','82238','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','On Quest accept - Self: Cast spell 82238 on Self');
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param7`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) 
values(@QUESTID,'5','2','0','48','0','100','0','0','0','0','0','0','','85','82238','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','On Quest accept - Self: Cast spell 82238 on Self');
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param7`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) 
values(@QUESTID,'5','1','0','49','0','100','0','0','0','0','0','0','','85','82238','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','On Quest accept - Self: Cast spell 82238 on Self');
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param7`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) 
values(@QUESTID,'5','3','0','50','0','100','0','0','0','0','0','0','','85','82238','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','On Quest accept - Self: Cast spell 82238 on Self');
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param7`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) 
values(@QUESTID,'5','4','0','51','0','100','0','0','0','0','0','0','','85','82238','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','On Quest accept - Self: Cast spell 82238 on Self');

UPDATE `quest_template_addon` SET ScriptName='SmartQuest' WHERE ID=@QUESTID
