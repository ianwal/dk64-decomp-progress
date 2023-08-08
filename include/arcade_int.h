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
    s32 *unk14; // imageDataPointer
    u8 unk18; // object_type
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

void func_global_asm_8060DEA8(void);
void func_global_asm_80737638(void * arg0, enum sfx_e arg1, u32 arg2 , u32 arg3, f32 arg4, u32 arg5, u32 arg6);

/* rom */
extern Gfx **D_1000040;
extern Gfx **D_1000090;

/*.data */ //0x8032220 = 0xE220
extern u8 D_arcade_80032228; // imageData
extern u8 D_arcade_80032470; // imageData
extern u8 D_arcade_800326B8; // imageData
extern u8 D_arcade_80032900; // imageData
// these are likely the same struct
extern u8  D_arcade_80032B48;
extern u8  D_arcade_80032B90;
extern u8  D_arcade_80032BD8;
extern u8  D_arcade_80032C20;
extern u8  D_arcade_80032DF8;
extern u8  D_arcade_80032E80; // imageData
extern u8  D_arcade_80032F68; // imageData
extern u8  D_arcade_800335D8;
extern u8  D_arcade_80033C48;
extern u8  D_arcade_80034360; // imageData
extern u8  D_arcade_80034568;
extern u8  D_arcade_80034610; // imageData //barrel
extern u8 D_arcade_80034818[];
extern u8 D_arcade_80034A20[];
extern u8 D_arcade_80034C28[];
extern u8 D_arcade_80034E30[];
extern u8 D_arcade_80035038[];
extern u8 D_arcade_80035240[];
extern u8 D_arcade_80035448[];
extern u8 D_arcade_80035650[];
extern u8 D_arcade_80035898[];
extern u8 D_arcade_80035AE0[];
extern u8 D_arcade_80035CE8[];
extern u8  D_arcade_80037130; // imageData
extern u8  D_arcade_80037338; // imageData
extern u8  D_arcade_80037580; // imageData
extern s32 D_arcade_80037B98; // sprite?
extern s32 D_arcade_80037DA0; // sprite?
extern s32 D_arcade_80037FA8; // sprite?
extern u8  D_arcade_800381B0; // imageData
extern s32 D_arcade_800383B8; // sprite?
extern s32 D_arcade_800385C0; // sprite?
extern s32 D_arcade_800387C8; // sprite?
extern u8 D_arcade_80038BD8[];
extern u8  D_arcade_80038DE0; // imageData
extern u8  D_arcade_80038FE8;
extern u8  D_arcade_800391F0;
extern u8  D_arcade_800393F8; // imageData
extern u8  D_arcade_80039640;
extern u8  D_arcade_80039888;
extern u8  D_arcade_800389D0;
extern u8  D_arcade_80039AD0;
extern s32 D_arcade_80039D18; // sprite
extern s32 D_arcade_80039F60; // sprite
extern s32 D_arcade_8003A1A8; // sprite
extern s32 D_arcade_8003A3F0; // sprite
extern u8  D_arcade_8003A638; // imageData
extern u8  D_arcade_8003A840; // imageData
extern u8  D_arcade_8003AA48; // imageData
extern u8  D_arcade_8003AC50; // imageData
extern u8  D_arcade_8003AE58; // nintendo coin sprite
extern u8 D_arcade_8003B180[];
extern rgba5551 D_arcade_8003DA90[8][8]; // image data
extern u8  D_arcade_8003DB18;
extern u8 D_arcade_8003DD60;
extern u8 D_arcade_8003E438;
extern u8 D_arcade_8003E680[];
extern u8 D_arcade_8003E868[];
extern u8 D_arcade_8003E9F0;
extern u8 D_arcade_8003F9B8; // imageData
extern s32 D_arcade_80040540; // sprite? // donkey kong sprite
extern s32 D_arcade_80041508;
extern s32 D_arcade_800424D0; // imageData
extern u8 D_arcade_80044460;
extern u8 D_arcade_80045428;

extern s32 D_arcade_80047C24; // reload_arcade_level
extern s32 D_arcade_8004A308[];
extern u8  D_arcade_8004A338[];
extern u8  D_arcade_8004A358[];
extern u8  D_arcade_8004A378[];

