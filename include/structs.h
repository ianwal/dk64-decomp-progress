#ifndef __STRUCTS_H__
#define __STRUCTS_H__

/* your struct definitions go here */

typedef struct HeapHeader HeapHeader;

struct HeapHeader {
    HeapHeader *prev;
    s32 size; // Used
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB; // Used
    s32 unkC;
};

typedef struct character_progress {
    u8 moves; // at 0x00
    u8 simian_slam; // at 0x01
    u8 weapon; // at 0x02, bitfield, xxxxxshw
    u8 ammo_belt; // at 0x03, see ScriptHawk's Game.getMaxStandardAmmo() for formula
    u8 instrument; // at 0x04, bitfield, xxxx321i
    u8 unk5;
    u16 coins; // at 0x06
    u16 instrument_ammo; // at 0x08, also used as lives in multiplayer
    u16 coloured_bananas[14]; // TODO: Better datatype?
    u16 coloured_bananas_fed_to_tns[14]; // TODO: Better datatype?
    u16 golden_bananas[14]; // TODO: Better datatype?
} CharacterProgress;

typedef struct PlayerProgress {
    union {
        CharacterProgress character_progress[6]; // 0x5E * 6 (5 Kongs + Krusha)
        u8 character_progress_as_bytes[6][0x5E]; // Note: Can't use sizeof(CharacterProgress) because mips_to_c can't do struct maths yet
        u16 character_progress_as_shorts[6][0x2F]; // Note: Can't use sizeof(CharacterProgress) because mips_to_c can't do struct maths yet
    };
    u8 unk234[0x2F0 - 0x234];
    u16 standardAmmo; // 0x2F0
    u16 homingAmmo; // 0x2F2
    u16 oranges; // 0x2F4
    u16 crystals; // 0x2F6 // Note: Multiplied by 150 compared to on screen counter
    u16 film; // 0x2F8
    u8 unk2FA;
    s8 health; // 0x2FB
    u8 melons; // 0x2FC
    s8 unk2FD; // Something to do with health... hmm
    u16 unk2FE[(0x306 - 0x2FE) / 2];
} PlayerProgress;

typedef struct {
    u8 unk0;
    u8 unk1;
} Struct80027840;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Struct80676CB0_unk10;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    Struct80676CB0_unk10 *unk10;
    s32 unk14;
    s32 unk18;
} Struct80676CB0;

typedef struct ledge_info_8c LedgeInfo8C;

struct ledge_info_8c {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC; // Used
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s16 unk24;
    u8 unk26; // Used
    u8 unk27; // Used
    LedgeInfo8C *next;
};

typedef struct ledge_info_90 LedgeInfo90;

struct ledge_info_90 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    LedgeInfo90 *next;
};

typedef struct {
    f32 unk0; // Used
    s32 unk4;
    s32 unk8;
    f32 unkC; // Used
    s32 unk10;
    s32 unk14;
    f32 unk18; // Used
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
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s16 unk54;
    s8 unk56;
    s8 unk57;
} LedgeInfo98;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s16 unk28;
    s8 unk2A; // Used
    s8 unk2B;
} LedgeInfoA0;

typedef struct {
    f32 unk0[1][4][4]; // TODO: How many? At least 2
} LedgeInfo74;

typedef struct ledge_info {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
    u16 unk48;
    u16 unk4A;
    u32 unk4C;
    u32 unk50;
    u32 unk54;
    u32 unk58;
    u32 unk5C;
    u32 unk60;
    u16 unk64;
    u16 unk66; // Used
    u32 unk68;
    u8 unk6C;
    u8 unk6D;
    u8 unk6E;
    u8 unk6F;
    u32 unk70;
    LedgeInfo74 (*unk74)[]; // TODO: How many?
    u32 unk78;
    s32 unk7C;
    s32 unk80; // object_timer gets written here
    s32 unk84;
    s32 unk88; // object_timer gets written here
    LedgeInfo8C *unk8C; // Linked List
    LedgeInfo90 *unk90;
    s32 unk94;
    LedgeInfo98 *unk98; // Array
    s32 unk9C;
    LedgeInfoA0 *unkA0; // Array
    s32 unkA4;
    s32 unkA8;
    u8 unkAC;
} LedgeInfo;

// TODO: What is this actually?
typedef struct animation_state_unk0 {
    s32 unk0;
    f32 unk4; // Used
    s32 unk8;
    s32 unkC;
    s16 unk10; // Used
    s16 unk12;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    f32 unk24; // Used
} AnimationStateUnk0;

typedef struct animation_state_unk8 {
    s32 unk0;
} AnimationStateUnk8;

typedef struct {
    s8 unk0;
    s8 unk1;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} AnimationStateUnk1C;

// TODO: Fill this in properly
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} AnimationStateUnk24;

// See boss func_8002FB7C
typedef struct animation_state_unk20 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} AnimationStateUnk20;

typedef struct actor_animation_state {
    AnimationStateUnk0 *unk0;
    s32 unk4;
    AnimationStateUnk8 *unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    void *bone_array_1; // at 0x14, camera, update bone positions // TODO: Proper type
    void *bone_array_2; // at 0x18, camera, update bone positions // TODO: Proper type
    AnimationStateUnk1C *unk1C; // TODO: Used in func_80724CA4 and func_8068FF40, pretty easy match, array of 0x8 structs? // malloc(0x100) in func_80683158
    AnimationStateUnk20 *unk20; // See boss func_8002FB7C
    AnimationStateUnk24 *unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    union {
        struct {
            f32 scale_x; // at 0x34
            f32 scale_y; // at 0x38
            f32 scale_z; // at 0x3C
        };
        f32 scale[3];
    };
    s32 unk40;
    s32 unk44;
    f32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    u16 unk64; // Used
    u16 unk66;
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
    f32 animation_timer_1; // at 0x94
    f32 animation_timer_2; // at 0x98
    s32 unk9C;
    s32 unk100;
    f32 animation_timer_3; // at 0x104
    f32 animation_timer_4; // at 0x108
} ActorAnimationState;

typedef struct {
    union {
        f32 unk0; // Used
        s32 unk0_s32; // Used // TODO: We might have another aaD situation here...
    };
    union {
        f32 unk4; // Used
        s32 unk4_s32; // Used // TODO: We might have another aaD situation here...
    };
    union {
        f32 unk8; // Used
        s32 unk8_s32; // Used // TODO: We might have another aaD situation here...
    };
    f32 unkC; // Used
    f32 unk10; // Used
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
} Actor124;

typedef struct actor_178 {
    s16 unk0; // Used
    s16 unk2;
    u8 unk4;
    u8 unk5;
    s16 unk6;
    s16 unk8;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u16 unk10; // Used
    u16 unk12; // Used
    u8 unk14;
} Actor178;

