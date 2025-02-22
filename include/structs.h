#ifndef __STRUCTS_H__
#define __STRUCTS_H__
#include "synthinternal.h"

/* your struct definitions go here */

typedef struct tuple_f {
    union {
        struct {
            f32 x;
            f32 y;
            f32 z;
        };
        f32 f[3];
    };
} tuple_f;

typedef struct tuple_s {
    union {
        struct {
            s16 x;
            s16 y;
            s16 z;
        };
        s16 f[3];
    };
} tuple_s;

typedef struct OverlayInfoStruct {
    s32 rom_code_start;
    s32 rom_data_end;
    void *rdram_start;
    void *overlay_end;
    void *rdram_code_end;
    void *rdram_data_end;
} OverlayInfoStruct;

typedef struct Critter Critter;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u16 unk4;
    u8 unk6;
    u8 unk7;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s16 unk18;
    u8 unk1A;
    u8 unk1B;
} MenuStruct80024000;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Struct8075C410;

typedef struct {
    s32 unk0;
    s32 unk4;
    union {
        struct {
            u8 unk8_0 : 1;
            u8 unk8_1 : 1;
            u8 unk8_2 : 1;
            u8 unk8_3 : 1;
            u8 unk8_4 : 1;
            u8 unk8_5 : 1;
            u8 unk8_6 : 1;
            u8 unk8_7 : 1;
        };
        u8 unk8;
    };
    u8 unk9;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    tuple_s unk20;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
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
} MapGeometryHeader;

// Finally!!!
typedef struct {
    union {
        f32 unk0;
        s32 unk0_s32;
        s32 *unk0_s32_ptr;
    };
    union {
        f32 unk4;
        s32 unk4_s32;
        s32 *unk4_s32_ptr;
    };
    f32 unk8;
} Struct807F5FD4_unk0;

typedef struct {
    Struct807F5FD4_unk0 *unk0[2];
    s32 unk8;
} Struct807F5FD4;
extern Struct807F5FD4 *D_global_asm_807F5FD4;

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
    s8 unk2FA;
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

typedef struct LedgeInfo74 {
    Mtx unk0[];
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
    Mtx *unk70;
    Mtx *unk74[2];
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

typedef struct AnimationStateUnk0_0 {
    f32 unk0;
    u16 unk4;
    u8 pad6[0x12 - 0x6];
    u8 unk12;
} AnimationStateUnk0_0;

// TODO: What is this actually?
typedef struct animation_state_unk0 {
    AnimationStateUnk0_0 *unk0;
    f32 unk4; // Used
    f32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10; // Used
    s16 unk12;
    f32 unk14;
    f32 unk18;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    f32 unk24; // Used
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
} AnimationStateUnk0;

typedef struct {
    s8 unk0;
    s8 unk1;
    union {
        s16 unk2;
        u16 unk2_u16; // used in K Rool Diddy code
    };
    s16 unk4;
    union {
        s16 unk6;
        u16 unk6_u16;
    };
    // Note: This is correctly sized, if you get references to unk8, use unk1C[1].unk0 instead
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

// See boss func_dk64_boot_8002FB7C
typedef struct animation_state_unk20 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} AnimationStateUnk20;

typedef struct actor_collision ActorCollision;
typedef struct actor Actor;

typedef struct ActorAnimationState_unk170 {
    u8 pad0[0x80];
} ActorAnimationState_unk170;

typedef struct actor_animation_state {
    AnimationStateUnk0 *unk0;
    AnimationStateUnk0 *unk4;
    AnimationStateUnk0 *unk8;
    AnimationStateUnk0 *unkC;
    f32 unk10;
    Mtx *bone_arrays[2]; // at 0x14, camera, update bone positions // TODO: Proper type
    AnimationStateUnk1C *unk1C;
    AnimationStateUnk20 *unk20; // See boss func_dk64_boot_8002FB7C
    AnimationStateUnk24 *unk24;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    union {
        struct {
            f32 scale_x; // at 0x34
            f32 scale_y; // at 0x38
            f32 scale_z; // at 0x3C
        };
        f32 scale[3];
    };
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    u16 unk5C;
    s16 unk5E;
    s32 unk60;
    u16 unk64; // Used
    u16 unk66;
    s32 unk68;
    s32 unk6C;
    s32 (*unk70)(Actor *);
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    f32 unk80;
    s32 unk84;
    s32 unk88;
    f32 unk8C;
    AnimationStateUnk0 unk90[4];
    ActorAnimationState_unk170 unk170[1];
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
    union {
        f32 unkC; // Used
        s32 unkC_s32; // Used // TODO: We might have another aaD situation here...
    };
    f32 unk10; // Used
    union {
        f32 unk14; // Used
        s32 unk14_s32; // Used // TODO: We might have another aaD situation here...
    };
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
    f32 unk8;
    u8 unkC;
    s8 unkD;
    s16 unkE;
    s16 unk10;
    s16 unk12;
} Actor118;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct807FBB70_unk278;

// TODO: What type is this actually?
// D_global_asm_807FBB70
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4; // X Position (updated when touching warp pad)
    f32 unk8; // Y Position (updated when touching warp pad)
    f32 unkC; // Z Position (updated when touching warp pad)
    s16 unk10;
    s16 unk12;
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
    Actor *unk7C[4]; // TODO: Confirm array count
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
    f32 unk8;
    s32 unkC;
    s16 unk10;
    u8 unk12;
    u8 unk13; // Used in func_global_asm_806925AC
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
    u8  unk26; // Used
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
    u8 pad46[2];
    s16* unk48;
    u8 pad4C[4];
    Mtx unk50[2];
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
    Actor *unkC; // Used
    Actor *unk10; // Used
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
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s8  unk12;
    s8  unk13;
    s8 unk14;
    s8 unk15;
    s8  unk16;
    s8 unk17;
} MenuAdditionalActorData;

