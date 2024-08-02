QUESTID := 6684700;
ACHIVMENTD := 16343;

DELIMITER //
CREATE TRIGGER `Vault of Inc. Myth` AFTER INSERT ON `character_queststatus_daily` FOR EACH ROW
BEGIN
  IF NEW.`quest` = 6684700 AND NOT EXISTS (SELECT * FROM `character_achievement` WHERE `guid` = NEW.`guid` AND `achievement` = 16354) THEN
    INSERT INTO `character_achievement` (`guid`, `achievement`, `date`) VALUES (NEW.`guid`, 16354, UNIX_TIMESTAMP());
  END IF;
END//
DELIMITER ;
