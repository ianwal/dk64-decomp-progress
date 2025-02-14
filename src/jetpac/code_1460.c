#include <ultra64.h>
#include "functions.h"

extern JetpacStruct1 D_jetpac_8002F3D0[0x300];
extern s32 D_jetpac_80045BD0;

void func_jetpac_80025460(void) {
    int x, y;
    JetpacStruct1 *ptr;

    ptr = &D_jetpac_8002F3D0[0];
    for (x = 0; x < 0x18; x++) {
        for (y = 0; y < 0x20; y++) {
            ptr->unk60 = 0;
            ptr->unk64.alpha = 0;
            ptr++;
        }
    }
}

void func_jetpac_800254B8(Struct8002C4D0* arg0, s32 arg1, s32 arg2, rgba* arg3, s32 arg4) {
    JetpacStruct1* temp_a0;
    JetpacStruct2* var_v0;
    s32 i;

    var_v0 = NULL;
    if ((arg1 >= 0) && (arg2 >= 0) && (arg1 <= 256) && (arg2 <= 0xC0)) {
        s32 index = arg1 / 8 + arg2 / 8 * 32;

        temp_a0 = &D_jetpac_8002F3D0[index];
        if (temp_a0->unk60 < 6) {
            var_v0 = &temp_a0->unk0[temp_a0->unk60++];
        }
        if (var_v0 != NULL) {
            var_v0->unk0 = arg1;
            var_v0->unk4 = arg2;
            var_v0->unk8 = arg4;
            var_v0->unkC = arg0;
            if ((temp_a0->unk64.as_array[3] == 0) || ((temp_a0->unk64.as_array[3] < 0xFF) && (func_jetpac_80027210() > 0.97 + 0.0))) {
                for (i = 0; i < 4; i++) {
                    temp_a0->unk64.as_array[i] = arg3->as_array[i];
                }
            }
        }
    }
}

void func_jetpac_800255D4(Gfx **arg0) {
    Gfx *dl;

    dl = *arg0;
    gDPPipeSync(dl++);
    gDPSetScissor(dl++, G_SC_NON_INTERLACE, 32, 24, 288, 216);
    gSPClearGeometryMode(dl++, -1);
    gSPSetGeometryMode(dl++, G_SHADE | G_SHADING_SMOOTH);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(dl++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetTextureFilter(dl++, G_TF_POINT);
    gDPSetTexturePersp(dl++, G_TP_NONE);
    gDPSetTextureConvert(dl++, G_TC_FILT);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gDPSetEnvColor(dl++, 0x00, 0x00, 0x00, 0x00);
    D_jetpac_80045BD0 = 0;
    func_jetpac_80025460();
    *arg0 = dl;
}