typedef struct SnideAaD180 {
    u8 control_byte;
    u8 screen;
    u8 turned_in_count;
    u8 pad[0x3];
    u8 unk6;
    u8 unk7;
    s32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s8 previous_y;
    s8 minigame_menu_unlocked;
    u8 unturned_count;
    u8 pad2[0x5];
} SnideAaD180;

typedef struct otherSpriteControl otherSpriteControl;

typedef struct player_additional_actor_data {
    s16 unk0; // Used
    s16 unk2;
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
    f32 unk54; // Used, y velocity?
    s32 unk58; // Used, related to D_global_asm_80767CC0
    s32 unk5C;
    s32 unk60;
    s16 unk64; // Used
    s16 unk66;
    f32 unk68;
    f32 unk6C; // Used
    s16 unk70; // Used, y rotation?
    s16 unk72;
    f32 unk74;
    f32 unk78; // used
    f32 unk7C; // used
    s16 unk80; // used
    s16 unk82;
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
    union {
        struct {
            s16 unkB0;
            s16 unkB2; // Used
        };
        f32 unkB0_f32;
    }; // TODO: Deconflict
    f32 unkB4; // Used
    f32 unkB8; // Used
    s16 unkBC; // Used
    s16 unkBE;
    s16 unkC0;
    s16 unkC2; // Used
    s32 unkC4;
    s16 unkC8;
    u8  unkCA; // Used
    s8  unkCB;
    s16 unkCC; // Used
    s16 unkCE;
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
    s16 unk10E;
    s16 unk110;
    s16 unk112;
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
    u16 unk1B8; // Used
    s16 unk1BA;
    f32 unk1BC; // Used
    union {
        struct {
            f32 unk1C0; // Used, x scale
            f32 unk1C4; // Used, y scale
            f32 unk1C8; // Used, z scale
        };
        f32 scale1C0[3];
    };
    union {
        struct {
            f32 unk1CC; // Used, x scale
            f32 unk1D0; // Used, y scale
            f32 unk1D4; // Used, z scale
        };
        f32 scale1CC[3];
    };
    f32 unk1D8; // Used
    f32 unk1DC; // Used
    f32 unk1E0; // Used
    s32 unk1E4;
    s32 unk1E8;
    u8 unk1EC;
    u8 unk1ED;
    s16 unk1EE; // Used
    s32 unk1F0; // Used, bitfield // TODO: Proper bitfield syntax
    s32 unk1F4;
    s32 unk1F8;
    u8 unk1FC; // Used
    u8 unk1FD;
    u16 unk1FE; // Used
    s16 unk200; // Used
    s16 unk202;
    f32 unk204;
    f32 unk208;
    f32 unk20C;
    f32 unk210; // Used, x
    f32 unk214; // Used, y
    f32 unk218; // Used, z
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
    u16 unk242; // Used, map?
    u8 unk244;
    u8 unk245; // Used
    s8 unk246; // Used func_global_asm_806CA26C
    s8 unk247; // Used func_global_asm_806CA26C
    s8 unk248;
    s8 unk249;
    u8 unk24A;
    s8 unk24B; // Used
    u16 unk24C; // Used // TODO: s16? func_global_asm_806CA1B4 uses this as u16
    u16 unk24E; // Used // TODO: s16? func_global_asm_806CA1B4 uses this as u16
    s32 unk250;
    otherSpriteControl *unk254;
    f32 unk258; // Used
    f32 unk25C; // Used
    void *unk260; // Used (multiplayer)
    s32 unk264; // Used
    u8 unk268; // Used
} PlayerAdditionalActorData;

//f32 at unk8 doesn't match with what's in structs.h (s16) 
//for PlayerAdditionalActorData so making this struct
typedef struct {
    u8 pad0[0x8];
    f32 unk8;
} PaaD0;

// Bonus func_bonus_800253E4
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

typedef struct struct806A57C0_3_sub10 {
    s16 unk0;
    s16 unk2;
    void *unk4;
    Mtx unk8[2];
    f32 unk88;
} struct806A57C0_3_sub10;

struct struct806A57C0_3 {
    s16 unk0;
    u8 unk2; // Used
    u8 unk3;
    f32 unk4; // Used
    f32 unk8; // Used
    s32 unkC;
    struct806A57C0_3_sub10 unk10;
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
    void *unk34; // Used
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
} AAD_global_asm_806A4DDC;

// TODO: This appears to be a "texture renderer" according to ScriptHawk, needs a better name though. Linked list at Actor->unk158
typedef struct global_asm_struct_60 GlobalASMStruct60;

