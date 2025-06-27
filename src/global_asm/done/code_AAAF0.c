#include "common.h"

extern s16 D_global_asm_80750384;
extern f32 D_global_asm_80750388;
extern s16 D_global_asm_8075038C;

typedef struct {
    SpriteData *unk0[7];
} Struct807504A4;

extern Struct807504A4 D_global_asm_807504A4;

extern f32 D_global_asm_807504C0;
extern f32 D_global_asm_807504C4;
extern u8 D_global_asm_807504C8;
extern u8 D_global_asm_807504CC;
extern u8 D_global_asm_807504D0;

extern s32 D_global_asm_8076A068;

extern s32 D_global_asm_807FBB68;
extern u8 D_global_asm_807FBD70;

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
} AAD_global_asm_806A5EAC;

typedef struct {
    u8 unk0;
    u8 unk1;
    s8 unk2;
    u8 unk3;
    u16 unk4;
    s16 unk6;
} AAD_global_asm_806A7600;

typedef struct {
    u8 unk0[0x36C - 0x0];
    u8 unk36C;
    u8 unk36D;
} AAD_806A664C_unk4;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    AAD_806A664C_unk4 *unk4;
    u16 unk8;
    s16 unkA;
} AAD_806A664C;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    u16 unk8;
    s16 unkA;
} AAD_806A6DB4;

typedef struct {
    f32 unk0;
    s16 unk4;
} AAD_global_asm_806A7EF0;

void func_global_asm_806A5DF0(s16 arg0, f32 x, f32 y, f32 z, s16 arg4, u8 arg5, s16 arg6, s32 arg7) {
    f32 var_f0;
    f32 sp2C[8];

    var_f0 = 0.15f;
    if (D_global_asm_807FBB68 & 0x10) {
        var_f0 = 2.0f * var_f0;
    }
    sp2C[0] = arg5;
    sp2C[1] = arg4;
    sp2C[2] = arg6;
    func_global_asm_806891D8(arg0, x, y, z, 0, var_f0, arg7, &sp2C);
}

void func_global_asm_806A5EAC(AAD_global_asm_806A5EAC *arg0, void *sprite, f32 scale) {
    if (D_global_asm_807FBB68 & 0x10) {
        scale *= 2.0f;
    }
    func_global_asm_807149FC(-1);
    func_global_asm_807149B8(1);
    func_global_asm_80714998(2);
    arg0->unk4 = func_global_asm_80714C08(sprite, scale * 0.35, gCurrentActorPointer, 1, 2);
}

void func_global_asm_806A5F44(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *aaD = gCurrentActorPointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_806A5EAC(aaD, &D_global_asm_80720710, 1.0f);
    }
}

void func_global_asm_806A5FA4(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *aaD = gCurrentActorPointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_806A5EAC(aaD, &D_global_asm_80720508, 1.0f);
    }
}

void func_global_asm_806A6004(void *arg0, Actors arg1) {
    // TODO: Which aaD type are they actually expecting here?
    void *aaD = gCurrentActorPointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        if (arg1 != gPlayerPointer->unk58) {
            changeActorColor(0xFF, 0xFF, 0xFF, 0x64);
        }
        func_global_asm_806A5EAC(aaD, arg0, 1.0f);
    }
}

void func_global_asm_806A6094(void) {
    func_global_asm_806A6004(&D_global_asm_807209EC, ACTOR_DIDDY);
}

void func_global_asm_806A60BC(void) {
    func_global_asm_806A6004(&D_global_asm_80720A10, ACTOR_CHUNKY);
}

void func_global_asm_806A60E4(void) {
    func_global_asm_806A6004(&D_global_asm_807207E0, ACTOR_LANKY);
}

void func_global_asm_806A610C(void) {
    func_global_asm_806A6004(&D_global_asm_80720A34, ACTOR_DK);
}

void func_global_asm_806A6134(void) {
    func_global_asm_806A6004(&D_global_asm_80720A58, ACTOR_TINY);
}

