#include <ultra64.h>
#include "functions.h"

extern uSprite D_jetpac_8002C4D0[];
extern uSprite D_jetpac_8002B9C0[];

extern uSprite D_jetpac_8002C330;
extern uSprite D_jetpac_8002C348[];
extern uSprite D_jetpac_8002C3A8[];
extern JetpacStruct D_jetpac_8002C518;

extern JetpacPlayerStruct D_jetpac_8002EC30;

extern MetaJetpacStruct3 D_jetpac_8002F050;
extern f32 D_jetpac_8002F054;
extern s32 D_jetpac_8002F060;
extern s32 D_jetpac_8002F064;
extern s32 D_jetpac_8002F068;
extern s32 D_jetpac_8002F07C;
extern s32 D_jetpac_8002F080;
extern s32 D_jetpac_8002F084;
extern s32 D_jetpac_8002F088;
extern s32 D_jetpac_8002F08C;
extern s32 D_jetpac_8002F094;

extern JetpacStruct D_jetpac_8002F09C[]; // At least 4 big
extern JetpacStruct1 D_jetpac_8002F3D0[0x300];

extern s32 D_jetpac_80045BD0;

extern void func_global_asm_8070E8F0(Gfx**, uSprite*);
void func_jetpac_80025700(uSprite *, s32, s32, rgba*, s32);
void func_jetpac_80026318(MetaJetpacStruct3*);
void func_jetpac_80027010(MetaJetpacStruct3 *arg0);

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_15D4/func_jetpac_80025700.s")

void func_jetpac_800254B8(uSprite *, s32, s32, rgba*, s32);
extern uSprite D_80042BD0[0x100][2];
extern s32 D_jetpac_80045BD0;

/* Frustratingly close...
void func_jetpac_80025700(uSprite* arg0, s32 base_or_stride_y, s32 base_or_stride_x, rgba* color, s32 arg4) {
    uSprite* temp_a0;
    s32 limit_x;
    s32 limit_y;
    s32 next_y;
    s32 next_x;
    s32 current_y;
    s32 current_x;
    s32 previous_x;
    s32 previous_y;
    s32 index;
    u8 index2;

    // I may have the X and Y mixed up here, I just know this is a 2D something...
    limit_y = arg0->unkA - 1;
    limit_x = arg0->unkC - 1;

    if (D_jetpac_80045BD0 >= 0x100) {
        return;
    }

    if (base_or_stride_y < 0) {
        base_or_stride_y += 0x100;
    }

    for (previous_x = 0, current_x = base_or_stride_x; previous_x < limit_x; previous_x = current_x, current_x += base_or_stride_x) {
        current_x += 8;
        current_x = (current_x & 0xFFF8) - base_or_stride_x;
        if (current_x >= limit_x) {
            if (!current_x);
            current_x = limit_x;
        }

        for (previous_y = 0, current_y = base_or_stride_y; previous_y < limit_y; previous_y = current_y, current_y += base_or_stride_y) {
            index = D_jetpac_80045BD0;
            if (index >= 0x100) {
                return;
            }

            temp_a0 = &D_80042BD0[D_global_asm_807444FC][index];
            D_jetpac_80045BD0++;
            *temp_a0 = *arg0;

            current_y += 8;
            current_y = (current_y & 0xFFF8) - base_or_stride_y;
            if (current_y >= limit_y) {
                if (!current_y);
                current_y = limit_y;
            }

            if (arg4 != 0) {
                temp_a0->unk10 += (limit_y - current_y);
            } else {
                temp_a0->unk10 += previous_y;
            }

            temp_a0->unk12 += previous_x;
            temp_a0->unkA = (current_y - previous_y) + 1;
            temp_a0->unkC = (current_x - previous_x) + 1;

            next_x = base_or_stride_x + previous_x;
            next_y = base_or_stride_y + previous_y;
            if (next_y >= 0x100) {
                next_y -= 0x100;
            }

            func_jetpac_800254B8(temp_a0, next_y, next_x, color, arg4);
        }
    }
}
*/

