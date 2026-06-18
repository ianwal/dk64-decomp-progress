#include "common.h"

extern s32 D_global_asm_80718188;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80748280;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct8074828C;

extern u8 D_global_asm_80748214[];
extern Struct80748280 D_global_asm_80748280;
extern Struct8074828C D_global_asm_8074828C;
extern s16 D_global_asm_807480D0;
extern s16 D_global_asm_807480D4;
extern s16 D_global_asm_807480D8;
extern f32 D_global_asm_807480E0;
extern f32 D_global_asm_807480E4;
extern f32 D_global_asm_807482A4;

extern u8 D_global_asm_80750AB4;
extern s32 D_global_asm_807552E8;

extern f32 D_global_asm_80770B68[];
extern f32 D_global_asm_80770BC0[];
extern s16 D_global_asm_80770628[];

extern f32 D_global_asm_807F621C; // X
extern f32 D_global_asm_807F6220; // Y
extern f32 D_global_asm_807F6224; // Z
extern f32 D_global_asm_807F6228;
extern f32 D_global_asm_807F622C; // Y Rotation
extern f32 D_global_asm_807F6230;
extern f32 D_global_asm_807F6234;
extern f32 D_global_asm_807F6238;
extern s8 D_global_asm_807F6950;
extern s8 D_global_asm_807F6951;
extern s32 D_global_asm_807F6C28;

extern u16 D_global_asm_807FC930[];

extern f32 D_global_asm_807480E8;
extern u8 D_global_asm_807480EF;

extern f32 D_global_asm_8074816C;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} Struct80748168;

extern Struct80748168 D_global_asm_80748168;

extern u32 D_global_asm_8076A068;

void func_global_asm_80716F10(Struct80717D84 *arg0, s32 arg1);

int func_global_asm_8071910C(); // TODO: Signature
extern int func_global_asm_8071F1D0(); // TODO: Signature

typedef struct SpriteStructSub384 {
    s16 unk0;
    s16 unk2;
    f32 unk4;
} SpriteStructSub384;

typedef struct SpriteStruct {
    u8 pad0[0x344];
    f32 unk344;
    u8 pad348[0x360 - 0x348];
    f32 unk360;
    f32 unk364;
    u8 pad368[0x384 - 0x368];
    SpriteStructSub384* unk384;
} SpriteStruct;

extern void func_global_asm_8064EE08(SpriteStruct *, u8 *);

void func_global_asm_80642BF0(Prop_ScriptData *arg0, s16 arg1, s32 arg2, s32 arg3) {
    func_global_asm_80714B84(&D_global_asm_8071FF18, 0.3f, arg1, 1, 0);
    func_global_asm_80714B84(&D_global_asm_8071FF18, 0.3f, arg1, 2, 0);
    func_global_asm_80714B84(&D_global_asm_8071FF18, 0.3f, arg1, 3, 0);
}

void func_global_asm_80642C78(Prop_ScriptData *arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;
    u8 temp;
    f32 x, y, z;
    s16 index;

    index = func_global_asm_80659470(arg1);
    switch (D_global_asm_807F6000[index].unk78[2].unk5_u8) {
        case 0xD:
        case 0x15:
        case 0x19:
            for (i = 1; i < 0xF; i++) {
                func_global_asm_806335B0(arg1, 1, i, &x, &y, &z);
                func_global_asm_807149B8(1);
                func_global_asm_80714998(2);
                func_global_asm_80714950(- ((func_global_asm_806119A0() / 10000U) % 50U) - 0x14);
                changeActorColor(0xE1, 0x87, 0x38, 0xFF);
                func_global_asm_8071498C(func_global_asm_80717D4C);
                drawSpriteAtPosition(&D_global_asm_8071FF18, 0.5f, x, y + 2.0f, z);
            }
            break;
    }
}

typedef struct InstanceData80642E34 {
    s32 unk0;
} InstanceData80642E34;

void func_global_asm_80642E34(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3) {
    f32 x, y, z;
    InstanceData80642E34 *var_v1;
    f32 var_f0;
    s32 sp48;

    if (arg0->unk0 == NULL) {
        arg0->unk0 = malloc(sizeof(InstanceData80642E34));
        ((InstanceData80642E34 *)arg0->unk0)->unk0 = arg2;
    }
    var_v1 = arg0->unk0;
    var_f0 = ((20.0 - var_v1->unk0) / 20.0);
    if (0.7 < var_f0) {
        var_f0 = 1.0f;
    }
    func_global_asm_806335B0(arg1, 1, 1, &x, &y, &z);
    sp48 = ((func_global_asm_806119A0() / 10000U) % 200) + 0x37;
    createLight(x, y, z, 0.0f, 0.0f, 0.0f, var_f0 * 200.0, 0, 0, sp48, ((func_global_asm_806119A0() / 10000U) % 80) + 0xAF);
    var_v1->unk0++;
    if (var_v1->unk0 == 0x14) {
        var_v1->unk0 = 0;
    }
}

typedef struct InstanceData80642FC4 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} InstanceData80642FC4;

void func_global_asm_80642FC4(Prop_ScriptData *arg0, s32 arg1, s32 arg2, s32 arg3) {
    InstanceData80642FC4 *var_v1;
    u8 sp33;
    f32 sp2C;

    if (arg0->unk0 == NULL) {
        var_v1 = malloc(sizeof(InstanceData80642FC4));
        arg0->unk0 = var_v1;
        var_v1->unk0 = 7.0f;
        var_v1->unk4 = ((func_global_asm_806119A0() / 10000U) % 1548) + 0x5DC;
        var_v1->unk8 = (((func_global_asm_806119A0() / 10000U) % 100) / 40.0) + 2.5;
        D_global_asm_807F6234 = (((func_global_asm_806119A0() / 10000U) % 100) / 500.0) + 0.14;
    }
    var_v1 = arg0->unk0;
    sp2C = D_global_asm_807F6220;
    sp33 = func_global_asm_80667110(D_global_asm_807F621C, D_global_asm_807F6224, &sp2C);
    var_v1->unk0 = var_v1->unk0 + -0.64;
    D_global_asm_807F621C += var_v1->unk8 * func_global_asm_80612794(var_v1->unk4);
    D_global_asm_807F6224 += var_v1->unk8 * func_global_asm_80612790(var_v1->unk4);
    if (var_v1->unk0 < -10.0f) {
        var_v1->unk0 = -10.0f;
    }
    D_global_asm_807F6220 += var_v1->unk0;
    if (sp33 != 0) {
        if (D_global_asm_807F6220 < sp2C) {
            var_v1->unk0 = (0.0 - var_v1->unk0) * 0.7;
            D_global_asm_807F6220 = sp2C;
        }
    }
}

void func_global_asm_80643274(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 sp24;

    if ((object_timer % (u32)arg3) == 0) {
        sp24 = ((func_global_asm_806119A0() / 10000U) % arg2) + 1;
        changeActorColor(0xFF, 0xFF, 0xFF, 0x64);
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, 1.5f, arg1, sp24, 0);
    }
}

void func_global_asm_80643354(s32 arg0, u32 arg1, u32 arg2) {
    u32 sp24;
    Struct807F5FD4_unk0 *temp_v0;

    if ((object_timer % arg2) == 0) {
        sp24 = (func_global_asm_806119A0() / 10000U) % arg1;
        changeActorColor(0xFF, 0xFF, 0xFF, 0x64);
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        temp_v0 = &D_global_asm_807F5FD4->unk0[0][sp24];
        drawSpriteAtPosition(&D_global_asm_8071FFA0, 1.5f, temp_v0->unk0, temp_v0->unk4, temp_v0->unk8);
    }
}

typedef struct InstanceData80643440 {
    s16 unk0;
} InstanceData80643440;

void func_global_asm_80643440(Prop_ScriptData *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 temp_f24;
    InstanceData80643440 *var_v1;

    if (arg0->unk0 == NULL) {
        arg0->unk0 = malloc(sizeof(InstanceData80643440));
        var_v1 = arg0->unk0;
        var_v1->unk0 = 0;
    }
    var_v1 = arg0->unk0;
    temp_f24 = D_global_asm_807F5FD4->unk0[1][0].unk4 + ((D_global_asm_807F5FD4->unk0[1][1].unk4 - D_global_asm_807F5FD4->unk0[1][0].unk4) * ((func_global_asm_80612794(var_v1->unk0) * 0.5) + 0.5));
    func_global_asm_80659610(1500);
    createLight(D_global_asm_807F5FD4->unk0[1][0].unk0, temp_f24, D_global_asm_807F5FD4->unk0[1][0].unk8, 0.0f, 0.0f, 0.0f, 500.0f, 0, 0xFF, 0xFF, 0xFF);
    temp_f24 = D_global_asm_807F5FD4->unk0[1][2].unk4 + ((D_global_asm_807F5FD4->unk0[1][3].unk4 - D_global_asm_807F5FD4->unk0[1][2].unk4) * ((func_global_asm_80612794(var_v1->unk0 + 1300) * 0.5) + 0.5));
    func_global_asm_80659610(1500);
    createLight(D_global_asm_807F5FD4->unk0[1][2].unk0, temp_f24, D_global_asm_807F5FD4->unk0[1][2].unk8, 0.0f, 0.0f, 0.0f, 500.0f, 0, 0xFF, 0xFF, 0xFF);
    temp_f24 = D_global_asm_807F5FD4->unk0[1][4].unk4 + ((D_global_asm_807F5FD4->unk0[1][5].unk4 - D_global_asm_807F5FD4->unk0[1][4].unk4) * ((func_global_asm_80612794(var_v1->unk0 + 2600) * 0.5) + 0.5));
    func_global_asm_80659610(1500);
    createLight(D_global_asm_807F5FD4->unk0[1][4].unk0, temp_f24, D_global_asm_807F5FD4->unk0[1][4].unk8, 0.0f, 0.0f, 0.0f, 500.0f, 0, 0xFF, 0xFF, 0xFF);
    var_v1->unk0 += 0x32;
}

void func_global_asm_806436A4(Prop_ScriptData *arg0, s32 arg1, s16 arg2, s16 arg3) {
    func_global_asm_80643354(0, arg2, arg3);
}

typedef struct InstanceData806436E0 {
    u32 unk0;
    s32 unk4;
} InstanceData806436E0;

void func_global_asm_806436E0(Prop_ScriptData *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Struct807F5FD4_unk0 *temp_v0_2;
    InstanceData806436E0 *var_v1;
    s32 x, y, z;
    s32 count;

    if (arg0->unk0 == NULL) {
        var_v1 = malloc(sizeof(InstanceData806436E0));;
        arg0->unk0 = var_v1;
        var_v1->unk0 = 0;
        var_v1->unk4 = 0;
    }
    var_v1 = arg0->unk0;
    if (var_v1->unk0 == 0) {
        count = (D_global_asm_807F5FD4->unk0[1] - D_global_asm_807F5FD4->unk0[0]);
        var_v1->unk4++;
        if (count == var_v1->unk4) {
            var_v1->unk4 = 0;
        }
        temp_v0_2 = &D_global_asm_807F5FD4->unk0[0][var_v1->unk4];
        x = temp_v0_2->unk0;
        y = temp_v0_2->unk4;
        z = temp_v0_2->unk8;
        func_global_asm_80714998(2);
        func_global_asm_807149B8(1);
        func_global_asm_80714950(0);
        func_global_asm_8071498C(func_global_asm_8071C004);
        drawSpriteAtPosition(&D_global_asm_8071FB54, 0.667f, x, y + 10, z);
        var_v1->unk0 = 0x19;
    }
    var_v1->unk0--;
}

void func_global_asm_8064384C(Prop_ScriptData *arg0, s16 arg1, s32 arg2, s32 arg3) {
    Prop *temp_v1 = &D_global_asm_807F6000[func_global_asm_80659470(arg1)];

    func_global_asm_8067DF44(temp_v1->x_position, temp_v1->y_position, temp_v1->z_position, temp_v1->hitbox_scale, 0, 1);
}

void func_global_asm_806438B8(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 boneIndex) {
    s32 pad;
    s32 temp_s0;
    s32 i;
    f32 x, y, z;

    if (arg2 == 1) {
        func_global_asm_806335B0(arg1, 1, boneIndex, &x, &y, &z);
    } else {
        x = D_global_asm_807F621C;
        y = D_global_asm_807F6220;
        z = D_global_asm_807F6224;
    }
    func_global_asm_807149B8(0);
    func_global_asm_807149FC(1);
    func_global_asm_80714950(0x100C8);
    func_global_asm_8071498C(func_global_asm_8071A8B0);
    drawSpriteAtPosition(&D_global_asm_8071FE08, 1.5f, x, y, z);
    for (i = 0; i < 7; i++) {
        temp_s0 = (s32)(func_global_asm_806119A0() / 10000U) % 3;
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(0xA);
        func_global_asm_8071498C(func_global_asm_8071910C);
        func_global_asm_80714998(2);
        func_global_asm_80714950(7);
        switch (temp_s0) {
            case 0:
                drawSpriteAtPosition(&D_global_asm_8071FE64, 0.5f, x, y, z);
                break;
            case 1:
                drawSpriteAtPosition(&D_global_asm_8071FE88, 0.5f, x, y, z);
                break;
            case 2:
                drawSpriteAtPosition(&D_global_asm_8071FEAC, 0.5f, x, y, z);
                break;
        }
    }
}

void func_global_asm_80643B24(Prop_ScriptData *arg0, s16 arg1, s32 arg2, s32 arg3) {
    if ((object_timer % 5U) == 0) {
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        changeActorColor(0xFF, 0xFF, 0xFF, 0x96);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, 1.0f, arg1, 1, 0);
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        changeActorColor(0xFF, 0xFF, 0xFF, 0x96);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, 1.0f, arg1, 2, 0);
    }
}

typedef struct InstanceData80643C0C {
    s32 unk0;
    s32 unk4;
} InstanceData80643C0C;

void func_global_asm_80643C0C(Prop_ScriptData *arg0, s32 arg1, s16 arg2, s32 arg3) {
    f32 var_f2;
    f32 temp_f20;
    InstanceData80643C0C *var_v1;

    if (arg0->unk0 == NULL) {
        arg0->unk0 = malloc(sizeof(InstanceData80643C0C));
    }
    var_v1 = arg0->unk0;
    if (arg2 == 1) {
        var_v1->unk0 = 0;
    }
    temp_f20 = (0x46 - var_v1->unk0++) / 70.0f;
    if (temp_f20 > 0.5) {
        var_f2 = 1.0 - (2.0 * (temp_f20 - 0.5));
    } else {
        var_f2 = 2.0 * temp_f20;
    }
    createLight(D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224, 0.0f, 0.0f, 0.0f, 200.0f * var_f2, 0, 0xFF, (-80.0f * var_f2) + 255.0f, (-205.0f * var_f2) + 255.0f);
    if (0.6 < temp_f20) {
        if ((object_timer % 6U) == 0) {
            func_global_asm_807149FC(2);
            func_global_asm_807149B8(1);
            func_global_asm_80714950(-0x190);
            changeActorColor(0xFF, 0xFF, 0xFF, 1);
            func_global_asm_8071498C(func_global_asm_80717CE8);
            drawSpriteAtPosition(&D_global_asm_807201D4, 1.2f, D_global_asm_807F621C, D_global_asm_807F6220 + 30.0, D_global_asm_807F6224);
        }
    }
    if (temp_f20 < 0.1) {
        arg0->unk48[1] = 1;
    }
}

void func_global_asm_80643F38(Prop_ScriptData *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 i;
    for (i = 0; i < 0x1E; i++) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(1);
        func_global_asm_8071498C(func_global_asm_8071EA24);
        func_global_asm_8071496C(i / 7);
        drawSpriteAtPosition(D_global_asm_8074E880[i % 3], 1.4f, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
    }
}

s16 func_global_asm_80605044(s16, s16, s16, s16, s32, f32, s32);

typedef struct InstanceData8064409C {
    u32 unk0;
    s32 unk4;
    s32 unk8;
} InstanceData8064409C;

