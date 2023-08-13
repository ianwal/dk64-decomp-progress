#include <ultra64.h>
#include "functions.h"

typedef struct menu_struct_0 {
    u8  unk0;
    u8  unk1;
    u8  pad2;
    u8  pad3;
    u8  pad4;
    u8  pad5;
    u8  unk6;
    u8  unk7;
    otherSpriteControl *unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
} MenuStruct0;

extern s32 D_global_asm_80720268;
extern s16 D_global_asm_80750AC8;

typedef struct {
    s32 unk0[6]
} Struct80032F48;

extern Struct80032F48 D_menu_80032F48[];
extern s32 D_menu_800330A0[];

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

void func_menu_80024000(MenuStruct80024000 *arg0) {
    s32 temp_v1;

    temp_v1 = D_menu_80032F48[getLevelIndex(D_global_asm_8076A0AB, 0)].unk0[arg0->unk1];
    if (temp_v1 == 0) {
        func_global_asm_8063DA40(D_menu_800330A0[arg0->unk1A], 9);
        arg0->unk0 = 4;
        arg0->unk1 = 0;
        return;
    }
    if (temp_v1 == 4) {
        arg0->unk6 = 1;
    }
    playCutscene(NULL, temp_v1, 1);
    arg0->unk1++;
}

void func_menu_800240BC(MenuStruct0 *arg0) {
    arg0->unk10 = 11.35f;
    arg0->unkC = -6.55f;
    arg0->unk14 = 6.6f;
    arg0->unk6 = 0;
    func_global_asm_80714998(0);
    func_global_asm_807149B8(1);
    func_global_asm_807149FC(-1);
    func_global_asm_80714998(0);
    arg0->unk8 = func_global_asm_80714CC0(&D_global_asm_80720268, 0.3f, 181.0f, 3.0f, 82.0f);
}

void func_menu_80024154(MenuStruct0 *arg0) {
    otherSpriteControl *sprite = arg0->unk8;

    sprite->xPos += arg0->unkC;
    sprite->unk_348 += arg0->unk14;
    arg0->unk10 += -1.0f;
    sprite->yPos += arg0->unk10;
    arg0->unk6++;
    if (arg0->unk6 >= 0x16) {
        arg0->unk6 = 0;
        func_global_asm_80715908(arg0->unk8);
        arg0->unk8 = NULL;
    }
}

void func_menu_800241E8(void) {
    func_global_asm_806CFF9C(player_pointer);
    func_global_asm_805FF898();
    playCutscene(NULL, 7, 1);
}

void func_menu_80024224(MenuStruct0 *arg0, s32 arg1) {
    s32 var_v0;
    s32 temp;

    switch (arg0->unk1) {
        case 0:
            if (func_global_asm_80629148() != 0) {
                if (arg1 != 0) {
                    func_global_asm_80629174();
                    func_global_asm_8070D8C0(current_actor_pointer, 0xB, 0);
                    temp = arg0->unk1A;
                    if (temp == 1) {
                        var_v0 = 1;
                    } else if (temp > 1) {
                        var_v0 = 2;
                    } else {
                        var_v0 = 3;
                    }
                    D_global_asm_80750AC8 = arg0->unk1A;
                    func_global_asm_8070D8C0(current_actor_pointer, 0xB, var_v0);
                } else {
                    if (arg0->unk1A == 1) {
                        var_v0 = 5;
                    } else {
                        var_v0 = 6;
                    }
                    D_global_asm_80750AC8 = arg0->unk1A;
                    func_global_asm_8070D8C0(current_actor_pointer, 0xB, var_v0);
                }
                arg0->unk1++;
            }
            break;
        case 1:
            if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                func_global_asm_8061CB08();
                arg0->unk1++;
            }
            break;
        case 2:
            if (func_global_asm_80629148() != 0) {
                func_global_asm_80629174();
                if (arg0->unk1A != 0) {
                    playCutscene(NULL, 5, 1);
                    arg0->unk1 = arg0->unk1 + 1;
                } else {
                    arg0->unk0 = 4;
                    arg0->unk1 = 0;
                }
            }
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            if (arg0->unk6 != 0) {
                if (arg0->unk6 == 1) {
                    if (func_global_asm_80629148() != 0) {
                        func_global_asm_80629174();
                        arg0->unk6 = 2;
                    }
                } else {
                    func_menu_80024154(arg0);
                }
            }
            if (func_global_asm_80629148() != 0) {
                func_global_asm_80629174();
                func_menu_80024000(arg0);
            }
            break;
    }
}

