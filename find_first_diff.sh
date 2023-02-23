#!/bin/bash

cmp -l build/us/$1.us.bin build/us/$1.full | gawk '{printf "%08X %02X %02X\n", $1, strtonum(0$2), strtonum(0$3)}'
#diff -y <(xxd build/us/$1.us.bin) <(xxd build/us/$1.full)