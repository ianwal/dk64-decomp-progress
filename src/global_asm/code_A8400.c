#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_80720A10;
extern s32 D_807209EC;
extern s32 D_807207E0;
extern s32 D_80720A34;
extern s32 D_80720A58;

extern s32 D_807204BC;
extern s32 D_80720508;
extern s32 D_807205C4;
extern s32 D_807205E8;
extern s32 D_80720768;
extern s32 *D_807207BC;
extern s32 D_807211D0;
extern s32 D_80721378;
extern f32 D_8075A9B0;
extern f32 D_8075A9B4;

extern s32 D_80720710;

extern s32 D_80720FE0;
extern s32 D_80720F98;
extern s32 D_80720FBC;
extern s32 D_80721028;
extern s32 D_80721004;
extern f32 D_8075AA70;
extern f32 D_8075AA74;

void func_80686A5C(Actor *arg0, f32 arg1, f32 arg2, s32 arg3);
void func_80665564(Actor *arg0, f32 arg1);
void func_806A6DB4(s32 arg0);
void func_806086CC(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, f32 arg8, s32 arg9);
void func_8065D254(Actor *actor, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, f32 arg10);
void func_80686CF8(Actor *actor);
void func_806319C4(Actor *arg0, s32 arg1);

void func_806A664C(f32 arg0);
void func_80714A08(f32 arg0, f32 arg1);

void func_806A3700(s32 arg0, s32 arg1) {

}

// Displaylist and matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A370C.s")

extern f32 D_8075A760;
extern f64 D_8075A790;

extern f64 D_8075A798;
extern f32 D_8075A7A0;
extern f32 D_8075A7A4;
extern f64 D_8075A7A8;

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
    Struct806A57C0_2 *unk1C;
};

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    Struct806A57C0_2 *unkC; // Used
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14; // Used
    s32 unk18;
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