void func_global_asm_806A615C(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *aaD = gCurrentActorPointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_80714A08(-0.35f, 0.35f);
        func_global_asm_806A5EAC(aaD, &D_global_asm_80720768, 1.0f);
    }
}

void func_global_asm_806A61D0(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *aaD = gCurrentActorPointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_806A5EAC(aaD, &D_global_asm_807204BC, 1.0f);
    }
}

void func_global_asm_806A6230(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *aaD = gCurrentActorPointer->additional_actor_data;
    s32 temp_v1;

    func_global_asm_806A664C(4.5f);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        temp_v1 = D_global_asm_807FBB64; // shadow_display_bitfield, shockwave_bitfield, long_distance_actor_spawn
        if (((temp_v1 << 0xC) < 0) || (temp_v1 & 0x2000)) {
            gCurrentActorPointer->unk15F = 1;
        }
        func_global_asm_806A5EAC(aaD, &D_global_asm_807207BC, 1.0f);
    }
}

void func_global_asm_806A62B4(void) {
    func_global_asm_806A6230();
}

void func_global_asm_806A62D4(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *aaD = gCurrentActorPointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        changeActorColor(0xFF, 0xFF, 0, 0xFF);
        func_global_asm_806A5EAC(aaD, &D_global_asm_807211D0, 1.5f);
    }
}

void func_global_asm_806A6348(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *aaD = gCurrentActorPointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_806A5EAC(aaD, &D_global_asm_807205C4, 1.0f);
    }
}

void func_global_asm_806A63A8(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *aaD = gCurrentActorPointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_806A5EAC(aaD, &D_global_asm_807205E8, 1.0f);
    }
}

void func_global_asm_806A6408(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *aaD = gCurrentActorPointer->additional_actor_data;
    func_global_asm_806A664C(12.0f);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_806A5EAC(aaD, &D_global_asm_80721378, 2.0f);
    }
}

void func_global_asm_806A6468(void) {
    void *aaD;
    void *sprite;

    aaD = gCurrentActorPointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        switch (gPlayerPointer->unk58) {
            case ACTOR_DIDDY:
                sprite = &D_global_asm_807203B0;
                break;
            case ACTOR_DK:
                sprite = &D_global_asm_8072041C;
                break;
            case ACTOR_LANKY:
                sprite = &D_global_asm_807203F8;
                break;
            case ACTOR_CHUNKY:
                sprite = &D_global_asm_807203D4;
                break;
            case ACTOR_TINY:
                sprite = &D_global_asm_80720440;
                break;
        }
        func_global_asm_806A5EAC(aaD, sprite, 1.0f);
        if (gCurrentActorPointer->control_state == 0x63) {
            gCurrentActorPointer->control_state = 1;
            gCurrentActorPointer->unk15F = 2;
        }
    }
}

void func_global_asm_806A6574(void) {
    void *aaD;
    void *sprite;

    aaD = gCurrentActorPointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        switch (gPlayerPointer->unk58) {
            case ACTOR_DIDDY:
                sprite = &D_global_asm_80720EE8;
                break;
            case ACTOR_DK:
                sprite = &D_global_asm_80720F40;
                break;
            case ACTOR_LANKY:
                sprite = &D_global_asm_80720F14;
                break;
            case ACTOR_CHUNKY:
                sprite = &D_global_asm_80720EBC;
                break;
            case ACTOR_TINY:
                sprite = &D_global_asm_80720F6C;
                break;
        }
        func_global_asm_806A5EAC(aaD, sprite, 1.0f);
    }
}