struct global_asm_struct_60 {
    s32 *unk0; // Used
    GlobalASMStruct60 *unk4; // Used? Might be wrong datatype, see func_global_asm_80688638
    u8 unk8; // Used
    u8 unk9;
    s16 unkA; // Used
    s16 unkC; // Used - Texture index?
    s16 unkE;
    f32 unk10; // Used
    f32 unk14; // Used
    s16 unk18; // Used
    s16 unk1A; // Used
    s16 unk1C; // Used
    s16 unk1E; // Used
    u8 unk20; // Used
    u8 unk21; // Used
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

typedef struct {
    Actor *unk0;
    Actor *unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
} CameraPaad_unk44;

typedef struct {
    Actor *unk0;
    u8 pad4[0x20 - 0x4];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    u8 pad38[0x44 - 0X38];
    CameraPaad_unk44 * unk44;
    s32 unk48;
    u8 pad4C[0x90 - 0x4C];
    f32 unk90;
    u8 pad94[0xAC - 0x94];
    s32 unkAC;
    u8 padB0[0xF3 - 0xB0];
    u8 unkF3;
    u8 padF4[0xFA - 0xF4];
    u8 unkFA;
    u8 unkFB;
} CameraPaad;

typedef struct {
    // Small header on top of DisplayList Pointer
    u8 unk0[0x1C - 0x0];
    s16 unk1C;
    u8 pad1E[2];
    u8 unk20;
    u8 unk21[0x38 - 0x21];
    f32 unk38;
} Actor_unk0;

typedef struct KRoolChunkyAAD178 {
    Actor *unk0;
    u8 pad4[0x14 - 0x4];
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
} KRoolChunkyAAD178;

struct actor {
    Actor_unk0 *unk0; 
    ActorAnimationState *animation_state;
    u32 *unk8; // Current bone array Pointer // TODO: Proper type
    s16 unkC;
    s16 unkE;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    f32 unk24;
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
    union {
        struct {
            f32 x_position; // at 0x7C
            f32 y_position; // at 0x80
            f32 z_position; // at 0x84
        };
        tuple_f position;
    };
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
    s8 unkB0;
    s8 padB1[3];
    f32 distance_from_floor; // at 0xB4
    f32 unkB8; // at 0xB8 // velocity?
    f32 unkBC; // at 0xBC
    f32 y_velocity; // at 0xC0
    f32 y_acceleration; // at 0xC4
    f32 terminal_velocity; // at 0xC8
    u8 unkCC; // Used, bone index?
    u8 unkCD;
    s16 unkCE;
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
    union {
        s16 unk132;
        u16 unk132_u16;
    };
    s16 health;
    s16 unk136;
    u32 unk138;
    ActorCollision *collision_queue_pointer; // at 0x13C
    LedgeInfo *ledge_info_pointer; // at 0x140
    u8 noclip_byte; // at 0x144
    u8 unk145;
    union {
        u16 unk146; // used (0x147 hand state? 0x146 seems to be u16)
        s16 unk146_s16; // used func_global_asm_8068A764
    };
    void *unk148; // Used
    void *unk14C; // Used
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
        void *AAD_as_array[4];
        struct {
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
                CameraPaad *CaaD;
                PaaD0 *PaaD0; // TODO: Figure this out
                BaaD2 *BaaD2; // TODO: Figure this out
                TempAAD *TaaD; // TODO: Figure this out (race overlay)
                void *additional_data_pointer; //legacy
            };
            union {
                void *unk178;
                Actor178 *a178;
                RaceActor178 *race178;
                BossActor178 *boss178;
                A178_806A18A8 *a178_806A18A8;
            };
            union {
                Actor17C *unk17C;
            };
            union {
                void *unk180;
                SnideAaD180* snide_aad_180;
            };
        };
    };
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
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} CharacterChange250;

typedef struct {
    f32 unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
} CharacterChange2DC;

typedef struct {
    u8      does_player_exist; // bitfield? 0x00
    u8      unk1;
    u8      unk2;
    u8      unk3;
    Actor*  player_pointer;    // 0x04
    Mtx     unk8[2];
    Mtx     unk88[2];
    u8      pad108[0x188 - 0x108];
    u16     unk188;
    u8      pad18A[0x190 - 0x18A];
    LookAt  unk190[2];
    Hilite  unk1D0[2];
    Hilite  unk1F0[2]; // Unsure on struct. Is a 0x10-sized struct 
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
    CharacterChange250 unk250[2];
    s16     unk270[4];
    union {
        struct {
            s16     unk278;
            s16     unk27A;
        };
        s16 unk278_arr[2];
    };
    f32     fov_y; // 0x27C
    f32     unk280;
    f32     near; // 0x284
    f32     far; // 0x288
    f32     unk28C;
    s16     chunk; // 0x290
    s16     unk292;
    OSContPad *unk294; // Used
    OSContPad *new_controller_inputs; // bitfield 0x298
    s16     action_initiated; // 0x29C
    s16     unk29E;
    Actor*  unk2A0;
    s32     unk2A4;
    s32     unk2A8; // Used
    s32     unk2AC;
    s32     unk2B0; // Used
    tuple_f unk2B4;
    u8      unk2C0; // Used
    u8      unk2C1; // Used
    u8      unk2C2; // Used
    u8      unk2C3; // Used
    f32     unk2C4; // Used
    s16     unk2C8; // Used
    s16     unk2CA;
    s16     unk2CC;
    s16     unk2CE;
    f32     unk2D0;
    f32     unk2D4;
    f32     unk2D8;
    CharacterChange2DC      unk2DC;
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

typedef struct prop_model_50_b8 PropModel50_B8;

struct prop_model_50_b8 {
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
    PropModel50_B8 *next; // unkD4
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
} PropModel54_BC;

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
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    u8 unk4E; // Used
    u8 unk4F; // Used
    PropModel50_B8 *unk50; // Used, pointer
    PropModel54_BC *unk54;
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
    s16 unkB4;
    s16 unkB6;
    PropModel50_B8 *unkB8; // Used, pointer
    PropModel54_BC *unkBC; // Used
    u8 unkC0;
    u8 unkC1;
    u8 unkC2;
    u8 unkC3;
} PropModel;

typedef struct {
    void* unk0;
    u32 unk4;
    f32 unk8;
    f32 unkC;
    s16 unk10;
    s16 unk12;
    f32 unk14[8]; // Unsure how many members of this array there are
    f32 unk34;
    s32 unk38;
    f32 unk3C;
    s16 unk40;
    s16 unk42;
    s16 unk44[2];
    u8 unk48[3];
    u8 next_state[3];
    s8 unk4E;
    s8 unk4F;
    u8 unk50;
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
    u16 unk5E;
    u8 unk60;
    u8 unk61;
    s16 unk62;
    s16 unk64;
    u8 unk66;
    u8 unk67;
    s32 unk68;
    s16 unk6C;
    u8 unk6E;
    s8 unk6F;
    union {
        u8 unk70;
        s8 unk70_s8;
    };
    u8 unk71;
    u8 unk72;
    u8 unk73;
    f32 unk74;
    f32 unk78;
    f32 unk7C;
    s16 unk80;
    s16 unk82;
    s16 unk84;
    s16 unk86;
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
} Prop_ScriptData;

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
} Prop_unk24;

