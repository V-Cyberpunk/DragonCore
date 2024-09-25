# ![logo](logo.png) <br> DragonCore

DragonCore is a derivative of the last Dragonflight revision from TrinityCore and last Dragonflight RetailCore DB!<br>
Target version is 10.2.7.<br>
DB and Data files are in the Release section.<br><br>

## DragonCore Features

* supports Dragonflight 10.2.7.55664
* dragonriding
* crafting
* map questmarker
* reagent bag and bag sorting
* offline extractor tools
* connection_patcher
* cert_creator

## connection_patcher / cert_creator How To

* no Arctium Launcher needed
* Use: connection_patcher <path_to_wow_exe>/Wow.exe
* Choose a domain name. e.g. wow.df, use your own domain name ;)
* create a self signed cert for wow.df: execute cert_creator and enter your domain name. Both files will be created and are already in the correct dir if you execute from your bin dir. Valid for 10 years.
* move these two files to your bin dir of your server if the files are NOT already in your bin dir
* on Windows, double click the crt, Install Certificate -> Local Machine -> Place certificate in the following store: Trusted Root Certification Authorities
* edit bnetserver.conf<br>
LoginREST.ExternalAddress="wow.df"
* update your realmlist with mysql: UPDATE realmlist SET address = 'wow.df';
* update client portal. open <wow_dir>/\_retail\_/WTF/Config.wtf if not there, start wow first and close. change SET portal entry "SET portal "wow.df"
* create a DNS A record, if you have DNS server or use the hosts file, on Windows it's at C:\Windows\System32\drivers\etc\hosts, to redirect the domain wow.df to your ip

Thanks to motivewc with the cert inspiration. Had the patching month ago but didn't thought about the certs to import. But it's logically. :D

<br><br>
More documentation here: https://trinitycore.info/
<br><br>

## RetailCoreDB Features from the RetailCoreDB Readme
<br>
Contentprogress:
<br><br>
Dragonflight:<br>
10.0 Content:<br>
Dracthyr Spells are hackfixed ^^<br>
Native Dragonriding Mounts can fly as normat Flying Mounts<br>
<br><br>
Dragonriding Glyphs:<br>
Waking Shore - Complete<br>
Ohn'ahran Plains - Complete<br>
Azure Span - WIP<br>
Thaldraszus<br>
<br><br><br>

Dragon Races:<br>
In Development<br>
<br><br>
Dractyr-Startzone <br>
Intro Horde - Complete<br>
Intro  Alliance - Complete<br>
<br><br>
Dragon Isles:<br>
Intro Horde - Complete<br>
Intro Alliance - Complete<br>
The Waking Shore -  Complete<br>
Ohn'ahran Plains - Compelte<br>
Azure Span - Complete<br>
Thaldraszus - Complete<br>
<br><br>
Faction Campaign:<br>
Dragon Isles Emissary - Complete<br>
The Mother Oathstone - Complete<br>
The Chieftain's Duty<br>
A Mystery, Sealed<br>
The Silver Purpose<br>
In the Halls of Titans<br>
Garden of Secrets<br>
The Dreamer<br>
The Spark of Ingenuity<br>
<br><br>
Forbitten Reach 10.0.7:<br>
Hidden Legacies - Complete<br>
Zskera Vaults - Complete<br>
-Verbal Archaeology  - Complete<br>
-While We Were Sleeping<br>
<br><br>
10.1 Embers of Neltharion :<br>
Breaking Ground - Complete<br>
Sundered Legacy - Complete<br>
The Ancient Bargain - Complete<br>
Inherited Sin - Complete<br>
Inevitable Confrontation - Complete<br>
A Flame, Extinguished - Coming Soon<br>
<br><br>
10.1.5<br>
Dawn of the Infinites -Complete (Just the Dungeon is WIP)<br>
10.1.7 Coalition of Flames Coming Soon<br>
<br><br>
10.2.6 Plunderstorm - Complete as Daily in Arathi Highlands (Queststarter is Zidormi)<br>
Dungeons/RAIDS: <br>
<br><br>
Vault of  incarnation - Complete  (daily quest ist availabe and gives you the achivement after complete)<br>
<br><br>
Aberrus - Spawns Complete (WIP)<br>
 <br><br><br>

Shadowlands: <br>
<br><br>
9.0 Content:<br>
Exil Reach:  - Mainstory - Complete<br>
⚠️Class Content is WIP ⚠️ <br>
<br><br>
Maw Into - Complete<br>
Bastion Campaign - Reworked<br>
Maldraxxus Campaign - Reworked<br>
Ardenweald Campaign - Reworked<br>
Revendreth Campaign - Reworked<br>
<br><br>
Sidequests:<br>
Bastion - Complete<br>
Maldraxxus - Complete<br>
Ardenweald Campaign - Complete<br>
Revendreth Campaign - WIP<br>
<br><br><br>

