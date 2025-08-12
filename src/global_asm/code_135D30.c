#include "common.h"

typedef struct {
    u8 unk0;
    // u8 pad1; // Padding
    s16 unk2;
    s16 flagIndex;
    u8 unk6;
    // u8 pad7; // Padding
} Struct80755A20;

//.data
// Flag mapping
// TODO: Get all the item flags in the enum
static Struct80755A20 D_global_asm_80755A20[] = {
    // Japes
    { MAP_JAPES_BARREL_BLAST,                   0x0001, 0x0003,                                     ACTOR_DK },
    { MAP_JAPES,                                0x0069, PERMFLAG_ITEM_GB_JAPES_FRONT_OF_DIDDY_CAGE, ACTOR_DK },
    { MAP_JAPES,                                0x0048, 0x0005,                                     ACTOR_DK },
    { MAP_JAPES_CHUNKY_CAVE,                    0x0003, 0x000C,                                     ACTOR_CHUNKY },
    { MAP_JAPES,                                0x0068, 0x0008,                                     ACTOR_TINY },
    { MAP_JAPES,                                0x004F, 0x0013,                                     ACTOR_LANKY },
    { MAP_JAPES,                                0x004D, 0x0012,                                     ACTOR_DIDDY },
    { MAP_JAPES,                                0x0050, 0x0016,                                     ACTOR_CHUNKY },
    { MAP_JAPES,                                0x004C, 0x0015,                                     ACTOR_TINY },
    { MAP_JAPES,                                0x0044, 0x0014,                                     ACTOR_DK },
    { MAP_JAPES,                                0x0052, 0x0017,                                     ACTOR_DIDDY },
    { MAP_JAPES_SHELL,                          0x003F, 0x0009,                                     ACTOR_TINY },
    { MAP_JAPES_LANKY_CAVE,                     0x0004, PERMFLAG_ITEM_GB_JAPES_PAINTING,            ACTOR_LANKY },
    { MAP_JAPES,                                0x001E, 0x001F,                                     ACTOR_DIDDY },
    // Aztec
    { MAP_AZTEC,                                0x0023, 0x0031,                                     ACTOR_CHUNKY },
    { MAP_AZTEC,                                0x00A3, 0x0036,                                     ACTOR_DIDDY },
    { MAP_AZTEC_FIVE_DOOR_TEMPLE_DIDDY,         0x0006, 0x0038,                                     ACTOR_DIDDY },
    { MAP_AZTEC_FIVE_DOOR_TEMPLE_DK,            0x0006, 0x0039,                                     ACTOR_DK },
    { MAP_AZTEC_FIVE_DOOR_TEMPLE_TINY,          0x0006, 0x003A,                                     ACTOR_TINY },
    { MAP_AZTEC,                                0x00EB, 0x003F,                                     ACTOR_DIDDY },
    { MAP_AZTEC_TINY_TEMPLE,                    0x0009, 0x0040,                                     ACTOR_CHUNKY },
    { MAP_AZTEC_TINY_TEMPLE,                    0x007E, 0x0041,                                     ACTOR_TINY },
    { MAP_AZTEC_TINY_TEMPLE,                    0x005B, 0x0043,                                     ACTOR_DIDDY },
    { MAP_AZTEC_LLAMA_TEMPLE,                   0x00AA, 0x0047,                                     ACTOR_TINY },
    { MAP_AZTEC_LLAMA_TEMPLE,                   0x002B, 0x0048,                                     ACTOR_LANKY },
    { MAP_AZTEC_BEETLE_RACE,                    0x0048, 0x004B,                                     ACTOR_TINY },
    { MAP_AZTEC,                                0x0026, 0x0033,                                     ACTOR_DK },
    { MAP_AZTEC_LLAMA_TEMPLE,                   0x006C, 0x004D,                                     ACTOR_DK },
    // Factory
    { MAP_FACTORY,                              0x002C, 0x0071,                                     ACTOR_DIDDY },
    { MAP_FACTORY,                              0x0029, 0x0072,                                     ACTOR_CHUNKY },
    { MAP_FACTORY,                              0x002A, 0x0073,                                     ACTOR_LANKY },
    { MAP_FACTORY,                              0x0082, 0x007C,                                     ACTOR_TINY },
    { MAP_FACTORY,                              0x003E, 0x007D,                                     ACTOR_LANKY },
    { MAP_FACTORY,                              0x0060, 0x007E,                                     ACTOR_DIDDY },
    { MAP_FACTORY,                              0x0063, 0x0079,                                     ACTOR_CHUNKY },
    { MAP_FACTORY_CRUSHER_ROOM,                 0x0007, 0x0080,                                     ACTOR_DK },
    { MAP_FACTORY,                              0x007E, 0x007A,                                     ACTOR_DK },
    { MAP_FACTORY_CAR_RACE,                     0x0062, 0x008B,                                     ACTOR_TINY },
    { MAP_FACTORY_POWER_SHED,                   0x0002, 0x0070,                                     ACTOR_DK },
    { MAP_FACTORY,                              0x0078, 0x0076,                                     ACTOR_LANKY },
    { MAP_FACTORY,                              0x007C, 0x007F,                                     ACTOR_CHUNKY },
    { MAP_FACTORY,                              0x0108, 0x0082,                                     ACTOR_DK },
    { MAP_FACTORY,                              0x0023, 0x007B,                                     ACTOR_TINY },
    // Galleon
    { MAP_GALLEON,                              0x0032, 0x009A,                                     ACTOR_CHUNKY },
    { MAP_GALLEON,                              0x002E, PERMFLAG_ITEM_GB_GALLEON_SEALFREE,          ACTOR_DK },
    { MAP_GALLEON_KROOLS_SHIP,                  0x0006, 0x00A6,                                     ACTOR_CHUNKY },
    { MAP_GALLEON_MECHANICAL_FISH,              0x000F, 0x00A7,                                     ACTOR_DIDDY },
    { MAP_GALLEON_LIGHTHOUSE,                   0x002F, 0x009D,                                     ACTOR_DK },
    { MAP_GALLEON,                              0x000E, 0x00B6,                                     ACTOR_CHUNKY },
    { MAP_GALLEON_SHIPWRECK_LANKY_TINY,         0x0000, 0x00B7,                                     ACTOR_LANKY },
    { MAP_GALLEON_MERMAID,                      0x000E, PERMFLAG_ITEM_GB_GALLEON_MERMAID,           ACTOR_TINY },
    { MAP_GALLEON,                              0x006B, 0x00C0,                                     ACTOR_LANKY },
    { MAP_GALLEON_SHIPWRECK_DIDDY_LANKY_CHUNKY, 0x000E, 0x00C7,                                     ACTOR_LANKY },
    { MAP_GALLEON_SHIPWRECK_DK_TINY,            0x0021, 0x00C9,                                     ACTOR_TINY },
    { MAP_GALLEON,                              0x002D, 0x00CC,                                     ACTOR_DIDDY },
    // Fungi
    { MAP_FUNGI,                                0x0050, 0x00D1,                                     ACTOR_TINY },
    { MAP_FUNGI,                                0x0028, 0x00D6,                                     ACTOR_DIDDY },
    { MAP_FUNGI_DIDDY_BARN,                     0x0003, 0x00D8,                                     ACTOR_DIDDY },
    { MAP_FUNGI_LANKY_ATTIC,                    0x0002, 0x00D9,                                     ACTOR_LANKY },
    { MAP_FUNGI,                                0x002B, 0x00DB,                                     ACTOR_DK },
    { MAP_FUNGI_FRONT_PART_OF_MILL,             0x000D, 0x00DD,                                     ACTOR_CHUNKY },
    { MAP_FUNGI_SHOOTING_GAME,                  0x0002, 0x00E1,                                     ACTOR_CHUNKY },
    { MAP_FUNGI_GIANT_MUSHROOM,                 0x0003, 0x00E4,                                     ACTOR_DK },
    { MAP_FUNGI_ANT_HILL,                       0x0000, 0x00CD,                                     ACTOR_TINY },
    { MAP_FUNGI,                                0x0057, PERMFLAG_ITEM_GB_FUNGI_RABBIT_RACE,         ACTOR_LANKY },
    { MAP_FUNGI_SPIDER,                         0x0001, PERMFLAG_ITEM_GB_FUNGI_SPIDER_BOSS,         ACTOR_TINY },
    { MAP_FUNGI,                                0x003E, PERMFLAG_ITEM_GB_FUNGI_APPLE,               ACTOR_CHUNKY },
    { MAP_FUNGI_MUSHROOM_LEAP,                  0x0000, 0x00E2,                                     ACTOR_LANKY },
    { MAP_FUNGI,                                0x0039, 0x00FE,                                     ACTOR_DK },
    // Caves
    { MAP_CAVES,                                0x0028, 0x010E,                                     ACTOR_CHUNKY },
    { MAP_CAVES_IGLOO_TINY,                     0x0002, 0x0117,                                     ACTOR_TINY },
    { MAP_CAVES_IGLOO_LANKY,                    0x0003, 0x0119,                                     ACTOR_LANKY },
    { MAP_CAVES,                                0x003E, 0x010C,                                     ACTOR_CHUNKY },
    { MAP_CAVES_LANKY_HUT,                      0x0001, PERMFLAG_ITEM_GB_CAVES_LANKY_CABIN,         ACTOR_LANKY },
    { MAP_CAVES_IGLOO_CHUNKY,                   0x0000, PERMFLAG_ITEM_GB_CAVES_CHUNKY_IGLOO,        ACTOR_CHUNKY },
    { MAP_CAVES_IGLOO_DK,                       0x0001, 0x0113,                                     ACTOR_DK },
    { MAP_CAVES_ROTATING_ROOM,                  0x0001, 0x0114,                                     ACTOR_DK },
    { MAP_CAVES_SHACK_DK,                       0x0008, 0x0105,                                     ACTOR_DK },
    { MAP_CAVES_SHACK_DIDDY_MIDDLE_PART,        0x0001, 0x0106,                                     ACTOR_DIDDY },
    { MAP_CAVES_IGLOO_DIDDY,                    0x0001, PERMFLAG_ITEM_GB_CAVES_DIDDY_IGLOO,         ACTOR_DIDDY },
    { MAP_CAVES_SHACK_TINY,                     0x0000, 0x0104,                                     ACTOR_TINY },
    { MAP_CAVES_BEETLE_RACE,                    0x0001, 0x0103,                                     ACTOR_LANKY },
    { MAP_CAVES_SHACK_DIDDY_UPPER_PART,         0x0004, 0x0125,                                     ACTOR_DIDDY },
    { MAP_CAVES_ICE_CASTLE,                     0x0010, PERMFLAG_ITEM_GB_CAVES_ICE_TOMATO,          ACTOR_LANKY },
    { MAP_CAVES,                                0x0029, 0x0129,                                     ACTOR_TINY },
    { MAP_CAVES,                                0x0032, 0x012A,                                     ACTOR_DK },
    // Castle
    { MAP_CASTLE_CRYPT_LANKY_TINY,              0x0003, 0x0134,                                     ACTOR_LANKY },
    { MAP_CASTLE_CRYPT_LANKY_TINY,              0x000D, 0x0135,                                     ACTOR_TINY },
    { MAP_CASTLE_CRYPT_DK_DIDDY_CHUNKY,         0x0008, 0x0136,                                     ACTOR_DIDDY },
    { MAP_CASTLE_LIBRARY,                       0x0003, 0x0139,                                     ACTOR_DK },
    { MAP_CASTLE_MUSEUM,                        0x0007, 0x013A,                                     ACTOR_CHUNKY },
    { MAP_CASTLE_TREE,                          0x0008, 0x0140,                                     ACTOR_DK },
    { MAP_CASTLE_CHUNKY_TOOLSHED,               0x0006, 0x0142,                                     ACTOR_CHUNKY },
    { MAP_CASTLE_GREENHOUSE,                    0x0001, PERMFLAG_ITEM_GB_CASTLE_GREENHOUSE,         ACTOR_LANKY },
    { MAP_CASTLE_BASEMENT,                      0x000F, PERMFLAG_ITEM_GB_CASTLE_FACE_PUZZLE,        ACTOR_DK },
    { MAP_CASTLE_TRASH_CAN,                     0x0004, PERMFLAG_ITEM_GB_CASTLE_TRASH_CAN,          ACTOR_TINY },
    { MAP_CASTLE_BASEMENT,                      0x000D, 0x0161,                                     ACTOR_DIDDY },
    // Isles
    { MAP_DK_ISLES_OVERWORLD,                   0x0004, 0x017D,                                     ACTOR_DK },
    { MAP_GALLEON_LOBBY,                        0x0009, 0x0193,                                     ACTOR_TINY },
    { MAP_CAVES_LOBBY,                          0x0005, 0x019B,                                     ACTOR_DK },
    { MAP_DK_ISLES_OVERWORLD,                   0x004D, 0x01A3,                                     ACTOR_DK },
    { MAP_DK_ISLES_OVERWORLD,                   0x002E, 0x01A7,                                     ACTOR_DIDDY },
    { MAP_DK_ISLES_OVERWORLD,                   0x002F, 0x01A5,                                     ACTOR_LANKY },
    { MAP_DK_ISLES_OVERWORLD,                   0x002B, 0x01A4,                                     ACTOR_TINY },
    { MAP_DK_ISLES_OVERWORLD,                   0x002D, 0x01A6,                                     ACTOR_CHUNKY },
    { MAP_KLUMSY,                               0x0003, 0x01AD,                                     ACTOR_LANKY },
    { MAP_DK_ISLES_OVERWORLD,                   0x0056, 0x01AF,                                     ACTOR_CHUNKY },
    { MAP_FAIRY_ISLAND,                         0x001E, PERMFLAG_ITEM_ISLES_RAREWARE_GB,            ACTOR_TINY },
    // Helm
    { MAP_HELM,                                 0x005D, PERMFLAG_ITEM_MEDAL_HELM_DK,                ACTOR_DK },
    { MAP_HELM,                                 0x005E, PERMFLAG_ITEM_MEDAL_HELM_CHUNKY,            ACTOR_CHUNKY },
    { MAP_HELM,                                 0x005F, PERMFLAG_ITEM_MEDAL_HELM_LANKY,             ACTOR_LANKY },
    { MAP_HELM,                                 0x0060, PERMFLAG_ITEM_MEDAL_HELM_TINY,              ACTOR_TINY },
    { MAP_HELM,                                 0x0061, PERMFLAG_ITEM_MEDAL_HELM_DIDDY,             ACTOR_DIDDY },
};