typedef struct Prop_unk74 Prop_unk74;

struct Prop_unk74 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    Prop_unk74 *next;
};

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    union {
        s8 unk5;
        u8 unk5_u8;
    };
    u8 unk6;
    u8 unk7;
    s32 unk8;
    f32 unkC;
    s16 unk10;
    s16 unk12;
} Prop_unk78;

typedef struct {
    u8 unk0[0x10 - 0x0];
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    void *unk18;
} Prop_unk28;

typedef struct {
    void *unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[0x24 - 0xC];
    u8 unk24;
    u8 unk25[2];
} Prop_unk48;

typedef struct {
    Prop_unk28 *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 pad16[2];
    s32 unk18;
    s32 unk1C;
} Prop_seg28;

typedef struct prop {
    f32 x_position; // at 0x00
    f32 y_position; // at 0x04
    f32 z_position; // at 0x08
    f32 hitbox_scale; // at 0x0C
    f32 x_rotation; // at 0x10
    f32 y_rotation; // at 0x14
    f32 z_rotation; // at 0x18
    f32 unk1C;
    PropModel *model_pointer; // at 0x20
    Prop_unk24 *unk24; // labelled behavior_type_pointer in ScriptHawk
    Prop_seg28 unk28;
    Prop_unk48 *unk48;
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
    Prop_unk74 *unk74;
    Prop_unk78 *unk78; // used in func_global_asm_80650AD8, weird format
    Prop_ScriptData *unk7C; // labelled behavior_pointer in ScriptHawk
    s32 unk80;
    s16 object_type; // at 0x84
    s16 unk86;
    s16 unk88;
    s16 unk8A;
    u8 unk8C; // bitfield, collectable state (u8)
    u8 unk8D;
    u8 unk8E;
    u8 unk8F;
} Prop;

typedef struct chunk_14 Chunk14;

struct chunk_14 {
    PropModel *unk0;
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
    s32 id;
    u8 images_per_frame_horizontal;
    u8 images_per_frame_vertical;
    u8 unk6;
    u8 codec;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 table;
    s16 width;
    s16 height;
    s16 image_count;
    s16 images[1]; // TODO: How many elements? m2c doesn't support VLAs
} SpriteData;

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
    void *unk2C;
    void *unk30;
} Struct8073BC74;

typedef struct Struct8073BC74_auxbus_unk20_unk4_unk20 {
    u8 pad0[2];
    s16 unk2;
    u8 pad4[8 - 4];
    void *unk8;
    u8 padC[0x28 - 0xC];
    s32 unk28;
    void *unk2C[1]; // TODO: How many elements? m2c doesn't support VLAs
} Struct8073BC74_auxbus_unk20_unk4_unk20;

typedef struct Struct8073BC74_auxbus_unk20_unk4 {
    u8 pad0[0x10];
    f32 unk10;
    f32 unk14;
    u8 unk18[4];
    f32 unk1C;
    Struct8073BC74_auxbus_unk20_unk4_unk20 * unk20;
    u8 unk24[0x28 - 0x24];
} Struct8073BC74_auxbus_unk20_unk4;

typedef struct Struct8073BC74_auxbus_unk20 {
    s32 unk0;
    Struct8073BC74_auxbus_unk20_unk4 *unk4;
    u8 pad8[0x20 - 0x8];
    s16 *unk20[1]; // TODO: How many elements? m2c doesn't support VLAs
} Struct8073BC74_auxbus_unk20;

typedef struct Struct8073BC74_auxbus_unk1C Struct8073BC74_auxbus_unk1C; 

struct Struct8073BC74_auxbus_unk1C {
    u8 pad0[8];
    Struct8073BC74_auxbus_unk1C *next;
    u8 unkC[0x18 - 0xC];
    s16 unk18;
    u8 pad1A[0x8C - 0x1A];
    u8 unk8C;
};

typedef struct Struct8073BC74_auxbus {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[4];
    Struct8073BC74_auxbus_unk1C *unk1C;
    Struct8073BC74_auxbus_unk20 *unk20;
    s32 unk24;
    u8 pad28[0x44 - 0x28];
    Struct8073BC74 * unk44;
} Struct8073BC74_auxbus;

typedef struct {
    u8 unk0[0x48 - 0x0];
    s32 unk48;
    f32 unk4C;
    s32 unk50;
    s32 unk54;
    s16 unk58;
    s16 unk5A;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 *unk80;
    s32 unk84;
    s32 unk88;
} Struct8073F1E4;

typedef struct Struct8073F1E4_container {
    u8 pad0[8];
    Struct8073F1E4* unk8;
} Struct8073F1E4_container;

typedef Acmd *(*CommandHandler)(s32, Acmd *, s32);

typedef struct N_ALMAinBus_s {
    ALFilter *source;
    CommandHandler handler;
} N_ALMAinBus;

typedef struct SoundState SoundState;

struct sndstate {
	/*0x00*/ ALLink node;
	/*0x08*/ ALSound *sound;
	/*0x0c*/ N_ALVoice voice;
	/*0x28*/ f32 basepitch;
	/*0x2c*/ f32 pitch;
	/*0x30*/ struct sndstate **unk30;
	/*0x34*/ s32 unk34;
	/*0x38*/ s16 vol;
	/*0x3a*/ s16 envvol;
	/*0x3c*/ ALMicroTime endtime;
	/*0x40*/ u8 priority;
	/*0x41*/ ALPan pan;
	/*0x42*/ u8 fxmix;
	/*0x43*/ u8 flags;
	/*0x44*/ u8 state;
	/*0x45*/ u8 fxbus;
	/*0x46*/ u16 soundnum;
};