/*
void func_jetpac_80025700(uSprite *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 lim_0;
    s32 lim_1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0_2;
    s32 var_s2;
    s32 var_s5_2;
    s32 var_v1;
    uSprite *temp_a0;

    lim_0 = arg0->unkC - 1;
    lim_1 = arg0->unkA - 1;
    if (D_jetpac_80045BD0 > 0xFF) {
        return;
    }
    if (arg1 < 0) {
        arg1 += 0x100;
    }
    var_s2 = 0;
    do {
        var_s5_2 = ((arg2 + 8) & 0xFFF8) - arg2;
        var_v1 = 0;
        var_s5_2 = MIN(var_s5_2, lim_0);
        do {
            temp_v0 = D_jetpac_80045BD0;
            if (D_jetpac_80045BD0 > 0xFF) {
                return;
            }
            D_jetpac_80045BD0 = temp_v0 + 1;
            temp_a0 = &D_80042BD0[temp_v0][D_global_asm_807444FC];
            *temp_a0 = *arg0;
            var_s0_2 = ((arg1 + 8) & 0xFFF8) - arg1;
            temp_v0_2 = arg1 + var_v1;
            var_s0_2 = MIN(var_s0_2, lim_1);
            if (arg4) {
                temp_a0->unk10 += (lim_1 - var_s0_2);
            } else {
                temp_a0->unk10 += var_v1;
            }
            temp_a0->unk12 += var_s2;
            temp_a0->unkA = ((var_s0_2 - var_v1) + 1);
            temp_a0->unkC = ((var_s5_2 - var_s2) + 1);
            temp_v0_2 &= 0xFF;
            if (temp_v0_2 >= 0x100) {
                temp_v0_2 -= 0x100;
            }
            func_jetpac_800254B8(temp_a0, temp_v0_2, arg2 + var_s2, arg3, arg4);
            var_v1 = var_s0_2;
            arg1 = var_s0_2 + arg1;
        } while (var_s0_2 < lim_1);
        var_s2 = var_s5_2;
        arg2 += var_s5_2;
    } while (var_s5_2 < lim_0);
}
*/

void func_jetpac_80025904(Gfx **arg0) {
    JetpacStruct1 *s3;
    s32 j, i;
    Gfx *dl;
    s32 k;
    u8 red;

    s3 = &D_jetpac_8002F3D0[0];
    dl = *arg0;
    for (i = 0; i < 0x18; i++) {
        for (j = 0; j < 0x20; j++) {
            if (s3->num_draw_sprites) {
                gDPSetPrimColor(dl++, 0, 0, s3->hue.as_array[0], s3->hue.as_array[1], s3->hue.as_array[2], 0xFF);
            }
            for (k = 0; k < s3->num_draw_sprites; k++) {
                func_global_asm_8070E8F0(&dl, s3->draw_sprites[k].draw_sprite);
                func_global_asm_8070F2C8(0x400, 0x400, s3->draw_sprites[k].unk8, 0);
                func_global_asm_8070F2FC(&dl, (s3->draw_sprites[k].x + 0x20) << 2, (s3->draw_sprites[k].y + 0x18) << 2);
            }
            s3++;
        }
    }
    *arg0 = dl;
}

void func_jetpac_80025A60(ExplosionSpriteState *arg0) {
    s32 sp2C;

    sp2C = (arg0->frame_counter / 14.0f) * 6.0f;
    if ((arg0->frame_counter % 7) == 0) {
        if (func_jetpac_80027210() < 0.5) {
            arg0->color.green = 0;
        } else {
            arg0->color.green = 0xFF;
        }
        if (func_jetpac_80027210() < 0.5) {
            arg0->color.blue = 0;
        } else {
            arg0->color.blue = 0xFF;
        }
    }
    func_jetpac_80025700(&D_jetpac_8002B9C0[sp2C], arg0->posX, arg0->posY, &arg0->color, 0);
    arg0->frame_counter++;
}

s32 func_jetpac_80025B70(JetpacSpatialState *arg0) {
    return (((s32) arg0->posX + arg0->unk1C.left) / 2) % 4;
}

