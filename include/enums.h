#ifndef __ENUMS_H__
#define __ENUMS_H__

typedef enum game_mode_e {
    GAME_MODE_NINTENDO_LOGO,
    GAME_MODE_OPENING_CUTSCENE,
    GAME_MODE_DK_RAP,
    GAME_MODE_DK_TV,
    GAME_MODE_UNKNOWN_4,
    GAME_MODE_MAIN_MENU,
    GAME_MODE_ADVENTURE,
    GAME_MODE_QUIT_GAME,
    GAME_MODE_UNKNOWN_8,
    GAME_MODE_GAME_OVER,
    GAME_MODE_END_SEQUENCE,
    GAME_MODE_DK_THEATRE,
    GAME_MODE_MYSTERY_MENU_MINIGAME,
    GAME_MODE_SNIDES_BONUS_GAME,
    GAME_MODE_END_SEQUENCE_DK_THEATRE
} GameModes;

typedef enum map_e {
    MAP_TEST_MAP,
    MAP_FUNKYS_STORE,
    MAP_DK_ARCADE,
    MAP_KROOL_BARREL_LANKY_MAZE,
    MAP_JAPES_MOUNTAIN,
    MAP_CRANKYS_LAB,
    MAP_JAPES_MINECART,
    MAP_JAPES,
    MAP_JAPES_ARMY_DILLO,
    MAP_JETPAC,
    MAP_KREMLING_KOSH_VERY_EASY,
    MAP_STEALTHY_SNOOP_NORMAL_NO_LOGO,
    MAP_JAPES_SHELL,
    MAP_JAPES_LANKY_CAVE,
    MAP_AZTEC_BEETLE_RACE,
    MAP_SNIDES_HQ,
    MAP_AZTEC_TINY_TEMPLE,
    MAP_HELM,
    MAP_TEETERING_TURTLE_TROUBLE_VERY_EASY,
    MAP_AZTEC_FIVE_DOOR_TEMPLE_DK,
    MAP_AZTEC_LLAMA_TEMPLE,
    MAP_AZTEC_FIVE_DOOR_TEMPLE_DIDDY,
    MAP_AZTEC_FIVE_DOOR_TEMPLE_TINY,
    MAP_AZTEC_FIVE_DOOR_TEMPLE_LANKY,
    MAP_AZTEC_FIVE_DOOR_TEMPLE_CHUNKY,
    MAP_CANDYS_MUSIC_SHOP,
    MAP_FACTORY,
    MAP_FACTORY_CAR_RACE,
    MAP_HELM_LEVEL_INTROS_GAME_OVER,
    MAP_FACTORY_POWER_SHED,
    MAP_GALLEON,
    MAP_GALLEON_KROOLS_SHIP,
    MAP_BATTY_BARREL_BANDIT_EASY,
    MAP_JAPES_CHUNKY_CAVE,
    MAP_DK_ISLES_OVERWORLD,
    MAP_KROOL_BARREL_DK_TARGET_GAME,
    MAP_FACTORY_CRUSHER_ROOM,
    MAP_JAPES_BARREL_BLAST,
    MAP_AZTEC,
    MAP_GALLEON_SEAL_RACE,
    MAP_NINTENDO_LOGO,
    MAP_AZTEC_BARREL_BLAST,
    MAP_TROFF_N_SCOFF,
    MAP_GALLEON_SHIPWRECK_DIDDY_LANKY_CHUNKY,
    MAP_GALLEON_TREASURE_CHEST,
    MAP_GALLEON_MERMAID,
    MAP_GALLEON_SHIPWRECK_DK_TINY,
    MAP_GALLEON_SHIPWRECK_LANKY_TINY,
    MAP_FUNGI,
    MAP_GALLEON_LIGHTHOUSE,
    MAP_KROOL_BARREL_TINY_MUSHROOM_GAME,
    MAP_GALLEON_MECHANICAL_FISH,
    MAP_FUNGI_ANT_HILL,
    MAP_BATTLE_ARENA_BEAVER_BRAWL,
    MAP_GALLEON_BARREL_BLAST,
    MAP_FUNGI_MINECART,
    MAP_FUNGI_DIDDY_BARN,
    MAP_FUNGI_DIDDY_ATTIC,
    MAP_FUNGI_LANKY_ATTIC,
    MAP_FUNGI_DK_BARN,
    MAP_FUNGI_SPIDER,
    MAP_FUNGI_FRONT_PART_OF_MILL,
    MAP_FUNGI_REAR_PART_OF_MILL,
    MAP_FUNGI_MUSHROOM_PUZZLE,
    MAP_FUNGI_GIANT_MUSHROOM,
    MAP_STEALTHY_SNOOP_NORMAL,
    MAP_MAD_MAZE_MAUL_HARD,
    MAP_STASH_SNATCH_NORMAL,
    MAP_MAD_MAZE_MAUL_EASY,
    MAP_MAD_MAZE_MAUL_NORMAL,
    MAP_FUNGI_MUSHROOM_LEAP,
    MAP_FUNGI_SHOOTING_GAME,
    MAP_CAVES,
    MAP_BATTLE_ARENA_KRITTER_KARNAGE,
    MAP_STASH_SNATCH_EASY,
    MAP_STASH_SNATCH_HARD,
    MAP_DK_RAP,
    MAP_MINECART_MAYHEM_EASY,
    MAP_BUSY_BARREL_BARRAGE_EASY,
    MAP_BUSY_BARREL_BARRAGE_NORMAL,
    MAP_MAIN_MENU,
    MAP_TITLE_SCREEN_NOT_FOR_RESALE_VERSION,
    MAP_CAVES_BEETLE_RACE,
    MAP_FUNGI_DOGADON,
    MAP_CAVES_IGLOO_TINY,
    MAP_CAVES_IGLOO_LANKY,
    MAP_CAVES_IGLOO_DK,
    MAP_CASTLE,
    MAP_CASTLE_BALLROOM,
    MAP_CAVES_ROTATING_ROOM,
    MAP_CAVES_SHACK_CHUNKY,
    MAP_CAVES_SHACK_DK,
    MAP_CAVES_SHACK_DIDDY_MIDDLE_PART,
    MAP_CAVES_SHACK_TINY,
    MAP_CAVES_LANKY_HUT,
    MAP_CAVES_IGLOO_CHUNKY,
    MAP_SPLISH_SPLASH_SALVAGE_NORMAL,
    MAP_KLUMSY,
    MAP_CAVES_ICE_CASTLE,
    MAP_SPEEDY_SWING_SORTIE_EASY,
    MAP_CAVES_IGLOO_DIDDY,
    MAP_KRAZY_KONG_KLAMOUR_EASY,
    MAP_BIG_BUG_BASH_VERY_EASY,
    MAP_SEARCHLIGHT_SEEK_VERY_EASY,
    MAP_BEAVER_BOTHER_EASY,
    MAP_CASTLE_TOWER,
    MAP_CASTLE_MINECART,
    MAP_KONG_BATTLE_BATTLE_ARENA,
    MAP_CASTLE_CRYPT_LANKY_TINY,
    MAP_KONG_BATTLE_ARENA_1,
    MAP_FACTORY_BARREL_BLAST,
    MAP_GALLEON_PUFFTOSS,
    MAP_CASTLE_CRYPT_DK_DIDDY_CHUNKY,
    MAP_CASTLE_MUSEUM,
    MAP_CASTLE_LIBRARY,
    MAP_KREMLING_KOSH_EASY,
    MAP_KREMLING_KOSH_NORMAL,
    MAP_KREMLING_KOSH_HARD,
    MAP_TEETERING_TURTLE_TROUBLE_EASY,
    MAP_TEETERING_TURTLE_TROUBLE_NORMAL,
    MAP_TEETERING_TURTLE_TROUBLE_HARD,
    MAP_BATTY_BARREL_BANDIT_EASY_2,
    MAP_BATTY_BARREL_BANDIT_NORMAL,
    MAP_BATTY_BARREL_BANDIT_HARD,
    MAP_MAD_MAZE_MAUL_INSANE,
    MAP_STASH_SNATCH_INSANE,
    MAP_STEALTHY_SNOOP_VERY_EASY,
    MAP_STEALTHY_SNOOP_EASY,
    MAP_STEALTHY_SNOOP_HARD,
    MAP_MINECART_MAYHEM_NORMAL,
    MAP_MINECART_MAYHEM_HARD,
    MAP_BUSY_BARREL_BARRAGE_HARD,
    MAP_SPLISH_SPLASH_SALVAGE_HARD,
    MAP_SPLISH_SPLASH_SALVAGE_EASY,
    MAP_SPEEDY_SWING_SORTIE_NORMAL,
    MAP_SPEEDY_SWING_SORTIE_HARD,
    MAP_BEAVER_BOTHER_NORMAL,
    MAP_BEAVER_BOTHER_HARD,
    MAP_SEARCHLIGHT_SEEK_EASY,
    MAP_SEARCHLIGHT_SEEK_NORMAL,
    MAP_SEARCHLIGHT_SEEK_HARD,
    MAP_KRAZY_KONG_KLAMOUR_NORMAL,
    MAP_KRAZY_KONG_KLAMOUR_HARD,
    MAP_KRAZY_KONG_KLAMOUR_INSANE,
    MAP_PERIL_PATH_PANIC_VERY_EASY,
    MAP_PERIL_PATH_PANIC_EASY,
    MAP_PERIL_PATH_PANIC_NORMAL,
    MAP_PERIL_PATH_PANIC_HARD,
    MAP_BIG_BUG_BASH_EASY,
    MAP_BIG_BUG_BASH_NORMAL,
    MAP_BIG_BUG_BASH_HARD,
    MAP_CASTLE_DUNGEON,
    MAP_HELM_INTRO_STORY,
    MAP_DK_ISLES_DK_THEATRE,
    MAP_FACTORY_MAD_JACK,
    MAP_BATTLE_ARENA_ARENA_AMBUSH,
    MAP_BATTLE_ARENA_MORE_KRITTER_KARNAGE,
    MAP_BATTLE_ARENA_FOREST_FRACAS,
    MAP_BATTLE_ARENA_BISH_BASH_BRAWL,
    MAP_BATTLE_ARENA_KAMIKAZE_KREMLINGS,
    MAP_BATTLE_ARENA_PLINTH_PANIC,
    MAP_BATTLE_ARENA_PINNACLE_PALAVER,
    MAP_BATTLE_ARENA_SHOCKWAVE_SHOWDOWN,
    MAP_CASTLE_BASEMENT,
    MAP_CASTLE_TREE,
    MAP_KROOL_BARREL_DIDDY_KREMLING_GAME,
    MAP_CASTLE_CHUNKY_TOOLSHED,
    MAP_CASTLE_TRASH_CAN,
    MAP_CASTLE_GREENHOUSE,
    MAP_JAPES_LOBBY,
    MAP_HELM_LOBBY,
    MAP_DK_HOUSE,
    MAP_ROCK_INTRO_STORY,
    MAP_AZTEC_LOBBY,
    MAP_GALLEON_LOBBY,
    MAP_FACTORY_LOBBY,
    MAP_TRAINING_GROUNDS,
    MAP_DIVE_BARREL,
    MAP_FUNGI_LOBBY,
    MAP_GALLEON_SUBMARINE,
    MAP_ORANGE_BARREL,
    MAP_BARREL_BARREL,
    MAP_VINE_BARREL,
    MAP_CASTLE_CRYPT,
    MAP_ENGUARDE_ARENA,
    MAP_CASTLE_CAR_RACE,
    MAP_CAVES_BARREL_BLAST,
    MAP_CASTLE_BARREL_BLAST,
    MAP_FUNGI_BARREL_BLAST,
    MAP_FAIRY_ISLAND,
    MAP_KONG_BATTLE_ARENA_2,
    MAP_RAMBI_ARENA,
    MAP_KONG_BATTLE_ARENA_3,
    MAP_CASTLE_LOBBY,
    MAP_CAVES_LOBBY,
    MAP_DK_ISLES_SNIDES_ROOM,
    MAP_CAVES_ARMY_DILLO,
    MAP_AZTEC_DOGADON,
    MAP_TRAINING_GROUNDS_END_SEQUENCE,
    MAP_CASTLE_KING_KUT_OUT,
    MAP_CAVES_SHACK_DIDDY_UPPER_PART,
    MAP_KROOL_BARREL_DIDDY_ROCKETBARREL_GAME,
    MAP_KROOL_BARREL_LANKY_SHOOTING_GAME,
    MAP_KROOL_FIGHT_DK_PHASE,
    MAP_KROOL_FIGHT_DIDDY_PHASE,
    MAP_KROOL_FIGHT_LANKY_PHASE,
    MAP_KROOL_FIGHT_TINY_PHASE,
    MAP_KROOL_FIGHT_CHUNKY_PHASE,
    MAP_BLOOPERS_ENDING,
    MAP_KROOL_BARREL_CHUNKY_HIDDEN_KREMLING_GAME,
    MAP_KROOL_BARREL_TINY_PONY_TAIL_TWIRL_GAME,
    MAP_KROOL_BARREL_CHUNKY_SHOOTING_GAME,
    MAP_KROOL_BARREL_DK_RAMBI_GAME,
    MAP_KLUMSY_ENDING,
    MAP_KROOLS_SHOE,
    MAP_KROOLS_ARENA
} Maps;

