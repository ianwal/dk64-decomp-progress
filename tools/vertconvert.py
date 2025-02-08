#!/usr/bin/env python3

import sys
from textwrap import wrap

def twos_complement(hexstr, bits):
    value = int(hexstr, 16)
    if value & (1 << (bits - 1)):
        value -= 1 << bits
    return value

for arg in sys.argv[1:]:
    arg = arg.lstrip().rstrip()
    if len(arg) == 0:
        continue
    if "dlabel" in arg:
        continue
    if len(arg) % 32 == 0:
        verts = wrap(arg, 32)
        for vert in verts:
            x = str(twos_complement(vert[0:4], 16))
            y = str(twos_complement(vert[4:8], 16))
            z = str(twos_complement(vert[8:12], 16))
            flag = vert[12:16]
            tx = str(twos_complement(vert[16:20], 16))
            ty = str(twos_complement(vert[20:24], 16))
            r = vert[24:26]
            g = vert[26:28]
            b = vert[28:30]
            a = vert[30:32]
            print("{{{ " + x + " , " + y + " , " + z + " }, 0x" + flag + ", { " + tx + ", " + ty + " }, { 0x" + r + ", 0x" + g + ", 0x" + b + ", 0x" + a +" }}},")