void func_menu_80024418(MenuStruct0 *arg0, s32 arg1) {
    switch (arg0->unk1) {
        case 0:
            if (func_global_asm_80629148()) {
                func_global_asm_8070D8C0(current_actor_pointer, 0xB, arg1);
                arg0->unk1++;
            }
            break;
        case 1:
            // TODO: Use proper bitfield syntax
            if ((s32)current_actor_pointer->object_properties_bitfield << 6 >= 0) {
                func_global_asm_8061CB08();
                arg0->unk1++;
            }
            break;
        case 2:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                arg0->unk0 = 4;
                arg0->unk1 = 0;
            }
            break;
    }
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_menu_800244EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_menu_80024788.s")

extern s16 D_menu_800330D8;
extern s8 D_menu_80032F50;

typedef struct {
    u8 unk0;
    u8 unk1; // Used
    u8 unk2;
    u8 unk3;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    s8 unk18; // Used
    s8 unk19; // Used
} Struct80024788;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    s8 unk3; // Used
} Struct807ECDEC;

extern Struct807ECDEC *D_global_asm_807ECDEC;
extern u8 D_menu_800330C0[];

void func_menu_800244EC();

/*
// TODO: Doable, good progress made
void func_menu_80024788(Struct80024788 *arg0) {
    s32 temp_v0;
    s32 sp40;
    CharacterProgress *sp3C;
    s32 var_s0_3;
    s32 temp_a0;
    s32 var_s0_2;
    s32 var_v0;
    s32 var_t5;

    sp40 = 0;
    D_menu_800330D8 = 0;
    switch (arg0->unk1) {
        case 0x2:
        case 0x37:
            break;
        case 0x0:
            if (func_global_asm_806F70A8(4) != 0) {
                sp3C = &D_global_asm_807FC950->character_progress[*current_character_index];
                for (var_s0_2 = 0; var_s0_2 < 8; var_s0_2++) {
                    if (isFlagSet(func_global_asm_807319D8(0x1D5, var_s0_2, *current_character_index), FLAG_TYPE_PERMANENT) != 0) {
                        temp_v0 = func_global_asm_807319D8(0x1FD, var_s0_2, *current_character_index);
                        if (isFlagSet(temp_v0, FLAG_TYPE_PERMANENT) == FALSE) {
                            setFlag(temp_v0, TRUE, FLAG_TYPE_PERMANENT);
                            sp3C->golden_bananas[var_s0_2] += 1;
                            sp40 = 1;
                        }
                    }
                }
                func_global_asm_806F8278(0);
            }
            if (sp40 != 0) {
                // Save the game
                func_global_asm_8060DEC8();
            }
            if (func_global_asm_8061CB50() == 0) {
                arg0->unk1++;
                func_global_asm_806EB0C0(0x55, NULL, 0);
            }
            break;
        case 0x1:
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                current_actor_pointer->unk15F = 0;
                arg0->unk1 = 3;
            } else {
                arg0->unk19 = 1;
                for (var_s0_3 = 0x1FD; var_s0_3 < 0x225; var_s0_3++) {
                    if (isFlagSet(var_s0_3, FLAG_TYPE_PERMANENT) == FALSE) {
                        arg0->unk19 = 0;
                        var_s0_3 = 0x224;
                    }
                }
                if (0xFF - current_actor_pointer->unk15F >= 9) {
                    var_v0 = 8;
                } else {
                    var_v0 = 0xFF - current_actor_pointer->unk15F;
                }
                current_actor_pointer->unk15F += var_v0;
                func_global_asm_8068C350(&func_menu_800244EC, current_actor_pointer, 3);
                if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
                    func_menu_800241E8();
                    arg0->unk1 = 2;
                } else if ((arg0->unk19 != 0) && (D_global_asm_807FD610[cc_player_index].unk2C & U_CBUTTONS)) {
                    arg0->unk1 = 4;
                }
            }
            break;
        case 0x3:
            D_menu_800330D8 = 1;
            if (D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | B_BUTTON)) {
                arg0->unk1 = 1;
            }
            break;
        default:
            if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
                var_t5 = 1;
            } else {
                if ((D_global_asm_807ECDEC->unk3 >= 0x29) && (arg0->unk18 < 0x29)) {
                    arg0->unk1--;
                    playSound(0x2A0, 0x7FFF, 64.0f, 1.0f, 0, 0);
                }
                if ((D_global_asm_807ECDEC->unk3 < -0x28) && (arg0->unk18 >= -0x28)) {
                    arg0->unk1++;
                    playSound(0x2A0, 0x7FFF, 64.0f, 1.0f, 0, 0);
                }
                var_t5 = ((arg0->unk1 - 4) & 7) + 4;
            }
            arg0->unk1 = var_t5;
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                func_global_asm_80712774(D_menu_800330C0[var_t5]);
                D_menu_80032F50 = 1;
                arg0->unk1 = 0x37;
            }
            func_global_asm_8068C350(&func_menu_800244EC, current_actor_pointer, 3);
            break;
    }
    arg0->unk18 = D_global_asm_807ECDEC->unk3;
}
*/

