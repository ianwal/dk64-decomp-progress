#include <ultra64.h>
#include "functions.h"

extern uSprite D_jetpac_8002C4D0[];
extern uSprite D_jetpac_8002B9C0[];

extern uSprite D_jetpac_8002C330;
extern uSprite D_jetpac_8002C348[];
extern uSprite D_jetpac_8002C3A8[];
extern JetpacStruct D_jetpac_8002C518;

extern JetpacGameStruct D_jetpac_8002EC30;

extern JetpacPlayerStruct D_jetpac_8002F050;
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
extern JetpacRenderingCell D_jetpac_8002F3D0[0x300];

extern s32 D_jetpac_80045BD0;

extern void func_global_asm_8070E8F0(Gfx**, uSprite*);
void func_jetpac_80025700(uSprite *, s32, s32, rgba*, s32);
void func_jetpac_80026318(JetpacPlayerStruct*);
void func_jetpac_80027010(JetpacPlayerStruct *arg0);

// Frustratingly close...
// https://decomp.me/scratch/FSiyf
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_15D4/func_jetpac_80025700.s")

void func_jetpac_800254B8(uSprite *, s32, s32, rgba*, s32);
extern uSprite D_80042BD0[2][0x100];
extern s32 D_jetpac_80045BD0;

/*
// Splits the sprite up into 8x8 cells on the screen to emulate old arcade hardware
void func_jetpac_80025700(uSprite* arg0, s32 base_x, s32 base_y, rgba* color, s32 horizontal_flip) {
    uSprite* next_sprite;
    s32 final_subsprite_bottom;
    s32 final_subsprite_right;
    s32 current_subsprite_left;
    s32 current_subsprite_top;
    s32 current_subsprite_right;
    s32 current_subsprite_bottom;
    s32 previous_subsprite_bottom;
    s32 previous_subsprite_right;

    final_subsprite_right = arg0->s.SubImageWidth - 1;
    final_subsprite_bottom = arg0->s.SubImageHeight - 1;
    
    if (D_jetpac_80045BD0 >= 256) {
        return;
    }

    if (base_x < 0) {
        base_x += 256;
    }
    
    previous_subsprite_bottom = 0;
    current_subsprite_bottom = base_y;
    while (previous_subsprite_bottom < final_subsprite_bottom)
    {
        current_subsprite_bottom += 8;
        current_subsprite_bottom = (current_subsprite_bottom & 0xFFF8) - base_y;
        if (current_subsprite_bottom >= final_subsprite_bottom) {
            if (!current_subsprite_bottom); // Probably fake, but doesn't affect lingering codegen difference so just suppressing noise
            current_subsprite_bottom = final_subsprite_bottom;
        }
        
        previous_subsprite_right = 0, current_subsprite_right = base_x; 
        while (previous_subsprite_right < final_subsprite_right)
        {
            if (D_jetpac_80045BD0 >= 256) {
                return;
            }
            
            next_sprite = &D_80042BD0[D_global_asm_807444FC][D_jetpac_80045BD0++];
            *next_sprite = *arg0;
            
            current_subsprite_right += 8;
            current_subsprite_right = (current_subsprite_right & 0xFFF8) - base_x;
            if (current_subsprite_right >= final_subsprite_right) {
                if (!current_subsprite_right); // Probably fake, but doesn't affect lingering codegen difference so just suppressing noise
                current_subsprite_right = final_subsprite_right;
            }

            if (horizontal_flip != 0) {
                next_sprite->s.SourceImageOffsetS += (final_subsprite_right - current_subsprite_right);
            } else {
                next_sprite->s.SourceImageOffsetS += previous_subsprite_right;
            }
            
            next_sprite->s.SourceImageOffsetT += previous_subsprite_bottom;
            next_sprite->s.SubImageWidth = (current_subsprite_right - previous_subsprite_right) + 1;
            next_sprite->s.SubImageHeight = (current_subsprite_bottom - previous_subsprite_bottom) + 1;
            
            current_subsprite_top = base_y + previous_subsprite_bottom;                
            current_subsprite_left = base_x + previous_subsprite_right;
            if (current_subsprite_left >= 256) {
                current_subsprite_left -= 256;
            }

            func_jetpac_800254B8(next_sprite, current_subsprite_left, current_subsprite_top, color, horizontal_flip);
            previous_subsprite_right = current_subsprite_right;
            current_subsprite_right += base_x;
        }

        previous_subsprite_bottom = current_subsprite_bottom;
        current_subsprite_bottom += base_y;
    }
}
*/

