#include <ultra64.h>
#include "functions.h"

typedef struct global_asm_struct_2 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} GlobalASMStruct2;

void func_global_asm_80732420(ALHeap *hp, u8 *base, s32 len) {
    // ALHeapInit
    hp->base = base;
    hp->len  = len;
    hp->cur  = hp->base;
    hp->count = 0;
}

void *func_global_asm_80732444(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size) {
    // alHeapDBAlloc

    s32 bytes;
    u8 *ptr = 0;

    bytes = (num*size + AL_CACHE_ALIGN) & ~AL_CACHE_ALIGN;
    
    #ifdef _DEBUG
        hp->count++;    
        bytes += sizeof(HeapInfo);
    #endif
        
    if ((hp->cur + bytes) <= (hp->base + hp->len)) {

        ptr = hp->cur;
        hp->cur += bytes;

        #ifdef _DEBUG    
                ((HeapInfo *)ptr)->magic = AL_HEAP_MAGIC;
                ((HeapInfo *)ptr)->size  = bytes;
                ((HeapInfo *)ptr)->count = hp->count;
                if (file) {
                    ((HeapInfo *)ptr)->file  = file;
                    ((HeapInfo *)ptr)->line  = line;
                } else {
                    ((HeapInfo *)ptr)->file  = (u8 *) "unknown";
                    ((HeapInfo *)ptr)->line  = 0;
                }
                
                ptr += sizeof(HeapInfo);        
        #endif

    } else {
        #ifdef _DEBUG
                __osError(ERR_ALHEAPNOFREE, 1, size);
        #endif        
    }

    return ptr;
}
