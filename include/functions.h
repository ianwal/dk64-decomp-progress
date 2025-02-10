#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "enums.h"
#include "structs.h"
#include "variables.h"

/* your function prototype definitions go here */

// Orphaned functions with signatures
// TODO: Assign these to a .c file
f32 func_global_asm_80612794(s16 arg0);
u8 func_global_asm_806E770C(void);
void func_global_asm_8073243C(void);
void func_global_asm_80732924(void);
void func_global_asm_80735A44(void);
void func_global_asm_80737600(void);
void func_global_asm_80737630(void);
void func_global_asm_80737B48(void);
void func_global_asm_80737B50(void);
void func_global_asm_80737E9C(void);
void func_global_asm_80737F38(void);
void func_global_asm_807383EC(void);
void func_global_asm_807383F4(void);
void func_global_asm_80738BA8(void);
void func_global_asm_80738BB0(void);
void func_global_asm_8073AD48(void);
void func_global_asm_8073E8B4(void);

// dk64_boot/dk64_boot_1050.c
void func_dk64_boot_80000450(s32 devAddr, s32 arg1, void *dramAddr);
void func_dk64_boot_800004B4(s32 *arg0, s32 *arg1);
void func_dk64_boot_800004F4(s32 arg0);
// TODO: func_dk64_boot_800005A8 has no documented signature
void func_dk64_boot_80000980(void);
void func_dk64_boot_800009D0(void);

// dk64_boot/dk64_boot_1630.c
// TODO: func_dk64_boot_80000A30 has no documented signature
// TODO: func_dk64_boot_80000AA0 has no documented signature
void func_dk64_boot_80000CD4(void);
void func_dk64_boot_80000D8C(void *arg0);
// TODO: func_dk64_boot_80000E48 has no documented signature
// TODO: func_dk64_boot_80000EEC has no documented signature
void func_dk64_boot_8000102C(s32 offset, s32 size, void *dramAddr);

// dk64_boot/inflate.c
// TODO: func_dk64_boot_800010C0 has no documented signature but has been matched
// TODO: func_dk64_boot_80001700 has no documented signature but has been matched
int func_dk64_boot_80001AF4(void); // inflate_stored();
int func_dk64_boot_80001C48(void); // inflate_fixed();
int func_dk64_boot_80001DB0(void); // inflate_dynamic();
int func_dk64_boot_800022D4(int *e); // inflate_block();
int func_dk64_boot_800023F4(void); //int inflate()

// dk64_boot/dk64_boot_30E0.c
// TODO: func_dk64_boot_800024E0 has no documented signature but has been matched
// TODO: func_dk64_boot_800025A4 has no documented signature
u32 func_dk64_boot_80002724(u32 arg0, s32 arg1);
void func_dk64_boot_80002750(void);

// dk64_boot/dk64_boot_3390.c
// TODO: func_dk64_boot_80002790 has no documented signature
// TODO: func_dk64_boot_80002828 has no documented signature
// TODO: func_dk64_boot_800028E0 has no documented signature
// TODO: func_dk64_boot_800029EC has no documented signature
u8 *strcpy(u8 *dest, u8 const *src);
// TODO: func_dk64_boot_80002A64 has no documented signature
u8 *func_dk64_boot_80002ABC(u8 *str, u8 *arg1);
// TODO: func_dk64_boot_80002B0C has no documented signature
// TODO: func_dk64_boot_80002BB8 has no documented signature
s32 func_dk64_boot_80002C74(u8 *str, u8 *arg1);
// TODO: func_dk64_boot_80002CE8 has no documented signature
u8 *func_dk64_boot_80002D60(u8 *str, u8 *ptr);
// TODO: func_dk64_boot_80002DE4 has no documented signature
void *memset(void *dest, s32 val, u32 len);
u8 *strchr(u8 const *str, s32 c);
u32 strlen(u8 const *str);
// TODO: func_dk64_boot_80002F54 has no documented signature but has been matched

// dk64_boot/dk64_boot_3C00.c
void *memcpy(void *dest, void *src, u32 n);

// dk64_boot/dk64_boot_3D20.c
// TODO: func_dk64_boot_80003120 has no documented signature
// TODO: func_dk64_boot_8000320C has no documented signature

// dk64_boot/io/vimgr.c
// TODO: viMgrMain has no documented signature

// dk64_boot/io/aisetfreq.c
// TODO: osWriteBackDCacheAll has no documented signature but has been matched

// dk64_boot/dk64_boot_61D0.c
void func_dk64_boot_800055D0(void);

// dk64_boot/ll.c
u64 __ull_rshift(u64 arg0, u64 arg1);
u64 __ull_rem(u64 arg0, u64 arg1);
u64 __ull_div(u64, u64);
s64 __ll_lshift(u64 arg0, u64 arg1);
s64 __ll_rem(u64 arg0, u64 arg1);
s64 __ll_div(s64 arg0, s64 arg1);
u64 __ll_mul(u64, u64);
void __ull_divremi(u64 *div, u64 *rem, u64 arg2, u16 arg3);
s64 __ll_mod(s64 arg0, s64 arg1);
s64 __ll_rshift(s64 arg0, s64 arg1);
s32 func_dk64_boot_80005A70(void);

// dk64_boot/io/contreaddata.c
s32 func_dk64_boot_800073D0(OSMesgQueue *arg0);
void func_dk64_boot_80007454(OSContPad *data); //void osContGetReadData(OSContPad *data)
void func_dk64_boot_800074E0(void); //static void __osPackReadData(void)

// dk64_boot/libc/llcvt.c
s64 __d_to_ll(f64 d);
s64 __f_to_ll(f32 f);
u64 __d_to_ull(f64 d);
u64 __f_to_ull(f32 f);
f64 __ll_to_d(s64 l);
f32 __ll_to_f(s64 l);
f64 __ull_to_d(u64 l);
f32 __ull_to_f(u64 l);

// dk64_boot/io/motor.c
// TODO: osMotorStartStop has no documented signature
// TODO: _MakeMotorData has no documented signature

// dk64_boot/os/thread.c
// TODO: send_mesg has no documented signature but has been matched

// dk64_boot/gu/cosf.c
// TODO: fcos has no documented signature
// TODO: __cosf has no documented signature but has been matched

// dk64_boot/gu/sinf.c
// TODO: __sinf has no documented signature but has been matched
// TODO: fsin has no documented signature

// dk64_boot/io/contpfs.c
// TODO: func_dk64_boot_8000D7E0 has no documented signature
// TODO: func_dk64_boot_8000D8B4 has no documented signature

// dk64_boot/dk64_boot_E790.c
// TODO: func_dk64_boot_8000DB90 has no documented signature

// global_asm/code_0.c
// TODO: func_global_asm_805FB300 has no documented signature
// TODO: func_global_asm_805FB5C4 has no documented signature