typedef struct {
    u8 map;
    // s8 pad1; // Padding
    s16 spawnerID;
    s16 flagIndex;
    u8 unk6;
    //s8 pad7; // Padding
} Struct80755DA8;

// TODO: D_global_asm_80755DAE -> D_global_asm_80755DA8[0].unk6
// TODO: Use map enum
// Character spawner flags
Struct80755DA8 D_global_asm_80755DA8[0x1F] = {
    { MAP_JAPES,                        0x0001, PERMFLAG_KONG_DIDDY,                        FALSE },
    { MAP_JAPES,                        0x0033, PERMFLAG_ITEM_FAIRY_JAPES_POOL,             FALSE },
    { MAP_JAPES_LANKY_CAVE,             0x0007, PERMFLAG_ITEM_FAIRY_JAPES_PAINTING,         FALSE },
    { MAP_AZTEC,                        0x000B, PERMFLAG_PROGRESS_LLAMA_FREE,               FALSE },
    { MAP_AZTEC_LLAMA_TEMPLE,           0x0002, PERMFLAG_PROGRESS_LLAMA_FREE,               TRUE  },
    { MAP_AZTEC_LLAMA_TEMPLE,           0x0001, PERMFLAG_KONG_LANKY,                        FALSE },
    { MAP_AZTEC_TINY_TEMPLE,            0x0013, PERMFLAG_KONG_TINY,                         FALSE },
    { MAP_AZTEC_LLAMA_TEMPLE,           0x000C, PERMFLAG_ITEM_FAIRY_AZTEC_LLAMA_TEMPLE,     FALSE },
    { MAP_AZTEC_FIVE_DOOR_TEMPLE_TINY,  0x000B, PERMFLAG_ITEM_FAIRY_AZTEC_5_DOOR_TEMPLE,    FALSE },
    { MAP_FACTORY,                      0x0001, PERMFLAG_KONG_CHUNKY,                       FALSE },
    { MAP_FACTORY,                      0x005C, PERMFLAG_ITEM_FAIRY_FACTORY_FUNKY,          FALSE },
    { MAP_FACTORY,                      0x0055, PERMFLAG_ITEM_FAIRY_FACTORY_NUMBER_GAME,    FALSE },
    { MAP_GALLEON,                      0x0015, PERMFLAG_ITEM_FAIRY_GALLEON_CHEST,          FALSE },
    { MAP_GALLEON,                      0x0002, PERMFLAG_ITEM_GB_GALLEON_SEALRACE,          FALSE },
    { MAP_GALLEON_SHIPWRECK_DK_TINY,    0x0008, PERMFLAG_ITEM_FAIRY_GALLEON_SHIP,           FALSE },
    { MAP_CAVES_LANKY_HUT,              0x0001, PERMFLAG_ITEM_GB_CAVES_LANKY_CABIN,         FALSE },
    { MAP_CAVES_IGLOO_CHUNKY,           0x0001, PERMFLAG_ITEM_GB_CAVES_CHUNKY_IGLOO,        FALSE },
    { MAP_CAVES_IGLOO_TINY,             0x0003, PERMFLAG_ITEM_FAIRY_CAVES_IGLOO,            FALSE },
    { MAP_CAVES_SHACK_DIDDY_UPPER_PART, 0x0003, PERMFLAG_ITEM_FAIRY_CAVES_CABIN,            FALSE },
    { MAP_FUNGI,                        0x0002, PERMFLAG_ITEM_GB_FUNGI_RABBIT_RACE,         FALSE },
    { MAP_FUNGI_DIDDY_BARN,             0x0002, PERMFLAG_ITEM_FAIRY_FUNGI_ATTIC,            FALSE },
    { MAP_FUNGI_DK_BARN,                0x0002, PERMFLAG_ITEM_FAIRY_FUNGI_BOX,              FALSE },
    { MAP_CASTLE_MUSEUM,                0x0005, PERMFLAG_ITEM_FAIRY_CASTLE_MUSEUM,          FALSE },
    { MAP_CASTLE_TREE,                  0x0004, PERMFLAG_ITEM_FAIRY_CASTLE_TREE,            FALSE },
    { MAP_FACTORY_LOBBY,                0x0002, PERMFLAG_ITEM_FAIRY_ISLES_FACTORY_LOBBY,    FALSE },
    { MAP_FUNGI_LOBBY,                  0x0001, PERMFLAG_ITEM_FAIRY_ISLES_FUNGI_LOBBY,      FALSE },
    { MAP_DK_ISLES_OVERWORLD,           0x0006, PERMFLAG_ITEM_FAIRY_ISLES_TREE,             FALSE },
    { MAP_DK_ISLES_OVERWORLD,           0x0007, PERMFLAG_ITEM_FAIRY_ISLES_KREM_ISLES,       FALSE },
    { MAP_HELM,                         0x0019, PERMFLAG_ITEM_FAIRY_HELM_1,                 FALSE },
    { MAP_HELM,                         0x001A, PERMFLAG_ITEM_FAIRY_HELM_2,                 FALSE },
    { 0xFF,                             NULL,   NULL,                                       FALSE },
};

