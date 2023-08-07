#ifndef RAREZIP_H
#define RAREZIP_H
#include <ultra64.h>

extern u8 *D_dk64_boot_80013AC0; // extern u8 *inbuf;
extern u8 *D_dk64_boot_80013AC4; //slide
extern u32 D_dk64_boot_80013AEC; // extern u32 inptr;
extern u32 D_dk64_boot_80013AF0; // wp
extern struct huft *D_dk64_boot_80013AB0; //unk
extern u32 D_dk64_boot_80013AB4; // extern u32 bb;
extern u32 D_dk64_boot_80013AB8; // extern u32 bk; 
extern s32 D_dk64_boot_80013ABC; //hufts

extern u8 D_8000EDE0[]; // border
extern u16 D_8000EDF4[]; // cplens
extern u8 D_8000EE34[]; // cplext
extern u16 D_8000EE54[]; // cpdist
extern u8 D_8000EE90[]; // cpdext
extern s32 D_8000EED4; // lbits
extern s32 D_8000EED8; // dbits
extern u16 mask_bits[]; // mask_bits

#ifndef WSIZE
#  define WSIZE 0x8000     /* window size--must be a power of two, and */
#endif                     /*  at least 32K for zip's deflate method */

//#define get_byte()  (inptr < insize ? inbuf[inptr++] : fill_inbuf(0))
// #define get_byte()  (inbuf[inptr++])
#define get_byte()  (D_dk64_boot_80013AC0[D_dk64_boot_80013AEC++])

#ifdef CRYPT
  uch cc;
#  define NEXTBYTE() \
     (decrypt ? (cc = get_byte(), zdecode(cc), cc) : get_byte())
#else
#  define NEXTBYTE()  (u8)get_byte()
#endif
#define NEEDBITS(n) {while(k<(n)){b|=((u32)NEXTBYTE())<<k;k+=8;}}
#define DUMPBITS(n) {b>>=(n);k-=(n);}

struct huft {
  u8 e;                /* number of extra bits or operation */
  u8 b;                /* number of bits in this code or subcode */
  union {
    u16 n;              /* literal, length base, or distance base */
    struct huft *t;     /* pointer to next level of table */
  } v;
};

/* If BMAX needs to be larger than 16, then h and x[] should be ulg. */
#define BMAX 16         /* maximum bit length of any code (16 for explode) */
#define N_MAX 288       /* maximum number of codes in any set */

#endif
