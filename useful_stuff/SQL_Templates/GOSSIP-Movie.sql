SET @ENTRY := 150087;
SET @GOSSIP := 900075;
SET @MovieID := 883;
SET @Text := '(Cinematic) Tell me what happened';


REPLACE INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, event_param5, event_param_string, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param7, action_param6, target_type, target_param1, target_param2, target_param3, target_param4, target_x, target_y, target_z, target_o, COMMENT) VALUES(@ENTRY,'0','1','0','62','0','100','0',@GOSSIP,'0','0','0','0','','68',@MovieID,'0','0','0','0','0','0','7','0','0','0','0','0','0','0','0','PlayMovie');
REPLACE INTO gossip_menu_option (MenuID, GossipOptionID, OptionID, OptionNpc, OptionText, OptionBroadcastTextID, LANGUAGE, Flags, ActionMenuID, ActionPoiID, GossipNpcOptionID, BoxCoded, BoxMoney, BoxText, BoxBroadcastTextID, SpellID, OverrideIconID, VerifiedBuild) VALUES(@GOSSIP,@GOSSIP,'0','0','Watch the movie!',@GOSSIP,'0','0','0','0',NULL,'0','0','Watch the movie2','0',NULL,NULL,'0');
REPLACE INTO gossip_menu (MenuID, TextID, VerifiedBuild) VALUES(@GOSSIP,999999999,'0');
REPLACE INTO hotfixes.broadcast_text (TEXT, Text1, ID, LanguageID, ConditionID, EmotesID, Flags, ChatBubbleDurationMs, VoiceOverPriorityID, SoundKitID1, SoundKitID2, EmoteID1, EmoteID2, EmoteID3, EmoteDelay1, EmoteDelay2, EmoteDelay3, VerifiedBuild) VALUES(@Text,@Text ,@GOSSIP,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0');
REPLACE INTO creature_template_gossip (CreatureID, MenuID, VerifiedBuild) VALUES(@ENTRY,@GOSSIP,'47936');
REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES('14',@GOSSIP,@GOSSIP,'0','0','0','0','0','0','0','0','0','0','','Gossip ');

UPDATE Creature_template
SET AIName='SmartAI'
WHERE entry=@ENTRY;