typedef struct {
    u8 unk0;
    // u8 pad1; // Padding
    s16 unk2;
    s16 flagIndex;
    u8 unk6;
    // u8 pad7; // Padding
} Struct80755EA0;

// TODO: D_global_asm_80755F4C -> D_global_asm_80755EA0[21].flagIndex
// TODO: D_global_asm_80755F4E -> D_global_asm_80755EA0[21].unk6
// Tied Trigger Flags
static Struct80755EA0 D_global_asm_80755EA0[] = {
    { MAP_JAPES,                0x0007, PERMFLAG_CUTSCENE_JAPES_FTCS,                   TRUE  },
    { MAP_JAPES,                0x0012, PERMFLAG_PROGRESS_JAPES_FIRST_GATE_OPENED,      FALSE },
    { MAP_JAPES,                0x0006, PERMFLAG_CUTSCENE_DIDDY_HELP_ME,                TRUE  },
    { MAP_JAPES_LANKY_CAVE,     0x0002, PERMFLAG_ITEM_GB_JAPES_PAINTING,                FALSE },
    { MAP_AZTEC,                0x0016, PERMFLAG_CUTSCENE_LLAMA_FTCS,                   TRUE  },
    { MAP_AZTEC_TINY_TEMPLE,    0x0002, PERMFLAG_CUTSCENE_TINY_HELP_ME,                 TRUE  },
    { MAP_AZTEC_LLAMA_TEMPLE,   0x0002, PERMFLAG_CUTSCENE_LANKY_HELP_ME,                TRUE  },
    { MAP_AZTEC,                0x000C, PERMFLAG_CUTSCENE_AZTEC_FTCS,                   TRUE  },
    { MAP_FACTORY,              0x000A, PERMFLAG_CUTSCENE_CHUNKY_HELP_ME,               FALSE },
    { MAP_FACTORY,              0x0011, PERMFLAG_CUTSCENE_CHUNKY_HELP_ME,               TRUE  },
    { MAP_GALLEON,              0x0016, PERMFLAG_CUTSCENE_GALLEON_FTCS,                 TRUE  },
    { MAP_FUNGI,                0x001A, PERMFLAG_CUTSCENE_FUNGI_FTCS,                   TRUE  },
    { MAP_CAVES_ROTATING_ROOM,  0x0001, PERMFLAG_CUTSCENE_ROTATING_ROOM_FTCS,           TRUE  },
    { MAP_CAVES_IGLOO_DIDDY,    0x0001, PERMFLAG_ITEM_GB_CAVES_DIDDY_IGLOO,             FALSE },
    { MAP_CAVES_IGLOO_CHUNKY,   0x0001, PERMFLAG_ITEM_GB_CAVES_CHUNKY_IGLOO,            FALSE },
    { MAP_CAVES,                0x0019, PERMFLAG_CUTSCENE_CAVES_FTCS,                   TRUE  },
    { MAP_CAVES_IGLOO_DK,       0x0001, PERMFLAG_CUTSCENE_DK_IGLOO_FTCS,                TRUE  },
    { MAP_CASTLE_GREENHOUSE,    0x0001, PERMFLAG_ITEM_GB_CASTLE_GREENHOUSE,             FALSE },
    { MAP_CASTLE,               0x0013, PERMFLAG_CUTSCENE_CASTLE_FTCS,                  TRUE  },
    { MAP_TROFF_N_SCOFF,        0x0007, PERMFLAG_CUTSCENE_TROFF_N_SCOFF_FTCS,           TRUE  },
    { MAP_TRAINING_GROUNDS,     0x0003, PERMFLAG_CUTSCENE_TRAINING_GROUNDS_WATERFALL,   TRUE  },
    { MAP_DK_ISLES_OVERWORLD,   0x0009, PERMFLAG_CUTSCENE_ISLES_FTCS,                   TRUE  },
};

