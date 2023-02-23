#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_80748E00;
extern u8 D_80748E04;
extern void *D_80748E14; // TODO: Datatype
extern u8 D_80748E18[];
extern f64 D_80758F08;

extern u8 D_807F951D;
extern f32 D_807F9468;
extern u8 D_807F946C;
extern u8 D_807F946E;
extern f32 D_807F9488;
extern f32 D_807F948C;
extern s16 D_807F9490;
extern s16 D_807F9498;
extern s16 D_807F94A2;
extern s16 D_807F94A4;
extern u8 D_807F94AA;
extern u8 D_807F94AE;
extern u8 D_807F94AF;
extern u8 D_807F94B0;
extern u8 D_807F94B1;
extern u8 D_807F94B3;
extern u8 D_807F94B4;
extern u8 D_807F94B5;
extern u8 D_807F94B7;
extern u8 D_807F94BC;
extern u8 D_807F9484;
extern u8 D_807F9510;
extern s32 *D_807F95A8[];
extern s32 D_807F9678;
extern u8 D_807F967C;
extern u8 D_807F967D;

extern s32 *D_807FB1A0[];

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80664CB0.s")

/*
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Temp20Big;

extern Temp20Big D_80748BA0[];
extern s8 D_807F9440[];
extern s32 D_807F9448;

void func_80664CB0(s16 arg0) {
    s32 i;

    D_807F9448 = 0;
    i = 0;
    do {
        if (arg0 == D_80748BA0[i].unk0) {
            if (D_807F9448 != 8) {
                D_807F9440[D_807F9448] = i;
                D_807F9448++;
            }
        }
    } while (i++ < 0xD);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80664D20.s")

void func_80665ACC(Actor *arg0);
u16 func_80672134(s16, s16, s16, s16);

void func_80665160(Actor *arg0, s16 arg1, s16 arg2) {
    func_8067ACB4();
    func_80665ACC(arg0);
    if (arg0->unkFC != 0) {
        func_80672680(arg0->unkEE, arg1, arg0->unkF4, arg0->unkF6, &arg0->unkF2);
        arg0->unkFA = func_80672134(arg0->unkF4, arg0->unkF6, arg2, arg0->unkF8);
        if ((arg0->unk64 & 0x200) && (arg0->unk64 & 0x100)) {
            arg0->unkFA = 0;
        }
        arg0->unkEE = arg0->unkF2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806651FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806653C0.s")

void func_80665548(void) {
    D_80748E00 = 1;
}

u8 func_80665558(void) {
    return D_80748E04;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80665564.s")

// short but kinda complicated, struct?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80665AAC.s")

void func_80665ACC(Actor *arg0) {
    arg0->object_properties_bitfield |= 0x2; // block playing instrument?
    arg0->object_properties_bitfield |= 0x20; // TODO: What is this used for?
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80665AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80665C18.s")

//forward decl necessary
//looks like its taking the linear distance between 2 points (2D)
void func_80665C18(f32,f32,f32,f32,f32);
void func_80665DE0(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = arg0 - arg2;
    temp_f2 = arg1 - arg3;
    func_80665C18(arg0, arg1, arg2, arg3, 
                    sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2)));
}

// complicated float stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80665E48.s")

/*
extern f32 D_80758EB0;

f32 func_80665E48(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    return (func_80665DE0(arg0, arg1, arg2, arg3) * D_80758EB0) * 0.00048828125;
}
*/

void func_80611BB4(f32, f32);