void func_global_asm_806A664C(f32 arg0) {
    AAD_806A664C *aaD;
    s32 temp_v0;
    s16 temp_0;
    s16 temp2;

    aaD = gCurrentActorPointer->additional_actor_data;
    if (D_global_asm_807FBB68 & 0x10) {
        arg0 *= 2.0f;
    }
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->control_state = (s32)gCurrentActorPointer->unk124->unk0;
        gCurrentActorPointer->unkEE = gCurrentActorPointer->unk124->unk4;
        gCurrentActorPointer->y_rotation = gCurrentActorPointer->unkEE;
        func_global_asm_8066E854(gCurrentActorPointer, 0.0f, 0.0f, 0.0f, -1);
        aaD->unk0 = 0;
        aaD->unk1 = 0;
        aaD->unkA = gCurrentActorPointer->unk124->unk8;
        gCurrentActorPointer->unkFA = 9999;
    }
    if (D_global_asm_807FBB70.unk0) {
        gCurrentActorPointer->control_state = D_global_asm_807FBB70.unk1;
    }
    func_global_asm_8067ACB4(gCurrentActorPointer);
    if (gCurrentActorPointer->unkFC) {
        if (func_global_asm_806725A0(gCurrentActorPointer, gCurrentActorPointer->unkEE) == 0) {
            // Regalloc in here somewhere
            temp_v0 = func_global_asm_80672A70(gCurrentActorPointer->unkF4, gCurrentActorPointer->unkF6);
            temp2 = gCurrentActorPointer->unkEE;
            temp2 = (temp2 + 0x800) & 0xFFF;
            temp_0 = temp_v0 - temp2;
            temp_v0 += temp_0;
            gCurrentActorPointer->unkEE = temp_v0;
        }
    }
    switch (gCurrentActorPointer->control_state) {
        case 1:
            gCurrentActorPointer->noclip_byte = 0x1C;
            func_global_asm_8066EB40(gCurrentActorPointer, 60.0f);
            func_global_asm_8066E8E4(gCurrentActorPointer, 0.0f, 0.0f, 0.0f, 50.0f, -1);
            func_global_asm_8066E854(gCurrentActorPointer, 0.0f, 0.0f, 0.0f, -1);
            gCurrentActorPointer->y_velocity = (((((u32)(func_global_asm_806119A0() / 10000) % 200)) * 0.5) + 220.0) - 50.0;
            if (!(D_global_asm_807FBB64 & 0x4000) && ((((gCurrentActorPointer->unk58 < 0x4BU))) || (gCurrentActorPointer->unk58 >= 0x50U))) {
                gCurrentActorPointer->unkB8 = 30.0f;
            }
            gCurrentActorPointer->control_state++;
            // fallthrough
        case 2:
            func_global_asm_806651FC(gCurrentActorPointer);
            func_global_asm_80665564(gCurrentActorPointer, arg0);
            gCurrentActorPointer->y_velocity -= 20.0f;
            if (gCurrentActorPointer->y_velocity < D_global_asm_8075038C) {
                gCurrentActorPointer->y_velocity = D_global_asm_8075038C;
            }
            if ((gCurrentActorPointer->unk6A & 1) && !(gCurrentActorPointer->unk6C & 1)) {
                switch (aaD->unk0) {
                    case 0:
                        if (gCurrentActorPointer->unk15F != 1) {
                            aaD->unk1 = 1;
                        }
                        gCurrentActorPointer->y_velocity = 150.0f;
                        break;
                    case 1:
                        gCurrentActorPointer->y_velocity = 100.0f;
                        break;
                    case 2:
                        gCurrentActorPointer->y_velocity = 50.0f;
                        break;
                    case 3:
                        gCurrentActorPointer->unkB8 = 0;
                        gCurrentActorPointer->y_velocity = 0;
                        if (gCurrentActorPointer->unk58 == ACTOR_RAINBOW_COIN) {
                            aaD->unk1 = 1;
                        }
                        if ((gCurrentActorPointer->unk58 != ACTOR_CB_BUNCH) && (gCurrentActorPointer->unk58 != ACTOR_RAINBOW_COIN) && !(D_global_asm_807FBB64 & 0x4000) && (gCurrentActorPointer->unk15F != 2)) {
                            aaD->unk8 = 0x64;
                            gCurrentActorPointer->control_state = 3;
                        } else {
                            gCurrentActorPointer->control_state = 0x64;
                        }
                        break;
                }
                switch (gCurrentActorPointer->unk58) {
                    case ACTOR_ORANGE_PICKUP:
                        playSoundAtActorPosition(gCurrentActorPointer, 0xF5, (u8)(gCurrentActorPointer->y_velocity + 105.0f), 0x7F, 0x1E);
                        break;
                    case ACTOR_DK_COIN:
                        temp_v0 = aaD->unk0;
                        if (!temp_v0) {
                            playSoundAtActorPosition(gCurrentActorPointer, 0x1D1, 0xFF, 0x7F, 0xA);
                        }
                        break;
                    default:
                        playSoundAtActorPosition(gCurrentActorPointer, 1, (u8)(gCurrentActorPointer->y_velocity + 105.0f), 0x7F, 0x14);
                        break;
                }
                aaD->unk0++;
            }
            break;
        default:
        case 0:
            break;
        case 3:
            if (func_global_asm_8061CB50() == 0) {
                aaD->unk8--;
            }
            if (aaD->unk8 == 0) {
                gCurrentActorPointer->control_state = 4;
            }
            break;
        case 4:
            aaD->unk4->unk36D -= 5;
            if (aaD->unk4->unk36D < 0xA) {
                if ((D_global_asm_807FBB64 & 0x10000) && (func_global_asm_806F5C30(gCurrentActorPointer->unk58) != 0)) {
                    func_global_asm_806F5F2C(gCurrentActorPointer->unk58, 0x258, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position);
                }
                deleteActor(gCurrentActorPointer);
            }
            break;
        case 25:
            aaD->unk8 = 0x64;
            gCurrentActorPointer->control_state = 3;
            aaD->unk1 = 1;
            break;
        case 24:
            break;
    }
}