typedef struct {
    s16 unk0;
    u8 unk2;
    // u8 pad3; // padding
} Struct80755F50;

// Bonus Barrel Data
// TODO: Document flags
static Struct80755F50 D_global_asm_80755F50[] = {
    { 0x00E0,                       ACTOR_LANKY },
    { PERMFLAG_ITEM_GB_NULL,        0x00 },
    { 0x0131,                       ACTOR_DIDDY },
    { 0x0132,                       ACTOR_LANKY },
    { 0x0002,                       ACTOR_TINY },
    { 0x0001,                       ACTOR_LANKY },
    { 0x001C,                       ACTOR_CHUNKY },
    { 0x0087,                       ACTOR_DIDDY },
    { 0x00E3,                       ACTOR_TINY },
    { 0x00EB,                       ACTOR_DK },
    { 0x0086,                       ACTOR_DIDDY },
    { 0x0088,                       ACTOR_CHUNKY },
    { 0x0089,                       ACTOR_LANKY },
    { 0x000B,                       ACTOR_LANKY },
    { 0x0074,                       ACTOR_TINY },
    { 0x003C,                       ACTOR_LANKY },
    { 0x003B,                       ACTOR_CHUNKY },
    { 0x0107,                       ACTOR_CHUNKY },
    { 0x0137,                       ACTOR_CHUNKY },
    { 0x013B,                       ACTOR_TINY },
    { 0x00D3,                       ACTOR_DIDDY },
    { 0x0049,                       ACTOR_LANKY },
    { 0x00A3,                       ACTOR_DIDDY },
    { 0x00A4,                       ACTOR_LANKY },
    { 0x013C,                       ACTOR_LANKY },
    { 0x003E,                       ACTOR_DK },
    { 0x0034,                       ACTOR_CHUNKY },
    { 0x013F,                       ACTOR_CHUNKY },
    { 0x0044,                       ACTOR_LANKY },
    { 0x0018,                       ACTOR_DIDDY },
    { 0x00B8,                       ACTOR_TINY },
    { 0x018E,                       ACTOR_LANKY },
    { 0x0192,                       ACTOR_TINY },
    { 0x0194,                       ACTOR_DK },
    { 0x013E,                       ACTOR_DK },
    { 0x00FE,                       ACTOR_DK },
    { 0x0196,                       ACTOR_CHUNKY },
    { 0x019A,                       ACTOR_DIDDY },
    { 0x019F,                       ACTOR_LANKY },
    { 0x01A0,                       ACTOR_DIDDY },
    { 0x01A8,                       ACTOR_CHUNKY },
    { 0x01A9,                       ACTOR_TINY },
    { 0x01AC,                       ACTOR_DIDDY },
    { 0x0126,                       ACTOR_DIDDY },
    { 0x0127,                       ACTOR_TINY },
    { 0x012A,                       ACTOR_DK },
    { 0x00C6,                       ACTOR_DIDDY },
    { 0x00C5,                       ACTOR_CHUNKY },
    { 0x00C8,                       ACTOR_DK },
    { 0x00CA,                       ACTOR_TINY },
    { 0x00FA,                       ACTOR_DIDDY },
    { 0x0019,                       ACTOR_CHUNKY },
    { 0x015E,                       ACTOR_DIDDY },
};

