#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s16 D_807463A0;
extern void *D_807463A8; // DKTV Inputs - Camera + Stick
extern s16 D_807463AC;
extern s16 D_807463B0;
extern s16 D_807463B4;

extern u8 D_807ECE30;
extern void *D_807ECE90; // DKTV Inputs - Buttons
extern void *D_807ECE94;
extern s16 *D_807ECE98;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10130/func_8060B430.s")

/*
// Very doable, datatype nonsense
void func_8060B430(void *arg0, void *arg1) {
    void *temp_a1;

    arg0->unk7C = arg1->unk0;
    temp_a1 = arg1 + 0x12;
    arg0->unk80 = arg1->unk4;
    arg0->unk84 = temp_a1->unk-A;
    arg0->unkE6 = temp_a1->unk-6;
    memcpy(&D_807FC950->character_progress[temp_a1->unk-2], temp_a1, 0x5E);
}
*/

s16 func_8060B49C(s32 arg0, s32 arg1) {
    is_autowalking = 2;
    func_8060B430(arg0, &D_807ECE20);
    return D_807463B0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10130/func_8060B4D4.s")

/*
// Very doable, datatype nonsense
void func_8060B4D4(void *arg0) {
    if (D_807463AC < (D_807463B0 - 1)) {
        arg0->unk2 = D_807ECE98->unk2;
        arg0->unk3 = D_807ECE98->unk3;
        if (D_807ECE98->unk0 & 0x8000) {
            D_807463B4 = *D_807ECE94;
            D_807ECE94 += 2;
        }
        arg0->unk0 = D_807463B4 & 0xEFFF;
    }
}
*/

void func_8060B55C(s16 *arg0) {
    if (D_807463AC < (D_807463B0 - 1)) {
        *arg0 = *D_807ECE98 & 0x7FFF;
        D_807ECE98 += 2;
        D_807463AC++;
        return;
    }
    is_autowalking = 0;
}

void func_8060B5C0(u8 *file) {
    s32 size;

    // Allocate buffer for camera + stick inputs
    if (!D_807463A8) {
        D_807463A8 = malloc(1800 * sizeof(u32));
    }
    D_807ECE98 = D_807463A8;

    // Allocate buffer for button inputs
    if (!D_807ECE90) {
        D_807ECE90 = malloc(1800 * sizeof(u16));
    }
    D_807ECE94 = D_807ECE90;

    // Read the number of camera + stick inputs
    memcpy(&D_807463B0, file, sizeof(u16));
    file += sizeof(u16);
    size = D_807463B0 * sizeof(u32);

    // Read the camera + stick inputs
    memcpy(D_807463A8, file, size);
    file += size;

    // Read the number of button inputs
    memcpy(&D_807463A0, file, sizeof(u16));
    file += sizeof(u16);
    size = D_807463A0 * sizeof(u16);

    // Read the button inputs
    memcpy(D_807ECE90, file, size);
    file += size;

    // Read the extra data
    memcpy(&D_807ECE20, file, 0x70);
    
    // TODO: This is dumb, fix it
    //[3:01 PM] I***: They wouldn't have written that right?
    //[3:01 PM] M***: no, but they may have set size to that 0x70 in someway
    //[3:02 PM] M***: or may have used a macro to advance the buffer pointer that would have referenced size and then never used it
    if (size);
}

void func_8060B6CC(void) {
    D_807463A8 = NULL;
    D_807ECE90 = NULL;
    D_807463AC = 0;
    D_807463B0 = 0;
    D_807463A0 = 0;
    is_autowalking = 0;
}

void func_8060B700(void) {
    if (D_807463A8) {
        func_8061130C(D_807463A8);
    }
    if (D_807ECE90) {
        func_8061130C(D_807ECE90);
    }
    func_8060B6CC();
}

void func_8060B750(s32 fileIndex) {
    void* file;

    // DK TV Inputs
    file = getPointerTableFile(0x11, fileIndex, 1, 1);
    func_8060B5C0(file);
    func_8066B434(file, 0xF8, 0x33);
    D_807ECE98 = D_807463A8;
    D_807ECE94 = D_807ECE90;
    D_807463AC = 0;
    D_807463B4 = 0;
}

// This is assigned to current_character_index
u8 func_8060B7C4(void) {
    return D_807ECE30;
}

void func_8060B7D0(s32 *mapPointer, s32 *exitPointer) {
    *mapPointer = D_807ECE20.map;
    *exitPointer = D_807ECE20.exit;
}
