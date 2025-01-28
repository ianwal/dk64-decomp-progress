#include <ultra64.h>
#include "functions.h"

extern s32 D_global_asm_80744470[];
extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;
extern s16 D_global_asm_80744498;
extern s16 D_global_asm_8074449C;
extern s16 D_global_asm_807444A0;
extern s16 D_global_asm_807444A4;

extern u8 D_global_asm_80747B20;
extern s32 D_global_asm_80747B24;
extern s32 D_global_asm_80747B28;
extern u8 *D_global_asm_80747B2C;
extern s32 D_global_asm_80747B38;

extern u8 D_global_asm_80747B40;
extern f32 D_global_asm_80747B44;
extern f32 D_global_asm_80747B48;
extern f32 D_global_asm_80747B4C;
extern f32 D_global_asm_80747B50;

extern void *D_807F5D80;
extern s8 D_global_asm_807F5D84;
extern s8 D_807F5D85;
extern s16 D_807F5D86;
extern s16 D_807F5D88;
extern f32 D_global_asm_807F5D8C;
extern f32 D_global_asm_807F5D90;
extern f32 D_global_asm_807F5D94;
extern Mtx D_807F5D98;
extern void *D_global_asm_807F5DD8;

void func_global_asm_807024E0(Gfx **, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, s32, s32, s32, void (*)(s32, s32, void *));
void func_global_asm_80704130(void*, u8, u8, u8, u8, u8);

void func_global_asm_80629190(void) {
    D_global_asm_807F5D84 = 0;
}

u8 func_global_asm_8062919C(void) {
    return D_global_asm_807F5D84;
}

u8 func_global_asm_806291A8(void) {
    return D_global_asm_80747B20;
}

void func_global_asm_806291B4(u8 arg0) {
    if ((D_global_asm_807F5D84 == 0) || (arg0 == 7)) {
        if (D_global_asm_807F5D84 == 0) {
            D_807F5D80 = malloc(D_global_asm_80744490 * D_global_asm_80744494 * 2);
        }
        func_global_asm_8070A848(D_807F5D80, D_global_asm_80744470[D_global_asm_807444FC]);
        D_global_asm_807F5D84 = 1;
        D_global_asm_80747B20 = 5;
        switch (arg0) {
            case 1:
                D_807F5D86 = 0xFF;
                break;
            case 2:
                D_807F5D86 = 0;
                break;
            case 0:
                D_807F5D86 = 0x136;
                break;
            case 3:
                D_807F5D86 = 0xA0;
                D_807F5D88 = 0xA0;
                break;
            case 4:
            case 5:
                D_global_asm_807F5D8C = -5.0f;
                break;
            case 6:
                D_global_asm_807F5D94 = 0.0f;
                break;
            case 7:
                func_global_asm_8062A348();
                break;
        }
        D_807F5D85 = arg0;
    }
}