void func_jetpac_80025BB8(MetaJetpacStruct3 *arg0, s32 new_is_flying) {
    if ((new_is_flying == 0) && (arg0->is_flying != 0)) {
        arg0->spatial_state.posX = (s32)arg0->spatial_state.posX & 0xFFFE;
    } else if ((new_is_flying != 0) && (arg0->is_flying == 0)) {
        func_jetpac_80027010(arg0);
    }
    arg0->spatial_state.unk1C.left = 0;
    arg0->spatial_state.unk1C.right = 0x10;
    arg0->is_flying = new_is_flying;
}

JetpacStruct *jetpac_get_free_laser(MetaJetpacStruct3 *arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (arg0->lasers[i].unk0.spatial_state.unk14 == 0) {
            return &arg0->lasers[i];
        }
    }
    return 0;
}

void func_jetpac_80025CA0(JetpacSpatialState *arg0) {
    arg0->unk14 = 4;
    arg0->unk1C.counter = 0;
}

void func_jetpac_80025CB0(JetpacStructSub0* arg0) {
    s32 new_var;
    f32 var_f12;
    f32 temp_f14;
    f32 var_f0;
    f32 temp_f2;
    JetpacSpatialState* spatial_state = &arg0->spatial_state;
    if ((spatial_state->unk14 == 3) && ((u32) arg0->counter_limit < (u32) spatial_state->unk1C.counter)) {
        func_jetpac_80025CA0(spatial_state);
    }
    if ((spatial_state->unk14 == 4) && (spatial_state->unk1C.right == spatial_state->unk1C.left)) {
        spatial_state->unk14 = 0;
        spatial_state->unk1C.counter = 0;
    }
    if (spatial_state->unk14 != 0) {
        if (spatial_state->unk14 == 3) {
            if (spatial_state->is_facing_left != 0) {
                var_f12 = spatial_state->unk1C.left;
                var_f0 = (MIN(spatial_state->unk1C.counter, 4) * 8) + var_f12;
            } else {
                var_f0 = spatial_state->unk1C.right;
                var_f12 = var_f0 - (MIN(spatial_state->unk1C.counter, 4) * 8);
            }
            temp_f14 = spatial_state->unk1C.top;
            temp_f2 = spatial_state->unk1C.bottom;
            if (func_jetpac_8002A974(var_f12, temp_f14, var_f0, temp_f2) != 0) {
                func_jetpac_80025CA0(spatial_state);
            }
            else if (func_jetpac_80028CF8(var_f12, temp_f14, var_f0, temp_f2, 0) >= 0) {
                func_jetpac_80025CA0(spatial_state);
            }
            else if (func_jetpac_800283EC(var_f12, temp_f14, var_f0, temp_f2) != 0) {
                func_jetpac_80025CA0(spatial_state);
            }
            else
            {
                if (spatial_state->is_facing_left != 0) {
                    spatial_state->unk1C.left -= 8;
                    if (spatial_state->unk1C.counter >= 0xD) {
                        spatial_state->unk1C.right -= 8;
                    }
                } else {
                    spatial_state->unk1C.right += 8;
                    if (spatial_state->unk1C.counter >= 0xD) {
                        spatial_state->unk1C.left += 8;
                    }
                }
                spatial_state->unk1C.counter += 1;
            }
        }
        else if (spatial_state->unk14 == 4) {
            new_var = (spatial_state->unk1C.right - spatial_state->unk1C.left) / 8;
            if ((spatial_state->unk1C.counter + new_var) >= 0xD) {
                if (spatial_state->is_facing_left != 0) {
                    spatial_state->unk1C.right -= 8;
                } else {
                    spatial_state->unk1C.left += 8;
                }
            }
            spatial_state->unk1C.counter += 1;
        }
    }
}

void func_jetpac_80025F48(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, rgba* arg4, s32 arg5) {
    s32 temp_t2;

    func_jetpac_80025700(&D_jetpac_8002C4D0[arg0], *arg1, arg3, arg4, arg5);
    *arg1 += arg2;
    if (*arg1 < 0) {
        *arg1 += 0x100;
    }
}