typedef struct boss_actor_178 {
    s32 unk0; // Used
} BossActor178;

typedef struct race_actor_178 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    f32 unk14;
} RaceActor178;

typedef struct {
    u8 unk0;
    u8 unk1; // Used
} A178_806A18A8;

typedef struct actor_17C {
    union {
        s32 unk0; // TODO: Actor*? Boss overlay Might require a union?
        s16 unk0_s16[2]; // TODO: Actor*? Boss overlay Might require a union?
        u16 unk0_u16[2]; // TODO: Actor*? Boss overlay Might require a union?
    };
    u8 unk4;
    u8 unk5;
    s16 unk6;
    s16 unk8;
} Actor17C;

typedef struct actor_collision ActorCollision;
typedef struct actor Actor;

typedef struct {
    Actor *unk0[4]; // Used
    u8 unk10; // Used, index into unk0
    s8 unk11;
    s8 unk12;
    s8 unk13;
} Actor114;

typedef struct {
    s32 unk0; // TODO: Proper members
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
} Actor118;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct807FBB70_unk278;

// TODO: What type is this actually?
// D_807FBB70
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4; // X Position (updated when touching warp pad)
    f32 unk8; // Y Position (updated when touching warp pad)
    f32 unkC; // Z Position (updated when touching warp pad)
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 pad1D[0x24 - 0x1D];
    u8 unk24;
    u8 unk25;
    u8 pad26[0x2C - 0x26];
    u8 unk2C;
    u8 pad2D[0x38 - 0x2D];
    u8 unk38;
    u8 unk39;
    u16 unk3A;
    f32 unk3C; // X Position?
    f32 unk40; // Y Position?
    f32 unk44; // Z Position?
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
    s32 unk74;
    s32 unk78;
    void *unk7C; // TODO: Actor*?
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    u8 unk90;
    u8 unk91;
    s16 unk92;
    s16 unk94;
    u8 unk96;
    u8 unk97;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    s32 unkCC;
    s32 unkD0;
    s32 unkD4;
    f32 unkD8;
    f32 unkDC; // TODO: Confirm datatype
    f32 unkE0;
    u8 unkE4;
    u8 unkE5;
    u8 unkE6;
    u8 unkE7;
    f32 unkE8;
    s32 unkEC;
    f32 unkF0;
    f32 unkF4;
    u8 padF8[0x1F8 - 0xF8];
    s32 unk1F8;
    Actor *unk1FC;
    u8 unk200;
    u8 unk201;
    s16 unk202;
    Actor *unk204[1]; // TODO: How many elements?
    u8 pad208[0x243 - 0x208];
    u8 unk243[1]; // TODO: How many elements?
    u8 unk244[1]; // TODO: How many elements?
    s8 unk245;
    s8 unk246;
    s8 unk247;
    u8 pad248[0x254 - 0x248];
    u8 unk254; // Used
    u8 unk255;
    u8 unk256;
    u8 unk257;
    s32 unk258[1]; // Used // TODO: How many elements?
    s32 unk25C;
    s32 unk260;
    s32 unk264;
    s32 unk268;
    s32 unk26C;
    s32 unk270;
    s32 unk274;
    Struct807FBB70_unk278 *unk278[1]; // Used // TODO: How many elements?
} GlobalASMStruct35;

struct actor_collision {
    u32 unk0; // Collision type?
    u8 unk4;
    u8 unk5;
    u16 unk6;
    Actor *collisionSource;
    u32 unkC;
    void *unk10; // Can be many different types
    ActorCollision* next;
    ActorCollision* prev;
};

typedef struct other_additional_actor_data {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
} OtherAdditionalActorData;

typedef struct another_additional_actor_data {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    u8 unk12;
    u8 unk13; // Used in func_806925AC
} AnotherAdditionalActorData;

typedef struct {
    u8 unk0[0x27 - 0x0];
    u8 unk27;
    u8 unk28[0x36 - 0x28];
    u8 unk36;
} RaaD_unk20_unk4;

typedef struct {
    Actor *unk0;
    RaaD_unk20_unk4 *unk4;
} RaaD_unk20;

typedef struct race_additional_actor_data {
    s16 unk0;
    s16 unk2; // used
    f32 unk4;
    s16 unk8;
    s16 unkA;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s16 unk18;
    s16 unk1A;
    u16 unk1C;
    u8 unk1E;
    s8 unk1F;
    RaaD_unk20 *unk20; // Array
    u8  unk24;
    u8  unk25;
    s8  unk26;
    s8  unk27;
    u8 unk28; // Used
    s8 unk29; // Used
    s16 unk2A;
    s32 unk2C;
    Actor *unk30;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    s32 unk38;
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 unk3F;
    s16 unk40;
    u8 unk42; // Used
    u8 unk43;
    u8 unk44;
    u8 unk45; // Used
} RaceAdditionalActorData;

typedef struct race_additional_actor_data2 {
    u8  unk0; // Used
    u8  unk1;
    u8  unk2;
    u8  unk3;
    u8 pad2[0x24 - 0x4];
    u8 unk24;
    u8 pad25[0x36 - 0x25];
    u8 unk36; // Used
} RaceAdditionalActorData2;

typedef struct yaad5 {
    f32 unk0; // Used
    f32 unk4; // Used
    f32 unk8; // Used
    u32 unkC;
    Actor* unk10; // Used
    s16 unk14; // Used
    s16 unk16; // Used
    u16 unk18;
    s16 unk1A; // Used
    s16 unk1C; // Used
    s8 unk1E; // Used
} YetAnotherAdditionalActorData5;

typedef struct yet_another_additional_actor_data {
    Actor *unk0;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    f32 unk24;
    s16 unk28;
    s16 unk2A;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s16 unk38;
    s16 unk3A;
    s32 unk3C;
} YetAnotherAdditionalActorData;

typedef struct yaad4 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10; // Used
    s16 unk12; // Used
    s16 unk14; // Used
} YetAnotherAdditionalActorData4;

typedef struct menu_additional_actor_data {
    //u8 pad0[0x17];
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s16 unk10;
    s8  unk12;
    s8  unk13;
    s16 unk14;
    s8  unk16;
    s8 unk17;
} MenuAdditionalActorData;