struct SoundState {
    ALLink node;
    ALSound *sound;
    ALVoice voice;
    f32 unk28;
    f32 pitch;
    SoundState **unk30;
    s32 unk34;
    s16 volume;
    u8 pad3A[0x40 - 0x3A];
    u8 priority;
    u8 pan;
    u8 unk42;
    u8 status;
    u8 playState;
    u8 pad45[0x48-0x45];
};

typedef struct CustomResampler {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    void* unk14;
    f32 unk18;
    s32 unk1C;
    f32 unk20;
    s32 unk24;
    void* unk28;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
} CustomResampler;

typedef struct CustomPVoice_unk70 {
    u8 pad0[0xB8];
} CustomPVoice_unk70;

typedef struct CustomPVoice_unk7C_unkC {
    u8 pad0[0x88];
    s32 unk88;
} CustomPVoice_unk7C_unkC;

typedef struct CustomPVoice_unk7C CustomPVoice_unk7C;
struct CustomPVoice_unk7C {
    CustomPVoice_unk7C *unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    union {
        struct {
            s16 unkC;
            s16 unkE;
        };
        CustomPVoice_unk7C_unkC *unkC_ptr;
        f32 unkC_f32;
        s32 unkC_s32;
    };
    union {
        struct {
            s16 unk10;
            u8 unk12;
            u8 unk13;
        };
        s32 unk10_s32;
    };
    u8 unk14;
    u8 unk15;
    u8 pad16[0x18 - 0x16];
    f32 unk18;
    s32 unk1C;
    void *unk20;
};

typedef struct CustomPVoice_unk20_unkC {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} CustomPVoice_unk20_unkC;

typedef struct CustomPVoice_unk20_unk10 {
    s32 unk0;
    s32 unk4;
} CustomPVoice_unk20_unk10;

typedef struct CustomPVoice_unk20 {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 pad9[0xC - 0x9];
    CustomPVoice_unk20_unkC *unkC;
    union {
        CustomPVoice_unk20_unk10 *unk10;
        s32 unk10_s32;
    };
} CustomPVoice_unk20;

typedef s32   (*CustomPVoice_unk28)(s32, s32, CustomResampler *);

typedef struct CustomPVoice {
    ALLink node;
    ALVoice *vvoice;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    CustomPVoice_unk20 *unk20;
    s32 unk24;
    CustomPVoice_unk28 unk28;
    CustomResampler resampler;
    s16 unk60;
    s16 unk62;
    u16 unk64;
    s16 unk66;
    s16 unk68;
    u16 unk6A;
    s16 unk6C;
    s16 unk6E;
    union {
        CustomPVoice_unk70 *unk70;
        s32 unk70_s32;
    };
    s32 unk74;
    s32 unk78;
    CustomPVoice_unk7C *unk7C;
    s32 *unk80;
    s32 unk84;
    s32 unk88;
    u8 unk8C;
    u8 pad8D[0x90 - 0x8D];
    s16 unk90;
    s16 unk92;
    u8 pad94[0x98 - 0x94];
    s32 unk98;
    u8 pad9C[0xB8 - 0x9C];
    s32 unkB8;
    s32 unkBC;
} CustomPVoice;

typedef struct {
    u8 pad0[0x2 - 0x0];
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
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

typedef union rgba {
    struct {
        u8 red;
        u8 green;
        u8 blue;
        u8 alpha;
    };
    u8 as_array[4];
} rgba;

typedef struct {
    s32 posX;
    s32 posY;
    s32 frame_counter;
    rgba color;
} ExplosionSpriteState;

// These bounds are in "local space", but for static objects they seem to be absolute
typedef struct JetpacSpawningInfoSub {
    s32 left; // 0x1C
    s32 top; // 0x20
    s32 right; // 0x24
    s32 bottom; // 0x28
    s32 counter; // 0x2C
} JetpacSpawningInfoSub;

typedef enum JetpacEntityState
{
    JETPAC_ENTITY_STATE_DEAD = 0,
    JETPAC_ENTITY_STATE_ALLOCATED = 2, // Not used except for >= check
    JETPAC_ENTITY_STATE_ACTIVE = 3,
    JETPAC_ENTITY_STATE_DYING = 4
} JetpacEntityState;

typedef struct JetpacSpatialState {
    f32 posX; // 0x0
    f32 posY; // 0x4
    f32 velX; // 0x8
    f32 velY; // 0xC
    rgba color; // 0x10
    JetpacEntityState entity_state; // 0x14
    s32 is_facing_left; // 0x18
    JetpacSpawningInfoSub unk1C;
} JetpacSpatialState;

typedef struct JetpacStructSub0 {
    JetpacSpatialState spatial_state;
    ExplosionSpriteState explosion_sprite;
    u32 counter_limit;
    s32 score_value;
} JetpacStructSub0;

typedef struct JetpacStructSub1 {
    void (*unk0)();
    void *unk4;
} JetpacStructSub1;

typedef struct JetpacStruct {
    JetpacStructSub0 unk0;
    JetpacStructSub1 unk48;
} JetpacStruct;

typedef struct {
    s32 x;
    s32 y;
    s32 horizontal_flip;
    uSprite *draw_sprite;
} JetpacRenderingCellEntry;

typedef struct {
    JetpacRenderingCellEntry entries[6];
    s32 num_entries;
    rgba hue;
} JetpacRenderingCell;

typedef struct {
    JetpacSpatialState spatial_state;
    s32 is_flying;
    s32 ground_platform_index;
    s32 laser_delay_counter;
    ExplosionSpriteState explosion_sprite;
    JetpacStruct lasers[4];
} JetpacPlayerStruct;

typedef struct JetpacPickupStruct JetpacPickupStruct;

typedef struct JetpacPickupPrimary {
    uSprite *sprite[2];
    f32 posX;
    f32 posY;
    f32 velX;
    f32 velY;
    rgba color;
    s32 unk1C;
    s32 unk20;
    JetpacSpawningInfoSub unk24;
    s32 unk38;
    s32 point_bonus;
    s32 drop_type;
    void (*unk44)(JetpacPickupStruct*);
} JetpacPickupPrimary;

struct JetpacPickupStruct {
    JetpacPickupPrimary primary_info;
    void (*code)(JetpacPickupStruct*, s32);
};

typedef struct Competitor {
    s32 level;
    s32 current_score;
    s32 lives;
    s32 rocket_stage;
    s32 unk10; //used
    JetpacPickupStruct rocket_segments[3];
    JetpacPickupStruct fuel_item;
    s32 bonus_item_counter_limit;
    JetpacPickupStruct next_bonus_item;
    //u8 unk_190[4];
} Competitor;

typedef struct Struct8002EF80 {
    JetpacSpatialState spatial_state;
    s32 unk30;
} JetpacGroundPlatform;

typedef struct JetpacGameStruct {
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
    JetpacGroundPlatform platforms[4];
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
} JetpacGameStruct;

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
    s16 unkC;
    u8 unkE;
    u8 unkF;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
} Struct8075EB80;

