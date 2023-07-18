#!/usr/bin/env python3

from typing import BinaryIO
import gzip
import io
import shutil

next_available_free_space = 0x2000000

overlays = [
    {
        "name": "global_asm",
        "codeROMAddress": 0x113F0,
        "dataROMAddress": 0xC29D4,
        "dataCompressedSize": 0x949C, # - 8 for length without gzip footer
        # Note: These byte arrays should not contain the gzip footer
        # codeCompressedData: [], // Will be written to ROM
        # dataCompressedData: [], // Will be written to ROM directly after .code, regardless of the original .data address
    },
    {
        "name": "menu",
        "codeROMAddress": 0xCBE70,
        "dataROMAddress": 0xD4554,
        "dataCompressedSize": 0x5A2, # - 8 for length without gzip footer
    },
    {
        "name": "multiplayer",
        "codeROMAddress": 0xD4B00,
        "dataROMAddress": 0xD69F8,
        "dataCompressedSize": 0xFB, # - 8 for length without gzip footer
    },
    {
        "name": "minecart",
        "codeROMAddress": 0xD6B00,
        "dataROMAddress": 0xD98A0,
        "dataCompressedSize": 0x197, # - 8 for length without gzip footer
    },
    {
        "name": "bonus",
        "codeROMAddress": 0xD9A40,
        "dataROMAddress": 0xDF346,
        "dataCompressedSize": 0x2AB, # - 8 for length without gzip footer
    },
    {
        "name": "race",
        "codeROMAddress": 0xDF600,
        "dataROMAddress": 0xE649A,
        "dataCompressedSize": 0x2DB, # - 8 for length without gzip footer
    },
    {
        "name": "critter",
        "codeROMAddress": 0xE6780,
        "dataROMAddress": 0xE9D17,
        "dataCompressedSize": 0x38C, # - 8 for length without gzip footer
    },
    {
        "name": "boss",
        "codeROMAddress": 0xEA0B0,
        "dataROMAddress": 0xF388F,
        "dataCompressedSize": 0x90A, # - 8 for length without gzip footer
    },
    {
        "name": "arcade",
        "codeROMAddress": 0xF41A0,
        "dataROMAddress": 0xFB42C,
        "dataCompressedSize": 0x1EC4, # - 8 for length without gzip footer
    },
    {
        "name": "jetpac",
        "codeROMAddress": 0xFD2F0,
        "dataROMAddress": 0x1010FD,
        "dataCompressedSize": 0x936, # - 8 for length without gzip footer
    },
]

def readAndDecompressOverlays(fr : BinaryIO):
    for x in overlays:
        x["codeCompressedSize"] = x["dataROMAddress"] - x["codeROMAddress"]
        fr.seek(x["codeROMAddress"], io.SEEK_SET)
        print(f"    - Read {x['name']}.code compressed from {hex(fr.tell())}")
        x["codeCompressedData"] = fr.read(x['codeCompressedSize'])
        x["codeDecompressedData"] = gzip.decompress(x["codeCompressedData"])
        print(f"    - Read {x['name']}.data compressed from {hex(fr.tell())}")
        x["dataCompressedData"] = fr.read(x['dataCompressedSize'])
        x["dataDecompressedData"] = gzip.decompress(x["dataCompressedData"])

def alignHex10(fr: BinaryIO):
    # Get the current position
    current_position = fr.tell()

    # Calculate the offset to the desired alignment
    alignment = 0x10
    offset = alignment - (current_position % alignment)

    # Adjust the position by seeking with the offset
    if abs(offset) < alignment:
        fr.seek(offset, io.SEEK_CUR)

    return fr.tell()

def writeDecompressedOverlaysToROM(fr : BinaryIO):
    fr.seek(next_available_free_space, io.SEEK_SET)
    for x in overlays:
        decompressedCodeStart = alignHex10(fr)
        fr.write(x["codeDecompressedData"])
        print(f"    - Wrote {x['name']}.code to {hex(decompressedCodeStart)}")
        decompressedDataStart = alignHex10(fr)
        fr.write(x["dataDecompressedData"])
        print(f"    - Wrote {x['name']}.data to {hex(decompressedDataStart)}")

# Make a copy of the baseROM to be used as the decompressed baseROM
shutil.copyfile('baserom.us.z64', 'baserom.us.decompressed.z64')

# Open the decompressed ROM
with open('baserom.us.decompressed.z64', "r+b") as fh:
    # Decompress all code and data segments
    print("[1 / 2] Decompressing overlays...")
    readAndDecompressOverlays(fh)

    # Concatenate the decompressed segments onto the end of the ROM file, align by 0x10 bytes
    print("[2 / 2] Writing decompressed overlays...")
    writeDecompressedOverlaysToROM(fh)
    print("Decompressed ROM created.")