void func_global_asm_806A6DB4(u8 arg0) {
    AAD_806A6DB4 *aaD;
    s16 temp_v0_2;
    s32 var_v1_2;
    s16 temp_0;

    aaD = gCurrentActorPointer->additional_actor_data;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->object_properties_bitfield |= 0x801000;
        gCurrentActorPointer->unk16A = 0xFF;
        gCurrentActorPointer->unk16B = 0xFF;
        gCurrentActorPointer->unk16C = 0xFF;
        gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
        gCurrentActorPointer->control_state = (s32)gCurrentActorPointer->unk124->unk0;
        gCurrentActorPointer->unkEE = gCurrentActorPointer->unk124->unk4;
        gCurrentActorPointer->y_rotation = gCurrentActorPointer->unkEE;
        aaD->unk0 = 0;
        aaD->unk1 = 1;
        aaD->unkA = gCurrentActorPointer->unk124->unk8;
        gCurrentActorPointer->unkFA = 0x270F;
        func_global_asm_806C9974(0, 0x40);
    }
    if (aaD->unk8 < 30.0f) {
        aaD->unk8++;
    }
    gCurrentActorPointer->shadow_opacity = aaD->unk8 * 0.033333335f * 255.0f;
    if (D_global_asm_807FBB70.unk0 != 0) {
        gCurrentActorPointer->control_state = D_global_asm_807FBB70.unk1;
    }
    func_global_asm_8067ACB4(gCurrentActorPointer);
    if ((gCurrentActorPointer->unkFC != 0) && (func_global_asm_806725A0(gCurrentActorPointer, gCurrentActorPointer->unkEE) == 0)) {
        // regalloc
        temp_v0_2 = func_global_asm_80672A70(gCurrentActorPointer->unkF4, gCurrentActorPointer->unkF6);
        temp_0 = gCurrentActorPointer->unkEE;
        temp_0 = (temp_0 + 0x800) & 0xFFF;
        var_v1_2 = temp_v0_2;
        temp_v0_2 -= temp_0;
        var_v1_2 += temp_v0_2;
        gCurrentActorPointer->unkEE = var_v1_2;
    }
    if ((gCurrentActorPointer->control_state == 1) || (gCurrentActorPointer->control_state == 2) || (gCurrentActorPointer->control_state == 4) || (gCurrentActorPointer->control_state == 5) || (gCurrentActorPointer->control_state == 6)) {
        gCurrentActorPointer->noclip_byte = 0x1C;
        func_global_asm_8066EB40(gCurrentActorPointer, 60.0f);
        func_global_asm_8066E8E4(gCurrentActorPointer, 0.0f, 0.0f, 0.0f, 50.0f, -1);
        func_global_asm_8066E854(gCurrentActorPointer, 0.0f, 0.0f, 0.0f, -1);
        switch (gCurrentActorPointer->control_state) {
            case 1:
                gCurrentActorPointer->unkB8 = D_global_asm_80750384;
                gCurrentActorPointer->y_velocity = 0.0f;
                break;
            case 2:
                gCurrentActorPointer->y_velocity = 2000.0f;
                break;
            case 4:
                gCurrentActorPointer->unkB8 = 1500.0f;
                gCurrentActorPointer->y_velocity = 4000.0f;
                break;
            case 5:
                gCurrentActorPointer->unkB8 = 200.0f;
                gCurrentActorPointer->y_velocity = 2000.0f;
                break;
            case 6:
                gCurrentActorPointer->unkB8 = 1000.0f;
                gCurrentActorPointer->y_velocity = 2000.0f;
                break;
        }
        gCurrentActorPointer->control_state = 3;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x0:
        case 0x64:
            break;
        case 0x3:
            func_global_asm_806651FC(gCurrentActorPointer);
            func_global_asm_80665564(gCurrentActorPointer, 0.0f);
            gCurrentActorPointer->y_velocity += D_global_asm_80750388;
            if (gCurrentActorPointer->y_velocity < D_global_asm_8075038C) {
                gCurrentActorPointer->y_velocity = D_global_asm_8075038C;
            }
            if ((gCurrentActorPointer->unk6A & 1) && !(gCurrentActorPointer->unk6C & 1)) {
                var_v1_2 = 0xC8;
                switch (aaD->unk0) {
                    case 0:
                        gCurrentActorPointer->y_velocity = 1600.0f;
                        gCurrentActorPointer->unkB8 /= 2;
                        break;
                    case 1:
                        gCurrentActorPointer->y_velocity = 1200.0f;
                        var_v1_2 = 0x64;
                        gCurrentActorPointer->unkB8 /= 2;
                        break;
                    case 2:
                        gCurrentActorPointer->y_velocity = 800.0f;
                        var_v1_2 = 0x46;
                        gCurrentActorPointer->unkB8 /= 2;
                        break;
                    case 3:
                        gCurrentActorPointer->unkB8 = 0.0f;
                        var_v1_2 = 0x1E;
                        gCurrentActorPointer->y_velocity = 0.0f;
                        if (arg0 != 0) {
                            gCurrentActorPointer->control_state = 0x64;
                        }
                        break;
                }
                if (gCurrentActorPointer->unk58 == ACTOR_BOSS_KEY) {
                    playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0x2A1, var_v1_2, 0x7F, 0, 0, 0.0f, 0);
                }
                aaD->unk0 = aaD->unk0 + 1;
            }
            break;
    }
    gCurrentActorPointer->y_rotation += 0x72;
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806A734C(void) {
    func_global_asm_806A6DB4(1);
}