extern Struct8075EB80 D_global_asm_8075EB80[];

// TODO: Use that clever tuple thing from BKomp
typedef struct {
    s16 coords_0[3]; // 0x0
    s16 coords_1[3]; // 0x6
    s16 coords_2[3]; // 0xC
    s16 coords_3[3]; // 0x12
    s16 coords_4[3]; // 0x18
} EnemyAggressionBox;

typedef struct EnemyMovementBox EnemyMovementBox;

struct EnemyMovementBox {
    s16 x_pos_0; // 0x0
    s16 z_pos_0; // 0x2
    s16 x_pos_1; // 0x4
    s16 z_pos_1; // 0x6
    u8 pad[4];
    EnemyAggressionBox *aggression_box_pointer; // = 0xC, -- u32
    u8 pad10[0xC];
    Actor *unk1C;
};

typedef struct SpawnerFileData {
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
} SpawnerFileData;

typedef struct SpawnerData_unk20 {
    u8 unk0;
    u8 unk1;
} SpawnerData_unk20;

typedef struct {
	SpawnerFileData init;
    u8 unk16;
    u8 unk17;
    Actor *tied_actor; // 0x18
	EnemyMovementBox *movement_box_pointer; // 0x1C
	SpawnerData_unk20 *unk20; // 0x20
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

typedef struct Fence6Struct {
    s16 x;
    s16 y;
    s16 z;
} Fence6Struct;

typedef struct FenceAStruct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
} FenceAStruct;

typedef struct FenceStruct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 padA[2];
    Fence6Struct *unkC;
    s16 unk10;
    u8 pad12[2];
    FenceAStruct *unk14;
    s8 unk18;
    s8 unk19;
    u8 pad1A[0x24 - 0x1A];
} FenceStruct;

typedef struct FenceDataStruct {
    s16 count;
    FenceStruct *data;
} FenceDataStruct;

typedef struct SpawnerDataStruct {
    s16 count;
    EnemySpawner *data;
} SpawnerDataStruct;

typedef struct Struct807FDC90 Struct807FDC90;

// Use this for D_global_asm_807FDC90
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
    union {
        struct {
            u16 unk1C; // Used
            u8 unk1E;
            u8 unk1F;
        };
        s32 unk1C_s32;
    };
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
    tuple_s pos;
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
    f32 unk0;
    tuple_f unk4;
    tuple_f unk10;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
} Struct80717D84_unk384_807186C8;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s32 unk14;
    u8 pad18[0x1C - 0x18];
} Struct80717D84_unk384_8071910C;

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80717D84_unk384_807195D4;

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80717D84_unk384_807197B4;

typedef struct otherSpriteControl_unk330 {
    SpriteData *unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    s16 unkC;
    s16 unkE;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    s16 unk16;
    s32 unk18;
    void *unk1C;
    s16 *unk20;
    s32 unk24;
} otherSpriteControl_unk330;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct80717D84_unk384_8071CDE0;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Struct80717D84_unk384_8071C9E8_sub6;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    Struct80717D84_unk384_8071C9E8_sub6 unk6;
    s16 unkC;
} Struct80717D84_unk384_8071C9E8;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80717D84_unk384_8071ABDC;

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} Struct80717D84_unk384_80718BF4;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80717D84_unk384_80717404;

typedef union {
    struct {
        s16 unk0;
        s16 unk2;
    } s16arr;
    s32 s32v;
    Actor *actor;
} otherSpriteControl_unk35C;

