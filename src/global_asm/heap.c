#include "common.h"

typedef struct {
    void *unk0; // Used
    s8 unk4; // Used
    s8 unk5;
    s8 unk6;
    s8 unk7;
} Struct807F0A58;

extern s32 D_global_asm_80746A30;
extern u8 D_global_asm_80746A37;
extern Struct807F0A58 D_global_asm_807F0A58[];
extern s32 D_global_asm_807F5A58;
extern s32 D_global_asm_807F5A5C;
extern HeapHeader *D_global_asm_807F5A64;
extern s32 D_global_asm_807F5A68;
extern s32 D_global_asm_807F5A70[]; // TODO: Datatype is sus
extern HeapHeader *D_global_asm_807F0990;
extern s32 D_global_asm_807F5A68;

void *func_global_asm_806111F8(s32 arg0, u32 arg1);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_80610350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_806109EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_80610A88.s")

// TODO: Datatypes are sus
void func_global_asm_80610B84(s32 arg0, s32 arg1, u32 arg2) {
    s32 temp_v0;
    s32 i;

    for (i = 0; i < D_global_asm_807F5A68; i++) {
        temp_v0 = D_global_asm_807F5A70[i] - arg0;
        if ((temp_v0 >= 0) && (temp_v0 < arg2)) {
            D_global_asm_807F5A70[i] = temp_v0 + arg1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_80610BD8.s")

typedef struct HeapArenaMeta {
    void *  index;
    void *  start;
    void *  tail;
    s32     bin_size;
    s16     chunk_size;
    u8      pad12[2];
} HeapArenaMeta;

typedef struct Struct80610BD8_arg1 {
    s32 unk0;
    s32 unk4;
    union {
        struct {
            u8 unk8;
            u8 unk9;
            u8 unkA;
            u8 unkB;
        };
        s32 unk8_s32;
    };
    s32 unkC;
} Struct80610BD8_arg1;

extern HeapArenaMeta D_807F0988[];
extern s32 D_807F0A28;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_80610C74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_80610DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_80610E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/malloc.s")

u8 func_global_asm_80611154(void) {
    return D_global_asm_80746A37;
}

void func_global_asm_80611160(void) {
    D_global_asm_80746A30 = 0;
}

s32 func_global_asm_8061116C(void) {
    return func_global_asm_8065EA44();
}

s32 func_global_asm_8061118C(void) {
    s32 size;
    HeapHeader *var_v0;

    var_v0 = D_global_asm_807F0990;
    size = 0;
    while (var_v0 != NULL) {
        size += var_v0->size + sizeof(HeapHeader);
        // TODO: WTF, union in the HeapHeader struct maybe?
        var_v0 = *((u32*)&var_v0->unk8);
    }
    return size;
}

s32 func_global_asm_806111BC(s32 arg0, s32 arg1) {
    s32 temp_v0 = func_global_asm_806111F8(arg0, (arg1 + 0xF) & ~0xF);
    if (temp_v0) {
        temp_v0 += 0x10;
        return temp_v0;
    }
    return 0;
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_806111F8.s")

typedef struct Struct807F0988_unk8 Struct807F0988_unk8;

struct Struct807F0988_unk8 {
    s32 unk0;
    s32 unk4;
    Struct807F0988_unk8 *unk8;
    Struct807F0988_unk8 *unkC;
};

typedef struct {
    s32 unk0;
    s32 unk4;
    Struct807F0988_unk8 *unk8;
    s32 unkC;
    s32 unk10;
} Struct807F0988;

extern Struct807F0988 D_global_asm_807F0988[];

/*
void *func_global_asm_806111F8(s32 arg0, u32 arg1) {
    u32 temp_a0;
    u32 var_v0;
    Struct807F0988_unk8 *temp_a0_2;
    volatile Struct807F0988_unk8 *temp_v0;
    Struct807F0988_unk8 *temp_v0_2;
    Struct807F0988_unk8 *var_a0;
    Struct807F0988_unk8 *var_v1;

    if (arg1 == 0) {
        return &D_global_asm_807F5A64[-1];
    }
    var_v1 = NULL;
    var_v0 = -1;
    var_a0 = D_global_asm_807F0988[arg0].unk8;
    if (var_a0 == NULL) {
        return NULL;
    }
    do {
        if (var_a0->unk4 >= arg1) {
            if (var_a0->unk4 < var_v0) {
                var_v1 = var_a0;
                var_v0 = var_a0->unk4;
            }
        }
        var_a0 = var_a0->unk8;
    } while (var_a0 != NULL);
    if (var_v1 != NULL) {
        temp_a0 = var_v1->unk4 - arg1;
        temp_v0 = var_v1 + temp_a0;
        if (temp_a0 >= 0x10) {
            temp_v0->unk4 = 0;
            temp_v0->unk0 = NULL;
            temp_v0->unkC = 0;
            temp_v0->unk8 = 0;
            temp_v0->unk4 = arg1;
            temp_v0->unk0 = var_v1;
            var_v1->unk4 = temp_a0 - 0x10;
            temp_v0[arg1 + 1].unk0 = temp_v0;
            return temp_v0;
        }
        temp_v0_2 = var_v1->unkC;
        temp_a0_2 = var_v1->unk8;
        var_v1->unk8 = NULL;
        var_v1->unkC = NULL;
        if (temp_v0_2 != NULL) {
            temp_v0_2->unk8 = temp_a0_2;
        } else {
            D_global_asm_807F0988[arg0].unk8 = temp_a0_2;
        }
        if (temp_a0_2 != NULL) {
            temp_a0_2->unkC = temp_v0_2;
        }
        return var_v1;
    }
    return NULL;
}
*/

void free(void *arg0) {
    if (((HeapHeader*)arg0 != D_global_asm_807F5A64)) {
        arg0 = (HeapHeader*)arg0 - 1;
        if (((HeapHeader*)arg0)->unkB == 0) {
            func_global_asm_80611408(arg0);
        }
    }
}

void func_global_asm_8061134C(void *arg0) {
    if (((HeapHeader*)arg0 != D_global_asm_807F5A64)) {
        arg0 = (HeapHeader*)arg0 - 1;
        if (((HeapHeader*)arg0)->unkB == 0) {
            func_global_asm_8061138C(arg0);
        }
    }
}

void func_global_asm_8061138C(void *arg0) {
    while (D_global_asm_807F5A58 >= 0xA00) {
        func_global_asm_80611730();
    }
    D_global_asm_807F0A58[D_global_asm_807F5A58].unk0 = arg0;
    D_global_asm_807F0A58[D_global_asm_807F5A58].unk4 = D_global_asm_807F5A5C;
    D_global_asm_807F5A58++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_80611408.s")

// Looks fiddly... hmm
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_80611534.s")

void func_global_asm_80611594(HeapHeader *arg0) {
    arg0[-1].unkB = 0;
}

void func_global_asm_8061159C(HeapHeader *arg0) {
    arg0[-1].unkB = 1;
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_806115A8.s")

/*
// TODO: Might only have 1 param
void func_global_asm_806115A8(HeapHeader **arg0, HeapHeader *arg1) {
    arg1 = &(*arg0)[-1];
    arg1->unkB = 2;
    D_global_asm_807F5A70[D_global_asm_807F5A68++] = arg1;
    if (D_global_asm_807F5A68 == 0x20) {
        raiseException(0xD, 0, 0, 0);
    }
}
*/

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_80611614.s")

extern s32 D_global_asm_807F5A68;

/*
void func_global_asm_80611614(HeapHeader **arg0) {
    s32 temp_t7;
    s32 i;
    HeapHeader *temp;

    temp = *arg0 - 1;
    temp->unkB = 0;
    temp_t7 = D_global_asm_807F5A68 - 1;
    for (i = 0; i < D_global_asm_807F5A68; i++) {
        if (temp == D_global_asm_807F5A70[i]) {
            break;
        }
    }
    D_global_asm_807F5A70[i] = D_global_asm_807F5A70[temp_t7];
    D_global_asm_807F5A68 = temp_t7;
    D_global_asm_807F5A70[temp_t7] = 0;
}
*/

s32 func_global_asm_80611688(HeapHeader *arg0) {
    return arg0[-1].size;
}

// Appears to be an 8 byte aligned memset implementation
void func_global_asm_80611690(void *arg0) {
    u64 *var_v0;
    u16 var_v1;

    var_v0 = arg0;
    var_v1 = ((HeapHeader*)arg0)[-1].size / 8U;
    while (var_v1--) {
        *var_v0++ = 0;
    }
}

// Appears to be a 4 byte aligned memset implementation
void func_global_asm_806116E0(HeapHeader *arg0, s32 arg1) {
    s32 *var_v0;
    u16 var_v1;

    var_v0 = arg0;
    var_v1 = arg0[-1].size / 4U;
    while (var_v1--) {
        *var_v0++ = arg1;
    }
}

void func_global_asm_80611724(s32 arg0, s32 arg1) {

}

// TODO: Blursed, maybe anti piracy?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/heap/func_global_asm_80611730.s")

void func_global_asm_80611844(void) {

}
