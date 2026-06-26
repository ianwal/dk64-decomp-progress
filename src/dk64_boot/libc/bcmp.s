#include "PR/R4300.h"
#include "sys/asm.h"
#include "sys/regdef.h"

.set noreorder

.text
#ifdef __sgi
WEAK(bcmp, _bcmp)
#else
#define _bcmp bcmp
#endif
LEAF(_bcmp)
    
    blt a2, 16, bytecmp
     xor v0, a0, a1

    andi v0, v0, 0x3
    bnez v0, unalgncmp
     negu t8, a0

    andi t8, t8, 0x3
    beqz t8, wordcmp
     subu a2, a2, t8
    
    move v0, v1
    lwl v0, 0(a0)
    lwl v1, 0(a1)
    addu a0, a0, t8
    addu a1, a1, t8
    bne v0, v1, cmpne

wordcmp:
     and a3, a2, ~3
    beqz a3, bytecmp
     subu a2, a2, a3

    addu a3, a3, a0
    lw v0, 0(a0)
1:
    lw v1, 0(a1)
    addiu a0, a0, 4
    addiu a1, a1, 4
    bne v0, v1, cmpne
     nop
    bnel a0, a3, 1b
     lw v0, 0(a0)
    b bytecmp
     nop
unalgncmp:
    negu a3, a1
    andi a3, a3, 0x3
    beqz a3, partaligncmp
     subu a2, a2, a3

    addu a3, a3, a0
    lbu v0, 0(a0)
1:
    lbu v1, 0(a1)
    addiu a0, a0, 1
    addiu a1, a1, 1
    bne v0, v1, cmpne
     nop
    bnel a0, a3, 1b
     lbu v0, 0(a0) 

partaligncmp:
    and a3, a2, ~3
    beqz a3, bytecmp
     subu a2, a2, a3
    addu a3, a3, a0
    
    lwl v0, 0(a0)
1:
    lw v1, 0(a1)
    lwr v0, 3(a0)
    addiu a0, a0, 4
    addiu a1, a1, 4
    bne v0, v1, cmpne
     nop
    bnel a0, a3, 1b 
     lwl v0, 0(a0)
    
bytecmp:
    blez a2, cmpdone
     addu a3, a2, a0

    lbu v0, 0(a0)
1:
    lbu v1, 0(a1)
    addiu a0, a0, 1
    addiu a1, a1, 1
    bne v0, v1, cmpne
     nop
    bnel a0, a3, 1b 
     lbu v0, 0(a0)

cmpdone:
    jr ra
     move v0, zero
cmpne:
    jr ra
     li v0, 1

.end _bcmp