typedef struct {
    s16 startFlagIndex;
    s16 endFlagIndex;
    s16 flagCountRequired;
    s16 globalFlagToSet;
} Struct80756024;

static Struct80756024 D_global_asm_80756024[] = {
    { PERMFLAG_ITEM_FAIRY_JAPES_POOL,      PERMFLAG_ITEM_FAIRY_JAPES_POOL + 20 - 1, 1,  GLOBALFLAG_MYSTERY_MENU }, // Mystery Menu unlocked for 1 fairy
    { PERMFLAG_ITEM_FAIRY_JAPES_POOL,      PERMFLAG_ITEM_FAIRY_JAPES_POOL + 20 - 1, 2,  GLOBALFLAG_CUTSCENE_MENU }, // DK Theatre Menu unlocked for 2 fairies
    { PERMFLAG_ITEM_FAIRY_JAPES_POOL,      PERMFLAG_ITEM_FAIRY_JAPES_POOL + 20 - 1, 6,  GLOBALFLAG_MINIGAME_MENU }, // Minigame Menu unlocked for 6 fairies
    { PERMFLAG_ITEM_FAIRY_JAPES_POOL,      PERMFLAG_ITEM_FAIRY_JAPES_POOL + 20 - 1, 10, GLOBALFLAG_BOSSES_MENU }, // Bosses Menu unlocked for 10 fairies
    { PERMFLAG_ITEM_FAIRY_JAPES_POOL,      PERMFLAG_ITEM_FAIRY_JAPES_POOL + 20 - 1, 15, GLOBALFLAG_KRUSHA_MENU }, // Krusha unlocked for 15 fairies
    { PERMFLAG_ITEM_FAIRY_JAPES_POOL,      PERMFLAG_ITEM_FAIRY_JAPES_POOL + 20 - 1, 20, GLOBALFLAG_CHEATS_MENU }, // Cheats unlocked for 20 fairies
    { PERMFLAG_KONG_DIDDY,                 PERMFLAG_KONG_DIDDY,                     1,  GLOBALFLAG_MULTIPLAYER_DIDDY },
    { PERMFLAG_KONG_LANKY,                 PERMFLAG_KONG_LANKY,                     1,  GLOBALFLAG_MULTIPLAYER_LANKY },
    { PERMFLAG_KONG_TINY,                  PERMFLAG_KONG_TINY,                      1,  GLOBALFLAG_MULTIPLAYER_TINY },
    { PERMFLAG_KONG_CHUNKY,                PERMFLAG_KONG_CHUNKY,                    1,  GLOBALFLAG_MULTIPLAYER_CHUNKY },
    { PERMFLAG_ITEM_CROWN_JAPES,           PERMFLAG_ITEM_CROWN_JAPES + 10 - 1,      1,  GLOBALFLAG_MULTIPLAYER_MENU },
    { PERMFLAG_LEVEL_ENTERED_JAPES,        PERMFLAG_LEVEL_ENTERED_JAPES,            1,  GLOBALFLAG_CUTSCENE_JAPES_INTRO },
    { PERMFLAG_LEVEL_ENTERED_AZTEC,        PERMFLAG_LEVEL_ENTERED_AZTEC,            1,  GLOBALFLAG_CUTSCENE_AZTEC_INTRO },
    { PERMFLAG_LEVEL_ENTERED_FACTORY,      PERMFLAG_LEVEL_ENTERED_FACTORY,          1,  GLOBALFLAG_CUTSCENE_FACTORY_INTRO },
    { PERMFLAG_LEVEL_ENTERED_GALLEON,      PERMFLAG_LEVEL_ENTERED_GALLEON,          1,  GLOBALFLAG_CUTSCENE_GALLEON_INTRO },
    { PERMFLAG_LEVEL_ENTERED_FUNGI,        PERMFLAG_LEVEL_ENTERED_FUNGI,            1,  GLOBALFLAG_CUTSCENE_FUNGI_INTRO },
    { PERMFLAG_LEVEL_ENTERED_CAVES,        PERMFLAG_LEVEL_ENTERED_CAVES,            1,  GLOBALFLAG_CUTSCENE_CAVES_INTRO },
    { PERMFLAG_LEVEL_ENTERED_CASTLE,       PERMFLAG_LEVEL_ENTERED_CASTLE,           1,  GLOBALFLAG_CUTSCENE_CASTLE_INTRO },
    { PERMFLAG_LEVEL_ENTERED_HELM,         PERMFLAG_LEVEL_ENTERED_HELM,             1,  GLOBALFLAG_CUTSCENE_ENTER_HIDEOUT },
    { PERMFLAG_PROGRESS_CROWN_DOOR_OPENED, PERMFLAG_PROGRESS_CROWN_DOOR_OPENED,     1,  GLOBALFLAG_CUTSCENE_PRESS_BUTTON },
    { PERMFLAG_PROGRESS_K_LUMSY_FREE,      PERMFLAG_PROGRESS_K_LUMSY_FREE,          1,  GLOBALFLAG_CUTSCENE_KROOL_TAKEOFF },
    { PERMFLAG_PROGRESS_HAS_QUIT_GAME,     PERMFLAG_PROGRESS_HAS_QUIT_GAME,         1,  GLOBALFLAG_CUTSCENE_GAME_OVER },
    { PERMFLAG_PROGRESS_K_ROOL_DEFEATED,   PERMFLAG_PROGRESS_K_ROOL_DEFEATED,       1,  GLOBALFLAG_CUTSCENE_END_SEQUENCE },
    { PERMFLAG_ITEM_NINTENDO_COIN,         PERMFLAG_ITEM_NINTENDO_COIN,             1,  GLOBALFLAG_MINIGAME_DK_ARCADE },
    { PERMFLAG_ITEM_RAREWARE_COIN,         PERMFLAG_ITEM_RAREWARE_COIN,             1,  GLOBALFLAG_MINIGAME_JETPAC },
    { PERMFLAG_ITEM_KEY_1,                 PERMFLAG_ITEM_KEY_1,                     1,  GLOBALFLAG_BOSSES_JAPES },
    { PERMFLAG_ITEM_KEY_2,                 PERMFLAG_ITEM_KEY_2,                     1,  GLOBALFLAG_BOSSES_AZTEC },
    { PERMFLAG_ITEM_KEY_3,                 PERMFLAG_ITEM_KEY_3,                     1,  GLOBALFLAG_BOSSES_FACTORY },
    { PERMFLAG_ITEM_KEY_4,                 PERMFLAG_ITEM_KEY_4,                     1,  GLOBALFLAG_BOSSES_GALLEON },
    { PERMFLAG_ITEM_KEY_5,                 PERMFLAG_ITEM_KEY_5,                     1,  GLOBALFLAG_BOSSES_FUNGI },
    { PERMFLAG_ITEM_KEY_6,                 PERMFLAG_ITEM_KEY_6,                     1,  GLOBALFLAG_BOSSES_CAVES },
    { PERMFLAG_ITEM_KEY_7,                 PERMFLAG_ITEM_KEY_7,                     1,  GLOBALFLAG_BOSSES_CASTLE },
    { PERMFLAG_PROGRESS_K_ROOL_DEFEATED,   PERMFLAG_PROGRESS_K_ROOL_DEFEATED,       1,  GLOBALFLAG_BOSSES_THE_MAIN_EVENT },
};