typedef enum actors_e {
    ACTOR_UNKNOWN_0,
    ACTOR_UNKNOWN_1,
    ACTOR_DK,
    ACTOR_DIDDY,
    ACTOR_LANKY,
    ACTOR_TINY,
    ACTOR_CHUNKY,
    ACTOR_KRUSHA,
    ACTOR_RAMBI,
    ACTOR_ENGUARDE,
    ACTOR_UNKNOWN_10, // Always loaded, not sure what it is
    ACTOR_UNKNOWN_11, // Always loaded, not sure what it is
    ACTOR_LOADING_ZONE_CONTROLLER, // Always loaded
    ACTOR_OBJECT_MODEL_2_CONTROLLER, // Always loaded
    ACTOR_UNKNOWN_14, // Always loaded, not sure what it is
    ACTOR_UNKNOWN_15, // Always loaded, not sure what it is
    ACTOR_UNKNOWN_16,
    ACTOR_CANNON_BARREL,
    ACTOR_RAMBI_CRATE,
    ACTOR_BARREL_DIDDY_5DI,
    ACTOR_CAMERA_FOCUS_POINT, // Exists during some cutscenes
    ACTOR_PUSHABLE_BOX, // Unused
    ACTOR_BARREL_SPAWNER_UNUSED, // Unused
    ACTOR_CANNON,
    ACTOR_VULTURE_RACE_HOOP,
    ACTOR_HUNKY_CHUNKY_BARREL,
    ACTOR_TNT_BARREL,
    ACTOR_TNT_BARREL_SPAWNER, // Army Dillo
    ACTOR_BONUS_BARREL,
    ACTOR_MINECART,
    ACTOR_BOSS_PROJECTILE_FIREBALL,
    ACTOR_CASTLE_BRIDGE,
    ACTOR_SWINGING_LIGHT,
    ACTOR_VINE_BROWN,
    ACTOR_KREMLING_KOSH_CONTROLLER,
    ACTOR_PROJECTILE_MELON,
    ACTOR_PROJECTILE_PEANUT,
    ACTOR_ROCKETBARREL_ON_KONG,
    ACTOR_PROJECTILE_PINEAPPLE,
    ACTOR_LARGE_BRIDGE, // Unused
    ACTOR_MINI_MONKEY_BARREL,
    ACTOR_PROJECTILE_ORANGE,
    ACTOR_PROJECTILE_GRAPE,
    ACTOR_PROJECTILE_FEATHER,
    ACTOR_BOSS_PROJECTILE_LASER,
    ACTOR_GOLDEN_BANANA, // Vulture, bonus barrels, probably some other places
    ACTOR_TTT_GUN,
    ACTOR_WATERMELON_SLICE,
    ACTOR_PROJECTILE_COCONUTS,
    ACTOR_ROCKETBARREL,
    ACTOR_PROJECTILE_LIME,
    ACTOR_AMMO_CRATE, // Dropped by Red Klaptrap
    ACTOR_ORANGE_PICKUP, // Dropped by Klump & Purple Klaptrap
    ACTOR_BANANA_COIN, // Dropped by "Diddy", otherwise unused?
    ACTOR_DK_COIN, // Minecart
    ACTOR_SMALL_EXPLOSION, // Seasick Chunky
    ACTOR_ORANGSTAND_SPRINT_BARREL,
    ACTOR_STRONG_KONG_BARREL,
    ACTOR_SWINGING_LIGHT_2,
    ACTOR_BOSS_PROJECTILE_FIREBALL_2,
    ACTOR_BANAPORTER,
    ACTOR_BOULDER,
    ACTOR_MINECART_DK,
    ACTOR_VASE_OVAL,
    ACTOR_VASE_DOTS,
    ACTOR_VASE_TRIANGLE,
    ACTOR_VASE_PLUS,
    ACTOR_CANNON_BALL,
    ACTOR_UNKNOWN_68,
    ACTOR_VINE, // Green
    ACTOR_COUNTER, // Unused?
    ACTOR_KREMLING_RED, // Lanky's Keyboard Game in R&D
    ACTOR_BOSS_KEY,
    ACTOR_GALLEON_CANNON, // Galleon Minigame
    ACTOR_GALLEON_CANNON_BALL, // Galleon Minigame Projectile
    ACTOR_BLUEPRINT_DIDDY,
    ACTOR_BLUEPRINT_CHUNKY,
    ACTOR_BLUEPRINT_LANKY,
    ACTOR_BLUEPRINT_DK,
    ACTOR_BLUEPRINT_TINY,
    ACTOR_MINECART_CHUNKY,
    ACTOR_BOSS_FIRE_SPAWNER, // TODO: Verify
    ACTOR_BOULDER_DEBRIS, // Minecart
    ACTOR_SPIDER_WEB, // Fungi miniBoss
    ACTOR_STEEL_KEG_SPAWNER,
    ACTOR_STEEL_KEG,
    ACTOR_CROWN,
    ACTOR_MINECART_BONUS,
    ACTOR_UNKNOWN_88,
    ACTOR_FIRE_UNUSED,
    ACTOR_ICE_WALL,
    ACTOR_BALLOON_DIDDY,
    ACTOR_STALACTITE,
    ACTOR_ROCK_DEBRIS, // Rotating, Unused?
    ACTOR_CAR, // Unused?
    ACTOR_PAUSE_MENU,
    ACTOR_HUNKY_CHUNKY_BARREL_DOGADON,
    ACTOR_TNT_BARREL_SPAWNER_DOGADON,
    ACTOR_TAG_BARREL,
    ACTOR_FIREBALL_GET_OUT, // Get Out
    ACTOR_DIDDY_5DI_PAD_1,
    ACTOR_DIDDY_5DI_PAD_2,
    ACTOR_DIDDY_5DI_PAD_3,
    ACTOR_DIDDY_5DI_PAD_4,
    ACTOR_DIDDY_5DI_PAD_5,
    ACTOR_DIDDY_5DI_PAD_6,
    ACTOR_KONG_REFLECTION,
    ACTOR_BONUS_BARREL_HELM,
    ACTOR_UNKNOWN_108
    /*
    [109] = "Race Checkpoint",
    [110] = "CB Bunch", // Unused? Doesn't seem to work, these are normally model 2
    ACTOR_BALLOON_CHUNKY,
    ACTOR_BALLOON_TINY,
    ACTOR_BALLOON_LANKY,
    ACTOR_BALLOON_DK,
    [115] = "K. Lumsy's Cage", // TODO: Also rabbit race finish line?
    [116] = "Chain",
    [117] = "Beanstalk",
    [118] = "Yellow ?", // Unused?
    [119] = "CB Single (Blue)", // Unused? Doesn't seem to work, these are normally model 2
    [120] = "CB Single (Yellow)", // Unused? Doesn't seem to work, these are normally model 2
    [121] = "Crystal Coconut", // Unused? Doesn't seem to work, these are normally model 2
    [122] = "DK Coin", // Multiplayer
    [123] = "Kong Mirror", // Creepy Castle Museum
    [124] = "Barrel Gun", // Peril Path Panic
    [125] = "Barrel Gun", // Krazy Kong Klamour
    [126] = "Fly Swatter",
    [127] = "Searchlight", // Searchlight Seek
    ACTOR_HEADPHONES,
    [129] = "Enguarde Crate",
    [130] = "Apple", // Fungi
    [131] = "Worm", // Fungi
    [132] = "Enguarde Crate (Unused?)",
    [133] = "Barrel",
    [134] = "Training Barrel",
    [135] = "Boombox", // Treehouse
    [136] = "Tag Barrel",
    [137] = "Tag Barrel", // Troff'n'Scoff
    ACTOR_B_LOCKER,
    ACTOR_RAINBOW_COIN_PATCH,
    ACTOR_RAINBOW_COIN,
    ACTOR_UNKNOWN_141,
    ACTOR_UNKNOWN_142,
    ACTOR_UNKNOWN_143,
    ACTOR_UNKNOWN_144,
    [145] = "Cannon (Seasick Chunky)", // Internal name "Puffer cannon"
    ACTOR_UNKNOWN_146,
    [147] = "Balloon (Unused - K. Rool)", // Internal Name: K. Rool Banana Balloon, unsure of purpose. Can only be popped by Lanky
    [148] = "Rope", // K. Rool's Arena
    [149] = "Banana Barrel", // Lanky Phase
    [150] = "Banana Barrel Spawner", // Lanky Phase, internal name "Skin barrel generator"
    ACTOR_UNKNOWN_151,
    ACTOR_UNKNOWN_152,
    ACTOR_UNKNOWN_153,
    ACTOR_UNKNOWN_154,
    ACTOR_UNKNOWN_155,
    ACTOR_WRINKLY,
    ACTOR_UNKNOWN_157,
    ACTOR_UNKNOWN_158,
    ACTOR_UNKNOWN_159,
    ACTOR_UNKNOWN_160,
    ACTOR_UNKNOWN_161,
    ACTOR_UNKNOWN_162,
    [163] = "Banana Fairy (BFI)",
    [164] = "Ice Tomato",
    [165] = "Tag Barrel (King Kut Out)",
    [166] = "King Kut Out Part",
    [167] = "Cannon",
    ACTOR_UNKNOWN_168,
    [169] = "Pufftup", // Pufftoss Fight
    [170] = "Damage Source", // K. Rool's Glove
    [171] = "Orange", // Krusha's Gun
    [173] = "Cutscene Controller",
    ACTOR_UNKNOWN_174,
    [175] = "Kaboom",
    [176] = "Timer",
    [177] = "Timer Controller", // Pufftoss Fight & Fac Beaver Bother Spawn Timer
    [178] = "Beaver", // Blue
    [179] = "Shockwave (Mad Jack)",
    [180] = "Krash", // Minecart Club Guy
    [181] = "Book", // Castle Library
    [182] = "Klobber",
    [183] = "Zinger",
    [184] = "Snide",
    [185] = "Army Dillo",
    [186] = "Kremling", // Kremling Kosh
    [187] = "Klump",
    [188] = "Camera",
    [189] = "Cranky",
    [190] = "Funky",
    [191] = "Candy",
    [192] = "Beetle", // Race
    [193] = "Mermaid",
    [194] = "Vulture",
    [195] = "Squawks",
    [196] = "Cutscene DK",
    [197] = "Cutscene Diddy",
    [198] = "Cutscene Lanky",
    [199] = "Cutscene Tiny",
    [200] = "Cutscene Chunky",
    [201] = "Llama",
    [202] = "Fairy Picture",
    [203] = "Padlock (T&S)",
    [204] = "Mad Jack",
    [205] = "Klaptrap", // Green
    [206] = "Zinger",
    [207] = "Vulture (Race)",
    [208] = "Klaptrap (Purple)",
    [209] = "Klaptrap (Red)",
    [210] = "GETOUT Controller",
    [211] = "Klaptrap (Skeleton)",
    [212] = "Beaver (Gold)",
    [213] = "Fire Column Spawner", // Japes Minecart
    [214] = "Minecart (TNT)", // Minecart Mayhem
    [215] = "Minecart (TNT)",
    [216] = "Pufftoss",
    ACTOR_UNKNOWN_217,
    [218] = "Handle",
    [219] = "Slot",
    [220] = "Cannon (Seasick Chunky)",
    [221] = "Light Piece", // Lanky Phase
    [222] = "Banana Peel", // Lanky Phase
    [223] = "Fireball Spawner", // Factory Crusher Room
    [224] = "Mushroom Man",
    ACTOR_UNKNOWN_225,
    [226] = "Troff",
    [227] = "K. Rool's Foot", // Including leftmost toe
    [228] = "Bad Hit Detection Man",
    [229] = "K. Rool's Toe", // Rightmost 3 toes
    [230] = "Ruler",
    [231] = "Toy Box",
    [232] = "Text Overlay",
    [233] = "Squawks",
    [234] = "Scoff",
    [235] = "Robo-Kremling",
    [236] = "Dogadon",
    ACTOR_UNKNOWN_237,
    [238] = "Kremling",
    [239] = "Bongos",
    [240] = "Spotlight Fish",
    [241] = "Kasplat (DK)",
    [242] = "Kasplat (Diddy)",
    [243] = "Kasplat (Lanky)",
    [244] = "Kasplat (Tiny)",
    [245] = "Kasplat (Chunky)",
    [246] = "Mechanical Fish",
    [247] = "Seal",
    [248] = "Banana Fairy",
    [249] = "Squawks with spotlight",
    [250] = "Owl",
    [251] = "Spider miniBoss",
    [252] = "Rabbit", // Fungi
    [253] = "Nintendo Logo",
    [254] = "Cutscene Object", // For objects animated by Cutscenes
    [255] = "Shockwave",
    [256] = "Minigame Controller",
    [257] = "Fire Breath Spawner", // Aztec Beetle Race
    [258] = "Shockwave", // Boss
    [259] = "Guard", // Stealthy Snoop
    [260] = "Text Overlay", // K. Rool boss
    [261] = "Robo-Zinger",
    [262] = "Krossbones",
    [263] = "Fire Shockwave (Dogadon)",
    [264] = "Squawks",
    [265] = "Light beam", // Boss bosss etc
    [266] = "DK Rap Controller", // Handles the lyrics etc
    [267] = "Shuri",
    [268] = "Gimpfish",
    [269] = "Mr. Dice",
    [270] = "Sir Domino",
    [271] = "Mr. Dice",
    [272] = "Rabbit",
    [273] = "Fireball (With Glasses)", // From Chunky 5DI
    ACTOR_UNKNOWN_274,
    [275] = "K. Lumsy",
    [276] = "Spiderling",
    [277] = "Squawks",
    [278] = "Projectile", // Spider miniBoss
    [279] = "Trap Bubble", // Spider miniBoss
    [280] = "Spider Silk String", // Spider miniBoss
    [281] = "K. Rool (DK Phase)",
    [282] = "Retexturing Controller", // Beaver Bother
    [283] = "Skeleton Head",
    ACTOR_UNKNOWN_284,
    [285] = "Bat",
    [286] = "Giant Clam",
    ACTOR_UNKNOWN_287,
    [288] = "Tomato", // Fungi
    [289] = "Kritter-in-a-Sheet",
    [290] = "Pufftup",
    [291] = "Kosha",
    [292] = "K. Rool (Diddy Phase)",
    [293] = "K. Rool (Lanky Phase)",
    [294] = "K. Rool (Tiny Phase)",
    [295] = "K. Rool (Chunky Phase)",
    ACTOR_UNKNOWN_296,
    [297] = "Battle Crown Controller",
    ACTOR_UNKNOWN_298,
    [299] = "Textbox",
    [300] = "Snake", // Teetering Turtle Trouble
    [301] = "Turtle", // Teetering Turtle Trouble
    [302] = "Toy Car", // Player in the Factory Toy Car Race
    [303] = "Toy Car",
    [304] = "Camera", // Factory Toy Car Race
    [305] = "Missile", // Car Race
    ACTOR_UNKNOWN_306,
    ACTOR_UNKNOWN_307,
    [308] = "Seal",
    [309] = "Kong Logo (Instrument)", // DK for DK, Star for Diddy, DK for Lanky, Flower for Tiny, DK for Chunky
    [310] = "Spotlight", // Tag barrel, instrument etc.
    [311] = "Race Checkpoint", // Seal race & Castle car race
    [312] = "Minecart (TNT)",
    [313] = "Idle Particle",
    [314] = "Rareware Logo",
    ACTOR_UNKNOWN_315,
    [316] = "Kong (Tag Barrel)",
    [317] = "Locked Kong (Tag Barrel)",
    ACTOR_UNKNOWN_318,
    [319] = "Propeller (Boat)",
    [320] = "Potion", // Cranky Purchase
    [321] = "Fairy (Refill)", // Refill Fairy
    [322] = "Car", // Car Race
    [323] = "Enemy Car", // Car Race, aka George
    [324] = "Text Overlay Controller", // Candy's
    [325] = "Shockwave", // Simian Slam
    [326] = "Main Menu Controller",
    [327] = "Kong", // Krazy Kong Klamour
    [328] = "Klaptrap", // Peril Path Panic
    [329] = "Fairy", // Peril Path Panic
    [330] = "Bug", // Big Bug Bash
    [331] = "Klaptrap", // Searchlight Seek
    [332] = "Big Bug Bash Controller?", // TODO: Fly swatter?
    [333] = "Barrel (Main Menu)",
    [334] = "Padlock (K. Lumsy)",
    [335] = "Snide's Menu",
    [336] = "Training Barrel Controller",
    [337] = "Multiplayer Model (Main Menu)",
    [338] = "End Sequence Controller",
    [339] = "Arena Controller", // Rambi/Enguarde
    [340] = "Bug", // Trash Can
    ACTOR_UNKNOWN_341,
    [342] = "Try Again Dialog",
    [343] = "Pause Menu", // Mystery menu bosses
    */
} Actors;

