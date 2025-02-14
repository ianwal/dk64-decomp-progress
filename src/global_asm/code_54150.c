#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_global_asm_8064F450.s")

// Prop_unk24 shenanigans
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_global_asm_8064F6C0.s")

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_global_asm_8064F6F8.s")

s32 func_global_asm_806358E8(s16, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32);

typedef struct {
    void *unk0;
    void *unk4;
} Prop_unk78_8064F6F8;

/*
void func_global_asm_8064F6F8(void *arg0, s16 arg1) {
    Prop_unk24 *pad;
    Prop_unk78_8064F6F8 *sp68;
    u32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    pad = D_global_asm_807F6000[arg1].unk24;
    sp68 = D_global_asm_807F6000[arg1].unk78;
    sp64 = pad->unk68 + pad->unk0;
    memcpy(sp68->unk0, arg0, sp64);
    memcpy(sp68->unk4, arg0, sp64);
    func_global_asm_806357F8(arg1, &sp60, &sp5C, &sp58, &sp54, &sp50, &sp4C, &sp48, &sp44, 0);
    func_global_asm_806358E8(arg1, sp60, sp5C, sp58, sp54, sp50, sp4C, sp48, sp44, 0, 0, 0, 0, 1);
}
*/

void func_global_asm_8064F804(Prop_unk78 *arg0) {
    if (arg0) {
        // TODO: Hmm...
        func_global_asm_8061134C(*((s32*)&arg0->unk0));
        func_global_asm_8061134C(*((s32*)&arg0->unk4));
        func_global_asm_80650684(arg0);
        free(arg0);
    }
}

extern s32 D_807F6BE0;
extern s32 D_807F6BE4;
extern Prop_unk78 *D_807F6BE8;
extern u8 D_global_asm_807F6BEC;

typedef struct Struct8064F84C {
    s32 unk0[2];
    s32 unk8;
    u8 padC[0x14 - 0xC];
    s16 unk14;
    u8 unk16;
} Struct8064F84C;

u8 func_global_asm_8064F84C(s16 arg0) {
    Struct8064F84C *temp_s6;
    Struct8064F84C *var_s0;
    s32 var_s1;

    temp_s6 = D_global_asm_807F6000[func_global_asm_80659470((s32) arg0)].unk78;
    D_global_asm_807F6BEC = 0;
    if (temp_s6 != NULL) {
        var_s1 = 0;
        D_807F6BE0 = temp_s6->unk0[D_global_asm_807444FC];
        var_s0 = temp_s6;
        D_807F6BE4 = temp_s6->unk0[D_global_asm_807444FC ^ 1];
        D_807F6BE8 = temp_s6;
        do {
            if (var_s0->unk16 == 1) {
                func_global_asm_8064F954((s32) &var_s0->unk8);
                D_global_asm_807F6BEC = 1;
            }
            var_s1 += 0x14;
            var_s0 = &var_s0->unk14;
        } while (var_s1 != 0xC8);
        func_global_asm_806506E8(temp_s6);
    }
    return D_global_asm_807F6BEC;
}