void func_global_asm_8064409C(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    InstanceData8064409C *temp_v0;

    if (arg0->unk0 == NULL) {
        temp_v0 = malloc(sizeof(InstanceData8064409C));
        arg0->unk0 = temp_v0;
        temp_v0->unk0 = 0;
        temp_v0->unk4 = 0;
    }
    temp_v0 = arg0->unk0;
    switch (temp_v0->unk0) {
    case 0:
        temp_v0->unk4++;
        if (temp_v0->unk4 == 4) {
            temp_v0->unk8 = 0;
            temp_v0->unk0++;
            if (arg0->unk10[0] < 0) {
                arg0->unk10[0] = func_global_asm_80605044(arg1, 0x12C, 0x3C, 1, 0x64, 1.0f, 0);
            }
        }
        break;
    case 1:
        temp_v0->unk4++;
        if (temp_v0->unk4 == 7) {
            temp_v0->unk4 = 4;
            temp_v0->unk8++;
            if (temp_v0->unk8 == 0x1E) {
                temp_v0->unk8 = 0;
                temp_v0->unk0++;
                if (arg0->unk10[0] >= 0) {
                    func_global_asm_80605380(arg0->unk10[0]);
                    arg0->unk10[0] = -1;
                }
                playSoundAtProp(arg1, 0x74, 0xFFU, 0x7FU, 0U, 0x50U, 0.3f);
            }
        }
        break;
    case 2:
        temp_v0->unk4 = 7;
        temp_v0->unk8++;
        if (temp_v0->unk8 == 0x28) {
            temp_v0->unk8 = 0;
            temp_v0->unk0++;
            playSoundAtProp(arg1, 0x74, 0xFFU, 0x7FU, 0U, 0x50U, 0.3f);
        }
        break;
    case 3:
        temp_v0->unk4 = 8;
        temp_v0->unk8++;
        if (temp_v0->unk8 == 0x28) {
            temp_v0->unk8 = 0;
            temp_v0->unk0++;
            playSoundAtProp(arg1, 0x75, 0xFFU, 0x7FU, 0U, 0x50U, 0.3f);
        }
        break;
    case 4:
        temp_v0->unk4 = 9;
        break;
    default:
        break;
    }
    func_global_asm_80635018(arg1, 1, temp_v0->unk4, 0);
}

void func_global_asm_8064431C(Prop_ScriptData *arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 x2, x1;
    f32 y2, y1;
    f32 z2, z1;

    func_global_asm_806335B0(arg1, 1, 1, &x1, &y1, &z1);
    func_global_asm_806335B0(arg1, 1, 2, &x2, &y2, &z2);
    createLight(x1, y1, z1, x2, y2, z2, 0.0f, 1, D_global_asm_807480D0, D_global_asm_807480D4, D_global_asm_807480D8);
}

void func_global_asm_80608DA8(s32, u8, s32, s32, s32);
extern f32 D_global_asm_80770DCC;
extern f32 D_global_asm_80770DD0;
extern f32 D_global_asm_80770DD4;
extern f32 D_global_asm_807480DC;
extern s8 D_global_asm_8077058C;
extern u8 D_global_asm_80770DC9;
extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;

typedef struct InstanceData806443E4 {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} InstanceData806443E4;

void func_global_asm_806443E4(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    InstanceData806443E4 *var_v1;
    f32 var_f16;
    f32 var_f14;
    f32 dx, dy, dz;

    // fake match
    if (gPlayerPointer->PaaD) {
    }

    if (gPlayerPointer->PaaD->unk1F0 & 0x20000000) {
        return;
    }
    if (arg0->unk0 == NULL) {
        var_v1 = malloc(0x10);
        arg0->unk0 = var_v1;
        var_v1->unk0 = 0;
        var_v1->unk4 = 0.0f;
        var_v1->unk8 = 0.0f;
        var_v1->unkC = 0.0f;
    }
    var_v1 = arg0->unk0;
    dz = character_change_array->look_at_eye_z - D_global_asm_807F6224;
    dx = character_change_array->look_at_eye_x - D_global_asm_807F621C;
    dy = character_change_array->look_at_eye_y - D_global_asm_807F6220;
    var_f16 = sqrtf(SQ(dz) + (SQ(dx) + SQ(dy)));
    if ((character_change_array->chunk == 0xE) && (is_cutscene_active != 1)) {
        var_f14 = 1.0f;
    } else if (character_change_array->chunk == 7) {
        var_f14 = 0.0f;
    } else {
        var_f16 -= sqrtf(SQ(D_global_asm_807F621C - 1714.0f) + SQ(D_global_asm_807F6220 - 226.0f) + SQ(D_global_asm_807F6224 - 3410.0f));
        if (var_f16 < 0.0) {
            var_f16 = 0.0f;
        }
        if (var_f16 > 600.0f) {
            var_f14 = 0.0f;
        } else {
            var_f14 = 1.0 - (var_f16 / 600.0f);
        }
    }
    if ((character_change_array->chunk == 0xE) || ((character_change_array->chunk == 0xB) && (var_f16 < D_global_asm_807480DC))) {
        func_global_asm_80711410(2.9f, -0x1E, var_f14, 0xE, MAX(0.05, var_f14));
    } else {
        D_global_asm_8077058C = 0;
    }
    if (RandClamp(50) == 0xF) {
        var_v1->unk0 = 0x28;
    }
    if (var_v1->unk0) {
        var_v1->unk0--;
        if (RandClamp(10) == 5) {
            if (var_f16 < 2200.0f) {
                if (D_global_asm_80770DC9 != 0) {
                    if (D_global_asm_80770DD4 < 600.0f) {
                        playSound(0x9C,
                            (s32) ((((var_f14 * 32767.0f * 60.0f) / 255.0f) * (600.0 - D_global_asm_80770DD4)) / 1000.0),
                                  D_global_asm_80770DCC,
                                  0.8f,
                                  0x1E,
                                  (u32) D_global_asm_80770DD0);
                    }
                } else {
                    func_global_asm_80608DA8(0x9C, var_f14 * 60.0f, 0x7F, 0x1E, (rand() >> 0xF) % 3);
                }
            }
            var_v1->unk4 = 1.0f;
            var_v1->unk8 = 1.0f;
            var_v1->unkC = 1.0f;
        }
    }
    var_v1->unk4 = ((0.4 - var_v1->unk4) * 0.2) + var_v1->unk4;
    var_v1->unk8 = ((0.3 - var_v1->unk8) * 0.2) + var_v1->unk8;
    var_v1->unkC = ((0.3 - var_v1->unkC) * 0.2) + var_v1->unkC;
    func_global_asm_80659670(var_v1->unk4, var_v1->unk8, var_v1->unkC, 0xE);
}