typedef struct {
    u8 unk0; // Used, likely map
    u8 unk1;
    s16 unk2; // Used
    u16 unk4; // Used
    u8 unk6; // Used
    u8 unk7; // Used
} Struct807FDCD0;

static Struct807FDCD0 D_global_asm_807FDCD0[0x18];

static u8 temporary_flag_block[0xE];

void func_global_asm_80731030(void) { // clearTemporaryFlags()
    s32 flagIndex;
    
    for (flagIndex = 0; flagIndex != 0xE; flagIndex++) {
        temporary_flag_block[flagIndex] = 0;
    }
}

void clearPermanentFlags(void) {
    s32 flagIndex;
    for (flagIndex = 0; flagIndex < 0x316; flagIndex++) {
        setFlag(flagIndex, FALSE, FLAG_TYPE_PERMANENT);
    }
}

void clearGlobalFlags(void) {
    s32 flagIndex;
    for (flagIndex = 0; flagIndex < 0x2C; flagIndex++) {
        setFlag(flagIndex, FALSE, FLAG_TYPE_GLOBAL);
    }
}

u8 isFlagSet(s16 flagIndex, u8 flagType) { // TODO: Can we use the FlagTypes enum? Needs to be a u8 to match
    u8 *flagBlock;
    s16 flagByte;

    if (flagIndex == -1) {
        return 0;
    }
    switch (flagType) {
        case FLAG_TYPE_PERMANENT:
        case FLAG_TYPE_GLOBAL:
            flagBlock = getFlagBlockAddress(flagType);
            break;
        case FLAG_TYPE_TEMPORARY:
            flagBlock = &temporary_flag_block;
    }
    flagByte = flagIndex >> 3;
    return flagBlock[flagByte] >> (s16)(flagIndex - flagByte * 8) & 1;
}