void func_806A3B78(s32 *arg0, AAD_806A4DDC *arg1, Struct806A57C0_2 *arg2, u8 arg3, u8 *arg4) {
    s32 sp44;
    s32 i;
    Struct806A57C0_3 *var_s0;

    sp44 = *arg0;
    var_s0 = arg2->unkC;
    i = 0;
    while ((var_s0 != NULL) && (*arg4 == 0)) {
        if (arg3 && (i == arg1->unk11)) {
            *arg4 = 1;
        }
        if (arg2->unk0 & 1) {
            func_806A370C(&sp44, arg1, arg2, var_s0);
        }
        var_s0 = var_s0->unkA0;
        i += 1;
    }
    *arg0 = sp44;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A3C6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A3DA0.s")

void func_806A3DA0(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, AAD_806A4DDC *arg4);

/*
// TODO: Very close, sp20 gets stored in sp24...
void func_806A3DA0(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, AAD_806A4DDC *arg4) {
    f32 sp20;

    sp20 = arg2 * D_8075A760;
    *arg0 += arg2 * arg3 * 24.0f * func_80612794((s16)(arg4->unk38 + sp20) & 0xFFF);
    *arg1 += arg2 * arg3 * 16.0f * func_80612790((s16)(arg4->unk3A + sp20) & 0xFFF);
}
*/

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A3E9C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A4284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A495C.s")

/*
void func_806A495C(void *arg0, void *arg1, void *arg2) {
    f32 sp38;
    f32 sp34;
    f32 sp30;
    void *sp2C;
    f32 temp_f2;
    s32 temp_v0;
    void *temp_v1;
    void *temp_v1_2;

    sp38 = arg0->unk0 * 0.5f;
    temp_f2 = arg0->unk4;
    sp34 = temp_f2;
    sp30 = arg0->unk8;
    if (arg0->unk14 == 0) {
        sp34 = temp_f2;
        func_807149FC(-1);
        func_807149B8(0);
        func_8071495C();
        func_80714998(2);
        func_80714A68(arg2->unk44, arg2->unk48, arg2->unk4C, arg2->unk50);
        temp_v1 = arg0 + 0x10;
        sp2C = temp_v1;
        temp_v0 = func_80714CC0(((temp_v1->unk0 * 4) + 0x80750000)->unk5390, 1.0f, arg2->unk44, arg2->unk48, 1.0f);
        temp_v1->unk4 = temp_v0;
        if (temp_v1->unk2 != 0) {
            temp_v0->unk360 = temp_v0->unk360 * -1.0f;
        }
    }
    temp_v1_2 = arg0 + 0x10;
    temp_v1_2->unk4->unk340 = (arg2->unk44 + (sp34 + sp38)) * 4.0;
    temp_v1_2->unk4->unk344 = (arg2->unk48 + (sp30 + (arg1->unk18 * 0.5f))) * 4.0;
    temp_v1_2->unk4->unk36D = arg0->unk3;
    temp_v1_2->unk4->unk38E = arg2->unk44;
    temp_v1_2->unk4->unk390 = arg2->unk48;
    temp_v1_2->unk4->unk392 = arg2->unk4C;
    temp_v1_2->unk4->unk394 = arg2->unk50;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A4B84.s")

void func_8070D9AC(void *arg0);
void func_806A4B84(f32 arg0, Actor *arg1, AAD_806A4DDC *arg2, Struct806A57C0_2 *arg3, u8 arg4, u8 *arg5);

/*
// TODO: Progress made, fiddly
void func_806A4B84(f32 arg0, Actor *arg1, AAD_806A4DDC *arg2, Struct806A57C0_2 *arg3, u8 arg4, u8 *arg5) {
    f32 var_f20;
    s32 var_a0;
    s32 i;
    u8 var_a0_2;
    Struct806A57C0_3 *var_s0;

    i = 0;
    var_s0 = arg3->unkC;
    var_f20 = (D_8075A790 - arg3->unk14) * 0.5;
    while ((var_s0 != NULL) && (*arg5 == 0)) {
        if ((arg4 != 0) && (i == arg2->unk11)) {
            if (!(arg2->unk55 & 4)) {
                *arg5 = 1;
            }
            if (arg1->control_state == 1) {
                if ((i == 0) && (var_s0->unk2 == 0)) {
                    func_806A3700(arg2->unk4, arg3->unk8);
                }
                if (var_s0->unk2 != 0xFF) {
                    var_a0 = 0x96;
                    if (arg2->unk55 & 2) {
                        var_a0 = 0x96 * 0.5;
                    }
                    if (!(arg2->unk55 & 4) && (var_a0 < (0xFF - var_s0->unk2))) {
                        var_s0->unk2 += var_a0;
                    } else {
                        var_s0->unk2 = 0xFF;
                        if (var_s0->unkA0 != NULL) {
                            arg2->unk11++;
                        } else {
                            arg2->unk11 = 0;
                            arg2->unk10++;
                            *arg5 = 1;
                            if (arg3->unk10 != 0) {
                                arg1->control_state = 3;
                                arg2->unk12 = arg3->unk10;
                            }
                        }
                    }
                }
            }
        }
        var_a0_2 = MIN(arg2->unk1D, var_s0->unk2);
        var_s0->unk4 = var_f20;
        var_s0->unk8 = arg0;
        var_s0->unk3 = var_a0_2;
        if (arg3->unk0 & 2) {
            func_806A495C(var_s0, arg3, arg2);
        }
        var_f20 += var_s0->unk0;
        var_s0 = var_s0->unkA0;
        i += 1;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A4DDC.s")

/*
// TODO: Progress made, fiddly
void func_806A4DDC(Actor *arg0) {
    u8 sp103;
    f32 sp50;
    f32 temp_f2_5;
    f32 var_f0;
    f32 var_f22;
    f64 temp_f0;
    f64 temp_f2;
    s32 var_s0;
    u8 var_v0;
    void *temp_a0;
    void *temp_a3;
    AAD_806A4DDC *aaD;
    Struct806A57C0_2 *var_s1;

    aaD = arg0->additional_actor_data;
    var_s1 = aaD->unkC;
    sp103 = FALSE;
    var_f0 = (1.0f - aaD->unk20) * D_8075A798;
    if (var_f0 > 1.0f) {
        var_f0 = 1.0f;
    }
    aaD->unk40 = var_f0;
    func_806A3DA0(&arg0->x_position, &arg0->y_position, aaD->unk20, var_f0, aaD);
    temp_f0 = (aaD->unk20 * D_8075A7A0) * 0.5;
    aaD->unk44 = arg0->x_position - temp_f0;
    temp_f2 = (aaD->unk20 * D_8075A7A4) * 0.5;
    aaD->unk48 = arg0->y_position - temp_f2;
    aaD->unk4C = arg0->x_position + temp_f0;
    aaD->unk50 = arg0->y_position + temp_f2;

    aaD->unk44 = MAX(aaD->unk44, character_change_array->unk270);
    aaD->unk48 = MAX(aaD->unk48, character_change_array->unk272);
    aaD->unk4C = MAX(aaD->unk4C, character_change_array->unk274);
    aaD->unk50 = MAX(aaD->unk50, character_change_array->unk276);

    var_f22 = aaD->unk14;
    var_s0 = 0;
    while ((aaD->unk10 >= var_s0) && (var_s1 != NULL) && (sp103 == 0)) {
        temp_f2_5 = var_f22 + var_s1->unk18;
        if ((D_8075A7A8 < temp_f2_5) && (arg0->control_state == 1)) {
            arg0->control_state = 2;
            aaD->unk18 = temp_f2_5 - D_8075A7A8;
            sp103 = TRUE;
        } else {
            temp_a3 = var_s1;
            if ((temp_f2_5 < 0.0f) && (arg0->control_state == 2)) {
                temp_a0 = var_s1;
                var_s0 -= 1;
                var_f22 = temp_f2_5;
                aaD->unk14 = aaD->unk14 + var_s1->unk18;
                aaD->unkC = var_s1->unk1C;
                aaD->unk10 = aaD->unk10 - 1;
                var_s1 = var_s1->unk1C;
                func_8070D9AC(temp_a0);
            } else {
                sp50 = temp_f2_5;
                func_806A4B84(var_f22, arg0, aaD, temp_a3, (var_s0 == aaD->unk10), &sp103);
                if (sp103 == 0) {
                    var_s1 = var_s1->unk1C;
                    var_f22 = sp50;
                }
            }
        }
        var_s0 += 1;
    }
    var_v0 = arg0->control_state;
    if (var_v0 == 3) {
        var_v0 = 1 & 0xFF;
        if (aaD->unk12 != 0) {
            aaD->unk12--;
            var_v0 = arg0->control_state;
        } else {
            arg0->control_state = 1;
        }
    }
    if ((var_v0 == 1) && (var_s1 == NULL)) {
        func_8070E808(arg0, aaD->unk4);
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A5174.s")

extern f64 D_8075A978;

void func_806A57C0(AAD_806A4DDC *arg0) {
    s32 var_v0;
    Struct806A57C0_2 *var_v1;

    var_v0 = 0;
    var_v1 = arg0->unkC;
    if ((var_v1 != NULL) && (var_v1->unkC->unk2 == 0)) {
        while (var_v1 != NULL) {
            var_v0 += var_v1->unk18;
            var_v1 = var_v1->unk1C;
        }
        if (var_v0 < D_8075A978) {
            arg0->unk14 = (D_8075A978 - var_v0) * 0.5;
        } else {
            arg0->unk14 = 6.0f;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A5868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A5C60.s")

typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4;
    u8 unk5;
} Struct80750400;

extern Struct80750400 D_80750400[];

void func_806A5DF0(s16, f32, f32, f32, s32, s32, s32, s32);

/*
// TODO: Progrss made, kinda fiddly, last loop is sus
void func_806A5C60(Actor *arg0) {
    s32 var_a1;
    s32 j;
    s16 var_s3;
    s32 i;
    u8 temp_v0;

    i = 0;
    var_a1 = FALSE;
    var_s3 = 0;
    if ((cc_number_of_players < 2) && !(D_807FBB64 & 0x4000)) {
        while (var_a1 == 0 && D_80750400[i].unk0 != 0) {
            if (arg0->unk58 == D_80750400[i].unk0) {
                var_a1 = TRUE;
            } else {
                i++;
            }
        }
        if (var_a1 != FALSE) {
            if (D_80750400[i].unk4 != 0) {
                playSong(D_80750400[i].unk4, 1.0f);
            }
            for (j = 0; j < D_80750400[i].unk5; j++) {
                func_806A5DF0(D_80750400[i].unk2, arg0->x_position, arg0->y_position, arg0->z_position, var_s3, 1, -1, 0);
                var_s3 += (0xFFF / D_80750400[i].unk5);
            }
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A5DF0.s")

extern f32 D_8075A9A0;
extern s32 D_807FBB68;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk1C;
    s32 unk18;
} Struct807500B4;

void func_806891D8(s16 arg0, f32 arg1, f32 arg2, s32 arg3, s16 arg4, f32 arg5, s32 arg6, Struct807500B4 *arg7);

/*
// TODO: Kinda close, datatypes on params are sus
void func_806A5DF0(s16 arg0, f32 arg1, f32 arg2, s32 arg3, s16 arg4, u8 arg5, s16 arg6, s32 arg7) {
    Struct807500B4 sp2C;
    f32 var_f0;

    var_f0 = D_8075A9A0;
    if (D_807FBB68 & 0x10) {
        var_f0 = 2.0f * D_8075A9A0;
    }
    sp2C.unk0 = arg5;
    sp2C.unk4 = arg4;
    sp2C.unk8 = arg6;
    func_806891D8(arg0, arg1, arg2, arg3, 0, var_f0, arg7, &sp2C);
}
*/

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
} AAD_806A5EAC;