void func_jetpac_80025904(Gfx **arg0) {
    JetpacRenderingCell *s3;
    s32 j, i;
    Gfx *dl;
    s32 k;
    u8 red;

    s3 = &D_jetpac_8002F3D0[0];
    dl = *arg0;
    for (i = 0; i < 0x18; i++) {
        for (j = 0; j < 0x20; j++) {
            if (s3->num_entries) {
                gDPSetPrimColor(dl++, 0, 0, s3->hue.as_array[0], s3->hue.as_array[1], s3->hue.as_array[2], 0xFF);
            }
            for (k = 0; k < s3->num_entries; k++) {
                func_global_asm_8070E8F0(&dl, s3->entries[k].draw_sprite);
                func_global_asm_8070F2C8(0x400, 0x400, s3->entries[k].horizontal_flip, 0);
                func_global_asm_8070F2FC(&dl, (s3->entries[k].x + 0x20) << 2, (s3->entries[k].y + 0x18) << 2);
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

void func_jetpac_80025BB8(JetpacPlayerStruct *arg0, s32 new_is_flying) {
    if ((new_is_flying == 0) && (arg0->is_flying != 0)) {
        arg0->spatial_state.posX = (s32)arg0->spatial_state.posX & 0xFFFE;
    } else if ((new_is_flying != 0) && (arg0->is_flying == 0)) {
        func_jetpac_80027010(arg0);
    }
    arg0->spatial_state.unk1C.left = 0;
    arg0->spatial_state.unk1C.right = 0x10;
    arg0->is_flying = new_is_flying;
}

JetpacStruct *jetpac_get_free_laser(JetpacPlayerStruct *arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (arg0->lasers[i].unk0.spatial_state.entity_state == JETPAC_ENTITY_STATE_DEAD) {
            return &arg0->lasers[i];
        }
    }
    return 0;
}

void func_jetpac_80025CA0(JetpacSpatialState *arg0) {
    arg0->entity_state = JETPAC_ENTITY_STATE_DYING;
    arg0->unk1C.counter = 0;
}

void func_jetpac_80025CB0(JetpacStructSub0* arg0) {
    s32 new_var;
    f32 var_f12;
    f32 temp_f14;
    f32 var_f0;
    f32 temp_f2;
    JetpacSpatialState* spatial_state = &arg0->spatial_state;
    if ((spatial_state->entity_state == JETPAC_ENTITY_STATE_ACTIVE) && ((u32) arg0->counter_limit < (u32) spatial_state->unk1C.counter)) {
        func_jetpac_80025CA0(spatial_state);
    }
    if ((spatial_state->entity_state == JETPAC_ENTITY_STATE_DYING) && (spatial_state->unk1C.right == spatial_state->unk1C.left)) {
        spatial_state->entity_state = JETPAC_ENTITY_STATE_DEAD;
        spatial_state->unk1C.counter = 0;
    }
    if (spatial_state->entity_state != JETPAC_ENTITY_STATE_DEAD) {
        if (spatial_state->entity_state == JETPAC_ENTITY_STATE_ACTIVE) {
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
        else if (spatial_state->entity_state == JETPAC_ENTITY_STATE_DYING) {
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
    if (arg0->unk0.spatial_state.entity_state >= JETPAC_ENTITY_STATE_ALLOCATED) {
        var_s4 = -8;
        temp_s7 = arg0->unk0.spatial_state.posY;
        temp_t7 = (arg0->unk0.spatial_state.unk1C.right - arg0->unk0.spatial_state.unk1C.left) / 8;
        if (arg0->unk0.spatial_state.entity_state == JETPAC_ENTITY_STATE_DYING) {
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

void func_jetpac_800260DC(JetpacPlayerStruct *arg0) {
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
        temp_v0->unk0.spatial_state.entity_state = JETPAC_ENTITY_STATE_ACTIVE;
        temp_v0->unk0.spatial_state.unk1C.counter = 0;
        temp_v0->unk0.counter_limit = (s32)(func_jetpac_80027210() * 8.0f) + 0xD;
        temp_v0->unk48.unk0 = func_jetpac_80025CB0;
        temp_v0->unk48.unk4 = 0;
        func_jetpac_80024E70(6);
    }
}

void func_jetpac_80026318(JetpacPlayerStruct* arg0) {
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

void func_jetpac_80026A3C(JetpacPlayerStruct *arg0) {
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

// Close, need to prevent first if-statement from using a0
// https://decomp.me/scratch/n0mR6
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_15D4/func_jetpac_80026AB0.s")

/*
void func_jetpac_80026AB0() {
    f32 posX;
    f32 posY;
    JetpacPlayerStruct* player = &D_jetpac_8002F050;
    JetpacSpatialState* ss = &player->spatial_state;
    s32 frame_index_by_position;
    s32 sp20 = TRUE;
    if (ss->entity_state >= JETPAC_ENTITY_STATE_ALLOCATED) // If this stops using a0, everything else matches
    {
        if ((ss->entity_state == JETPAC_ENTITY_STATE_DYING) && (player->explosion_sprite.frame_counter >= 8)) {
            sp20 = FALSE;
        }
        
        frame_index_by_position = func_jetpac_80025B70(ss);
        posX = ss->posX;
        posY = ss->posY;
        if (sp20) {
            if (player->is_flying == 0) {
                posX = (s16)posX & 0xFFFE;
                func_jetpac_80025700(&D_jetpac_8002C3A8[frame_index_by_position], posX, posY, &ss->color, ss->is_facing_left);
            } else {
                func_jetpac_80025700(&D_jetpac_8002C330, posX, posY, &ss->color, ss->is_facing_left);
                if (ss->is_facing_left == 0) {
                    if (frame_index_by_position == 4) {
                        posX -= 1.0f;
                    }
                    posX -= 3.0f;
                } else {
                    if (frame_index_by_position == 4) {
                        posX += 1.0f;
                    }
                    posX += 10.0f;
                }
                func_jetpac_80025700(&D_jetpac_8002C348[frame_index_by_position], posX, (posY + 18.0f), &ss->color, ss->is_facing_left);
            }
        }
        if (player->explosion_sprite.frame_counter < 0xE) {
            func_jetpac_80025A60(&player->explosion_sprite);
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

void func_jetpac_80027010(JetpacPlayerStruct *arg0) {
    if (arg0->explosion_sprite.frame_counter >= 0xE) {
        arg0->explosion_sprite.frame_counter = 0;
        arg0->explosion_sprite.posX = (s32)arg0->spatial_state.posX & 0xFFF8;
        arg0->explosion_sprite.posY = arg0->spatial_state.posY + 7.0f;
    }
}
