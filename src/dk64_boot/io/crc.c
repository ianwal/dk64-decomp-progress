#include <ultra64.h>

#define ADDRESS_CRC_MESSAGE_LENGTH 10
#define ADDRESS_CRC_LENGTH 5
#define ADDRESS_CRC_GENERATOR 0x15
#define ADDRESS_CRC_MASK ((1 << ADDRESS_CRC_LENGTH) - 1)

u8 __osContAddressCrc(u16 addr) {
    u32 addr32 = addr;
    u32 ret = 0;
    u32 bit;
    s32 i;

    // ret is used as a shift register for the CRC
    for (bit = (1 << ADDRESS_CRC_MESSAGE_LENGTH); bit != 0; bit >>= 1) {
        ret <<= 1;
        if (addr32 & bit) {
            if (ret & (1 << ADDRESS_CRC_LENGTH)) {
                // Same as ret++; ret ^= 0x15 since last bit always 0 after the shift
                ret ^= ADDRESS_CRC_GENERATOR - 1;
            } else {
                ret++;
            }
        } else if (ret & (1 << ADDRESS_CRC_LENGTH)) {
            ret ^= ADDRESS_CRC_GENERATOR;
        }
    }
    // Acts like 5 bits of 0s are appended to addr
    for (i = 0; i < ADDRESS_CRC_LENGTH; i++) {
        ret <<= 1;
        if (ret & (1 << ADDRESS_CRC_LENGTH)) {
            ret ^= ADDRESS_CRC_GENERATOR;
        }
    }

    // Discard the irrelevant bits above the actual remainder
    return ret & ADDRESS_CRC_MASK;
}

#define DATA_CRC_MESSAGE_BYTES 32
#define DATA_CRC_LENGTH 8
#define DATA_CRC_GENERATOR 0x85

u8 __osContDataCrc(u8* data) {
    s32 ret = 0;
    u32 bit;
    u32 byte;

    for (byte = DATA_CRC_MESSAGE_BYTES; byte != 0; byte--, data++) {
        // Loop over each bit in the byte starting with most significant
        for (bit = (1 << (DATA_CRC_LENGTH - 1)); bit != 0; bit >>= 1) {
            ret <<= 1;
            if (*data & bit) {
                if (ret & (1 << DATA_CRC_LENGTH)) {
                    // Same as ret++; ret ^= 0x85 since last bit always 0 after the shift
                    ret ^= DATA_CRC_GENERATOR - 1;
                } else {
                    ret++;
                }
            } else if (ret & (1 << DATA_CRC_LENGTH)) {
                ret ^= DATA_CRC_GENERATOR;
            }
        }
    }
    // Act like a byte of zeros is appended to data
    do {
        ret <<= 1;
        if (ret & (1 << DATA_CRC_LENGTH)) {
            ret ^= DATA_CRC_GENERATOR;
        }
        byte++;
    } while (byte < DATA_CRC_LENGTH);

    // Discarding the excess is done automatically by the return type
    return ret;
}
