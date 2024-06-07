#include <ultra64.h>
#include "functions.h"

typedef struct RaceStruct8 {
    u8 pad0[0x36];
    u8 unk36;
} RaceStruct8;

typedef struct RaceStruct9 {
    u8 pad0[0x1A];
    s16 unk1A; // Flag index
    s32 unk1C;
} RaceStruct9;

extern u16 D_global_asm_80750AC4;

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
} Struct8002FB10_race_8002FB70;

extern Struct8002FB10_race_8002FB70 D_race_8002FB10[];
extern Struct8002FB10_race_8002FB70 D_race_8002FB70[];

// TODO: Quite close, float nonsense
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_race_80024000.s")

/*
void func_race_80024000(void) {
    f32 var_f0;
    f32 sp50;
    f32 temp_f0_2;
    f32 var_f12;
    f32 sp44;
    f32 sp40;
    f32 var_f22;
    f32 var_f20;
    u8 sp37;
    Struct8002FB10_race_8002FB70 *var_t0;
    s16 var_v1;

    sp37 = D_global_asm_807FDC90->unk24;
    if (current_map == MAP_CAVES_BEETLE_RACE) {
        var_t0 = &D_race_8002FB10;
    } else {
        var_t0 = &D_race_8002FB70;
    }
    sp44 = current_actor_pointer->unkB8;
    sp40 = func_global_asm_80612794(current_actor_pointer->unkE0 * 11.4) * 20.0f;
    if (sqrtf(((current_actor_pointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0) * (current_actor_pointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0)) + ((current_actor_pointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4) * (current_actor_pointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4))) < D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk7) {
        var_f12 = ABS(current_actor_pointer->y_position - (f32)D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk2);
        if (var_f12 < 80.0f) {
            if (D_global_asm_807FDC90->unk25 < (D_global_asm_807FDCA0->unk10 - 1)) {
                if (D_global_asm_807FDC90->unk25 == var_t0[sp37].unk0) {
                    current_actor_pointer->y_acceleration = var_t0[sp37].unk4;
                    if (var_t0[sp37].unk8 == 1) {
                        playActorAnimation(current_actor_pointer, 0x286);
                        current_actor_pointer->y_velocity = 200.0f;
                        current_actor_pointer->control_state++;
                    }
                    D_global_asm_807FDC90->unk24++;
                }
                D_global_asm_807FDC90->unk25++;
            }
        }
    }
    var_f0 = (current_actor_pointer->y_position - current_player->y_position);
    var_f0 *= 0.25f;
    var_f0 = MIN(6.0f, var_f0);
    var_f0 = MAX(-6.0f, var_f0);
    var_f0 += ((D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk8 - (current_actor_pointer->unkB8 / 10.0f)) * 0.8);
    var_v1 = (s16)((func_global_asm_80611BB4(-(current_actor_pointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0), -(current_actor_pointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4)) * 4096.0) / 6.28318548202514648) - current_actor_pointer->unkEE;
    if (var_v1 >= 0x800) {
        var_v1 -= 4096.0;
    }
    if (var_v1 < -0x800) {
        var_v1 += 4096.0;
    }
    sp50 = (current_actor_pointer->unkB8 * var_v1) / 10000.0;
    var_f20 = func_global_asm_80612794(current_actor_pointer->unkEE) * sp44;
    var_f22 = func_global_asm_80612790(current_actor_pointer->unkEE) * sp44;
    if (current_actor_pointer->unk6A & 1) {
        var_f20 += func_global_asm_80612794(current_actor_pointer->unkDC) * sp40;
        var_f22 += func_global_asm_80612790(current_actor_pointer->unkDC) * sp40;
    }
    var_f20 += (func_global_asm_80612794(current_actor_pointer->unkEE) * var_f0) + (func_global_asm_80612790(current_actor_pointer->unkEE) * sp50);
    var_f22 += (func_global_asm_80612790(current_actor_pointer->unkEE) * var_f0) - (func_global_asm_80612794(current_actor_pointer->unkEE) * sp50);
    sp44 = sqrtf((var_f20 * var_f20) + (var_f22 * var_f22));
    temp_f0_2 = func_global_asm_80611BB4(var_f20, var_f22);
    if (current_actor_pointer->y_acceleration != -20.0f && current_actor_pointer->y_acceleration != -360.0f) {
        current_actor_pointer->unkB8 = D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk8 * 10.0;
    } else {
        current_actor_pointer->unkB8 = sp44;
    }
    current_actor_pointer->unkEE = (temp_f0_2 * 4096.0) / 6.28318548202514648;
    if (current_actor_pointer->unk6A & 1) {
        current_actor_pointer->unkB8 -= (f32)((current_actor_pointer->unkB8 * current_actor_pointer->unkB8) / 15000.0);
        if (current_actor_pointer->unkB8 < 0.0f) {
            current_actor_pointer->unkB8 = 0.0f;
        }
    }
}
*/

int func_race_80024634(RaceStruct8 *arg0, RaceStruct9 *arg1) {
    return arg0->unk36 && 
           !isFlagSet(arg1->unk1A, FLAG_TYPE_PERMANENT) &&
           arg1->unk1C <= D_global_asm_80750AC4;
}

// Jumptable, doable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_race_80024690.s")
