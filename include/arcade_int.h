#ifndef ARCADE_INTERNAL_H
#define ARCADE_INTERNAL_H

#include <ultra64.h>
#include "functions.h"

enum ARCADE_OBJ_E {
    ARCADE_OBJ_01_BARREL = 1,
    ARCADE_OBJ_02_FLAME_ENEMY,
    ARCADE_OBJ_03_SPRING,
    ARCADE_OBJ_04_PIE,
    ARCADE_OBJ_05_BONUS_ITEM,
    ARCADE_OBJ_06_HAMMER,
    ARCADE_OBJ_07_HAMMER_PARTICLES,
    ARCADE_OBJ_08_DK_HOW_HIGH,
    ARCADE_OBJ_09_NAME_SELECT_CURSOR,
    ARCADE_OBJ_0A_BARREL_STACK,
    ARCADE_OBJ_0B_RIVET,
    ARCADE_OBJ_0C_MOVING_LADDER,
    ARCADE_OBJ_0D_JUMPMAN,
    ARCADE_OBJ_0E_BONUS_OSD,
    ARCADE_OBJ_0F_100M_COMPLETE_PARTICLE,
    ARCADE_OBJ_10_OIL_DRUM,
    ARCADE_OBJ_11_ELEVATOR_CRANK,
    ARCADE_OBJ_12_PULLEY,
    ARCADE_OBJ_13_OIL_DRUM_FLAMES,
    ARCADE_OBJ_14_POINTS_TEXT,
    ARCADE_OBJ_15_DK_TITLE,
    ARCADE_OBJ_16_DK_25M,
    ARCADE_OBJ_17_DK_100M,
    ARCADE_OBJ_18_DK_75M,
    ARCADE_OBJ_19_DK_50M,
    ARCADE_OBJ_1A_PAULINE_BOTTOM,
    ARCADE_OBJ_1B_PAULINE_TOP,
    //ARCADE_OBJ_1C
    ARCADE_OBJ_1D_HELP_TEXT = 0x1D,
    ARCADE_OBJ_1E_NINTENDO_COIN
};

typedef struct {
    uSprite sprite[2]; //array size unknown
    u8 pad30[0x750];
} ArcadeStruct3; //size(0x780)

typedef struct arcade_struct_1 {
    f32 x_position; // x position at 0x0
    f32 y_position; // y position at 0x4
    f32 x_velocity; // x velocity at 0x8
    f32 y_velocity; // y velocity at 0xC
    union {
        f32 unk10; // lifetime?
        s32 unk10_s32;
    };
    void *sprite; // imageDataPointer
    u8 object_type; // object_type
    u8 unk19; // state?
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E; // height
    u8 unk1F; // width
} ArcadeStruct1;

typedef struct {
    u16 r:5;
    u16 g:5;
    u16 b:5;
    u16 a:1;
} rgba5551;

typedef struct {
    u8 pad0[0xC];
} ArcadeStruct4;