void func_global_asm_807311C4(s16 flagIndex) {
    s32 i;
    s32 chosenFlag;

    chosenFlag = -1;
    for (i = 0; i < 0x21U && chosenFlag == -1; i++) {
        if (flagIndex >= D_global_asm_80756024[i].startFlagIndex && D_global_asm_80756024[i].endFlagIndex >= flagIndex) {
            if (countSetFlags(D_global_asm_80756024[i].startFlagIndex, (D_global_asm_80756024[i].endFlagIndex - D_global_asm_80756024[i].startFlagIndex) + 1, FLAG_TYPE_PERMANENT) == D_global_asm_80756024[i].flagCountRequired) {
                chosenFlag = D_global_asm_80756024[i].globalFlagToSet;
            }
        }
    }

    if (chosenFlag >= 0) {
        setFlag(chosenFlag, TRUE, FLAG_TYPE_GLOBAL);
    }
}

void setFlag(s16 flagIndex, u8 newValue, u8 flagType) {
    u8 *flagBlock;
    s16 flagByte;
    s32 sp2C; // This is load bearing, cannot remove

    if (flagIndex != -1) {
        switch (flagType) {
            case FLAG_TYPE_PERMANENT:
            case FLAG_TYPE_GLOBAL:
                flagBlock = getFlagBlockAddress(flagType);
                break;
            case FLAG_TYPE_TEMPORARY:
                flagBlock = &temporary_flag_block;
                break;
        }
        flagByte = flagIndex >> 3;
        if (newValue) {
            flagBlock[flagByte] |= 1 << (s16)(flagIndex - (flagByte * 8));
        } else {
            flagBlock[flagByte] &= ~(1 << (s16)(flagIndex - (flagByte * 8)));
        }
        if (newValue && (flagType == FLAG_TYPE_PERMANENT)) {
            func_global_asm_807311C4(flagIndex);
        }
    }
}

void func_global_asm_807313BC(void) {
    s32 i;

    for (i = 0; i < 24; i++) {
        if (!func_global_asm_805FF938(D_global_asm_807FDCD0[i].unk0)) {
            D_global_asm_807FDCD0[i].unk7 = 0;
        }
    }
}

void func_global_asm_80731410(s16 arg0, s16 arg1, s16 arg2, u8 arg3) {
    s32 i;

    for (i = 0; i < 24; i++) {
        if (D_global_asm_807FDCD0[i].unk7 == 0) {
            D_global_asm_807FDCD0[i].unk0 = arg0;
            D_global_asm_807FDCD0[i].unk2 = arg1;
            D_global_asm_807FDCD0[i].unk4 = arg2;
            D_global_asm_807FDCD0[i].unk6 = arg3;
            D_global_asm_807FDCD0[i].unk7 = 1;
            return;
        }
    }
}

