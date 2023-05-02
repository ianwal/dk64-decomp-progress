#include <ultra64.h>
#include "functions.h"


extern u8 D_8074450C;

// TODO: Is this a huge static struct?
// If so, we can match this whole file pre much
extern s32 D_807FDB00;
extern s32 D_807FDB04;
extern s32 D_807FDB08;
extern u8 D_807FDB0C;
extern u8 D_807FDB0D;
extern u8 D_807FDB0E;
extern u8 D_807FDB0F;
extern s32 D_807FDB10;
extern s32 D_807FDB14;
extern u8 D_807FDB18;
extern u16 D_807FDB1A;
extern u8 D_807FDB1C;
extern u8 D_807FDB1D;
extern f32 D_807FDB20;
extern f32 D_807FDB24;
extern u8 D_807FDB28;
extern s32 D_807FDB2C;
extern s32 D_807FDB30;
extern u16 D_807FDB34;
extern u16 D_807FDB36;
extern s16 D_807FDB38;
extern u16 D_807FDB3A;
extern s16 D_807FDB3C;
extern s16 D_807FDB3E;
extern s16 D_807FDB40;
extern s16 D_807FDB42;

void func_80714A9C(void);

void func_80714670(void) {
    D_807FDB00 = 0;
    D_807FDB04 = 0;
    D_807FDB08 = 0;
    func_80714A9C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807146A4.s")

// TODO: Struct?
void func_807146E0(u8 *arg0, u8 *arg1, u8 *arg2) {
    *arg1 = arg0[4];
    *arg2 = arg0[5];
}

// TODO: Struct?
void func_807146F4(s16 *arg0, s16 *arg1, s16 *arg2) {
    *arg1 = arg0[7];
    *arg2 = arg0[8];
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80714708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80714778.s")

void func_80714944(s32 arg0) {
    D_807FDB30 = arg0;
}

void func_80714950(s32 arg0) {
    D_807FDB2C = arg0;
}

void func_8071495C(void) {
    D_807FDB1D = 1;
}

void func_8071496C(s16 arg0) {
    D_807FDB1A = arg0;
}

void func_8071497C(u16 arg0) {
    D_807FDB34 = arg0;
}

void func_8071498C(void *arg0) {
    D_807FDB14 = arg0;
}

void func_80714998(u8 arg0) {
    D_807FDB1C = arg0;
}

void func_807149A8(u16 arg0) {
    D_807FDB3A = arg0;
}

void func_807149B8(u8 arg0) {
    D_807FDB18 = arg0;
}

void func_807149C8(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    D_807FDB0C = arg0;
    D_807FDB0D = arg1;
    D_807FDB0E = arg2;
    D_807FDB0F = arg3;
}

void func_807149FC(s32 arg0) {
    D_807FDB10 = arg0;
}

void func_80714A08(f32 arg0, f32 arg1) {
    D_807FDB20 = arg0;
    D_807FDB24 = arg1;
    D_807FDB28 = 1;
}

void func_80714A28(u16 arg0) {
    D_807FDB36 = arg0;
}

void func_80714A38(u8 arg0) {
   D_807FDB36 |= arg0;
}

void func_80714A58(u16 arg0) {
    D_807FDB38 = arg0;
}

void func_80714A68(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_807FDB3C = arg0;
    D_807FDB3E = arg1;
    D_807FDB40 = arg2;
    D_807FDB42 = arg3;
}

void func_80714A9C(void) {
    D_807FDB0F = 0;
    D_807FDB10 = 1;
    D_807FDB14 = 0;
    D_807FDB18 = 0;
    D_807FDB1C = 1;
    D_807FDB1A = 0;
    D_807FDB1D = 0;
    D_807FDB28 = 0;
    D_807FDB2C = 0;
    D_807FDB30 = 0;
    D_807FDB36 = 0;
    D_807FDB38 = -1;
    D_807FDB3C = D_8074450C * 0xA;
    D_807FDB3E = D_8074450C * 0xA;
    D_807FDB40 = D_8074450C * 0x135;
    D_807FDB42 = D_8074450C * 0xE5;
    D_807FDB3A = 0x258;
}

s32 func_80714D08(void*, f32, f32, f32, f32, s32, s32, s32, s32);

void func_80714B84(void *arg0, f32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    func_806335B0(arg2, 1, arg3, &sp3C, &sp38, &sp34);
    func_80714D08(arg0, arg1, sp3C, sp38, sp34, 0, arg2, arg3, arg4);
}

s32 func_80714C08(void *arg0, f32 arg1, Actor *arg2, s32 arg3, u8 arg4) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    func_80671C0C(arg2, arg3, &sp3C, &sp38, &sp34);
    if (!(arg2->object_properties_bitfield & 0x200) && (arg2->animation_state != NULL) && (D_807FDB36 & 0x80)) {
        func_80714A38(0x40);
    }
    return func_80714D08(arg0, arg1, sp3C, sp38, sp34, arg2, 0, arg3, arg4);
}

s32 func_80714CC0(void* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return func_80714D08(arg0, arg1, arg2, arg3, arg4, 0, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80714D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071509C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80715270.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071586C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807158C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80715908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80715A3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80715B30.s")

void func_80715E38(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp_f0;
    f32 temp_f16;
    f32 temp_f2;

    temp_f0 = arg0 - arg3;
    temp_f2 = arg1 - arg4;
    temp_f16 = arg2 - arg5;
    sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f16 * temp_f16));
}

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80715E94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80716F10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80716FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071720C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717B64.s")

// Very doable, possibly same struct as func_8071C818
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717D4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717DB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717F1C.s")

// Doable, large struct, that sprite thing?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80718080.s")

void func_807180F4(s32 arg0, s32 arg1) {
    func_80717D4C();
    func_80716FB4(arg0, arg1);
}

extern s32 D_80718380; // Function pointer?
extern s32 D_8071FEF4;

void func_80718124(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_807149B8(1);
    func_80714998(3);
    func_8071498C(&D_80718380);
    func_80714CC0(&D_8071FEF4, arg0, arg1, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80718188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071827C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80718380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807184F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807186C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807189BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80718BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071910C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807195D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807197B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80719A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80719B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80719C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80719EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A1E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A8B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071AADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071ABDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071AF30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B1AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B24C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B2EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B44C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B8EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071BB14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071BC80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071BE04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C24C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C818.s")

/*
// TODO: Is this a different struct?
// 0x35C is alpha in this function
extern u8 D_807444FC;
extern f64 D_8075E9C8;

void func_8071C818(otherSpriteControl *arg0, s8 *arg1) {
    float sp70[4][4];
    float sp30[4][4];
    f64 temp_f2;

    temp_f2 = D_8075E9C8;
    arg0->xScale -= temp_f2;
    arg0->yScale -= temp_f2;
    if (arg0->xScale <= 0.0f) {
        *arg1 = 1;
    }
    arg0->unk35C += 5;
    guScaleF(&sp70, arg0->xScale, arg0->yScale, 0.0f);
    guRotateF(&sp30, arg0->unk35C, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp70, &sp30, &sp70);
    guMtxF2L(&sp70, arg0 + (D_807444FC << 6) + 0x128);
    arg0->unk32C = 2;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C9E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071CDE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D0F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D28C.s")

// More sprite stuff?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D5BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D94C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071DB74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071DC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071E028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071E110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071E1C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071E3EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071E864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071EA24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071EB70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071EDEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071EEA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071EEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071EFDC.s")

// TODO: Which struct is this?
typedef struct {
    u8 unk0[0x340 - 0x0];
    f32 unk340;
    f32 unk344;
    f32 unk348;
    s16 unk34C;
    s16 unk34E;
} Struct8071F034_arg0;

void func_8071F034(Struct8071F034_arg0 *arg0, s32 arg1) {
    if (arg0->unk34E == 0) {
        arg0->unk340 = player_pointer->x_position;
        arg0->unk344 = player_pointer->y_position;
        arg0->unk348 = player_pointer->z_position;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F1D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F2F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F3C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F8E4.s")
