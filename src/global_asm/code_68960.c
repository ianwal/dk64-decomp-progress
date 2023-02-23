#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80758DF0;
extern f64 D_80758DF8;
extern f64 D_80758E00;

typedef struct {
    s16 unk0;
    s8 unk2;
    s8 unk3;
    s16 unk4;
} GlobalASMStruct70;

extern GlobalASMStruct70 D_80748B70[];

void func_80663C60(f32 *arg0, s16 arg1) {
    s16 sp26;
    f32 temp_f0;
    f32 temp_f0_2;
    s16 temp_a0;
    s8 temp_v1;
    GlobalASMStruct70 *temp_v0;
    f32 phi_f2;
    s16 phi_a0;

    sp26 = 6;
    if (current_map == MAP_CASTLE) {
        if (func_8061CC00()) {
            phi_f2 = D_80758DF0;
        } else {
            phi_f2 = 900.0f;
        }
        temp_f0 = *arg0;
        *arg0 = ((phi_f2 - temp_f0) * D_80758DF8) + temp_f0;
    }
    for (phi_a0 = 0; phi_a0 < sp26; phi_a0++) {
        temp_v0 = &D_80748B70[phi_a0];
        if (current_map == temp_v0->unk0 && (arg1 == temp_v0->unk2 || temp_v0->unk2 == -1)) {
            temp_f0_2 = *arg0;
            *arg0 = ((temp_v0->unk4 - temp_f0_2) * D_80758E00) + temp_f0_2;
            return;
        }
    }
}