extern s32 D_807FBB68;
extern f64 D_8075A9A8;

s32 func_80714C08(s32 arg0, f32 arg1, Actor *arg2, s32 arg3, u8 arg4);
void func_807149FC(s32 arg0);

void func_806A5EAC(AAD_806A5EAC *arg0, s32 arg1, f32 arg2) {
    if (D_807FBB68 & 0x10) {
        arg2 *= 2.0f;
    }
    func_807149FC(-1);
    func_807149B8(1);
    func_80714998(2);
    arg0->unk4 = func_80714C08(arg1, arg2 * D_8075A9A8, current_actor_pointer, 1, 2);
}

void func_806A5F44(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_806A5EAC(sp1C, &D_80720710, 1.0f);
    }
}

void func_806A5FA4(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_806A5EAC(sp1C, &D_80720508, 1.0f);
    }
}

void func_806A6004(void *arg0, s32 arg1) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (arg1 != player_pointer->unk58) {
            func_807149C8(0xFF, 0xFF, 0xFF, 0x64);
        }
        func_806A5EAC(sp1C, arg0, 1.0f);
    }
}

void func_806A6094(void) {
    func_806A6004(&D_807209EC, 3);
}

void func_806A60BC(void) {
    func_806A6004(&D_80720A10, 6);
}