extern s32 D_arcade_8004A318[8];
extern ArcadeStruct1 arcade_jumpman_obj_template                ;//= {  96.0f, 247.0f, 0.0f,  0.0f, 0.0f,               NULL, ARCADE_OBJ_0D_JUMPMAN, 0, 3, 0, 0, 0, 0x10, 0x12};
extern ArcadeStruct1 arcade_barrel_obj_template                 ;//= {  64.0f,  79.0f, 1.0f,  0.0f, 0.0f, &D_arcade_80034610, ARCADE_OBJ_01_BARREL,  0, 0, 0, 0, 0, 0x10, 0x0F};
extern ArcadeStruct1 arcade_flame_enemy_obj_template            ;//= {  76.0f, 230.0f, 1.0f,  0.0f, 0.0f,               NULL, ARCADE_OBJ_02_FLAME_ENEMY, 2, 0, 0, 0, 0, 0x10, 0x11};
extern ArcadeStruct1 arcade_oil_drum_flame_obj_template         ;//= {  64.0f, 216.0f, 1.0f,  0.0f, 0.0f, &D_arcade_80032228, ARCADE_OBJ_13_OIL_DRUM_FLAMES, 2, 0, 0, 0, 0, 0x10, 0x10};
extern ArcadeStruct1 arcade_spring_obj_template                 ;//= { -24.0f,  81.0f, 2.0f, -3.5f, 0.0f,               NULL, ARCADE_OBJ_03_SPRING, 0, 0, 0, 0, 0, 0x10, 0x10};
extern ArcadeStruct1 arcade_bonus_osd_obj_template              ;//= { 219.0f,  38.0f, 2.0f, -3.5f, 0.0f, &D_arcade_80032F68, ARCADE_OBJ_0E_BONUS_OSD, 0, 0, 0, 0, 0, 0x2B, 0x13};
extern ArcadeStruct1 arcade_oil_drum_obj_template               ;//= {  64.0f, 231.0f, 0.0f,  0.0f, 0.0f, &D_arcade_80037338, ARCADE_OBJ_10_OIL_DRUM, 0, 0, 0, 0, 0, 0x10, 0x11};
extern ArcadeStruct1 arcade_elevator_obj_template               ;//= {  80.0f,  88.0f, 0.0f,  0.0f, 0.0f, &D_arcade_80037580, ARCADE_OBJ_11_ELEVATOR_CRANK, 0, 0, 0, 0, 0, 0x10, 0x10};
extern ArcadeStruct1 arcade_pulley_obj_template                 ;//= {  48.0f,  84.0f, 0.0f,  0.0f, 0.0f, &D_arcade_80037B98, ARCADE_OBJ_12_PULLEY, 0, 0, 0, 0, 0, 0x10, 0x10};
extern ArcadeStruct1 arcade_pauline_top_obj_template            ;//= { 136.0f,  26.0f, 0.0f,  0.0f, 0.0f,               NULL, ARCADE_OBJ_1B_PAULINE_TOP, 0, 0, 0, 0, 0, 0x10, 0x11};
extern ArcadeStruct1 arcade_pauline_bottom_obj_template         ;//= { 136.0f,  42.0f, 0.0f,  0.0f, 0.0f,               NULL, ARCADE_OBJ_1A_PAULINE_BOTTOM, 0, 0, 0, 0, 0, 0x10, 0x11};
extern ArcadeStruct1 arcade_nintendo_coin_obj_template          ;//= { 136.0f,  42.0f, 0.0f,  0.0f, 0.0f,               NULL, ARCADE_OBJ_1E_NINTENDO_COIN, 0, 0, 0, 0, 0, 0x14, 0x14};
extern ArcadeStruct1 arcade_help_text_obj_template              ;//= { 152.0f,  33.0f, 0.0f,  0.0f, 0.0f,               NULL, ARCADE_OBJ_1D_HELP_TEXT, 0, 0, 0, 0, 0, 0x18, 0x0A};
extern ArcadeStruct1 arcade_dk_title_obj_template               ;//= { 148.0f, 200.0f, 0.0f,  0.0f, 0.0f,               NULL, ARCADE_OBJ_15_DK_TITLE, 0, 0, 0, 0, 0, 0x30, 0x29};
extern ArcadeStruct1 arcade_dk_25m_obj_template                 ;//= {  68.0f,  38.0f, 0.0f,  0.0f, 0.0f, &D_arcade_80040540, ARCADE_OBJ_16_DK_25M, 0xC, 0, 0, 1, 0, 0x30, 0x29};
extern ArcadeStruct1 arcade_dk_100m_obj_template                ;//= { 136.0f,  53.0f, 0.0f,  0.0f, 0.0f, &D_arcade_80040540, ARCADE_OBJ_17_DK_100M, 2, 0, 0, 0, 0, 0x30, 0x29};
extern ArcadeStruct1 arcade_dk_75m_obj_template                 ;//= {  68.0f,  42.0f, 0.0f,  0.0f, 0.0f, &D_arcade_80040540, ARCADE_OBJ_18_DK_75M, 2, 0, 0, 0, 0, 0x30, 0x29};
extern ArcadeStruct1 arcade_dk_50m_obj_template                 ;//= {  68.0f,  42.0f, 1.0f,  0.0f, 0.0f, &D_arcade_80040540, ARCADE_OBJ_19_DK_50M, 2, 0, 0, 0, 0, 0x30, 0x29};
extern ArcadeStruct1 arcade_dk_how_high_obj_template            ;//= { 138.0f, 198.0f, 0.0f,  0.0f, 0.0f, &D_arcade_8003F9B8, ARCADE_OBJ_08_DK_HOW_HIGH, 0, 0, 0, 0, 0, 0x2E, 0x20};
extern ArcadeStruct1 arcade_points_text_obj_template            ;//= {   0.0f,   0.0f, 0.0f,  0.0f, 0.0f, &D_arcade_800381B0, ARCADE_OBJ_14_POINTS_TEXT, 0, 0, 0, 0, 0, 0x10, 0x10};
extern ArcadeStruct1 arcade_bonus_item_obj_template             ;//= { 180.0f, 247.0f, 0.0f,  0.0f, 0.0f, &D_arcade_80038DE0, ARCADE_OBJ_05_BONUS_ITEM, 0, 0, 0, 0, 0, 0x10, 0x10};
extern ArcadeStruct1 arcade_hammer_obj_template                 ;//= { 220.0f, 200.0f, 0.0f,  0.0f, 0.0f, &D_arcade_800393F8, ARCADE_OBJ_06_HAMMER, 0, 0, 0, 0, 0, 0x10, 0x10};
extern ArcadeStruct1 arcade_rivet_obj_template                  ;//= { 108.0f, 208.0f, 0.0f,  0.0f, 0.0f, &D_arcade_80032E80, ARCADE_OBJ_0B_RIVET, 0, 0, 0, 1, 0, 0x08, 0x09};
extern ArcadeStruct1 arcade_moving_ladder_obj_template          ;//= {  60.0f,  97.0f, 0.0f,  0.0f, 0.0f, &D_arcade_8003A638, ARCADE_OBJ_0C_MOVING_LADDER, 0, 0, 0, 0xF4, 0, 0x10, 0x10};
extern ArcadeStruct1 arcade_name_select_cursor_obj_template     ;//= {  60.0f,  97.0f, 0.0f,  0.0f, 0.0f, &D_arcade_8003A840, ARCADE_OBJ_09_NAME_SELECT_CURSOR, 0, 0, 0, 0, 0, 0x10, 0x10};
extern ArcadeStruct1 D_arcade_8004A6B8                          ;//= {  60.0f,  97.0f, 0.0f,  0.0f, 0.0f, &D_arcade_80034360, 0x1C, 0, 0, 0, 0, 0, 0x10, 0x10};
extern ArcadeStruct1 arcade_pie_obj_template                    ;//= {  60.0f, 207.0f, 0.0f,  0.0f, 0.0f, &D_arcade_8003AA48, ARCADE_OBJ_04_PIE, 0, 0, 0, 3, 0, 0x10, 0x10};
extern ArcadeStruct1 arcade_100m_complete_particle_obj_template ;//= { 160.0f, 214.0f, 0.0f,  0.0f, 0.0f, &D_arcade_8003AC50, ARCADE_OBJ_0F_100M_COMPLETE_PARTICLE, 0, 0, 0, 0, 0, 0x10, 0x10};
extern ArcadeStruct1 arcade_barrel_stack_obj_template           ;//= {  58.0f,  83.0f, 0.0f,  0.0f, 0.0f, &D_arcade_80037130, ARCADE_OBJ_0A_BARREL_STACK, 0, 0, 0, 0, 0, 0x10, 0x10};
extern u32 D_arcade_8004A738 ;//= 1; // rng
extern u8 D_arcade_8004A73C ;//= 0;
extern u8 D_arcade_8004A740 ;//= 0; // arcade_is_in_nintendo_coin_mode
extern u8 D_arcade_8004A744;
extern s32 arcade_current_score ;//= 3700; //0x8004A748
extern s32 arcade_saved_high_scores[5] ;/*= {
    7650, 6100, 5950, 5050, 4300
}; //0x8004A74C*/