typedef enum sfx_e{
    SFX_0_SILENCE,
    
    SFX_40_ARCADE_JUMPMAN_MOVING = 0x40,
    SFX_41_ARCADE_JUMPMAN_JUMPING,
    SFX_42_ARCADE_JUMPMAN_HIT,
    SFX_43_ARCADE_SPRING_SPRINGING,
    SFX_44_ARCADE_SPRING_FALL,
    SFX_45_ARCADE_POINTS,
    SFX_46_ARCADE_INTRO,

    SFX_48_ARCADE_RUNNING_OUT_OF_TIME = 0x48,
    SFX_49_ARCADE_HAMMER_MUSIC,

    SFX_4B_ARCADE_HAMMER_ATTACK = 0x4b,
    SFX_4C_ARCADE_PAULINE_SAVED_STAGE,
    SFX_4D_ARCADE_25M,
    SFX_4E_ARCADE_100M,
    SFX_4F_ARCADE_50M,

    SFX_53_ARCADE_DK_GRUNT = 0x53,
    SFX_54_ARCADE_JUMPMAN_DEATH
} SFX_E;

// TODO: Maybe we should just define these with preprocessor macros, unless there's a way to make this enum explicitly u8
typedef enum flagtype_e {
    FLAG_TYPE_PERMANENT,
    FLAG_TYPE_GLOBAL,
    FLAG_TYPE_TEMPORARY
} FlagTypes;

#endif
