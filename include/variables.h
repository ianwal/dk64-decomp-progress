#define ARRAY_COUNT(arr) (sizeof(arr) / sizeof(arr[0]))
extern s8 story_skip;
extern s8 widescreen_enabled;
extern PlayerAdditionalActorData *extra_player_info_pointer;
extern Actor *current_actor_pointer;
extern Actor *D_807FBB44;
extern Actor *D_807FBB48;
extern GlobalASMStruct35 D_807FBB70;
extern Actor *D_807FBD6C;
extern Actor *D_807FDC94;
extern EnemyInfo *D_807FDC98;
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
extern Struct807FDC90 *D_807FDC90; // Array?
extern CharacterSpawner *D_807FDC9C; // Character spawner array
extern s32 object_timer;
extern u8 is_autowalking;
extern ActorSpawner *actor_spawner_pointer;
extern PlayerProgress D_807FC950[4];
extern u16 enemies_killed;
extern Chunk *chunk_array_pointer;
extern u8 current_file;

extern s32 D_807FBB64; // shadow_display_bitfield, shockwave_bitfield, long_distance_actor_spawn

extern u8 D_8076A0AB; // Map
extern s16 D_807F6240[];

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

extern Struct807552E4 D_807552E4;

typedef struct {
    u16 unk0;
    s8 unk2;
    s8 unk3;
} Struct807ECD58;

extern Struct807ECD58 D_807ECD58;

typedef struct Struct807FD610 {
    s32 unk0; // Timer that ticks up once per frame
    f32 unk4; // Probably float
    f32 unk8; // Probably float
    f32 unkC; // Probably float
    f32 unk10;
    f32 unk14;
    f32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28; // Used
    u16 unk2A; // Used, controller button bitfield
    u16 unk2C; // Used, controller button bitfield
    s8 unk2E; // Used
    s8 unk2F; // Used
    u8 unk30; // Used
    u8 unk31;
    s16 unk32;
} Struct807FD610;

extern Struct807FD610 D_807FD610[]; // Often indexed by cc_player_index
extern OSPfs D_807F02D0[];

extern ALSeqPlayer *D_8076BF20[];

typedef struct {
    s16 unk0; // X Position
    s16 unk2; // Y Position
    s16 unk4; // Z Position
    s16 unk6;
    s16 unk8;
} Struct807FDCA0_unk14;

// TODO: What is this datatype?
typedef struct Struct807FDCA0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    Struct807FDCA0_unk14 *unk14;
    s8 unk18;
    s8 unk19; // Used
    s16 unk1A;
    Actor *unk1C;
    u8 unk20; // Used
} Struct807FDCA0;
extern Struct807FDCA0 *D_807FDCA0; // TODO: What is this datatype?

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

extern Struct807F0470 D_807F0470[];

typedef struct {
    s32 unk0;
    u8 unk4[0x280 - 0x4];
    s32 unk280;
    s32 frame_count;
} Struct80767A40;

extern Struct80767A40 D_80767A40;

typedef struct {
    Actor* unk0;
    s32 unk4;
} GlobalASMStruct53;

extern GlobalASMStruct53 D_807FB930[];

typedef struct global_asm_struct_58 GlobalASMStruct58;

struct global_asm_struct_58 {
    void *unk0; // used, at least 0x65 big (func_80661264, func_8065F5F0), not sure what datatype though
    f32 unk4; // used
    f32 unk8; // used
    f32 unkC; // used
    f32 unk10; // used
    f32 unk14; // used
    f32 unk18; // used
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s16 unk48;
    s8 unk4A; // used
    s8 unk4B; // used
    s8 unk4C; // used
    s8 unk4D;
    s16 unk4E;
    GlobalASMStruct58 *next; // used
};

extern GlobalASMStruct58 *D_807F93C0;

// Array of structs 0x10 big
// TODO: What are these actually?
typedef struct Temp10Big {
    s32 unk0;
    s16 unk4;
    s8 unk6;
    s8 unk7;
    s32 unk8;
    s32 unkC;
} Temp10Big;
extern Temp10Big D_8075C410[];

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