typedef struct player_additional_actor_data {
    union {
        s32 unk0; // TODO: May be s16 (see func_806CF580), but changing that causes some matching functions to break
        s16 unk0_s16[2];
    };
    f32 unk4;
    s16 unk8; // Used
    s16 unkA; // Used, Actor->y_rotation copied here
    s16 unkC; // Used
    s16 unkE; // Used
    s16 unk10; // Used
    s16 unk12; // Used
    s16 unk14; // Used
    union {
        struct {
            s8  unk16_s8;
            s8  unk17; // Used, set to current file selection?
        };
        s16 unk16;
    };
    s16 unk18; // Used
    u16 unk1A;
    f32 unk1C; // Used
    f32 unk20; // Used
    s16 unk24; // Used
    s16 unk26;
    s16 unk28; // Used
    s16 unk2A;
    f32 unk2C; // Used
    f32 unk30; // Used
    f32 unk34; // Used
    f32 unk38; // Used
    s16 unk3C;
    s16 unk3E; // Used
    s16 unk40;
    u8 unk42; // Used, related to distance from floor
    u8 unk43;
    u8 unk44;
    u8 unk45; // Used, VehicleAdditionalActorData
    u8 unk46;
    u8 unk47;
    s16 unk48; // Used
    s16 unk4A;
    s16 unk4C; // Used
    s16 unk4E;
    s16 unk50; // Used
    s16 unk52;
    f32 unk54;
    s32 unk58; // Used, related to D_80767CC0
    s32 unk5C;
    s32 unk60;
    s16 unk64; // Used
    s16 unk66;
    f32 unk68;
    f32 unk6C; // Used
    s16 unk70; // Used, y rotation?
    s16 unk72;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    Actor* vehicle_actor_pointer; // Used
    u8  unk8C; // Used
    u8  unk8D; // Used
    u8 unk8E; // Used
    u8 unk8F;
    u8 unk90;
    u8 unk91; // Used
    u8 unk92;
    u8 unk93;
    f32 unk94; // Used
    f32 unk98;
    f32 unk9C; // Used
    f32 unkA0; // Used
    f32 unkA4; // Used
    f32 unkA8; // Used
    union {
        s32 unkAC; // Used
        f32 unkAC_f32; // Used
    }; // TODO: Deconflict
    s16 unkB0;
    s16 unkB2; // Used
    s32 unkB4;
    f32 unkB8; // Used
    s16 unkBC; // Used
    s16 unkBE;
    s16 unkC0;
    s16 unkC2; // Used
    s32 unkC4;
    s16 unkC8;
    u8  unkCA; // Used
    s8  unkCB;
    s32 unkCC;
    s32 unkD0;
    s16 unkD4; // Used
    s16 unkD6;
    u8 unkD8; // Used
    u8 unkD9;
    u8 unkDA;
    u8 unkDB;
    Actor *unkDC; // Used
    f32 unkE0; // Used
    f32 unkE4; // Used
    u8 unkE8; // Used
    u8 unkE9;
    s16 unkEA; // Used
    s16 unkEC;
    u8 unkEE;
    u8 unkEF; // Used
    union { // TODO: No idea what's going on here, both are used
        float unkF0_f32;
        u8 unkF0;
        u8 unkF0_u8[4];
    };
    union { // TODO: No idea what's going on here, both are used
        float unkF4_f32;
        u8 unkF4;
        u8 unkF4_u8[4];
    };
    u8 unkF8; // Used
    u8 unkF9;
    u8 unkFA;
    u8 unkFB;
    union { // TODO: Deconflict
        u8 unkFC; // Used
        s32 unkFC_s32; // Used
    };
    s32 unk100;
    Actor *unk104; // Used, Actor*?
    f32 unk108; // Used
    s8 unk10C; // Used
    u8 unk10D;
    u8 unk10E;
    u8 unk10F;
    s32 unk110;
    s32 unk114;
    s32 unk118;
    u8 unk11C; // Used, VehicleAdditionalActorData?
    u8 unk11D;
    s16 unk11E; // Used
    s32 unk120;
    f32 unk124; // Used
    s32 unk128;
    s32 unk12C;
    Actor *unk130;
    s8 unk134;
    s8 unk135;
    s8 unk136;
    s8 unk137;
    f32 unk138;
    f32 unk13C;
    f32 unk140;
    f32 unk144;
    f32 unk148;
    f32 unk14C; // Used
    f32 unk150; // Used
    s16 unk154; // Used
    s16 unk156;
    Actor *unk158;
    s32 unk15C;
    s32 unk160;
    s32 unk164;
    s32 unk168;
    s32 unk16C;
    s32 unk170;
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    s32 unk188;
    s32 unk18C;
    s32 unk190;
    s32 unk194;
    s32 unk198;
    s16 unk19C; // Used
    s16 unk19E; // Used
    u16 unk1A0; // Used
    u8  unk1A2;
    u8  unk1A3; // Used
    u8  unk1A4; // Used, playerIndex?
    u8  unk1A5;
    u8  unk1A6;
    u8  unk1A7;
    Actor *unk1A8;
    Actor *unk1AC; // TODO: Is this correct?
    Actor *unk1B0; // Used
    s32 unk1B4;
    s32 unk1B8;
    f32 unk1BC; // Used
    f32 unk1C0; // Used
    f32 unk1C4; // Used
    f32 unk1C8; // Used
    f32 unk1CC; // Used
    f32 unk1D0; // Used, y scale
    f32 unk1D4; // Used, z scale
    f32 unk1D8; // Used
    f32 unk1DC; // Used
    f32 unk1E0; // Used
    s32 unk1E4;
    s32 unk1E8;
    s16 unk1EC;
    s16 unk1EE; // Used
    s32 unk1F0; // Used, bitfield // TODO: Proper bitfield syntax
    s32 unk1F4;
    s32 unk1F8;
    u8 unk1FC; // Used
    u8 unk1FD;
    u16 unk1FE; // Used
    s16 unk200; // Used
    s16 unk202;
    s32 unk204;
    s32 unk208;
    s32 unk20C;
    s32 unk210;
    s32 unk214;
    s32 unk218;
    s16 unk21C;
    u16 unk21E; // Used
    f32 unk220; // Used, x
    f32 unk224; // Used, y
    f32 unk228; // Used, z
    f32 unk22C; // Used, x
    f32 unk230; // Used, y
    f32 unk234; // Used, z
    f32 unk238; // Used
    u16 unk23C; // Used
    u8 unk23E;
    u8 unk23F; // Used
    u8 unk240; // Used
    u8 unk241;
    u16 unk242; // Used
    s8 unk244;
    u8 unk245; // Used
    s8 unk246; // Used func_806CA26C
    s8 unk247; // Used func_806CA26C
    s8 unk248;
    s8 unk249;
    s8 unk24A;
    s8 unk24B; // Used
    u16 unk24C; // Used // TODO: s16? func_806CA1B4 uses this as u16
    u16 unk24E; // Used // TODO: s16? func_806CA1B4 uses this as u16
    s32 unk250;
    s32 unk254;
    f32 unk258; // Used
    f32 unk25C; // Used
    s32 unk260;
    s32 unk264; // Used
} PlayerAdditionalActorData;