Covenant:<br>
Kyrian Covenant Campaign - WIP<br>
Necrolord Covenant Campaign - WIP<br>
<br><br>
9.1 Chains of Domination - Complete<br>
<br><br>
9.2 Zereth Mortis: Complete<br>
<br><br>
Battle for Azeroth:<br>
8.0 Content (War Campaign):<br>
<br><br>
Alliance:<br>
Questchain: wowpedia.fandom.com/wiki/Alliance_War_Campaign<br>
Battle for Lordaeron - Reworked<br>
Heart of Azeroth - Reworked<br>
A Nation Divided - Reworked<br>
Mission from the King - Reworked<br>
The Zandalar Campaign - Reworked<br>
Mole Machinations -  Reworked<br>
Heart of Darkness -  Reworked<br>
The Sands of Vol'dun - Reworked<br>
Island Expedition  - Reworked<br>
Uniting Kul Tiras - Reworked<br>
Blood on the Sand - Reworked<br>
Chasing Darkness - Reworked<br>
A Golden Opportunity  - Reworked<br>
Blood in the Water - Reworked<br>
The Strike on Zuldazar - Reworked<br>
<br><br>
Horde:<br>
Battle for Lordaeron - Reworked<br>
Heart of Azeroth - Reworked<br>
The Stormwind Extraction - Reworked<br>
Welcome to Zandalar - Reworked<br>
Mission from the Warchief- Reworked<br>
Drustvar Foothold - Reworked<br>
A Pirate's Life for We - Reworked<br>
Storming In -  Reworked<br>
Island Expedition - Reworked<br>
Uniting Zandalar - Reworked<br>
The First Assault -  Reworked<br>
The Marshal's Grave -  Reworked<br>
Death of a Sage  - Reworked<br>
At the Bottom of the Sea - Reworked<br>
<br><br><br>

8.1/.2/.3 Content:<br>
<br><br>
Alliance:<br>
Beware the Daughter of the Sea - Reworked<br>
Serious Monkey Business  - Reworked<br>
The Treasury Heist - Reworked<br>
Fog of War - Reworked<br>
The Price of Victory - Reworked<br>
My Brother's Keeper - Reworked<br>
The Gathering Storm - Reworked<br>
Stay of Execution - Reworked<br>
Breaking the Cycle - Reworked<br>
<br><br>
Horde:<br>
The Strike on Boralus - Reworked<br>
Norwington Assault - Reworked<br>
Adventures of Gallywix and the G.M.O.D. - Reworked<br>
Escape from Tol Dagor - Reworked<br>
The Fury of the Zandalari  - Reworked<br>
Diverging Paths - Reworked<br>
Lost Honor - Side with Varok - Reworked<br>
Testing Loyalties - Reworked<br>
Dark Consequences - Reworked<br>
Stay of Execution - Reworked<br>
Breaking the Cycle (Saurfang)  - Reworked<br>
<br><br><br>

8.2 Content Nazjatar:<br>
Alliance:<br>
Welcome to Nazjatar - Reworked<br>
Secrets in the Sea - Reworked<br>
Turning the Tide- Reworked<br>
<br><br>
Horde:<br>
Azshara's Trap-  - Reworked<br>
Secrets in the Sea - Reworked<br>
Turning the Tide- Reworked<br>
<br><br><br>

8.3 Vision of NZorth <br>
<br><br>
wowpedia.fandom.com/wiki/An_Unwelcome_Advisor<br>
Alliance - Complete<br>
Horde- Complete<br>
<br><br><br>

Zandalar Kampagne:<br>
Zulduzar - Complete<br>
https://wowpedia.fandom.com/wiki/Zuldazar_storyline<br>
<br><br>
KulTiras Kampagne <br>
Stormsung Valley - Complete<br>
https://wowpedia.fandom.com/wiki/Stormsong_Valley_storyline<br>
<br><br>
Tiragarde Sound -Complete<br>
https://wowpedia.fandom.com/wiki/Tiragarde_Sound_storyline<br>
<br><br>
Drustvar - Complete<br>
https://wowpedia.fandom.com/wiki/Drustvar_storyline<br>
<br><br><br><br><br>




