#include <ultra64.h>
#include "functions.h"



#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_807094D0.s")

extern u8 D_807444F4;
extern f32 D_807FD9C4;
extern s8 D_807FD9BC;
extern s8 D_807444F8;
extern u8 D_807FD9BD;
extern s32 D_8076D1F8;
extern s32 D_807FD9C8;

void func_80737638(s32, s32, s32, s32, f32, s32, s32);

/*
// TODO: Regalloc, and last function call is sus
void func_807094D0(u8 arg0) { // init zipper
    D_807444F4 = is_cutscene_active;
    switch (arg0) {
        case 2:
            D_807FD9C4 = 1.0f;
            D_807FD9BC = 0;
            D_807444F8 = 1;
            is_cutscene_active = 6;
            break;
        case 3:
            D_807FD9C4 = 0.5f;
            D_807FD9BC = 0;
            D_807444F8 = 2;
            is_cutscene_active = 2;
            D_807FD9BD = 6;
            if ((D_807444F4 == 1) && (D_807FBB64 & 1)) {
                func_80600BBC(0);
            }
            break;
    }
    func_80737638(D_8076D1F8, 0x1BC, 0x7FFF, 0x3F, 1.0f, 0, &D_807FD9C8);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_807095E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_80709890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_80709ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_80709BC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_8070A220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_8070A848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_8070A934.s")

/*
s32 func_805FE71C(s32, u8, s32 *, ?);
s32 func_805FE7B4(s32 *, s32 *, s32 *, ?);
s32 func_80610044(s32, s32, ?, ?, s32, s32);
s32 func_8061CBCC();
s32 func_8070AC74(s32, s32 *, u8 *);
s32 func_8070AF24(s32 *, u8 *);
s32 func_8070B7EC(s32 *, s32, s32);
extern u8 D_807444F4;
extern void *D_807FD9A8;
extern s32 D_807FD9B0;
extern s32 D_807FD9B4;
extern s32 D_807FD9B8;
extern u8 D_807FD9BC;
extern u8 D_807FD9BD;

// TODO: Made decent progress, cleaning up mips_to_c output, still needs some TLC though
// Those array/struct lookups, oof
// Also idk what's going on with the first switch case
void func_8070A934(s32 nextMap, s32 nextExit) {
    s32 sp34;
    s32 *sp30;
    s32 *temp_t7;
    s32 temp_t5;
    u8 temp_t1;
    u8 temp_t1_2;
    u8 temp_t5_2;

    func_80610044(((D_807444FC * 4) + 0x80770000)->unk-5FB0, D_8076A088, 3, 1, 0x4D2, 1);
    temp_t1 = D_807444FC ^ 1;
    temp_t5 = (temp_t1 & 0xFF) * 0x11B0;
    D_807444FC = temp_t1;
    object_timer++;
    temp_t7 = temp_t5 + &D_80767CE8;
    D_8076A048 = temp_t7;
    sp30 = temp_t7 + 0xDB0;
    switch (D_807FD9BC) {
        case 0:
            D_807FD9BC = 1;
            func_8070AF24(&object_timer, &D_807FD9BC);
            break;
        }
        case 1:
            if ((D_8076A0B1 & 1) && (D_807FD888 == 31.0f)) {
                sp34 = ((D_807444FC * 4) + 0x80770000)->unk-5FB0;
                if (D_8076A0B2 == 1) {
                    is_cutscene_active = D_807444F4;
                }
            } else {
                func_8070AC74(*0x8076A048, &sp34, &D_8076A0B1);
                if (func_8070B7EC(&sp34, D_807FD9B8, D_807FD9B0)) {
                    switch (D_807444F8) {
                        case 1:
                            osViBlack(1);
                            func_805FF378(nextMap, nextExit);
                            D_807FD888 = 31.0f;
                            D_807444F8 = 2;
                            break;
                        case 2:
                            func_8061134C(D_807FD9B0);
                            func_8061134C(D_807FD9A8->unk8);
                            func_8061134C(D_807FD9B4);
                            func_8061134C(D_807FD9A8->unk10);
                            func_8061134C(D_807FD9A8->unk14);
                            func_8066B434(D_807FD9B8, 0x24B, 0x4A);
                            is_cutscene_active = D_807444F4;
                            if ((is_cutscene_active == 1) && D_807FBB64 & 1) {
                                func_8061CBCC();
                            }
                            D_807444F8 = 3;
                            D_807FD888 = 0.0f;
                            break;
                    }
                }
            }
            if (D_807FD9BD != 0) {
                temp_t5_2 = D_807FD9BD - 1;
                D_807FD9BD = temp_t5_2;
                if ((temp_t5_2 & 0xFF) == 0) {
                    D_8076A0B1 |= 2;
                }
            }
            if (D_8076A0A4 && (is_cutscene_active != 6)) {
                func_805FE71C(sp34, D_807444FC, &D_8076A088, 0);
                func_805FE7B4(sp30, D_8076A048, &D_8076A08C, 1);
                return;
            }
            func_805FE71C(sp34, D_807444FC, &D_8076A088, 1);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_8070AC74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_8070AF24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_8070B05C.s")

extern u8 D_80755070; // intro_story_is_playing

void setIntroStoryPlaying(u8 arg0) {
    D_80755070 = arg0;
}

u8 isIntroStoryPlaying(void) {
    return D_80755070;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_8070B324.s")

extern s8 D_8074583C;
extern u8 D_8076A0B1;
extern u8 D_80755070;
extern s32 D_807550A4;
extern f32 D_8075E430;

void func_80737B58(s32, u16);
void func_8060A4D0(s32, f32);

/*
// TODO: Doable, progess made
void func_8070B324(f32 arg0, s32 arg1, s32 *arg2) {
    s32 sp34;
    s32 *var_s0;
    u32 temp_s0;
    u16 temp_t7;
    s32 var_a0;

    temp_t7 = (D_8075E430 * arg0);
    temp_s0 = ((temp_t7 * D_8074583C) / 40.0);
    sp34 = osGetThreadPri(NULL);
    osSetThreadPri(NULL, 0x1A);
    func_80737B58(0, temp_s0);
    if (arg1 != 0) {
        D_807550A4 = 1;
        func_80737B58(2, temp_s0);
        if ((D_80755070 == 0) && ((D_8076A0B1 & 1) || !(D_8076A0B1 & 0x40))) {
            func_8060A4D0(0, arg0);
        }
    } else {
        func_80737B58(3, ((temp_t7 * D_8074583C) / 40.0));
        if (D_807550A4 != 0) {
            D_807550A4 = 0;
            func_80737B58(2, ((D_8074583C * 25000) / 40.0));
            func_80737B58(1, ((D_8074583C * 25000) / 40.0));
        }
    }
    if (arg2 != NULL) {
        var_s0 = arg2 + (0 * 4);
        if (*arg2 != 0) {
            var_a0 = *var_s0;
loop_10:
            func_8060A4D0(var_a0, arg0);
            var_s0 += 4;
            if (arg2 != NULL) {
                var_a0 = *var_s0;
                if (var_a0 != 0) {
                    goto loop_10;
                }
            }
        }
    }
    osSetThreadPri(NULL, sp34);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10E1D0/func_8070B7EC.s")