extern DKTVExtraData D_807ECE20;

typedef struct model_2_model_50_b8 Model2Model50_B8;

struct model_2_model_50_b8 {
    s32 unk0[4];
    s32 unk10[4];
    s32 unk20[4];
    s32 unk30;
    s32 unk34;
    s16 unk38; // Used
    s16 unk3A; // Used
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    u8 unk48; // Used
    u8 unk49; // used
    u8 unk4A;
    u8 unk4B;
    s32 unk4C;
    s32 unk50; // Used
    s32 unk54; // Used
    s32 unk58;
    s32 unk5C;
    s32 unk60[4];
    s32 unk70[4];
    s32 unk80[4];
    s32 unk90[4];
    s32 unkA0[4];
    s32 unkB0[4];
    s32 unkC0[4];
    s32 unkD0;
    Model2Model50_B8 *next; // unkD4
};

typedef struct {
    s32 unk0;
    f32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
} Model2Model54_BC;

typedef struct {
    s32 unk0[4];
    s32 unk10[4];
    s32 unk20[4];
    s32 unk30[4];
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s16 unk4C;
    u8 unk4E; // Used
    u8 unk4F; // Used
    Model2Model50_B8 *unk50; // Used, pointer
    Model2Model54_BC *unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60[4];
    s32 unk70[4];
    s32 unk80[4];
    s32 unk90[4];
    s32 unkA0[4];
    s32 unkB0;
    s32 unkB4;
    Model2Model50_B8 *unkB8; // Used, pointer
    Model2Model54_BC *unkBC; // Used
} Model2Model;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s8 unk48[1]; // TODO: How many elements?
    s8 unk49;
    s8 unk4A;
    s8 unk4B;
    s32 unk4C;
    s32 unk50;
    s8 unk54;
    s8 unk55;
    s8 unk56;
    s8 unk57;
    s32 unk58;
    s32 unk5C;
    u8 unk60;
    u8 unk61;
    u8 unk62;
    u8 unk63;
    s16 unk64;
    s16 unk66;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
} OM2_unk7C;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s16 unk3C;
    s16 unk3E;
} OM2_unk24;

typedef struct OM2_unk74 OM2_unk74;

struct OM2_unk74 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 next;
};

typedef struct {
    s16 unk0;
    s8 unk2;
    s8 unk3;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} OM2_unk78;

typedef struct object_model2 {
    f32 x_position; // at 0x00
    f32 y_position; // at 0x04
    f32 z_position; // at 0x08
    f32 hitbox_scale; // at 0x0C
    f32 x_rotation; // at 0x10
    f32 y_rotation; // at 0x14
    f32 z_rotation; // at 0x18
    s32 unk1C;
    Model2Model *model_pointer; // at 0x20
    OM2_unk24 *unk24; // labelled behavior_type_pointer in ScriptHawk
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    OM2_unk74 *unk74;
    OM2_unk78 *unk78; // used in func_80650AD8, weird format
    OM2_unk7C *unk7C; // labelled behavior_pointer in ScriptHawk
    s32 unk80;
    s16 object_type; // at 0x84
    s16 unk86;
    s16 unk88;
    s16 unk8A;
    u8 unk8C; // bitfield, collectable state (u8)
    u8 unk8D;
    u8 unk8E;
    u8 unk8F;
} ObjectModel2;

extern ObjectModel2 *D_807F6000;

extern u16 D_80744710[]; // = { // Permanent flag index lookup array
//     26, // Key 1 Collected
//     74, // key 2 Collected
//     138, // Key 3 Collected
//     168, // Key 4 Collected
//     236, // Key 5 Collected
//     292, // Key 6 Collected
//     317, // Key 7 Collected
//     380, // Key 8 Collected
// }; // Permanent flag index lookup array

extern s32 D_80741F40;
extern s32 D_807432D0;
extern s32 D_80760840;
extern s32 D_80760C60;
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
extern gASMStruct1 D_807F0570;
extern gASMStruct2 D_807F0588;