Legion:<br>
<br><br>
Demon Hunter Intro:<br>
Horde  - Complete<br>
Alliance - Complete<br>
<br><br>
7.0 Content:<br>
Alliance:<br>
Intro Week 1 - Complete<br>
Intro Week 2 - Complete<br>
Intro Week 3 - Complete<br>
<br><br>
Horde:<br>
Intro Week 1 - Complete<br>
Intro Week 2 - Complete<br>
Intro Week 3 - Complete<br>
<br><br>
Class Campaign inkl. 7.2 Content:<br>
Demon Hunter - Complete<br>
Death Knight  - Complete<br>
Paladin - Complete<br>
Druid - Complete<br>
Warlock - Complete<br>
Hunter - Complete<br>
Mage - Complete<br>
Priest - Complete<br>
Shamane<br>
Warrior<br>
Monk<br>
Rogue<br>
<br><br>
Campaign:<br>
Highmountains - Complete<br>
Azsuna - Complete<br>
Stormheim - Complete<br>
Val`Shara - Complete<br>
Suramar - Complete<br>
<br><br>
Broken Shore<br>
Mage Tower<br>
<br><br>
7.1 Insurrection <br>
<br><br>
7.3 Argus - Complete<br>
<br><br>
Unlock Allied Races Questline:<br>
...

<br><br><br><br><br>





Warlords of Draenor: <br>
<br><br><br>

Zidormi Time Traveling 🧭 🧳<br>
6.0 Content:<br>
Horde:<br>
<br><br>
Garrison Campaign - WIP<br>
Dark Portal Assalut - Complete<br>
Frostwall -  Complete<br>
Gorgrond - Complete<br>
Talador - Complete<br>
Spires of Arak - Work in Progress<br>
6.2 Garrison Docks Camaign/ Tanaan Jungle 6.2 -<br>
Side Quests (sorting): ....<br>
<br><br><br>

Alliance:<br>
Garrison Campaign - WIP<br>
Dark Portal Assalut - Complete<br>
Shadowmoon Valley - Complete<br>
Gorgrond - Complete<br>
Talador - Complete<br>
Nagrand - Complete<br>
Shadowmoon Valley - Complete<br>
6.2 Garrison Docks Camaign/ Tanaan Jungle 6.2 - Complete<br>
Side Quests (sorting): ....<br>

<br><br><br>

Mists of Pandaria: <br>
5.0 Content:<br>
Panda Starting Zone - Complete<br>
<br><br>
Alliance (Kampagne):<br>
Intro & Jade Forest - Complete <br>
Valley of the four Winds - Complete <br>
Krasarang Wilds  - Complete <br>
Kun-Lai Summit - Complete <br>
Townlong Steppes - Complete<br>
Dread Wastes - Complete<br>
<br><br>
Side Quests (sorting): .... <br>
<br><br>
Horde (Kampagne):<br>
Intro & Jade Forest - Complete <br>
Valley of the four Winds - Complete <br>
Krasarang Wilds - Complete <br>
Kun-Lai Summit - Complete<br>
Townlong Steppes - Complete<br>
Dread Wastes - Complete<br>
<br><br>
Side Quests (sorting): .... <br>
<br><br>
5.1 Campaign: wowpedia.fandom.com/wiki/Krasarang_Wilds_storyline<br>
Operation: Shieldwall - Complete<br>
Dominance Offensives - Complete<br>
<br><br>
5.2 Campaigns: Thunder Isle - Complete<br>
wowpedia.fandom.com/wiki/Isle_of_Thunder_storyline<br>
<br><br>
5.3  Escalation: The King and the Council<br>
wowpedia.fandom.com/wiki/The_King_and_the_Council<br>
<br><br>
5.4 Timeless Isle:<br>
wowpedia.fandom.com/wiki/A_Flash_of_Bronze...<br>
<br><br>
Scenarios:<br>
... <br><br><br><br>



Cataclysm: <br>
<br><br>
4.0 Content:<br>
Worg Zone - complete<br>
Goblin Starting Zone - complete <br>
.
<br><br><br><br>



MOST CONTENT TO WOTLK SHOULD WORK OOB and will be testet from time to time

<br><br><br><br>


Bild<br>
Wrath of the Lichking: <br>
3.0 Content:<br>
<br><br>
Death Knight Start Zone - Complete<br>
<br><br>
Nothing is done <br>
<br><br><br>


The Burning Crusade: <br>
2.0 Content:<br>
<br><br>
Horde:<br>
- Hellfire Peninsula nearly complete<br>
<br><br>
Alliance <br>
<br><br><br>

Classic-Content: 1.0 - 40% preordered questlines <br>
Kalimdor:<br>
Teldrassil - Complete<br>
<br><br>
Eastern.:<br>
Westfall - Complete<br>
Redridge Mount. - Complete<br>
<br><br>
Special Places:<br>
Darkmoon Faire - WIP <br>