void func_global_asm_806A736C(void) {
    PlayerAdditionalActorData *PaaD = gCurrentActorPointer->PaaD;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->unk64 |= 4;
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
        func_global_asm_80686CF8(gCurrentActorPointer);
    }
    // TODO: Get rid of typecasts
    if ((u16)PaaD->unk8 == 1) {
        playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0x73, 0xFF, 0x7F, 1, 0, 0.0f, 0);
        playSong(MUSIC_59_GENERIC_TWINKLY_SOUNDS, 0.7f);
    } else if ((u16)PaaD->unk8 == 0xA) {
        playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0x19C, 0xB4, 0x7F, 1, 0, 0.0f, 0);
    }
    func_global_asm_806A6DB4(0);
    if (gCurrentActorPointer->y_position < gCurrentActorPointer->unkAC) {
        gCurrentActorPointer->unkB8 = 0.0f;
        gCurrentActorPointer->y_position = gCurrentActorPointer->unkAC;
        gCurrentActorPointer->y_velocity = gCurrentActorPointer->y_acceleration;
    }
    func_global_asm_8065D254(gCurrentActorPointer, 0x3C8, 0x40, 0x40, 0x1E, 0x1E, 1, 0x96, 0x78, 0, 1.0f);
}

void func_global_asm_806A7518(void) {
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
        func_global_asm_80686A5C(gCurrentActorPointer, 20.0f, 40.0f, 0x1E);
        gCurrentActorPointer->floor = 99999.0f;
        func_global_asm_80665564(gCurrentActorPointer, 0.0f);
    }
    func_global_asm_806A6DB4(0);
    if (99999.0f != gCurrentActorPointer->floor) {
        func_global_asm_8065D254(gCurrentActorPointer, 0x3C8, 0x40, 0x40, 0x19, 0x19, 1, 0x96, 0x78, 0, 1.0f);
    }
}