//f32 at unk8 doesn't match with what's in structs.h (s16) 
//for PlayerAdditionalActorData so making this struct
typedef struct {
    u8 pad0[0x8];
    f32 unk8;
} PaaD0;

// Bonus func_800253E4
typedef struct {
    Actor* unk0;
} BaaD2;

typedef struct TempAAD {
    s8 unk0;
    u8 pad0[0x14 - 0x1];
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    u8 pad1[0x24 - 0x1C];
    s8 unk24;
} TempAAD;

typedef struct struct806A57C0_2 Struct806A57C0_2;
typedef struct struct806A57C0_3 Struct806A57C0_3;

struct struct806A57C0_3 {
    s16 unk0;
    u8 unk2; // Used
    u8 unk3;
    f32 unk4; // Used
    f32 unk8; // Used
    s32 unkC;
    s32 unk10;
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
    Struct806A57C0_3 *unkA0; // Used
};

struct struct806A57C0_2 {
    u8 unk0; // Used
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
    Struct806A57C0_3 *unkC;
    u16 unk10; // Used
    u16 unk12;
    s32 unk14;
    f32 unk18;
    Struct806A57C0_2 *next; // 0x1C
};

typedef struct {
    u16 unk0; // Used
    s16 unk2;
    s32 unk4;
    s32 unk8;
    Struct806A57C0_2 *unkC; // Used
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14; // Used
    f32 unk18; // Used
    u8 unk1C;
    u8 unk1D; // Used
    u8 unk1E;
    u8 unk1F;
    f32 unk20; // Used
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s16 unk38;
    s16 unk3A;
    s32 unk3C;
    f32 unk40; // Used
    f32 unk44; // Used
    f32 unk48; // Used
    f32 unk4C; // Used
    f32 unk50;
    u8 unk54;
    u8 unk55; // Used
} AAD_806A4DDC;

// TODO: This appears to be a "texture renderer" according to ScriptHawk, needs a better name though. Linked list at Actor->unk158
typedef struct global_asm_struct_60 GlobalASMStruct60;

struct global_asm_struct_60 {
    s32 *unk0; // Used
    GlobalASMStruct60 *unk4; // Used? Might be wrong datatype, see func_80688638
    s16 unk8;
    s16 unkA; // Used
    s16 unkC; // Used - Texture index?
    s16 unkE;
    f32 unk10; // Used
    f32 unk14; // Used
    s16 unk18; // Used
    s16 unk1A; // Used
    s16 unk1C; // Used
    s16 unk1E; // Used
    s8 unk20; // Used
    s8 unk21; // Used
    u8 unk22; // Used
    u8 unk23;
    GlobalASMStruct60 *next; // at 0x24
};

typedef struct {
    s32 unk0; // TODO: Proper members
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} FloorTriangle;

struct actor {
    u32 *unk0; // Small header on top of DisplayList Pointer // TODO: Proper type
    ActorAnimationState *animation_state;
    u32 *unk8; // Current bone array Pointer // TODO: Proper type
    s16 unkC;
    s16 unkE;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    f32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4C;
    u32 unk50;
    u32 unk54;
    Actors unk58;
    u16 interactable; // Bitfield at 0x5C
    u16 unk5E;
    union {
        struct {
            u32 OPBBit0 : 1;
            u32 OPBBit1 : 1;
            u32 OPBBit2 : 1;
            u32 OPBBit3 : 1;
            u32 OPBBit4 : 1;
            u32 OPBBit5 : 1;
            u32 OPBBit6 : 1;
            u32 OPBBit7 : 1;
            u32 OPBBit8 : 1;
            u32 OPBBit9 : 1;
            u32 OPBBit10 : 1;
            u32 OPBBit11 : 1;
            u32 OPBBit12 : 1;
            u32 OPBBit13 : 1;
            u32 OPBBit14 : 1;
            u32 OPBBit15 : 1;
            u32 OPBBit16 : 1;
            u32 OPBBit17 : 1;
            u32 OPBBit18 : 1;
            u32 OPBBit19 : 1;
            u32 OPBBit20 : 1;
            u32 OPBBit21 : 1;
            u32 OPBBit22 : 1;
            u32 OPBBit23 : 1;
            u32 OPBBit24 : 1;
            u32 OPBBit25 : 1;
            u32 OPBBit26 : 1;
            u32 OPBBit27 : 1;
            u32 OPBBit28 : 1;
            u32 OPBBit29 : 1;
            u32 OPBBit30 : 1;
            u32 OPBBit31 : 1;
        };
        u32 object_properties_bitfield; // at 0x60
    };
    s32 unk64; // Another bitfield
    u16 unk68;
    u16 unk6A; // is_grounded?
    u16 unk6C;
    s16 unk6E[1]; // TODO: How many elements?
    s16 unk70;
    u16 unk72;
    f32 unk74;
    u8 unk78;
    u8 unk79;
    u8 unk7A;
    u8 unk7B;
    f32 x_position; // at 0x7C
    f32 y_position; // at 0x80
    f32 z_position; // at 0x84
    f32 unk88;
    f32 unk8C;
    f32 unk90;
    f32 unk94;
    f32 unk98;
    f32 unk9C;
    f32 unkA0;
    f32 floor; // at 0xA4
    f32 unkA8; // Used
    f32 unkAC;
    u32 unkB0;
    f32 distance_from_floor; // at 0xB4
    f32 unkB8; // at 0xB8 // velocity?
    f32 unkBC; // at 0xBC
    f32 y_velocity; // at 0xC0
    f32 y_acceleration; // at 0xC4
    f32 terminal_velocity; // at 0xC8
    u8 unkCC; // Used
    u8 unkCD;
    u8 unkCE;
    u8 unkCF;
    u8 unkD0;
    u8 unkD1; // Used
    u8 unkD2;
    u8 unkD3;
    u32 unkD4;
    s16 unkD8; // Used
    s16 unkDA; // Used
    s16 unkDC; // Used
    s16 unkDE;
    f32 unkE0;
    s16 x_rotation; // at 0xE4
    s16 y_rotation; // at 0xE6
    s16 z_rotation; // at 0xE8
    s16 unkEA;
    s16 unkEC; // Something to do with shadow opacity
    s16 unkEE; // TODO: Interacts with rotation, maybe a copy of it?
    s16 unkF0;
    s16 unkF2;
    s16 unkF4;
    s16 unkF6;
    s16 unkF8;
    s16 unkFA; // Used
    u8 unkFC;
    u8 unkFD;
    u8 unkFE;
    u8 unkFF;
    f32 unk100; // Used
    f32 unk104; // Used
    f32 unk108; // Used
    s16 unk10C;
    u8 unk10E; // Used
    u8 unk10F;
    u8 locked_to_pad; // at 0x110
    u8 unk111;
    u8 unk112;
    u8 unk113;
    Actor114 *unk114;
    Actor118 *unk118;
    Actor *unk11C;
    f32 unk120;
    Actor124 *unk124;
    s16 shadow_opacity; // at 0x128, max value 0xFF
    s16 draw_distance; // at 0x12A
    s16 unk12C; // Used
    u8 unk12E;
    u8 unk12F; // Used
    u8 unk130; // Used
    u8 unk131; // Used
    s16 unk132; // Used
    s16 health;
    s16 unk136;
    u32 unk138;
    ActorCollision *collision_queue_pointer; // at 0x13C
    LedgeInfo *ledge_info_pointer; // at 0x140
    u8 noclip_byte; // at 0x144
    u8 unk145;
    union {
        u16 unk146; // used (0x147 hand state? 0x146 seems to be u16)
        s16 unk146_s16; // used func_8068A764
    };
    u32 unk148; // Used
    u32 unk14C; // Used
    FloorTriangle *unk150;
    u8 control_state; // at 0x154
    u8 control_state_progress; // at 0x155
    u8 unk156;
    u8 unk157;
    GlobalASMStruct60 *unk158; // Texture renderer linked list
    s16 unk15C;
    u8 unk15E;
    u8 unk15F; // Used, set to 0x01, 0x06, 0x0B in some cases
    f64 unk160; // TODO: Probably not correct
    s16 unk168; // Used
    u8 unk16A;
    u8 unk16B;
    u8 unk16C;
    u8 unk16D;
    u8 unk16E;
    u8 unk16F;
    u8 unk170;
    u8 unk171;
    u8 unk172;
    u8 unk173;
    union {
        void *additional_actor_data; // For when you don't know which one it's using
        OtherAdditionalActorData *OaaD;
        AnotherAdditionalActorData *AaaD;
        RaceAdditionalActorData *RaaD;
        RaceAdditionalActorData2 *RaaD2;
        YetAnotherAdditionalActorData *YaaD;
        YetAnotherAdditionalActorData4 *YaaD4;
        YetAnotherAdditionalActorData5 *YaaD5;
        MenuAdditionalActorData *MaaD;
        PlayerAdditionalActorData *PaaD;
        PaaD0 *PaaD0; // TODO: Figure this out
        BaaD2 *BaaD2; // TODO: Figure this out
        TempAAD *TaaD; // TODO: Figure this out (race overlay)
        void *additional_data_pointer; //legacy
    };
    union {
        Actor178 *unk178;
        RaceActor178 *race178;
        BossActor178 *boss178;
        A178_806A18A8 *a178_806A18A8;
    };
    union {
        Actor17C *unk17C;
    };
    s32 unk180;
    void* unk184;
};