void func_global_asm_8064F954(s32 arg0) {
    func_global_asm_806500E0();
    func_global_asm_8064F97C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_global_asm_8064F97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_global_asm_8064FA7C.s")

// Jumptable, matrix stuff, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_global_asm_8064FB64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_global_asm_806500E0.s")

typedef struct {
    Prop_unk78* unk0; // Used
    void *unk4; // TODO: Which struct?
    void *unk8; // TODO: Which struct?
    u8 unkC; // Used
    s8 unkD;
    s8 unkE;
    s8 unkF;
} GlobalASMStruct10;

extern GlobalASMStruct10 D_global_asm_807F6960[];

void func_global_asm_8065051C(void) {
    s32 i;
    for (i = 0; i < 0x28; i++) {
        D_global_asm_807F6960[i].unk0 = NULL;
    }
}

void func_global_asm_8065054C(Prop_unk78 *arg0, void *arg1, void *arg2) {
    s32 found = FALSE;
    s32 i = 0;

    while (!found && i < 0x28) {
        if (!D_global_asm_807F6960[i].unk0) {
            found = TRUE;
        } else {
            i++;
        }
    }
    if (found) {
        D_global_asm_807F6960[i].unk0 = arg0;
        D_global_asm_807F6960[i].unk4 = arg1;
        D_global_asm_807F6960[i].unk8 = arg2;
        D_global_asm_807F6960[i].unkC = D_global_asm_807444FC ^ 1;
    } else {
        raiseException(0xB, 0, 0, 0);
    }
}

void func_global_asm_806505F0(Prop_unk78 *arg0) {
    s32 i;
    for (i = 0; i < 0x28; i++) {
        if (D_global_asm_807F6960[i].unk0 && arg0 == D_global_asm_807F6960[i].unk8) {
            D_global_asm_807F6960[i].unk0 = NULL;
        }
    }
}

void func_global_asm_80650684(Prop_unk78 *arg0) {
    s32 i;
    for (i = 0; i < 0x28; i++) {
        if (arg0 == D_global_asm_807F6960[i].unk0) {
            D_global_asm_807F6960[i].unk0 = NULL;
        }
    }
}

void func_global_asm_806506E8(Prop_unk78 *arg0) {
    s32 i;
    for (i = 0; i < 0x28; i++) {
        if (arg0 == D_global_asm_807F6960[i].unk0 && D_global_asm_807F6960[i].unkC == D_global_asm_807444FC) {
            // TODO: Sizeof which struct?
            memcpy(D_global_asm_807F6960[i].unk8, D_global_asm_807F6960[i].unk4, 0x40);
            D_global_asm_807F6960[i].unk0 = NULL;
            D_global_asm_807F6BEC = 1;
        }
    }
}

void func_global_asm_80650794(s16 arg0, s16 arg1, u8 arg2, f32 arg3) {
    Prop_unk78 *temp_v1;
    u8 var_a0;

    temp_v1 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    if (temp_v1 != NULL) {
        var_a0 = 8.0f * arg3;
        if (var_a0 >= 0x10) {
            var_a0 = 0xF;
        }
        temp_v1[arg1 + 1].unk7 = (var_a0 * 0x10) + arg2;
    }
}

void func_global_asm_806508B4(s16 arg0, s16 arg1, s16 arg2) {
    Prop_unk78 *temp_v0;
    Prop_unk78 *temp_v1;

    temp_v1 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    if (temp_v1 != NULL) {
        temp_v1[arg1].unk12 = arg2;
        temp_v1[arg1 + 1].unk2 = 1;
        temp_v1[arg1].unk10 = 0;
    }
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_global_asm_8065092C.s")

/*
void func_global_asm_8065092C(s16 arg0, s16 arg1) {
    Prop_unk78 *temp_a0;

    temp_a0 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    if (temp_a0 != NULL) {
        temp_a0[arg1 + 1].unk2 = 0;
        func_global_asm_8064FA7C(temp_a0, &temp_a0->unk8);
    }
}
*/

void func_global_asm_80650998(s16 arg0, s16 arg1) {
    Prop_unk78 *temp_v1;

    temp_v1 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    if (temp_v1 != NULL) {
        temp_v1[arg1 + 1].unk5 = 0;
        temp_v1[arg1].unkC = 0;
    }
}

void func_global_asm_80650A04(s16 arg0, s16 arg1, s16 arg2) {
    Prop_unk78 *temp_v1;

    temp_v1 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    if (temp_v1 != NULL) {
        temp_v1[arg1 + 1].unk0 = arg2;
    }
}

s16 func_global_asm_80650A70(s16 arg0, s16 arg1) {
    s16 var_v0;
    Prop_unk78 *temp_v1;

    temp_v1 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    var_v0 = 0;
    if (temp_v1 != NULL) {
        return temp_v1[arg1 + 1].unk0;
    }
    return var_v0;
}

void func_global_asm_80650AD8(s16 arg0, s16 arg1, s16 arg2, f32 arg3) {
    Prop_unk78 *temp_v1;

    temp_v1 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    if (temp_v1 != NULL) {
        temp_v1[arg1].unkC = arg3;
        temp_v1[arg1 + 1].unk5 = arg2;
    }
}

void func_global_asm_80650B50(s16 arg0, s16 arg1, s16 arg2) {
    Prop_unk78 *temp_v1;

    temp_v1 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    if (temp_v1 != NULL) {
        temp_v1[arg1 + 1].unk3 = arg2;
    }
}

void func_global_asm_80650BBC(s16 arg0, s16 arg1, s16 arg2) {
    Prop_unk78 *temp_v1;

    temp_v1 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    if (temp_v1 != NULL) {
        temp_v1[arg1 + 1].unk4 = arg2;
    }
}

void func_global_asm_80650C28(s16 arg0, s16 arg1, s16 arg2) {
    Prop_unk78 *temp_v1;

    temp_v1 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    if (temp_v1 != NULL) {
        temp_v1[arg1].unk10 = 0;
        temp_v1[arg1].unk12 = arg2;
    }
}

void func_global_asm_80650C98(s16 arg0, s16 arg1, s16 arg2) {
    Prop_unk78 *temp_v1;

    temp_v1 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    if (temp_v1 != NULL) {
        temp_v1[arg1 + 1].unk6 = arg2;
    }
}

u8 func_global_asm_80650D04(s16 arg0, s16 arg1) {
    Prop_unk78 *temp_v1;
    s32 var_v0;

    temp_v1 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    if (temp_v1 != NULL) {
        return temp_v1[arg1 + 1].unk2 == 1 ? 1 : 0;
    }
    return 0;
}

void func_global_asm_80650D8C(s16 arg0, s16 arg1, s16 *arg2, f32 *arg3, u8 *arg4) {
    Prop_unk78 *temp_v0;
    Prop_unk78 *temp_v1;

    temp_v1 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk78;
    if (temp_v1 != NULL) {
        temp_v0 = &temp_v1[arg1];
        *arg3 = temp_v1[arg1].unkC;
        *arg2 = temp_v1[arg1 + 1].unk5;
        *arg4 = temp_v1[arg1 + 1].unk3;
    }
}
