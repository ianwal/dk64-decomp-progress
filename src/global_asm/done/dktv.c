#include <ultra64.h>
#include "functions.h"


extern s16 D_global_asm_807463A0;
extern void *D_global_asm_807463A8; // DKTV Inputs - Camera + Stick
extern s16 D_global_asm_807463AC;
extern s16 D_global_asm_807463B0;
extern u16 D_global_asm_807463B4;

typedef struct {
    s16     button;
    s8      stick_x;        /* -80 <= stick_x <= 80 */
    s8      stick_y;        /* -80 <= stick_y <= 80 */
} DKTV_OSContPad;

extern u8 D_global_asm_807ECE30;
extern void *D_global_asm_807ECE90; // DKTV Inputs - Buttons
extern u16 *D_global_asm_807ECE94;

extern DKTV_OSContPad *D_global_asm_807ECE98;

void func_global_asm_8060B430(Actor *arg0, DKTVExtraData *arg1) {
    arg0->x_position = arg1->startingXPosition;
    arg0->y_position = arg1->startingYPosition;
    arg0->z_position = arg1->startingZPosition;
    arg0->y_rotation = arg1->startingYRotation;
    memcpy(&D_global_asm_807FC950->character_progress[arg1->characterIndex], &arg1->characterProgress, sizeof(CharacterProgress));
}

s16 func_global_asm_8060B49C(Actor *arg0, s32 arg1) {
    is_autowalking = 2;
    func_global_asm_8060B430(arg0, &D_global_asm_807ECE20);
    return D_global_asm_807463B0;
}

void func_global_asm_8060B4D4(OSContPad *arg0) {
    if (D_global_asm_807463AC < (D_global_asm_807463B0 - 1)) {
        arg0->stick_x = D_global_asm_807ECE98->stick_x;
        arg0->stick_y = D_global_asm_807ECE98->stick_y;
        if (D_global_asm_807ECE98->button & 0x8000) {
            D_global_asm_807463B4 = D_global_asm_807ECE94[0];
            D_global_asm_807ECE94++;
        }
        arg0->button = D_global_asm_807463B4 & 0xEFFF;
    }
}

void func_global_asm_8060B55C(u16 *arg0) {
    if (D_global_asm_807463AC < (D_global_asm_807463B0 - 1)) {
        *arg0 = D_global_asm_807ECE98->button & 0x7FFF;
        D_global_asm_807ECE98++;
        D_global_asm_807463AC++;
        return;
    }
    is_autowalking = 0;
}

void func_global_asm_8060B5C0(u8 *file) {
    s32 size;

    // Allocate buffer for camera + stick inputs
    if (!D_global_asm_807463A8) {
        D_global_asm_807463A8 = malloc(1800 * sizeof(u32));
    }
    D_global_asm_807ECE98 = D_global_asm_807463A8;

    // Allocate buffer for button inputs
    if (!D_global_asm_807ECE90) {
        D_global_asm_807ECE90 = malloc(1800 * sizeof(u16));
    }
    D_global_asm_807ECE94 = D_global_asm_807ECE90;

    // Read the number of camera + stick inputs
    memcpy(&D_global_asm_807463B0, file, sizeof(u16));
    file += sizeof(u16);
    size = D_global_asm_807463B0 * sizeof(u32);

    // Read the camera + stick inputs
    memcpy(D_global_asm_807463A8, file, size);
    file += size;

    // Read the number of button inputs
    memcpy(&D_global_asm_807463A0, file, sizeof(u16));
    file += sizeof(u16);
    size = D_global_asm_807463A0 * sizeof(u16);

    // Read the button inputs
    memcpy(D_global_asm_807ECE90, file, size);
    file += size;

    // Read the extra data
    memcpy(&D_global_asm_807ECE20, file, sizeof(DKTVExtraData));
    
    // TODO: This is dumb, fix it
    //[3:01 PM] I***: They wouldn't have written that right?
    //[3:01 PM] M***: no, but they may have set size to that 0x70 in someway
    //[3:02 PM] M***: or may have used a macro to advance the buffer pointer that would have referenced size and then never used it
    if (size);
}

void func_global_asm_8060B6CC(void) {
    D_global_asm_807463A8 = NULL;
    D_global_asm_807ECE90 = NULL;
    D_global_asm_807463AC = 0;
    D_global_asm_807463B0 = 0;
    D_global_asm_807463A0 = 0;
    is_autowalking = 0;
}

void func_global_asm_8060B700(void) {
    if (D_global_asm_807463A8) {
        free(D_global_asm_807463A8);
    }
    if (D_global_asm_807ECE90) {
        free(D_global_asm_807ECE90);
    }
    func_global_asm_8060B6CC();
}

void func_global_asm_8060B750(s32 fileIndex) {
    void* file;

    // DK TV Inputs
    file = getPointerTableFile(0x11, fileIndex, 1, 1);
    func_global_asm_8060B5C0(file);
    func_global_asm_8066B434(file, 0xF8, 0x33);
    D_global_asm_807ECE98 = D_global_asm_807463A8;
    D_global_asm_807ECE94 = D_global_asm_807ECE90;
    D_global_asm_807463AC = 0;
    D_global_asm_807463B4 = 0;
}

// This is assigned to current_character_index
u8 func_global_asm_8060B7C4(void) {
    return D_global_asm_807ECE30;
}

void func_global_asm_8060B7D0(s32 *mapPointer, s32 *exitPointer) {
    *mapPointer = D_global_asm_807ECE20.map;
    *exitPointer = D_global_asm_807ECE20.exit;
}