void func_global_asm_807314F4(s16 arg0, s16 arg1) {
    s32 max = 0x71;
    s32 i;

    for (i = 0; i < max; i++) {
        if ((arg0 == D_global_asm_80755A20[i].unk0) && (arg1 == D_global_asm_80755A20[i].unk2)) {
            setFlag(D_global_asm_80755A20[i].flagIndex, TRUE, FLAG_TYPE_PERMANENT);
            return;
        }
    }

    for (i = 0; i < 24; i++) {
        if (D_global_asm_807FDCD0[i].unk7 && arg0 == D_global_asm_807FDCD0[i].unk0 && arg1 == D_global_asm_807FDCD0[i].unk2) {
            setFlag(D_global_asm_807FDCD0[i].unk4, TRUE, FLAG_TYPE_PERMANENT);
            D_global_asm_807FDCD0[i].unk7 = 0;
            return;
        }
    }
}

u8 func_global_asm_807315D4(s16 arg0, s16 arg1) {
    s32 i;
    s32 max = 0x71;

    for (i = 0; i < max; i++) {
        if ((arg0 == D_global_asm_80755A20[i].unk0) && (arg1 == D_global_asm_80755A20[i].unk2)) {
            return isFlagSet(D_global_asm_80755A20[i].flagIndex, FLAG_TYPE_PERMANENT);
        }
    }
    return FALSE;
}

u8 func_global_asm_80731654(s16 arg0, s16 arg1) {
    s32 i;
    s32 max = 0x71;

    for (i = 0; i < max; i++) {
        if (arg0 == D_global_asm_80755A20[i].unk0) {
            if (arg1 == D_global_asm_80755A20[i].unk2) {
                return D_global_asm_80755A20[i].unk6;
            }
        }   
    }
    for (i = 0; i < 0x18; i++) {
        if (D_global_asm_807FDCD0[i].unk7 != 0) {
            if (arg0 == D_global_asm_807FDCD0[i].unk0) {
                if (arg1 == D_global_asm_807FDCD0[i].unk2) {
                    return D_global_asm_807FDCD0[i].unk6;
                }
            }
        }
    }
    return 0;
}

// close, doable, extra cast to s16 somewhere
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_135D30/func_global_asm_80731784.s")

/*
s16 func_global_asm_80731784(s16 map, s16 spawnerID, s32 *arg2) {
    s16 i;
    s32 max = 0x1F;

    for (i = 0, *arg2 = i; i < max; *arg2 = ++i) {
        if (map == D_global_asm_80755DA8[i].map) {
            if (spawnerID == D_global_asm_80755DA8[i].spawnerID) {
                return D_global_asm_80755DA8[i].flagIndex;
            }
        }
    }
    return -1;
}
*/

s32 func_global_asm_807317FC(s16 arg0, s16 arg1) {
    s32 flagIndex;
    s32 sp20;
    u8 flagIsSet;

    flagIndex = func_global_asm_80731784(arg0, arg1, &sp20);
    if ((flagIndex >= 0)) {
        flagIsSet = isFlagSet(flagIndex, FLAG_TYPE_PERMANENT);
        if (flagIsSet && D_global_asm_80755DA8[sp20].unk6) {
            return TRUE;
        }
        if (!(flagIsSet) && !D_global_asm_80755DA8[sp20].unk6) {
            return TRUE;
        }
        return FALSE;
    }
    return TRUE;
}

s32 func_global_asm_807318AC(s16 arg0, s16 arg1) {
    s32 i;
    s32 max = 0x16;
    s32 pad;

    for (i = 0; i < max; i++) {
        if (arg0 == D_global_asm_80755EA0[i].unk0 && arg1 == D_global_asm_80755EA0[i].unk2) {
            if (isFlagSet(D_global_asm_80755EA0[i].flagIndex, FLAG_TYPE_PERMANENT)) {
                return FALSE;
            }
            if (D_global_asm_80755EA0[i].unk6) {
                setFlag(D_global_asm_80755EA0[i].flagIndex, TRUE, FLAG_TYPE_PERMANENT);
            }
            return TRUE;
        }
    }
    return TRUE;
}

// TODO: Better way to match this?
typedef struct {
    s16 s1;
    s16 s2;
} Struct8073195C;

s16 func_global_asm_8073195C(s16 arg0) {
    if (arg0 == 0) {
        return -1;
    }
    return ((Struct8073195C*)(&D_global_asm_80755EA0[21].flagIndex))[arg0].s1;
}

u8 func_global_asm_8073198C(s16 arg0) {
    s32 i;
    s32 max = 0x35;

    for (i = 0; i < max; i++) {
        if (arg0 == D_global_asm_80755F50[i].unk0) {
            return D_global_asm_80755F50[i].unk2;
        }
    }
    return 0;
}

// Returns a permanent flag index
s32 func_global_asm_807319D8(s32 arg0, s32 arg1, s32 arg2) {
    s32 flagIndex = -1;
    if (arg1 < 8) {
        if (arg2 < 5) {
            flagIndex = (arg1 * 5) + arg0 + arg2;
        }
    }
    return flagIndex;
}

s32 func_global_asm_80731A04(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 flagIndex;
    s32 i;
    s32 count;

    count = 0;
    if (arg3 >= 5) {
        return 0;
    }
    
    for (i = arg1; i <= arg2; i++) {
        flagIndex = func_global_asm_807319D8(arg0, i, arg3);
        if (flagIndex >= 0) {
            count += isFlagSet(flagIndex, FLAG_TYPE_PERMANENT);
        }
    }
    return count;
}

s32 countSetFlags(s32 startIndex, s32 length, u8 flagType) {
    s32 flagIndex;
    s32 count = 0;
    for (flagIndex = startIndex; flagIndex < startIndex + length; flagIndex++) {
        count += isFlagSet(flagIndex, flagType);
    }
    return count;
}