void func_80665E94(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6) {
    f32 temp_f0;
    f32 temp_f2;
    f32 phi_f14;

    temp_f0 = arg0 - arg3;
    temp_f2 = arg2 - arg5;
    temp_f0 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
    if (temp_f0 < arg6) {
        phi_f14 = arg6;
    } else {
        phi_f14 = temp_f0;
    }
    func_80611BB4(arg4 - arg1, phi_f14);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80665F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80665FB4.s")

/*
extern f32 D_80758EB4;

void func_8066EB50(Actor *actor, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_806303C4(f32, f32, Actor*, s32, s32, s16, s32);

void func_80665FB4(Actor *arg0) {
    f32 phi_f0;

    f32 xPos = arg0->x_position;
    f32 yPos = arg0->y_position;
    f32 zPos = arg0->z_position;

    if (arg0->animation_state) {
        func_806303C4(yPos, zPos, arg0->draw_distance, 0, 1, -1, 1);
    }
    if (arg0->ledge_info_pointer) {
        if (arg0->animation_state) {
            phi_f0 = arg0->animation_state->scale_y;
        } else {
            phi_f0 = D_80758EB4;
        }
        func_8066EB50(arg0, xPos, yPos, zPos, phi_f0);
        arg0->ledge_info_pointer->unk80 = object_timer;
    }
    //return phi_f0;
}
*/

// Loads floors from pointer table 3 for the current map
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80666090.s")

void func_80666280(u8 arg0) {
    D_807F94B4 = arg0;
}

void func_80666428(Actor*, f32, f32, f32, s32, s32, s32, s32, u8);

void func_80666290(Actor *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    D_807F94BC = 0;
    D_807F94B3 = 0;
    if (arg0->unkCC && !arg0->locked_to_pad && arg0->object_properties_bitfield & 0x10) {
        func_80671C0C(arg0, arg0->unkCC, &sp3C, &sp38, &sp34);
    } else {
        sp3C = arg0->x_position;
        sp38 = arg0->unk8C;
        sp34 = arg0->z_position;
    }
    func_80666428(arg0, sp3C, sp38, sp34, arg1, arg2, arg3, arg4, arg5);
}

void func_8066635C(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4) {
    u8 sp3F;
    u8 sp3E;
    s32 sp38;
    s32 sp34;

    // Actor->behaviour == Camera
    if (arg0->unk58 == 0xBC) {
        D_807F94B3 = 1;
    } else {
        D_807F94B3 = 0;
    }
    D_807F94BC = 1;
    func_80666428(0, arg1, arg2, arg3, &sp3F, &sp38, &sp3E, &sp34, 0);
    *arg4 = D_807F948C;
}

void func_806663F8(void) {
    D_807F94AE = 0;
    D_807F94AF = 0;
    D_807F94B0 = 0;
    D_807F94B7 = 0;
}

u8 func_8066641C(void) {
    return D_807F951D;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80666428.s")

u8 func_80666A88(void) {
    return D_807F946E;
}

u8 func_80666A94(void) {
    return D_807F94AE;
}

u8 func_80666AA0(void) {
    return D_807F94AF;
}

u8 func_80666AAC(void) {
    return D_807F94B0;
}

u8 func_80666AB8(void) {
    return D_807F94B7;
}

void func_80666AC4(s16 *arg0, s16 *arg1) {
    *arg0 = D_807F94A2;
    *arg1 = D_807F94A4;
}

u8 func_80666AE0(void) {
    return D_807F94B1;
}

u8 func_80666AEC(void) {
    return D_807F94AA;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80666AF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80666D88.s")

s32 func_80666F04(f32 arg0, f32 arg1, u8 arg2, u8 arg3) {
    f32 phi_f0;
    s32 phi_v1;

    phi_v1 = 0;
    if (arg3 == 0xFF && arg0 < arg1) {
        phi_f0 = arg2 == 1 ? D_80758F08 : 25;
        if ((arg1 - arg0) < phi_f0) {
            D_807F946C = 1;
            D_807F9468 = arg1 - phi_f0;
            phi_v1 = 1;
            if (arg2) {
                D_807F9468 /= 6.0f;
            }
            D_807F9468 += 6.0;
        }
    }
    return phi_v1;
}

s32 func_80666FC8(f32 arg0, f32 arg1, f32 arg2, u8 arg3) {
    f32 phi_f0;
    s32 phi_v0;
    s32 phi_v1;
    f32 phi_f2;

    phi_f0 = arg3 == 1 ? 60.0 : 10.0;

    if (arg0 <= arg2)
        phi_v0 = TRUE;
    else if ((arg0 - arg2) < phi_f0)
        phi_v0 = TRUE;
    else
        phi_v0 = FALSE;

    if (arg1 <= arg2)
        phi_v1 = TRUE;
    else if ((arg1 - arg2) < phi_f0)
        phi_v1 = TRUE;
    else
        phi_v1 = FALSE;

    if (!(phi_v0 || phi_v1)) {
        return FALSE;
    }
    if (!phi_v1) {
        return FALSE;
    }
    if (!phi_v0) {
        return TRUE;
    }
    
    if (arg2 < arg0) {
        phi_f0 = arg0 - arg2;
    } else {
        phi_f0 = arg2 - arg0;
    }
    if (arg2 < arg1) {
        phi_f2 = arg1 - arg2;
    } else {
        phi_f2 = arg2 - arg1;
    }

    if (phi_f0 < phi_f2) {
        return FALSE;
    }
    return TRUE;
}

void func_80667110(s32 arg0, s32 arg1, s32 arg2) {
    D_807F9484 = 0;
    D_807F9510 = 0;
    func_80667180(arg0, arg1, arg2, 0);
    D_807F94A4 = D_807F9498;
    D_807F94A2 = D_807F9490;
}

u8 func_8066715C(f32 *arg0) {
    *arg0 = D_807F9488;
    return D_807F9484;
}

u8 func_80667174(void) {
    return D_807F94B5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80667180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806672B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066785C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806679BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80668520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806685E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806686F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806687E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806688B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066893C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806689F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80668B28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80668C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80668E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80669588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80669650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806696A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80669830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80669930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806699C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80669A6C.s")

typedef struct {
    f32     unk0;
    f32     unk4;
    f32     unk8;
    f32     unkC;
    f32     unk10;
    f32     unk14;
} GlobalASMStruct80;

int func_80669BE8(GlobalASMStruct80 *arg0, f32 arg1, f32 arg2) {
    if (arg1 < arg0->unk0) {
        return FALSE;
    }
    if (arg2 < arg0->unk8) {
        return FALSE;
    }
    if (arg0->unkC < arg1) {
        return FALSE;
    }
    if (arg0->unk14 < arg2) {
        return FALSE;
    }
    return TRUE;
}

int func_80669C6C(GlobalASMStruct80 *arg0, f32 arg1) {
    if (arg1 < arg0->unk4) {
        return FALSE;
    }
    if (arg0->unk10 < arg1) {
        return FALSE;
    }
    return TRUE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80669CB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80669E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066A08C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066A584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066A64C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066A75C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066A834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066A988.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066AC10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066ACA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066ADA0.s")

void func_8066AEE4(s32 arg0, s32 arg1) {
    s32 sp24;
    s32 sp20;

    sp24 = arg0;
    sp20 = arg1;
    if (!D_80748E14) {
        D_80748E14 = malloc(0x2400);
    }
    func_800024E0(&sp24, &sp20, D_80748E14);
    func_8061130C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066AF40.s")

s32 func_8066B020(s32 arg0, s32 arg1) {
    s32 sp1C;
    s32 sp18;

    func_8066B5F4();
    func_8066B4D4(arg0, arg1, &sp1C, &sp18);
    if (sp18 == 0) {
        return 0;
    }
    return sp1C;
}

s32 func_8066B06C(s32 arg0, s32 arg1) {
    s32 sp1C;
    s32 sp18;

    if (D_80748E18[arg0] != 0) {
        sp18 = *(D_807FB1A0[arg0] + arg1);
    } else {
        func_8066B5F4();
        func_8066B4D4(arg0, arg1, &sp1C, &sp18);
    }
    return sp18;
}

void func_8066B0DC(void) {
    D_807F967C = 1;
}

void func_8066B0EC(s32 arg0) {
    D_807F9678 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/getPointerTableFile.s")

void func_8066B424(void) {
    D_807F967D = 1;
}

//forward decl needed
void func_8066B4AC(s32,s32,s32);
s32  func_8066B9F4(void*);

// It's usually a file from a pointer table in arg0
void func_8066B434(void *arg0, s32 arg1, s32 arg2) {
    s32 sp1C;
    s32 sp18;

    if (func_8066B9F4(arg0) == 0) {
        func_8066BC00(arg0, &sp1C, &sp18);
        func_8066B4AC(sp1C, sp18, 0);
        if (D_807F967D == 0) {
            func_8061134C(arg0);
        } else {
            func_8061130C(arg0);
        }
    }
    D_807F967D = 0;
}

void func_8066B4AC(s32 arg0, s32 arg1, s32 arg2) {
    s32 *temp_v0 = D_807F95A8[arg0];
    if (temp_v0) {
        *(temp_v0 + arg1) = arg2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066B4D4.s")

s32 func_8066B5C8(s32 arg0, s32 arg1) {
    s32 *temp_v0;
    s32 phi_v1;

    temp_v0 = D_807F95A8[arg0];
    phi_v1 = 0;
    if (temp_v0) {
        phi_v1 = *(temp_v0 + arg1);
    }
    return phi_v1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066B5F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066B75C.s")

//forward declaration needed here
u32 func_8066C2B4(u32);
extern s32 D_807F9628[];
void func_8066B7AC(s32 arg0, s32 arg1, s32 arg2) {
    func_8066B7F4(D_807F9628[func_8066C2B4(arg0)], arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066B7F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066B8C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066B924.s")

s32 func_8066B9F4(void *arg0) {
    return func_8066BB44(D_807F9628[func_8066C2B4(arg0)], arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066BA2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066BAB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066BB44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066BC00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066BC5C.s")

typedef struct global_asm_struct_40 GlobalASMStruct40;

struct global_asm_struct_40 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    s8 unk11;
    s8 unk12;
    s8 unk13;
    GlobalASMStruct40 *unk14; // Doubly linked list?
    GlobalASMStruct40 *unk18; // Doubly linked list?
};

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    s8 unk11;
    s8 unk12;
    s8 unk13;
} GlobalASMStruct65;

/*
// TODO: Quite close, similar issue as below
GlobalASMStruct40 *func_8066BC5C(GlobalASMStruct40 *arg0, u32 arg1, s32 *arg2, s32 *arg3) {
    GlobalASMStruct40 *phi_s0;

    // phi_s0 = arg0;
    if (arg0) {
        if (arg1 == arg0->unk0) {
            *arg2 = arg0->unk4;
            *arg3 = arg0->unk8;
            if (!arg0->unk14 && !arg0->unk18) {
                func_8061130C(arg0);
                arg0 = NULL;
            } else {
                if (!arg0->unk14) {
                    arg0 = arg0->unk18;
                    func_8061130C(arg0);
                } else if (!arg0->unk18) {
                    arg0 = arg0->unk14;
                    func_8061130C(arg0);
                } else {
                    arg0->unk18 = func_8066BD54(arg0->unk18, arg0, &arg0->unk4, &arg0->unk8, &arg0->unkC, &arg0->unk10);
                }
            }
        } else if (arg0->unk0 < arg1) {
            arg0->unk18 = func_8066BC5C(arg0->unk18, arg1, arg2, arg3);
        } else {
            arg0->unk14 = func_8066BC5C(arg0->unk14, arg1, arg2, arg3);
        }
    }
    return arg0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066BD54.s")

/*
// TODO: a0/s0 mixup in one spot... Not sure how to fix
GlobalASMStruct40 *func_8066BD54(GlobalASMStruct40 *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4, s8 *arg5) {
    GlobalASMStruct40 *pad;

    if (!arg0->unk14) {
        *arg1 = arg0->unk0;
        *arg2 = arg0->unk4;
        *arg3 = arg0->unk8;
        *arg4 = arg0->unkC;
        *arg5 = arg0->unk10;
        arg0 = arg0->unk18;
        func_8061130C(arg0);
    } else {
        arg0->unk14 = func_8066BD54(arg0->unk14, arg1, arg2, arg3, arg4, arg5);
    }
    return arg0;
}
*/

void func_8066BE20(s32);
void func_8066BECC(GlobalASMStruct40 *arg0);
GlobalASMStruct40 *func_8066BF0C(GlobalASMStruct65 *arg0, s32 arg1, s32 arg2);

void func_8066BDE0() {
    int i;
    for (i = 0; i < 0x14; i++) {
        func_8066BE20(i);
    }
}

void func_8066BE20(s32 arg0) {
    s32 temp_v0;
    s32 *sp30;
    s32 sp2C;
    s32 sp28;

    sp28 = 0;
    temp_v0 = func_8066B75C(D_807F9628[arg0]);
    if (temp_v0 != 0) {
        sp30 = malloc(temp_v0 * sizeof(GlobalASMStruct65));
        func_8066BFF0(D_807F9628[arg0], sp30, &sp28);
        func_8066C0DC(sp30, 0, temp_v0 - 1);
        sp2C = func_8066BF0C(sp30, 0, temp_v0 - 1);
        func_8066BECC(D_807F9628[arg0]);
        D_807F9628[arg0] = sp2C;
        func_8061130C(sp30);
    }
}

// Recursion :O
void func_8066BECC(GlobalASMStruct40 *arg0) {
    if (arg0) {
        func_8066BECC(arg0->unk14);
        func_8066BECC(arg0->unk18);
        func_8061130C(arg0);
    }
}

GlobalASMStruct40 *func_8066BF0C(GlobalASMStruct65 *arg0, s32 arg1, s32 arg2) {
    GlobalASMStruct40 *temp_v0;
    s32 temp_t7;

    temp_v0 = malloc(sizeof(GlobalASMStruct40));
    temp_t7 = (arg1 + arg2) / 2;
    temp_v0->unk0 = arg0[temp_t7].unk0;
    temp_v0->unk4 = arg0[temp_t7].unk4;
    temp_v0->unk8 = arg0[temp_t7].unk8;
    temp_v0->unkC = arg0[temp_t7].unkC;
    temp_v0->unk10 = arg0[temp_t7].unk10;
    if (arg1 != temp_t7) {
        temp_v0->unk14 = func_8066BF0C(arg0, arg1, temp_t7 - 1);
    } else {
        temp_v0->unk14 = NULL;
    }
    if (arg2 != temp_t7) {
        temp_v0->unk18 = func_8066BF0C(arg0, temp_t7 + 1, arg2);
    } else {
        temp_v0->unk18 = NULL;
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066BFF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066C0DC.s")

u32 func_8066C2B4(u32 arg0) {
    return (u32) (arg0 >> 0xC) % 0x14U;
}