extern s32 D_arcade_8004A760 ;//= 7650;
extern u8  D_arcade_8004A764 ;//= 0;
extern s8  D_arcade_8004A768 ;//= 0;
extern u8  D_arcade_8004A76C ;//= 0;
extern u8 D_arcade_8004A770 ;//= 0;
extern u8 D_arcade_8004A774[3] ;//= {' ',' ',' '};
extern u8 arcade_saved_high_score_initials[5][3] ;/*= {
    {' ',' ',' '},
    {' ',' ',' '},
    {' ',' ',' '},
    {' ',' ',' '},
    {' ',' ',' '}
}; //0x8004A778*/
extern u8 D_arcade_8004A788[4];
extern s32 D_arcade_8004A78C ;//= 1;
extern s32 D_arcade_8004A790 ;//= 0;
extern u8 D_arcade_8004A794 ;//= 0x20;
extern s32 D_arcade_8004A798[0xC];

extern u8 D_arcade_8004A81C[8][2]; // 50m rivet positions
extern u8 D_arcade_8004A82C[5][3] ;/*= {
    {'1','S','T'},
    {'2','N','D'},
    {'3','R','D'},
    {'4','T','H'},
    {'5','T','H'},
};*/
extern s32 D_arcade_8004A83C ;//= 0;

