// Clamp Rand value within a range
#define RandClamp(a) ((rand() >> 0xF) % a)

// Get a random chance to a maximum precision of 0.1%
// Arg is any value between 0 and 1
#define RandChance(a) (RandClamp(1000) > (1000 - ((s32)((a) * 1000))))