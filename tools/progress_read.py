import argparse
import os
import re
import sys
import csv
import anybadge

# Read using `mips-linux-gnu-readelf -S`
overlay_sizes = {
    'dk64_boot'   : (0xE8B0 - 0x1000),
    'global_asm'  : 0x149160 - # need to subtract mips3 file sizes, which haven't been migrated yet
                    # TODO remove these when the mips3 files are migrated!!!
                    (0x02C700 - 0x0166A0) -
                    (0x127B00 - 0x124780) -
                    (0x149160 - 0x145D70),
    'menu'        : 0x00ef50,
    'multiplayer' : 0x002f70,
    'minecart'    : 0x004b90,
    'race'        : 0x00bb10,
    'bonus'       : 0x009860,
    'water'       : 0x0057f0,
    'arcade'      : 0x00e220,
    'jetpac'      : 0x007090,
    'boss'        : 0x0118b0,
}

def RGB_to_hex(RGB):
    ''' [255,255,255] -> "#FFFFFF" '''
    # Components need to be integers for hex to make sense
    RGB = [int(x) for x in RGB]
    return "#"+"".join(["0{0:x}".format(v) if v < 16 else
                        "{0:x}".format(v) for v in RGB])

def main(csv_name, version, overlay):
    with open(csv_name, mode='r') as csv_file:
        csv_reader = csv.DictReader(csv_file)
        line_count = 0
        total_func = 0
        incomplete_func = 0
        if overlay == 'total':
            total_byte = sum(overlay_sizes.values())
        else:
            total_byte = overlay_sizes[overlay]
        incomplete_byte = 0
        for row in csv_reader:
            if(row["version"] == version):
                total_func += 1
                if row['matching'] != 'yes':
                    incomplete_func += 1
                    incomplete_byte += int(row['length'])
        done_byte = total_byte - incomplete_byte
        done_func = total_func - incomplete_func
        percent = ((done_byte/total_byte) * 100)
        print("%s: bytes: %3.4f%% (%d/%d), nonstatic funcs: %3.4f%% (%d/%d)" % (overlay, percent, done_byte, total_byte,((done_func/total_func) *100), done_func, total_func ))
        green = min(255, round(min(1, (percent / 100) * 2) * 192))
        red = min(255, round(min(1, ((100 - percent) / 100) * 2) * 192))
        color = RGB_to_hex([red, green, 0])
        if overlay == 'total':
            badge = anybadge.Badge("Donkey Kong 64 (US)", "%3.4f%%" % (percent), default_color=color)
        else:
            badge = anybadge.Badge(overlay, "%3.4f%%" % (percent), default_color=color)
        badge.write_badge('progress/progress_' + overlay + '.svg',overwrite=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Create progress csv based on map file',
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('csv_name', type=str,
                        help="csv to read")
    parser.add_argument('ver_str', type=str,
                        help="version")
    parser.add_argument('overlay', type=str,
                        help="overlay name")
    args = parser.parse_args()

    main(args.csv_name, args.ver_str, args.overlay)