struct otherSpriteControl {
	/* 0x000 */ s8 unk_000[0x28];
	/* 0x028 */ Vtx unk28[0x10]; // Unsure on size
    /* 0x128 */ Mtx unk128[2];
    /* 0x1A8 */ u8 unk1A8[0x32C - 0x1A8];
    /* 0x32C */ s8 unk32C;
    /* 0x32D */ u8 pad32D[0x330 - 0x32D];
    /* 0x330 */ otherSpriteControl_unk330 *unk330;
    /* 0x334 */ u8 pad334[0x338 - 0x334];
    /* 0x338 */ Actor *unk338;
    /* 0x33C */ u8 pad33C[0x340 - 0x33C];
	/* 0x340 */ f32 xPos;
	/* 0x344 */ f32 yPos;
	/* 0x348 */ f32 zPos;
    /* 0x34C */ s8 unk_34C[2];
    /* 0x34E */ s16 unk34E;
	/* 0x350 */ u8 gif_update_frequency;
    /* 0x351 */ u8 unk351;
	/* 0x352 */ u8 pad352[0x2];
    /* 0x354 */ s32 unk354;
    /* 0x358 */ s32 unk358;
    /* 0x35C */ union {
        s32 unk35C;
        Actor *unk35C_actor;
        s16 unk35C_s16[2];
    };
	/* 0x360 */ f32 xScale;
	/* 0x364 */ f32 yScale;
	/* 0x368 */ s8 unk_368[0x2];
	/* 0x36A */ s8 transparency1;
	/* 0x36B */ s8 transparency2;
	/* 0x36C */ s8 transparency3;
	/* 0x36D */ u8 transparency4;
	/* 0x36E */ s8 unk36E;
    /* 0x36F */ u8 unk36F;
    /* 0x370 */ s8 unk_36E[0x384-0x370];
    union {
        void* some_pointer;
        Struct80717D84_unk384 *unk384;
        Struct80717D84_unk384_s16 *unk384_s16;
        Struct80717D84_unk384_f32 *unk384_f32;
        tuple_f *unk384_tuplef;
        Struct80717D84_unk384_80717814 *unk384_80717814;
        Struct80717D84_unk384_80717100 *unk384_80717100;
        Struct80717D84_unk384_8071720C *unk384_8071720C;
        Struct80717D84_unk384_80717B64 *unk384_80717B64;
        Struct80717D84_unk384_8071DC90 *unk384_8071DC90;
        Struct80717D84_unk384_8071E110 *unk384_8071E110;
        Struct80717D84_unk384_8071F444 *unk384_8071F444;
        Struct80717D84_unk384_80717930 *unk384_80717930;
        Struct80717D84_unk384_807189BC *unk384_807189BC;
        Struct80717D84_unk384_80719C00 *unk384_80719C00;
        Struct80717D84_unk384_80719EF4 *unk384_80719EF4;
        Struct80717D84_unk384_8071D0F0 *unk384_8071D0F0;
        Struct80717D84_unk384_8071B2EC *unk384_8071B2EC;
        Struct80717D84_unk384_807186C8 *unk384_807186C8;
        Struct80717D84_unk384_8071910C *unk384_8071910C;
        Struct80717D84_unk384_807195D4 *unk384_807195D4;
        Struct80717D84_unk384_807197B4 *unk384_807197B4;
        Struct80717D84_unk384_8071CDE0 *unk384_8071CDE0;
        Struct80717D84_unk384_8071C9E8 *unk384_8071C9E8;
        Struct80717D84_unk384_8071ABDC *unk384_8071ABDC;
        Struct80717D84_unk384_80718BF4 *unk384_80718BF4;
        Struct80717D84_unk384_80717404 *unk384_80717404;
    };
	/* 0x384 */ 
};

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
    s32 unk0;
    u8 unk4[0x16 - 0x4];
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
        u8 unk35C_arr[4];
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
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s16 unk4C;
    u8 unk4E;
    u8 unk4F;
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
    s32 unkD8;
    s32 unkDC;
    s32 unkE0;
    s32 unkE4;
    s32 unkE8;
    s32 unkEC;
    s32 unkF0;
    s32 unkF4;
    s32 unkF8;
    s32 unkFC;
    s32 unk100;
    s32 unk104;
    s32 unk108;
    s32 unk10C;
    s32 unk110;
    s32 unk114;
    s32 unk118;
    s32 unk11C;
    s32 unk120;
    s32 unk124;
    s32 unk128;
    s16 unk12C;
} Struct80652374_arg0_unk0;

typedef struct {
    Struct80652374_arg0_unk0 *unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    u8 unk22;
    u8 unk23;
    u8 unk24;
} Struct80652374_arg0;

typedef struct Struct131B0_1 Struct131B0_1;

struct Struct131B0_1 {
    Struct131B0_1 *next;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Struct131B0_2_unk268;

// P Sure this is OSScTask_s
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    OSTask unk10;
} Struct131B0_2_unk274;

typedef struct {
    u8  pad0[0x260 - 0x0];
    Struct131B0_1 *unk260;
    s32 unk264;
    Struct131B0_2_unk268 * unk268;
    Struct131B0_1 *unk26C;
    Struct131B0_1 *unk270;
    Struct131B0_2_unk274 *unk274;
    u8 pad278[0x290 - 0x278];
    OSTime unk290;

} Struct131B0_2;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    u8 unk18;
    u8 unk19;
    u16 unk1A;
    u32 unk1C;
    f64 unk20;
    f64 unk28;
    f64 unk30;
    f64 unk38;
} GlobalASMStruct64;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s8 unk18;
    s8 unk19;
    s8 unk1A;
    s8 unk1B;
} Struct807FDCC0_unk34;

typedef struct Struct807FDCC0 Struct807FDCC0;

struct Struct807FDCC0 {
    Actor *unk0; // Used
    u8 unk4; // Used
    u8 unk5;
    u8 unk6;
    u8 unk7;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    f32 unk14;
    u8 unk18;
    s8 unk19;
    s8 unk1A;
    s8 unk1B;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    s8 unk30;
    u8 unk31;
    s8 unk32;
    s8 unk33;
    Struct807FDCC0_unk34 *unk34;
    Struct807FDCC0 *next;
};

extern Struct807FDCC0 *D_global_asm_807FDCC0;

typedef struct global_asm_struct_71 GlobalASMStruct71;