typedef struct enemy_info {
    u8 enemy_type; // at 0x00
    u8 unk1;
    u16 y_rotation; // at 0x02
    s16 x_position; // at 0x04
    s16 y_position; // at 0x06
    s16 z_position; // at 0x08
    u8 cutscene_model_index; // at 0x0A
    u8 unkB;
    u32 unkC;
    u16 unk10;
    u8 unk12;
    u8 unk13;
    u32 unk14;
    Actor *unk18; // TODO: Is this accurate?
    u32 unk1C;
    Struct80027840 *unk20;
    u16 unk24;
    u16 unk26;
    u16 unk28; // Used
    s16 unk2A; // Used
    u32 unk2C;
    f32 unk30; // Used
    f32 unk34; // Used
    f32 unk38; // Used
    f32 unk3C; // at 0x3C
    s16 unk40; // Used
    s16 unk42;
    u8 unk44; // Used
    u8 unk45;
    u16 unk46; // Used
} EnemyInfo;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3; // Used
} CharacterChange294;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
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
} CharacterChange8Array;

typedef struct {
    u8     does_player_exist; // bitfield? 0x00
    u8     unk1;
    u8     unk2;
    u8     unk3;
    Actor*  player_pointer;    // 0x04
    CharacterChange8Array unk8[2]; // TODO: How many elements are there here?
    u8      pad_unknown[0x208 - 0x80];
    f32     look_at_eye_x; // 0x210 maybe an array?
    f32     look_at_eye_y; // 0x214
    f32     look_at_eye_z; // 0x218
    f32     unk21C; // Used
    f32     unk220; // Used
    f32     unk224; // Used
    f32     look_at_at_x; // 0x228 maybe an array?
    f32     look_at_at_y; // 0x22C
    f32     look_at_at_z; // 0x230
    f32     unk234; // Used
    f32     unk238; // Used
    f32     unk23C; // Used
    f32     look_at_up_x; // 0x240 maybe an array?
    f32     look_at_up_y; // 0x244
    f32     look_at_up_z; // 0x248;
    s32     unk24C;
    u8      pad_unknown2[0x270 - 0x250];
    s16     unk270; // Used, related to map chunk "deload" value
    s16     unk272; // Used, related to map chunk "deload" value
    s16     unk274; // Used, related to map chunk "deload" value
    s16     unk276; // Used, related to map chunk "deload" value
    s16     unk278;
    s16     unk27A;
    f32     fov_y; // 0x27C
    f32     unk280;
    f32     near; // 0x284
    f32     far; // 0x288
    s32     unk28C;
    s16     chunk; // 0x290
    s16     unk292;
    CharacterChange294 *unk294; // Used
    s32     new_controller_inputs; // bitfield 0x298
    s16     action_initiated; // 0x29C
    s16     unk29E;
    Actor*  unk2A0;
    s32     unk2A4;
    s32     unk2A8; // Used
    s32     unk2AC;
    s32     unk2B0; // Used
    u8      pad_unknown3[0x2C0 - 0x2B4];
    u8      unk2C0; // Used
    u8      unk2C1; // Used
    u8      unk2C2; // Used
    u8      unk2C3; // Used
    f32     unk2C4; // Used
    s16     unk2C8; // Used
    s16     unk2CA;
    u8      pad_unknown4[0x2E0 - 0x2CC];
    u16     unk2E0;
    u16     unk2E2;
    u8      unk2E4;
    u8      unk2E5;
    u8      unk2E6;
    u8      unk2E7;
    u8      unk2E8;
    u8      unk2E9;
    u8      unk2EA;
    u8      unk2EB;
    u8      unk2EC;
    u8      unk2ED;
    u8      unk2EE;
    u8      unk2EF;
} CharacterChange;