void func_global_asm_806449C0(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3) {
    func_global_asm_80714998(2);
    func_global_asm_807149B8(1);
    func_global_asm_80714B84(&D_global_asm_8071FBC8, 1.5f, arg1, arg2, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_80644A18.s")

typedef struct InstanceData80644CC0 {
    f32 unk0;
    f32 unk4;
} InstanceData80644CC0;

f32 func_global_asm_80627A00(f64, f32, s32, s32, s16, f32, f32, f32);

void func_global_asm_80644CC0(void **arg0, s32 arg1, s32 arg2, s32 arg3) {
    InstanceData80644CC0 *var_v1;

    if (*arg0 == NULL) {
        var_v1 = malloc(8);
        *arg0 = var_v1;
        var_v1->unk0 = 0.0f;
        var_v1->unk4 = 0.0f;
    }
    var_v1 = *arg0;
    func_global_asm_80644A18(var_v1, 2, 0x16, 1.0f);
    func_global_asm_80644A18(&var_v1->unk4, 4, 0x18, 0.8f);
}

void func_global_asm_80644D50(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 x2, x1;
    f32 y2, y1;
    f32 z2, z1;

    func_global_asm_806335B0(arg1, 1, 1, &x1, &y1, &z1);
    func_global_asm_806335B0(arg1, 1, 2, &x2, &y2, &z2);
    func_global_asm_8065A660(D_global_asm_807480E0, D_global_asm_807480E4);
    createLight(x1, y1, z1, x2, y2, z2, 0.0f, 1, D_global_asm_807480D0, D_global_asm_807480D4, D_global_asm_807480D8);
}

void func_global_asm_80644E2C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_global_asm_807149FC(-1);
    func_global_asm_8071498C(func_global_asm_80717760);
    func_global_asm_80714950(0x50);
    drawSpriteAtPosition(D_global_asm_8074E880[RandClamp(1000) % 3], 0.5f, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
}

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80645700_sp20;

void func_global_asm_80644EC8(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    u32 sp2C;

    if (((func_global_asm_806119A0() / 10000U) % arg2) == 0) {
        sp2C = (func_global_asm_806119A0() / 10000U) % arg3;
        func_global_asm_80714998(2);
        func_global_asm_80714950(0x10064);
        func_global_asm_8071498C(func_global_asm_8071AADC);
        changeActorColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawSpriteAtPosition(&D_global_asm_80720A7C, 1.2f, D_global_asm_807F5FD4->unk0[0][sp2C].unk0, D_global_asm_807F5FD4->unk0[0][sp2C].unk4, D_global_asm_807F5FD4->unk0[0][sp2C].unk8);
    }
    if (((func_global_asm_806119A0() / 10000U) % arg2) == 0) {
        sp2C = (func_global_asm_806119A0() / 10000U) % arg3;
        func_global_asm_80714998(2);
        func_global_asm_80714950(0x10064);
        func_global_asm_8071498C(func_global_asm_8071AADC);
        changeActorColor(0xFF, 0xFF, 0xFF, 0xFF);
        drawSpriteAtPosition(&D_global_asm_80720A7C, 1.2f, D_global_asm_807F5FD4->unk0[1][sp2C].unk0, D_global_asm_807F5FD4->unk0[1][sp2C].unk4, D_global_asm_807F5FD4->unk0[1][sp2C].unk8);
    }
}

void func_global_asm_806450C0(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    u32 temp_hi;
    f32 sp30;

    if (((func_global_asm_806119A0() / 10000U) % 10) == 0) {
        temp_hi = (func_global_asm_806119A0() / 10000U) % arg3;
        sp30 = D_global_asm_807F5FD4->unk0[arg2][temp_hi].unk4;
        if (func_global_asm_80667110(D_global_asm_807F5FD4->unk0[arg2][temp_hi].unk0, D_global_asm_807F5FD4->unk0[arg2][temp_hi].unk8, &sp30) != 0) {
            func_global_asm_80714950(sp30 + 2.0);
            func_global_asm_8071498C(func_global_asm_80718188);
            func_global_asm_807149FC(-1);
            func_global_asm_807149B8(1);
            changeActorColor(0xFF, 0xFF, 0xFF, D_global_asm_807480EF);
            drawSpriteAtPosition(&D_global_asm_80720CD8, D_global_asm_807480E8, D_global_asm_807F5FD4->unk0[arg2][temp_hi].unk0, D_global_asm_807F5FD4->unk0[arg2][temp_hi].unk4, D_global_asm_807F5FD4->unk0[arg2][temp_hi].unk8);
        }
    }
}

void func_global_asm_80645238(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 randomZOffset;
    f32 randomXOffset;
    f32 _randomScaleOffset;
    void *sprite;
    f64 randomScaleOffset;
    s32 pad;
    s32 randomSpriteIndex;
    s32 i;

    for (i = 0; i < 0x14; i++) {
        randomSpriteIndex = (s32)(func_global_asm_806119A0() / 10000) % 4;
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(0x3C);
        func_global_asm_8071498C(func_global_asm_8071910C);
        func_global_asm_80714998(2);
        func_global_asm_80714950(2);
        switch (randomSpriteIndex) {
            case 0:
                sprite = &D_global_asm_80720E44;
                break;
            case 1:
                sprite = &D_global_asm_80720E5C;
                break;
            case 2:
                sprite = &D_global_asm_80720E74;
                break;
            case 3:
                sprite = &D_global_asm_80720E8C;
                break;
        }
        drawSpriteAtPosition(sprite, 0.5f, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
    }
    for (i = 0; i < 6; i++) {
        randomXOffset = (func_global_asm_806119A0() / 1000) % 150;
        randomXOffset -= 75.0;
        randomZOffset = (func_global_asm_806119A0() / 1000) % 150;
        randomZOffset -= 75.0;
        randomScaleOffset = (func_global_asm_806119A0() / 1000) % 50;
        _randomScaleOffset = ((f32)(randomScaleOffset - 25.0)) / 50.0;
        if (i == 0) {
            func_global_asm_80714950(0x100FA);
            func_global_asm_8071498C(func_global_asm_8071A8B0);
        } else {
            func_global_asm_80714950(-0xAA);
            func_global_asm_8071498C(func_global_asm_80717D4C);
        }
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        changeActorColor(0xFF, 0xFF, 0xFF, 0x64);
        drawSpriteAtPosition(
            &D_global_asm_8071FFA0,
            _randomScaleOffset + 3.5,
            D_global_asm_807F621C + randomXOffset,
            D_global_asm_807F6220 + 30.0,
            D_global_asm_807F6224 + randomZOffset
        );
    }
}

void func_global_asm_80645614(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    u32 sp24;

    if (((func_global_asm_806119A0() / 10000U) % arg2) == 0) {
        sp24 = (func_global_asm_806119A0() / 10000U) % arg3;
        func_global_asm_80714998(2);
        func_global_asm_80714950(0x10064);
        func_global_asm_8071498C(func_global_asm_8071AADC);
        changeActorColor(0xFF, 0xFF, 0xFF, 0xFF);
        func_global_asm_807149B8(1);
        func_global_asm_80714B84(&D_global_asm_80720A7C, 0.5f, arg1, sp24 + 1, 0);
    }
}

void func_global_asm_80645700(Struct80645700_sp20 **arg0, s32 arg1, s16 arg2, s16 arg3) {
    u32 sp24;
    Struct80645700_sp20 *var_v1;
    Struct807F5FD4 *temp;

    if (*arg0 == NULL) {
        if (arg3) {
            var_v1 = malloc(8);
            *arg0 = var_v1;
            var_v1->unk0 = 0.0f;
            var_v1->unk4 = 0.0f;
        }
    }
    var_v1 = *arg0;
    sp24 = (func_global_asm_806119A0() / 10000U) % arg2;
    func_global_asm_807149B8(1);
    func_global_asm_80714998(3);
    func_global_asm_80714950(3);
    func_global_asm_8071498C(func_global_asm_8071E3EC);
    func_global_asm_807149A8(0x7D0);
    drawSpriteAtPosition(&D_global_asm_80720BC4, 2.5f, D_global_asm_807F5FD4->unk0[0][sp24].unk0, D_global_asm_807F5FD4->unk0[0][sp24].unk4, D_global_asm_807F5FD4->unk0[0][sp24].unk8);
    if (arg3) {
        if (gPlayerPointer->control_state == 0x42) {
            var_v1->unk0 = gPlayerPointer->y_position;
        }
        if (((var_v1->unk0 - gPlayerPointer->y_position) > 200.0) || gPlayerPointer->y_position < 10.0f) {
            if (var_v1->unk4 == 0.0) {
                func_global_asm_805FF9AC(0x48, 0x1C, 0, 0);
                var_v1->unk4 = 1.0f;
            }
        }
    }
}

void func_global_asm_806458C8(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    s16 sp2E;
    s16 sp2C;

    if (((u32)object_timer % arg2) == 0) {
        sp2E = RandClamp(2048) + (((D_global_asm_807F622C * 4096.0f) / 360.0f) - 1024.0f);
        sp2C = (RandClamp(32767) % 6) + 0xF;
        func_global_asm_80714950(-0x32 - RandClamp(80));
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(2);
        drawSpriteAtPosition(&D_global_asm_8071FFA0, 1.0f, (func_global_asm_80612794(sp2E) * sp2C) + D_global_asm_807F621C, D_global_asm_807F6220 + 50.0f, (func_global_asm_80612790(sp2E) * sp2C) + D_global_asm_807F6224);
    }
}

void func_global_asm_80645A64(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    s16 i;

    for (i = 0; i < arg2; i++) {
        func_global_asm_80714950(-0x96 - RandClamp(80));
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(2);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, 1.0f, arg1, i + 1, 0);
    }
}

void func_global_asm_80645B9C(gASMStruct3 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    if (((s32) (0x243 - arg0->unk44) % 60) == 0) {
        playSoundAtProp(arg1, 0x38, 0xFF, 0x7F, 0, 0x3C, 0.0f);
    }
}

void func_global_asm_80645C04(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 x, y, z;

    func_global_asm_806335B0(arg1, 1, 1, &x, &y, &z);
    func_global_asm_80659610(2500);
    func_global_asm_80659600(9);
    func_global_asm_806595F0(2);
    createLight(x, y, z, 0.0f, 0.0f, 0.0f, 600.0f, 0, 0xFF, 0xFF, 0xFF);
    func_global_asm_80659610(2500);
    func_global_asm_80659600(0xA);
    func_global_asm_806595F0(2);
    createLight(x, y, z, 0.0f, 0.0f, 0.0f, 600.0f, 0, 0xFF, 0xFF, 0xFF);
}

typedef struct {
    u8 unk0[0x90 - 0x0];
    f32 unk90;
    u8 unk94[0xFA - 0x94];
    u8 unkFA;
} AAD_global_asm_80645D14;

void func_global_asm_80645D14(s32 **arg0, s32 arg1, s16 arg2, s32 arg3) {
    s32 *var_v1;
    s32 pad;
    s32 pad2;
    AAD_global_asm_80645D14 *aaD;
    u8 sp1F;
    PlayerAdditionalActorData *PaaD;
    Actor *temp;

    sp1F = FALSE;
    if (*arg0 == NULL) {
        *arg0 = malloc(4);
        var_v1 = *arg0;
        *var_v1 = 1;
    }
    var_v1 = *arg0;
    PaaD = character_change_array->playerPointer->PaaD;
    temp = PaaD->unk104;
    aaD = temp->additional_actor_data;
    if (aaD->unkFA != 0) {
        if (character_change_array->look_at_eye_y < (aaD->unk90 + 3.0f)) {
            sp1F = TRUE;
        }
    }
    if (*var_v1 != 0) {
        if (sp1F == 0) {
            if (arg2 == 9) {
                func_global_asm_80656E58(9, 4, 1, 0);
                func_global_asm_80656E58(9, 5, 1, 0);
                func_global_asm_80656E58(9, 6, 1, 0);
            } else {
                func_global_asm_80656E58(0xF, 0xF, 1, 0);
                func_global_asm_80656E58(0xE, 0x11, 1, 0);
                func_global_asm_80656E58(0xD, 0x13, 1, 0);
                func_global_asm_80656E58(0xC, 0x15, 1, 0);
            }
            *var_v1 = 0;
        }
    }
    if (*var_v1 == 0) {
        if (sp1F != 0) {
            if (arg2 == 9) {
                func_global_asm_80656E58(9, 4, 1, 1);
                func_global_asm_80656E58(9, 5, 1, 1);
                func_global_asm_80656E58(9, 6, 1, 1);
            } else {
                func_global_asm_80656E58(0xF, 0xF, 1, 1);
                func_global_asm_80656E58(0xE, 0x11, 1, 1);
                func_global_asm_80656E58(0xD, 0x13, 1, 1);
                func_global_asm_80656E58(0xC, 0x15, 1, 1);
            }
            *var_v1 = 1;
        }
    }
}

void func_global_asm_80645F40(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;
    f32 phi_f22 = 0.0f;

    if ((object_timer & 0xF) == 0) {
        f64 temp_f26 = 0.05;
        f64 temp_f24 = 1.1;
        f64 temp;
        void* test = &D_global_asm_80720B00;
        for (i = 1; i < 0xB; i++) {
            func_global_asm_807149B8(1);
            func_global_asm_80714998(2);
            func_global_asm_8071498C(func_global_asm_8071EB70);
            func_global_asm_80714950(700);
            func_global_asm_807149A8(700);
            func_global_asm_80714B84(test, phi_f22 + temp_f24, arg1, i, 1);
            phi_f22 += temp_f26;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_80646058.s")

extern f32 D_global_asm_807480F0;
typedef struct InstanceData80646770 {
    s32 unk0;
} InstanceData80646770;

void func_global_asm_80646770(Prop_ScriptData *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 old;
    s32 count;
    InstanceData80646770 *var_v1;
    u8 found;

    found = FALSE;
    if (arg0->unk0 == NULL) {
        var_v1 = arg0->unk0 = malloc(sizeof(InstanceData80646770));
        var_v1->unk0 = 0;
    }
    var_v1 = arg0->unk0;
    old = var_v1->unk0;
    count = D_global_asm_807F5FD4->unk0[1] - D_global_asm_807F5FD4->unk0[0];
    if (count == ++var_v1->unk0) {
        var_v1->unk0 = 0;
    }
    while (!found && old != var_v1->unk0) {
        if (sqrtf(
            SQ((character_change_array->look_at_eye_x - D_global_asm_807F5FD4->unk0[0][var_v1->unk0].unk0)) +
            SQ((character_change_array->look_at_eye_y - D_global_asm_807F5FD4->unk0[0][var_v1->unk0].unk4)) +
            SQ((character_change_array->look_at_eye_z - D_global_asm_807F5FD4->unk0[0][var_v1->unk0].unk8))) < D_global_asm_807480F0) {
            found = TRUE;
            func_global_asm_807149B8(1);
            func_global_asm_80714998(3);
            func_global_asm_80714950(0);
            func_global_asm_8071498C(func_global_asm_8071E3EC);
            func_global_asm_807149A8(0x320);
            drawSpriteAtPosition(
                &D_global_asm_80720BC4,
                2.5f,
                D_global_asm_807F5FD4->unk0[0][var_v1->unk0].unk0,
                D_global_asm_807F5FD4->unk0[0][var_v1->unk0].unk4,
                D_global_asm_807F5FD4->unk0[0][var_v1->unk0].unk8
            );
        } else {
            if (count == ++var_v1->unk0) {
                var_v1->unk0 = 0;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_80646978.s")

typedef struct Struct80748154 {
    u8 pad0[3];
    u8 unk3;
} Struct80748154;

extern f32 D_global_asm_8074811C;
extern f32 D_global_asm_80748120;
extern f32 D_global_asm_80748124;
extern f32 D_global_asm_80748128;
extern s32 D_global_asm_8074812C;
extern s32 D_global_asm_80748130;
extern f32 D_global_asm_80748140;
extern f32 D_global_asm_80748144;
extern s32 D_global_asm_80748148;
extern f32 D_global_asm_8074814C;
extern s32 D_global_asm_80748150;
extern Struct80748154 D_global_asm_80748154;
extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;

/*
void func_global_asm_80646978(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    tuple_f sp88;
    f64 dx, dy, dz;
    s16 i;
    s32 j;

    for (i = 0; i < D_global_asm_80748148; i++) {
        dx = (func_global_asm_806119A0() / 1000U) % 100U;
        dy = (func_global_asm_806119A0() / 1000U) % 100U;
        dz = (func_global_asm_806119A0() / 1000U) % 100U;
        func_global_asm_8071496C(i);
        func_global_asm_807149B8(1U);
        if (i == 0) {
            func_global_asm_80714950(D_global_asm_80748150 + 0x10000);
            func_global_asm_8071498C(func_global_asm_8071AADC);
            func_global_asm_80714998(D_global_asm_80748154.unk3);
        } else {
            func_global_asm_8071498C(func_global_asm_8071BB14);
        }
        drawSpriteAtPosition(&D_global_asm_80720BE8,
            D_global_asm_80748140,
            D_global_asm_807F621C + (dx - 50.0),
            D_global_asm_807F6220 + (dy - 50.0),
            D_global_asm_807F6224 + (dz - 50.0));
    }
    for (j = 0; j < 0xC; j++) {
        func_global_asm_8071498C(func_global_asm_8071E864);
        func_global_asm_80714950(i);
        func_global_asm_807149B8(1);
        changeActorColor(0x8CU, 0x8CU, 0x8CU, 0xFFU);
        func_global_asm_80714998(3U);
        drawSpriteAtPosition(&D_global_asm_8071FFA0,
            D_global_asm_80748144,
            D_global_asm_807F621C,
            D_global_asm_807F6220 + D_global_asm_8074814C,
            D_global_asm_807F6224);
    }
    for (j = 0; j < 0x1130; j += 0x190) {
        sp88.x = RandClamp(D_global_asm_8074812C) + D_global_asm_80748120;
        sp88.y = j;
        sp88.z = RandClamp(D_global_asm_80748130) + D_global_asm_80748124;
        func_global_asm_806891D8(0x5A,
            D_global_asm_807F621C,
            D_global_asm_807F6220 + D_global_asm_8074811C,
            D_global_asm_807F6224, 0,
            D_global_asm_80748128,
            NULL, &sp88);
    }
}
*/

void func_global_asm_80646DC4(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 pad2;
    f32 x, y, z;
    s32 pad[6];
    f32 var_f28;
    s32 i;
    f32 sp84[3];
    s32 var_s5;

    if (arg2 != 0) {
        for (i = 1; i < 7; i++) {
            func_global_asm_806335B0(arg1, 1, i, &x, &y, &z);
            func_global_asm_8071496C(i);
            func_global_asm_807149B8(1);
            func_global_asm_8071498C(func_global_asm_8071BB14);
            changeActorColor(0xFF, 0xFF, 0xFF, 0x96);
            drawSpriteAtPosition(&D_global_asm_80720BE8, 1.5f, x, y, z);
        }
        return;
    }
    var_f28 = 0.3f;
    var_s5 = 7;
    if (arg3 != 0) {
        var_f28 = 0.2f;
        var_s5 = 0xA;
    }
    for (i = 1; i < var_s5; i++) {
        sp84[0] = (rand() % 300) + 300;
        sp84[1] = i * 0x2A8;
        sp84[2] = (rand() % 500) + 150;
        if (arg3 == 0) {
            func_global_asm_806335B0(arg1, 1, i, &x, &y, &z);
            y += 10.0;
        } else {
            x = ((func_global_asm_806119FC() * 30.0) + D_global_asm_807F621C) - 15.0;
            y = (func_global_asm_806119FC() * 40.0) + D_global_asm_807F6220;
            z = ((func_global_asm_806119FC() * 30.0) + D_global_asm_807F6224) - 15.0;
        }
        func_global_asm_806891D8(0x5A, x, y, z, 0, var_f28, NULL, &sp84[0]);
    }
}

void func_global_asm_80647108(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    func_global_asm_80714950(-0x78);
    func_global_asm_8071498C(func_global_asm_80717D4C);
    func_global_asm_807149B8(1);
    func_global_asm_80714998(3);
    func_global_asm_80714B84(&D_global_asm_8071FFA0, 1.5f, arg1, 1, 0);
}

void func_global_asm_80647170(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    f32 x, y, z;
    s32 green, blue;

    func_global_asm_806335B0(arg1, 1, 2, &x, &y, &z);
    if (arg2 != 0) {
        green = 0;
        blue = 0;
    } else {
        green = 0xFF;
        blue = 0xC8;
    }
    createLight(x, y, z, 0.0f, 0.0f, 0.0f, 80.0f, 0, 0xFF, green, blue);
}

void func_global_asm_80647218(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    f32 randomXOffset, randomYOffset, randomZOffset;
    f32 randomScaleOffset;

    for (i = 0; i < 6; i++) {
        randomXOffset = (f32)((func_global_asm_806119A0() / 1000U) % 20) - 10.0;
        randomYOffset = (f32)((func_global_asm_806119A0() / 1000U) % 20) - 10.0;
        randomZOffset = (f32)((func_global_asm_806119A0() / 1000U) % 20) - 10.0;
        randomScaleOffset = (f32)((f32)(((func_global_asm_806119A0() / 1000U) % 50) - 25.0) / 50.0);
        func_global_asm_80714950(-0xAA);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        func_global_asm_8071496C(i << 1);
        drawSpriteAtPosition(&D_global_asm_8071FFA0, (randomScaleOffset) + 1.5, D_global_asm_807F621C + (randomXOffset), D_global_asm_807F6220 + (randomYOffset), D_global_asm_807F6224 + (randomZOffset));
    }
}

void func_global_asm_80647508(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 sp34;
    f32 x, y, z;

    sp34 = ((func_global_asm_806119A0() / 1000U) % 10) + 1;
    func_global_asm_80714950(-0x28A - ((func_global_asm_806119A0() / 1000U) % 200));
    func_global_asm_8071498C(func_global_asm_80717D4C);
    func_global_asm_807149B8(1);
    func_global_asm_80714998(9);
    changeActorColor(0xFF, 0xFF, 0xFF, 0x64);
    func_global_asm_80714944(5);
    func_global_asm_806335B0(arg1, 1, sp34, &x, &y, &z);
    drawSpriteAtPosition(&D_global_asm_8071FFA0, 1.5f, x, y - 70, z);
}

typedef struct InstanceData80647610 {
    s32 unk0;
} InstanceData80647610;

void func_global_asm_80647610(Prop_ScriptData *arg0, s32 arg1, s16 arg2, s16 arg3) {
    s32 pad;
    s32 pad2;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    Struct807F5FD4_unk0 *temp_v0_2;
    InstanceData80647610 *var_v1;
    s32 var_a1;

    if (arg0->unk0 == NULL) {
        var_v1 = malloc(sizeof(InstanceData80647610));
        arg0->unk0 = var_v1;
        var_v1->unk0 = 0;
    }
    var_v1 = arg0->unk0;
    var_v1->unk0++;
    if (arg3 == var_v1->unk0) {
        var_v1->unk0 = 0;
    }
    temp_v0_2 = &D_global_asm_807F5FD4->unk0[arg2][var_v1->unk0];
    sp2C = temp_v0_2->unk0;
    sp28 = temp_v0_2->unk4;
    sp24 = temp_v0_2->unk8;
    func_global_asm_80714998(2);
    func_global_asm_807149B8(1);
    changeActorColor(0xFF, 0xFF, 0xFF, 0xC8);
    drawSpriteAtPosition(&D_global_asm_80720DE0, 1.0f, sp2C, sp28 + 0xA, sp24);
}

void func_global_asm_8064774C(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;

    for (i = 1; i < 0xF; i++) {
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        changeActorColor(0xFF, 0xFF, 0xFF, D_global_asm_80748168.unk3);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, D_global_asm_8074816C, arg1, i, 0);
    }
}

void func_global_asm_80647834(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;
    f32 randomYOffset;

    for (i = 0; i < 0xC; i++) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(0x3C);
        func_global_asm_8071498C(func_global_asm_8071910C);
        func_global_asm_80714998(2);
        func_global_asm_80714950(4);
        randomYOffset = ((func_global_asm_806119A0() / 1000U) % 80);
        drawSpriteAtPosition(&D_global_asm_80720EA4, 1.0f, D_global_asm_807F621C, D_global_asm_807F6220 + randomYOffset, D_global_asm_807F6224);
    }
    for (i = 1; i != 6; i++) {
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        changeActorColor(0xFF, 0xFF, 0xFF, 0x78);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, 3.0f, arg1, i, 0);
    }
}

void func_global_asm_80647A14(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    f32 temp_f26;
    f32 var_f20;

    temp_f26 = 682.0f;
    var_f20 = 0.0f;
    for (i = 0; i < 6; i++) {
        func_global_asm_8071496C(i << 1);
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(7);
        func_global_asm_8071498C(func_global_asm_8071F1D0);
        func_global_asm_80714998(1);
        func_global_asm_80714950(var_f20);
        drawSpriteAtPosition(&D_global_asm_8071FC8C, 0.5f, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
        func_global_asm_80714950(var_f20 + 2048.0f);
        drawSpriteAtPosition(&D_global_asm_8071FC8C, 0.5f, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
        var_f20 += temp_f26;
    }
}

typedef struct InstanceData80647B74 {
    u32 unk0;
    s32 unk4;
} InstanceData80647B74;

void func_global_asm_80647B74(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    InstanceData80647B74 *var_v1;

    if (arg0->unk0 == NULL) {
        var_v1= malloc(sizeof(InstanceData80647B74));
        arg0->unk0 = var_v1;
        var_v1->unk0 = 0;
        var_v1->unk4 = 0;
    }
    var_v1 = arg0->unk0;
    if ((var_v1->unk0 + 0x32) < object_timer) {
        if (RandChance(0.15)) {
            var_v1->unk4 = 1;
            var_v1->unk0 = object_timer;
        }
    }
    if (!var_v1->unk4) {
        return;
    }
    switch (var_v1->unk4) {
        case 1:
            func_global_asm_80635018(arg1, 1, 1, 0);
            break;
        case 3:
            func_global_asm_80635018(arg1, 1, 2, 0);
            break;
        case 5:
            func_global_asm_80635018(arg1, 1, 1, 0);
            break;
        case 7:
            func_global_asm_80635018(arg1, 1, 0, 0);
            var_v1->unk4 = 0;
            break;
    }
    if (var_v1->unk4) {
        var_v1->unk4++;
    }
}

void func_global_asm_80647CF4(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    func_global_asm_80714998(2);
    if (arg2 != 0) {
        drawSpriteAtPosition(&D_global_asm_8071FBC8, 3.0, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
        return;
    }
    func_global_asm_80714B84(&D_global_asm_8071FBC8, 3.0, arg1, 1, 0);
}

void func_global_asm_80647D7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 randomX, randomZ, randomY;
    s32 i;

    if (!((func_global_asm_806119A0() / 10000U) & 1)) {
        for (i = 0; i < 0xC; i++) {
            randomX = (f32)((func_global_asm_806119A0() / 10000U) % 200) * 0.25 - 2.0;
            randomY = (f32)((func_global_asm_806119A0() / 10000U) % 200) * 0.25 - 2.0;
            randomZ = (f32)((func_global_asm_806119A0() / 10000U) % 200) * 0.25 - 2.0;
            func_global_asm_807149B8(1);
            func_global_asm_80714950(1);
            func_global_asm_807149FC(-1);
            func_global_asm_8071498C(func_global_asm_80718BF4);
            drawSpriteAtPosition(
                &D_global_asm_8071FC40,
                0.0f,
                D_global_asm_807F621C + randomX,
                D_global_asm_807F6220 + randomY,
                D_global_asm_807F6224 + randomZ
            );
        }
    }
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_80648000.s")

/*
void func_global_asm_80648000(Prop_ScriptData *arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 (*temp_s0)[4];
    f32 (*temp_v0)[4];

    if (arg0->unk0 == NULL) {
        if (arg0->unk9A & 1) {
            arg0->unk0 = malloc(0x44);
            temp_v0 = arg0->unk0;
            func_global_asm_806335B0(arg1, 1, 1, &sp40, &temp_v0[4][0], &sp38);
            temp_v0[4][0] = temp_v0[4][0] - 10.0;
            guRotateF(temp_v0, D_global_asm_807F622C, 0.0f, 1.0f, 0.0f);
        }
    }
    if (arg0->unk9A & 1) {
        if (((func_global_asm_806119A0() / 10000U) % 20) == 0) {
            temp_s0 = arg0->unk0;
            sp48 = RandClamp(100) / 100.0;
            guMtxXFMF(temp_s0, (sp48 * 100.0) + -50.0, 0.0f, ((RandClamp(100) / 100.0) * 150.0) + -75.0, &sp40, &sp3C, &sp38);
            sp40 = (sp40 * D_global_asm_807F6234) + D_global_asm_807F621C;
            sp38 = (sp38 * D_global_asm_807F6234) + D_global_asm_807F6224;
            func_global_asm_807149B8(1);
            func_global_asm_80714950(2);
            func_global_asm_807149FC(-1);
            func_global_asm_8071498C(func_global_asm_80718BF4);
            drawSpriteAtPosition(&D_global_asm_8071FC40, 0.0f, sp40, temp_s0[4][0], sp38);
        }
    }
}
*/

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Struct8064826C_malloc;

typedef struct {
    Struct8064826C_malloc *unk0;
} Struct8064826C_arg0;

void func_global_asm_8064826C(Struct8064826C_arg0 *arg0, s32 arg1, s16 arg2, s32 arg3) {
    void *sprite;
    f32 sp38;
    s32 pad2;
    s32 pad;
    f32 xOffset;
    f32 zOffset;
    f32 temp_f0;
    Struct8064826C_malloc *temp_v0;

    xOffset = func_global_asm_80612794(((D_global_asm_807F622C + 90.0f) * 4096.0f) / 360.0f) * 15.0f;
    zOffset = func_global_asm_80612790(((D_global_asm_807F622C + 90.0f) * 4096.0f) / 360.0f) * 15.0f;
    if (arg0->unk0 == NULL) {
        arg0->unk0 = malloc(sizeof(Struct8064826C_malloc));
        temp_v0 = arg0->unk0;
        temp_v0->unk0 = 0;
        temp_v0->unk4 = 0;
        temp_v0->unk8 = 0;
    }
    temp_v0 = arg0->unk0;
    func_global_asm_807149B8(1);
    switch (arg2) {
        case 0:
            sprite = &D_global_asm_80721200;
            break;
        case 1:
            sprite = &D_global_asm_8072121C;
            break;
        case 2:
            sprite = &D_global_asm_80721250;
            break;
        case 3:
            sprite = &D_global_asm_80721238;
            break;
    }
    sp38 = func_global_asm_80612794(temp_v0->unk0) * 0.1;
    temp_f0 = func_global_asm_80612794(temp_v0->unk4);
    temp_v0->unk0 += 0x32;
    temp_v0->unk4 += 0x64;
    func_global_asm_80714A08(sp38 + 1.0, (f32)(temp_f0 * 0.1) + 1.0);
    func_global_asm_807149A8(1400);
    func_global_asm_80714A28(4);
    drawSpriteAtPosition(sprite, 0.0f, D_global_asm_807F621C + xOffset, (func_global_asm_80612794(temp_v0->unk8) * 10.0) + (D_global_asm_807F6220 + 80.0), D_global_asm_807F6224 + zOffset);
    temp_v0->unk8 += 0x64;
    if ((D_global_asm_8076A068 % 12) == 0) {
        func_global_asm_807149B8(1);
        func_global_asm_80714950(0x5A);
        func_global_asm_8071498C(func_global_asm_80716F10);
        func_global_asm_807149A8(1400);
        func_global_asm_80714A28(4);
        drawSpriteAtPosition(&D_global_asm_8072126C, 2.0f, D_global_asm_807F621C + xOffset, D_global_asm_807F6220 + 30.0, D_global_asm_807F6224 + zOffset);
    }
}

void func_global_asm_806485A0(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f26;
    s32 pad;
    f32 temp_f30;
    s16 temp_v0;
    s32 temp_v1;
    s32 i;
    f32 sp80;

    temp_v0 = arg2 >> 8;
    temp_f30 = arg2 & 0xFF;
    temp_v1 = arg3 & 0xFF;
    switch (temp_v0) {
        case 0:
            sp80 = 1; // doesn't match if 1.0f for some reason
            break;
        case 1:
            sp80 = 4.0f;
            break;
    }
    for (i = 0; i < temp_v1; i++) {
        func_global_asm_8071496C(func_global_asm_806119FC() * (arg3 >> 8));
        do {
            temp_f22 = (2.0f * func_global_asm_806119FC()) - 1.0f;
            temp_f20 = (2.0f * func_global_asm_806119FC()) - 1.0f;
            temp_f26 = (2.0f * func_global_asm_806119FC()) - 1.0f;
            temp_f0 = sqrtf(SQ(temp_f22) + SQ(temp_f20) + SQ(temp_f26));
        } while (temp_f0 < 0.05f);
        temp_f0 = temp_f30 / temp_f0;
        temp_f22 *= temp_f0;
        temp_f20 *= temp_f0;
        temp_f20 += temp_f30;
        temp_f26 *= temp_f0;
        drawSpriteAtPosition(&D_global_asm_8071FF18, sp80 * 1.5, D_global_asm_807F621C + temp_f22, D_global_asm_807F6220 + temp_f20, D_global_asm_807F6224 + temp_f26);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_806487C4.s")

int func_global_asm_80648C50(void) {
    s16 chunk = character_change_array[0].chunk;
    switch (chunk) {
        case 4:
        case 0xC:
            return TRUE;
        default:
            return FALSE;
    }
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_80648C84.s")

void func_global_asm_8064911C(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;

    for (i = 1; i < 8; i++) {
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        changeActorColor(0xFF, 0xFF, 0xFF, 0x96);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, 3.5f, arg1, i, 0);
    }
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_806491F4.s")

extern s8 D_global_asm_80748170[];
extern s8 D_global_asm_80748178;
extern s16 D_global_asm_807505B0[];

extern u8 D_global_asm_807446F0[];

/*
void func_global_asm_806491F4(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 pad;
    s32 sp28;
    s32 levelIndex;
    s32 var_v0;
    s8 temp;

    if (arg2 == 0) {
        levelIndex = getLevelIndex(D_global_asm_8076A0AB, 0);
        if (levelIndex >= 8) {
            levelIndex = 0;
        }
        sp28 = D_global_asm_807446F0[levelIndex];
        if (isFlagSet(D_global_asm_80744710[levelIndex], 0)) {
            func_global_asm_80635018(arg1, 1, 0xB, 0);
            func_global_asm_80635018(arg1, 2, 0xB, 0);
        } else if (func_global_asm_805FF0C8()) {
            func_global_asm_80635018(arg1, 1, D_global_asm_80748170[sp28], 0);
            func_global_asm_80635018(arg1, 2, D_global_asm_80748170[sp28], 0);
        } else {
            func_global_asm_80635018(arg1, 1, 0xA, 0);
            func_global_asm_80635018(arg1, 2, 0xA, 0);
        }
    } else {
        temp = D_global_asm_80748178 + 1;
        if (temp >= 0x15) {
            temp = 0;
        }
        D_global_asm_80748178 = temp;
        var_v0 = D_global_asm_80748170[temp >> 2];
        if (temp >> 2 > 0 && !isFlagSet(D_global_asm_807505B0[temp >> 2], 0)) {
            pad = 5;
        } else {
            pad = 0;
        }
        func_global_asm_80635018(arg1, 1, var_v0 + pad, 0);
        func_global_asm_80635018(arg1, 2, var_v0 + pad, 0);
    }
}
*/

void func_global_asm_806493C4(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    u8 temp_s1;
    s32 i;

    for (i = 0; i < arg2; i++) {
        temp_s1 = (RandClamp(32767) % (arg3 + 1));
        func_global_asm_807149B8(1);
        func_global_asm_807149A8(0x7D0);
        func_global_asm_8071498C(func_global_asm_8071F660);
        func_global_asm_807149FC(8);
        drawSpriteAtPosition(&D_global_asm_80721298, 1.0f, D_global_asm_807F5FD4->unk0[0][temp_s1].unk0, D_global_asm_807F5FD4->unk0[0][temp_s1].unk4, D_global_asm_807F5FD4->unk0[0][temp_s1].unk8);
    }
}

void func_global_asm_8064954C(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 levelIndex;
    s32 var_s2;
    s32 var_v1;

    levelIndex = getLevelIndex(D_global_asm_8076A0AB, 0);
    if (levelIndex >= 8) {
        levelIndex = 7;
    }
    var_v1 = D_global_asm_807446C0[levelIndex] - D_global_asm_807FC930[levelIndex];
    if (var_v1 < 0) {
        var_v1 = 0;
    }
    var_s2 = var_v1;
    for (i = 1; i != 4; i++) {
        func_global_asm_80635018(arg1, i, ((0xA - i) + (var_s2 % 10)) % 10, 0);
        var_s2 /= 10;
    }
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_806496B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_80649BF0.s")

typedef struct Struct80748180 {
    s16 unk0;
    s16 unk2;
} Struct80748180;

extern Struct80748180 D_global_asm_80748180[];

typedef struct InstanceData80649BF0 {
    s32 unk0;
    s32 unk4;
} InstanceData80649BF0;

/*
void func_global_asm_80649BF0(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 i;
    s32 found;
    InstanceData80649BF0 *temp_v0;
    Struct80748180 *ptr;

    if (arg0->unk0 == NULL) {
        temp_v0 = malloc(sizeof(InstanceData80649BF0));
        arg0->unk0 = temp_v0;
        temp_v0->unk0 = 0;
        temp_v0->unk4 = -1;
    }
    temp_v0 = arg0->unk0;
    if (temp_v0->unk4 == -1) {
        temp_v0->unk4 = arg0->unk48[0];
        return;
    }
    found = FALSE;
    if (temp_v0->unk4 & 1) {
        if ((arg0->unk48[0] + 1) == temp_v0->unk4) {
            found = TRUE;
        }
    } else if (arg0->unk48[0] == (temp_v0->unk4 + 1)) {
        found = TRUE;
    }
    if (found) {
        found = FALSE;
        temp_v0->unk0++;
        if (temp_v0->unk0 == 8) {
            arg0->next_state[0] = 0x64;
        }
    } else {
        found = FALSE;
        i = 0;
        ptr = &D_global_asm_80748180;
        while (!found) {
            if (temp_v0->unk4 == ptr->unk0) {
                found = TRUE;
            } else {
                i++;
                ptr++;
            }
            if (i);
        }
        found = FALSE;
        func_global_asm_806418E8(ptr->unk2, 0x28, 0);
        ptr = &D_global_asm_80748180;
        while (!found) {
            if (ptr->unk0 == arg0->unk48[0]) {
                found = TRUE;
            } else {
                ptr++;
            }
        }
        func_global_asm_806418E8(ptr->unk2, 0x28, 0);
    }
    temp_v0->unk4 = -1;
}
*/

typedef struct {
    s16 unk0;
    s16 unk2;
} Struct807481C0;

extern Struct807481C0 D_global_asm_807481C0[];

void func_global_asm_80649D74(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    Struct807481C0 *current;
    s16 target;
    s32 found;

    target = D_global_asm_807F6000[func_global_asm_80659470(arg1)].unk8A;
    found = FALSE;
    current = &D_global_asm_807481C0;
    while (!found) {
        if (target == current->unk0) {
            found = TRUE;
        } else {
            current++;
        }
    }
    func_global_asm_806418E8(0x3D, current->unk2, 1);
}

void func_global_asm_80649E00(GlobalASMStruct49 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unk14 = arg0->unk49;
}

extern s16 D_global_asm_807481F4[];

typedef struct InstanceData80649E34 {
    s32 unk0;
    s32 unk4;
} InstanceData80649E34;

void func_global_asm_80649E34(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    InstanceData80649E34 *temp_v0; // 2C
    s32 found; // 28
    s32 idx; // 24
    s32 i; // 1C

    if (arg0->unk0 == NULL) {
        temp_v0 = malloc(sizeof(InstanceData80649E34));
        arg0->unk0 = temp_v0;
        temp_v0->unk0 = 0;
        temp_v0->unk4 = 0;
    }
    temp_v0 = arg0->unk0;
    i = arg0->unk48[1];
    if (i == temp_v0->unk4) {
        return;
    }
    found = FALSE;
    i = 0;
    while (!found) {
        if (D_global_asm_807481F4[i] == arg0->unk48[1]) {
            found = TRUE;
        } else {
            i++;
        }
    }
    if (i < 15) {
        func_global_asm_806418E8(D_global_asm_807481F4[i + 1], 0xA, 0);
        idx = func_global_asm_80659470(D_global_asm_807F6240[D_global_asm_807481F4[i + 1]]);
        func_global_asm_8064199C(D_global_asm_807F6000[idx].unk7C, 0, 0);
    }
    if (i > 0) {
        func_global_asm_806418E8(D_global_asm_807481F4[i - 1], 0x14, 0);
    }
    temp_v0->unk4 = arg0->unk48[1];
}

void func_global_asm_80649F64(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    // TODO: Might actually use unk88 which gets read as unk8A because of the explicit s16 in the function signature
    // We'll see what looks more logical when the fields shake out down the line
    func_global_asm_806418E8(0x5F, D_global_asm_807F6000[func_global_asm_80659470(arg1)].unk8A, 1);
}

// 64 bit stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_80649FC0.s")

typedef struct InstanceData80649FC0 {
    OSTime unk0;
    s32 unk8;
    s32 unkC;
    s32 time_remaining_minutes;
    s32 time_remaining_seconds;
    s32 unk18;
    s32 unk1C;
} InstanceData80649FC0;

extern OSTime D_global_asm_807445B0;
extern Gfx *func_global_asm_8068DBA4(Gfx *, InstanceData80649FC0 *);

/*
void func_global_asm_80649FC0(Prop_ScriptData *arg0, s32 arg1, s32 arg2, s32 arg3) {
    InstanceData80649FC0 *temp_v0;
    u32 temp_t2;
    u32 temp_t1;
    u32 temp_t3;
    u32 temp_t4;
    u32 temp_t5;
    u32 temp_t9;
    u32 temp_v1;
    u32 temp_v1_2;
    u64 temp_ret_3;

    if (arg0->unk0 == NULL) {
        temp_v0 = malloc(sizeof(InstanceData80649FC0));
        arg0->unk0 = temp_v0;
        temp_v0->unk0 = osGetTime();
        temp_v0->unk8 = arg2 >> 0x1F;
        temp_v0->time_remaining_seconds = 0;
        temp_v0->time_remaining_minutes = 0;
        temp_v0->unk1C = 0;
        temp_v0->unk18 = 0;
        temp_v0->unkC = arg2;
    }
    temp_v0 = arg0->unk0;
    temp_v0->unk0 += D_global_asm_807445B0;
    temp_ret_3 = (osGetTime() - temp_v0->unk0) * 0x40;
    temp_ret_3 = temp_ret_3 / 0xBB8;
    temp_ret_3 = temp_ret_3 / 0xF4240;
    temp_v1_2 = (u32) temp_ret_3;
    temp_t4 = (temp_v0->unk8 - temp_ret_3) - (temp_v0->unkC < temp_v1_2);
    temp_t5 = temp_v0->unkC - temp_v1_2;
    temp_v0->time_remaining_seconds = temp_t5;
    temp_v0->time_remaining_minutes = temp_t4;
    if ((temp_v0->unk18 == 0U) && (temp_v0->unk1C == 0U)) {
        temp_t2 = arg3 >> 0x1F;
        if ((temp_t2 >= temp_t4) && ((temp_t4 < temp_t2) || (temp_t5 < arg3))) {
            temp_v0->unk1C = 1;
            temp_v0->unk18 = 0;
            arg0->next_state[0] = 0x14;
        }
    }
    if ((temp_v0->time_remaining_minutes == 0) && (temp_v0->time_remaining_seconds == 0)) {
        func_global_asm_8061134C(arg0->unk0);
        arg0->next_state[0] = 0x1E;
        arg0->unk0 = NULL;
    }
    addActorToTextOverlayRenderArray(&func_global_asm_8068DBA4, temp_v0, 5U);
}
*/

void func_global_asm_8064A180(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

}

void func_global_asm_8064A194(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    u8 found;
    s32 i;
    s16 temp_a0;
    u8 *var_v0_2;

    i = 0;
    found = FALSE;
    temp_a0 = D_global_asm_807F6000[func_global_asm_80659470(arg1)].unk8A;
    while (!found) {
        if (temp_a0 == D_global_asm_80748214[i]) {
            found = TRUE;
        } else {
            i++;
        }
    }
    if (i == 0x16) {
        var_v0_2 = &D_global_asm_80748214[0];
    } else {
        // TODO: Yuk
        i++;var_v0_2 = &D_global_asm_80748214[i];
    }
    func_global_asm_806418E8(*var_v0_2, 0xA, 0);
}

// 64 bit stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_8064A258.s")

extern s16 D_global_asm_8074822C[6][2];
extern s16 D_global_asm_80748244[12][2];

typedef struct InstanceData8064A804 {
    u8 unk0[6];
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
} InstanceData8064A804;

void func_global_asm_8064A804(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    InstanceData8064A804 *temp_v0; // 44
    u8 found; // 43
    u8 temp_t6;
    s16 temp_s0;
    s32 i; // 3c
    s32 j; // 38
    InstanceData8064A804 *temp_t2;

    found = FALSE;
    if (arg0->unk0 == NULL) {
        temp_v0 = malloc(sizeof(InstanceData8064A804));
        arg0->unk0 = temp_v0;
        for (i = 0; i < 6; i++) { \
            temp_v0->unk0[i] = 0;
        }
        temp_v0->unk6 = 1;
        temp_v0->unk9 = 0;
    }
    temp_v0 = arg0->unk0;
    for (i = 0; i < 6 && !found; i++) {
        for (j = 0; j < 2 && !found; j++) {
            if (D_global_asm_8074822C[i][j] == arg0->unk48[1]) {
                found = TRUE;
            }
        }
    }
    i--;
    j--;
    if (!(temp_v0->unk0[i] & 1 << j)) {
        temp_v0->unk0[i] = temp_v0->unk0[i] | (1 << j);
        temp_s0 = (i * 2) + j;
        if (temp_v0->unk0[i] == 3) {
            func_global_asm_80635018(arg1, D_global_asm_80748244[temp_s0][0], 0, 0);
            func_global_asm_80635018(arg1, D_global_asm_80748244[temp_s0][1], 0, 0);
            playSound(0x2A1, 0x7FFFU, 63.0f, 1.0f, 0, 0);
            temp_v0->unk9++;
            if (temp_v0->unk9 == 6) {
                arg0->next_state[1] = 0x32;
            }
        } else if (temp_v0->unk6) {
            func_global_asm_80635018(arg1, D_global_asm_80748244[temp_s0][0], 0, 0);
            func_global_asm_80635018(arg1, D_global_asm_80748244[temp_s0][1], 0, 0);
            temp_v0->unk8 = temp_s0;
            temp_v0->unk7 = i;
        } else {
            temp_v0->unk0[temp_v0->unk7] = 0;
            temp_v0->unk0[i] = 0;
            func_global_asm_80635018(arg1, D_global_asm_80748244[temp_v0->unk8][0], 1, 0);
            func_global_asm_80635018(arg1, D_global_asm_80748244[temp_v0->unk8][1], 1, 0);
            playSound(0x2A2, 0x7FFFU, 63.0f, 1.0f, 0, 0);
        }
        temp_v0->unk6 ^= 1;
    }
}

void func_global_asm_8064AAC4(s32 arg0, s16 arg1, s8 arg2, s32 arg3) {
    func_global_asm_806BD094(D_global_asm_807F6000[func_global_asm_80659470(arg1)].unk8A, arg2);
}

s32 func_global_asm_8064AB1C(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 i;
    Actor *temp_v0;

    for (i = 0; i < D_global_asm_807FBB34; i++) {
        temp_v0 = D_global_asm_807FB930[i].unk0;
        if (!((temp_v0->object_properties_bitfield & 0x2000)
            || (temp_v0->unk58 != ACTOR_LANKY)
            || (temp_v0->locked_to_pad != 1)
            || (arg1 != temp_v0->unk10C)
            || (arg2 == temp_v0->unk10E)
            || (temp_v0->unk10E == 0))) {
            func_global_asm_806508B4(arg1, temp_v0->unk10E, 2);
            func_global_asm_80641874(temp_v0->unk10E + 4, 0);
            return TRUE;
        }
    }
    return FALSE;
}

typedef struct DKTile {
    u8 position;
    u8 pad1;
    s16 enable_countdown;
    u8 tile_activated;
    u8 pad5;
} DKTile;

typedef struct InstanceData8064AC28 {
    u8 pad[0x18];
    DKTile tiles[9];
    u8 unk4E;
    u8 unk4F;
} InstanceData8064AC28;

void func_global_asm_8064AC28(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    InstanceData8064AC28 *temp_v0; // A4
    u8 pad0[3];
    u8 unkcounter;
    s16 sp9C; // 9C
    f32 sp98; // 98
    u8 sp97; // 97
    f32 dxz;
    s32 j;
    s32 i;
    u8 puzzle_complete; // 87
    f32 x, y, z; // 78, 7C, 80
    Actor *player;
    f32 max_dist;

    puzzle_complete = TRUE;
    unkcounter = 0;
    if (arg0->unk0 == NULL) {
        temp_v0 = arg0->unk0 = malloc(sizeof(InstanceData8064AC28));
        temp_v0->unk4E = 0;
        if (isFlagSet(PERMFLAG_ITEM_GB_CASTLE_FACE_PUZZLE, FLAG_TYPE_PERMANENT)) {
            for (i = 0; i < 9; i++) { \
                temp_v0->tiles[i].position = 3;
            }
        } else {
            temp_v0->tiles[2].position = 2;
            temp_v0->tiles[5].position = 2;
            temp_v0->tiles[7].position = 2;
            temp_v0->tiles[0].position = 0;
            temp_v0->tiles[1].position = 3;
            temp_v0->tiles[3].position = 0;
            temp_v0->tiles[4].position = 1;
            temp_v0->tiles[6].position = 3;
            temp_v0->tiles[8].position = 1;
        }
        for (i = 0; i < 9; i++) {
            temp_v0->tiles[i].tile_activated = TRUE;
            temp_v0->tiles[i].enable_countdown = 10;
        }
        temp_v0->unk4F = 0;
    }
    temp_v0 = arg0->unk0;
    for (i = 0; i < 9; i++) {
        if (temp_v0->tiles[i].tile_activated) {
            unkcounter++;
            func_global_asm_80650D8C(arg1, i + 1, &sp9C, &sp98, &sp97);
            if ((sp9C == temp_v0->tiles[i].position) && (sp98 < 0.1) && (!temp_v0->tiles[i].enable_countdown)) {
                func_global_asm_80650A04(arg1, i + 1, 0);
                func_global_asm_80650AD8(arg1, i + 1, sp9C, 0.0f);
                temp_v0->tiles[i].tile_activated = FALSE;
                func_global_asm_806335B0(arg1, 1, i + 1, &x, &y, &z);
                playSoundAtPosition(x, y, z, 0x1AE, 0xFFU, 0x7F, 0x14U, 0x50U, 0.7f, 0U);
            }
            if (temp_v0->tiles[i].enable_countdown) {
                temp_v0->tiles[i].enable_countdown--;
            }
        }
        if ((temp_v0->tiles[i].tile_activated) || (temp_v0->tiles[i].position != 3)) {
            puzzle_complete = FALSE;
        }
    }
    if (isFlagSet(PERMFLAG_ITEM_GB_CASTLE_FACE_PUZZLE, FLAG_TYPE_PERMANENT)) {
        temp_v0->unk4F = 0x14U;
    }
    if (temp_v0->unk4F == 0) {
        player = character_change_array->playerPointer;
        if (
            (player->control_state == 0x1C) &&
            (player->control_state_progress < 7) &&
            (current_character_index[0] == 0) &&
            (player->locked_to_pad == 1)
        ) {
            if (arg1 == player->unk10C) {
                max_dist = 100000.0f;
                j = -1;
                for (i = 0; i < 9; i++) {
                    func_global_asm_806335B0(arg1, 1, i + 1, &x, &y, &z);
                    x = gPlayerPointer->x_position - x;
                    z = gPlayerPointer->z_position - z;
                    dxz = (x * x) + (z * z);
                    if (dxz < max_dist) {
                        j = i;
                        max_dist = dxz;
                    }
                }
                if (j >= 0) {
                    temp_v0->tiles[j].position++;
                    temp_v0->tiles[j].position %= 4;
                    temp_v0->tiles[j].tile_activated = TRUE;
                    func_global_asm_80650A04(arg1, j + 1, 0x19);
                    temp_v0->unk4F = 0x14U;
                }
            }
        }
    }
    if (temp_v0->unk4F) {
        temp_v0->unk4F--;
    }
    if (puzzle_complete) {
        func_global_asm_8063DA40(0xF, 0xA);
        func_global_asm_8061134C(arg0->unk0);
        arg0->next_state[0] = 0x28;
        arg0->unk0 = NULL;
    }
}

void func_global_asm_8064B118(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    func_bonus_8002D6F8(arg1);
}

typedef struct {
    u8 unk0[0x14 - 0x0];
    f32 unk14[3]; // TODO: How many? At least 3
} Struct8064BAF4;

void func_global_asm_8064B150(Struct8064BAF4 *arg0, s32 arg1, s16 arg2, s16 arg3) {
    arg0->unk14[arg2] = arg0->unk14[arg2] + arg0->unk14[arg3];
}

void func_global_asm_8064B190(Struct8064BAF4 *arg0, s32 arg1, s16 arg2, s16 arg3) {
    f32 temp = -10.0 - arg0->unk14[arg2];
    temp /= -10.0;
    arg0->unk14[arg3] = -1.0 * temp;
}

void func_global_asm_8064B204(Struct8064BAF4 *arg0, s32 arg1, s16 arg2, s32 arg3) {
    arg0->unk14[arg2] = -1.0 - arg0->unk14[arg2];
    arg0->unk14[arg2] = 0.0 - arg0->unk14[arg2];
}

void func_global_asm_8064B260(Struct8064BAF4 *arg0, s32 arg1, s16 arg2, s32 arg3) {
    arg0->unk14[arg2] = gPlayerPointer->unk100;
    arg0->unk14[arg2 + 1] = gPlayerPointer->unk104;
    arg0->unk14[arg2 + 2] = gPlayerPointer->unk108;
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
} Struct8064B2AC;

void func_global_asm_8064B2AC(Struct8064B2AC **arg0, s32 arg1, s32 arg2, s32 arg3) {
    Struct8064B2AC *var_v1;

    if (*arg0 == NULL) {
        *arg0 = malloc(0x28);
    }
    var_v1 = *arg0;
    var_v1->unk0 = D_global_asm_807F621C;
    var_v1->unk4 = D_global_asm_807F6220;
    var_v1->unk8 = D_global_asm_807F6224;
    var_v1->unkC = D_global_asm_807F6228;
    var_v1->unk10 = D_global_asm_807F622C;
    var_v1->unk14 = D_global_asm_807F6230;
    var_v1->unk18 = D_global_asm_807F6234;
    var_v1->unk1C = D_global_asm_807F6234;
    var_v1->unk20 = D_global_asm_807F6234;
    var_v1->unk24 = D_global_asm_807F6238;
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
} GlobalASMStruct86;

void func_global_asm_8064B370(GlobalASMStruct86 **arg0, s32 arg1, s32 arg2, s32 arg3) {
    GlobalASMStruct86* temp_v0 = *arg0;
    D_global_asm_807F621C = temp_v0->unk0;
    D_global_asm_807F6220 = temp_v0->unk4;
    D_global_asm_807F6224 = temp_v0->unk8;
    D_global_asm_807F6228 = temp_v0->unkC;
    D_global_asm_807F622C = temp_v0->unk10;
    D_global_asm_807F6230 = temp_v0->unk14;
    D_global_asm_807F6234 = temp_v0->unk18;
    D_global_asm_807F6234 = temp_v0->unk1C;
    D_global_asm_807F6234 = temp_v0->unk20;
    D_global_asm_807F6238 = temp_v0->unk24;
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct8064B3F8;

void func_global_asm_8064B3F8(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    Struct8064B3F8 *temp_t0;
    Prop_ScriptData *temp_a0;
    f32 x;
    f32 y;
    f32 z;
    s32 propIndex;

    temp_t0 = arg0->unk0;
    propIndex = func_global_asm_80659470(arg1);
    x = D_global_asm_807F6000[propIndex].x_position;
    y = D_global_asm_807F6000[propIndex].y_position;
    z = D_global_asm_807F6000[propIndex].z_position;
    arg0->unk14[arg3] = (temp_t0->unk0 - x) / arg2;
    arg0->unk14[arg3 + 1] = (temp_t0->unk4 - y) / arg2;
    arg0->unk14[arg3 + 2] = (temp_t0->unk8 - z) / arg2;
}

void func_global_asm_8064B4AC(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    func_global_asm_806335B0(D_global_asm_807F6240[arg2], 1, arg3, &D_global_asm_807F621C, &D_global_asm_807F6220, &D_global_asm_807F6224);
}

void func_global_asm_8064B514(u8 arg0, u8 arg1, s8 arg2, s16 arg3) {
    func_global_asm_806FAC64(arg2);
    if (arg3) {
        func_global_asm_806F8D58(0xD, 0);
    } else {
        func_global_asm_806F8BC4(0xD, 1, 0);
    }
}

void func_global_asm_8064B574(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_global_asm_80726EE0(3);
}

void func_global_asm_8064B5A4(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    s32 i;

    if (arg3 != 0) {
        for (i = 0; i < D_global_asm_807F6C28; i++) {
            func_global_asm_80659670(D_global_asm_80748280.unk0, D_global_asm_80748280.unk4, D_global_asm_80748280.unk8, i);
        }
    } else {
        func_global_asm_80659620(&sp3C, &sp38, &sp34, 0);
        if (arg2 != 0) {
            sp3C = sp3C + D_global_asm_807482A4;
            sp38 = sp38 + D_global_asm_807482A4;
            if (D_global_asm_8074828C.unk0 < sp3C) {
                sp3C = D_global_asm_8074828C.unk0;
            }
            if (D_global_asm_8074828C.unk4 < sp38) {
                sp38 = D_global_asm_8074828C.unk4;
            }
            sp34 = sp34 + D_global_asm_807482A4;
            if (D_global_asm_8074828C.unk8 < sp34) {
                sp34 = D_global_asm_8074828C.unk8;
            }
        } else {
            sp3C = sp3C - D_global_asm_807482A4;
            sp38 = sp38 - D_global_asm_807482A4;
            if (sp3C < D_global_asm_80748280.unk0) {
                sp3C = D_global_asm_80748280.unk0;
            }
            if (sp38 < D_global_asm_80748280.unk4) {
                sp38 = D_global_asm_80748280.unk4;
            }
            sp34 = sp34 - D_global_asm_807482A4;
            if (sp34 < D_global_asm_80748280.unk8) {
                sp34 = D_global_asm_80748280.unk8;
            }
        }
        for (i = 0; i < D_global_asm_807F6C28; i++) {
            func_global_asm_80659670(sp3C, sp38, sp34, i);
        }
    }
}

void func_global_asm_8064B798(s32 arg0, s32 arg1, s8 arg2, s32 arg3) {
    PlayerAdditionalActorData *temp_v0 = character_change_array[0].playerPointer->PaaD;
    temp_v0->unk1FC = arg2;
}

void func_global_asm_8064B7C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

}

void func_global_asm_8064B7D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

}

void func_global_asm_8064B7E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_global_asm_806612B4(5, 1);
    func_global_asm_806612B4(6, 1);
}

void func_global_asm_8064B828(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_global_asm_8066134C(5, 0xFF);
    func_global_asm_8066134C(6, 0xFF);
}

void func_global_asm_8064B868(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 temp_a2 = func_global_asm_80661300(5);
    func_global_asm_8066134C(5, temp_a2 < 0xFC ? temp_a2 + 3 : 0xFF);
    func_global_asm_8066134C(6, temp_a2 < 0xFC ? temp_a2 + 3 : 0xFF);
    func_global_asm_806612B4(5, 0);
    func_global_asm_806612B4(6, 0);
}

void func_global_asm_8064B900(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    Actor *temp_v0;

    if (arg2 != 0) {
        if (arg2 != 1) {
            if (arg2 == 2) {
                func_global_asm_807271F4(8, 0, 0, 0, 0, 0, 0);
                gLastSpawnedActor->object_properties_bitfield &= -5;
            }
        } else {
            temp_v0 = getSpawnerTiedActor(8, 0);
            if (temp_v0) {
                temp_v0->object_properties_bitfield |= 4;
                playActorAnimation(temp_v0, 0x35C);
                func_global_asm_80614D00(temp_v0, 0.9f, 0);
            }
        }
    } else {
        temp_v0 = getSpawnerTiedActor(8, 0);
        if (temp_v0) {
            temp_v0->control_state = 0x3C;
        }
    }
}

void func_global_asm_8064B9E0(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    s16 x, y, z;

    switch (arg2) {
        case 0:
            x = 932;y = 6;z = 362;
            break;
        case 1:
            x = 1081;y = 122;z = 522;
            break;
        case 2:
            x = 861;y = 122;z = 567;
            break;
        case 3:
            x = 1282;y = 17;z = 288;
            break;
        case 4:
            x = 650;y = 18;z = 370;
            break;
    }
    func_global_asm_80688EE4(5, x, y, z);
}

u8 func_global_asm_8064BAF4(Struct8064BAF4 *arg0, s32 arg1, s16 arg2, s16 arg3) {
    return arg0->unk14[arg2] < arg0->unk14[arg3];
}

// TODO: This probably returns the result of func_global_asm_805FF0C8, if not, this is cursed
void func_global_asm_8064BB4C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_global_asm_805FF0C8();
}

// This function checks whether the key has been turned in for the map stored at D_global_asm_8076A0AB
s32 func_global_asm_8064BB78(s32 arg0, s32 arg1, s32 levelIndex, s32 arg3) {
    levelIndex = getLevelIndex(D_global_asm_8076A0AB, FALSE);
    if (levelIndex >= 8) {
        levelIndex = 0;
    }
    return isFlagSet(D_global_asm_80744710[levelIndex], FLAG_TYPE_PERMANENT);
}

u8 func_global_asm_8064BBD8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return (func_global_asm_806CC14C(func_global_asm_80665DE0((s16)D_global_asm_807F621C, (s16)D_global_asm_807F6224, (s16)gPlayerPointer->x_position, (s16)gPlayerPointer->z_position), gPlayerPointer->y_rotation) < 0x384);
}

s32 func_global_asm_8064BCB0(s32 arg0, s32 arg1) {
    Actor *player;
    s32 playerIndex;

    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        if (character_change_array[playerIndex].does_player_exist) {
            player = character_change_array[playerIndex].playerPointer;
            if ((player->locked_to_pad == 1) && (arg0 == player->unk10C) && (arg1 == player->unk10E)) {
                return playerIndex;
            }
        }
    }
    return -1;
}

s32 func_global_asm_8064BD2C(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    f32 x, y, z;
    f32 xRot, yRot, zRot;
    s32 scale;
    s32 sp40;
    s32 temp_a0;
    s32 temp_v0;
    s32 sp3C;

    temp_v0 = func_global_asm_8064BCB0(arg1, arg3);
    if (temp_v0 < 0) {
        return 0;
    } else {
        temp_a0 = D_global_asm_807F6240[arg2];
        sp3C = temp_a0;
        if (func_global_asm_8064BCB0(temp_a0, arg3) != -1) {
            return 0;
        } else {
            func_global_asm_806357F8(temp_a0, &x, &y, &z, &xRot, &yRot, &zRot, &scale, &sp40, 1);
            func_global_asm_8067ABC0(
                0,
                character_change_array[temp_v0].playerPointer,
                9,
                yRot * 11.37777805f,
                0,
                x,
                y,
                z
            );
        }
    }
    return 0;
}

u8 func_global_asm_8064BE58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return D_global_asm_807552E8 == 5;
}

extern s32 D_global_asm_807552F0;

s32 func_global_asm_8064BE80(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 playerIndex;
    f32 temp;

    playerIndex = func_global_asm_8064BCB0(arg1, arg2);
    if (playerIndex < 0) {
        return FALSE;
    }
    if (func_global_asm_806F8AD4(1, playerIndex) != 0) {
        changeCollectableCount(7, playerIndex, 1);
        temp = (f32)((s32)func_global_asm_806F8AD4(7, playerIndex)) / D_global_asm_807552F0;
        temp = ((1 / 2.0f) * temp) + 0.5f;
        playSound(0x2A1, 0x7FFF, 63.0f, temp, 5, 0);
        return TRUE;
    }
    return FALSE;
}

s32 func_global_asm_8064BF58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f64 dz, dx;

    dz = character_change_array[0].look_at_eye_z - 1274.0;
    dx = character_change_array[0].look_at_eye_x - 3081.0;
    if ((SQ(dz) + SQ(dx)) < SQ(100.0)) {
        return TRUE;
    }
    return FALSE;
}

void func_global_asm_8064BFD0(Prop_ScriptData *arg0, s32 arg1, s16 arg2, s16 arg3) {
    f32 temp_f12;

    temp_f12 = ((f64)ABS(arg0->unk14[arg2]) / arg0->unk14[arg3 + 1]);
    if (arg0->unk14[arg2] > 0.0) {
        if (arg0->unk14[arg3] < temp_f12) {
            arg0->unk14[arg3] += 0.1;
        }
    } else {
        if (-temp_f12 < arg0->unk14[arg3]) {
            arg0->unk14[arg3] -= 0.1;
        }
    }
    D_global_asm_807F6228 += arg0->unk14[arg3];
    if (D_global_asm_807F6228 > 8.0) {
        D_global_asm_807F6228 = 8.0f;
    }
    if (D_global_asm_807F6228 < -8.0) {
        D_global_asm_807F6228 = -8.0f;
    }
}

void func_global_asm_8064C134(Prop_ScriptData *arg0, s32 arg1, s16 arg2, s32 arg3) {
    if (1.2 < D_global_asm_807F6228 || D_global_asm_807F6228 < -1.2) {
        if (D_global_asm_807F6228 > 0.0) {
            if (arg0->unk14[arg2] > -1.0) {
                arg0->unk14[arg2] -= 0.1;
            }
        } else {
            if (arg0->unk14[arg2] < 1.0) {
                arg0->unk14[arg2] += 0.1;
            }
        }
        D_global_asm_807F6228 += arg0->unk14[arg2];
    } else {
        D_global_asm_807F6228 = 0.0f;
        arg0->unk14[arg2] = 0.0f;
    }
}

void func_global_asm_8064C250(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_global_asm_806A5DF0(0x2F, D_global_asm_807F621C, D_global_asm_807F6220 + 15.0f, D_global_asm_807F6224, 0, 1, -1, 0);
    func_global_asm_806A5DF0(0x2F, D_global_asm_807F621C, D_global_asm_807F6220 + 15.0f, D_global_asm_807F6224, 0x400, 1, -1, 0);
    func_global_asm_806A5DF0(0x2F, D_global_asm_807F621C, D_global_asm_807F6220 + 15.0f, D_global_asm_807F6224, 0x800, 1, -1, 0);
    func_global_asm_806A5DF0(0x2F, D_global_asm_807F621C, D_global_asm_807F6220 + 15.0f, D_global_asm_807F6224, 0xC00, 1, -1, 0);
    func_global_asm_807149B8(1);
    drawSpriteAtPosition(&D_global_asm_8071FFA0, 2.5f, D_global_asm_807F621C, D_global_asm_807F6220 + 30.0f, D_global_asm_807F6224);
}

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct8064C3E8_malloc;

typedef struct {
    Struct8064C3E8_malloc *unk0;
    u8 unk4[0x6E - 0x4];
    u8 unk6E;
} Struct8064C3E8_arg0;

void func_global_asm_8064C3E8(Struct8064C3E8_arg0 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 pad54;
    s32 pad50;
    s32 pad4C;
    s32 pad48;
    s16 pad46;
    s16 sp44;
    f32 sp40;
    u8 sp3F;
    Struct8064C3E8_malloc *var_v1;
    PlayerAdditionalActorData *sp34;

    sp34 = character_change_array->playerPointer->additional_actor_data;
    if (arg0->unk0 == NULL) {
        var_v1 = malloc(sizeof(Struct8064C3E8_malloc));
        arg0->unk0 = var_v1;
        var_v1->unk0 = 0;
        var_v1->unk4 = 0;
    }
    var_v1 = arg0->unk0;
    func_global_asm_80650D8C(arg1, 1, &sp44, &sp40, &sp3F);
    if (sp44 == 0) {
        var_v1->unk4 = 0xA;
    }
    if (sp44 == 2 && 0.8 <= sp40) {
        if (var_v1->unk4 != 0) {
            func_global_asm_8061EF4C(sp34->unk104, 4, 0xB, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224, 200.0f, 600.0f);
            var_v1->unk4--;
        }
    } else {
        var_v1->unk0 = 0;
    }
    if (sp44 == 2) {
        arg0->unk6E = 1;
    } else {
        arg0->unk6E = 0;
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
} Struct8064C544;

void func_global_asm_8064C544(Struct8064C544 *arg0, s16 arg1, s16 arg2, s32 arg3) {
    s16 sp2E;
    f32 sp28;
    u8 sp27;
    u8 sp26;

    if (arg0->unk10 >= 0) {
        func_global_asm_80650D8C(arg1, arg2, &sp2E, &sp28, &sp27);
        sp26 = D_global_asm_80770628[arg0->unk10];
        D_global_asm_80770B68[sp26] = (func_global_asm_80612794(((sp2E + sp28) * 2048.0) - 1024.0) * 0.3) + 1.3;
        D_global_asm_80770BC0[sp26] = 1.0f;
    }
}

void func_global_asm_8064C644(Struct8064C544 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    s16 sp2E;
    f32 sp28;
    u8 sp27;
    u8 sp26;

    if (arg0->unk10 >= 0) {
        func_global_asm_80650D8C(arg1, 1, &sp2E, &sp28, &sp27);
        sp26 = D_global_asm_80770628[arg0->unk10];
        D_global_asm_80770B68[sp26] = func_global_asm_80612794((sp2E << 0xB) / 27) + 0.3;
        D_global_asm_80770BC0[sp26] = 2.0f;
    }
}

void func_global_asm_8064C708(s32 **arg0, s16 arg1, s32 arg2, s32 arg3) {
    s16 sp3E;
    f32 sp38;
    u8 sp37;
    s32 *var_v1;

    if (*arg0 == NULL) {
        var_v1 = malloc(4);
        *arg0 = var_v1;
        *var_v1 = 0;
    }
    var_v1 = *arg0;
    func_global_asm_80650D8C(arg1, 1, &sp3E, &sp38, &sp37);
    if (*var_v1 == 0xB) {
        if (sp3E == 3) {
            *var_v1 = 3;
            playSoundAtProp(arg1, 0x257, 0x78, 0x7F, 0xA, 0x50, 0.3f);
        }
    } else if (sp3E == 0xB) {
        *var_v1 = 0xB;
        playSoundAtProp(arg1, 0x258, 0x78, 0x7F, 0xA, 0x50, 0.3f);
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct8064C814;

void func_global_asm_8064C814(void **arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 x, y, z;
    s16 sp42;
    f32 sp3C;
    u8 sp3B;
    Struct8064C814 *var_v1;

    if (*arg0 == NULL) {
        *arg0 = malloc(sizeof(Struct8064C814));
        var_v1 = *arg0;
        var_v1->unk0 = 0;
        var_v1->unk4 = 0;
    }
    var_v1 = *arg0;
    func_global_asm_80650D8C(arg1, 2, &sp42, &sp3C, &sp3B);
    sp42 = (sp42 + sp3C);
    if (sp42 == 0x28 || sp42 == 0x32) {
        if (sp42 != var_v1->unk0) {
            var_v1->unk0 = sp42;
            func_global_asm_806335B0(arg1, 1, 3, &x, &y, &z);
            playSoundAtPosition(x, y, z, 0x32, 0xFF, 0x7F, 0xA, 0x50, 0.3f, 0);
        }
    }
    func_global_asm_80650D8C(arg1, 3, &sp42, &sp3C, &sp3B);
    if (sp42 == 0x14 || sp42 == 0x18) {
        if (sp42 != var_v1->unk4) {
            var_v1->unk4 = sp42;
            func_global_asm_806335B0(arg1, 1, 2, &x, &y, &z);
            playSoundAtPosition(x, y, z, 0x332, 0xFF, 0x7F, 0, 0x50, 0.3f, 0);
        }
    }
}

typedef struct {
    s32 *unk0;
} Struct8064C9F8_arg0;

void func_global_asm_8064C9F8(Struct8064C9F8_arg0 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 x, y, z;
    s16 sp42;
    f32 sp3C;
    u8 sp3B;
    s32 *var_v1;

    if (arg0->unk0 == NULL) {
        arg0->unk0 = malloc(4);
        var_v1 = arg0->unk0;
        *var_v1 = 0;
    }
    var_v1 = arg0->unk0;
    func_global_asm_80650D8C(arg1, 2, &sp42, &sp3C, &sp3B);
    sp42 = sp42 + sp3C;
    if (sp42 == 0x22 || sp42 == 0x2E) {
        if (sp42 != *var_v1) {
            *var_v1 = sp42;
            func_global_asm_806335B0(arg1, 1, 2, &x, &y, &z);
            playSoundAtPosition(x, y, z, (sp42 == 0xA) + 0x257, 0xFF, 0x7F, 0xA, 0x50, 0.3f, 0);
        }
    }
}

void func_global_asm_8064CB3C(s32 **arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 x, y, z;
    s16 sp4A;
    f32 sp44;
    u8 sp43;
    s32 *var_v1;
    s32 pad;

    if (*arg0 == NULL) {
        *arg0 = malloc(4);
        var_v1 = *arg0;
        *var_v1 = 0;
    }
    var_v1 = *arg0;
    func_global_asm_80650D8C(arg1, 2, &sp4A, &sp44, &sp43);
    sp4A = sp4A + sp44;
    if (sp4A != *var_v1) {
        if (sp4A == 0 || sp4A == 0xC || sp4A == 0x18 || sp4A == 0x24) {
            *var_v1 = sp4A;
            func_global_asm_806335B0(arg1, 1, 2, &x, &y, &z);
            playSoundAtPosition(x, y, z, 0x3A, 0x50, 0x7F, 0, 0x50, 0.3f, 0);
        }
    }
}

void func_global_asm_8064CC80(s32 **arg0, s16 arg1, s32 arg2, s32 arg3) {
    s16 sp3E;
    u32 sp38;
    u8 sp37;
    s32 *var_v1;
    s32 *sp30;

    if (*arg0 == NULL) {
        *arg0 = malloc(4);
        **arg0 = 0x64;
    }
    var_v1 = *arg0;
    func_global_asm_80650D8C(arg1, 1, &sp3E, &sp38, &sp37);
    if (sp3E != *var_v1) {
        *var_v1 = sp3E;
        playSoundAtProp(arg1, 0x129, 0xFF, 0x7F, 3, 0x50, 0.3f);
    }
}

extern f32 D_global_asm_807F61FC;
extern f32 D_global_asm_807F6200;
extern f32 D_global_asm_807F6204;
extern s16 D_global_asm_807482B0;
extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;
extern f32 D_global_asm_807F622C;

typedef struct InstanceData8064CD3C {
    tuple_f unk0[0x1E];
    s32 unk168[2];
} InstanceData8064CD3C;

void func_global_asm_8064CD3C(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    InstanceData8064CD3C *temp_v0;
    s32 pad;
    tuple_f *temp;
    f64 temp_f2;
    s16 var_s1;
    s16 var_s2;
    f32 sp78;
    f32 sp74;
    s16 sp72;
    s16 sp70;
    f32 sp6C;
    u8 sp6B;
    s16 var_v0_2;
    s32 i;
;
    if (arg0->unk0 == NULL) {
        temp_v0 = malloc(sizeof(InstanceData8064CD3C));
        arg0->unk0 = temp_v0;
        for (i = 0; i < 0x1E; i++) {
            temp_v0->unk0[i].x = D_global_asm_807F61FC;
            temp_v0->unk0[i].y = D_global_asm_807F6200;
            temp_v0->unk0[i].z = D_global_asm_807F6204;
        }
    }
    temp_v0 = arg0->unk0;
    sp78 = D_global_asm_807F6220;
    if (func_global_asm_80667110(D_global_asm_807F621C, D_global_asm_807F6224, &sp78)) {
        if (func_global_asm_8066715C(&sp74)) {
            D_global_asm_807F6220 = sp74;
        }
    } else {
        var_v0_2 = D_global_asm_807482B0 - 1;
        temp = temp_v0->unk0;
        if (var_v0_2 < 0) {
            var_v0_2 = 0x1D;
        }
        D_global_asm_807F6220 = temp[var_v0_2].y;
    }
    temp_v0->unk0[D_global_asm_807482B0].x = D_global_asm_807F621C;
    temp_v0->unk0[D_global_asm_807482B0].y = D_global_asm_807F6220;
    temp_v0->unk0[D_global_asm_807482B0].z = D_global_asm_807F6224;
    var_s1 = D_global_asm_807482B0 + 1;
    if (var_s1 == 0x1E) {
        var_s1 = 0;
    }
    D_global_asm_807F622C = ((func_global_asm_80665E48(temp_v0->unk0[var_s1].x, temp_v0->unk0[var_s1].z, D_global_asm_807F621C, D_global_asm_807F6224) * 57.295776f) + 270.0);
    var_s2 = 0x15;
    if (D_global_asm_807F622C > 360.0) {
        D_global_asm_807F622C -= 360.0;
    }
    D_global_asm_807482B0 = var_s1;
    for (i = 0; i < 2; i++) {
        func_global_asm_80650D8C(arg1, i + 1, &sp70, &sp6C, &sp6B);
        if (sp70 != temp_v0->unk168[i]) {
            temp_v0->unk168[i] = (s32) sp70;
            if (sp70 == 0) {
                playSoundAtProp(arg1, var_s2, 0xFFU, 0x7FU, 3U, 0x46U, 0.3f);
            }
        }
        var_s2 = 0x14;
    }
}

void func_global_asm_8064D0C4(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3) {
    f32 sp24;
    f32 sp20;
    u8 temp_v0;
    u8 sp1E;

    sp1E = 2;
    sp24 = D_global_asm_807F6220 + 20.0f;
    if (func_global_asm_80667110(D_global_asm_807F621C, D_global_asm_807F6224, &sp24)) {
        if (func_global_asm_8066715C(&sp20)) {
            if (sp20 < sp24) {
                sp1E = 0;
                D_global_asm_807F6220 = sp24;
            } else {
                sp1E = 1;
                D_global_asm_807F6220 = sp20;
            }
        }
    }
    if (arg2 != 0) {
        arg3 = func_global_asm_80650D04(arg1, 1);
        if (sp1E == 1 && !arg3) {
            func_global_asm_806508B4(arg1, 1, -1);
            func_global_asm_806508B4(arg1, 2, -1);
        } else if (sp1E == 0 && arg3) {
            func_global_asm_8065092C(arg1, 1);
            func_global_asm_8065092C(arg1, 2);
        }
    }
}

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_8064D1E8.s")

typedef struct InstanceData8064D1E8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} InstanceData8064D1E8;

/*
void func_global_asm_8064D1E8(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    InstanceData8064D1E8 *temp_v0;
    s32 var_a0;
    s32 temp;

    if (arg0->unk0 == NULL) {
        temp_v0 = malloc(sizeof(InstanceData8064D1E8));
        arg0->unk0 = temp_v0;
        temp_v0->unk0 = 0;
        temp_v0->unk4 = 0;
        temp_v0->unk8 = 0xDAC;
    }
    temp_v0 = arg0->unk0;
    func_global_asm_80661398(0, ((func_global_asm_80612794(temp_v0->unk8) * 60.0) + 40.0), 20.0f);
    if (!temp_v0->unk0) {
        if ((temp_v0->unk8 >= 0x2BC) && (temp_v0->unk8 < 0x2C6)) {
            playSound(0x359, 0x7FFFU, 63.0f, 0.6f, 0, 0);
        }
        if (((temp_v0->unk8 >= 0x2EE) && (temp_v0->unk8 < 0x2F8)) || ((temp_v0->unk8 >= 0x960) && (temp_v0->unk8 < 0x96A))) {
            if (arg0->unk10 >= 0) {
                func_global_asm_80605380(arg0->unk10);
                arg0->unk10 = -1;
            }
        }
        if (((temp_v0->unk8 >= 0x410) && (temp_v0->unk8 < 0x41A)) || ((temp_v0->unk8 >= 0xE74) && (temp_v0->unk8 < 0xE7E))) {
            arg0->unk10 = func_global_asm_80605044(arg1, 0x138, 1, 1, 0x78, 1.0f, -1);
        }
        var_a0 = ABS(temp_v0->unk8 - 0x400); // Issue is here
        if (!(var_a0 < 0xA)) {
            if (temp_v0->unk8 - 0xC00 < 0) {
                var_a0 = -(temp_v0->unk8 - 0xC00);
            } else {
                var_a0 = temp_v0->unk8 - 0xC00;
            }
        }
        if ((var_a0 < 0xA) && (temp_v0->unk4 == 0)) {
            temp_v0->unk0 = 0x12C;
        }
        if (temp_v0->unk4) {
            temp_v0->unk4--;
        }
        temp_v0->unk8 = (temp_v0->unk8 + 0xA) & 0xFFF;
        return;
    }
    temp_v0->unk0--;
    if (temp_v0->unk0 == 0) {
        temp_v0->unk4 = 0xA;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_8064D418.s")

void func_global_asm_8064D880(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    f32 phi_f0;
    s32 levelIndex;

    levelIndex = getLevelIndex(D_global_asm_8076A0AB, FALSE);
    phi_f0 = (f32)D_global_asm_807FC930[levelIndex] / D_global_asm_807446C0[levelIndex];
    if (phi_f0 > 1.0) {
        phi_f0 = 1.0f;
    }
    if (arg2 == 0) {
        phi_f0 = 1.0f - phi_f0;
    }
    func_global_asm_80650AD8(arg1, 1, 0, phi_f0);
    func_global_asm_80650A04(arg1, 1, 0);
}

typedef struct {
    u8 unk0[0x48 - 0x0];
    u8 unk48;
} Struct8064D978;

void func_global_asm_8064D978(Struct8064D978 *arg0, s16 arg1, s16 arg2, s32 arg3) {
    s16 sp36;
    u8 levelIndex;
    f32 var_f2;
    u8 sp2F;
    f32 var_f0;

    levelIndex = getLevelIndex(D_global_asm_8076A0AB, 0);
    var_f0 = (f32)D_global_asm_807FC930[levelIndex] / D_global_asm_807446C0[levelIndex];
    if (var_f0 > 1.0) {
        var_f0 = 1.0f;
    }
    if (arg2 == 0) {
        var_f0 = 1.0f - var_f0;
    }
    func_global_asm_80650D8C(arg1, 1, &sp36, &var_f2, &sp2F);
    func_global_asm_80650A04(arg1, 1, 0);
    if (var_f0 < var_f2) {
        var_f2 -= 0.1;
        if (var_f2 < var_f0) {
            var_f2 = var_f0;
        }
    } else {
        var_f2 += 0.1;
        if (var_f0 < var_f2) {
            var_f2 = var_f0;
        }
    }
    if (arg2 != 0) {
        // Note: These two doubles come from same rodata location
        // Possibliy a macro
        if (0.999 <= var_f2) {
            if (0.999 <= var_f0) {
                arg0->unk48 = 0x14;
            }
        }
    } else {
        // Note: These two doubles come from same rodata location
        // Possibliy a macro
        if (var_f2 <= 0.001) {
            if (var_f0 <= 0.001) {
                arg0->unk48 = 0x14;
            }
        }
    }
    func_global_asm_80650AD8(arg1, 1, sp36, var_f2);
    func_global_asm_806508B4(arg1, 1, 1);
}

void func_global_asm_8064DB98(s32 **arg0, s16 arg1, s32 arg2, s32 arg3) {
    s16 sp5E;
    f32 sp58;
    u8 sp57;
    s32 *var_v1;
    f32 temp_f0;
    f32 temp_f2;

    if (*arg0 == NULL) {
        *arg0 = malloc(4);
        **arg0 = 0;
    }
    var_v1 = *arg0;
    func_global_asm_80650D8C(arg1, 1, &sp5E, &sp58, &sp57);
    if (sp5E != *var_v1) {
        switch (sp5E) {
            case 0xF:
                playSoundAtPosition(D_global_asm_807F6000[arg1].x_position, D_global_asm_807F6000[arg1].y_position + 300.0f, D_global_asm_807F6000[arg1].z_position, 0x8E, 0xFF, 0x50, 0, 0x50, 0.3f, 0);
                break;
            case 0:
                playSoundAtPosition(D_global_asm_807F6000[arg1].x_position, D_global_asm_807F6000[arg1].y_position + 300.0f, D_global_asm_807F6000[arg1].z_position, 0x8F, 0xFF, 0x64, 0, 0x50, 0.3f, 0);
                break;
        }
        *var_v1 = sp5E;
    }
    temp_f0 = ((sp5E + sp58) / 31.0) * 11.0;
    temp_f2 = (temp_f0 - (s32)temp_f0) * 64.0;
    func_global_asm_80635018(arg1, 1, temp_f0, temp_f2);
    func_global_asm_80635018(arg1, 2, temp_f0, temp_f2);
    func_global_asm_80635018(arg1, 3, temp_f0, temp_f2);
    func_global_asm_80635018(arg1, 4, temp_f0, temp_f2);
}

// TODO: Any cleanup possible? Stack seems a bit whack
void func_global_asm_8064DE04(Prop_ScriptData *arg0, s32 arg1, s16 arg2, s32 arg3) {
    Actor *temp;
    Actor *closestActor;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 closestDistance;
    PlayerAdditionalActorData *PaaD;
    s32 i;
    u16 actorType;

    closestActor = NULL;
    closestDistance = 99999.0f;
    PaaD = gPlayerPointer->additional_actor_data;
    if (arg0->unk5C != 0) {
        actorType = arg0->unk5E;
        for (i = 0; i < D_global_asm_807FBB34; i++) {
            temp = D_global_asm_807FB930[i].unk0;
            if (temp->unk58 == actorType) {
                dx = temp->x_position - D_global_asm_807F621C;
                dy = temp->y_position - D_global_asm_807F6220;
                dz = temp->z_position - D_global_asm_807F6224;
                if (SQ(dx) + SQ(dy) + SQ(dz) < closestDistance) {
                    closestDistance = SQ(dx) + SQ(dy) + SQ(dz);
                    closestActor = temp;
                }
            }
        }
        if (closestActor != NULL) {
            func_global_asm_80679200(closestActor, NULL, 8, 0, 0, 0);
        }
        if (arg2 == 0) {
            if (closestActor != NULL) {
                if (closestActor->unk58 == ACTOR_STEEL_KEG) {
                    PaaD->unk1F0 &= 0xFFDFFFFF;
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/propScripts/func_global_asm_8064DF5C.s")

typedef struct InstanceData8064DF5C {
    u8 combo[4];
    u8 unk4;
    u8 unk5;
} InstanceData8064DF5C;

/*
void func_global_asm_8064DF5C(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    InstanceData8064DF5C *temp_v0;
    u8 var_t0; // 23
    s8 var_v0;
    u8 sp1C[4]; // 1C, 1D, 1E, 1F
    s32 i;

    var_t0 = FALSE;
    if (arg0->unk0 == NULL) {
        arg0->unk0 = temp_v0 = malloc(sizeof(InstanceData8064DF5C));
        temp_v0->unk4 = 0;
        temp_v0->unk5 = 0;
    }
    temp_v0 = arg0->unk0;
    if (arg2 == -1) {
        temp_v0->unk4 = 0;
        temp_v0->unk5 = 0;
        return;
    }
    switch (D_global_asm_807F6000[func_global_asm_80659470(arg1)].unk8A) {
        case 0x41:
            sp1C[3] = 1;
            sp1C[2] = 3;
            sp1C[1] = 4;
            sp1C[0] = 2;
            break;
        case 0x40:
            sp1C[3] = 3;
            sp1C[2] = 1;
            sp1C[1] = 2;
            sp1C[0] = 4;
            break;
        case 0x3F:
            sp1C[3] = 4;
            sp1C[2] = 2;
            sp1C[1] = 3;
            sp1C[0] = 1;
            break;
    }
    temp_v0->combo[temp_v0->unk4] = arg2;
    var_v0 = temp_v0->unk4++;
    if (temp_v0->unk4 == 4) {
        temp_v0->unk4 = 0;
    }
    if (temp_v0->unk5 == temp_v0->unk4) {
        var_t0 = TRUE;
        temp_v0->unk5++;
        if (temp_v0->unk5 == 4) {
            temp_v0->unk5 = 0;
        }
    }
    if (!var_t0) {
        return;
    }
    if (sp1C[0] != temp_v0->combo[var_v0]) {
        return;
    }
    var_v0--;
    if (var_v0 < 0) {
        var_v0 = 3;
    }
    if (sp1C[1] != temp_v0->combo[var_v0]) {
        return;
    }
    var_v0--;
    if (var_v0 < 0) {
        var_v0 = 3;
    }
    if (sp1C[2] != temp_v0->combo[var_v0]) {
        return;
    }
    var_v0--;
    if (var_v0 < 0) {
        var_v0 = 3;
    }
    if (sp1C[3] == temp_v0->combo[var_v0]) {
        arg0->next_state[0] = 5;
    }
}
*/

typedef struct InstanceData8064E174 {
    u8 unk0[5];
    u8 unk5;
    u8 unk6;
} InstanceData8064E174;

void func_global_asm_8064E174(Prop_ScriptData *arg0, s16 arg1, s16 arg2, u8 *array, s32 size, s16 arg5, s16 arg6) {
    InstanceData8064E174 *temp_v0;
    s32 i;
    s32 diff;
    s8 j;

    if (arg0->unk0 == NULL) {
        temp_v0 = malloc(sizeof(InstanceData8064E174));
        arg0->unk0 = temp_v0;
        temp_v0->unk5 = 0;
        temp_v0->unk6 = 0;
    }
    temp_v0 = arg0->unk0;
    temp_v0->unk0[temp_v0->unk5] = arg2;
    j = temp_v0->unk5++;
    if (size == temp_v0->unk5) {
        temp_v0->unk5 = 0;
    }
    if (temp_v0->unk5 == temp_v0->unk6) {
        temp_v0->unk6++;
        if (size == temp_v0->unk6) {
            temp_v0->unk6 = 0U;
        }
        diff = size;
    } else {
        diff = temp_v0->unk5 - temp_v0->unk6;
    }
    for (i = (size - diff); i < size; i++) {
        if (array[i] != temp_v0->unk0[j]) {
            if (arg6 != -1) {
                arg0->next_state[0] = arg6;
            }
            temp_v0->unk5 = 0;
            temp_v0->unk6 = 0;
            return;
        }
        j--;
        if (j < 0) {
            j = size - 1;
        }
    }
    if (arg5 != -1) {
        if (size == diff) {
            arg0->next_state[0] = arg5;
        }
    }
}

typedef struct {
    s32 unk0;
} Struct807482DC;

typedef struct {
    u8 unk0[5];
} Struct807482E0;

typedef struct {
    u8 unk0[3];
} Struct807482E8;

typedef struct {
    s32 unk0;
} Struct807482EC;

extern Struct807482E0 D_global_asm_807482E0;
extern Struct807482E8 D_global_asm_807482E8;
extern Struct807482EC D_global_asm_807482EC;
extern Struct807482DC D_global_asm_807482DC;

void func_global_asm_8064E428(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3) {
    Struct807482DC sp2C = D_global_asm_807482DC;
    func_global_asm_8064E174(arg0, arg1, arg2, &sp2C, 4, 5, 0x14);
}

void func_global_asm_8064E48C(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3) {
    Struct807482E0 sp28 = D_global_asm_807482E0;
    func_global_asm_8064E174(arg0, arg1, arg2, &sp28, 5, 4, 0x14);
}

void func_global_asm_8064E4F8(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3) {
    Struct807482E8 sp2C = D_global_asm_807482E8;
    func_global_asm_8064E174(arg0, arg1, arg2, &sp2C, 3, 7, 0x14);
}

void func_global_asm_8064E55C(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3) {
    Struct807482EC sp2C = D_global_asm_807482EC;
    func_global_asm_8064E174(arg0, arg1, arg2, &sp2C, 3, 7, 0x14);
}

typedef struct {
    u8 unk0[0x60 - 0x0];
    u8 unk60;
    u8 unk61;
    s16 unk62;
    s16 unk64;
    u8 unk66;
} Struct8064E5C0_arg0;

void func_global_asm_8064E5C0(Struct8064E5C0_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 sp26;

    sp26 = arg0->unk62;
    arg0->unk66 = 0xFF;
    arg0->unk60 = 1;
    if (RandClamp(100) >= 0x29) {
        arg0->unk62 = 0;
    } else {
        arg0->unk62 = 0xFF;
    }
    if (sp26 != arg0->unk62) {
        playSound(0x8A, 0xBB8, 63.0f, 1.0f, 0x1E, 0);
    }
}

typedef struct InstanceData8064E65C {
    s32 unk0;
} InstanceData8064E65C;

void func_global_asm_8064E65C(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    InstanceData8064E65C *temp_v0;
    f32 x, y, z;
    f64 red;
    f64 green;

    if (arg2 != 0xB) {
        func_global_asm_806335B0(arg1, 1U, 1, &x, &y, &z);
    }
    arg0->unk98 = y - D_global_asm_807F6220;
    if (arg0->unk0 == NULL) {
        temp_v0 = malloc(sizeof(InstanceData8064E65C));
        arg0->unk0 = temp_v0;
        temp_v0->unk0 = 0;
    }
    temp_v0 = arg0->unk0;
    switch (arg2) {
        case 10:
        case 11:
            playSoundAtPosition(x, y, z, 0x305, 0x64U, 0x7F, 0U, 0U, 0.0f, 0U);
            spawnActor(ACTOR_SHOCKWAVE_MAD_JACK, 0x5D);
            gLastSpawnedActor->animation_state->scale[0] *= 3.2;
            gLastSpawnedActor->animation_state->scale[1] *= 3.2;
            gLastSpawnedActor->animation_state->scale[2] *= 3.2;
            gLastSpawnedActor->object_properties_bitfield |= 0x400;
            playActorAnimation(gLastSpawnedActor, 0x335);
            if (arg2 == 0xB) {
                gLastSpawnedActor->x_position = D_global_asm_807F621C;
                gLastSpawnedActor->y_position = D_global_asm_807F6220;
                gLastSpawnedActor->z_position = D_global_asm_807F6224;
                return;
            }
            gLastSpawnedActor->x_position = x;
            gLastSpawnedActor->y_position = y;
            gLastSpawnedActor->z_position = z;
        case 1:
        case 3:
        case 4:
            if (temp_v0->unk0 >= 2) {
                temp_v0->unk0 -= 2;
            } else {
                temp_v0->unk0 = 0;
                break;
            }
        case 0:
            if (arg2 == 0) {
                temp_v0->unk0 = 0xFF;
            }
            func_global_asm_80659610(5000);
            red = arg3 ? temp_v0->unk0 * 0.27 : temp_v0->unk0;
            green = arg3 ? temp_v0->unk0 * 0.63 : temp_v0->unk0;
            createLight(x, y - 50.0f, z, 0.0f, 0.0f, 0.0f, 240.0f, 0, red, green, temp_v0->unk0);
        default:
            return;
    }
}

void func_global_asm_8064EA48(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_global_asm_806F8AD4(1, 0) >= 2) {
        func_global_asm_806F8BC4(1, 0, 0);
        changeCollectableCount(1, 0, -2);
        // DK Arcade Level 3?
        setFlag(PERMFLAG_PROGRESS_ARCADE_2_COINS_PAID, TRUE, FLAG_TYPE_PERMANENT);
    }
}

typedef struct global_asm_struct_7 {
    u8 unk0[0x4B];
    s8 next_state;
} GlobalASMStruct7;

void func_global_asm_8064EAB4(GlobalASMStruct7 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 numberOfGunSwitchesPressed;

    // Fungi Mushroom Gun Switches Pressed
    // Odd that they didn't use countSetFlags() for this
    numberOfGunSwitchesPressed = isFlagSet(PERMFLAG_PROGRESS_CANNON_COCONUT_SWITCH, FLAG_TYPE_PERMANENT);
    numberOfGunSwitchesPressed += isFlagSet(PERMFLAG_PROGRESS_CANNON_FEATHER_SWITCH, FLAG_TYPE_PERMANENT);
    numberOfGunSwitchesPressed += isFlagSet(PERMFLAG_PROGRESS_CANNON_PEANUT_SWITCH, FLAG_TYPE_PERMANENT);
    numberOfGunSwitchesPressed += isFlagSet(PERMFLAG_PROGRESS_CANNON_GRAPE_SWITCH, FLAG_TYPE_PERMANENT);
    numberOfGunSwitchesPressed += isFlagSet(PERMFLAG_PROGRESS_CANNON_PINEAPPLE_SWITCH, FLAG_TYPE_PERMANENT);

    arg0->next_state = numberOfGunSwitchesPressed;
}

s32 func_global_asm_8064EB3C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (!isFlagSet(PERMFLAG_ITEM_GB_FACTORY_ARCADE, FLAG_TYPE_PERMANENT)) {
        return TRUE;
    }
    if (isFlagSet(PERMFLAG_PROGRESS_ARCADE_2_COINS_PAID, FLAG_TYPE_PERMANENT)) {
        return TRUE;
    }
    return FALSE;
}

u8 func_global_asm_8064EB9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 levelIndex = getLevelIndex(D_global_asm_8076A0AB, FALSE);
    s32 temp;
    if (levelIndex >= 8) {
        levelIndex = 0;
    }
    temp = D_global_asm_807446F0[levelIndex];
    return temp == current_character_index[0];
}

extern s16 D_global_asm_807446D0[];

u8 func_global_asm_8064EC04(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 sp1E;
    sp1E = func_global_asm_80600530();
    return ((s16)func_global_asm_806FB418() >= D_global_asm_807446D0[sp1E]);
}

u8 func_global_asm_8064EC60(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 sp1B;
    s32 temp_v0;
    s32 kongIndex;
    u8 phi_t0;

    phi_t0 = FALSE;
    switch (arg2) {
        case 3:
            kongIndex = 1;
            break;
        case 4:
            kongIndex = 2;
            break;
        case 5:
            kongIndex = 3;
            break;
        case 6:
            kongIndex = 4;
            break;
        default:
            kongIndex = 0;
            break;
    }
    temp_v0 = func_global_asm_80600530();
    sp1B = D_global_asm_807FC950->character_progress[kongIndex].unk5 & 0x7F;
    if (sp1B == temp_v0) {
        phi_t0 = TRUE;
        if ((arg3 == 0) && (D_global_asm_807FC950->character_progress[kongIndex].unk5 & 0x80)) {
            phi_t0 = FALSE;
        }
    } else if (temp_v0 < sp1B) {
        phi_t0 = TRUE;
    }
    if ((phi_t0 == TRUE) && (arg3 == 2)) {
        D_global_asm_807FC950->character_progress[kongIndex].unk5 &= 0x7F;
    }
    return phi_t0;
}

s32 func_global_asm_8064ED68(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    u8 phi_s0;
    s32 phi_s3;

    phi_s3 = FALSE;
    for (phi_s0 = 2; phi_s0 < 7; phi_s0++) {
        if (!func_global_asm_8064EC60(arg0, arg1, phi_s0, 1)) {
            phi_s3 = TRUE;
        }
    }
    return phi_s3;
}

extern s8 D_global_asm_807F6950;

void func_global_asm_8064EE08(SpriteStruct *arg0, u8 *arg1) {
    SpriteStructSub384 *var_t0;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = var_t0 = malloc(8);
        var_t0->unk0 = 0;
        var_t0->unk2 = 0;
        var_t0->unk4 = arg0->unk344;
    }
    var_t0 = arg0->unk384;
    switch (var_t0->unk0) {
        case 0:
            arg0->unk360 += 0.015;
            if (arg0->unk360 > 0.5) {
                arg0->unk360 = 0.5f;
                var_t0->unk0 = 1;
            }
            break;
        case 1:
            if (func_global_asm_8061CB38()) {
                var_t0->unk0 = 2;
            }
            if (!func_global_asm_8061CB50()) {
                var_t0->unk0 = 2;
            }
            break;
        case 2:
            if (!func_global_asm_8061CB38() || !func_global_asm_8061CB50()) {
                var_t0->unk0 = 3;
                playSound(0x2E8, 0x7FFFU, 63.0f, 1.0f, 0, 0);
            }
            break;
        case 3:
            arg0->unk360 -= 0.015;
            if (arg0->unk360 < 0.0) {
                D_global_asm_807F6950 = 1;
                arg0->unk360 = 0.0f;
                *arg1 = 1;
            }
            break;
    }
    if (var_t0->unk0 != 3) {
        arg0->unk344 = (func_global_asm_80612794(((object_timer * 0x3C) & 0xFFF)) * 2.75f) + var_t0->unk4;
    }
    arg0->unk364 = arg0->unk360;
}

void func_global_asm_8064F028(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    changeActorColor(0xFF, 0xFF, 0xFF, 0x80);
    func_global_asm_8071498C(func_global_asm_8064EE08);
    func_global_asm_807149FC(-1);
    func_global_asm_807149B8(1);
    func_global_asm_80714998(2);
    drawSpriteAtPosition(&D_global_asm_80721530, 0, D_global_asm_807F621C, D_global_asm_807F6220 + 17.5, D_global_asm_807F6224);
    spawnActor(ACTOR_WRINKLY, 0x53);
    gLastSpawnedActor->x_position = D_global_asm_807F621C;
    gLastSpawnedActor->y_position = D_global_asm_807F6220;
    gLastSpawnedActor->z_position = D_global_asm_807F6224;
    gLastSpawnedActor->y_rotation = (D_global_asm_807F622C * 4096.0f) / 360.0f;
    if ((current_map == MAP_FUNGI_LOBBY) || ((current_map == MAP_AZTEC_LOBBY) && (arg2 == 4))) {
        // BUG(?): This angle addition does not truncate to 4096
        gLastSpawnedActor->y_rotation += 0x800;
    }
    playCutscene(gLastSpawnedActor, 0x22, 5);
    playSong(MUSIC_171_WRINKLY_KONG, 1.0f);
    playSound(0x2EA, 0x7FFF, 63.0f, 1.0f, 0, 0);
    D_global_asm_807F6951 = arg2;
    D_global_asm_807F6950 = 0;
}

extern s8 D_global_asm_807F6950;
extern s8 D_global_asm_807FC8D0;

u8 func_global_asm_8064F1C4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (D_global_asm_807F6950) {
        func_global_asm_80602B60(0xAB, 0);
    }
    return D_global_asm_807F6950;
}

u8 func_global_asm_8064F210(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 sp2C;
    f32 temp2;
    f64 temp3;
    s16 temp_f18;
    f32 temp4;
    f32 temp_f0;
    f32 temp;
    f32 new_var;

    temp_f18 = (D_global_asm_807F622C * 4096.0f) / 360.0f;
    sp2C = func_global_asm_80612794(temp_f18);
    temp_f0 = func_global_asm_80612790(temp_f18);
    temp = ((D_global_asm_807F621C * sp2C) + (D_global_asm_807F6224 * temp_f0));
    temp = -temp;
    new_var = (gPlayerPointer->x_position * sp2C) + (temp_f0 * gPlayerPointer->z_position) + temp;
    return 6.0 < new_var;
}

s32 func_global_asm_8064F2F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return 1;
}

void func_global_asm_8064F308(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 flagIndex;

    if (D_global_asm_807FC8D0 == 5) {
        flagIndex = PERMFLAG_PROGRESS_KEY_6_TURNED; // Key 6 turned
    } else {
        flagIndex = PERMFLAG_PROGRESS_KEY_7_TURNED; // Key 7 turned
    }
    setFlag(flagIndex, TRUE, FLAG_TYPE_PERMANENT);
}

u8 func_global_asm_8064F358(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    PlayerProgress *temp = &D_global_asm_807FC950[cc_player_index];
    return temp->character_progress[current_character_index[cc_player_index]].coloured_bananas[getLevelIndex(D_global_asm_8076A0AB, 0)] > 0;
}

u8 func_global_asm_8064F404(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    // Has the player collected 4 or more Battle Crowns?
    return countSetFlags(PERMFLAG_ITEM_CROWN_JAPES, 10, FLAG_TYPE_PERMANENT) >= 4;
}