// global_asm/code_450.c
void func_global_asm_805FB750(s32 arg0, s32 arg1, void* arg2);
void func_global_asm_805FB7E4(void);
// TODO: func_global_asm_805FB944 has no documented signature
void func_global_asm_805FBC5C(void);
void func_global_asm_805FBE04(void);
// TODO: func_global_asm_805FBFF4 has no documented signature
void func_global_asm_805FC2B0(void);
// TODO: func_global_asm_805FC668 has no documented signature
u32 func_global_asm_805FC98C(void);
u8 func_global_asm_805FCA64(void); // getCutsceneBarState()
// TODO: func_global_asm_805FCA94 has no documented signature
Gfx *func_global_asm_805FCFD8(Gfx *dl);
Gfx *func_global_asm_805FD030(Gfx *dl);
// TODO: func_global_asm_805FD088 has no documented signature but has been matched
Gfx *func_global_asm_805FE398(Gfx *dl);
Gfx *func_global_asm_805FE4D4(Gfx *dl);
void func_global_asm_805FE544(u8 arg0);
Gfx *func_global_asm_805FE634(Gfx *dl, u8 arg1);
void func_global_asm_805FE71C(Gfx *dl, u8 arg1, s32 *arg2, u8 arg3);
void func_global_asm_805FE7B4(Gfx *dl, Gfx *arg1, s32 *arg2, u8 arg3);
void func_global_asm_805FE7FC(void);
void func_global_asm_805FEE84(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_global_asm_805FEEB8(s32 *arg0, s32 arg1);

// global_asm/code_3C10.c
s32 func_global_asm_805FEF10(s32 *arg0);
s32 func_global_asm_805FEF74(Maps map);
u8 func_global_asm_805FF000(u8 map);
s32 func_global_asm_805FF018(s32 actorBehaviour, s32 kongIndex);
u8 getLevelIndex(u8 map, u8 arg1);
u8 func_global_asm_805FF0C8(void);
void func_global_asm_805FF118(void);
void func_global_asm_805FF158(u8 arg0);
void func_global_asm_805FF168(void);
void func_global_asm_805FF188(s16 map, u8 exit);
void func_global_asm_805FF1B0(s32 player_index);
void func_global_asm_805FF2F4(void);
void func_global_asm_805FF378(Maps nextMap, s32 nextExit);
void func_global_asm_805FF4D8(Maps map, s32 exit);
void func_global_asm_805FF544(void);
void func_global_asm_805FF5A0(Maps map);
void func_global_asm_805FF628(Maps map, s32 exit);
void func_global_asm_805FF660(u8 arg0);
void func_global_asm_805FF670(void);
s32 func_global_asm_805FF800(Maps *arg0, s32 *arg1);
void func_global_asm_805FF898(void);
void func_global_asm_805FF8F8(void);
s32 func_global_asm_805FF938(s16 arg0);
// TODO: func_global_asm_805FF9AC has no documented signature
s32 func_global_asm_805FFE50(s32 arg0, s16 arg1, s16 arg2);
void func_global_asm_805FFEF8(Maps map);
void func_global_asm_805FFFC8(void);
void func_global_asm_80600044(s32 arg0);
s32 func_global_asm_80600080(Maps map);
// TODO: func_global_asm_80600174 has no documented signature
s32 func_global_asm_80600340(s32 arg0, u8 arg1, s32 *arg2);
void func_global_asm_806003EC(s16 arg0);
s32 func_global_asm_8060042C(s16 arg0);
u8 func_global_asm_80600454(s16 arg0, u8 *arg1);
s32 func_global_asm_80600530(void);
void func_global_asm_80600590(Maps map);
// TODO: func_global_asm_80600674 has no documented signature

// global_asm/code_5650.c
void func_global_asm_80600950(void);
void* func_global_asm_8060095C(s32 arg0, s32 *arg1, s32 *arg2);
void func_global_asm_8060098C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_global_asm_80600B10(void);
void func_global_asm_80600BBC(void *arg0);
void func_global_asm_80600C68(void);

// global_asm/done/code_5A50.c
void func_global_asm_80600D50(void);
void func_global_asm_806010A0(void);
void func_global_asm_80601120(u8 arg0);
void func_global_asm_8060116C(u8 arg0);
void func_global_asm_806011A0(u8 arg0, s32 arg1);
void func_global_asm_806011D4(s32 arg0, s32 arg1, s32 arg2);
void func_global_asm_806011E4(u8 arg0, s32 arg1, u8 arg2);
void func_global_asm_80601224(u8 arg0, s32 arg1);
void func_global_asm_80601258(u8 arg0, s32 arg1);
void func_global_asm_8060128C(u8 arg0, s32 arg1, u8 arg2);
void func_global_asm_806012D4(u8 arg0, u8 arg1, u8 arg2);
void func_global_asm_8060131C(u8 arg0, s32 arg1, u8 arg2);
void func_global_asm_806013A0(u8 arg0, u8 arg1, u8 arg2);
void func_global_asm_806013E8(u8 arg0, s32 arg1, u8 arg2);
void func_global_asm_80601484(u8 arg0, s32 arg1, s32 arg2);
void func_global_asm_8060151C(u8 arg0, s32 arg1, s32 arg2);
void func_global_asm_806015E0(u8 arg0, s32 arg1, s32 arg2);
void func_global_asm_80601678(u8 arg0, u8 arg1, u8 arg2);
void func_global_asm_806016D0(u8 arg0, u8 arg1, u8 arg2);
void func_global_asm_80601728(u8 arg0, u8 arg1, u8 arg2);
void func_global_asm_80601780(u8 arg0, s32 arg1);
void func_global_asm_806017B4(u8 arg0);
void func_global_asm_806017E8(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4);
void func_global_asm_80601848(u8 arg0, f32 arg1, f32 arg2);
void func_global_asm_8060188C(u8 arg0, s32 arg1);
ALMicroTime func_global_asm_806018B4(u8 arg0);
void func_global_asm_806018D4(u8 arg0, u8 arg1, s32 arg2);
void func_global_asm_8060193C(u8 arg0, u8 arg1);
void func_global_asm_806019B8(u8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

// global_asm/code_6710.c
// TODO: func_global_asm_80601A10 has no documented signature
void func_global_asm_80601CC0(void);
void func_global_asm_80601CF0(s32 arg0);
// TODO: func_global_asm_80601D24 has no documented signature
// TODO: func_global_asm_80601EE4 has no documented signature
// TODO: func_global_asm_80602104 has no documented signature
// TODO: func_global_asm_80602144 has no documented signature
void *func_global_asm_806022DC(s32 *arg0);
// TODO: func_global_asm_80602314 has no documented signature
u8 func_global_asm_80602430(s16 arg0);
u8 func_global_asm_8060245C(s16 arg0);
void func_global_asm_80602488(u8 arg0);
void func_global_asm_80602498(void);
void func_global_asm_806025AC(s32 arg0, s32 arg1, s32 arg2);
// TODO: func_global_asm_806025D4 has no documented signature
void playSong(s32 arg0, f32 arg1);
void func_global_asm_80602B60(s32 arg0, u8 arg1);
void func_global_asm_80602C0C(void);
void func_global_asm_80602C6C(s32 arg0, f32 arg1);
void func_global_asm_80602CE0(s32 arg0, s32 arg1, u8 arg2);
f32 func_global_asm_80602D4C(s32 arg0);
void func_global_asm_80602DC4(s32 arg0, f32 arg1);
// TODO: func_global_asm_80602E6C has no documented signature
f32 func_global_asm_80603340(f32 arg0, f32 arg1, f32 arg2, u8 arg3, u8 arg4, f32 arg5);
// TODO: func_global_asm_80603450 has no documented signature
void func_global_asm_806049CC(s32 arg0);
void func_global_asm_80604BE8(u8 arg0, f32 arg1, f32 arg2);
void func_global_asm_80604C80(u8 arg0, u8 arg1);
void func_global_asm_80604CBC(Actor* arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6, s8 arg7);
// TODO: func_global_asm_80604D70 has no documented signature
// TODO: func_global_asm_80605044 has no documented signature
void func_global_asm_80605314(Actor *arg0, u8 arg1);
void func_global_asm_80605380(s16 arg0);
// TODO: func_global_asm_80605510 has no documented signature
// TODO: func_global_asm_806057F8 has no documented signature
void playSoundAtActorPosition(Actor *arg0, s16 arg1, u8 arg2, s16 arg3, u8 arg4);
void playSoundAtProp(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6);
void func_global_asm_8060866C(Actor *arg0, s16 arg1, u8 arg2, f32 arg3, u8 arg4, u8 arg5);
s16 playSoundAtPosition(f32 x, f32 y, f32 z, s16 arg3, u8 arg4, s16 arg5, u8 arg6, u8 arg7, f32 arg8, u8 arg9);
// TODO: func_global_asm_80608DA8 has no documented signature
s16 playSound(s16 arg0, u32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5);
// TODO: func_global_asm_8060956C has no documented signature
// TODO: func_global_asm_80609B80 has no documented signature
// TODO: func_global_asm_8060A1B0 has no documented signature
// TODO: func_global_asm_8060A398 has no documented signature
void func_global_asm_8060A4D0(s32 arg0, f32 arg1);
// TODO: func_global_asm_8060A500 has no documented signature
void func_global_asm_8060A60C(s32 arg0, f32 arg1);
void func_global_asm_8060A634(s32 arg0, f32 arg1);
void func_global_asm_8060A670(s32 arg0, u8 arg1);
// TODO: func_global_asm_8060A6A0 has no documented signature

// global_asm/done/code_F4C0.c
s16 func_global_asm_8060A7C0(s16 arg0, Actor *arg1, u8 arg2);

// global_asm/code_F600.c
u8 func_global_asm_8060A900(void);
// TODO: func_global_asm_8060A9BC has no documented signature
void func_global_asm_8060AA04(void);
// TODO: func_global_asm_8060AA58 has no documented signature
u8 func_global_asm_8060AB38(s32 arg0);
void func_global_asm_8060AB48(OSContPad *arg0);
u8 func_global_asm_8060AC28(void);
// TODO: func_global_asm_8060AC34 has no documented signature
// TODO: func_global_asm_8060AC7C has no documented signature
void func_global_asm_8060B110(OSContPad *arg0);

// global_asm/code_FE40.c
// TODO: func_global_asm_8060B140 has no documented signature

// global_asm/done/dktv.c
void func_global_asm_8060B430(Actor *arg0, DKTVExtraData *arg1);
s16 func_global_asm_8060B49C(Actor *arg0, s32 arg1);
void func_global_asm_8060B4D4(OSContPad *arg0);
void func_global_asm_8060B55C(u16 *arg0);
void func_global_asm_8060B5C0(u8 *file);
void func_global_asm_8060B6CC(void);
void func_global_asm_8060B700(void);
void func_global_asm_8060B750(s32 fileIndex);
u8 func_global_asm_8060B7C4(void);
void func_global_asm_8060B7D0(Maps *mapPointer, s32 *exitPointer);

// global_asm/saveFile.c
void func_global_asm_8060B7F0(void);
void func_global_asm_8060B84C(f32 arg0);
void func_global_asm_8060B8F8(s32 arg0);
s32 func_global_asm_8060B968(u8 *arg0, u16 arg1);
u8 getEEPROMSaveSlot(s32 fileIndex);
void func_global_asm_8060BA14(void);
// TODO: func_global_asm_8060BB18 has no documented signature
// TODO: func_global_asm_8060BBE0 has no documented signature
void func_global_asm_8060BCA0(s32 arg0, u8 arg1, u8 arg2, u16 *arg3, u8 *arg4);
void func_global_asm_8060BEA8(s32 arg0, u8 arg1, u16 *arg2, u8 *arg3);
void func_global_asm_8060BF84(s32 arg0, u8 arg1, u16 *arg2, u8 *arg3);
void func_global_asm_8060C2C4(s32 arg0, s32 arg1, u8 arg2, u16 *arg3, s8 *arg4);
void func_global_asm_8060C340(u16 *arg0, u8 *arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5);
u32 func_global_asm_8060C430(s32 arg0, u32 arg1, s32 arg2);
void func_global_asm_8060C648(s32 arg0, u8 arg1, u8 arg2, u8 fileIndex, u32 arg4);
s32 func_global_asm_8060C6B8(s32 arg0, u8 arg1, u8 arg2, u8 fileIndex);
s32 func_global_asm_8060C724(u8 fileIndex);
// TODO: func_global_asm_8060C758 has no documented signature
void func_global_asm_8060C830(u8 fileIndex, s32 arg1);
void func_global_asm_8060C8AC(u8 arg0);
void func_global_asm_8060CB74(void);
void func_global_asm_8060CB9C(void);
// TODO: func_global_asm_8060CBBC has no documented signature
void func_global_asm_8060D0A8(void);
void func_global_asm_8060D14C(void);
// TODO: func_global_asm_8060D2C8 has no documented signature
void func_global_asm_8060D768(void);
void func_global_asm_8060D788(void);
void func_global_asm_8060D7A8(void);
void func_global_asm_8060DC3C(u8 fileIndex, s32 arg1);
void func_global_asm_8060DEA8(void);
void func_global_asm_8060DEC8(void); // saveTheGame()
void func_global_asm_8060E128(s32 arg0);
void func_global_asm_8060E1A8(void);
u8 *getFlagBlockAddress(u8 flagType); // TODO: Can we use the FlagTypes enum? Needs to be a u8 to match
u8 func_global_asm_8060E3B0(u16 arg0, u8 arg1);
void func_global_asm_8060E430(u16 arg0, u8 arg1, u8 arg2);

// global_asm/code_131B0.c
void func_global_asm_8060E4B0(Struct807F0470 *arg0);
void func_global_asm_8060E4D0(u8 arg0);
void func_global_asm_8060E574(u8 arg0);
void func_global_asm_8060E664(u8 arg0);
void func_global_asm_8060E6E8(s32 arg0);
s32 func_global_asm_8060E79C(u8 arg0);
void func_global_asm_8060E7EC(u8 arg0, u8 arg1, s32 arg2);
void func_global_asm_8060E8CC(Struct807F0470 *arg0);
void func_global_asm_8060E8EC(u8 arg0);
void func_global_asm_8060E930(void);
void func_global_asm_8060E958(void);
int func_global_asm_8060E980(void);
void func_global_asm_8060EA28(void);
void func_global_asm_8060EC54(s32 arg0);
// TODO: func_global_asm_8060EC80 has no documented signature
void func_global_asm_8060ED6C(Struct131B0_2 *arg0, Struct131B0_1 *arg1, s32 arg2, s32 arg3, s32 arg4);
void func_global_asm_8060EDD0(Struct131B0_2 *arg0, Struct131B0_1 *arg1);
s32 func_global_asm_8060EE58(s32 arg0);
// TODO: func_global_asm_8060EE60 has no documented signature
void func_global_asm_8060F1D0(Struct131B0_2 *arg0, Struct131B0_1 *arg1);
// TODO: func_global_asm_8060F208 has no documented signature
// TODO: func_global_asm_8060F254 has no documented signature
// TODO: func_global_asm_8060F54C has no documented signature
// TODO: func_global_asm_8060F730 has no documented signature
// TODO: func_global_asm_8060F854 has no documented signature
void func_global_asm_8060F928(Struct131B0_2 *arg0, Struct131B0_1 *arg1);
// TODO: func_global_asm_8060F960 has no documented signature
// TODO: func_global_asm_8060FA5C has no documented signature
void func_global_asm_8060FAA4(OSMesgQueue *arg0, OSMesg arg1, s32 arg2);
// TODO: func_global_asm_8060FAE4 has no documented signature

// global_asm/done/code_14CF0.c
void func_global_asm_8060FFF0(void);
void func_global_asm_80610044(void *arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4, u8 arg5); // TODO: arg0 Gfx*?
void func_global_asm_80610268(s32 arg0);
// TODO: func_global_asm_80610310 has no documented signature but has been matched
// TODO: func_global_asm_8061032C has no documented signature but has been matched

// global_asm/heap.c
// TODO: func_global_asm_80610350 has no documented signature
// TODO: func_global_asm_806109EC has no documented signature
// TODO: func_global_asm_80610A88 has no documented signature
void func_global_asm_80610B84(s32 arg0, s32 arg1, u32 arg2);
// TODO: func_global_asm_80610BD8 has no documented signature
// TODO: func_global_asm_80610C74 has no documented signature
// TODO: func_global_asm_80610DCC has no documented signature
// TODO: func_global_asm_80610E84 has no documented signature
void *malloc(s32 size);
u8 func_global_asm_80611154(void);
void func_global_asm_80611160(void);
s32 func_global_asm_8061116C(void);
s32 func_global_asm_8061118C(void);
s32 func_global_asm_806111BC(s32 arg0, s32 arg1);
// TODO: func_global_asm_806111F8 has no documented signature
void free(void *ptr);
void func_global_asm_8061134C(void *arg0);
void func_global_asm_8061138C(void *arg0);
// TODO: func_global_asm_80611408 has no documented signature
// TODO: func_global_asm_80611534 has no documented signature
void func_global_asm_80611594(HeapHeader *arg0);
void func_global_asm_8061159C(HeapHeader *arg0);
// TODO: func_global_asm_806115A8 has no documented signature
// TODO: func_global_asm_80611614 has no documented signature
s32 func_global_asm_80611688(HeapHeader *arg0);
void func_global_asm_80611690(void *arg0);
void func_global_asm_806116E0(HeapHeader *arg0, s32 arg1);
void func_global_asm_80611724(s32 arg0, s32 arg1);
// TODO: func_global_asm_80611730 has no documented signature
void func_global_asm_80611844(void);

// global_asm/done/code_16550.c
f32 func_global_asm_80611850(f32 arg0);
f32 func_global_asm_806118FC(f32 arg0);

// global_asm/done/rand.c
u32 func_global_asm_806119A0(void);
void func_global_asm_806119F0(s32 arg0);
f32 func_global_asm_806119FC(void);
s32 rand(void);
void func_global_asm_80611A70(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3);
f32 func_global_asm_80611BB4(f32 arg0, f32 arg1);

// global_asm/done/code_169F0.c
f32 func_global_asm_80611CF0(f32 arg0);
s32 func_global_asm_80611D08(f32 arg0);

// global_asm/done/code_16A20.c
s32 func_global_asm_80611D20(s32);
u16 func_global_asm_80611DA0(s16 arg0);
s16 func_global_asm_80611DF4(s16 arg0);
s32 func_global_asm_80611E60(s32);
// TODO: func_global_asm_80611E88 has no documented signature but has been matched
// TODO: D_global_asm_80611F0C has no documented signature
// TODO: D_global_asm_80612710 has no documented signature
f32 func_global_asm_80612790(s16 arg0);
// TODO: func_global_asm_80612800 has no documented signature but has been matched

// global_asm/code_17540.c
// TODO: func_global_asm_80612840 has no documented signature
// TODO: func_global_asm_806128A8 has no documented signature
// TODO: func_global_asm_80612910 has no documented signature
// TODO: func_global_asm_80612970 has no documented signature
// TODO: func_global_asm_80612A14 has no documented signature
// TODO: func_global_asm_80612A54 has no documented signature
void func_global_asm_80612AD8(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);

// global_asm/done/code_17800.c
f32 func_global_asm_80612B00(f32 arg0, s16 arg1);
f32 func_global_asm_80612B48(s16 arg0);
void func_global_asm_80612BC0(f32 (*arg0)[4], f32 arg1);
void func_global_asm_80612C30(f32 (*arg0)[4], f32 arg1);
void func_global_asm_80612CA0(f32 (*arg0)[4], f32 arg1);
f32 func_global_asm_80612D10(f32 arg0);
f32 func_global_asm_80612D1C(f32 arg0);

// global_asm/done/code_17B40.c
f32 func_global_asm_80612E40(f32 arg0);

// global_asm/code_17B90.c
// TODO: func_global_asm_80612E90 has no documented signature
// TODO: func_global_asm_806130A4 has no documented signature
void func_global_asm_80613194(Actor *actor, s16 arg1);
void func_global_asm_806131D4(Actor *actor, s16 arg1);
void func_global_asm_80613214(Actor *actor);
// TODO: func_global_asm_8061324C has no documented signature
// TODO: func_global_asm_80613358 has no documented signature
// TODO: func_global_asm_806133C8 has no documented signature
// TODO: func_global_asm_80613448 has no documented signature but has been matched
// TODO: func_global_asm_806134B4 has no documented signature
void func_global_asm_806136B4(Actor *arg0);
void func_global_asm_80613794(Actor *arg0, u8 arg1);
// TODO: func_global_asm_80613944 has no documented signature
void func_global_asm_80613A50(Actor *arg0, s8 arg1);
void func_global_asm_80613AF8(Actor *arg0, s32 arg1, f32 arg2, f32 arg3);
// TODO: func_global_asm_80613BA0 has no documented signature
void func_global_asm_80613C48(Actor *arg0, s16 arg1, f32 arg2, f32 arg3);
// TODO: func_global_asm_80613CA8 has no documented signature
// TODO: func_global_asm_80613FB0 has no documented signature
void func_global_asm_80614014(Actor *arg0, u16 arg1, f32 arg2, u8 arg3);
// TODO: func_global_asm_80614130 has no documented signature
// TODO: func_global_asm_8061421C has no documented signature
// TODO: func_global_asm_80614644 has no documented signature
f32 func_global_asm_80614A54(Actor *arg0);
void func_global_asm_80614A64(Actor *arg0);
// TODO: func_global_asm_80614B34 has no documented signature
// TODO: func_global_asm_80614C38 has no documented signature
void func_global_asm_80614D00(Actor *arg0, f32 arg1, f32 arg2);
void func_global_asm_80614D48(Actor *arg0, f32 arg1, f32 arg2);
void func_global_asm_80614D90(Actor *arg0);
void playAnimation(Actor *arg0, s32 arg2);
void playActorAnimation(Actor *arg0, s32 arg1);
void getAnimationArg8(u8 *arg0);
void getAnimationArg16(s16 *arg0);
void getAnimationArg24(s32 *arg0);
void getAnimationArg32(s32 *arg0);
s32 func_global_asm_8061503C(Actor *arg0);
s32 func_global_asm_8061505C(Actor *arg0);
s32 func_global_asm_8061507C(Actor *arg0);
s32 func_global_asm_806150C8(Actor *arg0);
s32 func_global_asm_806150F8(Actor *arg0);
s32 func_global_asm_80615134(Actor *arg0);
s32 func_global_asm_806151BC(Actor *arg0);
s32 func_global_asm_8061522C(Actor *arg0);
s32 func_global_asm_806152FC(Actor *arg0);
s32 func_global_asm_80615328(Actor *arg0);
s32 func_global_asm_8061537C(Actor *arg0);
s32 func_global_asm_8061540C(Actor *arg0);
s32 func_global_asm_8061551C(Actor *arg0);
s32 func_global_asm_80615558(Actor *arg0);
s32 func_global_asm_806155F4(Actor *arg0);
s32 func_global_asm_8061562C(Actor *arg0);
s32 func_global_asm_80615664(Actor *arg0);
s32 func_global_asm_806156A0(Actor *arg0);
s32 func_global_asm_806156DC(Actor *arg0);
s32 func_global_asm_80615774(Actor *arg0);
s32 func_global_asm_8061580C(Actor *arg0);
s32 func_global_asm_806158E8(Actor *arg0);
s32 func_global_asm_8061594C(Actor *arg0);
s32 func_global_asm_8061599C(Actor *arg0);
s32 func_global_asm_806159EC(Actor *arg0);
s32 func_global_asm_80615A3C(Actor *arg0);
s32 func_global_asm_80615A94(Actor *arg0);
s32 func_global_asm_80615ADC(Actor *arg0);
s32 func_global_asm_80615B34(Actor *arg0);
s32 func_global_asm_80615B84(Actor *arg0);
s32 func_global_asm_80615BDC(Actor *arg0);
s32 func_global_asm_80615C34(Actor *arg0);
s32 func_global_asm_80615CE4(Actor *arg0);
s32 func_global_asm_80615DA4(Actor *arg0);
s32 func_global_asm_80615E74(Actor *arg0);
s32 func_global_asm_80615FA0(Actor *arg0);
s32 func_global_asm_8061600C(Actor *arg0);
s32 func_global_asm_8061607C(Actor *arg0);
s32 func_global_asm_8061612C(Actor *arg0);
s32 func_global_asm_806161D0(Actor *arg0);
s32 func_global_asm_80616254(Actor *arg0);
s32 func_global_asm_806162C4(Actor *arg0);
s32 func_global_asm_80616318(Actor *arg0);
s32 func_global_asm_80616374(Actor *arg0);
s32 func_global_asm_806163D0(Actor *arg0);
s32 func_global_asm_806163E8(Actor *arg0);
s32 func_global_asm_80616470(Actor *arg0);
s32 func_global_asm_806164C4(Actor *arg0);
s32 func_global_asm_80616518(Actor *arg0);
s32 func_global_asm_80616594(Actor *arg0);
s32 func_global_asm_806165F0(Actor *arg0);
s32 func_global_asm_80616644(Actor *arg0);
s32 func_global_asm_806166A8(Actor *arg0);
s32 func_global_asm_8061670C(Actor *arg0);
s32 func_global_asm_80616770(Actor *arg0);
s32 func_global_asm_806167D4(Actor *arg0);
s32 func_global_asm_806167EC(Actor *arg0);
s32 func_global_asm_80616850(Actor *arg0);
s32 func_global_asm_806168E4(Actor *arg0);
s32 func_global_asm_80616964(Actor *arg0);
s32 func_global_asm_806169C0(Actor *arg0);
s32 func_global_asm_80616A1C(Actor *arg0);
// TODO: func_global_asm_80616A9C has no documented signature
s32 func_global_asm_80616BA4(Actor *arg0);
s32 func_global_asm_80616BF0(Actor *arg0);
s32 func_global_asm_80616C1C(Actor *arg0);
s32 func_global_asm_80616C64(Actor *arg0);
s32 func_global_asm_80616C8C(Actor *arg0);
s32 func_global_asm_80616CB8(Actor *arg0);
s32 func_global_asm_80616D5C(Actor *arg0);
s32 func_global_asm_80616D84(Actor *arg0);
s32 func_global_asm_80616DA8(Actor *arg0);
s32 func_global_asm_80616DB4(Actor *arg0);
// TODO: func_global_asm_80616E08 has no documented signature
s32 func_global_asm_80617140(Actor *arg0);
// TODO: func_global_asm_80617238 has no documented signature
s32 func_global_asm_80617400(Actor *arg0);
s32 func_global_asm_806174B4(Actor *arg0);
// TODO: func_global_asm_806175C4 has no documented signature
// TODO: func_global_asm_80617770 has no documented signature
s32 func_global_asm_8061796C(Actor *arg0);
s32 func_global_asm_806179C0(Actor *arg0);
s32 func_global_asm_80617A60(Actor *arg0);
s32 func_global_asm_80617AF0(Actor *arg0);
s32 func_global_asm_80617B38(Actor *arg0);
s32 func_global_asm_80617BD8(Actor *arg0);
s32 func_global_asm_80617C6C(Actor *arg0);
s32 func_global_asm_80617CC0(Actor *arg0);
s32 func_global_asm_80617D14(Actor *arg0);
void func_global_asm_80617D20(Actor *arg0); // TODO: s32 return?
void func_global_asm_80617D70(Actor *arg0); // TODO: s32 return?
void func_global_asm_80617D94(s32 arg0);
void func_global_asm_80617DFC(Actor*, s16);
s32 func_global_asm_80617FFC(Actor *arg0);
s32 func_global_asm_80618048(Actor *arg0);
void func_global_asm_806180FC(Actor *arg0);
// TODO: func_global_asm_80618104 has no documented signature
void func_global_asm_80618430(Actor *arg0);
void func_global_asm_8061849C(Actor *arg0);
void func_global_asm_806184BC(Actor *arg0);
void func_global_asm_8061859C(Actor *arg0);
// TODO: func_global_asm_80618608 has no documented signature
void func_global_asm_80618728(Actor *arg0);
void func_global_asm_806187BC(s32 arg0);
void func_global_asm_806187E8(Actor *arg0);
void func_global_asm_80618820(Actor *arg0);
void func_global_asm_8061885C(Actor *arg0);
void func_global_asm_80618880(Actor *arg0);
void func_global_asm_806188B8(Actor *arg0);
void func_global_asm_806188F4(Actor *arg0);
void func_global_asm_8061892C(Actor *arg0);
void func_global_asm_80618968(Actor *arg0);
void func_global_asm_80618998(Actor *arg0);
void func_global_asm_80618B6C(Actor *arg0);
void func_global_asm_80618C00(Actor *actor, u8 boneIndex);
void func_global_asm_80618C8C(Actor *arg0);
void func_global_asm_80618CD8(Actor *arg0);
void func_global_asm_80618D20(Actor *arg0);
// TODO: func_global_asm_80618D68 has no documented signature
void func_global_asm_80618E4C(Actor *arg0);
void func_global_asm_80618EE8(Actor *arg0);
void func_global_asm_80618F74(Actor *arg0);
void func_global_asm_80619018(Actor *arg0);
void func_global_asm_806190C0(Actor *arg0);
void func_global_asm_806192A4(Actor *arg0);
void func_global_asm_80619500(Actor *arg0); // TODO: s32 return?
// TODO: func_global_asm_80619520 has no documented signature but has been matched
void func_global_asm_80619540(Actor *arg0);
void func_global_asm_80619580(Actor *arg0);
void func_global_asm_806195B4(Actor *arg0);

// global_asm/code_201B0.c
u8 func_global_asm_8061B4B0(void);
// TODO: func_global_asm_8061B4E4 has no documented signature
void func_global_asm_8061B5C4(s16 playerIndex);
void func_global_asm_8061B610(Actor *arg0);
void func_global_asm_8061B650(Actor *arg0);
// TODO: func_global_asm_8061B660 has no documented signature but has been matched
// TODO: func_global_asm_8061B7E0 has no documented signature but has been matched
// TODO: func_global_asm_8061B840 has no documented signature but has been matched
// TODO: func_global_asm_8061B84C has no documented signature
// TODO: func_global_asm_8061B9B0 has no documented signature
// TODO: func_global_asm_8061C0FC has no documented signature but has been matched
void func_global_asm_8061C2C4(Actor *arg0, s32 arg1);
void func_global_asm_8061C2D8(Actor *camera, s32 arg1);
void func_global_asm_8061C2F0(Actor *camera, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, u8 arg7);
void func_global_asm_8061C39C(Actor *camera);
void func_global_asm_8061C458(Actor *camera, s32 arg1);
void func_global_asm_8061C464(Actor *arg0, Actor *arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, f32 argA);
void func_global_asm_8061C518(Actor *arg0, Actor *arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, f32 argA);
void func_global_asm_8061C600(Actor *arg0, Actor *arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, f32 argA);
void func_global_asm_8061C6A8(Actor *arg0, Actor *arg1, s32 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, f32 arg10);
// TODO: func_global_asm_8061C804 has no documented signature
void func_global_asm_8061CAD8(void);
void func_global_asm_8061CB08(void);
u8 func_global_asm_8061CB38(void);
u8 func_global_asm_8061CB50(void);
u8 func_global_asm_8061CB80(void);
u8 func_global_asm_8061CB98(u8 arg0);
void func_global_asm_8061CBCC(void);
u8 func_global_asm_8061CC00(void);
void func_global_asm_8061CC30(void);
s32 playCutscene(Actor *arg0, s16 arg1, u8 arg2);
void func_global_asm_8061CF24(s16 *arg0, s16 *arg1, s16 *arg2, s16 *arg3);
void func_global_asm_8061CF80(s16 arg0);
void func_global_asm_8061CF90(Actor *arg0, s16 arg1);
void func_global_asm_8061CFCC(Actor *arg0);
void func_global_asm_8061D058(void);
// TODO: func_global_asm_8061D060 has no documented signature
// TODO: func_global_asm_8061D1FC has no documented signature
void func_global_asm_8061D4E4(Actor *arg0);
// TODO: func_global_asm_8061D6A8 has no documented signature
void func_global_asm_8061D898(void);
void func_global_asm_8061D934(u8 arg0);
void func_global_asm_8061D968(u8 arg0, u8 arg1);
void func_global_asm_8061D9EC(s32 arg0, s32 arg1, s32 arg2);
void func_global_asm_8061DA14(s32 arg0, s32 arg1, s32 arg2);
void func_global_asm_8061DA84(s32 arg0, s32 arg1, s32 arg2);
void func_global_asm_8061DAAC(s16 arg0, s16 arg1, u16 arg2);
void func_global_asm_8061DB64(Actor *arg0);
// TODO: func_global_asm_8061DBD4 has no documented signature
void func_global_asm_8061EA78(void);
s32 func_global_asm_8061EB04(Actor *playerPointer, u8 playerIndex);
// TODO: func_global_asm_8061EDA0 has no documented signature but has been matched
void func_global_asm_8061EF4C(Actor*, u8, u16, f32, f32, f32, f32, f32);
void func_global_asm_8061F0B0(Actor *arg0, u8 arg1, u16 arg2);
// TODO: func_global_asm_8061F164 has no documented signature but has been matched
void func_global_asm_8061F18C(Actor *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_8061F2B8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 *arg9, f32 *argA, f32 *argB);
// TODO: func_global_asm_8061F4B0 has no documented signature
// TODO: func_global_asm_8061F510 has no documented signature
// TODO: func_global_asm_8061F53C has no documented signature
// TODO: func_global_asm_80620628 has no documented signature
// TODO: func_global_asm_80620B38 has no documented signature
// TODO: func_global_asm_80620F00 has no documented signature
// TODO: func_global_asm_80621174 has no documented signature
// TODO: func_global_asm_8062133C has no documented signature
// TODO: func_global_asm_80621E9C has no documented signature
// TODO: func_global_asm_8062210C has no documented signature but has been matched
void func_global_asm_8062217C(Actor*, s16);
// TODO: func_global_asm_80622334 has no documented signature
void func_global_asm_806224CC(Actor *arg0, Actor *arg1);
void func_global_asm_806225C0(Actor *arg0);
// TODO: func_global_asm_806225D4 has no documented signature
// TODO: func_global_asm_806227F0 has no documented signature but has been matched
void func_global_asm_806228BC(Actor *actor, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6);
f32 func_global_asm_80622ABC(f32 arg0, f32 arg1, f32 arg2);
// TODO: func_global_asm_80622B24 has no documented signature
// TODO: func_global_asm_80624978 has no documented signature
// TODO: func_global_asm_80624CA4 has no documented signature
f32 func_global_asm_806252CC(f32 arg0, f32 arg1, f32 arg2);
// TODO: func_global_asm_80625320 has no documented signature
// TODO: func_global_asm_806256D0 has no documented signature
void func_global_asm_80625994(Actor *arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4);
// TODO: func_global_asm_806259FC has no documented signature
s16 func_global_asm_80625A80(s32 lockRegionIndex);
void func_global_asm_80625B3C(s16 *arg0, s16 *arg1, s16 *arg2);
// TODO: func_global_asm_80625C30 has no documented signature
void func_global_asm_80626110(Actor *arg0, s16 arg1, s16 arg2);
void func_global_asm_806261CC(Actor *arg0);
// TODO: func_global_asm_806261EC has no documented signature but has been matched
// TODO: func_global_asm_80626264 has no documented signature
// TODO: func_global_asm_80626478 has no documented signature
// TODO: func_global_asm_8062649C has no documented signature
// TODO: func_global_asm_806264DC has no documented signature
// TODO: func_global_asm_80626BC8 has no documented signature
// TODO: func_global_asm_80626CAC has no documented signature
s32 func_global_asm_80626F8C(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, s32 arg5, f32 arg6, s32 arg7);
// TODO: func_global_asm_80627388 has no documented signature
// TODO: func_global_asm_80627490 has no documented signature
void func_global_asm_8062754C(f32 arg0);
f32 func_global_asm_806276AC(void);
s16 func_global_asm_8062773C(Actor *arg0);
void func_global_asm_80627878(Actor *arg0);
void func_global_asm_80627888(Actor *arg0);
void func_global_asm_80627948(Actor *arg0, u8 arg1, u8 arg2, u8 arg3);

// global_asm/code_2C700.c
// TODO: func_global_asm_80627A00 has no documented signature
void func_global_asm_80627B58(f32 arg0);

// global_asm/code_2C910.c
void func_global_asm_80627C10(u8 arg0);
// TODO: func_global_asm_80627C5C has no documented signature
Actor *func_global_asm_80627EA8(s16 spawn_trigger);
// TODO: func_global_asm_80627F04 has no documented signature
s32 func_global_asm_80629148(void);
void func_global_asm_80629174(void);

// global_asm/code_2DE90.c
void func_global_asm_80629190(void);
u8 func_global_asm_8062919C(void);
u8 func_global_asm_806291A8(void);
void func_global_asm_806291B4(u8 arg0);
Gfx *func_global_asm_80629300(Gfx *dl);
void func_global_asm_8062A130(s32 arg0, s32 arg1, void *arg2);
void func_global_asm_8062A228(s32 arg0, s32 arg1, void *arg2);
void func_global_asm_8062A24C(s32 arg0, s32 arg1, void *arg2);
void func_global_asm_8062A274(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4);
void func_global_asm_8062A348(void);
// TODO: func_global_asm_8062A3F0 has no documented signature
void func_global_asm_8062A774(void);
void func_global_asm_8062A7D0(void);
void func_global_asm_8062A808(s32 arg0, s32 arg1);
Gfx *func_global_asm_8062A844(Gfx *dl);

// global_asm/code_2F550.c
f32 func_global_asm_8062A850(void);
void func_global_asm_8062A944(f32 arg0, f32 arg1, f32 arg2);
void func_global_asm_8062AC68(void *arg0);
void func_global_asm_8062AD28(f32 arg0, f32 arg1, f32 arg2, GlobalASMStruct64 *arg3, f32 *arg4);
void func_global_asm_8062B194(GlobalASMStruct64 *arg0);
// TODO: func_global_asm_8062B220 has no documented signature
// TODO: func_global_asm_8062B3C4 has no documented signature
void func_global_asm_8062B478(s32 arg0);
void func_global_asm_8062B630(s16 arg0, u8 arg1);
// TODO: func_global_asm_8062B660 has no documented signature
f32 func_global_asm_8062B840(s8 arg0);
void func_global_asm_8062B86C(s32 arg0, f32 arg1, f32 arg2);
void func_global_asm_8062B8A4(s32 arg0, f32 arg1, f32 arg2);
void func_global_asm_8062B8E4(f32 *arg0);
void func_global_asm_8062BA0C(f32 *arg0);
// TODO: func_global_asm_8062BA74 has no documented signature but has been matched
void func_global_asm_8062BAE4(void);
// TODO: func_global_asm_8062BB2C has no documented signature
u8 func_global_asm_8062BCC8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
// TODO: func_global_asm_8062BDB0 has no documented signature
// TODO: func_global_asm_8062BF24 has no documented signature
void func_global_asm_8062C1C0(s32 arg0);
void func_global_asm_8062C22C(void);
// TODO: func_global_asm_8062C29C has no documented signature
// TODO: func_global_asm_8062C99C has no documented signature but has been matched
Gfx *func_global_asm_8062CA0C(Gfx *dl, f32 arg1, f32 arg2, f32 arg3);
// TODO: func_global_asm_8062CA70 has no documented signature
// TODO: func_global_asm_8062CEA8 has no documented signature
void func_global_asm_8062D094(PropModel *arg0, u8 arg1);
// TODO: func_global_asm_8062D0CC has no documented signature but has been matched
void func_global_asm_8062D1A8(void);
// TODO: func_global_asm_8062D1E0 has no documented signature
void func_global_asm_8062D26C(Actor *arg0);
u8 func_global_asm_8062D2AC(void *arg0, void *arg1, u8 arg2);
// TODO: func_global_asm_8062D2F0 has no documented signature but has been matched
void func_global_asm_8062D3E4(void *arg0);
// TODO: func_global_asm_8062D414 has no documented signature but has been matched
// TODO: func_global_asm_8062D620 has no documented signature
// TODO: func_global_asm_8062DAF4 has no documented signature but has been matched
void func_global_asm_8062DB70(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
// TODO: func_global_asm_8062DBDC has no documented signature
// TODO: func_global_asm_8062E040 has no documented signature
// TODO: func_global_asm_8062E1F8 has no documented signature
// TODO: func_global_asm_8062E3B4 has no documented signature
s32 func_global_asm_8062E548(s16 *arg0, u8 arg1, f64 arg3, u8 arg4);
void func_global_asm_8062E608(void *arg0, s32 *arg1, s32 arg2);
// TODO: func_global_asm_8062E67C has no documented signature but has been matched
// TODO: func_global_asm_8062E898 has no documented signature
// TODO: func_global_asm_8062EBB8 has no documented signature
Gfx *func_global_asm_8062EDA8(Gfx *dl, u8 arg1);
void func_global_asm_8062EE48(u8 arg0);
void func_global_asm_8062EFA0(void);
void func_global_asm_8062F050(MapGeometryHeader *arg0);
void func_global_asm_8062F318(void);
void func_global_asm_8062F328(s32 arg0);
s32 func_global_asm_8062F388(s32 *arg0);
// TODO: func_global_asm_8062F3A0 has no documented signature
// TODO: func_global_asm_8062F420 has no documented signature
// TODO: func_global_asm_8062F538 has no documented signature
// TODO: func_global_asm_8062F640 has no documented signature
// TODO: func_global_asm_8062F998 has no documented signature
// TODO: func_global_asm_8062FBC8 has no documented signature
// TODO: func_global_asm_8062FF10 has no documented signature

// global_asm/code_35000.c
void func_global_asm_80630300(void);
s32 func_global_asm_80630324(u8 arg0, Struct80652374_arg0_unk0 *arg1);
void func_global_asm_8063039C(void);
Chunk14 *func_global_asm_806303C4(Chunk14 *arg0, u8 arg1, PropModel *arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6, s16 arg7, u8 arg8, s16 arg9, u8 argA);
Chunk14 *func_global_asm_80630588(Chunk14 *arg0, PropModel *arg1, u8 arg2, u8 *arg3);
void func_global_asm_806306D0(Chunk14 *current);
Chunk14 *func_global_asm_8063070C(Chunk14 *arg0);
void func_global_asm_806307AC(Chunk14 *current);
void func_global_asm_806307CC(Chunk14 *arg0, PropModel *arg1, u8 arg2, u8 arg3, s8 *arg4);
// TODO: func_global_asm_80630890 has no documented signature
Gfx *func_global_asm_80630B70(Gfx*, s32, f32, f32, f32, s32, s32, s32);
// TODO: func_global_asm_80630DCC has no documented signature
s32 func_global_asm_8063162C(Actor *arg0, s16 *arg1);
s32 func_global_asm_806317D4(Actor *arg0, s16 *arg1, f32 arg2, f32 arg3, f32 arg4);
void renderActor(Actor *arg0, u8 arg1);

// global_asm/code_36880.c
void func_global_asm_80631B80(void);
void func_global_asm_80631B8C(s16 arg0);
s32 func_global_asm_80631BCC(s16 arg0);
s16 func_global_asm_80631C20(u8 arg0);
void func_global_asm_80631C3C(void);
s32 func_global_asm_80631D8C(u8 map);
s32 func_global_asm_80631EB8(u16 arg1);
// TODO: func_global_asm_80631F58 has no documented signature
s16 func_global_asm_80631FAC(Maps arg0, u8 arg1);
// TODO: func_global_asm_80632084 has no documented signature
void func_global_asm_806323C0(Chunk14 *arg0);
s32 func_global_asm_8063253C(s32 arg0, s32 arg1);
s32 func_global_asm_8063254C(s32 objectType, s32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, s16 *arg5, s16 *arg6);
s16 func_global_asm_80632630(s32 arg0, f32 x, f32 y, f32 z, f32 arg4, u8 arg5);
// TODO: func_global_asm_80632860 has no documented signature
void func_global_asm_80632E10(s16 arg0, u8 *arg1);
void func_global_asm_80632E74(s16 arg0, s16 arg1, u8 *arg2);
// TODO: func_global_asm_80632F20 has no documented signature but has been matched
u8 func_global_asm_80632F74(f32 arg0, f32 arg1, f32 arg2);
void func_global_asm_80632FCC(s16 arg0, u8 arg1);
// TODO: func_global_asm_806330C4 has no documented signature
// TODO: func_global_asm_806333F8 has no documented signature
void func_global_asm_80633570(GlobalASMStruct83 *arg0);
void func_global_asm_806335B0(s32 arg0, u8 arg1, s32 boneIndex, f32* x, f32* y, f32* z);
// TODO: func_global_asm_8063367C has no documented signature
// TODO: func_global_asm_8063373C has no documented signature
void func_global_asm_806338B4(Prop_unk74 *arg0);
void func_global_asm_806338F4(s32 arg0);
void func_global_asm_8063393C(s32 arg0, u8 arg1, u8 arg2, u8 arg3);
// TODO: func_global_asm_80633A1C has no documented signature
void func_global_asm_80633D30(f32 *arg0, f32 *arg1);
// TODO: func_global_asm_80633DC0 has no documented signature but has been matched
// TODO: func_global_asm_80634768 has no documented signature but has been matched
void func_global_asm_806348B4(Prop_unk48 *arg0);
void func_global_asm_80634908(s32 arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8);
void func_global_asm_8063495C(Prop_unk24 *arg0, Prop *arg1);
// TODO: func_global_asm_806349FC has no documented signature
void func_global_asm_80634CC8(s32 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_80634D14(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80634D64(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, u8 arg6);
void func_global_asm_80634E10(PropModel50_B8 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 *arg4, s16 *arg5, u8 arg6);
void func_global_asm_80634EA4(s32 arg0, s16 arg1, u8 arg2);
void func_global_asm_80634EDC(s32 arg0, s16 arg1, u8 *arg2);
void func_global_asm_80634F14(s32 arg0, s16 arg1, u8 arg2, u8 *arg3, u8 arg4);
void func_global_asm_80634FA0(PropModel50_B8 *arg0, s16 arg1, u8 arg2, u8 *arg3, u8 arg4);
void func_global_asm_80635018(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80635098(PropModel50_B8 *arg0, s16 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_80635114 has no documented signature
s32 func_global_asm_80635214(Gfx *dl);
// TODO: func_global_asm_8063524C has no documented signature
// TODO: func_global_asm_80635468 has no documented signature
// TODO: func_global_asm_80635548 has no documented signature but has been matched
void func_global_asm_80635588(void);
void func_global_asm_806355DC(s32 arg0, u8 arg1);
void func_global_asm_806357F8(s32 arg0, f32 *x, f32 *y, f32 *z, f32 *xRot, f32 *yRot, f32 *zRot, f32 *scale, f32 *arg8, u8 arg9);
// TODO: func_global_asm_806358E8 has no documented signature
s32 func_global_asm_80635EF0(f32 x1, f32 y1, f32 z1, s16 x2, s16 y2, s16 z2, u16 arg6);
void func_global_asm_80636014(s32 arg0, u8 arg1, u8 arg2);
void func_global_asm_80636074(Prop *arg0);
void func_global_asm_80636164(PropModel *arg0, u8 arg1);
void func_global_asm_80636210(PropModel *arg0, u8 arg1);
void func_global_asm_806362C4(s32 arg0, u8 arg1);
// TODO: func_global_asm_80636380 has no documented signature but has been matched
void func_global_asm_8063643C(void);
void func_global_asm_80636448(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4);
void func_global_asm_806364C4(void);
void func_global_asm_806365D0(Prop *arg0, Prop_unk24 *arg1, PropModel *arg2);
// TODO: func_global_asm_80636784 has no documented signature
void func_global_asm_806368F0(Prop *arg0, s32 propType);
f32 func_global_asm_80636A44(s32 arg0);
u8 func_global_asm_80636A8C(s32 arg0);
void func_global_asm_80636AE8(Prop *arg0);
// TODO: func_global_asm_80636B50 has no documented signature
// TODO: func_global_asm_80636C00 has no documented signature
// TODO: func_global_asm_80636D38 has no documented signature
// TODO: func_global_asm_80636EFC has no documented signature
// TODO: func_global_asm_80636FFC has no documented signature
// TODO: func_global_asm_80637B6C has no documented signature
// TODO: func_global_asm_806392BC has no documented signature
void func_global_asm_806398E4(s32 propIndex, u8 arg1, u8 arg2);
// TODO: func_global_asm_80639968 has no documented signature
// TODO: func_global_asm_80639C04 has no documented signature
// TODO: func_global_asm_80639CD0 has no documented signature but has been matched
s32 func_global_asm_80639F1C(PropModel50_B8 *arg0, s32 *arg1, s32 *arg2);
// TODO: func_global_asm_80639FC0 has no documented signature
s32 func_global_asm_8063A38C(Chunk14 *arg0, Chunk14 *arg1, f32 arg2, f32 arg3, f32 arg4);
// TODO: func_global_asm_8063A848 has no documented signature
void func_global_asm_8063A8C4(s16 arg0, u8 arg1, f32 arg2);
// TODO: func_global_asm_8063A968 has no documented signature
void func_global_asm_8063B4A4(void);
// TODO: func_global_asm_8063B4C0 has no documented signature
// TODO: func_global_asm_8063B758 has no documented signature
// TODO: func_global_asm_8063B8D8 has no documented signature
// TODO: func_global_asm_8063BBB0 has no documented signature
// TODO: func_global_asm_8063BEC0 has no documented signature but has been matched
// TODO: func_global_asm_8063BF34 has no documented signature
void func_global_asm_8063C1EC(s32 arg0, u8 arg1);
void func_global_asm_8063C248(s32 arg0, u8 arg1);
s32 func_global_asm_8063C2A8(s16 arg0);
s16 func_global_asm_8063C328(s16 arg0);
void func_global_asm_8063C390(void);
void func_global_asm_8063C3C0(s16 arg0);
Gfx *func_global_asm_8063C418(Gfx *dl, s16 arg1);
void func_global_asm_8063C450(void);
void func_global_asm_8063C4A8(void);
Gfx *func_global_asm_8063C4C4(Gfx *dl);
void func_global_asm_8063C6D8(void);
void func_global_asm_8063C784(void);
// TODO: func_global_asm_8063C7C4 has no documented signature
void func_global_asm_8063CA7C(void);
void func_global_asm_8063CADC(void);
// TODO: func_global_asm_8063CB40 has no documented signature
void func_global_asm_8063CE64(void);
void func_global_asm_8063CF0C(void);
Gfx *func_global_asm_8063CF3C(Gfx *dl);
void func_global_asm_8063D1D8(void);
void func_global_asm_8063D288(void);
Gfx *func_global_asm_8063D2E4(Gfx *dl);
void func_global_asm_8063D468(void);
void func_global_asm_8063D494(void);
Gfx *func_global_asm_8063D4A4(Gfx *dl);
void func_global_asm_8063D5AC(void);
void func_global_asm_8063D608(void);
Gfx *func_global_asm_8063D638(Gfx *dl);
void func_global_asm_8063D854(void);

// global_asm/code_42630.c
void func_global_asm_8063D930(void);
s16 func_global_asm_8063D990(s16 arg0);
s16 func_global_asm_8063D9D0(s16 arg0, u8 arg1);
void func_global_asm_8063DA40(s16 arg0, s16 arg1);
void func_global_asm_8063DA78(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_8063DB0C(void);
void func_global_asm_8063DB3C(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_8063DBD8(s16 arg0);
// TODO: func_global_asm_8063DC58 has no documented signature
// TODO: func_global_asm_8063DE68 has no documented signature but has been matched
void func_global_asm_8063DED0(Prop_ScriptData *arg0);
void func_global_asm_8063DFEC(s32 arg0, void *arg1);
void func_global_asm_8063E078(Prop_ScriptData *arg0);
// TODO: func_global_asm_8063E0D4 has no documented signature
void func_global_asm_8063E5B4(Prop_ScriptData *arg0);
void func_global_asm_8063E6B4(Prop_ScriptData *arg0);
void func_global_asm_8063E72C(Prop_ScriptData *arg0);
// TODO: func_global_asm_8063EA14 has no documented signature
// TODO: func_global_asm_8063FA48 has no documented signature
void func_global_asm_80641724(s16 arg0);
void func_global_asm_806417BC(s16 arg0, s16 arg1);
void func_global_asm_80641874(s16 arg0, s16 arg1);
s32 func_global_asm_806418E8(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_8064199C(Struct8064199C_arg0 *arg0, s8 arg1, s16 arg2);
s32 func_global_asm_806419F8(void);
void func_global_asm_80641A78(void);
void func_global_asm_80641B00(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_80641BCC(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_80641C98(s16 arg0, s16 arg1, s16 arg2);
// TODO: func_global_asm_80641DA0 has no documented signature but has been matched
void func_global_asm_80641F68(void);
u8 func_global_asm_80641F70(s16 arg0);
u8 func_global_asm_8064216C(s16 cap, f32 x, f32 y, f32 z);
s32 func_global_asm_80642204(s16 arg0);
s32 func_global_asm_806422D8(s16 arg0);
s32 func_global_asm_806423A8(s16 distance, s16 startSpawnTrigger, s16 endSpawnTrigger);
void func_global_asm_80642480(s16 arg0, s32 arg1);
s32 func_global_asm_80642500(f32 *arg0, s16 arg1, s16 arg2);
s32 func_global_asm_806425FC(s16 arg0, s16 arg1);
// TODO: func_global_asm_80642748 has no documented signature but has been matched
// TODO: func_global_asm_80642844 has no documented signature but has been matched
void func_global_asm_80642940(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

// global_asm/propScripts.c
void func_global_asm_80642BF0(Prop_ScriptData *arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80642C78(Prop_ScriptData *arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80642E34(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3);
void func_global_asm_80642FC4(Prop_ScriptData *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_80643274(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_80643354(s32 arg0, u32 arg1, u32 arg2);
void func_global_asm_80643440(Prop_ScriptData *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_806436A4(Prop_ScriptData *arg0, s32 arg1, s16 arg2, s16 arg3);
void func_global_asm_806436E0(Prop_ScriptData *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064384C(Prop_ScriptData *arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_806438B8(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 boneIndex);
void func_global_asm_80643B24(Prop_ScriptData *arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80643C0C(Prop_ScriptData *arg0, s32 arg1, s16 arg2, s32 arg3);
void func_global_asm_80643F38(Prop_ScriptData *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064409C(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_8064431C(Prop_ScriptData *arg0, s16 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_806443E4 has no documented signature
void func_global_asm_806449C0(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3);
void func_global_asm_80644A18(s32 arg0, s32 arg1, s32 arg2, f32 arg3);
void func_global_asm_80644CC0(void **arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_80644D50(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80644E2C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_80644EC8(s32 arg0, s32 arg1, s16 arg2, s16 arg3);
void func_global_asm_806450C0(s32 arg0, s32 arg1, s16 arg2, s16 arg3);
void func_global_asm_80645238(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_80645614(s32 arg0, s16 arg1, s16 arg2, s16 arg3);
// TODO: func_global_asm_80645700 has no documented signature but has been matched
void func_global_asm_806458C8(s32 arg0, s32 arg1, s16 arg2, s32 arg3);
void func_global_asm_80645A64(s32 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_global_asm_80645B9C(gASMStruct3 *arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80645C04(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80645D14(s32 **arg0, s32 arg1, s16 arg2, s32 arg3);
void func_global_asm_80645F40(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_80646058 has no documented signature
// TODO: func_global_asm_80646770 has no documented signature
// TODO: func_global_asm_80646978 has no documented signature
void func_global_asm_80646DC4(s32 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_80647108(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80647170(s32 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_global_asm_80647218(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_80647508(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80647610(Prop_ScriptData *arg0, s32 arg1, s16 arg2, s16 arg3);
void func_global_asm_8064774C(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80647834(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80647A14(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_80647B74(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_80647CF4(s32 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_global_asm_80647D7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_80648000 has no documented signature
// TODO: func_global_asm_8064826C has no documented signature but has been matched
void func_global_asm_806485A0(s32 arg0, s32 arg1, s16 arg2, s16 arg3);
// TODO: func_global_asm_806487C4 has no documented signature
int func_global_asm_80648C50(void);
// TODO: func_global_asm_80648C84 has no documented signature
void func_global_asm_8064911C(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_806491F4 has no documented signature
void func_global_asm_806493C4(s32 arg0, s32 arg1, s16 arg2, s16 arg3);
void func_global_asm_8064954C(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_806496B0 has no documented signature
// TODO: func_global_asm_80649BF0 has no documented signature
void func_global_asm_80649D74(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_80649E00(GlobalASMStruct49 *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_80649E34(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_80649F64(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_80649FC0 has no documented signature
void func_global_asm_8064A180(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064A194(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_8064A258 has no documented signature
void func_global_asm_8064A804(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_8064AAC4(s32 arg0, s16 arg1, s8 arg2, s32 arg3);
s32 func_global_asm_8064AB1C(s32 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_global_asm_8064AC28(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_8064B118(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_8064B150 has no documented signature but has been matched
// TODO: func_global_asm_8064B190 has no documented signature but has been matched
// TODO: func_global_asm_8064B204 has no documented signature but has been matched
// TODO: func_global_asm_8064B260 has no documented signature but has been matched
// TODO: func_global_asm_8064B2AC has no documented signature but has been matched
// TODO: func_global_asm_8064B370 has no documented signature but has been matched
void func_global_asm_8064B3F8(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_8064B4AC(s32 arg0, s32 arg1, s16 arg2, s16 arg3);
void func_global_asm_8064B514(u8 arg0, u8 arg1, s8 arg2, s16 arg3);
void func_global_asm_8064B574(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064B5A4(s32 arg0, s32 arg1, s16 arg2, s16 arg3);
void func_global_asm_8064B798(s32 arg0, s32 arg1, s8 arg2, s32 arg3);
void func_global_asm_8064B7C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064B7D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064B7E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064B828(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064B868(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064B900(s32 arg0, s32 arg1, s16 arg2, s32 arg3);
void func_global_asm_8064B9E0(s32 arg0, s32 arg1, s16 arg2, s32 arg3);
// TODO: func_global_asm_8064BAF4 has no documented signature but has been matched
void func_global_asm_8064BB4C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_global_asm_8064BB78(s32 arg0, s32 arg1, s32 levelIndex, s32 arg3);
u8 func_global_asm_8064BBD8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_global_asm_8064BCB0(s32 arg0, s32 arg1);
s32 func_global_asm_8064BD2C(s32 arg0, s16 arg1, s16 arg2, s16 arg3);
u8 func_global_asm_8064BE58(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_global_asm_8064BE80(s32 arg0, s16 arg1, s16 arg2, s32 arg3);
s32 func_global_asm_8064BF58(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064BFD0(Prop_ScriptData *arg0, s32 arg1, s16 arg2, s16 arg3);
void func_global_asm_8064C134(Prop_ScriptData *arg0, s32 arg1, s16 arg2, s32 arg3);
void func_global_asm_8064C250(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_8064C3E8 has no documented signature but has been matched
// TODO: func_global_asm_8064C544 has no documented signature but has been matched
// TODO: func_global_asm_8064C644 has no documented signature but has been matched
void func_global_asm_8064C708(s32 **arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064C814(void **arg0, s16 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_8064C9F8 has no documented signature but has been matched
void func_global_asm_8064CB3C(s32 **arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064CC80(s32 **arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064CD3C(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_8064D0C4(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3);
// TODO: func_global_asm_8064D1E8 has no documented signature
// TODO: func_global_asm_8064D418 has no documented signature
void func_global_asm_8064D880(s32 arg0, s16 arg1, s16 arg2, s32 arg3);
// TODO: func_global_asm_8064D978 has no documented signature but has been matched
void func_global_asm_8064DB98(s32 **arg0, s16 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064DE04(Prop_ScriptData *arg0, s32 arg1, s16 arg2, s32 arg3);
// TODO: func_global_asm_8064DF5C has no documented signature
void func_global_asm_8064E174(Prop_ScriptData *arg0, s16 arg1, s16 arg2, u8 *array, s32 size, s16 arg5, s16 arg6);
void func_global_asm_8064E428(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3);
void func_global_asm_8064E48C(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3);
void func_global_asm_8064E4F8(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3);
void func_global_asm_8064E55C(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s32 arg3);
// TODO: func_global_asm_8064E5C0 has no documented signature but has been matched
void func_global_asm_8064E65C(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_8064EA48(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_8064EAB4 has no documented signature but has been matched
s32 func_global_asm_8064EB3C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
u8 func_global_asm_8064EB9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
u8 func_global_asm_8064EC04(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
u8 func_global_asm_8064EC60(Prop_ScriptData *arg0, s16 arg1, s16 arg2, s16 arg3);
s32 func_global_asm_8064ED68(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_8064EE08 has no documented signature but has been matched
void func_global_asm_8064F028(s32 arg0, s32 arg1, s16 arg2, s32 arg3);
u8 func_global_asm_8064F1C4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
// TODO: func_global_asm_8064F210 has no documented signature
s32 func_global_asm_8064F2F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_8064F308(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
u8 func_global_asm_8064F358(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
u8 func_global_asm_8064F404(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

// global_asm/code_54150.c
// TODO: func_global_asm_8064F450 has no documented signature
// TODO: func_global_asm_8064F6C0 has no documented signature
void func_global_asm_8064F6F8(void *arg0, s16 arg1);
void func_global_asm_8064F804(Prop_unk78 *arg0);
u8 func_global_asm_8064F84C(s16 arg0);
void func_global_asm_8064F954(s32 arg0);
// TODO: func_global_asm_8064F97C has no documented signature
void func_global_asm_8064FA7C(void *arg0, void *arg1);
// TODO: func_global_asm_8064FB64 has no documented signature
// TODO: func_global_asm_806500E0 has no documented signature
void func_global_asm_8065051C(void);
void func_global_asm_8065054C(Prop_unk78 *arg0, void *arg1, void *arg2);
void func_global_asm_806505F0(Prop_unk78 *arg0);
void func_global_asm_80650684(Prop_unk78 *arg0);
void func_global_asm_806506E8(Prop_unk78 *arg0);
void func_global_asm_80650794(s16 arg0, s16 arg1, u8 arg2, f32 arg3);
void func_global_asm_806508B4(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_8065092C(s16 arg0, s16 arg1);
void func_global_asm_80650998(s16 arg0, s16 arg1);
void func_global_asm_80650A04(s16 arg0, s16 arg1, s16 arg2);
s16 func_global_asm_80650A70(s16 arg0, s16 arg1);
void func_global_asm_80650AD8(s16 arg0, s16 arg1, s16 arg2, f32 arg3);
void func_global_asm_80650B50(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_80650BBC(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_80650C28(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_80650C98(s16 arg0, s16 arg1, s16 arg2);
u8 func_global_asm_80650D04(s16 arg0, s16 arg1);
void func_global_asm_80650D8C(s16 arg0, s16 arg1, s16 *arg2, f32 *arg3, u8 *arg4);

// global_asm/code_55B20.c
// TODO: func_global_asm_80650E20 has no documented signature
// TODO: func_global_asm_80650ECC has no documented signature
// TODO: func_global_asm_80651708 has no documented signature
// TODO: func_global_asm_80651904 has no documented signature
u8 func_global_asm_80651B64(s16 arg0);
void func_global_asm_80651BC0(s16 arg0, u8 arg1);
void func_global_asm_80651BE0(s16 arg0, u8 arg1, u8 arg2);
// TODO: func_global_asm_80651C2C has no documented signature
void func_global_asm_8065214C(void);
void func_global_asm_806521F8(void);
s32 func_global_asm_806522CC(s16 arg0, s16 arg1, s16 arg2);
// TODO: func_global_asm_80652374 has no documented signature but has been matched
void func_global_asm_806524A0(PropModel *arg0, u8 arg1);
u8 func_global_asm_80652594(PropModel *arg0, s16 *arg1, u8 arg2);
void func_global_asm_806526E0(u8 arg0);
void func_global_asm_80652790(u8 arg0);
void func_global_asm_80652858(f32 arg0, f32 arg1, f32 arg2, u8 arg3);
void func_global_asm_8065297C(void);
void func_global_asm_80652A08(f32 arg0, f32 arg1, f32 arg2, u8 arg3);
void func_global_asm_80652B04(void);
u8 func_global_asm_80652BC8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
s32 func_global_asm_80652DB4(f32 arg0, f32 arg1, f32 arg2);
u8 func_global_asm_80652E58(s16 arg0);
u8 func_global_asm_80652EBC(s16 arg0);
u8 func_global_asm_80652F24(s16 arg0, s16 arg1);
s16 func_global_asm_80652F9C(f32 arg0, f32 arg1, f32 arg2, s16 arg3);
void func_global_asm_80652FDC(f32 arg0, f32 arg1, f32 arg2, s16 arg3, s16 arg4, s16 *arg5);
s16 func_global_asm_806531B8(f32 arg0, f32 arg1, f32 arg2, s16 arg3);
s32 func_global_asm_806533C4(f32 arg0, f32 arg1, f32 arg2);
s32 func_global_asm_806534E0(f32 arg0, f32 arg1, f32 arg2, s16 chunkIndex, s8 *arg4, f32 *arg5);
s32 func_global_asm_80653684(Chunk78_7C *arg0, f32 arg1, f32 arg2);
s32 func_global_asm_80653804(Chunk78_7C *arg0, f32 arg1, f32 arg2);
void func_global_asm_80653A70(s16 chunkIndex);
void func_global_asm_80653B70(u8 arg0);
void func_global_asm_80653B80(f32 arg0, f32 arg1, f32 arg2);
// TODO: func_global_asm_80653DF0 has no documented signature
void func_global_asm_80653EA8(Gfx *dl, Gfx *arg1);
void func_global_asm_80653F68(s16 index);
// TODO: func_global_asm_80653FA4 has no documented signature
void func_global_asm_80654380(f32 arg0, f32 arg1, f32 arg2);
void func_global_asm_80654418(f32 arg0, f32 arg1, f32 arg2);
// TODO: func_global_asm_806545D4 has no documented signature
void func_global_asm_806547A8(f32 arg0, f32 arg1, f32 arg2);
void func_global_asm_80654A2C(f32 arg0, f32 arg1, f32 arg2);
void func_global_asm_80654BC0(s32 arg0, u8 arg1);
// TODO: func_global_asm_80654CCC has no documented signature
// TODO: func_global_asm_80654E84 has no documented signature but has been matched
// TODO: func_global_asm_80654FEC has no documented signature
void func_global_asm_80655258(f32 arg0, f32 arg1, f32 arg2, s32 arg3);
void func_global_asm_80655410(f32 arg0, f32 arg1, f32 arg2);
void func_global_asm_80655AD0(void);
void func_global_asm_80655BF0(void);
s32 func_global_asm_80655CF8(s16 arg0, s32 arg1);
// TODO: func_global_asm_80655DD0 has no documented signature
// TODO: func_global_asm_80656B98 has no documented signature
void func_global_asm_80656E58(s16 arg0, s16 arg1, u8 arg2, u8 arg3);
// TODO: func_global_asm_80656F14 has no documented signature
// TODO: func_global_asm_806574B8 has no documented signature
void func_global_asm_80657508(s32 arg0);
void func_global_asm_8065756C(s16 arg0);
s32 func_global_asm_806575D0(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
// TODO: func_global_asm_8065776C has no documented signature
// TODO: func_global_asm_80657974 has no documented signature
void func_global_asm_80657CB0(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 *arg6);
void func_global_asm_80657E24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 *arg8, s32 *arg9, s32 *argA, s32 *argB);
s32 func_global_asm_80657F14(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 *arg8, s32 *arg9, s32 *argA, s32 *argB);
u8 func_global_asm_80658000(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4);
// TODO: func_global_asm_80658134 has no documented signature
// TODO: func_global_asm_806582F8 has no documented signature
void func_global_asm_8065850C(f32 arg0[4][4], f32 arg1[4][4], s32 arg2, f32 arg3[4][4]);
void func_global_asm_80658624(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4);
void func_global_asm_806588E0(s32 fileIndex);
// TODO: func_global_asm_80658930 has no documented signature
s16 func_global_asm_80658B08(s8 arg0, u8 *arg1, s16 arg2);
void func_global_asm_80658BD0(void);
void func_global_asm_80658C10(s32 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_80658CCC(void);
u8 func_global_asm_80658DAC(s32 arg0);
void func_global_asm_80658E58(u16 arg0, u16 arg1, u16 arg2, u16 arg3);
// TODO: func_global_asm_80658E8C has no documented signature

// global_asm/done/code_5DE10.c
void func_global_asm_80659110(u8 arg0);
u8 func_global_asm_80659190(void);
Gfx *func_global_asm_8065919C(Gfx *dl);
Gfx *func_global_asm_806592B4(Gfx *dl);

// global_asm/done/code_5E020.c
void func_global_asm_80659320(void);
void func_global_asm_80659350(void);
void func_global_asm_806593C8(s32 arg0, s32 arg1);
s32 func_global_asm_80659470(s32 arg0);
void func_global_asm_806594C8(s32 arg0);
s32 func_global_asm_80659544(s32 arg0);
void func_global_asm_80659574(void);
void func_global_asm_806595B0(void);

// global_asm/code_5E2F0.c
void func_global_asm_806595F0(u8 arg0);
void func_global_asm_80659600(s16 arg0);
void func_global_asm_80659610(s16 arg0);
void func_global_asm_80659620(f32 *arg0, f32 *arg1, f32 *arg2, s16 arg3);
void func_global_asm_80659670(f32 arg0, f32 arg1, f32 arg2, s16 arg3);
void func_global_asm_8065996C(s16 arg0);
void func_global_asm_80659DB0(f32 arg0, f32 arg1, f32 arg2, s16 arg3);
// TODO: func_global_asm_80659F7C has no documented signature
void func_global_asm_8065A570(void);
void func_global_asm_8065A648(void);
void func_global_asm_8065A654(void);
void func_global_asm_8065A660(f32 arg0, f32 arg1);
void func_global_asm_8065A6F8(u16 arg0);
void createLight(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 radius, u8 arg7, u8 red, u8 green, u8 blue);
// TODO: func_global_asm_8065A884 has no documented signature
s16 func_global_asm_8065BAA0(f32 arg0, f32 arg1, s32 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s32 arg9, s8 *argA);
void func_global_asm_8065BE74(s16 arg0);
// TODO: func_global_asm_8065BF18 has no documented signature
// TODO: func_global_asm_8065C240 has no documented signature but has been matched
void func_global_asm_8065C334(f32 arg0, f32 arg1, f32 arg2, s16 arg3, s8 *arg4, s8 *arg5, s8 *arg6, s16 arg7);

// global_asm/code_61690.c
// TODO: func_global_asm_8065C990 has no documented signature

// global_asm/code_61AA0.c
void func_global_asm_8065CDA0(u8 arg0);
void func_global_asm_8065CDB0(Gfx *dl, Gfx *endDL);
void func_global_asm_8065CE4C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 *arg5);
f32 func_global_asm_8065CFB8(s16 arg0, f32 arg1);
Gfx *func_global_asm_8065D008(Gfx *dl, s16 arg1, u8 arg2);
f32 func_global_asm_8065D0FC(f32 arg0);
void func_global_asm_8065D170(void);
void func_global_asm_8065D1AC(void);
void func_global_asm_8065D244(u16 arg0);
void func_global_asm_8065D254(Actor *actor, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, f32 arg10);
// TODO: func_global_asm_8065D964 has no documented signature but has been matched
// TODO: func_global_asm_8065D994 has no documented signature
void func_global_asm_8065E040(s32 arg0);
s32 func_global_asm_8065E0CC(void);
void func_global_asm_8065E124(void);
// TODO: func_global_asm_8065E138 has no documented signature
// TODO: func_global_asm_8065E634 has no documented signature
s32 func_global_asm_8065E81C(s32 arg0, s32 arg1);
s32 func_global_asm_8065EA44(void);
s32 func_global_asm_8065EA98(s32 arg0, s16 arg1, u8 arg2);
void func_global_asm_8065EACC(void);
void func_global_asm_8065EAF4(void);

// global_asm/code_63810.c
// TODO: func_global_asm_8065EB10 has no documented signature
void func_global_asm_8065EFF0(void);
void func_global_asm_8065F134(s32 arg0, u8 arg1);

// global_asm/code_63EC0.c
// TODO: func_global_asm_8065F1C0 has no documented signature
void func_global_asm_8065F49C(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_8065F4F4(GlobalASMStruct58 *arg0);
u8 func_global_asm_8065F5F0(GlobalASMStruct58 *arg0);
void func_global_asm_8065F614(void);
void func_global_asm_8065F678(f32 arg0, f32 arg1, f32 arg2, u8 arg3);
void func_global_asm_8065F964(GlobalASMStruct58 *arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, f32 arg5[4][4], s32 arg6);
// TODO: func_global_asm_8065FB04 has no documented signature but has been matched
// TODO: func_global_asm_8065FB64 has no documented signature
// TODO: func_global_asm_8065FD88 has no documented signature
// TODO: func_global_asm_8065FEB8 has no documented signature but has been matched
// TODO: func_global_asm_80660070 has no documented signature
// TODO: func_global_asm_80660520 has no documented signature
// TODO: func_global_asm_80660830 has no documented signature
// TODO: func_global_asm_806608FC has no documented signature
// TODO: func_global_asm_80660D38 has no documented signature
s32 func_global_asm_8066104C(s32 arg0);
// TODO: func_global_asm_80661054 has no documented signature
void func_global_asm_80661264(s32 arg0, u8 arg1);
void func_global_asm_806612B4(s32 arg0, u8 arg1);
u8 func_global_asm_80661300(s32 arg0);
void func_global_asm_8066134C(s32 arg0, u8 arg1);
void func_global_asm_80661398(s32 arg0, f32 arg1, f32 arg2);
void func_global_asm_806613E8(s32 arg0, f32 arg1, f32 arg2);
void func_global_asm_80661440(f32 *arg0);
void func_global_asm_80661484(f32 *arg0);
f32 func_global_asm_806614D0(s32 arg0);
void func_global_asm_80661520(f32 x, f32 y, f32 z, f32 arg3, f32 arg4, f32 arg5);
void func_global_asm_806615BC(void);
void func_global_asm_8066164C(void);
void func_global_asm_80661658(u8 arg0);
// TODO: func_global_asm_806616A0 has no documented signature
// TODO: func_global_asm_806618A0 has no documented signature
// TODO: func_global_asm_80661AB4 has no documented signature but has been matched
void func_global_asm_80661B84(u8 arg0);
// TODO: func_global_asm_80661BF0 has no documented signature but has been matched
// TODO: func_global_asm_80661E34 has no documented signature but has been matched
void func_global_asm_80661EC4(u8 arg0);
Gfx *func_global_asm_80661F0C(Gfx *dl, s32 arg1, u8 arg2);
void func_global_asm_80662108(s32 arg0);
void func_global_asm_80662110(u8 arg0);
void func_global_asm_80662158(Gfx *dl, s32 arg1, u8 arg2);
void func_global_asm_80662180(s32 arg0);
void func_global_asm_80662188(u8 arg0);
Gfx *func_global_asm_806621D0(Gfx *dl, s32 arg1, u8 arg2);
void func_global_asm_806623CC(s32 arg0);
void func_global_asm_806623D4(u8 arg0);
// TODO: func_global_asm_8066241C has no documented signature but has been matched
void func_global_asm_806625D0(u8 arg0);
// TODO: func_global_asm_80662618 has no documented signature but has been matched
void func_global_asm_806627CC(u8 arg0);
// TODO: func_global_asm_80662838 has no documented signature
// TODO: func_global_asm_80662AB4 has no documented signature but has been matched

// global_asm/code_67890.c
// TODO: func_global_asm_80662B90 has no documented signature
s32 func_global_asm_80663040(s32 arg0);
void func_global_asm_8066308C(f32 arg0, f32 arg1, f32 arg2);
Gfx *func_global_asm_806634A4(Gfx *dl);
Gfx *func_global_asm_80663594(Gfx *dl, s32 arg1);

// global_asm/code_684C0.c
void func_global_asm_806637C0(MapGeometryHeader *arg0);
void func_global_asm_80663844(Actor *arg0);
s32 func_global_asm_806639CC(Actor *arg0, GlobalASMStruct83 *arg1);
// TODO: func_global_asm_80663A0C has no documented signature but has been matched
void func_global_asm_80663A80(void);
void func_global_asm_80663BE8(Actor *arg0);

// global_asm/done/code_68960.c
void func_global_asm_80663C60(f32 *arg0, s16 arg1);

// global_asm/code_68AA0.c
void func_global_asm_80663DA0(void);
u8 func_global_asm_80663FCC(s16 propIndex);
void func_global_asm_80664044(u8 arg0, u8 arg1, u8 arg2, f32 arg3);

// global_asm/done/code_68EA0.c
void func_global_asm_806641A0(void);
void func_global_asm_806643C4(s32 arg0, s32 arg1, f32 arg2);
void func_global_asm_806644B0(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void func_global_asm_806645B8(s16 arg0);
s32 func_global_asm_8066461C(s16 arg0);
void func_global_asm_8066466C(void);
void func_global_asm_80664834(s16 arg0);
void func_global_asm_80664A38(s16 arg0);

// global_asm/done/code_699B0.c
void func_global_asm_80664CB0(s16 arg0);
void func_global_asm_80664D20(void);

// global_asm/code_69E60.c
void func_global_asm_80665160(Actor *arg0, s16 arg1, s16 arg2);
void func_global_asm_806651FC(Actor *arg0);
void func_global_asm_806653C0(Actor *arg0, f32 arg1, f32 arg2);
void func_global_asm_80665548(void);
u8 func_global_asm_80665558(void);
void func_global_asm_80665564(Actor *arg0, f32 arg1);
u8 func_global_asm_80665AAC(Actor *arg0);
void func_global_asm_80665ACC(Actor *arg0);
f32 func_global_asm_80665AE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s16 func_global_asm_80665C18(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
s16 func_global_asm_80665DE0(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
f32 func_global_asm_80665E48(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
f32 func_global_asm_80665E94(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6);
LedgeInfo *func_global_asm_80665F24(Actor *arg0);
void func_global_asm_80665FB4(Actor *arg0);
void func_global_asm_80666090(MapGeometryHeader *arg0);

// global_asm/code_6AF80.c
void func_global_asm_80666280(u8 arg0);
void func_global_asm_80666290(Actor *arg0, void *arg1, void *arg2, void *arg3, void *arg4, u8 arg5);
u8 func_global_asm_8066635C(Actor *arg0, f32 x, f32 y, f32 z, f32 *arg4);
void func_global_asm_806663F8(void);
u8 func_global_asm_8066641C(void);
void func_global_asm_80666428(Actor *arg0, f32 x, f32 y, f32 z, void *arg4, void *arg5, void *arg6, void *arg7, u8 arg8);
u8 func_global_asm_80666A88(void);
u8 func_global_asm_80666A94(void);
u8 func_global_asm_80666AA0(void);
u8 func_global_asm_80666AAC(void);
u8 func_global_asm_80666AB8(void);
void func_global_asm_80666AC4(s16 *arg0, s16 *arg1);
u8 func_global_asm_80666AE0(void);
u8 func_global_asm_80666AEC(void);
void func_global_asm_80666AF8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5, u8 arg6);
void func_global_asm_80666D88(f32 arg0, f32 arg1, u8 arg2, Actor *arg3, u8 arg4);
s32 func_global_asm_80666F04(f32 arg0, f32 arg1, u8 arg2, u8 arg3);
s32 func_global_asm_80666FC8(f32 arg0, f32 arg1, f32 arg2, u8 arg3);
s32 func_global_asm_80667110(f32 arg0, f32 arg1, f32 *arg2);
u8 func_global_asm_8066715C(f32 *arg0);
u8 func_global_asm_80667174(void);
u8 func_global_asm_80667180(f32 arg0, f32 arg1, f32 *arg2, s32 arg3);
s32 func_global_asm_806672B8(f32 arg0, f32 arg1, f32 *arg2, s32 arg3);
f32 func_global_asm_8066785C(void *arg0, f32 arg1, f32 arg2);
u8 func_global_asm_806679BC(f32 arg0, f32 arg1, f32 *arg2);
s32 func_global_asm_80668520(f32 *arg0, f32 arg1, f32 arg2, f32 *arg3);
// TODO: func_global_asm_806685E0 has no documented signature but has been matched
void func_global_asm_806686F4(s32 arg0);
void func_global_asm_806687E0(void);
void func_global_asm_806688B8(s32 arg0);
// TODO: func_global_asm_8066893C has no documented signature but has been matched
// TODO: func_global_asm_806689F0 has no documented signature
// TODO: func_global_asm_80668B28 has no documented signature but has been matched
// TODO: func_global_asm_80668C30 has no documented signature
u8 func_global_asm_80668E9C(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5);
void func_global_asm_80669588(s32 arg0, f32 arg1);
s32 func_global_asm_80669650(u8 arg0, u8 *arg1);
// TODO: func_global_asm_806696A0 has no documented signature but has been matched
// TODO: func_global_asm_80669830 has no documented signature
s32 func_global_asm_80669930(f32[4][4]);
// TODO: func_global_asm_806699C4 has no documented signature but has been matched
void func_global_asm_80669A6C(Actor *arg0);
// TODO: func_global_asm_80669BE8 has no documented signature but has been matched
// TODO: func_global_asm_80669C6C has no documented signature but has been matched
// TODO: func_global_asm_80669CB4 has no documented signature but has been matched
// TODO: func_global_asm_80669E04 has no documented signature
// TODO: func_global_asm_8066A08C has no documented signature
void func_global_asm_8066A584(s32 arg0, f32 arg1);
// TODO: func_global_asm_8066A64C has no documented signature
// TODO: func_global_asm_8066A75C has no documented signature
// TODO: func_global_asm_8066A834 has no documented signature
// TODO: func_global_asm_8066A988 has no documented signature
// TODO: func_global_asm_8066AC10 has no documented signature
void func_global_asm_8066ACA4(s32 arg0, s32 arg1, s32 arg2);
void func_global_asm_8066ADA0(void);
void func_global_asm_8066AEE4(void *arg0, s32 arg1);
void func_global_asm_8066AF40(void);
s32 func_global_asm_8066B020(s32 pointerTableIndex, s32 fileIndex);
s32 func_global_asm_8066B06C(s32 pointerTableIndex, s32 fileIndex);
void func_global_asm_8066B0DC(void);
void func_global_asm_8066B0EC(s32 arg0);
void *getPointerTableFile(s32 pointerTableIndex, s32 fileIndex, u8 arg2, u8 arg3);
void func_global_asm_8066B424(void);
void func_global_asm_8066B434(void *arg0, s32 arg1, s32 arg2);
void func_global_asm_8066B4AC(s32 arg0, s32 arg1, s32 arg2);
s32 func_global_asm_8066B4D4(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3);
s32 func_global_asm_8066B5C8(s32 pointerTableIndex, s32 fileIndex);
void func_global_asm_8066B5F4(s32 pointerTableIndex);
// TODO: func_global_asm_8066B75C has no documented signature but has been matched
void func_global_asm_8066B7AC(s32 arg0, s32 arg1, s32 arg2);
// TODO: func_global_asm_8066B7F4 has no documented signature but has been matched
void func_global_asm_8066B8C8(u32 arg0, s32 pointerTableIndex, s32 arg2);
// TODO: func_global_asm_8066B924 has no documented signature but has been matched
s32 func_global_asm_8066B9F4(void *arg0);
void func_global_asm_8066BA2C(s32 arg0, u8 *arg1, u16 *arg2, s32 *arg3);
void func_global_asm_8066BAB8(s32 arg0, u8 arg1, u16 arg2);
// TODO: func_global_asm_8066BB44 has no documented signature but has been matched
void func_global_asm_8066BC00(s32 arg0, s32 arg1, s32 arg2);
// TODO: func_global_asm_8066BC5C has no documented signature but has been matched
// TODO: func_global_asm_8066BD54 has no documented signature but has been matched
void func_global_asm_8066BDE0(void);
void func_global_asm_8066BE20(s32 arg0);
// TODO: func_global_asm_8066BECC has no documented signature but has been matched
// TODO: func_global_asm_8066BF0C has no documented signature but has been matched
// TODO: func_global_asm_8066BFF0 has no documented signature
// TODO: func_global_asm_8066C0DC has no documented signature
u32 func_global_asm_8066C2B4(u32 arg0);

// global_asm/code_70FD0.c
// TODO: func_global_asm_8066C2D0 has no documented signature but has been matched
void func_global_asm_8066C610(s16 arg0, s8 arg1, f32 (*arg2)[4]);
// TODO: func_global_asm_8066C7F4 has no documented signature but has been matched
void func_global_asm_8066C8B0(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8);
void func_global_asm_8066C904(Prop_unk28 *arg0);
// TODO: func_global_asm_8066C958 has no documented signature
// TODO: func_global_asm_8066CB88 has no documented signature
// TODO: func_global_asm_8066CCD8 has no documented signature
void func_global_asm_8066CDD0(void);
void func_global_asm_8066CDF8(void);
// TODO: func_global_asm_8066CEE4 has no documented signature but has been matched
// TODO: func_global_asm_8066D250 has no documented signature but has been matched
// TODO: func_global_asm_8066D2F4 has no documented signature
// TODO: func_global_asm_8066D4DC has no documented signature
// TODO: func_global_asm_8066DB40 has no documented signature
// TODO: func_global_asm_8066DD34 has no documented signature
void func_global_asm_8066E21C(LedgeInfo *ledgeInfo);
// TODO: func_global_asm_8066E2C0 has no documented signature
void func_global_asm_8066E5CC(Actor *arg0, s32 arg1, u16 arg2);
void func_global_asm_8066E5F8(Actor *arg0, s32 arg1, u8 arg2);
void func_global_asm_8066E62C(Actor *arg0, s32 arg1, u8 arg2);
void func_global_asm_8066E664(Actor *arg0, s32 arg1, u8 arg2);
void func_global_asm_8066E6C8(Actor *arg0, s32 arg1, u8 arg2);
void func_global_asm_8066E72C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6, void *arg7, s32 arg8);
void func_global_asm_8066E854(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
void func_global_asm_8066E8E4(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
void func_global_asm_8066E990(Actor *arg0);
f32 func_global_asm_8066E9EC(Actor *arg0, s32 arg1, f32 arg2);
void func_global_asm_8066EA64(Actor *arg0, s32 arg1);
void func_global_asm_8066EA90(Actor *arg0, s32 arg1);
void func_global_asm_8066EABC(Actor *arg0);
LedgeInfo8C *func_global_asm_8066EAEC(Actor *arg0, s32 arg1);
void func_global_asm_8066EB40(Actor *arg0, f32 arg1);
void func_global_asm_8066EB50(Actor *actor, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_global_asm_8066EBF4(Actor *arg0);
void func_global_asm_8066EC6C(LedgeInfo *arg0);
// TODO: func_global_asm_8066EE50 has no documented signature but has been matched
void func_global_asm_8066F06C(LedgeInfo *arg0);
u8 func_global_asm_8066F1F8(Actor *arg0, s16 arg1);
u8 func_global_asm_8066F250(Actor *arg0, s16 *arg1, s16 *arg2, s8 *arg3);
u8 func_global_asm_8066F274(Actor *arg0, s16 *arg1, s16 *arg2, s8 *arg3);
void func_global_asm_8066F400(Actor *arg0);
// TODO: func_global_asm_8066F4AC has no documented signature
// TODO: func_global_asm_8066F84C has no documented signature
// TODO: func_global_asm_8066FC0C has no documented signature
s32 func_global_asm_8066FD6C(Actor *arg0);
// TODO: func_global_asm_8066FE08 has no documented signature
// TODO: func_global_asm_80670548 has no documented signature
// TODO: func_global_asm_80670C5C has no documented signature
void func_global_asm_80670F04(LedgeInfo *arg0);
u8 func_global_asm_80670FA4(Actor *arg0, s16 *arg1, s16 *arg2);
// TODO: func_global_asm_806710E0 has no documented signature
void func_global_asm_80671260(Actor *arg0);
// TODO: func_global_asm_806713E4 has no documented signature
// TODO: func_global_asm_80671528 has no documented signature
s32 func_global_asm_806717FC(Actor *arg0);
// TODO: func_global_asm_80671880 has no documented signature
// TODO: func_global_asm_80671A6C has no documented signature
u8 getBonePosition(Actor *actor, s32 boneIndex, f32 *x, f32 *y, f32 *z);
void func_global_asm_80671D10(Actor *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4);
// TODO: func_global_asm_80671D64 has no documented signature
// TODO: func_global_asm_80671E00 has no documented signature
// TODO: func_global_asm_80671F54 has no documented signature
s16 func_global_asm_80672134(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
// TODO: func_global_asm_80672328 has no documented signature
s32 func_global_asm_806725A0(Actor *arg0, s16 arg1);
s32 func_global_asm_806725E4(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s32 func_global_asm_80672630(Actor *arg0, s16 arg1, s16 arg2);
s32 func_global_asm_80672680(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16* arg4);
s32 func_global_asm_806726DC(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 *arg4, s16 arg5);
s32 func_global_asm_806728F0(s16 arg0, s16 arg1, s16 arg2);
s16 func_global_asm_80672A70(s16 arg0, s16 arg1);
void func_global_asm_80672AFC(Actor *actor);
void func_global_asm_80672B1C(Actor *actor);
u8 func_global_asm_80672BD4(Actor *arg0);
void func_global_asm_80672C30(Actor *arg0);
void func_global_asm_80672C70(s32 arg0);
s32 func_global_asm_80672CBC(s8 arg0);
void func_global_asm_80672E64(void);
void func_global_asm_80672E6C(void);

// global_asm/code_77B90.c
// TODO: func_global_asm_80672E90 has no documented signature
// TODO: func_global_asm_80672EBC has no documented signature
// TODO: func_global_asm_80672F94 has no documented signature
// TODO: func_global_asm_806730A4 has no documented signature
// TODO: func_global_asm_80673240 has no documented signature
// TODO: func_global_asm_806732A8 has no documented signature
// TODO: func_global_asm_80673324 has no documented signature
// TODO: func_global_asm_806734E4 has no documented signature
// TODO: func_global_asm_80673708 has no documented signature
// TODO: func_global_asm_806738D0 has no documented signature
// TODO: func_global_asm_806739D8 has no documented signature
// TODO: func_global_asm_80673A40 has no documented signature
// TODO: func_global_asm_80673A94 has no documented signature
// TODO: func_global_asm_80673B78 has no documented signature
// TODO: func_global_asm_80673C34 has no documented signature
// TODO: func_global_asm_80673D48 has no documented signature
// TODO: func_global_asm_80673FDC has no documented signature
// TODO: func_global_asm_80674080 has no documented signature
// TODO: func_global_asm_80674150 has no documented signature
// TODO: func_global_asm_806742C0 has no documented signature
// TODO: func_global_asm_80674330 has no documented signature
// TODO: func_global_asm_8067443C has no documented signature
// TODO: func_global_asm_806744A8 has no documented signature
// TODO: func_global_asm_8067457C has no documented signature
// TODO: func_global_asm_80674688 has no documented signature
// TODO: func_global_asm_8067470C has no documented signature
// TODO: func_global_asm_80674884 has no documented signature
// TODO: func_global_asm_80674A5C has no documented signature
// TODO: func_global_asm_80674ADC has no documented signature

// global_asm/code_79890.c
// TODO: func_global_asm_80674B90 has no documented signature
void func_global_asm_80674E14(Actor *arg0);
// TODO: func_global_asm_80675180 has no documented signature
f32 func_global_asm_80675234(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_global_asm_806752D4(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6);
void func_global_asm_80675380(Actor *arg0, Actor *arg1);
// TODO: func_global_asm_80675478 has no documented signature
void func_global_asm_806755A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

// global_asm/done/code_7A510.c
// TODO: func_global_asm_80675810 has no documented signature but has been matched
void func_global_asm_80675AFC(Actor *arg0, Actor *arg1);
s32 func_global_asm_80675C70(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_80675D70(Actor *arg0);
void func_global_asm_80675DD0(Actor *arg0, Actor *arg1);
// TODO: func_global_asm_80675E3C has no documented signature but has been matched
void func_global_asm_80675EE0(Actor *arg0);
void func_global_asm_8067605C(Actor *arg0, u8 arg1);
void func_global_asm_8067618C(Actor *arg0, u8 *arg1);
void func_global_asm_806761D0(Actor *arg0);
void func_global_asm_806761EC(Actor *arg0);
u8 func_global_asm_80676208(Actor *arg0);
s32 func_global_asm_80676220(s16 arg0);

// global_asm/done/code_7AF60.c
void func_global_asm_80676260(Actor *arg0, Actor *arg1, s32 arg2);
u8 func_global_asm_80676280(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2);
u8 func_global_asm_806762C0(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2);
u8 func_global_asm_80676308(Actor *arg0, Actor *arg1, s32 arg2);
u8 func_global_asm_80676338(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2);
u8 func_global_asm_8067641C(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2);
u8 func_global_asm_806764D8(Actor *arg0, Actor *arg1, Actor *arg2);
u8 func_global_asm_80676540(Actor *arg0, Actor *arg1, Actor *arg2);
u8 func_global_asm_80676590(Actor *arg0, Actor *arg1, s32 arg2);
u8 func_global_asm_806765E8(Actor *arg0, Actor *arg1, s32 arg2);
u8 func_global_asm_80676690(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2);
u8 func_global_asm_806766E0(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2);
u8 func_global_asm_80676730(s32 arg0, s32 arg1, Struct80676CB0 *arg2);
u8 func_global_asm_8067675C(s32 arg0, s32 arg1, Struct80676CB0 *arg2);
u8 func_global_asm_80676788(s32 arg0, s32 arg1, Struct80676CB0 *arg2);
u8 func_global_asm_806767B4(s32 arg0, s32 arg1, Struct80676CB0 *arg2);
u8 func_global_asm_806767E0(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2);
s32 func_global_asm_8067680C(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2);
int func_global_asm_806769A8(s32 arg0, Actor *arg1, s32 arg2);
int func_global_asm_80676A0C(s32 arg0, Actor *arg1, s32 arg2);
u8 func_global_asm_80676A70(s32 arg0, Actor *arg1, s32 arg2);
u8 func_global_asm_80676AB8(Actor *arg0, Actor *arg1, Actor *arg2);
u8 func_global_asm_80676B38(Actor *arg0, Actor *arg1, Actor *arg2);
u8 func_global_asm_80676B70(Actor *arg0, Actor *arg1, Actor *arg2);
u8 func_global_asm_80676BCC(s32 arg0, Actor *arg1, s32 arg2);
u8 func_global_asm_80676C10(s32 arg0, Actor *arg1, s32 arg2);
u8 func_global_asm_80676C64(s32 arg0, Actor *arg1, Struct80676CB0 *arg2);
u8 func_global_asm_80676CB0(Struct80676CB0 *arg0, u8 arg1);

// global_asm/done/code_7BA00.c
void func_global_asm_80676D00(Actor *arg0, Actor *arg1, s32 arg2, s32 arg3);

// global_asm/code_7BBD0.c
u8 func_global_asm_80676ED0(Actor *arg0, s16 *arg1, s16 *arg2);
// TODO: func_global_asm_80677148 has no documented signature
// TODO: func_global_asm_8067760C has no documented signature
// TODO: func_global_asm_806776A0 has no documented signature
s32 func_global_asm_80677CAC(s16 arg0, s16 arg1);
s32 func_global_asm_80677D58(Actor *arg0);

// global_asm/code_7CA80.c
void func_global_asm_80677D80(void);
void func_global_asm_80677EC8(s32 arg0);
// TODO: func_global_asm_80677ED0 has no documented signature but has been matched
s32 spawnActor(Actors actorIndex, s32 modelIndex);
s32 func_global_asm_80678014(s32 arg0);
s32 func_global_asm_80678050(u16);
s32 deleteActor(Actor*);
s32 func_global_asm_806782E8(Actor *arg0);
void func_global_asm_806783BC(void);
void func_global_asm_80678428(Actor *arg0);
void func_global_asm_80678458(Actor *arg0);
void func_global_asm_80678530(Actor *arg0);
void func_global_asm_806785D4(Actor *arg0);
void func_global_asm_806787CC(void);
void func_global_asm_806787EC(void);
void func_global_asm_806787F4(void);
void func_global_asm_806787FC(void);
void func_global_asm_80678804(void);
void func_global_asm_8067880C(void);
void func_global_asm_80678814(void);
void func_global_asm_8067881C(void);
// TODO: func_global_asm_80678824 has no documented signature
// TODO: func_global_asm_8067889C has no documented signature
// TODO: func_global_asm_806789E4 has no documented signature
void func_global_asm_80678B04(void);
void func_global_asm_80678BBC(Actor *arg0);
void func_global_asm_80678CC8(Actor *arg0);
void func_global_asm_80678DD8(Actor *arg0);
void func_global_asm_80678E14(Actor *arg0);
void func_global_asm_80678E6C(Actor *arg0);
void func_global_asm_80678F64(Actor *arg0);
void func_global_asm_80678F9C(Actor *arg0, s32 arg1);
s32 func_global_asm_80679010(Actor *arg0, Actor *arg1);
void func_global_asm_80679064(void *arg0);
void func_global_asm_806790F4(u8 arg0);
void func_global_asm_80679178(Actor *arg0);
void func_global_asm_806791DC(Actor *arg0, s32 arg1);
void func_global_asm_806791EC(Actor *arg0, s32 arg1);
void func_global_asm_80679200(Actor *arg0, Actor *arg1, s32 arg2, u8 arg3, s32 arg4, void *arg5);
void func_global_asm_80679290(Actor *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4, s32 arg5, s32 arg6);
// TODO: func_global_asm_80679334 has no documented signature
ActorCollision *func_global_asm_80679490(Actor *arg0, s32 arg1, u8 arg2, s32 arg3, void *arg4);
// TODO: func_global_asm_806794EC has no documented signature
void func_global_asm_80679DC4(Actor *arg0, Actor *arg1, u8 arg2);
// TODO: func_global_asm_8067A09C has no documented signature but has been matched
void func_global_asm_8067A170(Actor *arg0, u8 arg1);
void func_global_asm_8067A1DC(Actor *arg0);
void func_global_asm_8067A69C(Actor *arg0, Actor *arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5);
void func_global_asm_8067A70C(Actor *arg0, Actor *arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, u8 arg6);
void func_global_asm_8067A784(Actor *arg0, Actor *arg1, s16 arg2, f32 arg3, s16 arg4);
void func_global_asm_8067A7EC(Actor *arg0, Actor *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, u8 arg6);
void func_global_asm_8067A864(Actor *arg0, Actor *arg1, s16 arg2, s16 arg3, void *arg4, void *arg5, s32 arg6, s32 arg7, s32 arg8);
void func_global_asm_8067A908(Actor *arg0, Actor *arg1, void *arg2, void *arg3, s32 arg4, s32 arg5, s32 arg6);
void func_global_asm_8067A99C(Actor *arg0, Actor *arg1, s32 arg2);
void func_global_asm_8067A9F0(Actor *arg0, Actor *arg1, f32 arg2, f32 arg3, f32 arg4);
void func_global_asm_8067AA58(Actor *arg0, Actor *arg1, f32 arg2, f32 arg3);
void func_global_asm_8067AAB8(Actor *arg0, Actor *arg1, s16 arg2, f32 arg3, s16 arg4);
void func_global_asm_8067AB20(Actor *arg0, Actor *arg1, s32 arg2, u8 arg3, void *arg4, u8 arg5);
void func_global_asm_8067ABC0(Actor *arg0, Actor *arg1, u8 arg2, s16 arg3, s16 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_global_asm_8067AC38(void);
void func_global_asm_8067ACB4(Actor *arg0);
u16 func_global_asm_8067ACC0(u16 index);
s32 func_global_asm_8067ACDC(Actor *arg0, u16 arg1, s32 (*arg2)(Actor *));
Actor *func_global_asm_8067ADB4(u16);
s32 func_global_asm_8067AE0C(Actor *arg0);
void func_global_asm_8067AE58(void);
void func_global_asm_8067AE90(Actor *arg0);
void func_global_asm_8067AEFC(Actor *arg0);
s32 func_global_asm_8067AF44(Actor *arg0);
s16 func_global_asm_8067AF74(Actor *arg0);
void func_global_asm_8067B01C(void);
void func_global_asm_8067B100(Actor *player);
u8 func_global_asm_8067B1E0(Actor *arg0);
void moveAndScaleActorToAnother(Actor *destination, Actor *source, f32 scale);
void func_global_asm_8067B280(void);
void func_global_asm_8067B288(void);
void func_global_asm_8067B290(void);
void func_global_asm_8067B298(void);
void func_global_asm_8067B2A0(void);
void func_global_asm_8067B2A8(void);
void func_global_asm_8067B2B0(s32 arg0);
void func_global_asm_8067B2B8(s32 arg0);
s32 func_global_asm_8067B2C0(s32 arg0);
s32 func_global_asm_8067B2DC(ActorSpawner *arg0);
s32 func_global_asm_8067B3F4(s32 arg0);
s32 func_global_asm_8067B42C(s32 arg0);

// global_asm/code_80150.c
// TODO: func_global_asm_8067B450 has no documented signature
// TODO: func_global_asm_8067B4C8 has no documented signature
void func_global_asm_8067BA3C(void);
// TODO: func_global_asm_8067BA7C has no documented signature
void func_global_asm_8067BC68(void);
void func_global_asm_8067BC88(void);
void func_global_asm_8067BCA8(void);
void func_global_asm_8067BCC8(void);
void func_global_asm_8067BCE8(void);
void func_global_asm_8067BD08(void);
void func_global_asm_8067BD28(void);
void func_global_asm_8067BDB8(void);
void func_global_asm_8067BDF8(void);
// TODO: func_global_asm_8067BE30 has no documented signature
void func_global_asm_8067BF4C(void);
u8 func_global_asm_8067BF84(s16 arg0, u8 *arg1, u8 *arg2, u8 *arg3);
void func_global_asm_8067C2B8(void);
void func_global_asm_8067C67C(void);
void func_global_asm_8067C69C(void);
void func_global_asm_8067C6BC(void);
void func_global_asm_8067C6DC(void);
void func_global_asm_8067C6FC(void);
// TODO: func_global_asm_8067C71C has no documented signature
void func_global_asm_8067DCC0(void);
void func_global_asm_8067DF44(f32 x, f32 y, f32 z, f32 arg3, u8 arg4, u8 arg5);
void func_global_asm_8067E278(u8 arg0, u8 arg1);
void func_global_asm_8067E2E4(Actor *arg0, u8 arg1, f32 arg2);
void func_global_asm_8067E348(void);
void func_global_asm_8067E3D0(void);
void func_global_asm_8067E43C(void);
void func_global_asm_8067E4D4(void);
void func_global_asm_8067E510(void);
void func_global_asm_8067E69C(void);
void func_global_asm_8067E6C4(void);
void func_global_asm_8067E6E4(void);
void func_global_asm_8067E704(void);
void func_global_asm_8067E724(void);
void func_global_asm_8067E764(void);
// TODO: func_global_asm_8067E784 has no documented signature
void func_global_asm_8067FAC8(void);
// TODO: func_global_asm_8067FB6C has no documented signature
void func_global_asm_80680774(void);
void func_global_asm_8068086C(void);
u8 func_global_asm_80680908(void);
// TODO: func_global_asm_806809F0 has no documented signature
void func_global_asm_80681B14(void);
void func_global_asm_80681BD8(void);
void func_global_asm_80681E18(void);
// TODO: func_global_asm_806822FC has no documented signature
// TODO: func_global_asm_80682AB4 has no documented signature
// TODO: func_global_asm_80682DF4 has no documented signature
// TODO: func_global_asm_80682E38 has no documented signature but has been matched
void func_global_asm_8068304C(void);
void func_global_asm_80683158(void);
s32 func_global_asm_806832F4(Actors arg0, s32 arg1);
// TODO: func_global_asm_806833DC has no documented signature
// TODO: func_global_asm_806836D0 has no documented signature
// TODO: func_global_asm_80683A80 has no documented signature
Gfx *func_global_asm_80683AD8(Gfx *dl, Actor *arg1);
void func_global_asm_8068408C(Actor *arg0);
void func_global_asm_8068412C(void);
void func_global_asm_806844EC(void);
void func_global_asm_8068450C(void);
void func_global_asm_8068452C(void);

// global_asm/code_89250.c
void func_global_asm_80684550(Actor* actor, u8 boneIndex, f32 scale);
void func_global_asm_806845B8(u8 arg0, u8 arg1);
void func_global_asm_806846B4(f32 xPosition, f32 yPosition, f32 zPosition, f32 xzScale, f32 yScale, Actor *arg5, u8 arg6);
void func_global_asm_80684850(u8 arg0);
void func_global_asm_80684900(u8 arg0);
void func_global_asm_80684A00(s16 arg0, s8 arg1);
void func_global_asm_80684BB0(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_80684D98(u8 arg0);
void func_global_asm_80685020(u8 arg0, u8 arg1);
void func_global_asm_806850D0(void);
void func_global_asm_80685210(f32 arg0, s16 arg1, s16 arg2);
void func_global_asm_806852C4(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_80685390(void);
void func_global_asm_80685520(f32 arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_global_asm_80685708(Actor *arg0, u8 arg1);
void func_global_asm_8068581C(Actor *actor, s16 boneIndex, f32 scale, f32 x, f32 y, f32 z, s32 arg6);
void func_global_asm_8068588C(Actor *actor, s16 boneIndex, f32 scale, f32 x, f32 y, f32 z, s32 arg6);
void func_global_asm_806858E8(Actor *actor, s16 boneIndex, f32 scale, f32 x, f32 y, f32 z, s32 arg6);
void func_global_asm_80685984(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_80685B44(void *arg0, u8 arg1, f32 arg2, u8 arg3, u8 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8);
void func_global_asm_80685D84(Actor *arg0);
void func_global_asm_80685E78(Actor *arg0);
void func_global_asm_80685F60(Actor *actor);
void func_global_asm_8068613C(Actor *arg0);
void func_global_asm_80686340(void);
void func_global_asm_80686390(Actor *actor, f32 arg1, f32 x, f32 y, f32 z);
void func_global_asm_8068696C(Actor *arg0);
void func_global_asm_80686A5C(Actor *arg0, f32 arg1, f32 arg2, s32 arg3);
void func_global_asm_80686CF8(Actor *actor);
void func_global_asm_80686E40(f32 x, f32 y, f32 z, s32 arg3);
void func_global_asm_80686F90(u8 arg0, s16 arg1, s16 arg2);
void func_global_asm_80687080(void);
void func_global_asm_806871DC(u8 arg0);
void func_global_asm_80687400(void);
void func_global_asm_80687474(Actor *arg0, f32 arg1);
void func_global_asm_806874EC(void);
void func_global_asm_806877C8(u8 arg0);
void func_global_asm_8068780C(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_global_asm_80687C48(void);
void func_global_asm_80687CC8(void);

// global_asm/code_8CA50.c
// TODO: func_global_asm_80687D50 has no documented signature
Gfx *func_global_asm_80687EE0(Gfx *dl, Actor *arg1);
void func_global_asm_80687F7C(Actor *actor);
void func_global_asm_80687FC8(GlobalASMStruct60 *arg0);
s32 func_global_asm_806882DC(Actor *actor, s32 arg1, s16 arg2);
void func_global_asm_80688320(Actor *actor, s32 arg1, s16 arg2, void *arg3);
void func_global_asm_80688370(Actor *actor, s32 arg1, f32 arg2);
void func_global_asm_8068839C(Actor *actor, s32 arg1, u8 arg2);
void func_global_asm_806883C8(Actor *actor, s32 arg1, u8 arg2);
void func_global_asm_806883F4(Actor *actor, s32 arg1, s16 arg2, f32 arg3);
void func_global_asm_8068842C(Actor *actor, s32 arg1, s16 arg2);
void func_global_asm_80688460(Actor *actor, s32 arg1, u8 arg2);
void func_global_asm_8068848C(Actor *actor, s32 arg1, s16 arg2);
void func_global_asm_806884B8(Actor *actor, s32 arg1, s16 arg2);
void func_global_asm_806884E4(Actor *actor, s32 arg1);
void func_global_asm_80688514(Actor *actor, s32 arg1);
s32 func_global_asm_80688540(Actor *actor, s32 arg1);
GlobalASMStruct60 *func_global_asm_80688584(Actor *arg0, s32 arg1);
void func_global_asm_80688638(GlobalASMStruct60 **arg0);

// global_asm/code_8D3E0.c
// TODO: func_global_asm_806886E0 has no documented signature
void func_global_asm_80688940(void);
void func_global_asm_80688A6C(void);
s16 func_global_asm_80688C30(u16 arg0);
u16 func_global_asm_80688C84(u16 arg0);
void func_global_asm_80688CC4(Actor *arg0, s16 arg1, f32 arg2);
void func_global_asm_80688CF4(Actor *arg0, s16 arg1, s32 arg2);
// TODO: func_global_asm_80688D20 has no documented signature
s32 func_global_asm_80688E08(void);
s16 func_global_asm_80688E68(Actor *arg0);
Actor *func_global_asm_80688EA4(s16 id);
void func_global_asm_80688EE4(s16 id, f32 x, f32 y, f32 z);
void func_global_asm_80688F74(Actor *arg0, f32 x, f32 y, f32 z);
// TODO: func_global_asm_80688FC0 has no documented signature
void func_global_asm_80689064(s16 arg0, f32 x, f32 y, f32 z, s16 arg4, f32 arg5);
void func_global_asm_80689114(s16 arg0, f32 x, f32 y, f32 z, s16 arg4, f32 arg5, Actor *arg6);
void func_global_asm_806891D8(s16 arg0, f32 x, f32 y, f32 z, s16 arg4, f32 arg5, Actor *arg6, Struct807500B4 *arg7);
ActorSpawner *func_global_asm_80689250(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, f32 arg5, void *arg6, u8 arg7, Actor *arg8, s16 arg9);
void func_global_asm_80689418(void);
void func_global_asm_806896D0(ActorSpawner *arg0);
void func_global_asm_806896F0(ActorSpawner *arg0);
void func_global_asm_80689710(ActorSpawner *arg0, u8 arg1);
void func_global_asm_806897F0(Actor *arg0);
void func_global_asm_806898A8(void);
s32 func_global_asm_806898F8(void);
void func_global_asm_80689958(s32 *arg0);
void func_global_asm_80689A80(s16 arg0, void *arg1);
u8 func_global_asm_80689B10(s16 arg0, u8 arg1, u8 arg2);
s32 func_global_asm_80689BAC(s16 arg0);
// TODO: func_global_asm_80689C20 has no documented signature
f32 func_global_asm_80689DD4(f32 x, f32 y, f32 z);
s32 func_global_asm_80689E98(s32 arg0);
void func_global_asm_80689EA4(ActorSpawner *spawner);
u8 func_global_asm_80689EE4(ActorSpawner *spawner);
s32 func_global_asm_80689F2C(void);
u8 func_global_asm_80689F80(ActorSpawner *spawner);
u8 func_global_asm_80689FEC(ActorSpawner *spawner);
u8 func_global_asm_8068A074(ActorSpawner *spawner);
s32 func_global_asm_8068A10C(s32 arg0);
u8 func_global_asm_8068A118(ActorSpawner *arg0);
u8 func_global_asm_8068A164(ActorSpawner *spawner);
void func_global_asm_8068A1B8(void);
void func_global_asm_8068A1CC(s16 arg0);
void func_global_asm_8068A20C(s16 arg0);
s32 func_global_asm_8068A24C(ActorSpawner *spawner);
s32 func_global_asm_8068A2AC(ActorSpawner *spawner);
void func_global_asm_8068A2FC(Actor *actor);

// global_asm/code_8F050.c
void func_global_asm_8068A350(Actor *arg0, s32 arg1, s32 arg2);
// TODO: func_global_asm_8068A3A0 has no documented signature
void func_global_asm_8068A404(Actor *arg0, s32 arg1, s32 arg2);
void func_global_asm_8068A4C8(Actor *arg0, s32 arg1, s32 arg2);
// TODO: func_global_asm_8068A508 has no documented signature
void func_global_asm_8068A764(Actor *arg0, u8 arg1);
void func_global_asm_8068A784(Actor *arg0, u8 arg1);

// global_asm/code_8F4B0.c
void func_global_asm_8068A7B0(void); // spawnPersistentActors()
void func_global_asm_8068A810(void);
void func_global_asm_8068A830(void);
// TODO: func_global_asm_8068A858 has no documented signature
s32 func_global_asm_8068ABE0(s16 arg0);
// TODO: func_global_asm_8068AD7C has no documented signature
void func_global_asm_8068B80C(void);
void func_global_asm_8068B81C(void);
void func_global_asm_8068B830(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_8068B8A4(f32 arg0);
void func_global_asm_8068B8FC(void);
void func_global_asm_8068B930(void);
void func_global_asm_8068B9B4(void);
void func_global_asm_8068BA2C(void);
// TODO: func_global_asm_8068BBF8 has no documented signature
void func_global_asm_8068C080(void);
void func_global_asm_8068C0B4(void);
void *func_global_asm_8068C12C(u16 textureIndex);
// TODO: func_global_asm_8068C20C has no documented signature
void func_global_asm_8068C2EC(void);
void func_global_asm_8068C2F8(Actor *arg0);
void addActorToTextOverlayRenderArray(void *arg0, Actor *arg1, u8 arg2);

// global_asm/code_910A0.c
Gfx *func_global_asm_8068C3A0(Gfx *dl, s32 arg1, s16 x, s16 y, s16 arg4);
Gfx *displayImage(Gfx *dl, u16 textureIndex, s32 arg3, s32 codec, s32 width, s32 height, s16 x, s16 y, f32 xScale, f32 yScale, s32 arg11, f32 arg12);
Gfx *func_global_asm_8068D264(Gfx *dl, f32 *arg1);
void func_global_asm_8068D8C8(Gfx *dl, s32 arg1);
// TODO: func_global_asm_8068D9DC has no documented signature
Gfx *func_global_asm_8068DAF4(Gfx *dl, u8 *arg1);
// TODO: func_global_asm_8068DBA4 has no documented signature
// TODO: func_global_asm_8068DC54 has no documented signature
Gfx *func_global_asm_8068E474(Gfx *dl, Actor *arg1);
Gfx *func_global_asm_8068E7B4(Gfx *dl, f32 arg1, f32 arg2, s32 seconds);

// global_asm/code_936B0.c
void func_global_asm_8068E9B0(Actor **arg0);
void func_global_asm_8068EA38(Actor **arg0);
// TODO: func_global_asm_8068EB3C has no documented signature but has been matched
void func_global_asm_8068ECF4(s32 arg0, u8 arg1);
// TODO: func_global_asm_8068EF54 has no documented signature
// TODO: func_global_asm_8068F72C has no documented signature
// TODO: func_global_asm_8068FF40 has no documented signature but has been matched
void func_global_asm_80690058(Actor *arg0, s32 arg1);
void func_global_asm_80690094(Actor *arg0, Actor *arg1);
// TODO: func_global_asm_80690190 has no documented signature but has been matched
void func_global_asm_806903BC(Actor *actor, RaceAdditionalActorData *arg1);
void func_global_asm_80690470(Actor *arg0);
void func_global_asm_80690500(void);
void func_global_asm_806907B8(void);
void func_global_asm_806907E0(void);
void func_global_asm_806907F0(f32 x, f32 y, f32 z);
void func_global_asm_80690814(Actor *arg0, s32 arg1);
void func_global_asm_8069084C(s16 arg0, s16 arg1, f32 arg2, s16 arg3, f32 arg4, f32 arg5, Actor *arg6);
void func_global_asm_80690930(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, Actor *arg8);
void func_global_asm_80690A28(s16 arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Actor *arg7);
void func_global_asm_80690AB0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, Actor *arg9);
void func_global_asm_80690BE8(s16 arg0, s16 arg1, f32 arg2, Actor *arg3, s32 arg4, f32 arg5, Actor *arg6);
// TODO: func_global_asm_80690C60 has no documented signature
// TODO: func_global_asm_80690F30 has no documented signature
void func_global_asm_806915B0(void);
void func_global_asm_80691830(s16 arg0, f32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
void func_global_asm_80691930(u8 arg0, u8 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5);
// TODO: func_global_asm_806919E0 has no documented signature
void func_global_asm_806921DC(u8 arg0);
void func_global_asm_80692500(void);
void func_global_asm_80692520(void);
void func_global_asm_80692540(void);
void func_global_asm_80692564(void);
void func_global_asm_80692588(void);
void func_global_asm_806925AC(void);
void func_global_asm_80692640(void);
void func_global_asm_80692940(void);
void func_global_asm_80692E50(void);
void func_global_asm_8069329C(void);
// TODO: func_global_asm_8069346C has no documented signature
void func_global_asm_80693EC0(void);
void func_global_asm_806944BC(void);
// TODO: func_global_asm_80694948 has no documented signature
void func_global_asm_80694D20(void);
s32 func_global_asm_806951B0(Actor *arg0);
// TODO: func_global_asm_806951E8 has no documented signature
void func_global_asm_80695724(f32 arg0, u8 arg1);
void func_global_asm_80695B50(void);
void func_global_asm_80695BAC(void);
void func_global_asm_806960A4(void);
void func_global_asm_80696574(void);
void func_global_asm_80696A6C(void);
void func_global_asm_806970CC(void);
void func_global_asm_80697184(void);

// global_asm/code_9BF30.c
// TODO: func_global_asm_80697230 has no documented signature
void func_global_asm_806978FC(void);
// TODO: func_global_asm_80697988 has no documented signature
void func_global_asm_80697CEC(void);

// global_asm/code_9CE20.c
void func_global_asm_80698120(u8 arg0);
void func_global_asm_80698FEC(void);
void func_global_asm_8069900C(void);
void func_global_asm_8069902C(void);
void func_global_asm_8069904C(void);

// global_asm/code_9DD70.c
void func_global_asm_80699070(s16 *arg0, s16 *arg1, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2);
// TODO: func_global_asm_80699128 has no documented signature but has been matched
void func_global_asm_80699284(void);
void func_global_asm_806998C8(void);
void func_global_asm_806998E8(void);
void func_global_asm_806998F0(void);
void func_global_asm_80699914(void);
// TODO: func_global_asm_80699958 has no documented signature
// TODO: func_global_asm_8069A614 has no documented signature
// TODO: func_global_asm_8069A750 has no documented signature
// TODO: func_global_asm_8069A7C8 has no documented signature
// TODO: func_global_asm_8069AB74 has no documented signature
void func_global_asm_8069AFF0(void);
// TODO: func_global_asm_8069B010 has no documented signature
void func_global_asm_8069B3FC(void);
s32 func_global_asm_8069B85C(void);
// TODO: func_global_asm_8069B908 has no documented signature
void func_global_asm_8069CD9C(void);
void func_global_asm_8069CF54(void);
void func_global_asm_8069D018(void);
void func_global_asm_8069D058(void);
void func_global_asm_8069D078(void);
void func_global_asm_8069D098(void);
void func_global_asm_8069D0B8(void);
void func_global_asm_8069D0D8(void);
void func_global_asm_8069D0F8(u8 arg0, s16 arg1, s16 arg2, char *arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7);
void func_global_asm_8069D2AC(u8 arg0, s16 arg1, s16 arg2, char *arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7);
Gfx *func_global_asm_8069D358(Gfx *dl, Actor *arg1, s16 xOffset, f32 scale);
Gfx *func_global_asm_8069D424(Gfx *dl, Actor *arg1);
Gfx *func_global_asm_8069D930(Gfx *dl, Actor *arg1);
void func_global_asm_8069DA54(void);
// TODO: func_global_asm_8069DC10 has no documented signature
void *func_global_asm_8069DC80(u8 arg0, void *arg1, u8 arg2, u8 arg3, u8 arg4);
void func_global_asm_8069DD40(void);
void func_global_asm_8069DF58(void);
void func_global_asm_8069E018(void);
void func_global_asm_8069E040(void);
void func_global_asm_8069E088(void);

// global_asm/code_A2F10.c
// TODO: func_global_asm_8069E210 has no documented signature
void func_global_asm_8069E490(u16 arg0, s16 arg1);
void func_global_asm_8069E4E0(s16 arg0);
void func_global_asm_8069E5B8(void);
int func_global_asm_8069E660(Actor *arg0, f32 arg1, f32 arg2);
s32 func_global_asm_8069E724(Actors actorBehaviourIndex);
void func_global_asm_8069E774(void);
s32 func_global_asm_8069EF50(s16 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);
void func_global_asm_8069F020(void);
void func_global_asm_8069F904(Gfx *dl, Actor *arg1);
Gfx *func_global_asm_8069FA40(Gfx *dl, Actor *arg1);
// TODO: func_global_asm_8069FDA0 has no documented signature
void func_global_asm_806A018C(void);
void func_global_asm_806A02F0(void);
void func_global_asm_806A0310(void);
void func_global_asm_806A0330(void);
void func_global_asm_806A05D4(void);
void func_global_asm_806A05FC(void);
void func_global_asm_806A081C(Actor *arg0);
void func_global_asm_806A0864(void);
void func_global_asm_806A0B74(void);
void func_global_asm_806A0F78(Actor *arg0, u8 arg1, u8 arg2);
void func_global_asm_806A1008(u8 arg0, u8 arg1);
// TODO: func_global_asm_806A10BC has no documented signature
// TODO: func_global_asm_806A112C has no documented signature

// global_asm/done/code_A6280.c
void func_global_asm_806A1580(void);
void func_global_asm_806A18A8(void);
void func_global_asm_806A1ABC(void);
void func_global_asm_806A1AC4(void);
void func_global_asm_806A1F28(void);
void func_global_asm_806A1F64(void);
void func_global_asm_806A1FD0(void);
void func_global_asm_806A1FD8(void);
void func_global_asm_806A2328(void);
void func_global_asm_806A285C(void);

// global_asm/code_A7710.c
// TODO: func_global_asm_806A2A10 has no documented signature
void func_global_asm_806A2B08(Actor *arg0);
void func_global_asm_806A2B20(Actor *arg0);
// TODO: func_global_asm_806A2B38 has no documented signature
void func_global_asm_806A2B80(Actor *arg0);
Gfx *func_global_asm_806A2B90(Gfx *dl, Actor *arg1);
void func_global_asm_806A2E30(void);
void func_global_asm_806A36F4(void);

// global_asm/code_A8400.c
void func_global_asm_806A3700(s32 arg0, s32 arg1);
// TODO: func_global_asm_806A370C has no documented signature
void func_global_asm_806A3B78(s32 *arg0, AAD_global_asm_806A4DDC *arg1, Struct806A57C0_2 *arg2, u8 arg3, u8 *arg4);
Gfx *func_global_asm_806A3C6C(Gfx *dl, s32 arg1, u8 arg2, s32 arg3);
// TODO: func_global_asm_806A3DA0 has no documented signature but has been matched
// TODO: func_global_asm_806A3E9C has no documented signature
Gfx *func_global_asm_806A4284(Gfx *dl, Actor *arg1);
// TODO: func_global_asm_806A495C has no documented signature
// TODO: func_global_asm_806A4B84 has no documented signature
// TODO: func_global_asm_806A4DDC has no documented signature
void func_global_asm_806A5174(Actor *arg0, void *arg1, f32 arg2);
void func_global_asm_806A57C0(AAD_global_asm_806A4DDC *arg0);
void func_global_asm_806A5868(void);
void func_global_asm_806A5C60(Actor *arg0);

// global_asm/done/code_AAAF0.c
void func_global_asm_806A5DF0(s16 arg0, f32 x, f32 y, f32 z, s16 arg4, u8 arg5, s16 arg6, s32 arg7);
// TODO: func_global_asm_806A5EAC has no documented signature but has been matched
void func_global_asm_806A5F44(void);
void func_global_asm_806A5FA4(void);
void func_global_asm_806A6004(void *arg0, Actors arg1);
void func_global_asm_806A6094(void);
void func_global_asm_806A60BC(void);
void func_global_asm_806A60E4(void);
void func_global_asm_806A610C(void);
void func_global_asm_806A6134(void);
void func_global_asm_806A615C(void);
void func_global_asm_806A61D0(void);
void func_global_asm_806A6230(void);
void func_global_asm_806A62B4(void);
void func_global_asm_806A62D4(void);
void func_global_asm_806A6348(void);
void func_global_asm_806A63A8(void);
void func_global_asm_806A6408(void);
void func_global_asm_806A6468(void);
void func_global_asm_806A6574(void);
void func_global_asm_806A664C(f32 arg0);
void func_global_asm_806A6DB4(u8 arg0);
void func_global_asm_806A734C(void);
void func_global_asm_806A736C(void);
void func_global_asm_806A7518(void);
void func_global_asm_806A7600(void *arg0);
void func_global_asm_806A7B04(void);
void func_global_asm_806A7B28(void);
void func_global_asm_806A7B4C(void);
void func_global_asm_806A7B70(void);
void func_global_asm_806A7B94(void);
void func_global_asm_806A7BB8(void);
void func_global_asm_806A7BDC(void);
void func_global_asm_806A7EF0(void);
void func_global_asm_806A8070(void);

// global_asm/code_ACDC0.c
s32 func_global_asm_806A80C0(s8 arg0);
// TODO: func_global_asm_806A8158 has no documented signature
// TODO: func_global_asm_806A9124 has no documented signature
Gfx *func_global_asm_806A921C(Gfx *dl);
// TODO: func_global_asm_806A92B4 has no documented signature
Gfx *func_global_asm_806AA09C(s16 x, s16 y, s16 arg2, s16 arg3, Gfx *dl, s8 arg5, f32 scale);
// TODO: func_global_asm_806AA304 has no documented signature
// TODO: func_global_asm_806AB4EC has no documented signature
// TODO: func_global_asm_806AB808 has no documented signature
// TODO: func_global_asm_806ABA6C has no documented signature
Gfx *printText(Gfx *dl, s16 x, s16 y, f32 scale, char *string);
// TODO: func_global_asm_806ABC94 has no documented signature
void func_global_asm_806ABE3C(void);
Gfx *func_global_asm_806AC048(Gfx *dl, Actor *arg1);
// TODO: func_global_asm_806AC07C has no documented signature
Gfx *func_global_asm_806ACA88(Gfx *dl, Actor *arg1);
void func_global_asm_806ACC00(u8 arg0);
void func_global_asm_806ACC64(void);
void func_global_asm_806ACCE8(void);
Gfx *func_global_asm_806ACF10(Gfx* dl, Actor *arg1);
// TODO: func_global_asm_806ACFFC has no documented signature

// global_asm/done/code_B1F60.c
void func_global_asm_806AD260(s16 arg0, u8 arg1, s32 arg2);
void func_global_asm_806AD54C(void);
void func_global_asm_806AD7AC(void);
void func_global_asm_806AD84C(void);
void func_global_asm_806AD9AC(void);
void func_global_asm_806AD9F4(void);
void func_global_asm_806ADDD8(void);

// global_asm/code_B2CE0.c
void func_global_asm_806ADFE0(void);
void func_global_asm_806AE2B0(s32 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_806AE394(f32 arg0, f32 arg1);
// TODO: func_global_asm_806AE588 has no documented signature
void func_global_asm_806AEE08(void);
// TODO: func_global_asm_806AEE84 has no documented signature
void func_global_asm_806AF688(void);
void func_global_asm_806AFA60(u8 arg0);
// TODO: func_global_asm_806AFB58 has no documented signature
void func_global_asm_806B02EC(void);
void func_global_asm_806B0354(void);
s32 func_global_asm_806B0770(void);
// TODO: func_global_asm_806B0848 has no documented signature

// global_asm/code_B5EC0.c
void func_global_asm_806B11C0(u8 arg0);
void func_global_asm_806B1290(void);
void func_global_asm_806B1348(void);
void func_global_asm_806B13B4(u8 arg0);
void func_global_asm_806B1D78(u8 arg0);
void func_global_asm_806B1DD4(u8 arg0);
void func_global_asm_806B1EA8(void);
void func_global_asm_806B1EC8(void);
void func_global_asm_806B1EE8(void);
void func_global_asm_806B1F08(void);
void func_global_asm_806B1F28(void);

// global_asm/done/code_B6C50.c
void func_global_asm_806B1F50(void);
void func_global_asm_806B24B8(void);

// global_asm/code_B7490.c
void func_global_asm_806B2790(void);
void func_global_asm_806B2D5C(void);
// TODO: func_global_asm_806B2D64 has no documented signature
void func_global_asm_806B3420(void);
void func_global_asm_806B3680(void);
void func_global_asm_806B3C30(u8 arg0);
void func_global_asm_806B3C94(void);
void func_global_asm_806B3D18(void);
void func_global_asm_806B3DA4(void);
void func_global_asm_806B3E08(void);
void func_global_asm_806B3E7C(void);
void func_global_asm_806B3F3C(void);
// TODO: func_global_asm_806B3F90 has no documented signature but has been matched
void func_global_asm_806B4194(void);
void func_global_asm_806B42A8(int (*arg0)(), u16 arg1, u16 arg2, s16 arg3);
void func_global_asm_806B486C(void);
void func_global_asm_806B48B8(void);
void func_global_asm_806B4904(void);
void func_global_asm_806B4958(void);
void func_global_asm_806B49B0(u8 arg0, s16 arg1, s16 arg2);
void func_global_asm_806B4DCC(void);
void func_global_asm_806B50F4(void);
void func_global_asm_806B513C(void);
void func_global_asm_806B52DC(void);
void func_global_asm_806B54BC(void);

// global_asm/code_BA790.c
// TODO: func_global_asm_806B5A90 has no documented signature
void func_global_asm_806B63E0(void);
void func_global_asm_806B640C(void);

// global_asm/done/code_BB300.c
void func_global_asm_806B6600(u8 arg0);
void func_global_asm_806B6958(void);
void func_global_asm_806B6C88(s16 arg0, s16 arg1);
void func_global_asm_806B6DB0(s32 arg0);
void func_global_asm_806B75F4(void);
void func_global_asm_806B761C(void);
void func_global_asm_806B7660(void);

// global_asm/code_BC3B0.c
void func_global_asm_806B76B0(Gfx *dl, Actor *arg1);
Gfx *func_global_asm_806B7830(Gfx *dl, Actor *arg1);
void func_global_asm_806B7BB8(s32 arg0);
// TODO: func_global_asm_806B7C74 has no documented signature but has been matched
// TODO: func_global_asm_806B7EA0 has no documented signature
void func_global_asm_806B83E4(void);
void func_global_asm_806B86AC(void);
void func_global_asm_806B8878(void);
void func_global_asm_806B8898(void);
void func_global_asm_806B88B8(void);

// global_asm/done/code_BD820.c
void func_global_asm_806B8B20(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_806B8BDC(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_806B8C78(void);
void func_global_asm_806B904C(void);

// global_asm/code_BDEE0.c
// TODO: func_global_asm_806B91E0 has no documented signature
void func_global_asm_806B9CB0(void);
void func_global_asm_806B9CE0(u8 arg0, s8 arg1);
s32 func_global_asm_806B9EB4(u8 arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_global_asm_806BA130(void);
s32 func_global_asm_806BA240(u8 arg0, s16 arg1);
void func_global_asm_806BA76C(f32 arg0);
void func_global_asm_806BA8C8(void);
// TODO: func_global_asm_806BA93C has no documented signature
void func_global_asm_806BB32C(void);
void func_global_asm_806BB400(void);
s32 func_global_asm_806BB604(u8 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_global_asm_806BB81C(void);
// TODO: func_global_asm_806BB874 has no documented signature
void func_global_asm_806BC080(void);
void func_global_asm_806BC0E4(void);
void func_global_asm_806BC148(void);
void func_global_asm_806BC1AC(void);

// global_asm/IceTomato.c
// TODO: func_global_asm_806BC1E0 has no documented signature
Gfx *func_global_asm_806BCF98(Gfx *dl, s32 arg1);
void func_global_asm_806BD094(s16 arg0, s8 arg1);
void func_global_asm_806BD0CC(void);

// global_asm/code_C1E70.c
void func_global_asm_806BD170(void);
// TODO: func_global_asm_806BD3E4 has no documented signature
// TODO: func_global_asm_806BD7B0 has no documented signature
s32 areAllKeysTurnedIn(void);

// global_asm/code_C2A90.c
u8 func_global_asm_806BDD90(void);
void func_global_asm_806BDEC8(void);
void func_global_asm_806BE09C(void);
void func_global_asm_806BE674(u8 arg0);
Gfx *func_global_asm_806BE6F0(Gfx *dl, Actor *arg1);
void func_global_asm_806BE8BC(void);
// TODO: func_global_asm_806BF218 has no documented signature
void func_global_asm_806BF920(void);
void func_global_asm_806BFA8C(u16 arg0);
void func_global_asm_806BFBB4(void);
void func_global_asm_806BFBF4(void);
void func_global_asm_806C10A0(u8 arg0, u16 arg1, s16 arg2);
void func_global_asm_806C1300(void);
void func_global_asm_806C13AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_global_asm_806C151C(u16 arg0, u8 arg1, s16 tempFlagIndex);
void func_global_asm_806C15E8(void);
void func_global_asm_806C1640(void);
void func_global_asm_806C1734(void);
void func_global_asm_806C19F4(void);
void func_global_asm_806C1B50(void);
void func_global_asm_806C1CCC(void);
void func_global_asm_806C1E44(void);
void func_global_asm_806C226C(void);
void func_global_asm_806C27DC(void);
void func_global_asm_806C28B8(void);
void func_global_asm_806C2A64(u8 arg0, u8 arg1, u8 arg2, f32 arg3, f32 arg4, f32 arg5, void *arg6, f32 arg7);
// TODO: func_global_asm_806C2B2C has no documented signature
void func_global_asm_806C2D7C(void);
// TODO: func_global_asm_806C2DF4 has no documented signature
void func_global_asm_806C3A8C(void);

// global_asm/code_C8C10.c
void func_global_asm_806C3F10(u8 arg0, u8 arg1, u8 arg2);
void func_global_asm_806C43A8(void);
// TODO: func_global_asm_806C4414 has no documented signature
void func_global_asm_806C4904(void);
void func_global_asm_806C4948(void);
void func_global_asm_806C498C(void);
void func_global_asm_806C49D0(void);
u8 func_global_asm_806C4AC4(u16 arg0, u16 arg1);
void func_global_asm_806C4E8C(void);
void func_global_asm_806C4EB4(void);
void func_global_asm_806C4EE0(u8 arg0, u8 arg1);
// TODO: func_global_asm_806C4F5C has no documented signature
void func_global_asm_806C55D8(void);
void func_global_asm_806C55E0(void);
void func_global_asm_806C5C20(void);
void func_global_asm_806C5FEC(void);
void func_global_asm_806C61C8(void);

// global_asm/done/code_CB230.c
void func_global_asm_806C6530(void);
void func_global_asm_806C6884(s16 arg0, s16 arg1, u16 arg2);
void func_global_asm_806C6B50(void);
void func_global_asm_806C6BA0(void);
void func_global_asm_806C6BC8(void);

// global_asm/code_CBEA0.c
void func_global_asm_806C71A0(void);
void func_global_asm_806C71A8(void);
void func_global_asm_806C71B0(void);
void func_global_asm_806C71B8(void);
void func_global_asm_806C71C0(void);
void func_global_asm_806C71C8(void);
void func_global_asm_806C71D0(void);
void func_global_asm_806C71D8(void);
void func_global_asm_806C71E0(void);
void func_global_asm_806C71E8(void);
void func_global_asm_806C71F0(void);
void func_global_asm_806C71F8(void);
void func_global_asm_806C7200(void);
void func_global_asm_806C7208(void);
void func_global_asm_806C7210(void);
void func_global_asm_806C7218(void);
void func_global_asm_806C7220(void);
void func_global_asm_806C7228(void);
void func_global_asm_806C7230(void);
void func_global_asm_806C7238(void);
void func_global_asm_806C7240(void);
void func_global_asm_806C7248(void);
void func_global_asm_806C7250(void);
void func_global_asm_806C7258(void);
void func_global_asm_806C7260(void);
void func_global_asm_806C7268(void);
// TODO: func_global_asm_806C7270 has no documented signature
// TODO: func_global_asm_806C75A4 has no documented signature

// global_asm/code_CC800.c
void func_global_asm_806C7B00(void);
s32 func_global_asm_806C7B34(void);
void func_global_asm_806C7B50(Actors actorIndex, u8 arg1, Actor *player);
void func_global_asm_806C7BAC(Actor *arg0, Actor *arg1);
void func_global_asm_806C7C10(void);
Struct80750948 *func_global_asm_806C7C94(u8 arg0);
// TODO: func_global_asm_806C7D40 has no documented signature
void func_global_asm_806C80E4(void);
void func_global_asm_806C81DC(s16 arg0, s16 arg1);
// TODO: func_global_asm_806C8220 has no documented signature
void func_global_asm_806C850C(s32 arg0, u8 arg1);
void func_global_asm_806C8984(void);
void func_global_asm_806C8D20(Actor *arg0);
u8 func_global_asm_806C8D2C(s16 arg0);
s32 func_global_asm_806C8DE0(s32 playerIndex);
// TODO: func_global_asm_806C8E58 has no documented signature
void func_global_asm_806C8EE8(void);
// TODO: func_global_asm_806C8F8C has no documented signature but has been matched
void func_global_asm_806C90C4(s32 exitIndex);
void func_global_asm_806C92C4(s32 arg0);
void func_global_asm_806C9304(Actor *arg0, PlayerAdditionalActorData *arg1);
void func_global_asm_806C93E4(Actor *arg0, PlayerAdditionalActorData *arg1);
void func_global_asm_806C9434(s32 arg0);
void loadExits(Maps map);
void func_global_asm_806C9658(Maps);
ExitData *getExitData(s32 exitIndex);
s8 func_global_asm_806C9830(s8 arg0, Actor *arg1);
s32 func_global_asm_806C9974(u8 playerIndex, s8 arg1);
void func_global_asm_806C9AE0(void);
void func_global_asm_806C9C1C(s32 arg0);
void func_global_asm_806C9C80(s32 playerIndex, s32 arg1, s32 arg2);
void func_global_asm_806C9D20(u8 playerIndex);
s32 func_global_asm_806C9D7C(void);

// global_asm/code_CEAE0.c
void func_global_asm_806C9DE0(void);
void func_global_asm_806C9E10(void);
void func_global_asm_806C9E40(void);
void func_global_asm_806C9E70(void);
void func_global_asm_806C9EA0(void);
void func_global_asm_806C9ED0(void);
void func_global_asm_806C9F00(void);
void func_global_asm_806C9F44(void);
void func_global_asm_806C9F74(Actor *arg0);
Actor *func_global_asm_806C9FD8(Actor *actor);
void func_global_asm_806CA048(Actor *actor, PlayerAdditionalActorData *arg1);
void func_global_asm_806CA0E8(Actor *arg0, Actor *arg1, s32 arg2);
s32 func_global_asm_806CA1B4(s32 arg0);
void func_global_asm_806CA26C(void);
void func_global_asm_806CA2AC(void);
void func_global_asm_806CA2E4(void);
void func_global_asm_806CA540(void);
// TODO: func_global_asm_806CA5F8 has no documented signature
void func_global_asm_806CB53C(void);
void func_global_asm_806CBE44(void);
void func_global_asm_806CBE90(void);
s16 func_global_asm_806CC10C(s16 arg0, s16 arg1);
s16 func_global_asm_806CC14C(s16 arg0, s16 arg1);
s16 func_global_asm_806CC190(s16 arg0, s16 arg1, f32 arg2);
s16 func_global_asm_806CC284(s16 arg0, s16 arg1, f32 arg2);
// TODO: func_global_asm_806CC364 has no documented signature
void func_global_asm_806CC5DC(void);
void func_global_asm_806CC638(f32 arg0);
void func_global_asm_806CC8A8(void);
void func_global_asm_806CC8B8(void);
void func_global_asm_806CC8F0(void);
void func_global_asm_806CC920(void);
void func_global_asm_806CC948(void);
void func_global_asm_806CC970(void);
void applyActorYAcceleration(void);
void func_global_asm_806CCB94(void);
s32 func_global_asm_806CCC10(void);
// TODO: func_global_asm_806CCC54 has no documented signature
// TODO: func_global_asm_806CD424 has no documented signature
f32 func_global_asm_806CD898(f32 currentSpeed, f32 desiredSpeed, f32 boostAmount);
void func_global_asm_806CD8EC(void);
s16 func_global_asm_806CD988(Actor *arg0);
s16 func_global_asm_806CD9A0(Actor *arg0, f32 arg1, f32 arg2, s16 arg3, s16 arg4);
s32 func_global_asm_806CDD24(Actor *arg0, f32 arg1, f32 arg2, s32 arg3);
u32 func_global_asm_806CE174(Actor *arg0, f32 arg1, f32 arg2, s32 arg3);
s16 func_global_asm_806CE4E4(Actor *arg0, f32 arg1, f32 arg2, s32 arg3);
s32 func_global_asm_806CE7A0(Actor *arg0, f32 arg1, f32 arg2, s16 arg3, s16 arg4);
s16 func_global_asm_806CE928(Actor *arg0, f32 arg1, f32 arg2, s32 arg3);
s32 func_global_asm_806CEB44(f32 arg0, f32 arg1);
// TODO: func_global_asm_806CEC04 has no documented signature
void func_global_asm_806CEE64(f32 arg0);
void func_global_asm_806CEED8(void);
// TODO: func_global_asm_806CEFBC has no documented signature
void func_global_asm_806CF0D0(void);
// TODO: func_global_asm_806CF138 has no documented signature
void func_global_asm_806CF2EC(s32 *arg0, s32 *arg1);
void func_global_asm_806CF398(Actor *arg0);
void func_global_asm_806CF42C(Actor *arg0);
void func_global_asm_806CF4B8(Actor *arg0);
void func_global_asm_806CF580(void);
void func_global_asm_806CF878(void);
void func_global_asm_806CF918(void);
// TODO: func_global_asm_806CF9CC has no documented signature
u8 func_global_asm_806CFC90(Actor *arg0, f32 *arg1, u8 arg2, f32 arg3);
void func_global_asm_806CFD68(void);
void func_global_asm_806CFDA8(void);
void func_global_asm_806CFDEC(void);
void func_global_asm_806CFE30(void);
void setYAccelerationFrom80753578(void);
void func_global_asm_806CFEA4(void);
void func_global_asm_806CFECC(void);
void func_global_asm_806CFEF4(void);
void func_global_asm_806CFF1C(Actor *arg0);
void func_global_asm_806CFF9C(Actor *arg0);
void func_global_asm_806D0150(Actor *arg0);
void func_global_asm_806D01AC(void);
void func_global_asm_806D024C(void);
void func_global_asm_806D0378(void);
void func_global_asm_806D03BC(void);
void func_global_asm_806D0408(void);
void func_global_asm_806D0430(f32 arg0);
// TODO: func_global_asm_806D0468 has no documented signature
void func_global_asm_806D06A0(void);
s32 func_global_asm_806D0964(s32 arg0, u8 playerIndex);
void func_global_asm_806D09E8(Actor *arg0);
void func_global_asm_806D0A54(Actor *arg0, s32 arg1, s32 arg2);
void func_global_asm_806D0A84(void);
u8 func_global_asm_806D0DE4(Actor *arg0, Actor *arg1);
void func_global_asm_806D0EBC(Actor *arg0);
s16 func_global_asm_806D1080(f32 arg0, f32 arg1);
s32 func_global_asm_806D10D0(Actor *arg0);
void func_global_asm_806D1110(void);
void func_global_asm_806D11FC(void);
void func_global_asm_806D1238(void);
void func_global_asm_806D1270(void);
void func_global_asm_806D1278(void);
void func_global_asm_806D12CC(void);
void func_global_asm_806D1420(void);
void func_global_asm_806D1568(void);
void func_global_asm_806D19A8(void);
void func_global_asm_806D1B60(void);
void func_global_asm_806D1D3C(void);
void func_global_asm_806D1D84(void);
void func_global_asm_806D1DEC(void);
void func_global_asm_806D1E90(void);
void func_global_asm_806D1F28(void);
void func_global_asm_806D205C(void);
void func_global_asm_806D21E4(void);
void func_global_asm_806D2238(void);
void func_global_asm_806D22A0(void);
void func_global_asm_806D22C0(void);
void func_global_asm_806D2330(void *arg0);
void func_global_asm_806D2378(void);
void func_global_asm_806D239C(void);
void func_global_asm_806D24A8(void);
void func_global_asm_806D24E4(void);
void func_global_asm_806D25CC(void);
void func_global_asm_806D266C(void);
void func_global_asm_806D26D8(void);
void func_global_asm_806D2744(s32 arg0);
void func_global_asm_806D2784(void);
void func_global_asm_806D27A4(void);
void func_global_asm_806D281C(void);
void func_global_asm_806D28E4(void);
void func_global_asm_806D2904(void);
void func_global_asm_806D2954(s16 arg0);
void func_global_asm_806D2A14(s16 arg0);
void func_global_asm_806D2AA0(s16 arg0);
void func_global_asm_806D2B90(void);
void func_global_asm_806D2BB0(void);

// global_asm/code_D78D0.c
void func_global_asm_806D2BD0(void);
void func_global_asm_806D2C54(void);
void func_global_asm_806D2CAC(void);
void func_global_asm_806D2D38(void);
void func_global_asm_806D2DC4(void);
void func_global_asm_806D2E9C(void);
void func_global_asm_806D3224(void);
void func_global_asm_806D32C0(void);
void func_global_asm_806D332C(void);
void func_global_asm_806D34B4(void);
void func_global_asm_806D3530(void);
void func_global_asm_806D3608(void);
void func_global_asm_806D36CC(void);
void func_global_asm_806D374C(void);
void func_global_asm_806D37CC(void);
void func_global_asm_806D38AC(s32 arg0);
void func_global_asm_806D3A38(void);
void func_global_asm_806D3AC8(void);
void func_global_asm_806D3AE8(void);
void func_global_asm_806D3B08(void);
void func_global_asm_806D3B28(void);
void func_global_asm_806D3B48(void);
void func_global_asm_806D3BC8(void);
void func_global_asm_806D3CD4(void);
void func_global_asm_806D3D5C(void);
void func_global_asm_806D3DE4(void);
void func_global_asm_806D3FA0(void);
void func_global_asm_806D4010(void);
void func_global_asm_806D423C(void);
void func_global_asm_806D428C(void);
void func_global_asm_806D45A4(void);
void func_global_asm_806D4758(void);
void func_global_asm_806D491C(void);
void func_global_asm_806D4A70(void);
void func_global_asm_806D4C7C(void);
void func_global_asm_806D4DE4(void);
void func_global_asm_806D5008(void);
void func_global_asm_806D5218(void);
void func_global_asm_806D5300(void);
void func_global_asm_806D57F0(void);
void func_global_asm_806D5834(void);
void func_global_asm_806D59E4(void);
void func_global_asm_806D5B44(void);
void func_global_asm_806D5CCC(void);
void func_global_asm_806D61B8(void);
void func_global_asm_806D6558(void);
s32 func_global_asm_806D69A4(void);
void func_global_asm_806D6B00(void);
void func_global_asm_806D6F0C(void);
void func_global_asm_806D6F64(void);
void func_global_asm_806D7098(void);
void func_global_asm_806D7170(void);
void func_global_asm_806D7238(void);
void func_global_asm_806D72D4(void);
void func_global_asm_806D7510(void);
void func_global_asm_806D7704(void);
void func_global_asm_806D7878(void);
void func_global_asm_806D79E4(void);
void func_global_asm_806D7A28(void);
void func_global_asm_806D7DF8(void);
void func_global_asm_806D7E88(void);
void func_global_asm_806D7F48(void);
void func_global_asm_806D7FE8(void);
void func_global_asm_806D8070(void);
void func_global_asm_806D80A8(void);
void func_global_asm_806D8308(void);
int func_global_asm_806D850C(void);
void func_global_asm_806D87FC(void);
void func_global_asm_806D8A64(void);
void func_global_asm_806D8B08(void);
void func_global_asm_806D8FCC(void);
void func_global_asm_806D9134(void);
void func_global_asm_806D9184(void);
void func_global_asm_806D91A4(void);
void func_global_asm_806D9320(void);
void func_global_asm_806D97A4(void);
void func_global_asm_806D9820(void);
void func_global_asm_806D9924(Actor *actor);
void func_global_asm_806D9940(void);
void func_global_asm_806D9AD4(void);
void func_global_asm_806D9D58(void);
void func_global_asm_806D9FD0(void);
void func_global_asm_806DA320(void);
void func_global_asm_806DA3E4(void);
void func_global_asm_806DA4D8(void);
void func_global_asm_806DA7EC(void);
void func_global_asm_806DA89C(void);
void func_global_asm_806DA94C(void);
void func_global_asm_806DAA14(void);
void func_global_asm_806DAADC(void);
void func_global_asm_806DABE4(void);
void func_global_asm_806DADA0(void);
void func_global_asm_806DAF5C(void);
void func_global_asm_806DB08C(void);
void func_global_asm_806DB0C4(void);
void func_global_asm_806DB3AC(void);
void func_global_asm_806DB670(void);
void func_global_asm_806DBB04(void);
void func_global_asm_806DC170(void);
void func_global_asm_806DC3A4(f32 arg0);
void func_global_asm_806DC410(void);
// TODO: func_global_asm_806DCA7C has no documented signature
void func_global_asm_806DCF60(void);
void func_global_asm_806DD24C(void);
void func_global_asm_806DD874(void);
void func_global_asm_806DDAB0(void);
void func_global_asm_806DE264(void);
void func_global_asm_806DE930(void);
void func_global_asm_806DE9F4(void);
void func_global_asm_806DEAA4(void);
void func_global_asm_806DECD4(void);
void func_global_asm_806DED44(void);
void func_global_asm_806DF050(void);
void func_global_asm_806DF1A0(void);
void func_global_asm_806DF280(void);

// global_asm/code_E4090.c
void func_global_asm_806DF390(Actor* arg0, PlayerAdditionalActorData *arg1, u8 arg2);
void func_global_asm_806DF3D0(Actor* arg0, PlayerAdditionalActorData *arg1, u8 arg2);
void func_global_asm_806DF44C(Actor* arg0, PlayerAdditionalActorData *arg1, u8 arg2);
void func_global_asm_806DF494(s16 *arg0, s16 arg1, s16 arg2);
void func_global_asm_806DF5A0(s16 *arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_806DF670(s16 *arg0, s16 arg1, s16 arg2);
// TODO: handleInputsForControlState has no documented signature
u16 func_global_asm_806DFF34(u16 arg0, u16 *arg1);
f32 func_global_asm_806DFFA0(f32 arg0, s16 arg1, s16 arg2);
void func_global_asm_806DFFDC(s16 arg0);
void func_global_asm_806E0050(void);
void func_global_asm_806E007C(void);
void func_global_asm_806E0178(void);
void func_global_asm_806E0294(void);
f32 func_global_asm_806E03C8(f32 arg0, f32 arg1);
f32 func_global_asm_806E0454(f32 arg0, f32 arg1);
void func_global_asm_806E04E0(void);
void func_global_asm_806E0654(void);
void func_global_asm_806E0694(void);
void func_global_asm_806E06E8(void);
void func_global_asm_806E077C(void);
void func_global_asm_806E07F8(void);
void func_global_asm_806E0BEC(void);
// TODO: func_global_asm_806E0D40 has no documented signature
// TODO: func_global_asm_806E0FAC has no documented signature
void func_global_asm_806E1334(void);
void func_global_asm_806E14DC(void);
void func_global_asm_806E1630(void);
void func_global_asm_806E1728(void);
void func_global_asm_806E17F4(void);
void func_global_asm_806E1864(void);
void func_global_asm_806E186C(void);
void func_global_asm_806E1A50(void);
void func_global_asm_806E1BA4(void);
void func_global_asm_806E1D38(void);
void func_global_asm_806E1E54(void);
void func_global_asm_806E1F8C(void);
void func_global_asm_806E208C(void);
void func_global_asm_806E2140(void);
// TODO: func_global_asm_806E225C has no documented signature
// TODO: func_global_asm_806E2B20 has no documented signature
void func_global_asm_806E2C74(Actor *arg0);
u8 playerCanThrowOrange(void);
void func_global_asm_806E2DE8(void);
void func_global_asm_806E2E6C(void);
void func_global_asm_806E2EA8(void);
void func_global_asm_806E2ECC(void);
void func_global_asm_806E2F3C(void);
void func_global_asm_806E2FE8(void);
void func_global_asm_806E3040(void);
void func_global_asm_806E31FC(void);
void func_global_asm_806E330C(void);
void func_global_asm_806E341C(void);
void func_global_asm_806E34D8(void);
void func_global_asm_806E352C(void);
void func_global_asm_806E35D8(void);
void func_global_asm_806E36B4(void);
void func_global_asm_806E380C(void);
void func_global_asm_806E382C(void);
void func_global_asm_806E384C(void);
void func_global_asm_806E3B00(void);
void func_global_asm_806E3C14(void);
void func_global_asm_806E3C38(void);
void func_global_asm_806E3CEC(void);
void func_global_asm_806E3D14(f32 arg0);
void func_global_asm_806E3E40(void);
void func_global_asm_806E41B4(void);
void func_global_asm_806E41EC(void);
s32 func_global_asm_806E4580(void);
void func_global_asm_806E4634(void);
void func_global_asm_806E4740(void);
void func_global_asm_806E4AD8(void);
void func_global_asm_806E4C6C(void);
void func_global_asm_806E4D14(void);
void func_global_asm_806E4D84(void);
void func_global_asm_806E4E88(void);
void func_global_asm_806E5044(void);
void func_global_asm_806E521C(void);
s32 func_global_asm_806E527C(void);
void func_global_asm_806E52D0(void);
s32 func_global_asm_806E5488(Actor *arg0);
u8 func_global_asm_806E560C(Actor *arg0);
s32 func_global_asm_806E56EC(void);
void func_global_asm_806E5C2C(Maps map, s32 arg1, s32 arg2);
int func_global_asm_806E5C74(void);
void func_global_asm_806E5D60(void);
void func_global_asm_806E5E58(void);
void func_global_asm_806E5E60(void);
void func_global_asm_806E5E68(void);
void func_global_asm_806E5EA8(void);
void func_global_asm_806E5ED4(void);
void func_global_asm_806E5FA0(void);
void func_global_asm_806E607C(void);
void func_global_asm_806E61D0(void);
void func_global_asm_806E6234(void);
void func_global_asm_806E6318(void);
void func_global_asm_806E6368(void);
void func_global_asm_806E63B8(void);
void func_global_asm_806E64D0(void);
void func_global_asm_806E65BC(void);
void func_global_asm_806E67D8(void);
void func_global_asm_806E6A38(void);
void func_global_asm_806E6B98(void);
void func_global_asm_806E6DE8(void);
void func_global_asm_806E6E7C(void);

// global_asm/code_EBBE0.c
void func_global_asm_806E6EE0(void);
void func_global_asm_806E6F74(void);
void func_global_asm_806E6FF0(void);
void func_global_asm_806E7050(void);
void func_global_asm_806E7088(void);
void func_global_asm_806E709C(void);
void func_global_asm_806E7230(void);
void func_global_asm_806E7338(void);
void func_global_asm_806E7484(void);
void func_global_asm_806E7568(void);
void func_global_asm_806E7658(void);
u8 playerCanDive(void);
void func_global_asm_806E7780(void);
void func_global_asm_806E78B8(void);
void func_global_asm_806E78E0(void);
void func_global_asm_806E78F8(void);
void func_global_asm_806E7900(void);
void func_global_asm_806E7B48(void);
void func_global_asm_806E7C70(void);
void func_global_asm_806E7DF4(void);
void func_global_asm_806E8244(void);
void func_global_asm_806E84A4(void);
void func_global_asm_806E84C0(void);
void func_global_asm_806E84F8(void);
// TODO: func_global_asm_806E854C has no documented signature but has been matched
void func_global_asm_806E8724(Actor *arg0, RaceAdditionalActorData *arg1);
void func_global_asm_806E884C(void);
void func_global_asm_806E8880(void);
void func_global_asm_806E88AC(void);
void func_global_asm_806E88D8(void);
void func_global_asm_806E8A8C(void);
void func_global_asm_806E8AF0(void);
void func_global_asm_806E8B28(void);
void func_global_asm_806E8BA4(void);
void func_global_asm_806E8BFC(void);
void func_global_asm_806E8C2C(void);
void func_global_asm_806E8D54(void);
void func_global_asm_806E8DB4(void);
void func_global_asm_806E8E00(void);
void func_global_asm_806E8E78(void);
void func_global_asm_806E8F04(void);
void func_global_asm_806E8F68(void);
void func_global_asm_806E9070(void);
void func_global_asm_806E918C(void);
void func_global_asm_806E9388(void);
void func_global_asm_806E93F8(void);
void func_global_asm_806E9468(void);
u8 func_global_asm_806E9580(void);
void func_global_asm_806E9804(s16 arg0);
void func_global_asm_806E9874(void);
void func_global_asm_806E98F8(void);
void func_global_asm_806E9964(PlayerAdditionalActorData *PaaD);
void func_global_asm_806E9A5C(void);
void func_global_asm_806E9ACC(void);
void func_global_asm_806E9B3C(void);
void func_global_asm_806E9BA8(s32 arg0);
void func_global_asm_806E9CDC(void);
void func_global_asm_806E9CFC(void);
s32 func_global_asm_806E9D1C(s16 arg0, u8 arg1, u8 arg2);
void func_global_asm_806E9DE0(void);
void func_global_asm_806E9ECC(void);
void func_global_asm_806E9F8C(void);
void func_global_asm_806EA04C(void);
void func_global_asm_806EA0A4(void);
void func_global_asm_806EA200(void);
void func_global_asm_806EA26C(void);
f32 func_global_asm_806EA2D8(void);
void func_global_asm_806EA334(void);
void func_global_asm_806EA460(void);
void func_global_asm_806EA568(void);
void func_global_asm_806EA5CC(void);
void func_global_asm_806EA600(void);
void func_global_asm_806EA628(void);
void func_global_asm_806EA7E8(void);
void func_global_asm_806EA844(void);
void func_global_asm_806EA8A0(void);
void func_global_asm_806EA8FC(void);
void func_global_asm_806EA958(void);
void func_global_asm_806EA9B4(void);
void func_global_asm_806EAA44(void);
void func_global_asm_806EAAA0(void);
void func_global_asm_806EAB44(Actor *arg0, u8 arg1);
void func_global_asm_806EAC8C(void);
void func_global_asm_806EACBC(void);
void func_global_asm_806EACEC(void);
void func_global_asm_806EAE04(void);
void func_global_asm_806EAE60(void);
void func_global_asm_806EAF6C(void);
void func_global_asm_806EAFEC(void);
void func_global_asm_806EAFF4(void);
void func_global_asm_806EB058(void);

// global_asm/code_EFDC0.c
u8 setAction(s16 actionIndex, Actor *actor, u8 playerIndex);
void func_global_asm_806EB178(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_806EB194(void);
void func_global_asm_806EB2B8(void);
void func_global_asm_806EB364(void);
// TODO: func_global_asm_806EB400 has no documented signature
void func_global_asm_806EB4B4(void);
void func_global_asm_806EB4F8(void);
void func_global_asm_806EB544(void);
void func_global_asm_806EB5C8(void);
void func_global_asm_806EB6D8(void);
void func_global_asm_806EB744(void);
void func_global_asm_806EB8CC(void);
void func_global_asm_806EB964(void);
void func_global_asm_806EBA04(void);
void func_global_asm_806EBA74(void);
void func_global_asm_806EBAF4(void);
void func_global_asm_806EBB44(void);
void func_global_asm_806EBBD0(void);
void func_global_asm_806EBC60(void);
void func_global_asm_806EBCF0(void);
void func_global_asm_806EBDAC(void);
void func_global_asm_806EBDC4(void);
void func_global_asm_806EBE8C(void);
void func_global_asm_806EBED0(void);
void func_global_asm_806EBF34(void);
void func_global_asm_806EBF74(void);
void func_global_asm_806EBFD0(void);
void func_global_asm_806EC014(void);
void func_global_asm_806EC044(void);
void func_global_asm_806EC1A8(void);
void func_global_asm_806EC2CC(void);
void func_global_asm_806EC3BC(void);
void func_global_asm_806EC4AC(void);
void func_global_asm_806EC708(void);
void func_global_asm_806EC800(void);
void func_global_asm_806EC8C4(void);
void func_global_asm_806EC994(void);
void func_global_asm_806ECA74(void);
void func_global_asm_806ECAC4(void);
void func_global_asm_806ECBD4(void);
void func_global_asm_806ECC48(void);
void func_global_asm_806ECCDC(void);
void func_global_asm_806ECDD4(void);
void func_global_asm_806ECE2C(void);
void func_global_asm_806ECF1C(void);
void func_global_asm_806ECF9C(void);
void func_global_asm_806ED050(void);
void func_global_asm_806ED0FC(void);
void func_global_asm_806ED244(void);
void func_global_asm_806ED420(void);
void func_global_asm_806ED508(u16 actorBehaviourIndex);
void func_global_asm_806ED5C0(Actor *arg0);
// TODO: func_global_asm_806ED6B0 has no documented signature
void func_global_asm_806EDFF8(void);
void func_global_asm_806EE02C(void);
void func_global_asm_806EE06C(void);
void func_global_asm_806EE10C(void);
void func_global_asm_806EE1C4(void);
void func_global_asm_806EE26C(void);
void func_global_asm_806EE2B8(void);
void func_global_asm_806EE454(void);
void func_global_asm_806EE5A4(void);
void func_global_asm_806EE634(void);
void func_global_asm_806EE660(void);
void func_global_asm_806EE6B0(void);
void func_global_asm_806EE700(void);
void func_global_asm_806EE74C(void);
void func_global_asm_806EE7B8(void);
void func_global_asm_806EE7F4(void);
void func_global_asm_806EE878(void);
void func_global_asm_806EE924(void);
void func_global_asm_806EE994(void);
void func_global_asm_806EEA5C(void);
void func_global_asm_806EEAF8(s16 arg0);
void func_global_asm_806EF830(void);
void func_global_asm_806EF944(void);
void func_global_asm_806EFA08(void);
void func_global_asm_806EFA1C(void);
void func_global_asm_806EFA3C(void);
void func_global_asm_806EFB4C(void);
void func_global_asm_806EFC38(void);
void func_global_asm_806EFD50(void);
void func_global_asm_806EFDFC(void);
void func_global_asm_806EFF34(void);
void func_global_asm_806F006C(void);
void func_global_asm_806F0074(void);
void func_global_asm_806F007C(void);
void func_global_asm_806F00BC(void);
void func_global_asm_806F014C(void);
void func_global_asm_806F0184(void);
void func_global_asm_806F01D8(void);
void func_global_asm_806F0238(void);
void func_global_asm_806F027C(void);
void func_global_asm_806F0344(void);
// TODO: func_global_asm_806F03C4 has no documented signature
void func_global_asm_806F0624(void);
void func_global_asm_806F06A4(void);
void func_global_asm_806F0700(void);
void func_global_asm_806F07CC(void);
void func_global_asm_806F0878(void);
void func_global_asm_806F0930(void);

// global_asm/code_F56F0.c
void func_global_asm_806F09F0(Actor *arg0, u16 arg1);
void func_global_asm_806F0B34(Actor *arg0);
void func_global_asm_806F0C18(Actor *arg0);
void func_global_asm_806F0D68(Actor *arg0);
void func_global_asm_806F1048(Actor *arg0);
void func_global_asm_806F10E8(Actor *arg0);
void func_global_asm_806F1250(Actor *arg0);
void func_global_asm_806F12FC(Actor *arg0);
void func_global_asm_806F1350(s32 arg0);
void func_global_asm_806F1378(s32 arg0);
void func_global_asm_806F1380(Actor *arg0);
void func_global_asm_806F13C8(Actor *arg0);
void func_global_asm_806F142C(Actor *arg0);
void func_global_asm_806F149C(Actor *arg0);
void func_global_asm_806F14BC(Actor *arg0);
s32 func_global_asm_806F1668(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
// TODO: func_global_asm_806F1768 has no documented signature but has been matched
// TODO: func_global_asm_806F1858 has no documented signature but has been matched
// TODO: func_global_asm_806F18F4 has no documented signature but has been matched
// TODO: func_global_asm_806F1990 has no documented signature but has been matched
// TODO: func_global_asm_806F1A18 has no documented signature but has been matched
// TODO: func_global_asm_806F1AE0 has no documented signature but has been matched
// TODO: func_global_asm_806F1B58 has no documented signature but has been matched
f32 func_global_asm_806F1B90(f32 *arg0, f32 arg1);
void func_global_asm_806F1C04(Actor *arg0, AnimationStateUnk1C *arg1, s32 *arg2);
// TODO: func_global_asm_806F1EB0 has no documented signature
// TODO: func_global_asm_806F22A8 has no documented signature
// TODO: func_global_asm_806F2754 has no documented signature
// TODO: func_global_asm_806F2A40 has no documented signature but has been matched
// TODO: func_global_asm_806F2C48 has no documented signature
// TODO: func_global_asm_806F2EDC has no documented signature but has been matched
// TODO: func_global_asm_806F2FC0 has no documented signature but has been matched
// TODO: func_global_asm_806F3190 has no documented signature
void func_global_asm_806F3760(s16 map);
// TODO: func_global_asm_806F37BC has no documented signature but has been matched
void func_global_asm_806F386C(u8 arg0, Actor *arg1, Actor *arg2, s16 arg3, u8 arg4);
// TODO: func_global_asm_806F3950 has no documented signature but has been matched
void func_global_asm_806F397C(Actor *arg0, Actor *arg1, s16 arg2, s16 arg3);
void func_global_asm_806F39E8(Actor *arg0, ExitData *arg1, u8 arg2);
void func_global_asm_806F3BEC(Actor *arg0, s16 arg1, s16 arg2, u8 arg3);
void func_global_asm_806F3DB0(void);
void func_global_asm_806F3DC8(u16 *arg0, s16 *arg1, u8 *arg2, u16 arg3);
// TODO: func_global_asm_806F3E0C has no documented signature
// TODO: func_global_asm_806F4528 has no documented signature but has been matched
f32 func_global_asm_806F46B0(s16 arg0);

// global_asm/code_F9450.c
void func_global_asm_806F4750(void);
void func_global_asm_806F4778(void);
void func_global_asm_806F4D70(u8 playerIndex, f32 x, f32 y, f32 z, f32 arg4);
// TODO: func_global_asm_806F4DC0 has no documented signature
s32 func_global_asm_806F4E74(s16 arg0);
s32 func_global_asm_806F4EBC(f32 arg0, f32 arg1);
// TODO: func_global_asm_806F4F50 has no documented signature
void func_global_asm_806F50C8(s16 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5);
// TODO: func_global_asm_806F5270 has no documented signature
void func_global_asm_806F5378(void);
// TODO: func_global_asm_806F53EC has no documented signature but has been matched
s32 func_global_asm_806F544C(s32 arg0, s32 actorBehaviourIndex, u8 arg2);
void func_global_asm_806F5498(void);
// TODO: func_global_asm_806F54E0 has no documented signature
void func_global_asm_806F58A0(u8 arg0, s16 arg1, Actor *arg2);
void func_global_asm_806F5A48(u8 arg0, s16 arg1, Actor *arg2, u16 arg3);
s32 func_global_asm_806F5C30(s32 arg0);
s32 func_global_asm_806F5CE4(s32 arg0);
void func_global_asm_806F5D80(s32 *arg0, s32 *arg1);
void func_global_asm_806F5DF8(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5);
s32 func_global_asm_806F5EB4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_global_asm_806F5F2C(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_global_asm_806F5FA0(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_806F5FE8(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4);
void func_global_asm_806F603C(void);
// TODO: func_global_asm_806F6204 has no documented signature
// TODO: func_global_asm_806F6554 has no documented signature but has been matched
s32 func_global_asm_806F6644(s16 arg0, s32 arg1, u16 arg2);
void func_global_asm_806F69A8(u8 playerIndex);
u8 func_global_asm_806F6E58(s16 arg0);
s32 func_global_asm_806F6EDC(void);
void func_global_asm_806F6F28(void);
s32 func_global_asm_806F70A8(s16 arg0);
// TODO: func_global_asm_806F70FC has no documented signature
f32 func_global_asm_806F7378(s32 arg0);
// TODO: func_global_asm_806F73A0 has no documented signature
// TODO: func_global_asm_806F79E0 has no documented signature

// global_asm/hud.c
PlayerHUD* func_global_asm_806F7FD0(u8 playerIndex);
void func_global_asm_806F8004(f32 xRotation, f32 yRotation, f32 *xOut, f32 *yOut, f32 *zOut);
void func_global_asm_806F8170(s32 HUDItemIndex, f32 *xOut, f32 *yOut, f32 *zOut);
// TODO: func_global_asm_806F8278 has no documented signature
void func_global_asm_806F833C(s32 arg0);
void func_global_asm_806F8A8C(u8 arg0, u8 playerIndex, s32 arg2);
u16 func_global_asm_806F8AD4(u8 arg0, u8 playerIndex);
void func_global_asm_806F8BC4(s32 HUDItemIndex, u8 arg1, s32 arg2);
void func_global_asm_806F8CB0(s32 HUDItemIndex);
void func_global_asm_806F8CFC(s32 HUDItemIndex, s32 arg1);
void func_global_asm_806F8D58(s32 HUDItemIndex, s32 arg1);
void func_global_asm_806F8DC4(u8 *arg0, s32 arg1, s32 arg2);
s32 func_global_asm_806F8EB4(void);
u16 func_global_asm_806F8EDC(s32 HUDItemIndex, s32 playerIndex); // getMaxItemCapacity(HUDItemIndex, playerIndex)
void changeCollectableCount(s32 HUDItemIndex, u8 playerIndex, s16 amount);
void func_global_asm_806F93EC(u16 *arg0, Maps map);
void func_global_asm_806F942C(u16 *arg0, Maps map);
u8 func_global_asm_806F9470(u16 arg0, Maps map);
// TODO: func_global_asm_806F94AC has no documented signature but has been matched
void func_global_asm_806F9518(s32 HUDItemIndex);
void func_global_asm_806F95C8(void);
// TODO: func_global_asm_806F9608 has no documented signature but has been matched
// TODO: func_global_asm_806F966C has no documented signature but has been matched
// TODO: func_global_asm_806F96CC has no documented signature but has been matched
// TODO: func_global_asm_806F9744 has no documented signature but has been matched
// TODO: func_global_asm_806F9848 has no documented signature
// TODO: func_global_asm_806F9AF0 has no documented signature but has been matched
// TODO: func_global_asm_806F9B64 has no documented signature
// TODO: func_global_asm_806F9CD0 has no documented signature
// TODO: func_global_asm_806F9D8C has no documented signature
// TODO: func_global_asm_806FA1A4 has no documented signature
// TODO: func_global_asm_806FA504 has no documented signature but has been matched
Gfx *func_global_asm_806FA5A4(s32 HUDItemIndex, Gfx *dl);
s32 func_global_asm_806FA7A4(s32 arg0);
Gfx *func_global_asm_806FA7BC(s32 HUDItemIndex, Gfx *dl);
Gfx *func_global_asm_806FA9C0(s32 HUDItemIndex, Gfx *dl);
Gfx *func_global_asm_806FAB20(Gfx *dl);
void func_global_asm_806FAC64(u8 arg0);
void *func_global_asm_806FACE8(u32 arg0);
// TODO: func_global_asm_806FAFE4 has no documented signature
void func_global_asm_806FB218(void);
void func_global_asm_806FB290(void);
// TODO: func_global_asm_806FB2B8 has no documented signature
void func_global_asm_806FB370(u8 HUDItemIndex, u8 playerIndex, u8 arg2);
u8 func_global_asm_806FB3D0(u8 HUDItemIndex, u8 playerIndex);
s32 func_global_asm_806FB418(void);

// global_asm/code_100180.c
void func_global_asm_806FB480(void);
void func_global_asm_806FB488(void);
// TODO: func_global_asm_806FB490 has no documented signature
// TODO: func_global_asm_806FB714 has no documented signature
void func_global_asm_806FB8B0(s32 arg0);
// TODO: func_global_asm_806FB914 has no documented signature
void func_global_asm_806FBB58(void);
void *func_global_asm_806FBB9C(s16 textureIndex);
void func_global_asm_806FBC34(void);
s32 getCenterOfString(s16 renderStyle, char *string);
s16 func_global_asm_806FBEAC(u8 *arg0);
Gfx *func_global_asm_806FBEF0(Gfx *dl, u8 arg1, s16 arg2);
Gfx *printStyledText(Gfx *dl, s16 style, s16 x, s16 y, char *string, u32 extraBitfield);
// TODO: func_global_asm_806FCC88 has no documented signature
// TODO: func_global_asm_806FD094 has no documented signature
// TODO: func_global_asm_806FD490 has no documented signature
// TODO: func_global_asm_806FD7A8 has no documented signature
u8 func_global_asm_806FD894(s16 arg0);

// global_asm/code_1025E0.c
Gfx *func_global_asm_806FD8E0(Gfx *dl, s16 style, char *string, s16 y, u8 extraBitfield);
Gfx *func_global_asm_806FD950(Gfx *dl, s16 style, char *string, s16 y);
void func_global_asm_806FD9A0(void);
Struct80754AD0 *func_global_asm_806FD9B4(s16 arg0);
// TODO: func_global_asm_806FD9FC has no documented signature
f32 func_global_asm_806FDA8C(s16 arg0);
void func_global_asm_806FDAB8(s16 arg0, f32 arg1);
void func_global_asm_806FDAEC(s16 arg0);
// TODO: func_global_asm_806FDB8C has no documented signature
void func_global_asm_806FDF1C(s16 arg0, char *arg1);
void func_global_asm_806FDF54(f32 *arg0, f32 *arg1);
Gfx *func_global_asm_806FE078(Gfx *dl, u8 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

// global_asm/code_103AB0.c
Gfx *func_global_asm_806FEDB0(Gfx *dl, u8 arg1);
Gfx *func_global_asm_806FEF7C(Gfx *dl, Actor *arg1);
Gfx *func_global_asm_806FF01C(Gfx *dl, Actor *arg1);
void func_global_asm_806FF144(Gfx *dl);
void func_global_asm_806FF32C(Gfx *dl, Actor *arg1);
// TODO: func_global_asm_806FF358 has no documented signature
Gfx *func_global_asm_806FF628(Gfx *dl, Actor *arg1);
// TODO: func_global_asm_806FF75C has no documented signature
void func_global_asm_806FFB2C(Gfx *dl, Actor *arg1);
// TODO: func_global_asm_806FFC04 has no documented signature
s16 *func_global_asm_806FFEAC(s16 *arg0, s16 *arg1);
void func_global_asm_806FFF5C(void);
// TODO: func_global_asm_806FFF88 has no documented signature
// TODO: func_global_asm_80700088 has no documented signature
void func_global_asm_807002AC(u16 *arg0, s16 **arg1, f32 arg2);
// TODO: func_global_asm_8070033C has no documented signature
Gfx *func_global_asm_8070068C(Gfx *dl);
// TODO: func_global_asm_807007B8 has no documented signature
s16 func_global_asm_807009F4(s16 arg0);
s16 func_global_asm_80700AE4(s16, s16);
// TODO: func_global_asm_80700BF4 has no documented signature
// TODO: func_global_asm_80701098 has no documented signature
void func_global_asm_80701C90(void);
// TODO: func_global_asm_80701CA0 has no documented signature
void func_global_asm_807023E8(Gfx **dl, void *texture, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC);
void func_global_asm_80702464(Gfx **dl, void *texture, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, u8 argD, u8 argE);
// TODO: func_global_asm_807024E0 has no documented signature
Gfx *func_global_asm_80703374(Gfx *dl, u8 r, u8 g, u8 b, u8 a);
// TODO: func_global_asm_807035C4 has no documented signature
void func_global_asm_80703850(u8 arg0);
// TODO: func_global_asm_80703AB0 has no documented signature
// TODO: func_global_asm_80703CF8 has no documented signature
void func_global_asm_807040D0(u16 arg0);
void func_global_asm_807040E0(u8 arg0, u8 arg1, u8 arg2);
void func_global_asm_80704108(u8 arg0, u8 arg1, u8 arg2);
// TODO: func_global_asm_80704130 has no documented signature but has been matched
// TODO: func_global_asm_80704298 has no documented signature
// TODO: func_global_asm_80704444 has no documented signature
// TODO: func_global_asm_80704484 has no documented signature
// TODO: func_global_asm_80704960 has no documented signature
void func_global_asm_80704AFC(f32 arg0, f32 arg1, f32 arg2);
// TODO: func_global_asm_80704B20 has no documented signature
// TODO: func_global_asm_80705B14 has no documented signature but has been matched
void func_global_asm_80705B30(void);
void func_global_asm_80705C00(s16 arg0, s16 arg1, u8 arg2);
// TODO: func_global_asm_80705F5C has no documented signature
// TODO: func_global_asm_807063B8 has no documented signature
// TODO: func_global_asm_807065F8 has no documented signature
// TODO: func_global_asm_807069A4 has no documented signature
// TODO: func_global_asm_80706F90 has no documented signature
Gfx *func_global_asm_8070770C(Gfx *dl);
// TODO: func_global_asm_80707980 has no documented signature
// TODO: func_global_asm_8070835C has no documented signature
void func_global_asm_80708574(f32 arg0);

// global_asm/code_10D2D0.c
// TODO: func_global_asm_807085D0 has no documented signature
// TODO: func_global_asm_80708BB8 has no documented signature but has been matched
void func_global_asm_80708C24(s32 playerIndex, CharacterChange *arg1, PlayerProgress *arg2, s32 arg3);
Gfx *func_global_asm_80708DA4(Gfx *dl, s16 arg1, CharacterChange* arg2);
Gfx *func_global_asm_80709344(Gfx *dl);
s32 func_global_asm_8070943C(void);
void func_global_asm_80709464(u8 playerIndex);

// global_asm/code_10E1D0.c
void func_global_asm_807094D0(u8 arg0);
// TODO: func_global_asm_807095E4 has no documented signature
// TODO: func_global_asm_80709890 has no documented signature
// TODO: func_global_asm_80709ACC has no documented signature but has been matched
// TODO: func_global_asm_80709BC4 has no documented signature
// TODO: func_global_asm_8070A220 has no documented signature
// TODO: func_global_asm_8070A848 has no documented signature
// TODO: func_global_asm_8070A934 has no documented signature
void func_global_asm_8070AC74(Mtx *arg0, Gfx **dlp);
void func_global_asm_8070AF24(void);
// TODO: func_global_asm_8070B05C has no documented signature
void setIntroStoryPlaying(u8 arg0);
u8 isIntroStoryPlaying(void);
// TODO: func_global_asm_8070B324 has no documented signature
// TODO: func_global_asm_8070B7EC has no documented signature

// global_asm/code_110F00.c
// TODO: func_global_asm_8070C200 has no documented signature
void func_global_asm_8070C210(float (*mf)[4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_global_asm_8070C27C(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
// TODO: func_global_asm_8070C2D8 has no documented signature
void func_global_asm_8070C590(f32 (*arg0)[4], f32 (*arg1)[4], f32 (*arg2)[4]);
// TODO: func_global_asm_8070C808 has no documented signature
void func_global_asm_8070C89C(float (*mf)[4], f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_8070C8F4(float (*mf)[4], f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_8070C990(float (*mf)[4], f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_8070C9E8(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_8070CA2C(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_8070CA70(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_8070CAB4(float (*mf)[4], f32 arg1);
void func_global_asm_8070CB2C(float (*mf)[4], f32 arg1);
void func_global_asm_8070CBA4(float (*mf)[4], f32 arg1);
void func_global_asm_8070CC1C(Mtx *arg0, f32 arg1);
void func_global_asm_8070CC54(Mtx *arg0, f32 arg1);
void func_global_asm_8070CC8C(Mtx *arg0, f32 arg1);
void func_global_asm_8070CCC4(float (*mf)[4]);
void func_global_asm_8070CD14(Mtx *arg0);
void func_global_asm_8070CD44(float (*mf)[4], f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_8070CD8C(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_8070CDD0(f32 (*arg0)[4], f32 (*arg1)[4], f32 arg2, f32 arg3, f32 arg4);
void func_global_asm_8070D020(Mtx *arg0, Mtx *arg1, f32 arg2, f32 arg3, f32 arg4);
void func_global_asm_8070D07C(f32 (*mf)[4], f32 (*mf2)[4], f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_global_asm_8070D300(Mtx *arg0, Mtx *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);

// global_asm/code_112080.c
// TODO: func_global_asm_8070D380 has no documented signature but has been matched
// TODO: func_global_asm_8070D3CC has no documented signature but has been matched
// TODO: func_global_asm_8070D464 has no documented signature but has been matched
// TODO: func_global_asm_8070D568 has no documented signature but has been matched
// TODO: func_global_asm_8070D654 has no documented signature but has been matched
// TODO: func_global_asm_8070D6D8 has no documented signature but has been matched
// TODO: func_global_asm_8070D754 has no documented signature but has been matched
// TODO: func_global_asm_8070D82C has no documented signature
void loadText(Actor *arg0, u16 fileIndex, u8 textIndex);
// TODO: func_global_asm_8070D928 has no documented signature but has been matched
void func_global_asm_8070D970(u16 arg0);
void func_global_asm_8070D9AC(Struct806A57C0_2 *arg0);
void func_global_asm_8070DA28(AAD_global_asm_806A4DDC *arg0);
void func_global_asm_8070DA74(Actor *arg0);
// TODO: func_global_asm_8070DB7C has no documented signature but has been matched
// TODO: func_global_asm_8070DB9C has no documented signature
// TODO: func_global_asm_8070DC40 has no documented signature but has been matched
// TODO: func_global_asm_8070DCA4 has no documented signature but has been matched
// TODO: func_global_asm_8070DD18 has no documented signature but has been matched
// TODO: func_global_asm_8070DD44 has no documented signature
s32 func_global_asm_8070DDDC(u16 arg0, s32 arg1);
// TODO: func_global_asm_8070DED4 has no documented signature
// TODO: func_global_asm_8070E2AC has no documented signature but has been matched
void func_global_asm_8070E34C(void *arg0, void *arg1, s32 arg2);
void func_global_asm_8070E548(Actor *arg0, u16 arg1, u8 arg2);
char *getTextString(u8 fileIndex, s32 stringIndex, s32 arg2);
void func_global_asm_8070E808(Actor *arg0, Actor *arg1);
void func_global_asm_8070E8C8(void);
void func_global_asm_8070E8DC(u8 arg0);

// global_asm/code_1135F0.c
// TODO: func_global_asm_8070E8F0 has no documented signature
void func_global_asm_8070F2C8(s16 arg0, s16 arg1, u8 arg2, u8 arg3);
void func_global_asm_8070F2FC(Gfx **arg0, s16 arg1, s16 arg2);

// global_asm/code_114270.c
void func_global_asm_8070F570(void);
void func_global_asm_8070F5CC(s32 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, u8 arg5);
// TODO: func_global_asm_8070FA58 has no documented signature but has been matched
// TODO: func_global_asm_8070FC40 has no documented signature but has been matched
// TODO: func_global_asm_8070FCCC has no documented signature
// TODO: func_global_asm_8071006C has no documented signature but has been matched
// TODO: func_global_asm_80710174 has no documented signature but has been matched
// TODO: func_global_asm_807102AC has no documented signature
// TODO: func_global_asm_807103E0 has no documented signature
// TODO: func_global_asm_807105D4 has no documented signature
Gfx *func_global_asm_80710CA0(Gfx *dl, Actor *arg1);
void func_global_asm_80711410(f32 arg0, s16 arg1, f32 arg2, s16 arg3, f32 arg4);
// TODO: func_global_asm_80711950 has no documented signature
// TODO: func_global_asm_80711BD0 has no documented signature
void func_global_asm_80711F90(f32 arg0, s16 arg1, f32 arg2, s16 arg3, f32 arg4);
s32 func_global_asm_807122B4(void);
void func_global_asm_80712490(Maps newMap, s32 newExit, u8 newGameMode);
void func_global_asm_807124B8(Maps newMap, s32 cutsceneIndex, u8 newGameMode);
void func_global_asm_80712524(Maps newMap, s32 cutsceneIndex);
s32 func_global_asm_80712548(void);
void func_global_asm_80712574(void);
void func_global_asm_8071261C(void);
u8 func_global_asm_80712628(void);
void func_global_asm_80712634(Maps newMap, s32 arg1);
int gameIsInDKTheatreMode(void);
void func_global_asm_8071268C(void);
void func_global_asm_807126B0(Maps newMap, s32 newExit, s32 characterIndex, s8 moves, s8 simianSlam, s8 instrument, s8 melons);
void func_global_asm_80712774(Maps newMap);
s32 func_global_asm_80712798(void);
void func_global_asm_807127B4(void);
void func_global_asm_807127F4(s32 isDKTheatre);
void func_global_asm_80712830(Actor *arg0, s32 exit);
void func_global_asm_80712944(OSContPad *arg0);
void func_global_asm_80712A40(void);

// global_asm/code_117880.c
void func_global_asm_80712B80(void);
// TODO: func_global_asm_80712BD4 has no documented signature
void func_global_asm_80712EDC(void);
void func_global_asm_80712F10(Maps *arg0, s32 *arg1);
void func_global_asm_80712FC8(void);
void func_global_asm_80713088(void);
void func_global_asm_807130D4(void);
void func_global_asm_80713168(void);
void func_global_asm_807131BC(void);
void func_global_asm_8071321C(void);
void func_global_asm_80713270(void);
Gfx *func_global_asm_807132DC(Gfx *dl);
Gfx *func_global_asm_8071338C(Gfx *dl);
Gfx *func_global_asm_80713438(Gfx *dl, u8 arg1);
Gfx *func_global_asm_807135B4(Gfx *dl);
s32 func_global_asm_8071375C(s32 arg0);
Gfx *func_global_asm_80713764(Gfx *dl, u8 arg1, f32 arg2);
Gfx *func_global_asm_807138A4(Gfx *dl);
// TODO: func_global_asm_807138CC has no documented signature
Gfx *func_global_asm_80713AA8(Gfx *dl);
// TODO: func_global_asm_80713B40 has no documented signature
// TODO: func_global_asm_80713C8C has no documented signature
Gfx *func_global_asm_80713DFC(Gfx *dl);
s32 func_global_asm_80713EA8(s32 arg0);
// TODO: func_global_asm_80713EB0 has no documented signature
// TODO: func_global_asm_80714060 has no documented signature
int gameIsInDKTVMode(void);
int gameIsInAdventureMode(void);
int func_global_asm_80714360(void);
int gameIsInQuitGameMode(void);
int gameIsInSnidesBonusGameMode(void);
int gameIsInMysteryMenuMinigameMode(void);
int gameIsInMainMenuMode(void);
int func_global_asm_80714464(void);
void func_global_asm_807144B8(s8 arg0);
void func_global_asm_8071458C(void);
void func_global_asm_807145F8(void);
int func_global_asm_80714608(s32 arg0);
void func_global_asm_80714638(void);
void func_global_asm_80714660(void);

// global_asm/code_119370.c
void func_global_asm_80714670(void);
s32 func_global_asm_807146A4(s32 arg0);
void func_global_asm_807146E0(u8 *arg0, u8 *arg1, u8 *arg2);
void func_global_asm_807146F4(s16 *arg0, s16 *arg1, s16 *arg2);
void func_global_asm_80714708(u8 *arg0, s16 *arg1, s16 *arg2);
// TODO: func_global_asm_80714778 has no documented signature
void func_global_asm_80714944(s32 arg0);
void func_global_asm_80714950(s32 arg0);
void func_global_asm_8071495C(void);
void func_global_asm_8071496C(s16 arg0);
void func_global_asm_8071497C(u16 arg0);
void func_global_asm_8071498C(void *arg0);
void func_global_asm_80714998(u8 arg0);
void func_global_asm_807149A8(s16 arg0);
void func_global_asm_807149B8(u8 arg0);
void changeActorColor(u8 red, u8 green, u8 blue, u8 alpha);
void func_global_asm_807149FC(s32 arg0);
void func_global_asm_80714A08(f32 arg0, f32 arg1);
void func_global_asm_80714A28(u16 arg0);
void func_global_asm_80714A38(u8 arg0);
void func_global_asm_80714A58(u16 arg0);
void func_global_asm_80714A68(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_global_asm_80714A9C(void);
Struct80717D84 *func_global_asm_80714B84(void *arg0, f32 arg1, s32 arg2, s32 arg3, u8 arg4);
Struct80717D84 *func_global_asm_80714C08(void *sprite, f32 scale, Actor *actor, s32 boneIndex, u8 arg4);
Struct80717D84 *drawSpriteAtPosition(void *sprite, f32 scale, f32 x, f32 y, f32 z);
Struct80717D84 *func_global_asm_80714D08(void *sprite, f32 scale, f32 x, f32 y, f32 z, Actor *actor, s32 arg6, s32 boneIndex, u8 arg8);
// TODO: func_global_asm_8071509C has no documented signature
// TODO: func_global_asm_80715270 has no documented signature
void func_global_asm_8071586C(Actor *arg0);
void func_global_asm_807158C0(void);
void func_global_asm_80715908(void *arg0);
// TODO: func_global_asm_80715A3C has no documented signature
// TODO: func_global_asm_80715B30 has no documented signature
void func_global_asm_80715E38(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
// TODO: func_global_asm_80715E94 has no documented signature
void func_global_asm_80716F10(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_80716FB4(Struct80717D84 *arg0, s32 arg1);

// global_asm/code_11BE00.c
// TODO: func_global_asm_80717100 has no documented signature
void func_global_asm_8071720C(Struct80717D84 *arg0, s32 arg1);
// TODO: func_global_asm_80717404 has no documented signature
void func_global_asm_80717760(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_80717814(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_80717930(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_80717B64(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_80717CE8(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_80717D4C(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_80717D84(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_80717DB4(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_80717F1C(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_80718080(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_807180F4(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_80718124(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_80718188(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071827C(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_80718380(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_807184F4(Struct80717D84 *arg0, s32 arg1);
// TODO: func_global_asm_807186C8 has no documented signature
void func_global_asm_807189BC(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_80718BF4(Struct80717D84 *arg0, s8 *arg1);
// TODO: func_global_asm_8071910C has no documented signature
// TODO: func_global_asm_807195D4 has no documented signature
// TODO: func_global_asm_807197B4 has no documented signature
void func_global_asm_80719A0C(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_80719B88(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_80719C00(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_80719EF4(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071A038(Struct80717D84 *arg0, s32 arg1);
// TODO: func_global_asm_8071A1E4 has no documented signature
void func_global_asm_8071A440(Struct80717D84 *arg0, s32 arg1);
// TODO: func_global_asm_8071A674 has no documented signature
void func_global_asm_8071A8B0(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071AADC(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071ABDC(otherSpriteControl *, s8 *); // TODO: Datatype
void func_global_asm_8071AF30(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071B1AC(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071B24C(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071B2EC(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071B44C(Struct80717D84 *arg0, s32 arg1);
// TODO: func_global_asm_8071B520 has no documented signature
void func_global_asm_8071B758(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071B89C(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071B8EC(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071BB14(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071BC80(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071BE04(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071C004(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071C24C(Struct80717D84 *arg0, u8 *arg1);
// TODO: func_global_asm_8071C48C has no documented signature
void func_global_asm_8071C620(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071C818(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071C914(Struct80717D84 *arg0, s32 arg1);
// TODO: func_global_asm_8071C9E8 has no documented signature
// TODO: func_global_asm_8071CDE0 has no documented signature
void func_global_asm_8071D0F0(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071D260(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071D28C(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071D5BC(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071D784(Struct80717D84 *arg0, s8 *arg1);
// TODO: func_global_asm_8071D94C has no documented signature
void func_global_asm_8071DB74(Struct80717D84 *arg0, u8 *arg1);
void func_global_asm_8071DC90(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071E028(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071E110(Struct80717D84 *arg0, u8 arg1, u16 arg2, f32 arg3, f32 arg4, s32 arg5);
void func_global_asm_8071E1C8(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071E3EC(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071E864(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071EA24(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071EB70(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071EDEC(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071EEA4(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071EEE0(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071EFDC(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071F034(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071F078(Struct80717D84 *arg0, s32 arg1);
// TODO: func_global_asm_8071F1D0 has no documented signature
void func_global_asm_8071F2F8(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071F3C0(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071F444(Struct80717D84 *arg0, s8 *arg1);
void func_global_asm_8071F660(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071F758(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_8071F8E4(Struct80717D84 *arg0, u8 *arg1);

// global_asm/code_126260.c
void func_global_asm_80721560(s16 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5);
void func_global_asm_807215AC(s8 arg0, s8 arg1, s8 arg2);
void func_global_asm_807215D0(s8 arg0, s8 arg1);
void func_global_asm_807215EC(void);
void func_global_asm_8072167C(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void addActorRecolor(Actor *actor, s16 x, s16 y, s16 z, u8 alpha, u8 red, u8 green, u8 blue, u8);
// TODO: func_global_asm_80721814 has no documented signature
void func_global_asm_80722280(void);
// TODO: func_global_asm_80722294 has no documented signature

// global_asm/code_127B00.c
void func_global_asm_80722E00(Maps map);
// TODO: func_global_asm_80722E48 has no documented signature but has been matched
s32 func_global_asm_80722FEC(u8 arg0);
s32 func_global_asm_80723020(Actor *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6);
void func_global_asm_80723284(s32 arg0, u8 arg1);
void func_global_asm_807232B8(s32 arg0, u8 arg1);
void func_global_asm_807232EC(s32 arg0, u8 arg1);
void func_global_asm_80723320(s32 arg0, s32 arg1);
void func_global_asm_8072334C(s32 arg0, u8 arg1);
void func_global_asm_80723380(s32 arg0, u8 arg1);
void func_global_asm_807233B4(Actor *arg0);
void func_global_asm_80723428(s32 arg0);
void func_global_asm_80723484(s32 arg0, Actor *arg1);
// TODO: func_global_asm_807238D4 has no documented signature
u8 func_global_asm_80723C98(s32 arg0);
// TODO: func_global_asm_80723CCC has no documented signature
// TODO: func_global_asm_80723F88 has no documented signature
void func_global_asm_80724154(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 *arg4, f32 *arg5);
// TODO: func_global_asm_80724308 has no documented signature
s16 func_global_asm_807245D8(s32 arg0);

// global_asm/done/code_1292F0.c
void func_global_asm_807245F0(Actor *arg0, u8 arg1);
void func_global_asm_80724874(Actor *arg0);

// global_asm/code_1295B0.c
void func_global_asm_807248B0(Actor *arg0, f32 arg1);
void func_global_asm_80724994(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
s32 func_global_asm_80724A20(void);
void func_global_asm_80724A9C(u8 arg0, u8 arg1, u8 arg2);
void func_global_asm_80724B5C(u8 arg0, u8 arg1, f32 *x, f32 *y, f32 *z);
void func_global_asm_80724C2C(s16 arg0);
void func_global_asm_80724C78(void* arg0);
void func_global_asm_80724CA4(s16 arg0, s16 arg1);
void func_global_asm_80724D28(s16 arg0, s16 arg1);
void func_global_asm_80724DB0(s16 arg0, s16 arg1);
void func_global_asm_80724E48(u8 arg0);
// TODO: func_global_asm_807255A8 has no documented signature
u8 func_global_asm_80725B38(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
// TODO: func_global_asm_80725BA4 has no documented signature but has been matched
u8 func_global_asm_80725DC0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6);
// TODO: func_global_asm_80725ED4 has no documented signature
s32 func_global_asm_80726164(Actor *actor, s16 x, s16 y, s16 z, FenceStruct *arg4);
// TODO: func_global_asm_807264B0 has no documented signature
void func_global_asm_807266E8(Actor *arg0, CharacterSpawner *arg1);
// TODO: func_global_asm_80726744 has no documented signature
u8 func_global_asm_80726D7C(u8 arg0);
u8 func_global_asm_80726DC0(u8 arg0);
u8 func_global_asm_80726DEC(u8 arg0, u8 arg1);
void func_global_asm_80726E60(u16 arg0, u8 arg1);
void func_global_asm_80726EE0(u8 arg0);
void func_global_asm_8072707C(s16 arg0, u8 arg1, u16 arg2);
Actor *getSpawnerTiedActor(s16 spawn_trigger, u16 arg1);
u8 func_global_asm_80727194(Actor *arg0);
Actor *func_global_asm_807271F4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6);
void func_global_asm_807273A8(s16 arg0, u8 arg1);
void func_global_asm_8072752C(s16 arg0, s16 x1, s16 y1, s16 z1, s16 x2, s16 y2, s16 z2, s16 arg7, s16 arg8);
void func_global_asm_80727678(void);
void func_global_asm_807278C0(EnemySpawner *arg0);
void func_global_asm_80727958(void);
u8 func_global_asm_80727F20(EnemyInfo *arg0, s32 arg1);
u8 func_global_asm_80728004(EnemyInfo *arg0, s32 arg1);
u8 func_global_asm_807280C8(EnemyInfo *arg0, s32 arg1);
// TODO: func_global_asm_8072818C has no documented signature
// TODO: func_global_asm_8072827C has no documented signature but has been matched
// TODO: func_global_asm_80728300 has no documented signature
// TODO: func_global_asm_8072881C has no documented signature
void func_global_asm_80728950(u8 arg0);
void func_global_asm_807289B0(u8 arg0, u8 arg1);
// TODO: func_global_asm_807289E8 has no documented signature
void func_global_asm_80729AA4(u8 arg0);

// global_asm/code_12E800.c
void initializeCharacterSpawnerActor(void);
void func_global_asm_80729E6C(void);
// TODO: func_global_asm_80729EB0 has no documented signature
// TODO: func_global_asm_8072A450 has no documented signature
void func_global_asm_8072A714(void);
void func_global_asm_8072A7DC(void);
// TODO: func_global_asm_8072A86C has no documented signature
void func_global_asm_8072A920(s16 arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, f32 arg6, f32 arg7, u16 arg8);
// TODO: func_global_asm_8072AA80 has no documented signature
u8 func_global_asm_8072AB74(u8 arg0, f32 x, f32 z, u16 arg3, f32 arg4);
void func_global_asm_8072B324(Actor *arg0, s32 arg1);
void func_global_asm_8072B330(u16 arg0);
void func_global_asm_8072B438(u16 arg0);
void func_global_asm_8072B59C(u8 arg0, s16 arg1, s32 arg2);
void func_global_asm_8072B608(void);
void func_global_asm_8072B79C(s16 arg0, s16 arg1, s16 arg2);
void func_global_asm_8072B7CC(s32 arg0);
u8 func_global_asm_8072C670(u8 arg0, s8 *arg1);
void func_global_asm_8072C870(u8 arg0, u8 arg1, s32 arg2);
// TODO: func_global_asm_8072C918 has no documented signature
void func_global_asm_8072CFE8(s16 *arg0, s16 *arg1, s16 *arg2);
void func_global_asm_8072D08C(void);
u8 func_global_asm_8072D13C(u8 arg0, s32 arg1);
void func_global_asm_8072D714(Actor *arg0, s32 arg1);
void func_global_asm_8072D99C(void);
void func_global_asm_8072D9D4(void);
void func_global_asm_8072DA60(void);
void func_global_asm_8072DAA4(void);
void func_global_asm_8072DB68(s32 arg0);
void func_global_asm_8072DC7C(u8 arg0);
// TODO: func_global_asm_8072DCF4 has no documented signature
s32 func_global_asm_8072DE10(u16 arg0);
void func_global_asm_8072DE44(s32 arg0);
void func_global_asm_8072DEA8(s32 arg0, u8 arg1, Actor *arg2);
void func_global_asm_8072E02C(void);
// TODO: func_global_asm_8072E0A8 has no documented signature
void func_global_asm_8072E1A4(u8 arg0, Actor *arg1);
u8 func_global_asm_8072E22C(u16 arg0);
void func_global_asm_8072E2B0(Actor *arg0, f32 *arg1, f32 *arg2, f32 *arg3);
void func_global_asm_8072E320(f32 arg0);
u8 func_global_asm_8072E54C(void);

// global_asm/done/triggers.c
u8 func_global_asm_8072E5B0(void);
// TODO: func_global_asm_8072E5FC has no documented signature but has been matched
void func_global_asm_8072E740(Maps map);
s32 func_global_asm_8072E7DC(s16 arg0, Actor **arg1);
void func_global_asm_8072E868(void);
// TODO: func_global_asm_8072EA90 has no documented signature but has been matched
void func_global_asm_8072EC94(s32 arg0, u8 arg1);
void func_global_asm_8072ECFC(s32 arg0, s16 arg1, s16 arg2, s16 arg3);

// global_asm/code_133A90.c
void func_global_asm_8072ED90(void);
void func_global_asm_8072ED9C(Actor *arg0, u8 arg1, u8 arg2);
void func_global_asm_8072EE0C(Actor *arg0, u8 arg1, u8 arg2);
void func_global_asm_8072EE7C(Actor *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, u8 argB, f32 argC, f32 argD, u8 argE);
void func_global_asm_8072EF7C(Actor *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, f32 arg5, f32 arg6, f32 arg7, u8 arg8, s16 arg9, s16 argA, s16 argB, s16 argC);
void func_global_asm_8072F09C(Actor *arg0);
void func_global_asm_8072F120(void);
// TODO: func_global_asm_8072F230 has no documented signature
u8 func_global_asm_8072F4A8(Actor *arg0, u8 arg1, f32 *arg2, f32 *arg3, f32 *arg4);
// TODO: func_global_asm_8072F59C has no documented signature
s32 func_global_asm_8072F8D4(Struct807FDCC0 *arg0, s32 arg1, s16 arg2);
f32 func_global_asm_8072FA14(Actor *arg0, PlayerAdditionalActorData *arg1, Struct807FDCC0 *arg2, u8 arg3);
// TODO: func_global_asm_8072FCC4 has no documented signature
void func_global_asm_8072FDD4(Struct807FDCC0 *arg0, f32 arg1, s8 *arg2, f32 *arg3);
// TODO: func_global_asm_8072FE60 has no documented signature
// TODO: func_global_asm_807300BC has no documented signature
// TODO: func_global_asm_80730408 has no documented signature
void func_global_asm_80730AEC(u8 arg0, f32 arg1, Struct807FDCC0 *arg2, f32 *arg3, f32 *arg4, f32 *arg5);
void func_global_asm_80730D60(Actor *arg0, u8 arg1, u8 arg2, u8 arg3, void **arg4, void **arg5);
// TODO: func_global_asm_80730E18 has no documented signature

// global_asm/code_135D30.c
void func_global_asm_80731030(void); // clearTemporaryFlags()
void clearPermanentFlags(void);
void clearGlobalFlags(void);
u8 isFlagSet(s16 flagIndex, u8 flagType);
void func_global_asm_807311C4(s16 arg0);
void setFlag(s16 flagIndex, u8 newValue, u8 flagType);
void func_global_asm_807313BC(void);
void func_global_asm_80731410(s16 arg0, s16 arg1, s16 arg2, u8 arg3);
void func_global_asm_807314F4(s16 arg0, s16 arg1);
u8 func_global_asm_807315D4(s16 arg0, s16 arg1);
u8 func_global_asm_80731654(s16 arg0, s16 arg1);
s16 func_global_asm_80731784(s16 map, s16 spawnerID, s32 *arg2);
s32 func_global_asm_807317FC(s16 arg0, s16 arg1);
s32 func_global_asm_807318AC(s16 arg0, s16 arg1);
s16 func_global_asm_8073195C(s16 arg0);
u8 func_global_asm_8073198C(s16 arg0);
s32 func_global_asm_807319D8(s32 arg0, s32 arg1, s32 arg2);
s32 func_global_asm_80731A04(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 countSetFlags(s32 startIndex, s32 length, u8 flagType);

// global_asm/code_136820.c
void func_global_asm_80731B20(s32 arg0, s32 arg1, s32 arg2);
void func_global_asm_80731B60(s32 arg0);
void func_global_asm_80731B88(u8 arg0);
void func_global_asm_80731D20(char*, ...);
// TODO: func_global_asm_80731E68 has no documented signature
// TODO: func_global_asm_8073202C has no documented signature
// TODO: func_global_asm_80732064 has no documented signature
s32 func_global_asm_8073209C(s32 instruction, s32 *shift, s32 *addr, s32 **addr_0);
void func_global_asm_80732158(OSThread *arg0);
// TODO: func_global_asm_80732280 has no documented signature
void raiseException(u8 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_global_asm_8073239C(void);

// global_asm/audio/heap.c
// TODO: alHeapInit has no documented signature but has been matched
// TODO: alHeapDBAlloc has no documented signature but has been matched

// global_asm/audio/bnkf.c
// TODO: alSeqFileNew has no documented signature but has been matched
// TODO: alBnkfNew has no documented signature but has been matched
// TODO: _bnkfPatchBank has no documented signature but has been matched
// TODO: _bnkfPatchInst has no documented signature but has been matched
// TODO: _bnkfPatchSound has no documented signature but has been matched
// TODO: _bnkfPatchWaveTable has no documented signature but has been matched

// global_asm/audio/code_137630.c
// TODO: func_global_asm_80732930 has no documented signature
// TODO: func_global_asm_807329AC has no documented signature but has been matched
// TODO: func_global_asm_80732B3C has no documented signature but has been matched
// TODO: func_global_asm_80732D80 has no documented signature but has been matched
f32 func_global_asm_80732DAC(f32 arg0);
// TODO: func_global_asm_80732DEC has no documented signature but has been matched

// global_asm/audio/csplayer.c
// TODO: func_global_asm_80732F10 has no documented signature but has been matched
// TODO: func_global_asm_80733180 has no documented signature
// TODO: func_global_asm_80733A88 has no documented signature but has been matched
// TODO: func_global_asm_80733B88 has no documented signature
// TODO: func_global_asm_80733C34 has no documented signature
// TODO: func_global_asm_80733D8C has no documented signature
// TODO: func_global_asm_80735624 has no documented signature but has been matched
// TODO: func_global_asm_80735864 has no documented signature but has been matched
// TODO: func_global_asm_80735958 has no documented signature but has been matched
// TODO: func_global_asm_807359A0 has no documented signature but has been matched
// TODO: func_global_asm_80735A34 has no documented signature but has been matched

// global_asm/audio/cspsetbank.c
void func_global_asm_80735A50(ALSeqPlayer *arg0, ALBank *arg1);

// global_asm/audio/code_13A7A0.c
// TODO: func_global_asm_80735AA0 has no documented signature
// TODO: func_global_asm_80735CF4 has no documented signature but has been matched
// TODO: func_global_asm_80735DBC has no documented signature
// TODO: func_global_asm_80736FB8 has no documented signature but has been matched
// TODO: func_global_asm_80737028 has no documented signature but has been matched
// TODO: func_global_asm_807370A4 has no documented signature but has been matched
// TODO: func_global_asm_80737198 has no documented signature but has been matched
// TODO: func_global_asm_8073726C has no documented signature
// TODO: func_global_asm_8073749C has no documented signature but has been matched
// TODO: func_global_asm_807375E0 has no documented signature but has been matched
// TODO: func_global_asm_80737608 has no documented signature but has been matched
struct sndstate *func_global_asm_80737638(ALBank *arg0, s16 soundnum, u16 vol, ALPan pan, f32 pitch, u8 fxmix, struct sndstate **handleptr);
// TODO: func_global_asm_80737924 has no documented signature but has been matched
void func_global_asm_80737990(u8 arg0);
void func_global_asm_80737A4C(void);
void func_global_asm_80737A74(void);
void func_global_asm_80737A9C(void);
void func_global_asm_80737AC4(s32 arg0, s16 arg1, s32 arg2);
u16 func_global_asm_80737B2C(u8 arg0);
void func_global_asm_80737B58(u8 arg0, u16 arg1);

// global_asm/audio/code_13C920.c
void func_global_asm_80737C20(s32 arg0);
void func_global_asm_80737CF4(s32 arg0, s32 arg1);

// global_asm/audio/seqpgetstate.c
s32 func_global_asm_80737E30(ALSeqPlayer *seqp);

// global_asm/audio/cspplay.c
void func_global_asm_80737E50(ALCSPlayer *seqp);

// global_asm/audio/code_13CB90.c
// TODO: func_global_asm_80737E90 has no documented signature but has been matched
// TODO: func_global_asm_80737EA4 has no documented signature but has been matched
// TODO: func_global_asm_80737F0C has no documented signature but has been matched
// TODO: func_global_asm_80737F40 has no documented signature but has been matched
// TODO: func_global_asm_80737FD8 has no documented signature
// TODO: func_global_asm_8073801C has no documented signature
// TODO: func_global_asm_80738080 has no documented signature
// TODO: func_global_asm_807380CC has no documented signature
// TODO: func_global_asm_80738118 has no documented signature

// global_asm/audio/code_13CE70.c
void func_global_asm_80738170(ALSeqPlayer *seqp, u8 arg1, u8 arg2);
void func_global_asm_807381D8(ALSeqPlayer *seqp, f32 arg1, f32 arg2);
void func_global_asm_80738230(ALSeqPlayer *seqp, u8 arg1, u8 arg2);

// global_asm/audio/code_13CFA0.c
void func_global_asm_807382A0(ALSeqPlayer *seqp, s32 arg1, u8 arg2, u8 arg3, u8 arg4);

// global_asm/audio/code_13D020.c
// TODO: func_global_asm_80738320 has no documented signature but has been matched

// global_asm/audio/code_13D0B0.c
s32 func_global_asm_807383B0(ALSeqPlayer *arg0);

// global_asm/audio/code_13D100.c
void func_global_asm_80738400(ALSeqPlayer *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4);

// global_asm/audio/cseq.c
// TODO: alCSeqSetLoc has no documented signature but has been matched
// TODO: alCSeqGetLoc has no documented signature but has been matched
// TODO: n_alCSeqNewMarker has no documented signature but has been matched
// TODO: func_global_asm_80738E58 has no documented signature
// TODO: __getTrackByte has no documented signature but has been matched
// TODO: __readVarLen has no documented signature but has been matched

// global_asm/audio/n_sl.c
void n_alInit(N_ALGlobals *g, ALSynConfig *c);
void n_alClose(N_ALGlobals *glob);

// global_asm/audio/link.c
void alLink(ALLink *ln, ALLink *to);
void alUnlink(ALLink *ln);

// global_asm/audio/synthesizer.c
// TODO: n_alSynNew has no documented signature
// TODO: n_alAudioFrame has no documented signature
// TODO: __n_allocParam has no documented signature but has been matched
// TODO: __n_freeParam has no documented signature but has been matched
void _n_collectPVoices();
// TODO: _n_freePVoice has no documented signature but has been matched
s32 _n_timeToSamplesNoRound(s32 micros);
// TODO: func_global_asm_80739E24 has no documented signature

// global_asm/audio/seqpstop.c
void alSeqpStop(ALSeqPlayer *seqp);

// global_asm/audio/seqpsetseq.c
void alSeqpSetSeq(ALSeqPlayer *seqp, ALSeq *seq);

// global_asm/audio/seqpsetvol.c
void alSepqSetVol(ALSeqPlayer *seqp, s16 vol);

// global_asm/audio/code_13ECE0.c
// TODO: func_global_asm_80739FE0 has no documented signature
// TODO: __n_unmapVoice has no documented signature
// TODO: __n_seqpReleaseVoice has no documented signature
// TODO: __n_voiceNeedsNoteKill has no documented signature
// TODO: __n_mapVoice has no documented signature
// TODO: __n_lookupVoice has no documented signature
// TODO: __n_lookupSoundQuick has no documented signature
// TODO: __n_vsVol has no documented signature but has been matched
// TODO: func_global_asm_8073A7B8 has no documented signature
// TODO: __n_vsDelta has no documented signature but has been matched
// TODO: __n_vsPan has no documented signature but has been matched
// TODO: __n_initFromBank has no documented signature but has been matched
// TODO: __n_initChanState has no documented signature but has been matched
// TODO: __n_resetPerfChanState has no documented signature but has been matched
// TODO: __n_setInstChanState has no documented signature but has been matched
// TODO: __n_seqpStopOsc has no documented signature

// global_asm/audio/event.c
void alEvtqNew(ALEventQueue *evtq, ALEventListItem *items, s32 itemCount);
ALMicroTime alEvtqNextEvent(ALEventQueue *evtq, ALEvent *evt);
void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);
void alEvtqFlushType(ALEventQueue *evtq, s16 type);

// global_asm/audio/synaddplayer.c
void func_global_asm_8073B560(ALPlayer *arg0);

// global_asm/audio/code_1402D0.c
void func_global_asm_8073B5D0(ALPlayer *arg0);
void func_global_asm_8073B640(ALPlayer *arg0);

// global_asm/audio/n_synstopvoice.c
// TODO: n_alSynStopVoice has no documented signature but has been matched

// global_asm/audio/synfreevoice.c
// TODO: func_global_asm_8073B750 has no documented signature but has been matched

// global_asm/audio/synsetvol.c
// TODO: func_global_asm_8073B830 has no documented signature but has been matched

// global_asm/audio/n_synsetpitch.c
// TODO: func_global_asm_8073B900 has no documented signature but has been matched
// TODO: func_global_asm_8073B9B0 has no documented signature but has been matched
// TODO: func_global_asm_8073BA60 has no documented signature but has been matched
void func_global_asm_8073BB10(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4);
void _init_lpfilter(Struct8073BC74 *arg0);
// TODO: func_global_asm_8073BDC4 has no documented signature
void func_global_asm_8073BE54(Struct8073BC74 *arg0, f32 arg1);
// TODO: n_alFxNew has no documented signature but has been matched
// TODO: alN_PVoiceNew has no documented signature but has been matched

// global_asm/audio/code_141520.c
// TODO: func_global_asm_8073C820 has no documented signature but has been matched
// TODO: func_global_asm_8073C8D0 has no documented signature but has been matched
// TODO: func_global_asm_8073C948 has no documented signature but has been matched
void func_global_asm_8073C9C0(s32 arg0, s16 arg1, s32 arg2);
// TODO: func_global_asm_8073CA04 has no documented signature but has been matched

// global_asm/audio/synallocvoice.c
// TODO: func_global_asm_8073CAC0 has no documented signature
// TODO: func_global_asm_8073CC94 has no documented signature but has been matched

// global_asm/audio/synstartvoiceparam.c
// TODO: func_global_asm_8073CDD0 has no documented signature but has been matched

// global_asm/audio/code_141C00.c
// TODO: func_global_asm_8073CF00 has no documented signature but has been matched
// TODO: func_global_asm_8073CFB0 has no documented signature but has been matched
// TODO: func_global_asm_8073D060 has no documented signature but has been matched

// global_asm/audio/n_syndelete.c
void n_alSynDelete(void);

// global_asm/audio/code_141E60.c
// TODO: func_global_asm_8073D160 has no documented signature but has been matched

// global_asm/audio/code_141EF0.c
// TODO: n_alFxPull has no documented signature
// TODO: n_alFxParamHdl has no documented signature
// TODO: _n_loadOutputBuffer has no documented signature
// TODO: _n_loadBuffer has no documented signature
// TODO: _n_saveBuffer has no documented signature but has been matched
// TODO: func_global_asm_8073E63C has no documented signature but has been matched
// TODO: _doModFunc has no documented signature but has been matched
// TODO: func_global_asm_8073E800 has no documented signature but has been matched

// global_asm/audio/synsetpriority.c
// TODO: func_global_asm_8073E8A0 has no documented signature but has been matched

// global_asm/audio/env.c
// TODO: n_alEnvmixerPull has no documented signature but has been matched
// TODO: n_alEnvmixerParam has no documented signature but has been matched
// TODO: _pullSubFrame has no documented signature but has been matched
s16 _getRate(f32 arg0, f32 arg1, s32 arg2, u16 *arg3);
// TODO: _getVol has no documented signature

// global_asm/audio/code_1445A0.c
// TODO: func_global_asm_8073F8A0 has no documented signature

// global_asm/audio/code_144A90.c
// TODO: func_global_asm_8073FD90 has no documented signature but has been matched

// global_asm/audio/code_144E00.c
// TODO: func_global_asm_80740100 has no documented signature
// TODO: func_global_asm_807407A8 has no documented signature
// TODO: func_global_asm_80740A90 has no documented signature but has been matched

// global_asm/audio/code_145950.c
// TODO: func_global_asm_80740C50 has no documented signature but has been matched
// TODO: func_global_asm_80740F48 has no documented signature but has been matched

// global_asm/audio/code_145D70.c
// TODO: func_global_asm_80741070 has no documented signature but has been matched
// TODO: func_global_asm_807412B4 has no documented signature but has been matched

// menu/code_0.c
// TODO: func_menu_80024000 has no documented signature but has been matched
// TODO: func_menu_800240BC has no documented signature but has been matched
// TODO: func_menu_80024154 has no documented signature but has been matched
void func_menu_800241E8(void);
// TODO: func_menu_80024224 has no documented signature but has been matched
// TODO: func_menu_80024418 has no documented signature but has been matched
Gfx *func_menu_800244EC(Gfx *dl, Actor *arg1);
// TODO: func_menu_80024788 has no documented signature
// TODO: func_menu_80024BFC has no documented signature but has been matched
void func_menu_80024CB0(void);
// TODO: func_menu_80024EF0 has no documented signature
// TODO: func_menu_800252AC has no documented signature
void func_menu_80025AE0(void);

// menu/code_1AF0.c
// TODO: func_menu_80025AF0 has no documented signature but has been matched
Gfx *func_menu_80025B64(Gfx *dl, Actor *arg1);
// TODO: func_menu_80025D14 has no documented signature but has been matched
// TODO: func_menu_80025D44 has no documented signature but has been matched
// TODO: func_menu_80025D8C has no documented signature but has been matched
// TODO: func_menu_80025E04 has no documented signature but has been matched
// TODO: func_menu_80025FB4 has no documented signature
// TODO: func_menu_800261C0 has no documented signature but has been matched
// TODO: func_menu_80026250 has no documented signature but has been matched
// TODO: func_menu_80026290 has no documented signature but has been matched
// TODO: func_menu_800262A8 has no documented signature
// TODO: func_menu_80026684 has no documented signature but has been matched
// TODO: func_menu_800266F0 has no documented signature but has been matched
// TODO: func_menu_80026804 has no documented signature but has been matched
// TODO: func_menu_80026874 has no documented signature but has been matched
// TODO: func_menu_80026B28 has no documented signature
// TODO: func_menu_80026DAC has no documented signature
// TODO: func_menu_80027028 has no documented signature but has been matched
// TODO: func_menu_800270E0 has no documented signature
s32 func_menu_800275EC(s32 arg0);
void func_menu_800275FC(void);
void func_menu_80027738(void);
Gfx *func_menu_80027808(Gfx *dl, Actor *arg1);
// TODO: func_menu_80027988 has no documented signature
void func_menu_80027DEC(void);

// menu/code_3E10.c
void func_menu_80027E10(void);
void func_menu_80027E60(Actor *arg0, s32 arg1);
Gfx *func_menu_80027F34(Actor *arg0, Gfx *dl);
void func_menu_80027F40(Actor *arg0, s32 arg1);
void func_menu_80027FAC(Actor *arg0, s32 arg1);
Gfx *func_menu_800286C8(Actor *arg0, Gfx *dl);
void func_menu_80028834(Actor *arg0, s32 arg1);
void func_menu_80028C18(void);
void func_menu_80028C20(Actor *arg0, s32 arg1);
Gfx *func_menu_80028D3C(Actor *arg0, Gfx *dl);
void func_menu_80028EA8(Actor *arg0, s32 arg1);
void func_menu_8002907C(void);
void func_menu_80029114(Actor *arg0, s32 arg1);
// TODO: func_menu_800291CC has no documented signature
s32 func_menu_800297A8(s32 arg0);
// TODO: func_menu_800297B8 has no documented signature
void func_menu_80029AAC(Actor *arg0, s32 arg1);
Gfx *func_menu_80029BB4(Actor *arg0, Gfx *dl);
void func_menu_80029D30(Actor *arg0, s32 arg1);
void func_menu_80029EF8(Actor *arg0, s32 arg1);
// TODO: func_menu_8002A088 has no documented signature
void func_menu_8002A36C(Actor *arg0, s32 arg1);
void func_menu_8002A468(Actor *arg0, s32 arg1);
// TODO: func_menu_8002A638 has no documented signature
void func_menu_8002AA98(s32 arg0, s32 arg1);
void func_menu_8002AB28(s32 arg0);
void func_menu_8002AB80(Actor *arg0, s32 arg1);
s32 func_menu_8002ACD4(s32 arg0);
s32 func_menu_8002AD50(s32 arg0);
// TODO: func_menu_8002ADC8 has no documented signature
// TODO: func_menu_8002B708 has no documented signature
void func_menu_8002C0C8(Actor *arg0, s32 arg1);
void func_menu_8002C584(Actor *arg0, s32 arg1);
// TODO: func_menu_8002C634 has no documented signature
// TODO: func_menu_8002C91C has no documented signature
void func_menu_8002CB18(void);
// TODO: func_menu_8002CFA4 has no documented signature
Gfx *func_menu_8002D520(Actor *arg0, Gfx *dl);
void func_menu_8002D7EC(Actor *arg0, s32 arg1);
void func_menu_8002D8AC(Actor *arg0, s32 arg1);
Gfx *func_menu_8002DBDC(Actor *arg0, Gfx *dl);
void func_menu_8002DEE8(Actor *arg0, s32 arg1);
void func_menu_8002DFA8(Actor *arg0, s32 arg1);
// TODO: func_menu_8002E420 has no documented signature
// TODO: func_menu_8002E8B8 has no documented signature
void func_menu_8002ECE8(void);
void func_menu_8002EE18(void);
// TODO: func_menu_8002EF68 has no documented signature
// TODO: func_menu_8002F284 has no documented signature
void func_menu_8002F6C8(Actor *arg0, s32 arg1);
// TODO: func_menu_8002F75C has no documented signature
void func_menu_8002F8EC(void);
// TODO: func_menu_8002F980 has no documented signature
// TODO: func_menu_8002FB88 has no documented signature
// TODO: func_menu_8002FC1C has no documented signature but has been matched
// TODO: func_menu_8002FD38 has no documented signature but has been matched
// TODO: func_menu_8002FE08 has no documented signature but has been matched
void func_menu_8002FEBC(void);
void func_menu_80030250(void);
Gfx *func_menu_80030258(Gfx *dl, Actor *arg1);
Gfx *func_menu_80030340(Actor *actor, s32 arg1, Gfx *dl, s32 arg3);
// TODO: func_menu_80030894 has no documented signature but has been matched
// TODO: func_menu_80030A90 has no documented signature but has been matched
// TODO: func_menu_80030C14 has no documented signature
// TODO: func_menu_8003155C has no documented signature
// TODO: func_menu_800317E8 has no documented signature but has been matched
// TODO: func_menu_80031980 has no documented signature
void func_menu_80031A5C(void);
void func_menu_80031B08(void);
// TODO: func_menu_80032024 has no documented signature
s32 func_menu_800322D0(s32 fileIndex);
s32 func_menu_80032304(void);
void func_menu_800324CC(void);

// menu/code_E550.c
void func_menu_80032550(void);
void func_menu_8003264C(void);
// TODO: func_menu_8003292C has no documented signature

// multiplayer/code_0.c
Gfx *func_multiplayer_80024000(Gfx *dl, Actor *arg1);
s32 func_multiplayer_800241F4(PlayerProgress *arg0, s32 playerIndex);
s32 func_multiplayer_80024254(s32 playerIndex);
void func_multiplayer_800242FC(void *aaD);
void func_multiplayer_800243C8(void);
void func_multiplayer_8002449C(void);
void func_multiplayer_8002452C(void);
// TODO: func_multiplayer_800245B0 has no documented signature
Gfx *func_multiplayer_800246EC(Gfx *dl, Struct800246EC *aaD, f32 arg2);
// TODO: func_multiplayer_800249D8 has no documented signature
// TODO: func_multiplayer_80024CA4 has no documented signature
// TODO: func_multiplayer_80025264 has no documented signature
// TODO: func_multiplayer_80025378 has no documented signature
s32 func_multiplayer_800253C8(void);
s32 func_multiplayer_80025404(void);
s32 func_multiplayer_80025608(s32 objectType);
// TODO: func_multiplayer_80025654 has no documented signature but has been matched
// TODO: func_multiplayer_80025794 has no documented signature
// TODO: func_multiplayer_80025B48 has no documented signature but has been matched
void func_multiplayer_80025CE8(s32 playerIndex);
void func_multiplayer_80025F84(void);
// TODO: func_multiplayer_80025FFC has no documented signature but has been matched
// TODO: func_multiplayer_80026094 has no documented signature
void func_multiplayer_800268C0(u8 arg0);
void func_multiplayer_800268DC(Actor *arg0, PlayerAdditionalActorData *arg1, PlayerProgress *arg2);
// TODO: func_multiplayer_8002698C has no documented signature but has been matched
void func_multiplayer_800269C8(u8 playerIndex, s8 arg1);
void func_multiplayer_80026B0C(s32 playerIndex);
s32 func_multiplayer_80026BD8(s32 arg0);
void func_multiplayer_80026D40(Actor *arg0, s32 arg1);
void func_multiplayer_80026E20(u8 playerIndex, s8 arg1);

// minecart/code_0.c
void func_minecart_80024000(u8 arg0, u8 arg1);
void func_minecart_800240DC(u8 arg0, u8 arg1);
void func_minecart_800241A0(s16 *arg0, u8 arg1, u8 arg2);
// TODO: func_minecart_80024254 has no documented signature but has been matched
void func_minecart_8002430C(u8 arg0, s32 arg1, s16 arg2, u8 arg3);
void func_minecart_80024768(void);
void func_minecart_80024890(void);
void func_minecart_80024914(void);
// TODO: func_minecart_80024B00 has no documented signature
// TODO: func_minecart_80024E78 has no documented signature but has been matched
void func_minecart_80024FD0(void);
// TODO: func_minecart_8002538C has no documented signature but has been matched
// TODO: func_minecart_800253C0 has no documented signature

// minecart/code_25F0.c
void func_minecart_800265F0(void);
// TODO: func_minecart_80026B6C has no documented signature but has been matched
void func_minecart_80026C54(void);
void func_minecart_80026DA8(void);
void func_minecart_80027778(void);
void func_minecart_80027CF4(void);
// TODO: func_minecart_80027DA0 has no documented signature but has been matched
void func_minecart_80027E04(void);
// TODO: func_minecart_80027EE8 has no documented signature but has been matched
void func_minecart_800280BC(void);
void func_minecart_8002835C(void);
void func_minecart_800286EC(void);

// bonus/code_0.c
Gfx *func_bonus_80024000(Gfx *dl, Actor *arg1);
void func_bonus_800240F0(void);
void func_bonus_80024158(void);
Gfx *func_bonus_80024D3C(Gfx *dl, s32 arg1);
s32 func_bonus_80024D8C(void);
void func_bonus_80024E38(void);

// bonus/code_12A0.c
Gfx *func_bonus_800252A0(Gfx *dl, Actor *arg1);
Actor* func_bonus_800253E4(s32 model, s16 x, s16 y, s16 z);
u8 func_bonus_80025480(Actor **arg0, u8 arg1);
void func_bonus_800254B0(s16 x, s16 y, s16 z, s16 count);
void func_bonus_8002563C(s32 arg0);
void func_bonus_800256C4(Actor **arg0, u8 arg1);
// TODO: func_bonus_8002570C has no documented signature
void func_bonus_800261B8(void);
void func_bonus_800264E0(u8 arg0, u8 textIndex);
void func_bonus_800265C0(u8 arg0, u8 textIndex);

// bonus/code_2690.c
Gfx *func_bonus_80026690(Gfx *dl, Actor *arg1);
Gfx *func_bonus_80026940(Gfx *dl, Actor *KoshController);
// TODO: func_bonus_80026CF0 has no documented signature
// TODO: func_bonus_800271B4 has no documented signature but has been matched
// TODO: func_bonus_80027308 has no documented signature but has been matched
// TODO: func_bonus_8002733C has no documented signature but has been matched
void func_bonus_800274A0(f32 arg0, f32 arg1, f32 arg2);
u8 func_bonus_80027548(f32 arg0, f32 arg1, f32 arg2);
void func_bonus_800277F8(void);
// TODO: func_bonus_80027F14 has no documented signature
void func_bonus_800284C0(void);
// TODO: func_bonus_80028648 has no documented signature but has been matched
// TODO: func_bonus_8002881C has no documented signature
// TODO: func_bonus_80028E3C has no documented signature
// TODO: func_bonus_80029364 has no documented signature
// TODO: func_bonus_80029B9C has no documented signature
void func_bonus_80029E54(Actor *arg0);
void func_bonus_8002A010(void);
void func_bonus_8002A398(void);
void func_bonus_8002AAA4(void);
void func_bonus_8002AD10(void);
// TODO: func_bonus_8002AED8 has no documented signature
// TODO: func_bonus_8002B920 has no documented signature
// TODO: func_bonus_8002BE44 has no documented signature
// TODO: func_bonus_8002BF98 has no documented signature
void func_bonus_8002C8EC(void);
Gfx *func_bonus_8002CC08(Gfx *arg0, Actor *arg1);

// bonus/code_9010.c
Gfx *func_bonus_8002D010(Gfx *dl, Actor *arg1);
void func_bonus_8002D2F0(void);
void func_bonus_8002D6F8(s16 arg0);
void func_bonus_8002D7E8(s16 arg0);

// race/code_0.c
void func_race_80024000(void);
// TODO: func_race_80024634 has no documented signature but has been matched
void func_race_80024690(void);

// race/code_1770.c
s32 func_race_80025770(s32 arg0, s32 arg1);
s32 func_race_8002578C(s32 arg0, s32 arg1);
// TODO: func_race_800257A4 has no documented signature
void func_race_8002597C(void);
void func_race_80025E9C(Actor *arg0);
void func_race_80025FDC(void);
// TODO: func_race_80026004 has no documented signature but has been matched
// TODO: func_race_80026050 has no documented signature but has been matched
// TODO: func_race_80026098 has no documented signature but has been matched
// TODO: func_race_800261E0 has no documented signature but has been matched
// TODO: func_race_80026354 has no documented signature
// TODO: func_race_80026B20 has no documented signature but has been matched
void func_race_80026CA8(void);
void func_race_80026D2C(f32 arg0);
Gfx *func_race_80026EE4(Gfx *dl, Actor *arg1);
// TODO: func_race_80026F04 has no documented signature
void func_race_800274C0(void);

// race/code_36B0.c
// TODO: func_race_800276B0 has no documented signature but has been matched
// TODO: func_race_80027710 has no documented signature
f32 func_race_80027880(s32 arg0, u16 arg1, u16 arg2);
// TODO: func_race_80027920 has no documented signature
void func_race_80027AF8(RaceStruct3 *arg0, s8 arg1);
void func_race_80027B30(RaceStruct3 *arg0);
// TODO: func_race_80027BD0 has no documented signature but has been matched
void func_race_80027C60(void);
// TODO: func_race_80027CE8 has no documented signature
// TODO: func_race_800280E8 has no documented signature but has been matched
void func_race_800282D8(void);
void func_race_800283D4(f32 arg0);
void func_race_80028440(void);
// TODO: func_race_80028AD0 has no documented signature
// TODO: func_race_80028E20 has no documented signature
void func_race_80029054(void);

// race/code_52B0.c
Gfx *func_race_800292B0(Gfx *dl, Actor *arg1);
void func_race_800292D0(Actor *arg0);
void sealRaceSetup(void);
void func_race_800294A8(void);
f32 func_race_8002978C(void);
void func_race_80029F88(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
// TODO: func_race_8002A080 has no documented signature but has been matched
// TODO: func_race_8002A0AC has no documented signature

// race/code_6650.c
void initializeCastleCarRace(Actor *arg0);
// TODO: func_race_8002A7F8 has no documented signature but has been matched
void func_race_8002AE6C(Gfx *dl, Actor *arg1);
void func_race_8002AE9C(void);
// TODO: func_race_8002B180 has no documented signature
// TODO: func_race_8002B518 has no documented signature but has been matched
// TODO: func_race_8002B610 has no documented signature but has been matched
// TODO: func_race_8002B6C8 has no documented signature but has been matched
// TODO: func_race_8002B6F4 has no documented signature but has been matched
// TODO: func_race_8002B76C has no documented signature but has been matched
void func_race_8002B964(void);

// race/code_7BD0.c
void func_race_8002BBD0(Actor *arg0, s32 numRacers);
// TODO: func_race_8002BC2C has no documented signature but has been matched
// TODO: func_race_8002BCB0 has no documented signature but has been matched
void func_race_8002BCD4(Actor *arg0);
// TODO: func_race_8002BDDC has no documented signature
Gfx *func_race_8002BEE8(Gfx *dl, Actor *arg1);
// TODO: func_race_8002C14C has no documented signature but has been matched
// TODO: func_race_8002C2E8 has no documented signature
// TODO: func_race_8002C63C has no documented signature but has been matched
// TODO: func_race_8002C76C has no documented signature
Gfx *func_race_8002CAC8(Gfx *dl, Actor *arg1, RaceAdditionalActorData *arg2);
Gfx *func_race_8002CBEC(Gfx *dl, Actor *arg1);
void func_race_8002CFF0(void);
void castleCarRaceSetup(void);
void initializeSealRace(void);
void func_race_8002D0FC(void);
// TODO: func_race_8002D148 has no documented signature but has been matched
void func_race_8002D224(u8 arg0);
// TODO: func_race_8002D2C0 has no documented signature but has been matched
// TODO: func_race_8002D338 has no documented signature but has been matched
Actor *func_race_8002D360(Actor *arg0);
void func_race_8002D40C(void);
void func_race_8002D4A0(void);
// TODO: func_race_8002D524 has no documented signature
void func_race_8002D72C(Actor *arg0);
void func_race_8002D754(Actor *arg0);
// TODO: func_race_8002D778 has no documented signature
void func_race_8002DA68(RaceStruct3 *arg0);
void func_race_8002DB90(void);
void func_race_8002DC24(void);
// TODO: func_race_8002DCF0 has no documented signature but has been matched
f32 func_race_8002DD70(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
// TODO: func_race_8002DDA0 has no documented signature but has been matched
// TODO: func_race_8002DE78 has no documented signature but has been matched
// TODO: func_race_8002DF38 has no documented signature but has been matched
// TODO: func_race_8002E1C8 has no documented signature but has been matched
void func_race_8002E2C8(Actor *arg0);
Gfx *func_race_8002E464(Gfx *dl, Actor *arg1);
void func_race_8002E484(void);
// TODO: func_race_8002E644 has no documented signature but has been matched
// TODO: func_race_8002E8EC has no documented signature but has been matched

// race/code_A960.c
// TODO: func_race_8002E960 has no documented signature but has been matched
// TODO: func_race_8002E9AC has no documented signature
// TODO: func_race_8002E9F8 has no documented signature
void setupRaceOnMapLoad(Maps map);
void func_race_8002ECD4(Actor *arg0, f32 arg1);
void func_race_8002ED04(f32 arg0, s32 arg1, u8 arg2);
// TODO: func_race_8002EDD4 has no documented signature but has been matched
f32 func_race_8002F04C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
// TODO: func_race_8002F0AC has no documented signature
// TODO: func_race_8002F280 has no documented signature but has been matched
// TODO: func_race_8002F304 has no documented signature but has been matched
// TODO: func_race_8002F36C has no documented signature but has been matched
// TODO: func_race_8002F420 has no documented signature but has been matched
void func_race_8002F490(void *arg0);
// TODO: func_race_8002F784 has no documented signature
// TODO: func_race_8002F90C has no documented signature but has been matched
// TODO: func_race_8002F950 has no documented signature

// critter/code_0.c
// TODO: func_critter_80024000 has no documented signature but has been matched
// TODO: func_critter_8002409C has no documented signature but has been matched
// TODO: func_critter_800240EC has no documented signature but has been matched
// TODO: func_critter_80024154 has no documented signature but has been matched
// TODO: func_critter_8002427C has no documented signature but has been matched
// TODO: func_critter_8002448C has no documented signature but has been matched
// TODO: func_critter_80024518 has no documented signature but has been matched
// TODO: func_critter_80024578 has no documented signature but has been matched
// TODO: func_critter_800245B8 has no documented signature but has been matched
// TODO: func_critter_800247F4 has no documented signature but has been matched
// TODO: func_critter_80024B78 has no documented signature but has been matched
// TODO: func_critter_80024C88 has no documented signature but has been matched
// TODO: func_critter_80024F28 has no documented signature but has been matched
// TODO: func_critter_8002516C has no documented signature but has been matched
// TODO: func_critter_80025500 has no documented signature but has been matched
// TODO: func_critter_800255C4 has no documented signature but has been matched
Gfx *func_critter_800257D4(Gfx *dl);
void func_critter_800258B0(f32 arg0[4][4], s16 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
// TODO: func_critter_80025A3C has no documented signature but has been matched
// TODO: func_critter_80025AD0 has no documented signature but has been matched
// TODO: func_critter_80025D1C has no documented signature but has been matched
// TODO: func_critter_80025DB8 has no documented signature but has been matched
// TODO: func_critter_80025F3C has no documented signature but has been matched
// TODO: func_critter_80025F8C has no documented signature but has been matched
// TODO: func_critter_8002601C has no documented signature
// TODO: func_critter_80026298 has no documented signature but has been matched
// TODO: func_critter_800262C0 has no documented signature but has been matched
// TODO: func_critter_80026338 has no documented signature but has been matched
// TODO: func_critter_80026410 has no documented signature but has been matched
// TODO: func_critter_8002646C has no documented signature but has been matched
// TODO: func_critter_80026530 has no documented signature but has been matched
// TODO: func_critter_8002658C has no documented signature
// TODO: func_critter_80026874 has no documented signature but has been matched
// TODO: func_critter_80026904 has no documented signature but has been matched
// TODO: func_critter_80026A5C has no documented signature but has been matched
// TODO: func_critter_80026B78 has no documented signature but has been matched
// TODO: func_critter_80026C9C has no documented signature
// TODO: func_critter_80026E0C has no documented signature but has been matched
void func_critter_80026FD0(void *arg0);
Gfx *func_critter_80027034(Gfx *dl);
// TODO: func_critter_8002708C has no documented signature but has been matched
// TODO: func_critter_80027118 has no documented signature

// critter/code_3340.c
void func_critter_80027340(s32 arg0);
// TODO: func_critter_80027448 has no documented signature
void func_critter_80027DC0(void);
void func_critter_80028120(void);

// critter/code_4840.c
void func_critter_80028840(void);
// TODO: func_critter_800288A8 has no documented signature but has been matched
// TODO: func_critter_80028A9C has no documented signature
Gfx *func_critter_80028DE8(Gfx *dl, Actor *arg1);
// TODO: func_critter_80028EE8 has no documented signature but has been matched
// TODO: func_critter_8002904C has no documented signature but has been matched

// critter/code_5110.c
// TODO: func_critter_80029110 has no documented signature but has been matched
// TODO: func_critter_80029118 has no documented signature
Gfx *func_critter_800296DC(Gfx *dl, Actor *arg1);

// boss/ArmyDillo.c
// TODO: func_boss_80024000 has no documented signature but has been matched
// TODO: func_boss_8002413C has no documented signature
void func_boss_80024300(void);
// TODO: func_boss_8002450C has no documented signature but has been matched
void func_boss_80024524(u8 arg0, s16 arg1);
// TODO: func_boss_80024568 has no documented signature
void func_boss_80024EAC(void);
// TODO: func_boss_80024FA8 has no documented signature but has been matched
// TODO: func_boss_800251A0 has no documented signature but has been matched
void func_boss_8002531C(void);
void func_boss_80025364(void);
void func_boss_800253AC(void);
// TODO: func_boss_800254D0 has no documented signature
void func_boss_80027770(void);

// boss/KRoolGeneric.c
void func_boss_80027840(u8 *arg0);
// TODO: func_boss_800278F4 has no documented signature but has been matched
// TODO: func_boss_80027950 has no documented signature but has been matched
// TODO: func_boss_80027A30 has no documented signature but has been matched
// TODO: func_boss_80027BA8 has no documented signature
void func_boss_80028458(void);
void func_boss_80028478(u16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8 arg5);
void func_boss_80028680(void);
Gfx *func_boss_800286B8(Gfx *dl, Actor *arg1);
void func_boss_80028818(void);
void func_boss_80028820(void);
void func_boss_80028878(u8 *arg0);
void func_boss_800290D4(u8 arg0);
void func_boss_80029140(s16* arg0);
void func_boss_8002920C(void);

// boss/Pufftoss.c
void func_boss_800292B0(f32 arg0);
void func_boss_800293C0(void);
// TODO: func_boss_80029468 has no documented signature

// boss/Dogadon.c
// TODO: func_boss_8002A240 has no documented signature
void func_boss_8002A41C(u8 arg0);
void func_boss_8002A55C(u8 arg0, f32 arg1);
void func_boss_8002A5CC(void);
void func_boss_8002A8B8(s32 arg0);
// TODO: func_boss_8002A92C has no documented signature

// boss/SpiderBoss.c
void func_boss_8002C520(s16 arg0, s16 arg1, s16 arg2);
void func_boss_8002C5F4(void);
void func_boss_8002C748(u8 arg0);
void func_boss_8002C7CC(void);
void func_boss_8002C8B4(void);
void func_boss_8002C964(void);

// boss/KRoolDK.c
void func_boss_8002D230(void);

// boss/KRoolDiddy.c
void func_boss_8002DC60(void);
void func_boss_8002DCE0(void);
void func_boss_8002DD7C(void);
// TODO: func_boss_8002DE04 has no documented signature

// boss/KRoolLanky.c
void func_boss_8002E7A0(Actor *arg0);
void func_boss_8002E82C(void);
void func_boss_8002E9B8(s32 arg0, s16 arg1);
void func_boss_8002EA14(void);
void func_boss_8002EA7C(void);

// boss/KRoolTiny.c
void func_boss_8002F100(void);
void func_boss_8002FB7C(u8 arg0);
void func_boss_8002FC48(Actor *arg0, u8 arg1);
// TODO: func_boss_8002FC98 has no documented signature
void func_boss_8002FDF8(Actor* arg0, u8 arg1);
void func_boss_8002FEC0(Actor* toes[], u8 toeIndex, s32 modelIndex);
void func_boss_8002FF74(void);
void func_boss_80030888(void);

// boss/KRoolChunky.c
void func_boss_80030920(KRoolChunkyAAD178 *arg0);
// TODO: func_boss_80030AE0 has no documented signature but has been matched
void func_boss_80030C30(f32 arg0);
void func_boss_80030D50(void);
void func_boss_80030E58(void);
void func_boss_80030EC4(void);

// boss/KutOut.c
// TODO: func_boss_80031AA0 has no documented signature
void func_boss_80032B08(void);

// boss/MadJack.c
// TODO: func_boss_800330D0 has no documented signature
// TODO: func_boss_8003340C has no documented signature but has been matched
// TODO: func_boss_800334A4 has no documented signature but has been matched
void func_boss_800336C0(void);
// TODO: func_boss_80033784 has no documented signature but has been matched
// TODO: func_boss_8003392C has no documented signature but has been matched
// TODO: func_boss_800339D8 has no documented signature but has been matched
void func_boss_80033A80(s8 arg0);
// TODO: func_boss_80033AF0 has no documented signature
void func_boss_8003575C(void);

// arcade/code_0.c
// TODO: func_arcade_80024000 has no documented signature but has been matched
// TODO: func_arcade_8002419C has no documented signature but has been matched
// TODO: func_arcade_80024320 has no documented signature but has been matched
// TODO: func_arcade_8002440C has no documented signature but has been matched
// TODO: arcade_set_text_rgba has no documented signature but has been matched
// TODO: arcade_set_text_position has no documented signature but has been matched
// TODO: arcade_draw_text has no documented signature but has been matched
// TODO: arcade_cycle_rng has no documented signature but has been matched
// TODO: arcade_add_points_to_score has no documented signature but has been matched
// TODO: func_arcade_800246C8 has no documented signature but has been matched
// TODO: arcade_get_first_empty_slot has no documented signature but has been matched
// TODO: func_arcade_80024764 has no documented signature but has been matched
// TODO: func_arcade_800247B8 has no documented signature but has been matched
// TODO: func_arcade_800247F0 has no documented signature but has been matched
// TODO: func_arcade_80024828 has no documented signature but has been matched
// TODO: arcade_get_first_object_of_type has no documented signature but has been matched
// TODO: arcade_get_object_type_count has no documented signature but has been matched
// TODO: func_arcade_80024940 has no documented signature but has been matched
// TODO: func_arcade_80024A50 has no documented signature but has been matched
// TODO: func_arcade_80024B04 has no documented signature but has been matched
// TODO: func_arcade_80024C34 has no documented signature but has been matched
// TODO: func_arcade_80024CF8 has no documented signature but has been matched
// TODO: func_arcade_80024D90 has no documented signature but has been matched
// TODO: func_arcade_80024E84 has no documented signature but has been matched
// TODO: func_arcade_800251D8 has no documented signature but has been matched
// TODO: func_arcade_80025240 has no documented signature but has been matched
// TODO: arcade_play_sfx has no documented signature but has been matched
// TODO: func_arcade_800252D8 has no documented signature but has been matched
// TODO: func_arcade_8002549C has no documented signature but has been matched
// TODO: func_arcade_800255A8 has no documented signature but has been matched
// TODO: func_arcade_800255F4 has no documented signature but has been matched
// TODO: func_arcade_800257D8 has no documented signature but has been matched
// TODO: func_arcade_80025960 has no documented signature but has been matched
// TODO: func_arcade_800259D0 has no documented signature but has been matched
// TODO: func_arcade_80025C08 has no documented signature but has been matched
// TODO: func_arcade_80026050 has no documented signature but has been matched
// TODO: func_arcade_8002628C has no documented signature but has been matched
// TODO: func_arcade_800263EC has no documented signature but has been matched
// TODO: func_arcade_80026518 has no documented signature but has been matched
// TODO: func_arcade_80026680 has no documented signature but has been matched
// TODO: func_arcade_800268AC has no documented signature but has been matched
// TODO: func_arcade_80026EF4 has no documented signature but has been matched
// TODO: func_arcade_800274E0 has no documented signature but has been matched
// TODO: func_arcade_800275E8 has no documented signature but has been matched
// TODO: func_arcade_80027A38 has no documented signature but has been matched
// TODO: func_arcade_80027E8C has no documented signature but has been matched
// TODO: arcade_25m_setup has no documented signature but has been matched
// TODO: arcade_100m_setup has no documented signature but has been matched
// TODO: arcade_75m_setup has no documented signature but has been matched
// TODO: arcade_50m_setup has no documented signature but has been matched
// TODO: func_arcade_80029968 has no documented signature but has been matched
// TODO: func_arcade_80029ACC has no documented signature but has been matched
// TODO: func_arcade_80029CD0 has no documented signature but has been matched
// TODO: func_arcade_80029EFC has no documented signature but has been matched
// TODO: func_arcade_8002A264 has no documented signature but has been matched
// TODO: func_arcade_8002A390 has no documented signature but has been matched
// TODO: func_arcade_8002A408 has no documented signature but has been matched
// TODO: func_arcade_8002A474 has no documented signature but has been matched
// TODO: func_arcade_8002A734 has no documented signature but has been matched
// TODO: func_arcade_8002AA24 has no documented signature but has been matched
// TODO: func_arcade_8002AC54 has no documented signature but has been matched
// TODO: func_arcade_8002AF2C has no documented signature but has been matched
// TODO: func_arcade_8002AFA4 has no documented signature but has been matched
// TODO: func_arcade_8002B2C0 has no documented signature but has been matched
// TODO: __arcade_abs_w has no documented signature but has been matched
// TODO: func_arcade_8002B390 has no documented signature but has been matched
// TODO: func_arcade_8002B89C has no documented signature but has been matched
// TODO: func_arcade_8002CBD8 has no documented signature but has been matched
// TODO: func_arcade_8002CD64 has no documented signature but has been matched
// TODO: func_arcade_8002D6FC has no documented signature but has been matched
// TODO: func_arcade_8002E158 has no documented signature but has been matched
// TODO: func_arcade_8002E3D4 has no documented signature but has been matched
// TODO: arcade_pauline_top_update has no documented signature but has been matched
// TODO: arcade_pauline_bottom_update has no documented signature but has been matched
// TODO: arcade_nintendo_coin_update has no documented signature but has been matched
// TODO: arcade_help_text_update has no documented signature but has been matched
// TODO: arcade_pulley_update has no documented signature but has been matched
// TODO: arcade_dk_title_update has no documented signature but has been matched
// TODO: func_arcade_8002EEB8 has no documented signature but has been matched
// TODO: func_arcade_8002F82C has no documented signature but has been matched
// TODO: func_arcade_8002FE28 has no documented signature but has been matched
// TODO: arcade_dk_50m_update has no documented signature but has been matched
// TODO: arcade_points_text_update has no documented signature but has been matched
// TODO: arcade_bonus_item_update has no documented signature but has been matched
// TODO: arcade_hammer_update has no documented signature but has been matched
// TODO: func_arcade_80030734 has no documented signature but has been matched
// TODO: arcade_rivet_update has no documented signature but has been matched
// TODO: func_arcade_80030A04 has no documented signature but has been matched
// TODO: arcade_pie_update has no documented signature but has been matched
// TODO: func_arcade_80030C70 has no documented signature but has been matched
// TODO: func_arcade_80030CEC has no documented signature but has been matched
// TODO: arcade_barrel_stack_update has no documented signature but has been matched
// TODO: func_arcade_80030FEC has no documented signature but has been matched
// TODO: func_arcade_800311E0 has no documented signature but has been matched
// TODO: func_arcade_800313B8 has no documented signature but has been matched
// TODO: func_arcade_8003159C has no documented signature but has been matched
// TODO: func_arcade_80031948 has no documented signature but has been matched
// TODO: func_arcade_800319D4 has no documented signature but has been matched

// jetpac/code_0.c
void func_jetpac_80024000(void);
// TODO: func_jetpac_8002419C has no documented signature but has been matched
void func_jetpac_80024390(void);
void func_jetpac_80024408(Gfx **arg0);
void func_jetpac_8002463C(void);
void func_jetpac_8002466C(Gfx **arg0);
void func_jetpac_800248A0(Gfx **arg0);
void func_jetpac_800248E8(Gfx **arg0);
void func_jetpac_80024A4C(void);
void func_jetpac_80024A8C(Gfx **arg0);
void func_jetpac_80024C90(Gfx **arg0);
void func_jetpac_80024D48(Gfx **arg0);
void func_jetpac_80024E70(s32 arg0);
void func_jetpac_80024F24(s32 arg0, s32 arg1);
void func_jetpac_80024F64(s32 arg0);
void func_jetpac_80024F9C(s32 arg0);
void func_jetpac_800250A0(void);
void func_jetpac_80025168(Gfx **arg0);
void func_jetpac_80025368(Competitor *arg0);

// jetpac/code_1460.c
void func_jetpac_80025460(void);
// TODO: func_jetpac_800254B8 has no documented signature
void func_jetpac_800255D4(Gfx **arg0);
// TODO: func_jetpac_80025700 has no documented signature
void func_jetpac_80025904(Gfx **arg0);
// TODO: func_jetpac_80025A60 has no documented signature but has been matched
// TODO: func_jetpac_80025B70 has no documented signature but has been matched
// TODO: func_jetpac_80025BB8 has no documented signature but has been matched
// TODO: func_jetpac_80025C40 has no documented signature but has been matched
// TODO: func_jetpac_80025CA0 has no documented signature but has been matched
// TODO: func_jetpac_80025CB0 has no documented signature
// TODO: func_jetpac_80025F48 has no documented signature but has been matched
void func_jetpac_80025FC4(JetpacStruct *arg0);
// TODO: func_jetpac_800260DC has no documented signature but has been matched
// TODO: func_jetpac_80026318 has no documented signature
// TODO: func_jetpac_80026A3C has no documented signature but has been matched
// TODO: func_jetpac_80026AB0 has no documented signature
void func_jetpac_80026CA4(void);
void func_jetpac_80026CEC(void);
void func_jetpac_80026D48(void);
void func_jetpac_80026DC8(void);
int func_jetpac_80026FE0(void);
// TODO: func_jetpac_80027010 has no documented signature but has been matched

// jetpac/code_3060.c
s32 func_jetpac_80027060(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_jetpac_80027108(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5);
f32 func_jetpac_80027210(void);
int func_jetpac_80027250(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
int func_jetpac_80027330(f32 arg0);
// TODO: func_jetpac_80027380 has no documented signature but has been matched
// TODO: func_jetpac_800273C8 has no documented signature but has been matched
f32 func_jetpac_80027410(f32 arg0);

// jetpac/code_3480.c
s32 func_jetpac_80027480(void);
s32 func_jetpac_800274C0(void);
// TODO: func_jetpac_80027510 has no documented signature but has been matched
void func_jetpac_800275F4(Competitor *arg0);
// TODO: func_jetpac_80027728 has no documented signature
// TODO: func_jetpac_80027BE8 has no documented signature
void func_jetpac_80027D64(Competitor *arg0);
// TODO: func_jetpac_80027EC0 has no documented signature
void func_jetpac_80028340(Competitor *arg0);
s32 func_jetpac_800283EC(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_jetpac_80028544(void);
void func_jetpac_800285DC(void);
void func_jetpac_80028634(void);
// TODO: func_jetpac_800286D0 has no documented signature
void func_jetpac_80028950(void);
// TODO: func_jetpac_800289EC has no documented signature
void func_jetpac_80028B54(Competitor *arg0);
// TODO: func_jetpac_80028BD0 has no documented signature but has been matched
void func_jetpac_80028C3C(void);
s32 func_jetpac_80028CF8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
s32 func_jetpac_80028E04(s32 arg0, s32 arg1, s32 arg2);
// TODO: func_jetpac_80028E88 has no documented signature

// jetpac/code_4FC0.c
JetpacStruct *func_jetpac_80028FC0(void);
// TODO: func_jetpac_80029064 has no documented signature
// TODO: func_jetpac_800291AC has no documented signature but has been matched
void func_jetpac_80029204(JetpacStruct *arg0);
JetpacStruct *func_jetpac_800292C4(void);
void func_jetpac_80029450(void);
void func_jetpac_800294EC(JetpacStruct *arg0, s32 arg1);
// TODO: func_jetpac_80029640 has no documented signature but has been matched
void func_jetpac_8002976C(JetpacStruct *arg0);
// TODO: func_jetpac_80029884 has no documented signature but has been matched
void func_jetpac_800298C8(JetpacStruct *arg0);
void func_jetpac_8002992C(JetpacStruct *arg0);
void func_jetpac_8002998C(JetpacStruct *arg0);
void func_jetpac_80029AF8(JetpacStruct *arg0);
void func_jetpac_80029B90(JetpacStruct *arg0);
void func_jetpac_80029C1C(JetpacStruct *arg0);
// TODO: func_jetpac_80029E0C has no documented signature but has been matched
// TODO: func_jetpac_80029F7C has no documented signature
void func_jetpac_8002A254(JetpacStruct *arg0);
void func_jetpac_8002A2AC(JetpacStruct *arg0);
f32 func_jetpac_8002A2DC(f32 arg0, f32 arg1);
void func_jetpac_8002A374(JetpacStruct *arg0);
void func_jetpac_8002A530(JetpacStruct *arg0);
void func_jetpac_8002A67C(JetpacStruct *arg0);
void func_jetpac_8002A6C0(JetpacStruct *arg0);
void func_jetpac_8002A758(JetpacStruct *arg0);
// TODO: func_jetpac_8002A8F0 has no documented signature but has been matched
void func_jetpac_8002A944(JetpacStruct *arg0);
s32 func_jetpac_8002A974(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_jetpac_8002AAD4(void);
void func_jetpac_8002ABDC(void);
void func_jetpac_8002AD8C(void);
void func_jetpac_8002AE00(Gfx **arg0);
void func_jetpac_8002AE94(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_jetpac_8002AEC8(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_jetpac_8002AEFC(Gfx **arg0, char *string, s32 x, s32 y, s32 arg4);
#endif