Gfx *func_global_asm_80629300(Gfx *dl) {
    s32 sp54;

    sp54 = D_global_asm_80744478 * 0.5f;
    if (D_global_asm_80747B24 == 0) {
        guScale(&D_807F5D98, 2.0f, 2.0f, 1.0f);
        D_global_asm_80747B24 = 1;
    }
    if ((D_global_asm_807F5D84 == 0) && (D_global_asm_80747B20 != 0)) {
        D_global_asm_80747B20--;
    }
    if (D_global_asm_807F5D84 < 0) {
        D_global_asm_807F5D84++;
        if (D_global_asm_807F5D84 == 0) {
            func_global_asm_8061134C(D_807F5D80);
        }
    } else {
        if (D_global_asm_807F5D84 > 0) {
            gSPDisplayList(dl++, &D_1000118);
            dl = func_global_asm_805FD030(dl);
            gSPMatrix(dl++, &D_2000140, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gSPMatrix(dl++, &D_807F5D98, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPPipeSync(dl++);
            gDPSetTextureFilter(dl++, G_TF_POINT);
            gDPSetColorDither(dl++, G_CD_DISABLE);
            gDPSetScissor(dl++, G_SC_NON_INTERLACE, D_global_asm_80744498, D_global_asm_8074449C, D_global_asm_807444A0, D_global_asm_807444A4);
            gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            switch (D_807F5D85) {
                case 7:
                    func_global_asm_8062A3F0();
                    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                    func_global_asm_807023E8(&dl, D_807F5D80, 0, 0x140, 0xF0, 0x20, 0x20, 0.0f, 0.0f, 319.0f, 239.0f, 0.0f, 0.0f);
                    if (global_properties_bitfield & 0x40) {
                        D_global_asm_807F5D84 = -2;
                    }
                    break;
                case 1:
                    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, D_807F5D86);
                    func_global_asm_807023E8(&dl, D_807F5D80, 0, 0x140, 0xF0, 0x20, 0x20, 0.0f, 0.0f, 319.0f, 239.0f, 0.0f, 0.0f);
                    D_807F5D86 -= sp54 * 5;
                    if (D_807F5D86 < 0) {
                        D_global_asm_807F5D84 = -2;
                    }
                    break;
                case 2:
                    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                    func_global_asm_807023E8(&dl, D_807F5D80, 0, 0x140, 0xF0, 0x20, 0x20, D_807F5D86, 0.0f, 319.0f, 239.0f, D_807F5D86, 0.0f);
                    gDPPipeSync(dl++);
                    gDPSetCombineMode(dl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                    if (D_807F5D86 >= 0x11) {
                        func_global_asm_807024E0(&dl, D_807F5D80, 0, 0x140, 0xF0, 0x10, 0x50, (D_807F5D86 - 0x10), 0.0f, D_807F5D86, 239.0f, (D_807F5D86 - 0x10), 0.0f, 1, 0x10, 1, NULL);
                    }
                    D_807F5D86 += (sp54 * 0xA);
                    if (D_807F5D86 >= 0x137) {
                        D_global_asm_807F5D84 = -2;
                    }
                    break;
                case 0:
                    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                    func_global_asm_807023E8(&dl, D_807F5D80, 0, 0x140, 0xF0, 0xA, 0x50, 0.0f, 0.0f, D_807F5D86, 239.0f, 0.0f, 0.0f);
                    gDPSetCombineMode(dl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                    if (D_807F5D86 < 0x131) {
                        func_global_asm_807024E0(&dl, D_807F5D80, 0, 0x140, 0xF0, 0x10, 0x20, D_807F5D86, 0.0f, D_807F5D86 + 0x10, 239.0f, D_807F5D86, 0.0f, 1, 0x10, 2, NULL);
                    }
                    D_807F5D86 -= (sp54 * 0xA);
                    if (D_807F5D86 < 0xB) {
                        D_global_asm_807F5D84 = -2;
                    }
                    break;
                case 3:
                    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                    func_global_asm_807023E8(&dl, D_807F5D80, 0, 0x140, 0xF0, 0x20, 0x20, D_807F5D86, 0.0f, 319.0f, 239.0f, D_807F5D86, 0.0f);
                    func_global_asm_807023E8(&dl, D_807F5D80, 0, 0x140, 0xF0, 0xA, 0x50, 0.0f, 0.0f, D_807F5D88, 239.0f, 0.0f, 0.0f);
                    gDPSetCombineMode(dl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                    if (D_807F5D86 >= 0x11) {
                        func_global_asm_807024E0(&dl, D_807F5D80, 0, 0x140, 0xF0, 0x10, 0x50, (D_807F5D86 - 0x10), 0.0f, D_807F5D86, 239.0f, (D_807F5D86 - 0x10), 0.0f, 1, 0x10, 1, NULL);
                    }
                    if (D_807F5D88 < 0x131) {
                        func_global_asm_807024E0(&dl, D_807F5D80, 0, 0x140, 0xF0, 0x10, 0x20, D_807F5D88, 0.0f, D_807F5D88 + 0x10, 239.0f, D_807F5D88, 0.0f, 1, 0x10, 2, NULL);
                    }
                    D_807F5D86 += (sp54 * 0xA);
                    D_807F5D88 -= (sp54 * 0xA);
                    if (D_807F5D86 >= 0x137) {
                        D_global_asm_807F5D84 = -2;
                    }
                    break;
                case 4:
                    gDPSetCombineMode(dl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                    D_global_asm_807F5D8C = D_global_asm_807F5D8C + (5.0 * sp54);
                    D_global_asm_807F5D90 = D_global_asm_807F5D8C + 40.0f;
                    func_global_asm_807024E0(&dl, D_807F5D80, 0, 0x140, 0xF0, 0x20, 0x20, 0.0f, 0.0f, 320.0f, 239.0f, 0.0f, 0.0f, 1, 0x10, 1, func_global_asm_8062A24C);
                    if (D_global_asm_807F5D8C > 170.0f) {
                        D_global_asm_807F5D84 = -2;
                    }
                    break;
                case 5:
                    gDPSetCombineMode(dl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                    D_global_asm_807F5D8C = D_global_asm_807F5D8C + (12.0 * sp54);
                    D_global_asm_807F5D90 = D_global_asm_807F5D8C + 40.0f;
                    func_global_asm_807024E0(&dl, D_807F5D80, 0, 0x140, 0xF0, 0x20, 0x20, 0.0f, 0.0f, 320.0f, 239.0f, 0.0f, 0.0f, 1, 0x10, 1, func_global_asm_8062A228);
                    if (D_global_asm_807F5D8C > 350.0f) {
                        D_global_asm_807F5D84 = -2;
                    }
                    break;
                case 6:
                    gDPSetCombineMode(dl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                    D_global_asm_807F5D94 = D_global_asm_807F5D94 + (15.0 * sp54);
                    func_global_asm_807024E0(&dl, D_807F5D80, 0, 0x140, 0xF0, 0x20, 0x20, 0.0f, 0.0f, 320.0f, 239.0f, 0.0f, 0.0f, 1, 0x10, 1, func_global_asm_8062A130);
                    if (D_global_asm_807F5D94 > 350.0f) {
                        D_global_asm_807F5D84 = -2;
                    }
                    break;
            }
            gDPPipeSync(dl++);
            gDPSetColorDither(dl++, G_CD_MAGICSQ);
            gDPSetTextureFilter(dl++, G_TF_BILERP);
        }
    }
    return dl;
}

void func_global_asm_8062A130(s32 arg0, s32 arg1, void* arg2) {
    f32 temp_f0;
    s32 phi_v0;

    temp_f0 = func_global_asm_80665AE4(0xA0, 0x78, arg0, arg1);
    if (D_global_asm_807F5D94 < 20.0) {
        func_global_asm_80704130(arg2, 0xFF, 0xFF, 0xFF, 0xFF, 0);
        return;
    }
    phi_v0 = 0;
    if (D_global_asm_807F5D94 < temp_f0) {
        if ((temp_f0 - D_global_asm_807F5D94) < 25.0) {
            phi_v0 = (s16) (((temp_f0 - D_global_asm_807F5D94) / 25.0) * 255.0);
        } else {
            phi_v0 = 0xFF;
        }
    } else {
        phi_v0 = 0;
    }
    func_global_asm_80704130(arg2, 0xFF, 0xFF, 0xFF, phi_v0, 0);
}

void func_global_asm_8062A228(s32 arg0, s32 arg1, void *arg2) {
    func_global_asm_8062A274(arg0, arg1, arg2, 0, 0);
}

void func_global_asm_8062A24C(s32 arg0, s32 arg1, void *arg2) {
    func_global_asm_8062A274(arg0, arg1, arg2, 0xA0, 0x78);
}

void func_global_asm_8062A274(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4) {
    f32 temp_f0;
    s32 temp_v0;
    s32 temp_v1;
    s16 phi_v0;

    temp_v0 = arg0 - arg3;
    temp_v1 = arg1 - arg4;
    temp_f0 = sqrtf(SQ(temp_v0) + SQ(temp_v1));
    if (temp_f0 < D_global_asm_807F5D8C) {
        phi_v0 = 0;
    } else if (D_global_asm_807F5D90 < temp_f0) {
        phi_v0 = 0xFF;
    } else {
        phi_v0 = ((temp_f0 - D_global_asm_807F5D8C) / (D_global_asm_807F5D90 - D_global_asm_807F5D8C)) * 255.0f;
    }
    func_global_asm_80704130(arg2, 0xFF, 0xFF, 0xFF, phi_v0, 0);
}

void func_global_asm_8062A348(void) {
    s32 phi_v1;

    D_global_asm_80747B2C = malloc((D_global_asm_80747B28 << 5) + 1);
    phi_v1 = 0;
    while (D_global_asm_80747B28 << 5 >= phi_v1) {
        // TODO: Might be better as array notation
        *(D_global_asm_80747B2C + phi_v1) = phi_v1 / D_global_asm_80747B28;
        phi_v1++;
    }
    D_global_asm_80747B38 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2DE90/func_global_asm_8062A3F0.s")

void func_global_asm_8062A774(void) {
    if (!D_global_asm_80747B40) {
        D_global_asm_807F5DD8 = malloc(0x25800);
        memset(D_global_asm_807F5DD8, 0, 0x25800);
        D_global_asm_80747B40 = 1;
    }
}

void func_global_asm_8062A7D0(void) {
    if (D_global_asm_80747B40) {
        func_global_asm_8061134C(D_global_asm_807F5DD8);
        D_global_asm_80747B40 = 0;
    }
}

void func_global_asm_8062A808(s32 arg0, s32 arg1) {
    D_global_asm_80747B4C = 2.0f;
    D_global_asm_80747B50 = 2.0f;
    D_global_asm_80747B44 = arg0;
    D_global_asm_80747B48 = arg1;
}

Gfx *func_global_asm_8062A844(Gfx *dl) {
    return dl;
}
