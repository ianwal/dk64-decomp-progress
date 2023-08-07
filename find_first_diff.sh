#!/bin/bash

cmp -l baserom.us.decompressed.z64 build/us/donkeykong64.us.uncompressed.z64 | gawk '{printf "%08X %02X %02X\n", $1, strtonum(0$2), strtonum(0$3)}'
#diff -y <(xxd build/us/$1.us.bin) <(xxd build/us/$1.full)