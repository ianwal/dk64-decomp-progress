#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/os/initialize/osInitialize.s")

/*
typedef struct
{
   unsigned int inst1; // 0x0
   unsigned int inst2; // 0x4
   unsigned int inst3; // 0x8
   unsigned int inst4; // 0xC
} __osExceptionVector;
extern __osExceptionVector __osExceptionPreamble;

extern OSTime osClockRate;// = OS_CLOCK_RATE;
extern s32 osViClock;// = VI_NTSC_CLOCK;
extern u32 __osShutdown;// = 0;
extern u32 __OSGlobalIntMask;// = OS_IM_ALL;
extern u32 __osFinalrom;

void osInitialize()
{
   u32 pifdata;
   u32 clock = 0;
   __osFinalrom = TRUE;
   __osSetSR(__osGetSR() | SR_CU1);    //enable fpu
   __osSetFpcCsr(FPCSR_FS | FPCSR_EV); //flush denorm to zero, enable invalid operation

   while (__osSiRawReadIo(PIF_RAM_END - 3, &pifdata)) //last byte of joychannel ram
   {
      ;
   }
   while (__osSiRawWriteIo(PIF_RAM_END - 3, pifdata | 8))
   {
      ; //todo: magic contant
   }
   *(__osExceptionVector *)UT_VEC = __osExceptionPreamble;
   *(__osExceptionVector *)XUT_VEC = __osExceptionPreamble;
   *(__osExceptionVector *)ECC_VEC = __osExceptionPreamble;
   *(__osExceptionVector *)E_VEC = __osExceptionPreamble;
   osWritebackDCache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
   osInvalICache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
   osMapTLBRdb();
   //osUnmapTLBAll(); // TODO: Which function is actually called here
   //osUnmapTLBAll(); // TODO: Which function is actually called here
   osPiRawReadIo(4, &clock); //TODO: remove magic constant;
   clock &= ~0xf;            //clear lower 4 bits
   if (clock != 0)
   {
      osClockRate = clock;
   }
   //osClockRate = osClockRate * 3 / 4; // TODO: How do we do division/multiplication on a u64?
   if (osResetType == 0) // cold reset
   {
      bzero(osAppNMIBuffer, OS_APP_NMI_BUFSIZE);
   }
   if (osTvType == OS_TV_PAL) {
      osViClock = VI_PAL_CLOCK;
   } else if (osTvType == OS_TV_MPAL) {
      osViClock = VI_MPAL_CLOCK;
   } else {
      osViClock = VI_NTSC_CLOCK;
   }
}
*/