void func_arcade_8002549C(void);
void func_arcade_80024D90(void);
void func_arcade_800259D0(Gfx **arg0);
void func_arcade_80026680(Gfx **arg0);
void func_arcade_800268AC(Gfx **arg0);
void func_arcade_80029968(void);
s32  func_arcade_80029ACC(s32 arg0, s32 arg1);
s32 func_arcade_80029CD0(s32 arg0, s32 arg1);
s32 func_arcade_80029EFC(s32 arg0, s32 arg1);
s32 func_arcade_8002A264(s32 arg0, s32 arg1);
s32  func_arcade_8002A408(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void func_arcade_8002B2C0(Gfx **arg0);

void func_arcade_800303B8(u8);
void func_arcade_80030734(u8);
void arcade_rivet_update(u8);
void func_arcade_80030A04(u8);
void func_arcade_80030CEC(u8);
void arcade_pie_update(u8);

void func_arcade_80030FEC(void);
void func_arcade_800313B8(void);

/*.rodata 0x8004A840*/
extern u8  D_arcade_8004A934;
extern u8  D_arcade_8004A944;
extern u8  D_arcade_8004A954;
extern u8  D_arcade_8004A95C;
extern u8  D_arcade_8004A974;
extern u8  D_arcade_8004A97C;
extern u8  D_arcade_8004A984;
extern u8  D_arcade_8004A98C;
extern u8  D_arcade_8004A994;
extern u8  D_arcade_8004A9A0;
extern u8  D_arcade_8004A9B0;
extern u8  D_arcade_8004A9BC;
extern u8  D_arcade_8004A9D0;
extern u8  D_arcade_8004A9DC;
/*jmp_tbl D_arcade_8004A9EC[6]*/

extern f32 D_arcade_8004AA18; // 1170.2857666
extern f64 D_arcade_8004AA98;
extern f64 D_arcade_8004AAA0;
extern f64 D_arcade_8004AAA8;
extern f64 D_arcade_8004AAB0;
extern f32 D_arcade_8004AB24;
extern f64 D_arcade_8004AB28;
extern f64 D_arcade_8004AB30;
extern f32 D_arcade_8004AB38;

extern f32 D_arcade_8004AB78;
extern f32 D_arcade_8004AB7C;

/* .bss 0x804AC00 */
extern ArcadeStruct3 D_arcade_8004AC00[];
extern uSprite D_arcade_8004BB00[2];
extern uSprite D_arcade_8004BB30[2];
extern uSprite D_arcade_8004BB60[2];
extern uSprite D_arcade_8004BB90[2];
extern uSprite D_arcade_8004BBC0[2];
extern uSprite D_arcade_8004BBF0[];
extern f32 D_arcade_8004BC88[6][3];
extern ArcadeStruct1 arcade_objects[0x50];
extern void *D_arcade_8004C6D0;
extern s32 D_arcade_8004C6D4;
extern s16 D_arcade_8004C6D6;
extern s32 D_arcade_8004C6D8;
extern s32 D_arcade_8004C6DC; // arcade_internal_timer
extern s32 D_arcade_8004C6E0;
extern s32 D_arcade_8004C6E4;
extern s32 D_arcade_8004C6EC;
extern s32 D_arcade_8004C6E8;
extern s32 D_arcade_8004C6F0;
extern s32 D_arcade_8004C6F4;
extern s32 D_arcade_8004C6F8;
extern s32 D_arcade_8004C6FC;
extern s32 D_arcade_8004C704;
extern s32 D_arcade_8004C708;
extern s32 D_arcade_8004C70C;
extern s32 arcade_hammer_timer;
extern s32 arcade_next_sfx; //0x8004C714
extern u8  arcade_rivet_bitfield;
extern u8  D_arcade_8004C719;
extern u8  D_arcade_8004C71A;
extern u8  arcade_lives_internal; //0x8004C71B
extern u8  arcade_lives_visual;   //0x8004C71C
extern u8  arcade_game_state; //0x8004C71D
extern s8  arcade_bonus_timer;
extern u8  arcade_jumpman_slot; // Index into arcade_objects[], arcade_jumpman_slot?
extern u8  D_arcade_8004C720;
extern u8 D_arcade_8004C721;
extern u8  arcade_background_visual; //0x8004C722
extern u8  D_arcade_8004C723;
extern u8  D_arcade_8004C724;
extern u8 arcade_text_red;
extern u8 arcade_text_green;
extern u8 arcade_text_blue;
extern u8 arcade_text_alpha;
extern s32 arcade_text_x;
extern s32 arcade_text_y;

/* global_asm */
extern u8  D_global_asm_807444FC;
extern s32 D_global_asm_8076A048;
extern void *D_global_asm_8076A080;
extern s32 D_global_asm_8076A088;
extern s32 D_global_asm_8076A08C;
extern u8  D_global_asm_8076A0B1;
extern u8  D_global_asm_80767CE8;
extern f32 D_global_asm_807FD888;
extern u32 D_global_asm_8076D1F8; // ??
extern s32 D_global_asm_80770DF8;
extern GlobalASMStruct17 *D_global_asm_807ECDE8;
extern u8 *D_global_asm_80746800;
#endif /* ARCADE_INTERNAL_H */
