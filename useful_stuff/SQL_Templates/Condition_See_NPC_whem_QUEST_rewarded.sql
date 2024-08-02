SET @ENTRY := 164579;
SET @QUEST := 60055;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES('32','5', @Entry ,'0','1','47','0', @Quest ,'66','0','0','0','0','','OR Spawn of creature with entry 157093 requires Quest 57102 complete/rewarded');
