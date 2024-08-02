SET @entry := 108401;
SET @guid :=  20508723;
SET @areatrigger := '9105795';
SET @map := 1220;
SET @xachse := -734.906;
SET @yachse := 4500.55;
SET @zachse := 731.081;
SET @oache :=  1;
SET @text := 'Halduron told me to expect you.You must have went through some trouble to get your hands on this oak and ore. These are tricky materials to work with, but I think you´ll be impressed with the final product. The weapons I´m crafting should be sharp enough to pierce through any armor, and sturdy enough for repeated use. I have to say, I think this might be my finest work yet. Don´t let that weaponry fall into the wrong hands.';

-- Add the text for the creature to say in the creature_text table
REPLACE INTO creature_text (CreatureID, GroupID, ID, TEXT, TYPE, LANGUAGE, Probability, Emote, Duration, Sound, SoundPlayType, BroadcastTextId, TextRange, COMMENT) 
VALUES(@entry,'0','0',@text,'12','0','100','0','0','0','0',@areatrigger,'0',''); 

REPLACE  INTO hotfixes.broadcast_text (`Text`, `Text1`, `ID`, `LanguageID`, `ConditionID`, `EmotesID`, `Flags`, `ChatBubbleDurationMs`, `VoiceOverPriorityID`, `SoundKitID1`, `SoundKitID2`, `EmoteID1`, `EmoteID2`, `EmoteID3`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `VerifiedBuild`) 
VALUES(@text,@text,@areatrigger,'0','0','0','0','0','221970','0','0','0','0','0','4','0','0','1');


REPLACE INTO areatrigger (SpawnId, AreaTriggerId, IsServerSide, MapId, SpawnDifficulties, PosX, PosY, PosZ, Orientation, PhaseUseFlags, PhaseId, PhaseGroup, Shape, ShapeData0, ShapeData1, ShapeData2, ShapeData3, ShapeData4, ShapeData5, ShapeData6, ShapeData7, ScriptName, COMMENT) 
VALUES(@areatrigger,@areatrigger,1,@map,'0,1,2,3,4,6,7,8,9,10,12,14,18,23,33',@xachse,@yachse,@zachse,@oache,1,0,0,0,5,0,0,0,0,0,0,0,"SmartAreaTriggerAI",'0');

REPLACE INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) 
VALUES(@areatrigger,'1','0','0','10','10','0','0','0','0','0','0','46924');

REPLACE INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, COMMENT)
VALUES (@areatrigger, 12, 3, 0, 46, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10, @guid, @entry, 0);


