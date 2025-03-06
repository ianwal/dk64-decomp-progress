#include "common.h"

extern JetpacRenderingCell D_jetpac_8002F3D0[0x300];
extern s32 D_jetpac_80045BD0;

void func_jetpac_80025460(void) {
    int x, y;
    JetpacRenderingCell *ptr;

    ptr = &D_jetpac_8002F3D0[0];
    for (x = 0; x < 0x18; x++) {
        for (y = 0; y < 0x20; y++) {
            ptr->num_entries = 0;
            ptr->hue.alpha = 0;
            ptr++;
        }
    }
}

// add_sprite_to_cell
void func_jetpac_800254B8(uSprite* draw_sprite, s32 x, s32 y, rgba* hue, s32 horizontal_flip) {
    JetpacRenderingCell* temp_a0;
    JetpacRenderingCellEntry* var_v0;
    s32 i;

    var_v0 = NULL;
    if ((x >= 0) && (y >= 0) && (x <= 256) && (y <= 0xC0)) {
        s32 index = x / 8 + y / 8 * 32;

        temp_a0 = &D_jetpac_8002F3D0[index];
        if (temp_a0->num_entries < 6) {
            var_v0 = &temp_a0->entries[temp_a0->num_entries++];
        }
        if (var_v0 != NULL) {
            var_v0->x = x;
            var_v0->y = y;
            var_v0->horizontal_flip = horizontal_flip;
            var_v0->draw_sprite = draw_sprite;
            if ((temp_a0->hue.as_array[3] == 0) || ((temp_a0->hue.as_array[3] < 0xFF) && (func_jetpac_80027210() > 0.97))) {
                for (i = 0; i < 4; i++) {
                    temp_a0->hue.as_array[i] = hue->as_array[i];
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
