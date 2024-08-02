SET @QUESTID :=  90474;
SET @areatrigger := '910237';
SET @map := 2444 ;
SET @xachse := 2338;
SET @yachse := -1351;
SET @zachse := 629;
SET @oache :=  1;

-- Add the text for the creature to say in the creature_text table

REPLACE INTO areatrigger (SpawnId, AreaTriggerId, IsServerSide, MapId, SpawnDifficulties, PosX, PosY, PosZ, Orientation, PhaseUseFlags, PhaseId, PhaseGroup, Shape, ShapeData0, ShapeData1, ShapeData2, ShapeData3, ShapeData4, ShapeData5, ShapeData6, ShapeData7, ScriptName, COMMENT) 
VALUES(@areatrigger,@areatrigger,1,@map,'0,1,2,3,4,6,7,8,9,10,12,14,18,23,33',@xachse,@yachse,@zachse,@oache,1,0,0,0,5,0,0,0,0,0,0,0,"SmartAreaTriggerAI",'0');

REPLACE INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) 
VALUES(@areatrigger,'1','0','0','10','10','0','0','0','0','0','0','46924');

REPLACE INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_X, target_y, target_z, target_o, COMMENT)
VALUES (@areatrigger, 12, 3, 0, 46, 0, 100, 0, 0, 0, 0, 0, 7, @questid, 0, 0, 0, 0, 0, 17, 5, 5, 0, 0, 0);






DELIMITER $$

USE `characters`$$

DROP TRIGGER /*!50032 IF EXISTS */ `Dragon Glyphs: Dragonsprings Summit`$$

CREATE
    /*!50017 DEFINER = 'root'@'localhost' */
    TRIGGER `Dragon Glyphs: Dragonsprings Summit` AFTER INSERT ON `character_queststatus_rewarded` 
    FOR EACH ROW BEGIN
  IF NEW.`quest` = 90497 AND NOT EXISTS (SELECT * FROM `character_achievement` WHERE `guid` = NEW.`guid` AND `achievement` = 16061) THEN
    INSERT INTO `character_achievement` (`guid`, `achievement`, `date`) VALUES (NEW.`guid`, 16061, UNIX_TIMESTAMP());
  END IF;
END;
$$

DELIMITER ;