void func_global_asm_806A7600(void *arg0) {
    AAD_global_asm_806A7600 *sp34;
    s16 permanentFlagIndex;
    s32 var_a0_2;
    s32 var_v0;

    sp34 = gCurrentActorPointer->additional_actor_data;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        if (gCurrentActorPointer->unk58 == ACTOR_BALLOON_KROOL) {
            sp34->unk6 = -1;
        } else {
            sp34->unk6 = func_global_asm_80688C30(func_global_asm_80688E68(gCurrentActorPointer));
        }
        if ((sp34->unk6 != -1) && (isFlagSet(sp34->unk6, FLAG_TYPE_PERMANENT))) {
            deleteActor(gCurrentActorPointer);
            return;
        }
        func_global_asm_8066E854(gCurrentActorPointer, 0, 0, 0, -1);
        func_global_asm_8066EB40(gCurrentActorPointer, 175.0f);
        func_global_asm_8066E8E4(gCurrentActorPointer, 0, 12.0f, 0, 80.0f, -1);
        sp34->unk0 = gCurrentActorPointer->unk124->unk0_s32;
        sp34->unk1 = gCurrentActorPointer->unk124->unk4_s32;
        sp34->unk2 = func_global_asm_80723020(gCurrentActorPointer, sp34->unk0, 0, 0.0f, 0.0f, 0.0f, 0);
        if (sp34->unk2 != -1) {
            func_global_asm_807232B8(sp34->unk2, 1);
            func_global_asm_80723284(sp34->unk2, sp34->unk1);
            func_global_asm_80723320(sp34->unk2, -1);
            func_global_asm_8072334C(sp34->unk2, 1);
        }
        sp34->unk4 = 0;
        return;
    }
    if (sp34->unk2 != -1) {
        // TODO: There might be only 1 param for the first call here
        func_global_asm_80723484(sp34->unk2, gCurrentActorPointer);
        func_global_asm_807238D4(sp34->unk2, &gCurrentActorPointer->x_position, &gCurrentActorPointer->y_position, &gCurrentActorPointer->z_position);
    }
    gCurrentActorPointer->y_position += (5.0 * func_global_asm_80612794(sp34->unk4));
    sp34->unk4 = (sp34->unk4 + 0x50) & 0xFFF;
    if ((D_global_asm_8076A068 % 24U) == 0) {
        switch (gCurrentActorPointer->unk58) {
            default:
                permanentFlagIndex = -1;
                break;
            case ACTOR_BALLOON_DIDDY:
                permanentFlagIndex = PERMFLAG_KONG_DIDDY;
                break;
            case ACTOR_BALLOON_CHUNKY:
                permanentFlagIndex = PERMFLAG_KONG_CHUNKY;
                break;
            case ACTOR_BALLOON_TINY:
                permanentFlagIndex = PERMFLAG_KONG_TINY;
                break;
            case ACTOR_BALLOON_LANKY:
                permanentFlagIndex = PERMFLAG_KONG_LANKY;
                break;
        }
        if ((permanentFlagIndex == -1) || (isFlagSet(permanentFlagIndex, FLAG_TYPE_PERMANENT) != FALSE)) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            func_global_asm_807149B8(1);
            var_a0_2 = TRUE;
            if (gCurrentActorPointer->unk58 == ACTOR_BALLOON_KROOL) {
                var_a0_2 = FALSE;
            } else if ((gPlayerPointer->unk58 == ACTOR_DIDDY) && (gCurrentActorPointer->unk58 == ACTOR_BALLOON_DIDDY)) {
                var_a0_2 = FALSE;
            } else if ((gPlayerPointer->unk58 == ACTOR_CHUNKY) && (gCurrentActorPointer->unk58 == ACTOR_BALLOON_CHUNKY)) {
                var_a0_2 = FALSE;
            } else if ((gPlayerPointer->unk58 == ACTOR_TINY) && (gCurrentActorPointer->unk58 == ACTOR_BALLOON_TINY)) {
                var_a0_2 = FALSE;
            } else if ((gPlayerPointer->unk58 == ACTOR_LANKY) && (gCurrentActorPointer->unk58 == ACTOR_BALLOON_LANKY)) {
                var_a0_2 = FALSE;
            } else if ((gPlayerPointer->unk58 == ACTOR_DK) && (gCurrentActorPointer->unk58 == ACTOR_BALLOON_DK)) {
                var_a0_2 = FALSE;
            }
            if (var_a0_2 != 0) {
                changeActorColor(0xFF, 0xFF, 0xFF, 0x96);
            } else {
                func_global_asm_8071498C(func_global_asm_8071EB70);
                func_global_asm_80714950(0x226);
            }
            func_global_asm_80714A28(4);
            func_global_asm_80714998(3);
            func_global_asm_80714C08(arg0, 0.8f, gCurrentActorPointer, 1, 2);
            gCurrentActorPointer->noclip_byte = 2;
        } else {
            gCurrentActorPointer->noclip_byte = 1;
        }
    }
    if (D_global_asm_807FBD70 == 4) {
        func_global_asm_80686CF8(gCurrentActorPointer);
        playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0x2BF, 0xFF, 0x7F, 0x1E, 0, 0.0f, 0);
        deleteActor(gCurrentActorPointer);
        if (gCurrentActorPointer->unk58 == ACTOR_BALLOON_KROOL) {
            func_global_asm_80724994(3, 1, 0x27, 0, 0);
            return;
        }
        if (sp34->unk6 != -1) {
            setFlag(sp34->unk6, TRUE, FLAG_TYPE_PERMANENT);
        }
        func_global_asm_806F8BC4(0, 0, 0);
        changeCollectableCount(0, 0, 10);
    }
}

