SET @ACGUID := 304070;
SET @PATH := @ACGUID * 100;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Dorak - Northen Barrens');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 66.85916, -3643.826, 27.43744, NULL, 0),
(@PATH, 1, 66.50076, -3653.195, 27.26537, NULL, 77185),
(@PATH, 2, 66.85916, -3643.826, 27.43744, NULL, 355488),
(@PATH, 3, 69.16949, -3618.468, 28.68636, NULL, 4253);

UPDATE `creature` SET `position_x`= 66.85916, `position_y`= -3643.826, `position_z`= 27.43744, `orientation`= 0, `MovementType`= 2 WHERE `guid`= @ACGUID;

DELETE FROM `creature_addon` WHERE `guid`= @ACGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `SheathState`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@ACGUID, @PATH, 0, 0, 1, 0, 0, '');