struct global_asm_struct_71 {
    s32 unk0;
    s32 unk4;
    s32 unk8; // Used
    s32 unkC;
    s16 unk10;
    s16 unk12;
    GlobalASMStruct71 *unk14; // Used, prev?
    GlobalASMStruct71 *unk18; // Next?
};

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8; // Used
    s32 unkC;
    s16 unk10;
    s16 unk12;
    GlobalASMStruct71 *unk14; // Used, prev?
    GlobalASMStruct71 *unk18; // Next?
} GS71_F32;

typedef struct HUDDisplay {
	/* 0x000 */ u16* actual_count_pointer;
	/* 0x004 */	u16 hud_count;
	/* 0x006 */	u8 freeze_timer;
	/* 0x007 */	u8 counter_timer;
	/* 0x008 */	s32 screen_x;
	/* 0x00C */	s32 screen_y;
	/* 0x010 */ f32 unk_10;
    /* 0x014 */ f32 unk_14;
    /* 0x018 */ f32 unk_18;
    /* 0x01C */ u8 unk_1c;
    /* 0x01D */ u8 unk_1d;
    /* 0x01E */ u8 unk_1e;
    /* 0x01F */ u8 unk_1f;
	/* 0x020 */ u32 hud_state; // 0 = invisible, 1 = appearing, 2 = visible, 3 = disappearing
	/* 0x024 */ s32 unk_24;
	/* 0x028 */	GlobalASMStruct71* counter_pointer;
	/* 0x02C */ u8 unk_2c; // Infinites?
    /* 0x02D */ u8 unk_2d; // Infinites?
    /* 0x02E */ u8 unk_2e;
    /* 0x02F */ u8 unk_2f;
} HUDDisplay;

typedef struct {
    // TODO: Union with friendly field names?
    // TODO: Enum with indexes?
    // 0 = Coloured Banana
    // 1 = Banana Coin
    // 2 = ???
    // 3 = ???
    // 4 = ???
    // 5 = Crystal Coconut
    // 6 = ???
    // 7 = ???
    // 8 = GB Count (Character)
    // 9 = ???
    // 10 = Banana Medal
    // 11 = ???
    // 12 = Blueprint
    // 13 = Coloured Banana?
    // 14 = Banana Coin?
    HUDDisplay hud_item[15];
} PlayerHUD;

typedef struct Struct80754AD0 Struct80754AD0;

typedef struct {
    u8 width;
    u8 file_count;
    u8 height;
    u8 kerning_space;
    u8 kerning_character;
    u8 kerning_animation;
} Struct80754A34;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
} Struct806FD9FC;

struct Struct80754AD0 {
    Struct80754AD0 *next;
    u8 *unk4;
    Struct806FD9FC *unk8;
    u8 unkC;
    u8 unkD;
    u8 padE[0x10 - 0x0E];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    s16 unk1C;
};
extern Struct80754AD0 *D_global_asm_80754AD0;

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    f32 unk4;
    f32 unk8;
} RaceStruct3;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    union {
        struct {
            s16 unk4;
            s16 unk6;
            s16 unk8;
            s16 unkA;
        };
        s16 unk4_arr[4];
    };
} Struct80750948;

typedef struct Struct800246EC_unk20 {
    u8 pad0[0x4];
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Struct800246EC_unk20;

typedef struct Struct800246EC {
    u8 pad0[0x20];
    Struct800246EC_unk20 *unk20[4];
    u8 unk30[0x44 - 0x30];
    s32 unk44;
    s32 unk48;
} Struct800246EC;

typedef struct rgb {
    u8 red;
    u8 green;
    u8 blue;
} rgb;

typedef struct global_asm_struct_1 {
    u8 unk0; // inSubmap?
    u8 unk1;
    s16 unk2;
    f32 xPosition; // X Position
    f32 yPosition; // Y Position
    f32 zPosition; // Z Position
    s16 yRotation; // Y Rotation
    s16 unk12; // Map
    u8 unk14; // Used
    u8 unk15;
    s16 unk16;
    void *unk18;
    s32 unk1C;
    void *unk20; // Used
    rgb chunk_rgb[52];
} Struct8076A160; // Size 0xC0

typedef struct dk64_boot_struct_0 {
    u8 *unk0;
    u8 *unk4;
    u8 pad8[0x10];
} dk64_boot_struct_0;

typedef struct UnkMQStruct {
    OSMesgQueue mq;
    OSMesg msgs[1];
} UnkMQStruct;

typedef struct {
    s32 unk0;
    s32 unk4;
    AnimationStateUnk0_0 *unk8;
} Struct807FB7B0;

typedef struct {
    OSTime unk0;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
} Struct80755340;

typedef struct {
    u16 unk0;
    u16 unk2;
    s32 *unk4;
    u8 unk8;
} Struct807FB630;

typedef struct Struct80630B70 Struct80630B70;
struct Struct80630B70 {
    Actor *unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    u8 pad10[0x14-0x10];
    Struct80630B70 *unk14;
    u8 pad18[0x24 - 0x18];
    u8 unk24;
};

typedef struct Struct80614C38_0 Struct80614C38;
struct Struct80614C38_0 {
    void *unk0;
    void *unk4;
    u8 unk8;
    u8 pad9[0xC - 0x9];
    Struct80614C38 *unkC;
    u8 pad10[0x14 - 0x10];
    Struct80614C38 *next;
};

typedef struct ActorModelHeader {
    s32 unk0;
    union {
        s32 *unk4;
        s32 unk4_raw;
    };
    s32 unk8;
    s32 unkC;
    s32 unk10;
    Struct80614C38 * unk14;
    u8 pad18[0x20 - 0x18];
    u8 bone_count;
    u8 unk21;
    u8 pad22[0x28 - 0x22];
} ActorModelHeader;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
} Struct8066AC10;

#endif