void func_806A60E4(void) {
    func_806A6004(&D_807207E0, 4);
}

void func_806A610C(void) {
    func_806A6004(&D_80720A34, 2);
}

void func_806A6134(void) {
    func_806A6004(&D_80720A58, 5);
}

void func_806A615C(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_80714A08(D_8075A9B0, D_8075A9B4);
        func_806A5EAC(sp1C, &D_80720768, 1.0f);
    }
}

void func_806A61D0(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_806A5EAC(sp1C, &D_807204BC, 1.0f);
    }
}

void func_806A6230(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    s32 temp_v1;

    func_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        temp_v1 = D_807FBB64; // shadow_display_bitfield, shockwave_bitfield, long_distance_actor_spawn
        if (((temp_v1 << 0xC) < 0) || (temp_v1 & 0x2000)) {
            current_actor_pointer->unk15F = 1;
        }
        func_806A5EAC(sp1C, &D_807207BC, 1.0f);
    }
}

void func_806A62B4(void) {
    func_806A6230();
}

void func_806A62D4(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_807149C8(0xFF, 0xFF, 0, 0xFF);
        func_806A5EAC(sp1C, &D_807211D0, 1.5f);
    }
}

void func_806A6348(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_806A5EAC(sp1C, &D_807205C4, 1.0f);
    }
}

void func_806A63A8(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_806A5EAC(sp1C, &D_807205E8, 1.0f);
    }
}

void func_806A6408(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(12.0f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_806A5EAC(sp1C, &D_80721378, 2.0f);
    }
}

// jumptable :(
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A6468.s")

// jumptable :(
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A6574.s")

// jumptable :(
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A664C.s")

// jumptable :(
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A6DB4.s")

void func_806A734C(void) {
    func_806A6DB4(1);
}