void func_global_asm_806A7B04(void) {
    func_global_asm_806A7600(&D_global_asm_80720FBC);
}

void func_global_asm_806A7B28(void) {
    func_global_asm_806A7600(&D_global_asm_80720F98);
}

void func_global_asm_806A7B4C(void) {
    func_global_asm_806A7600(&D_global_asm_80721028);
}

void func_global_asm_806A7B70(void) {
    func_global_asm_806A7600(&D_global_asm_80721004);
}

void func_global_asm_806A7B94(void) {
    func_global_asm_806A7600(&D_global_asm_80720FE0);
}

void func_global_asm_806A7BB8(void) {
    func_global_asm_806A7600(&D_global_asm_80721004);
}

// Headphones
void func_global_asm_806A7BDC(void) {
    s32 sp64;
    s32 sp60;
    Struct807504A4 sp44;

    sp64 = D_global_asm_807FC950->character_progress[current_character_index[0]].instrument & 1;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_8066E854(gCurrentActorPointer, 0, 10.0f, 0, -1);
        func_global_asm_8066EB40(gCurrentActorPointer, 175.0f);
        func_global_asm_8066E8E4(gCurrentActorPointer, 0, 10.0f, 0, 80.0f, -1);
        gCurrentActorPointer->floor = 99999.0f;
        func_global_asm_80665564(gCurrentActorPointer, 0.0f);
    }
    func_global_asm_8067ACB4(gCurrentActorPointer);
    if ((sp64 != 0) && (D_global_asm_807FBD70 == 4) && ((object_timer % 5U) == 0)) {
        sp60 = RandClamp(255) % 7;
        sp44 = D_global_asm_807504A4;
        func_global_asm_8071498C(func_global_asm_8071D28C);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_80714950(0x64);
        func_global_asm_80714C08(sp44.unk0[sp60], 0.2f, gCurrentActorPointer, 1, 0);
        playSong(MUSIC_127_HEADPHONES_GET, 1.0f);
        func_global_asm_806F8BC4(7, 0, 0);
        changeCollectableCount(7, 0, func_global_asm_806F8EDC(7, 0));
    }
    if (!(object_timer & 0xF)) {
        func_global_asm_807149B8(1);
        func_global_asm_8071498C(func_global_asm_8071EB70);
        func_global_asm_80714950(0x226);
        func_global_asm_80714998(2);
        changeActorColor(0xFF, 0xFF, 0xFF, sp64 != 0 ? 0xFF : 0x7F);
        func_global_asm_80714C08(&D_global_asm_80721170, 0.4f, gCurrentActorPointer, 1, 2);
    }
    if (99999.0f != gCurrentActorPointer->floor) {
        func_global_asm_8065D254(gCurrentActorPointer, 0x3C8, 0x40, 0x40, 0xE, 0xE, 1, 0x96, 0x78, 0, 1.0f);
    }
}

