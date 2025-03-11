#include "PR/R4300.h"
#include "sys/asm.h"
#include "sys/regdef.h"

.set noreorder

.text
#ifdef __sgi
WEAK(bzero, _bzero)
WEAK(blkclr, _blkclr)
#else
#define _bzero bzero
#define _blkclr blkclr
#endif
LEAF(_bzero)
XLEAF(_blkclr)
    blt a1, 12, bytezero
    negu v1, a0

    andi v1, v1, 0x3
    beqz v1, blkzero
     subu a1, a1, v1

    swl zero, 0(a0)
    addu a0, a0, v1
blkzero:
    and a3, a1, ~31
    beqz a3, wordzero
     subu a1, a1, a3

    addu a3, a3, a0
1:
    addiu a0, a0, 32
    sw zero, -32(a0)
    sw zero, -28(a0)
    sw zero, -24(a0)
    sw zero, -20(a0)
    sw zero, -16(a0)
    sw zero, -12(a0)
    sw zero, -8(a0)
    bne a0, a3, 1b
     sw zero, -4(a0)

wordzero:
     and a3, a1, ~3
    
    beqz a3, bytezero
     subu a1, a1, a3

    addu a3, a3, a0
1:
    addiu a0, a0, 4
    bne a0, a3, 1b
     sw zero, -4(a0)

bytezero:
    blez a1, zerodone
    nop
    addu a1, a1, a0
1:
    addiu a0, a0, 1
    bne a0, a1, 1b
     sb zero, -1(a0)
zerodone:
    jr ra
    nop

.end _bzero
