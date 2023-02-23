#include <ultra64.h>
#include "functions.h"
#include "variables.h"

// malloc, needs struct definitions
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_3840/func_80027840.s")

typedef struct BossStruct2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} BossStruct2;

void func_800278F4(BossStruct2 *arg0, f32 arg1, s16 arg2, s16 arg3) {
    arg0->unkC += ((arg2 - arg0->unkC) * arg1);
    arg0->unk8 += ((arg3 - arg0->unk8) * arg1);
}

// Loop, needs some more struct definitions I think
// Looks doable though
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_3840/func_80027950.s")

// Loop, needs some more struct definitions I think
// Looks doable though
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_3840/func_80027A30.s")

// Jumptable, 2224 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_3840/func_80027BA8.s")

void func_80028458() {
    func_805FF8F8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_3840/func_80028478.s")

extern f32 D_80036050;
extern s32 D_8074E880[];
extern void func_8071CDE0();

void func_806A5DF0(s32, f32, f32, f32, s32, s32, s16, s32);

/*
// TODO: Very close, might need .rodata defined for D_80036050
void func_80028478(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8 arg5) {
    s16 i;

    playSong(0x36, 1.0f);
    if (isFlagSet(arg0, FLAG_TYPE_PERMANENT)) {
        func_80028458();
        return;
    }

    for (i = 0; i < 6; i++) {
        func_8071498C(&func_8071CDE0);
        func_807149FC(-1);
        func_807149B8(1);
        func_80714950(D_807FDC94);
        func_80714CC0(D_8074E880[((rand() >> 0xF) % 1000) % 3], D_80036050, D_807FDC94->x_position, D_807FDC94->y_position + D_807FDC94->unk15E, D_807FDC94->z_position);
    }
    func_806A5DF0(0x48, arg1, arg2, arg3, arg4, arg5, arg0, 0);
}
*/

void func_80028680() {
    func_806A2A10(-0x7F83, 0xD2, 0xB4);
    func_806A2B08(current_actor_pointer->unk11C);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_3840/func_800286B8.s")

void func_80028818() {

}

void func_80028820() {
    // K. Rool Tiny Phase Toes Complete
    setFlag(0x51, FALSE, FLAG_TYPE_TEMPORARY);
    setFlag(0x52, FALSE, FLAG_TYPE_TEMPORARY);
    setFlag(0x53, FALSE, FLAG_TYPE_TEMPORARY);
    setFlag(0x54, FALSE, FLAG_TYPE_TEMPORARY);
}

// Jumptable, 2140 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_3840/func_80028878.s")

void func_800290D4(u8 arg0) {
    if (arg0) {
        func_8066EA64(current_actor_pointer, 2);
        func_8066EA64(current_actor_pointer, 3);
    } else {
        func_8066EA90(current_actor_pointer, 2);
        func_8066EA90(current_actor_pointer, 3);
    }
}

typedef struct BossStruct1 {
    u8 unk0; // Map
    u8 unk1;
    s16 unk2; // Flag
    u8 unk4;
    u8 unk5;
} BossStruct1;

extern BossStruct1 D_800359D0[];

void func_80029140(s16* arg0) {
    s16 i = 0;
    while (D_800359D0[i].unk0 != 0 && D_800359D0[i].unk0 != current_map) {
        i++;
    }
    if (D_800359D0[i].unk0 != 0 && D_800359D0[i].unk4 == *arg0) {
        if (isFlagSet(D_800359D0[i].unk2, FLAG_TYPE_TEMPORARY)) {
            *arg0 = D_800359D0[i].unk5;
        }
    }
}

void func_8002920C(void) {
    s16 i = 0;
    while (D_800359D0[i].unk0 != 0 && D_800359D0[i].unk0 != current_map) {
        i++;
    }
    if (D_800359D0[i].unk0 != 0) {
        setFlag(D_800359D0[i].unk2, TRUE, FLAG_TYPE_TEMPORARY);
    }
}