typedef struct global_asm_struct_83 GlobalASMStruct83;
struct global_asm_struct_83 {
    Actor* unk0;
    u32 unk4;
    Actor* unk8;
    GlobalASMStruct83 *next;
};

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
    u8 unkD0;
    u8 unkD1;
    u8 unkD2;
    u8 unkD3;
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
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    void *unk24[1]; // TODO: How many?
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    void *unk34[1]; // TODO: How many?
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s16 unk4C;
    u8 unk4E; // Used
    u8 unk4F; // Used
    Model2Model50_B8 *unk50; // Used, pointer
    Model2Model54_BC *unk54;
    u8 unk58;
    u8 unk59;
    u8 unk5A;
    u8 unk5B;
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
    u8 unkC0;
    u8 unkC1;
    u8 unkC2;
    u8 unkC3;
} Model2Model;

typedef struct {
    s32 unk0;
    u32 unk4;
    f32 unk8;
    f32 unkC;
    s16 unk10;
    s16 unk12;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    s32 unk38;
    f32 unk3C;
    s16 unk40;
    s16 unk42;
    s16 unk44[2];
    u8 unk48[3];
    u8 unk4B[3];
    s8 unk4E;
    s8 unk4F;
    s8 unk50;
    s8 unk51;
    u8 unk52;
    s8 unk53;
    s8 unk54;
    s8 unk55;
    s8 unk56;
    s8 unk57;
    s32 unk58;
    u8 unk5C;
    u8 unk5D;
    u8 unk5E;
    u8 unk5F;
    u8 unk60;
    u8 unk61;
    s16 unk62;
    s16 unk64;
    u8 unk66;
    u8 unk67;
    s32 unk68;
    s16 unk6C;
    s8 unk6E;
    s8 unk6F;
    s8 unk70;
    s8 unk71;
    u8 unk72;
    u8 unk73;
    f32 unk74;
    f32 unk78;
    f32 unk7C;
    s16 unk80;
    s16 unk82;
    u16 unk84;
    u16 unk86;
    s16 unk88;
    u16 unk8A;
    f32 unk8C;
    f32 unk90;
    Actor *unk94;
    s16 unk98;
    u8 unk9A;
    s8 unk9B;
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
} OM2_unk24;

typedef struct OM2_unk74 OM2_unk74;

struct OM2_unk74 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    OM2_unk74 *next;
};

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    s8 unk5;
    u8 unk6;
    u8 unk7;
    s32 unk8;
    f32 unkC;
    s16 unk10;
    s16 unk12;
} OM2_unk78;

typedef struct {
    u8 unk0[0x10 - 0x0];
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    s32 unk18;
} OM2_unk28;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[0x24 - 0xC];
    u8 unk24;
    u8 unk25[2];
} OM2_unk48;

typedef struct object_model2 {
    f32 x_position; // at 0x00
    f32 y_position; // at 0x04
    f32 z_position; // at 0x08
    f32 hitbox_scale; // at 0x0C
    f32 x_rotation; // at 0x10
    f32 y_rotation; // at 0x14
    f32 z_rotation; // at 0x18
    f32 unk1C;
    Model2Model *model_pointer; // at 0x20
    OM2_unk24 *unk24; // labelled behavior_type_pointer in ScriptHawk
    OM2_unk28 *unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    OM2_unk48 *unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    u8 unk6C;
    u8 unk6D[1]; // TODO: How many?
    u8 unk6E;
    u8 unk6F;
    GlobalASMStruct83 *unk70;
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

typedef struct chunk_14 Chunk14;

struct chunk_14 {
    Model2Model *unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    Chunk14 *next;
    Chunk14 *next2;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    u8 unk22; // Used
    u8 unk23; // Used
    u8 unk24; // Used
};

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    u8 unk12;
    u8 unk13;
} Chunk78_7C;

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} Chunk4C;

typedef struct {
    u8  loaded;
    u8  unk1; // used
    u8  unk2;
    u8  unk3;
    u8  unk4;
    u8  visible; // 0x5 -- if 0x02 visible, else invisible
    u8  unk6;
    u8  unk7;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    Chunk14 *unk14;
    s32 unk18;
    Chunk14 *unk1C; // TODO: Same struct as unk14?
    s32 unk20;
    s32 unk24;
    u8  pad8[0x4C - 0x28];
    Chunk4C *unk4C;
    s32 unk50;
    u8  pad54[0x60 - 0x54];
    s32 unk60[1]; // TODO: How many?
    s32 unk64;
    s32 deload1; // 0x68
    s32 deload2; // 0x6C
    s32 deload3; // 0x70
    s32 deload4; // 0x74
    Chunk78_7C *unk78; // First in array?
    Chunk78_7C *unk7C; // Last in array?
    s16 unk80; // Used
    s16 unk82; // Used
    s16 unk84; // Used
    s16 unk86; // Used
    u8  pad2[0x1C8 - 0x88]; // total size 0x1C8
} Chunk;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unkC;
    s32 unk8;
    s32 unk10;
    s32 unk14;
    s32 unk1C;
    s32 unk18;
} Struct807500B4;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8[1]; // TODO: How many elements?
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
} Struct8073BC74;

// func_80712944, func_8060AC34
typedef struct global_asm_struct_12 {
    u16 unk0;
    s8 unk2;
    s8 unk3;
    s16 unk4;
    u16 unk6;
    s8 unk8;
    s8 unk9;
    u16 unkA;
    u16 unkC;
    s8 unkE;
    s8 unkF;
    u16 unk10;
    u16 unk12;
    s8 unk14;
    s8 unk15;
} GlobalASMStruct12;

typedef struct {
    u8 pad0[0x6 - 0x0];
    s16 unk6;
    u8 unk8;
    u8 unk9;
    union {
        u8 unkA_u8[2];
        u16 unkA_u16;
        s16 unkA_s16;
    };
    u8 unkC; // Used
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10; // Used
    u8 unk11;
    u8 unk12;
    u8 unk13; // Used
} CharacterSpawner;

typedef struct global_asm_struct_17 {
    u16 unk0;
    s8 unk2;
    s8 unk3;
} GlobalASMStruct17;

typedef struct JetpacStruct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
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
    u8 pad1[0x44 - 0x3C];
    s32   unk44;
    void (*unk48)();
    s32 *unk4C;
} JetpacStruct;

typedef struct JetpacItem {
    u8 unk0;
} JetpacItem;

typedef struct CompetitorSub14 {
    u8 unk0[0x8];
    f32 unk8;
    f32 unkC;
    u8 unk10[0x1C-0x10];
    s32 unk1C;
    u8 unk20[0x48-0x20];
    void* code;
} CompetitorSub14;