void func_jetpac_80025FC4(JetpacStruct *arg0) {
    s32 sp6C;
    s32 var_a0;
    s32 var_s4;
    s32 temp_s5;
    s32 temp_s7;
    s32 temp_t7;
    s32 var_s1;
    s32 i;

    if (var_s4) {} // TODO: This fixes regalloc but it's an awful way to get a match...

    temp_s5 = arg0->unk0.spatial_state.is_facing_left;
    var_s1 = 0;
    if (arg0->unk0.spatial_state.unk14 >= 2) {
        var_s4 = -8;
        temp_s7 = arg0->unk0.spatial_state.posY;
        temp_t7 = (arg0->unk0.spatial_state.unk1C.right - arg0->unk0.spatial_state.unk1C.left) / 8;
        if (arg0->unk0.spatial_state.unk14 == 4) {
            var_s1 = arg0->unk0.spatial_state.unk1C.counter;
        }
        if (temp_s5 != 0) {
            var_s4 = 8;
            sp6C = arg0->unk0.spatial_state.unk1C.left;
        } else {
            sp6C = arg0->unk0.spatial_state.unk1C.right - 8;
        }
        for (i = 0; i < temp_t7; i++) {
            if (var_s1 < 4) {
                var_a0 = 0;
            } else if (var_s1 < 9) {
                var_a0 = 1;
            } else {
                var_a0 = 2;
            }
            func_jetpac_80025F48(var_a0, &sp6C, var_s4, temp_s7, &arg0->unk0.spatial_state.color, temp_s5);
            var_s1 += 1;
        }
    }
}

void func_jetpac_800260DC(MetaJetpacStruct3 *arg0) {
    JetpacStruct *temp_v0;
    s32 temp_f4;
    s32 temp_f16_2;

    temp_v0 = jetpac_get_free_laser(arg0);
    if (temp_v0 == NULL) {
        if ((ABS(arg0->spatial_state.velY)) < 0.01f) {
            if (arg0->spatial_state.posY < 152.0f) {
                func_jetpac_80024E70(6);
            }
        }
    } else {
        temp_v0->unk0.spatial_state.is_facing_left = arg0->spatial_state.is_facing_left;
        if (temp_v0->unk0.spatial_state.is_facing_left != 0) {
            temp_v0->unk0.spatial_state.posX = ((s32)(arg0->spatial_state.posX + arg0->spatial_state.unk1C.left) / 8) * 8;
            temp_v0->unk0.spatial_state.velX = -8.0f;
        } else {
            temp_v0->unk0.spatial_state.posX = ((s32)(arg0->spatial_state.posX + arg0->spatial_state.unk1C.right + 6.0f) / 8) * 8;
            temp_v0->unk0.spatial_state.velX = 8.0f;
        }
        temp_v0->unk0.spatial_state.unk1C.left = temp_v0->unk0.spatial_state.posX;
        temp_v0->unk0.spatial_state.unk1C.right = temp_v0->unk0.spatial_state.posX;
        temp_v0->unk0.spatial_state.posY = arg0->spatial_state.posY + 10.0f;
        temp_v0->unk0.spatial_state.velY = 0.0f;
        temp_f16_2 = temp_v0->unk0.spatial_state.posY;
        temp_v0->unk0.spatial_state.unk1C.bottom = temp_f16_2 + 1;
        temp_v0->unk0.spatial_state.unk1C.top = temp_f16_2;
        temp_f4 = func_jetpac_80027210() * 3.0f;
        temp_v0->unk0.spatial_state.color.red = 0xFF;
        temp_v0->unk0.spatial_state.color.green = 0xFF;
        if (temp_f4 < 2) {
            temp_v0->unk0.spatial_state.color.as_array[temp_f4] = 0;
        }
        temp_v0->unk0.spatial_state.color.blue = 0xFF;
        temp_v0->unk0.spatial_state.color.alpha = 1;
        temp_v0->unk0.spatial_state.unk14 = 3;
        temp_v0->unk0.spatial_state.unk1C.counter = 0;
        temp_v0->unk0.counter_limit = (s32)(func_jetpac_80027210() * 8.0f) + 0xD;
        temp_v0->unk48.unk0 = func_jetpac_80025CB0;
        temp_v0->unk48.unk4 = 0;
        func_jetpac_80024E70(6);
    }
}

