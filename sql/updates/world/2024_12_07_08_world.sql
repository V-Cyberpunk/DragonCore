DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_arcane_pulse';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_spatial_rift_despawn';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_light_judgement';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_make_camp';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_back_camp';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_maghar_orc_racial_ancestors_call';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(260364, 'spell_arcane_pulse'),
(257040, 'spell_spatial_rift_despawn'),
(256893, 'spell_light_judgement'),
(312370, 'spell_make_camp'),
(312372, 'spell_back_camp'),
(274738, 'spell_maghar_orc_racial_ancestors_call');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_evo_soar';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_evo_cosmic_visage';

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(369536, 'spell_evo_soar'),
(351239, 'spell_evo_cosmic_visage');
