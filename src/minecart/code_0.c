#include <ultra64.h>
#include "functions.h"
#include "variables.h"

s32 func_8070E750(s32, s32, s32);

void func_80024000(u8 arg0, u8 arg1) {
    playSound(0x143, 0x7FFF, 63.0f, 1.0f, 0, 0);
    func_8069D2AC(0x81, 0, 0x78, func_8070E750(0x1A, arg1, 1), 0, 0x28, 8, 8);
    current_actor_pointer->unk11C->control_state = 0;
    playSong(0x28, 1.0f);
    func_806EB0C0(0x44, NULL, 0);
    current_actor_pointer->control_state++;
    if (arg0 != 0) {
        playCutscene(player_pointer, 5, 5);
    }
}

void func_800240DC(u8 arg0, u8 arg1) {
    s32 temp = func_8070E750(0x1A, arg1, 1);
    func_8069D2AC(0x81, 0, 0x78, temp, 0, 0x28, 8, 8);
    current_actor_pointer->unk11C->control_state = 0;
    playSong(0x2A, 1.0f);
    func_806EB0C0(0x43, NULL, 0);
    current_actor_pointer->control_state++;
    if (arg0 != 0) {
        playCutscene(player_pointer, 5, 5);
    }
}

extern s32 D_8071A440; // TODO: Proper datatype
extern s32 D_80028C30; // TODO: Proper datatype
extern s32 D_8072006C; // TODO: Proper datatype

s32 func_80714C08(void*, f32, Actor*, s32, s32);
u8 func_806119A0(void);

void func_800241A0(s16 *arg0, u8 arg1, u8 arg2) {
    // TODO: Get rid of this typecast if possible
    if (((func_806119A0() & 0xFF) >= (u32)arg2) && (*arg0 == 0)) {
        func_80608528(current_actor_pointer, 0x8A, 0x96, 0x7F, 0x32);
        func_80714950(current_actor_pointer);
        func_8071498C(&D_8071A440);
        D_80028C30 = func_80714C08(&D_8072006C, 0.4f, current_actor_pointer, arg1 + 7, 2);
    }
}

// struct spaghetti
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_80024254.s")

// jumptable, can't auto decompile
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_8002430C.s")

void func_8065A660(f32, f32);
void func_8065A6F8(s32);
void func_8065A708(f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);

void func_80024768(void) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    if (extra_player_info_pointer->unk1F0 & 0x10000002) {
        func_80671C0C(current_actor_pointer, 2, &sp38, &sp3C, &sp40);
        func_80671C0C(current_actor_pointer, 1, &sp44, &sp48, &sp4C);
    } else {
        func_80671C0C(current_actor_pointer, 1, &sp38, &sp3C, &sp40);
        func_80671C0C(current_actor_pointer, 2, &sp44, &sp48, &sp4C);
    }
    func_8065A6F8(0xC8);
    func_8065A660(20.0f, 40.0f);
    func_8065A708(sp38, sp3C, sp40, sp44, sp48, sp4C, 0.0f, 1, 0xFF, 0xFF, 0xFF);
}

// struct float aaa
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_80024890.s")

// struct float aaa
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_80024914.s")

// long, structs
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_80024B00.s")

// struct, loop
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_80024E78.s")

// jumptable, can't auto decompile
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_80024FD0.s")

typedef struct minecart_struct_0 {
    u8 pad0[0x20];
    f32 unk20;
    f32 unk24;
    f32 unk28;
} MinecartStruct0;

void func_8002538C(MinecartStruct0 *arg0) {
    arg0->unk20 = arg0->unk20 + arg0->unk24;
    if (arg0->unk28 < arg0->unk20) {
        arg0->unk20 = arg0->unk28;
    }
}

// huge, struct, float, loop
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_800253C0.s")
