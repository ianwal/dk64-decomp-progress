#ifndef __MACROS_H__
#define __MACROS_H__

#define ALIGNED(x) __attribute__((aligned(x)))
#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

#ifndef __GNUC__
#define __attribute__(x)
#endif

// Clamp Rand value within a range
#define RandClamp(a) ((rand() >> 0xF) % a)

// Get a random chance to a maximum precision of 0.1%
// Arg is any value between 0 and 1
#define RandChance(a) (RandClamp(1000) > (1000 - ((s32)((a) * 1000))))

#define ARRAY_COUNT(arr) (sizeof(arr) / sizeof(arr[0]))
#define	ABS(d)		(((d) > 0) ? (d) : -(d))
#define ABS_DIFF(a, b) (((b) < (a)) ? ((a) - (b)) : (-((a) - (b))))
#define SQ(x) ((x) * (x))
#define reinterpret_cast(type, var) (*((type *)&var))
#define CLAMP(value, min, max) ((value) < (min) ? (min) : MIN(max, value))
#define FILEOFFSET(base, offset) (offset + (s32)base)

#endif
