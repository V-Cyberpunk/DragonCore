SET @WAITMIN := '0';
SET @WAITMAX := '0';
SET @REPMIN := 420000;
SET @REPMAX := 420000;
SET @SPELL := 381615;
SET @ENTRY := 189492;

SET @NUMBERPrev := 0;
SET @NUMBERNOW := 1;


UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;

REPLACE INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param7`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY,'0',@NUMBERNOW,@NUMBERPrev,'0','0','100','0',@WAITMIN,@WAITMAX,@REPMIN,@REPMAX,'0','','11',@SPELL,'0','0','0','0','0','0','2','0','0','0','0','0','0','0','0','0');