void func_menu_80024BFC(MenuStruct0 *arg0) {
    switch (arg0->unk1) {
        case 0:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                arg0->unk1++;
                D_global_asm_80750AC8 = func_global_asm_80712548();
                func_global_asm_8070D8C0(current_actor_pointer, 0xB, 8);
            }
            break;
        case 1:
            // TODO: Use proper bitfield syntax
            if (((s32)current_actor_pointer->object_properties_bitfield << 6) >= 0) {
                func_global_asm_8061CB08();
                arg0->unk1++;
            }
            break;
    }
}

extern s16 D_global_asm_8076AEF2;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3[0x1A - 0x03];
    u8 unk1A;
} A180_80024CB0;

void func_menu_80024CB0(void) {
    A180_80024CB0 *a180;
    s32 sp28;
    u8 var_v1;
    s32 sp20;

    sp28 = -1;
    var_v1 = 0;
    a180 = current_actor_pointer->unk180;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        sp20 = 1;
        sp28 = -1;
        a180->unk2 = func_global_asm_80731AA8(0x1FD, 0x28, 0);
        a180->unk1A = func_global_asm_80731A04(0x1D5, 0, 7, *current_character_index);
        a180->unk1A = a180->unk1A - func_global_asm_80731A04(0x1FD, 0, 7, *current_character_index);
        if (D_global_asm_8076AEF2 != 0x1C) {
            if (!isFlagSet(0x174, FLAG_TYPE_PERMANENT)) {
                a180->unk0 = 0;
                a180->unk1 = 0;
                sp20 = 0;
                func_global_asm_806F397C(player_pointer, 0, 0, 0);
                setFlag(0x174, 1, 0);
            } else {
                if (a180->unk2 == 0x28) {
                    a180->unk0 = 2;
                    a180->unk1 = 0;
                } else if (a180->unk1A == 0) {
                    a180->unk0 = 1;
                    a180->unk1 = 0;
                } else {
                    a180->unk0 = 3;
                    a180->unk1 = 0;
                }
            }
            playCutscene(NULL, sp20, 1);
        } else {
            a180->unk0 = 5;
            a180->unk1 = 0;
        }
        func_global_asm_80629174();
        func_menu_800240BC(a180);
        var_v1 = D_menu_80032F50;
        D_menu_80032F50 = 0;
    }
    switch (a180->unk0) {
        case 0:
            func_menu_80024224(a180, 1);
            break;
        case 3:
            func_menu_80024224(a180, 0);
            break;
        case 1:
            sp28 = 4;
            // fallthrough
        case 2:
            if (sp28 < 0) {
                sp28 = 7;
            }
            if (var_v1 != 0) {
                sp28 = 0xB;
            }
            func_menu_80024418(a180, sp28);
            break;
        case 4:
            func_menu_80024788(a180);
            break;
        case 5:
            func_menu_80024BFC(a180);
            break;
    }
    func_global_asm_80729B00();
    func_global_asm_806BFBF4();
    func_global_asm_806319C4(current_actor_pointer, 0);
}

// Checks if all blueprints turned in, malloc, current_actor_pointer, playSFX
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_menu_80024EF0.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_menu_800252AC.s")

void func_menu_80025AE0(void) {

}