void func_global_asm_806A7EF0(void) {
    AAD_global_asm_806A7EF0 *aaD;
    AnimationStateUnk20 *temp_v0_2;

    aaD = gCurrentActorPointer->additional_actor_data;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->animation_state->unk20 = malloc(0x20);
        func_global_asm_80611690(gCurrentActorPointer->animation_state->unk20);
        aaD->unk4 = 0;
        aaD->unk0 = 1.0f;
        gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
        gCurrentActorPointer->object_properties_bitfield |= 0x40000000;
        gCurrentActorPointer->shadow_opacity = D_global_asm_807504CC;
    }
    if (D_global_asm_807504D0 < gCurrentActorPointer->shadow_opacity) {
        gCurrentActorPointer->shadow_opacity -= D_global_asm_807504D0;
    }
    aaD->unk4++;
    if (D_global_asm_807504C4 < aaD->unk4) {
        deleteActor(gCurrentActorPointer);
        return;
    }
    aaD->unk0 *= D_global_asm_807504C0;
    temp_v0_2 = gCurrentActorPointer->animation_state->unk20;
    temp_v0_2->unk0 = D_global_asm_807504C8;
    temp_v0_2->unk1 = 0xFF;
    temp_v0_2->unk4 = aaD->unk0;
    temp_v0_2->unk8 = aaD->unk0;
    temp_v0_2->unkC = aaD->unk0;
    temp_v0_2[1].unk0 = 0xFF;
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806A8070(void) {
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->object_properties_bitfield |= 0x40000000;
    }
    renderActor(gCurrentActorPointer, 0);
}