void func_jetpac_80026318(MetaJetpacStruct3* arg0) {
    Competitor* player;
    s8 pad[0x8];
    f32 max_speed_x;
    f32 max_speed_y;
    s32 holding_fly_input;
    s32 holding_hover_input; 
    s32 holding_fire_input;
    s32 holding_left_input;
    s32 holding_right_input;
    s32 other_index;

    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    holding_fire_input = D_jetpac_8002EC30.unk0 & 0x4000;
    holding_left_input = D_jetpac_8002EC30.unk0 & 0x200;
    holding_right_input = D_jetpac_8002EC30.unk0 & 0x100;
    holding_fly_input = D_jetpac_8002EC30.unk0 & 0x8000;
    holding_hover_input = D_jetpac_8002EC30.unk0 & 0x2030;

    if (holding_fire_input && (arg0->laser_delay_counter >= 5)) {
        func_jetpac_800260DC(arg0);
        arg0->laser_delay_counter = 0;
    } else if (arg0->laser_delay_counter < 5) {
        arg0->laser_delay_counter++;
    }

    if ((holding_fly_input != 0) && ((arg0->is_flying == 0) || (holding_hover_input == 0))) {
        func_jetpac_80025BB8(arg0, 1);
        arg0->spatial_state.velY -= 0.2f;
    } else if (arg0->is_flying != 0) {
        if (holding_hover_input != 0) {
            arg0->spatial_state.velY = 0.0f;
        } else {
            arg0->spatial_state.velY += 0.2;
        }
    }

    if(arg0->is_flying);

    if (holding_left_input != 0) {
        arg0->spatial_state.velX -= 0.33333334f;
        if ((arg0->spatial_state.is_facing_left == 0) && (arg0->spatial_state.velX <= 0.0f)) {
            arg0->spatial_state.is_facing_left = 1;
            func_jetpac_80025BB8(arg0, arg0->is_flying);
        }
    } else if (holding_right_input != 0) {
        arg0->spatial_state.velX += 0.33333334f;
        if ((arg0->spatial_state.is_facing_left != 0) && (arg0->spatial_state.velX >= 0.0f)) {
            arg0->spatial_state.is_facing_left = 0;
            func_jetpac_80025BB8(arg0, arg0->is_flying);
        }
    } else {
        if (arg0->spatial_state.velX > 0.0f) {
            arg0->spatial_state.velX -= 0.16666667f;
        } else if (arg0->spatial_state.velX < 0.0f) {
            arg0->spatial_state.velX += 0.16666667f;
        }
    }

    if (arg0->is_flying != 0) {
        max_speed_x = 2.0f;
        max_speed_y = 2.0f;
    } else {
        max_speed_x = 1.0f;
        max_speed_y = 0.0f;
    }

    arg0->spatial_state.velX = CLAMP(arg0->spatial_state.velX, -max_speed_x, max_speed_x);
    arg0->spatial_state.velY = CLAMP(arg0->spatial_state.velY, -max_speed_y, max_speed_y);

    if ((arg0->spatial_state.velX < 0.1) && (arg0->spatial_state.velX > -0.1)) {
        arg0->spatial_state.velX = 0.0f;
    }
    if ((arg0->spatial_state.velY < 0.1) && (arg0->spatial_state.velY > -0.1)) {
        arg0->spatial_state.velY = 0.0f;
    }

    if (arg0->is_flying != 0) {
        other_index = func_jetpac_80028CF8(
            arg0->spatial_state.unk1C.left + arg0->spatial_state.posX + arg0->spatial_state.velX,
            arg0->spatial_state.unk1C.top + arg0->spatial_state.posY + arg0->spatial_state.velY,
            arg0->spatial_state.unk1C.right + arg0->spatial_state.posX + arg0->spatial_state.velX,
            arg0->spatial_state.unk1C.bottom + arg0->spatial_state.posY + arg0->spatial_state.velY, 1);
        if (other_index >= 0) {
            if (D_jetpac_8002EC30.platforms[other_index].spatial_state.unk1C.bottom <= arg0->spatial_state.unk1C.top + arg0->spatial_state.posY) {
                arg0->spatial_state.velY *= -0.4f;
                if (ABS(arg0->spatial_state.velY) <= 0.15f) {
                    arg0->spatial_state.velY = 0.0f;
                }
            } else if ((arg0->spatial_state.unk1C.bottom + arg0->spatial_state.posY) <= D_jetpac_8002EC30.platforms[other_index].spatial_state.unk1C.top) {
                arg0->ground_platform_index = other_index;
                arg0->spatial_state.velY = 0.0f;
                func_jetpac_80025BB8(arg0, 0);
                arg0->spatial_state.posY = D_jetpac_8002EC30.platforms[other_index].spatial_state.posY - 24.0f;
            } else {
                arg0->spatial_state.velX *= -0.5f;
            }
        }
    } else {
        other_index = func_jetpac_80028E04(arg0->ground_platform_index, (arg0->spatial_state.unk1C.left + arg0->spatial_state.posX + arg0->spatial_state.velX), (arg0->spatial_state.unk1C.right + arg0->spatial_state.posX + arg0->spatial_state.velX));
        if (other_index != -2) {
            if ((other_index != -1) && (other_index != 1)) {
                if (other_index == 2) {
block_62:
                    func_jetpac_80025BB8(arg0, 1);
                    arg0->spatial_state.velY = -0.5f;
                }
            } else if ((arg0->spatial_state.is_facing_left == 0) && (holding_left_input == 0)) {
                arg0->spatial_state.velX = 1.0f;
            } else if (holding_right_input == 0) {
                arg0->spatial_state.velX = -1.0f;
            }
        } else {
            goto block_62;
        }
    }

    arg0->spatial_state.posX += arg0->spatial_state.velX;
    if ((arg0->spatial_state.posX + arg0->spatial_state.unk1C.right) > 256.0f) {
        arg0->spatial_state.posX -= 256.0f;
    }
    if ((arg0->spatial_state.posX + arg0->spatial_state.unk1C.left) < 0.0f) {
        arg0->spatial_state.posX += 256.0f;
    }
    arg0->spatial_state.posY += arg0->spatial_state.velY;
    if (arg0->spatial_state.posY < 18.0f) {
        arg0->spatial_state.posY = 18.0f;
        arg0->spatial_state.velY = 0.0f;
    }
    if (arg0->spatial_state.posY > 168.0f) {
        arg0->spatial_state.posY = 168.0f;
    }
    if ((func_jetpac_80027330(arg0->spatial_state.posX) != 0) && (player->rocket_stage == 8) && (arg0->spatial_state.posY > 152.0f)) {
        func_jetpac_80024F9C(4);
    }
}