/*.rodata 0x8004A840*/
extern char D_arcade_8004A840[] ;//= "NAME %.3s";
extern char D_arcade_8004A84C[] ;//= "---";
extern char D_arcade_8004A850[] ;//= "REGI TIME <%02d>";
extern char D_arcade_8004A864[] ;//= "YOUR NAME WAS";
extern char D_arcade_8004A874[] ;//= "REGISTERED";
extern char D_arcade_8004A880[] ;//= "NAME REGISTRATION";
extern char D_arcade_8004A894[] ;//= "A B C D E F G H I J";
extern char D_arcade_8004A8A8[] ;//= "K L M N O P Q R S T";
extern char D_arcade_8004A8BC[] ;//= "U V W X Y Z . -";
extern char D_arcade_8004A8CC[] ;//= "ba";
extern char D_arcade_8004A8D0[] ;//= "%.3s";
extern char D_arcade_8004A8D8[] ;//= "%.3s  %06d  %.3s";
extern char D_arcade_8004A8EC[] ;//= "CREDIT 00";
extern char D_arcade_8004A8F8[] ;//= "1UP";
extern char D_arcade_8004A8FC[] ;//= "HIGH SCORE";
extern char D_arcade_8004A908[] ;//= "L=%02d";
extern char D_arcade_8004A910[] ;//= "%06d    %06d";
extern char D_arcade_8004A920[] ;//= "GAME OVER";
extern char D_arcade_8004A92C[] ;//= "RETURN";
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
extern ArcadeStruct1 D_arcade_8004BCD0[0x50];
extern void *D_arcade_8004C6D0;
extern s32 D_arcade_8004C6D4;
extern s16 D_arcade_8004C6D6;
extern s32 D_arcade_8004C6D8;
extern s32 D_arcade_8004C6DC; // arcade_internal_timer
extern s32 D_arcade_8004C6E0;
extern D_arcade_8004C6E4;
extern D_arcade_8004C6EC;
extern s32 D_arcade_8004C6E8;
extern s32 D_arcade_8004C6F0;
extern s32 D_arcade_8004C6F4;
extern s32 D_arcade_8004C6F8;
extern s32 D_arcade_8004C6FC;
extern s32 D_arcade_8004C704;
extern u32 D_arcade_8004C708;
extern s32 D_arcade_8004C70C;
extern s32 D_arcade_8004C710;
extern s32 arcade_next_sfx; //0x8004C714
extern u8  D_arcade_8004C718;
extern u8  D_arcade_8004C719;
extern u8  D_arcade_8004C71A;
extern u8  arcade_lives_internal; //0x8004C71B
extern u8  arcade_lives_visual;   //0x8004C71C
extern u8  arcade_game_state; //0x8004C71D
extern s8  D_arcade_8004C71E;
extern u8  D_arcade_8004C71F; // Index into D_arcade_8004BCD0[], arcade_jumpman_slot?
extern u8  D_arcade_8004C720;
extern u8 D_arcade_8004C721;
extern u8  arcade_background_visual; //0x8004C722
extern u8  D_arcade_8004C723;
extern u8  D_arcade_8004C724;
extern u8 D_arcade_8004C725;
extern u8 D_arcade_8004C726;
extern u8 D_arcade_8004C727;
extern u8 D_arcade_8004C728;
extern D_arcade_8004C72C;
extern s16 D_arcade_8004C72E;
extern D_arcade_8004C730;
extern s16 D_arcade_8004C732;

/* global_asm */
extern u8  D_global_asm_807444FC;
extern Gfx *D_global_asm_8076A050[];
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