typedef struct Competitor {
    s32 level;
    s32 current_score;
    s32 lives;
    s32 lives_consumed;
    s32 unk10; //used
    CompetitorSub14 unk14[4];
    s32 unk_144;
    JetpacItem next_item_pointer;
    u8 unk14C[4];
    float unk150;
    u8 pad1[0x18C - 0x154];
    void (*fun_ptr)(JetpacItem*);
    void (*fun_ptr2)(JetpacItem*,u8);
    //u8 unk_190[4];
} Competitor;

typedef struct JetpacPlayerStruct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s8 unkC;
    s8 unkD;
    s8 unkE;
    s8 unkF;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    Competitor player[2];
    s32 player_index;
    s32 unk348;
    s32 unk34C;
    s32 unk350;
    s32 unk354;
    s32 unk358;
    s32 unk35C;
    s32 unk360;
    s32 unk364;
    s32 unk368;
    s32 unk36C; // Used
    s32 unk370;
    s32 unk374; // Used
    u8 pad378[0x420 - 0x378];
    f32 unk420;
    f32 unk424;
    f32 unk428;
    f32 unk42C;
    u8 unk430;
    u8 unk431;
    u8 unk432;
    u8 unk433;
    s32 unk434;
    s32 unk438;
    s32 unk43C;
    s32 unk440;
    s32 unk444;
    s32 unk448;
    s32 unk44C;
    s32 unk450;
    s32 unk454;
    s32 unk458;
    s32 unk45C;
    s32 unk460;
    s32 unk464;
    u8 unk468;
    u8 unk469;
    u8 unk46A;
    u8 unk46B;
    u8 pad46C[0x78C - 0x46C];
    s32 unk78C;
    s32 unk790;
    s32 unk794;
    u8 unk798;
    u8 unk799;
    u16 unk79A;
} JetpacPlayerStruct;

typedef struct ActorSpawner ActorSpawner;

struct ActorSpawner {
    s16 actor_type; // At 0x0
    u16 unk2;
    f32 x_position; // At 0x4
    f32 y_position; // At 0x8
    f32 z_position; // At 0xC
    f32 unk10;
    f32 unk14;
    f32 unk18;
    s16 y_rotation; // At 0x1C
    u16 unk1E;
    f32 unk20; // At 0x20, Used
    u8 pad24[0x32 - 0x24];
    s16 unk32;
    u8 pad34[0x44 - 0x34];
    Actor* tied_actor; // At 0x44
    u8 unk48; // Used
    u8 unk49;
    s16 unk4A;
    u8 unk4C; // Used
    u8 unk4D;
    Actor *unk50;
    f32 unk54;
    s16 unk58;
    s16 id; // At 0x5A
    s32 (*unk5C)(s32); // At 0x5C
    s32 (*drawing_code)(s32); // At 0x60
    ActorSpawner* previous_spawner; // At 0x64
    ActorSpawner* next_spawner; // At 0x68
    u8 pad6C[0x80 - 0x6C];
};

typedef struct {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
} Struct8075EB80;

extern Struct8075EB80 D_8075EB80[];

// TODO: Use that clever tuple thing from BKomp
typedef struct {
    s16 coords_0[3]; // 0x0
    s16 coords_1[3]; // 0x6
    s16 coords_2[3]; // 0xC
    s16 coords_3[3]; // 0x12
    s16 coords_4[3]; // 0x18
} EnemyAggressionBox;

typedef struct {
    s16 x_pos_0; // 0x0
    s16 z_pos_0; // 0x2
    s16 x_pos_1; // 0x4
    s16 z_pos_1; // 0x6
    EnemyAggressionBox *aggression_box_pointer; // = 0xC, -- u32
} EnemyMovementBox;

typedef struct {
	u8 enemy_value; // 0x0
    u8 unk1;
	u16 y_rot; // 0x2
	s16 x_pos; // 0x4
	s16 y_pos; // 0x6
	s16 z_pos; // 0x8
	u8 cs_model; // 0xA
    u8 unkB;
	u8 max_idle_speed; // 0xC
	u8 max_aggro_speed; // 0xD
    u8 unkE;
	u8 scale; // 0xF
	u8 aggro; // 0x10
    u8 unk11;
	u8 something_spawn_state; // 0x12
	u8 spawn_trigger; // 0x13
	u8 respawn_timer_init; // 0x14 - Result is multiplied by 30 to get actual respawn timer
	u8 unk15;
    u8 unk16;
    u8 unk17;
    Actor *tied_actor; // 0x18
	EnemyMovementBox *movement_box_pointer; // 0x1C
	void *unk20; // 0x20
	s16 respawn_time; // 0x24
    s16 unk26;
    s32 unk28;
	f32 unk2C; // 0x2C initially written to 0.01
	f32 unk30; // 0x30 initially written to 1
	f32 animation_speed; // 0x34
	u32 unk38; // 0x38 TODO: maybe float, based on alt enemy type
	u32 unk3C;
    s16 chunk; // 0x40
	u8 spawn_state; // 0x42
	u8 counter; // 0x43
	u8 alternative_enemy_spawn; // 0x44

	// 1000 0000 0000 0000 - ?
	// 0100 0000 0000 0000 - ? Resets on Respawn
	// 0010 0000 0000 0000 - ? Resets on Respawn
	// 0001 0000 0000 0000 - ?

	// 0000 1000 0000 0000 - ?
	// 0000 0100 0000 0000 - ?
	// 0000 0010 0000 0000 - ?
	// 0000 0001 0000 0000 - ?

	// 0000 0000 1000 0000 - ?
	// 0000 0000 0100 0000 - Ignores instrument plays
	// 0000 0000 0010 0000 - Ignores movement boundaries
	// 0000 0000 0001 0000 - ?

	// 0000 0000 0000 1000 - ? Reset on respawn
	// 0000 0000 0000 0100 - ?
	// 0000 0000 0000 0010 - Won't Respawn
	// 0000 0000 0000 0001 - Spawned from respawn pending

    // TODO: proper bitfield syntax
	u16 properties_bitfield; // = 0x46 bitfield -- TODO: Document this, find where this comes from so we can display stuff pre-load
} EnemySpawner; // 807FDC8C pointer to array of structs, count at 807FDC88

typedef struct Struct807FDC90 Struct807FDC90;

