#include <ultra64.h>
#include "functions.h"
#include "variables.h"

// Weird array/struct stuff going on here
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_80024000.s")

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
} MenuStruct0;

extern f32 D_800339F8;
extern f32 D_800339FC;
extern f32 D_80033A00;
extern s32 D_80720268;
extern s16 D_80750AC8;

void func_800240BC(MenuStruct0 *arg0) {
    arg0->unk10 = D_800339F8;
    arg0->unkC = D_800339FC;
    arg0->unk14 = D_80033A00;
    arg0->unk6 = 0;
    func_80714998(0);
    func_807149B8(1);
    func_807149FC(-1);
    func_80714998(0);
    arg0->unk8 = func_80714CC0(&D_80720268, 0.3f, 181.0f, 3.0f, 82.0f);
}

void func_80024154(MenuStruct0 *arg0) {
    otherSpriteControl *sprite = arg0->unk8;

    sprite->xPos += arg0->unkC;
    sprite->unk_348 += arg0->unk14;
    arg0->unk10 += -1.0f;
    sprite->yPos += arg0->unk10;
    arg0->unk6++;
    if (arg0->unk6 >= 0x16) {
        arg0->unk6 = 0;
        func_80715908(arg0->unk8);
        arg0->unk8 = NULL;
    }
}

void func_800241E8(void) {
    func_806CFF9C(player_pointer);
    func_805FF898();
    playCutscene(NULL, 7, 1);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_80024224.s")

void func_80024418(MenuStruct0 *arg0, u8 arg1) {
    switch (arg0->unk1) {
        case 0:
            if (func_80629148()) {
                func_8070D8C0(current_actor_pointer, 0xB, arg1);
                arg0->unk1++;
            }
            break;
        case 1:
            // TODO: Use proper bitfield syntax
            if ((s32)current_actor_pointer->object_properties_bitfield << 6 >= 0) {
                func_8061CB08();
                arg0->unk1++;
            }
            break;
        case 2:
            if (func_80629148()) {
                func_80629174();
                arg0->unk0 = 4;
                arg0->unk1 = 0;
            }
            break;
    }
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_800244EC.s")

// Super interesting, somewhat doable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_80024788.s")

void func_80024BFC(MenuStruct0 *arg0) {
    switch (arg0->unk1) {
        case 0:
            if (func_80629148()) {
                func_80629174();
                arg0->unk1++;
                D_80750AC8 = func_80712548(arg0);
                func_8070D8C0(current_actor_pointer, 0xB, 8);
            }
            break;
        case 1:
            // TODO: Use proper bitfield syntax
            if (((s32)current_actor_pointer->object_properties_bitfield << 6) >= 0) {
                func_8061CB08();
                arg0->unk1++;
            }
            break;
    }
}

// Jumptable, 576 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_80024CB0.s")

// Checks if all blueprints turned in, malloc, current_actor_pointer, playSFX
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_80024EF0.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_800252AC.s")

void func_80025AE0(void) {

}