void func_jetpac_80026A3C(MetaJetpacStruct3 *arg0) {
    Competitor *player;
    s32 temp_v0;

    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    if (arg0->spatial_state.unk1C.counter < 0xE) {
        arg0->spatial_state.unk1C.counter++;
        return;
    }
    player->lives--;
    func_jetpac_80025368(player);
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_15D4/func_jetpac_80026AB0.s")

/*
void func_jetpac_80026AB0(void) {
    f32 temp_f2;
    f32 var_f0;
    s32 temp_v0;
    s32 var_a1;

    var_a1 = 1;
    if (D_jetpac_8002F064 >= 2) {
        if (D_jetpac_8002F064 == 4 && D_jetpac_8002F094 >= 8) {
            var_a1 = 0;
        }
        temp_v0 = func_jetpac_80025B70(&D_jetpac_8002F050);
        var_f0 = D_jetpac_8002F050[0].unk0;
        temp_f2 = D_jetpac_8002F054;
        if (var_a1 != 0) {
            if (D_jetpac_8002F080 == 0) {
                func_jetpac_80025700(&D_jetpac_8002C3A8[temp_v0], (s16)var_f0 & 0xFFFE, temp_f2, &D_jetpac_8002F060, D_jetpac_8002F068);
            } else {
                func_jetpac_80025700(&D_jetpac_8002C330, var_f0, temp_f2, &D_jetpac_8002F060, D_jetpac_8002F068);
                if (D_jetpac_8002F068 == 0) {
                    if (temp_v0 == 4) {
                        var_f0 -= 1.0f;
                    }
                    var_f0 -= 3.0f;
                } else {
                    if (temp_v0 == 4) {
                        var_f0 += 1.0f;
                    }
                    var_f0 += 10.0f;
                }
                func_jetpac_80025700(&D_jetpac_8002C348[temp_v0], var_f0, temp_f2 + 18.0f, &D_jetpac_8002F060, D_jetpac_8002F068);
            }
        }
        if (D_jetpac_8002F094 < 0xE) {
            func_jetpac_80025A60(&D_jetpac_8002F08C);
        }
    }
}
*/

void func_jetpac_80026CA4(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        func_jetpac_80025FC4(&D_jetpac_8002F09C[i]);
    }
}

