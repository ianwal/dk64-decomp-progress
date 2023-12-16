#define ARRAY_COUNT(arr) (sizeof(arr) / sizeof(arr[0]))
extern s8 story_skip;
extern s8 widescreen_enabled;
extern PlayerAdditionalActorData *extra_player_info_pointer;
extern Actor *current_actor_pointer;
extern Actor *D_global_asm_807FBB44;
extern Actor *D_global_asm_807FBB48;
extern GlobalASMStruct35 D_global_asm_807FBB70;
extern Actor *D_global_asm_807FBD6C;
extern Actor *D_global_asm_807FDC94;
extern EnemyInfo *D_global_asm_807FDC98;
extern u8 current_character_index[];
extern CharacterChange *character_change_array;
extern Actor *player_pointer;
extern u8 cc_player_index; // index into character_change_array, current_character_index[]
extern u8 cc_number_of_players;
extern s32 global_properties_bitfield;
extern Maps current_map;
extern s32 current_exit;
extern Maps next_map;
extern s32 next_exit;
extern u8 is_cutscene_active;
extern u8 game_mode;
extern u8 game_mode_copy;
extern u16 newly_pressed_input;
extern u16 newly_pressed_input_copy;
extern Struct807FDC90 *D_global_asm_807FDC90; // Array?
extern CharacterSpawner *D_global_asm_807FDC9C; // Character spawner array
extern s32 object_timer;
extern u8 is_autowalking;
extern ActorSpawner *actor_spawner_pointer;
extern PlayerProgress D_global_asm_807FC950[4];
extern u16 enemies_killed;
extern Chunk *chunk_array_pointer;
extern u8 current_file;

extern u16 D_global_asm_807446C0[];

extern u8 D_global_asm_807445E0[]; // level_index_mapping
extern s32 D_global_asm_80744720[] ;/*= {
    0x181, // Kong Unlocked: DK
    0x6, // Kong Unlocked: Diddy
    0x46, // Kong Unlocked: Lanky
    0x42, // Kong Unlocked: Tiny
    0x75, // Kong Unlocked: Chunky
}; // kong_unlocked_flag_mapping*/

extern u16 D_global_asm_80744734[] ;/*= { // lobby_array
   MAP_JAPES_LOBBY,
   MAP_AZTEC_LOBBY,
   MAP_FACTORY_LOBBY,
   MAP_GALLEON_LOBBY,
   MAP_FUNGI_LOBBY,
   MAP_CAVES_LOBBY,
   MAP_CASTLE_LOBBY,
   MAP_HELM_LOBBY,
   MAP_HELM_LOBBY, // TODO: Why is this here twice?
}; // lobby_array*/

extern Gfx **D_1000020;
extern Gfx **D_1000030;
extern Gfx **D_1000068;
extern Gfx **D_1000040;
extern Gfx **D_1000090;
extern Gfx **D_1000118;
extern Mtx D_2000080;
extern Mtx D_20000C0;
extern Mtx D_2000180;
extern Mtx D_2000200;

extern u8 D_global_asm_807444FC;

extern u16 D_global_asm_807FBB34;
extern s32 D_global_asm_807FBB64; // shadow_display_bitfield, shockwave_bitfield, long_distance_actor_spawn

extern Actor *D_global_asm_807F5D10;

extern u8 D_global_asm_8076A0AB; // Map
extern s16 D_global_asm_807F6240[];

typedef struct {
    s32 unk0; // Used
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20; // Used
} Struct807552E4;

extern Struct807552E4 D_global_asm_807552E4;

typedef struct {
    u16 unk0;
    s8 unk2;
    s8 unk3;
} Struct807ECD58;

extern Struct807ECD58 D_global_asm_807ECD58;

typedef struct Struct807FD610 {
    s32 unk0; // Timer that ticks up once per frame
    f32 unk4; // Probably float
    f32 unk8; // Probably float
    f32 unkC; // Probably float
    f32 unk10[4];
    s16 unk20[4];
    s16 unk28; // Used
    u16 unk2A; // Used, controller button bitfield
    u16 unk2C; // Used, controller button bitfield
    s8 unk2E; // Used
    s8 unk2F; // Used
    u8 unk30; // Used
    u8 unk31;
    s16 unk32;
} Struct807FD610;

extern Struct807FD610 D_global_asm_807FD610[]; // Often indexed by cc_player_index
extern OSPfs D_global_asm_807F02D0[];

extern ALSeqPlayer *D_global_asm_8076BF20[];