// Use this for D_807FDC90
struct Struct807FDC90 {
    Struct807FDC90 *unk0; // TODO: This type may not be correct
    Actor *unk4;
    s16 unk8;
    s16 unkA; // Used: X Position
    s16 unkC; // Used
    s16 unkE; // Used: Z Position
    s16 unk10; // Used
    s16 unk12;
    s16 unk14; // Used
    s16 unk16;
    u16 unk18;
    u16 unk1A; // Used
    u16 unk1C; // Used
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    s16 unk26; // Used
    s32 unk28;
    s16 unk2C;
    s16 unk2E; // TODO: This might not be correct
    f32 unk30; // Used
    u8 unk34;
    u8 unk35; // Used
    u8 unk36;
    u8 unk37;
    u8 unk38;
};

typedef struct ExitData {
	s16 x_pos; // At 0x00
	s16 y_pos; // At 0x02
	s16 z_pos; // At 0x04
    u8 angle; // At 0x06
    u8 unk7; // At 0x07
    u8 has_autowalk; // At 0x08
    u8 size; // At 0x0A
} ExitData;

// From Practice ROM
typedef struct spriteDisplay {
	/* 0x000 */ s32 disappear;
	/* 0x004 */ s8 unk_04[0x11];
	/* 0x015 */ s8 unk_15;
} spriteDisplay;

typedef struct spriteControl {
	/* 0x000 */ f32 movement_style;
	/* 0x004 */ f32 pointer_offset_0x15;
	/* 0x008 */ f32 xPos;
	/* 0x00C */ f32 yPos;
	/* 0x010 */ f32 scale;
	/* 0x014 */ f32 unk_14;
	/* 0x018 */ s32 unk_18;
	/* 0x01C */ s32 unk_1C;
} spriteControl;

typedef struct otherSpriteControl {
	/* 0x000 */ s8 unk_000[0x28];
	/* 0x028 */ u8 left_stretch;
	/* 0x029 */ u8 right_stretch;
	/* 0x02A */ u8 up_stretch;
	/* 0x02B */ u8 down_stretch;
	/* 0x02C */ s8 unk_02C[0x340-0x2C];
	/* 0x340 */ f32 xPos;
	/* 0x344 */ f32 yPos;
	/* 0x348 */ f32 unk_348;
    /* 0x34C */ s8 unk_34C[4];
	/* 0x350 */ s8 gif_update_frequency;
	/* 0x351 */ s8 unk_351[0xB];
	/* 0x35C */ spriteControl* gif_control_pointer;
	/* 0x360 */ f32 xScale;
	/* 0x364 */ f32 yScale;
	/* 0x368 */ s8 unk_368[0x2];
	/* 0x36A */ s8 transparency1;
	/* 0x36B */ s8 transparency2;
	/* 0x36C */ s8 transparency3;
	/* 0x36D */ s8 transparency4;
	/* 0x36E */ s8 unk_36E[0x384-0x36E];
	/* 0x384 */ void* some_pointer;
} otherSpriteControl;

// TODO: Which struct is this?
typedef struct {
    s32 unk0[21];
    s8 unk54; // Used
    s8 unk55;
    s8 unk56;
    s8 unk57;
    s32 unk58; // Used
    s32 unk5C;
} Struct8064199C_arg0;

typedef struct {
    u8  pad0[0x14];
    f32 unk14;
    u8  pad1[0x31];
    u8 unk49;
} GlobalASMStruct49;

typedef struct {
    s16 unk0;
    s16 unk2;
} Struct80717D84_unk384_80717814;

typedef struct {
    f32 unk0;
    f32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} Struct80717D84_unk384;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80717D84_unk384_f32;

typedef struct {
    s16 unk0;
} Struct80717D84_unk384_s16;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
} Struct80717D84_unk384_80717100;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct80717D84_unk384_8071720C;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Struct80717D84_unk384_80717B64;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} Struct80717D84_unk384_8071DC90;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} Struct80717D84_unk384_8071E110;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80717D84_unk384_8071F444;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
} Struct80717D84_unk384_80717930;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct80717D84_unk384_807189BC;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} Struct80717D84_unk384_80719C00;

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80717D84_unk384_80719EF4;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80717D84_unk384_8071D0F0;

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80717D84_unk384_8071B2EC;

typedef struct {
    u8 unk0[0x16 - 0x0];
    s16 unk16;
} Struct80717D84_unk330;

typedef struct Struct80717D84 Struct80717D84;

typedef struct {
    void *unk0;
    void *unk4;
} Struct80717D84_unk0;

struct Struct80717D84 {
    Struct80717D84_unk0 unk0[4]; // TODO: How many?
    u8 unk20;
    u8 unk21[0x128 - 0x21];
    float unk128[2][4][4]; // TODO: How many?
    u8 unk1A8[0x328 - 0x1A8];
    void *unk328;
    u8 unk32C;
    u8 unk32D[0x330 - 0x32D];
    Struct80717D84_unk330 *unk330;
    s8 unk334;
    s8 unk335;
    s8 unk336;
    s8 unk337;
    Actor *unk338;
    s16 unk33C;
    s8 unk33E;
    s8 unk33F;
    f32 unk340; // X
    f32 unk344; // Y
    f32 unk348; // Z
    s16 unk34C;
    s16 unk34E;
    u8 unk350;
    u8 unk351;
    u8 unk352;
    u8 unk353;
    s32 unk354;
    s32 unk358;
    union {
        s32 unk35C;
        u32 unk35C_u32;
        Actor *unk35C_actor;
    };
    f32 unk360; // X
    f32 unk364; // Y
    s16 unk368;
    u8 unk36A;
    u8 unk36B;
    u8 unk36C;
    u8 unk36D;
    u8 unk36E;
    u8 unk36F;
    u8 unk370[0x380 - 0x370];
    s32 unk380;
    union {
        Struct80717D84_unk384 *unk384;
        Struct80717D84_unk384_f32 *unk384_f32;
        Struct80717D84_unk384_s16 *unk384_s16;
        Struct80717D84_unk384_80717100 *unk384_80717100;
        Struct80717D84_unk384_80717814 *unk384_80717814;
    };
    s16 unk388;
    s8 unk38A;
    s8 unk38B;
    u16 unk38C;
    u16 unk38E;
    u16 unk390;
    u16 unk392;
    u16 unk394;
    Struct80717D84 *unk398; // Prev?
    Struct80717D84 *unk39C; // Next?
};

typedef struct Struct807FDB00 Struct807FDB00;

struct Struct807FDB00 {
    void *unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14[0x24 - 0x14];
    Struct807FDB00 *next;
};

typedef struct Struct807FDB04 Struct807FDB04;

struct Struct807FDB04 {
    u8 unk0[0x338 - 0x0];
    Actor *unk338;
    u8 unk33C[0x39C - 0x33C];
    Struct807FDB04 *next;
};

#endif
