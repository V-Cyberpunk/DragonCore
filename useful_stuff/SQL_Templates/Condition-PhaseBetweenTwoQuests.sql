SET @StartQUESTID :=  '57677';
SET @FinishQUESTID :=  '57709';
SET @NewPhase := '20002';
SET @NewPhaseName := 'Bastion PelagStarterARest';
SET @PhaseArea := '11473';

INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(@NewPhase, @NewPhaseName);

INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(@PhaseArea, @NewPhase, @NewPhaseName);


INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) 
VALUES('26',@NewPhase,@PhaseArea,'0','0','47','0',@FinishQUESTID,'64','0','1','0','0','','Allow Phase 14027 if Quest 59774 IS NOT complete/rewarded');
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) 
VALUES('26',@NewPhase,@PhaseArea,'0','0','47','0',@StartQUESTID,'66','0','0','0','0','','Allow Phase 14027 if Quest 59774 IS complete/rewarded');