typedef struct {
    s16 unk0; // X Position
    s16 unk2; // Y Position
    s16 unk4; // Z Position
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
} Struct807FDCA0_unk14;

// TODO: What is this datatype?
typedef struct Struct807FDCA0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    Struct807FDCA0_unk14 *unk14;
    s8 unk18;
    u8 unk19; // Used
    s16 unk1A;
    Actor *unk1C;
    u8 unk20; // Used
} Struct807FDCA0;
extern Struct807FDCA0 *D_global_asm_807FDCA0; // TODO: What is this datatype?

typedef struct Struct807F0470 {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    u16 unk10;
    u8 unk12;
    u8 unk13;
} Struct807F0470;

extern Struct807F0470 D_global_asm_807F0470[];

typedef struct {
    s32 unk0;
    u8 unk4[0x260 - 0x4];
    s32 unk260;
    u8 unk264[0x280 - 0x264];
    s32 unk280;
    s32 frame_count;
} Struct80767A40;

extern Struct80767A40 D_global_asm_80767A40; // TODO: Might be an array, see func_global_asm_805FBC5C

typedef struct {
    Actor* unk0;
    s32 unk4;
} GlobalASMStruct53;

extern GlobalASMStruct53 D_global_asm_807FB930[];

typedef struct global_asm_struct_58 GlobalASMStruct58;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u8 unk14[0x46 - 0x14];
    s16 unk46; // Used
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    s16 unk4E; // Used
    s16 unk50[2]; // TODO: How many?
    u8 unk54[0x60 - 0x54];
    u8 unk60;
    u8 unk61; // Used
    u8 unk62; // Used
    u8 unk63; // Used
    u8 unk64;
    u8 unk65;
    u8 unk66;
    u8 unk67;
    u8 unk68;
} GlobalASMStruct58_unk0;

struct global_asm_struct_58 {
    GlobalASMStruct58_unk0 *unk0; // used, at least 0x65 big (func_global_asm_80661264, func_global_asm_8065F5F0), not sure what datatype though
    f32 unk4; // used
    f32 unk8; // used
    f32 unkC; // used
    f32 unk10; // used
    f32 unk14; // used
    f32 unk18; // used
    s32 unk1C[1]; // TODO: How many?
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
    s16 unk48;
    s8 unk4A; // used
    s8 unk4B; // used
    u8 unk4C; // used
    s8 unk4D;
    s16 unk4E;
    GlobalASMStruct58 *next; // used
};

extern GlobalASMStruct58 *D_global_asm_807F93C0;

// Array of structs 0x10 big
// TODO: What are these actually?
// typedef struct Temp10Big {
//     s32 unk0;
//     s32 unk4;
//     s32 unk8;
//     s32 unkC;
// } Temp10Big;
// extern Temp10Big D_global_asm_8075C410[];

typedef struct DKTVExtraData {
    f32 startingXPosition; // 0x00
    f32 startingYPosition; // 0x04
    f32 startingZPosition; // 0x08
    s16 startingYRotation; // 0x0C
    u8 map; // 0x0E
    u8 exit; // 0x0F
    u8 characterIndex; // 0x10
    u8 unk11; // 0x11
    CharacterProgress characterProgress; // 0x12
} DKTVExtraData;

extern DKTVExtraData D_global_asm_807ECE20;

extern ObjectModel2 *D_global_asm_807F6000;

extern u16 D_global_asm_80744710[]; // = { // Permanent flag index lookup array
//     26, // Key 1 Collected
//     74, // Key 2 Collected
//     138, // Key 3 Collected
//     168, // Key 4 Collected
//     236, // Key 5 Collected
//     292, // Key 6 Collected
//     317, // Key 7 Collected
//     380, // Key 8 Collected
// }; // Permanent flag index lookup array

extern s32 D_global_asm_80741F40;
extern s32 D_global_asm_807432D0;
extern s32 D_global_asm_80760840;
extern s32 D_global_asm_80760C60;
typedef struct gASMStruct1 {
    s32 *unk0;
    s32 *unk4;
    s32 *unk8;
    s32 *unkC;
}gASMStruct1;
typedef struct gASMStruct2 {
    s32 *unk0;
    s32 *unk4;
    s32 *unk8;
    s32 *unkC;
}gASMStruct2;
typedef struct gASMStruct3 {
    u8 unk0[0x44];
    s16 unk44;
}gASMStruct3;
extern gASMStruct1 D_global_asm_807F0570;
extern gASMStruct2 D_global_asm_807F0588;