void func_806A736C(void) {
    PlayerAdditionalActorData *PaaD = current_actor_pointer->PaaD;
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->unk64 |= 4;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        func_80686CF8(current_actor_pointer);
    }
    // TODO: Get rid of typecasts
    if ((u16)PaaD->unk8 == 1) {
        func_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x73, 0xFF, 0x7F, 1, 0, 0.0f, 0);
        playSong(0x3B, 0.7f);
    } else if ((u16)PaaD->unk8 == 0xA) {
        func_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x19C, 0xB4, 0x7F, 1, 0, 0.0f, 0);
    }
    func_806A6DB4(0);
    if (current_actor_pointer->y_position < current_actor_pointer->unkAC) {
        current_actor_pointer->unkB8 = 0.0f;
        current_actor_pointer->y_position = current_actor_pointer->unkAC;
        current_actor_pointer->y_velocity = current_actor_pointer->y_acceleration;
    }
    func_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x1E, 0x1E, 1, 0x96, 0x78, 0, 1.0f);
}

void func_806A7518(void) {
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->object_properties_bitfield |= 0x400;
        func_80686A5C(current_actor_pointer, 20.0f, 40.0f, 0x1E);
        current_actor_pointer->floor = D_8075AA70;
        func_80665564(current_actor_pointer, 0.0f);
    }
    func_806A6DB4(0);
    if (D_8075AA74 != current_actor_pointer->floor) {
        func_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x19, 0x19, 1, 0x96, 0x78, 0, 1.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A7600.s")

extern u8 D_807FBD70;
extern s32 D_8076A068;
extern s32 D_8071EB70;

s32 func_80723020(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6);
s16 func_80688E68(Actor *arg0);
s16 func_80688C30(u16 arg0);
void func_8066EB40(Actor*, f32);
void func_8066E8E4(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
void func_8066E854(Actor*, f32, f32, f32, s32);

typedef struct {
    s8 unk0;
    u8 unk1;
    s8 unk2;
    u8 unk3;
    u16 unk4;
    s16 unk6;
} AAD_806A7600;

/*
// TODO: Regalloc :(
void func_806A7600(s32 arg0) {
    AAD_806A7600 *sp34;
    s32 temp_t8;
    s16 permanentFlagIndex;
    s32 var_a0_2;
    s32 var_v0;

    sp34 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (current_actor_pointer->unk58 == 0x93) {
            sp34->unk6 = -1;
        } else {
            sp34->unk6 = func_80688C30(func_80688E68(current_actor_pointer));
        }
        if ((sp34->unk6 != -1) && (isFlagSet(sp34->unk6, FLAG_TYPE_PERMANENT) != FALSE)) {
            func_806782C0(current_actor_pointer);
            return;
        }
        func_8066E854(current_actor_pointer, 0, 0, 0, -1);
        func_8066EB40(current_actor_pointer, 175.0f);
        func_8066E8E4(current_actor_pointer, 0, 12.0f, 0, 80.0f, -1);
        temp_t8 = current_actor_pointer->unk124->unk0_s32;
        sp34->unk0 = temp_t8;
        sp34->unk1 = current_actor_pointer->unk124->unk4_s32;
        sp34->unk2 = func_80723020(current_actor_pointer, temp_t8 & 0xFF, 0, 0.0f, 0.0f, 0.0f, 0);
        if (sp34->unk2 != -1) {
            func_807232B8(sp34->unk2, 1);
            func_80723284(sp34->unk2, sp34->unk1);
            func_80723320(sp34->unk2, -1);
            func_8072334C(sp34->unk2, 1);
        }
        sp34->unk4 = 0;
        return;
    }
    if (sp34->unk2 != -1) {
        func_80723484(sp34->unk2, current_actor_pointer);
        func_807238D4(sp34->unk2, &current_actor_pointer->x_position, &current_actor_pointer->y_position, &current_actor_pointer->z_position);
    }
    current_actor_pointer->y_position += (5.0 * func_80612794(sp34->unk4));
    sp34->unk4 = (sp34->unk4 + 0x50) & 0xFFF;
    if ((D_8076A068 % 24U) == 0) {
        switch (current_actor_pointer->unk58) {
            default:
                permanentFlagIndex = -1;
                break;
            case 0x5B: // Balloon (Diddy)
                permanentFlagIndex = 6;
                break;
            case 0x6F: // Balloon (Chunky)
                permanentFlagIndex = 0x75;
                break;
            case 0x70: // Balloon (Tiny)
                permanentFlagIndex = 0x42;
                break;
            case 0x71: // Balloon (Lanky)
                permanentFlagIndex = 0x46;
                break;
        }
        if ((permanentFlagIndex == -1) || (isFlagSet(permanentFlagIndex, FLAG_TYPE_PERMANENT) != FALSE)) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            func_807149B8(1);
            var_a0_2 = TRUE;
            if (current_actor_pointer->unk58 == 0x93) {
                var_a0_2 = FALSE;
            } else if ((player_pointer->unk58 == 3) && (current_actor_pointer->unk58 == 0x5B)) {
                var_a0_2 = FALSE;
            } else if ((player_pointer->unk58 == 6) && (current_actor_pointer->unk58 == 0x6F)) {
                var_a0_2 = FALSE;
            } else if ((player_pointer->unk58 == 5) && (current_actor_pointer->unk58 == 0x70)) {
                var_a0_2 = FALSE;
            } else if ((player_pointer->unk58 == 4) && (current_actor_pointer->unk58 == 0x71)) {
                var_a0_2 = FALSE;
            } else if ((player_pointer->unk58 == 2) && (current_actor_pointer->unk58 == 0x72)) {
                var_a0_2 = FALSE;
            }
            if (var_a0_2 != 0) {
                func_807149C8(0xFF, 0xFF, 0xFF, 0x96);
            } else {
                func_8071498C(&D_8071EB70);
                func_80714950(0x226);
            }
            func_80714A28(4);
            func_80714998(3);
            func_80714C08(arg0, 0.8f, current_actor_pointer, 1, 2);
            current_actor_pointer->noclip_byte = 2;
        } else {
            current_actor_pointer->noclip_byte = 1;
        }
    }
    if (D_807FBD70 == 4) {
        func_80686CF8(current_actor_pointer);
        func_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x2BF, 0xFF, 0x7F, 0x1E, 0, 0.0f, 0);
        func_806782C0(current_actor_pointer);
        if (current_actor_pointer->unk58 == 0x93) {
            func_80724994(3, 1, 0x27, 0, 0);
            return;
        }
        if (sp34->unk6 != -1) {
            setFlag(sp34->unk6, TRUE, FLAG_TYPE_PERMANENT);
        }
        func_806F8BC4(0, 0, 0);
        func_806F91B4(0, 0, 0xA);
    }
}
*/

void func_806A7B04(void) {
    func_806A7600(&D_80720FBC);
}

void func_806A7B28(void) {
    func_806A7600(&D_80720F98);
}

void func_806A7B4C(void) {
    func_806A7600(&D_80721028);
}

void func_806A7B70(void) {
    func_806A7600(&D_80721004);
}

void func_806A7B94(void) {
    func_806A7600(&D_80720FE0);
}

void func_806A7BB8(void) {
    func_806A7600(&D_80721004);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A7BDC.s")

extern f32 D_807504C4;
extern u8 D_807504D0;
extern u8 D_807504CC;
extern f32 D_807504C0;
extern u8 D_807504C8;

typedef struct {
    f32 unk0;
    s16 unk4;
} AAD_806A7EF0;

void func_80611690(void*);

void func_806A7EF0(void) {
    AAD_806A7EF0 *aaD;
    AnimationStateUnk20 *temp_v0_2;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->animation_state->unk20 = malloc(0x20);
        func_80611690(current_actor_pointer->animation_state->unk20);
        aaD->unk4 = 0;
        aaD->unk0 = 1.0f;
        current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
        current_actor_pointer->object_properties_bitfield |= 0x40000000;
        current_actor_pointer->shadow_opacity = D_807504CC;
    }
    if (D_807504D0 < current_actor_pointer->shadow_opacity) {
        current_actor_pointer->shadow_opacity -= D_807504D0;
    }
    aaD->unk4++;
    if (D_807504C4 < aaD->unk4) {
        func_806782C0(current_actor_pointer);
        return;
    }
    aaD->unk0 *= D_807504C0;
    temp_v0_2 = current_actor_pointer->animation_state->unk20;
    temp_v0_2->unk0 = D_807504C8;
    temp_v0_2->unk1 = 0xFF;
    temp_v0_2->unk4 = aaD->unk0;
    temp_v0_2->unk8 = aaD->unk0;
    temp_v0_2->unkC = aaD->unk0;
    temp_v0_2->unk10 = 0xFF;
    func_806319C4(current_actor_pointer, 0);
}

void func_806A8070(void) {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield |= 0x40000000;
    }
    func_806319C4(current_actor_pointer, 0);
}
