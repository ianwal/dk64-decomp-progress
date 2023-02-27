#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "enums.h"
#include "structs.h"

/* your function prototype definitions go here */
void *malloc(s32 size);
s32 rand(void);
void *memcpy(void *dest, void *src, u32 n);

void *getPointerTableFile(s32 pointerTableIndex, s32 fileIndex, s32 arg2, s32 arg3);
void loadExits(s32 map);
void setFlag(s16 flagIndex, u8 newValue, u8 flagType); // TODO: Can we use the FlagTypes enum?
u8 isFlagSet(s16 flagIndex, u8 flagType); // TODO: Can we use the FlagTypes enum?
ExitData *getExitData(s32 exitIndex);

// TODO: What do the params mean?
void playCutscene(Actor*, s16, s32);
void playSong(s32, f32);
void playSound(s16, s16, f32, f32, s32, s32);

// TODO: arg0 might be actionIndex
u8 func_806EB0C0(s16 arg0, Actor *actor, u8 playerIndex);
void func_8067B238(Actor *destination, Actor *source, f32 scale);

void func_80684900(u8);
f32 func_80612794(s16);
void func_80614E78(Actor*, s32);
void func_80629174(void);

// Heap stuff???
void func_8061130C(void *);

// TODO: Signatures are suspect
s32 func_80659470(s32); // Returns index into object model2 array
s32 func_80659544(s32);

s32 func_805FF800(Maps *arg0, s32 *arg1);

u16 func_806F8AD4(u8 arg0, u8 playerIndex);

void func_80614EBC(Actor*, s32);

u8 playerCanDive(void);
u8 playerCanThrowOrange(void);

u8 func_805FCA64(void); // getCutsceneBarState()
u8 getLevelIndex(u8 map, u8 arg1);
void func_805FF378(Maps nextMap, s32 nextExit);
void func_805FF4D8(Maps map, s32 exit);
void func_805FF5A0(Maps map);
void func_805FFEF8(Maps map);

void func_806F5378(void);
s32 func_80600080(Maps map);
f32 func_80612790(s16);
void func_806782C0(Actor *arg0);

u8 func_806E770C(void);

void setIntroStoryPlaying(u8 arg0);
u8 isIntroStoryPlaying(void);

s32 func_80712798(void);
int gameIsInDKTVMode(void);
int gameIsInMysteryMenuMinigameMode(void);
int gameIsInMainMenuMode(void);
int gameIsInAdventureMode(void);
int gameIsInDKTheatreMode(void);
int gameIsInQuitGameMode(void);
s32 func_80714CC0(void*, f32, f32, f32, f32);

// countSetFlags(startIndex, length, flagType);
s32 func_80731AA8(s32 startIndex, s32 length, u8 flagType);

// TODO: Not 100% on return type
u8 func_80671C0C(Actor*, s32, f32*, f32*, f32*);

// TODO: Why can't this signature live here, causes some problems for arcade when uncommented
// void func_8060C648(u8 arg0, u32 arg1, u8 arg2, u32 arg3, s32 arg4);

// TODO: Where is the best place to put this so it's available everywhere and doesn't conflict with internal libultra/gu stuff?
#define	ABS(d)		((d) > 0) ? (d) : -(d)

#endif