void func_jetpac_80026CEC(void) {
    JetpacStruct *temp_a0;
    s32 i;

    for (i = 0; i < 4; i++) {
        temp_a0 = &D_jetpac_8002F050.lasers[i];
        if (temp_a0->unk48.unk0 != 0) {
            temp_a0->unk48.unk0(temp_a0);
        }
    }
}

void func_jetpac_80026D48(void) {
    s32 phi_v0;

    if (!func_jetpac_80026FE0()) {
        phi_v0 = D_jetpac_8002F064;
        if (phi_v0 == 1) {
            func_jetpac_80024E70(3);
            phi_v0 = 3;
        }
        D_jetpac_8002F064 = phi_v0;
        if (phi_v0 == 3) {
            func_jetpac_80026318(&D_jetpac_8002F050);
        }
        phi_v0 = D_jetpac_8002F064;
        if (phi_v0 == 4) {
            func_jetpac_80026A3C(&D_jetpac_8002F050);
        }
    }
}

void func_jetpac_80026DC8(void) {
    s32 i;
    JetpacStruct sp1C;

    sp1C = D_jetpac_8002C518;
    D_jetpac_8002EC30.unk428 = 0.0f;
    D_jetpac_8002EC30.unk42C = 0.0f;
    D_jetpac_8002EC30.unk430 = 0xFF;
    D_jetpac_8002EC30.unk431 = 0xFF;
    D_jetpac_8002EC30.unk432 = 0xFF;
    D_jetpac_8002EC30.unk433 = 1;
    D_jetpac_8002EC30.unk434 = 1;
    D_jetpac_8002EC30.unk44C = 0;
    D_jetpac_8002EC30.unk438 = 0;
    D_jetpac_8002EC30.unk464 = 0xE;
    D_jetpac_8002EC30.unk468 = 0xFF;
    D_jetpac_8002EC30.unk46B = 1;
    D_jetpac_8002EC30.unk440 = 0;
    D_jetpac_8002EC30.unk43C = 0;
    D_jetpac_8002EC30.unk444 = 0x10;D_jetpac_8002EC30.unk448 = 0x18;

    D_jetpac_8002EC30.unk450 = 1;
    D_jetpac_8002EC30.unk420 = 126.0f;
    D_jetpac_8002EC30.unk424 = 160.0f;
    func_jetpac_80025BB8(&D_jetpac_8002F050, 0);
    D_jetpac_8002F084 = 3;
    D_jetpac_8002F088 = 4;
    for (i = 0; i < 4; i++) {
        D_jetpac_8002F09C[i] = sp1C;
    }
}

int func_jetpac_80026FE0(void) {
    return D_jetpac_8002F064 == 1 && D_jetpac_8002F07C < 0xB4;
}

void func_jetpac_80027010(MetaJetpacStruct3 *arg0) {
    if (arg0->explosion_sprite.frame_counter >= 0xE) {
        arg0->explosion_sprite.frame_counter = 0;
        arg0->explosion_sprite.posX = (s32)arg0->spatial_state.posX & 0xFFF8;
        arg0->explosion_sprite.posY = arg0->spatial_state.posY + 7.0f;
    }
}
