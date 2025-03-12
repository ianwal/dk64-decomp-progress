import argparse
import csv
import anybadge

# This unused import makes the yaml library faster. don't remove
import pylibyaml  # pyright: ignore
import yaml

# Read using `mips-linux-gnu-readelf -S`
overlays = [
    'dk64_boot',
    'global_asm',
    'menu',
    'multiplayer',
    'minecart',
    'bonus',
    'race',
    'critter',
    'arcade',
    'jetpac',
    'boss',
]

def RGB_to_hex(RGB):
    ''' [255,255,255] -> "#FFFFFF" '''
    # Components need to be integers for hex to make sense
    RGB = [int(x) for x in RGB]
    return "#"+"".join(["0{0:x}".format(v) if v < 16 else
                        "{0:x}".format(v) for v in RGB])

def is_integer_num(n):
    if isinstance(n, int):
        return True
    if isinstance(n, float):
        return n.is_integer()
    return False

def makeUnitLabel(numerator, denominator, units, percent):
    if is_integer_num(percent):
        if percent >= 100:
            percent = 101
            percentStr = "101% 🍌"
        else:
            percentStr = f'{int(percent)}%'
    else:
        percentStr = ("%3.4f%%" % (percent))
    if numerator == denominator:
        unitStr = f"{numerator} {units}"
    else:
        unitStr = f"{numerator}/{denominator} {units}"
    return f'{percentStr} | {unitStr}'

def writeDataBadges(overlay, type, migratedBytes, totalBytes):
    percent = ((migratedBytes/totalBytes) * 100)
    green = min(255, round(min(1, (percent / 100) * 2) * 192))
    red = min(255, round(min(1, ((100 - percent) / 100) * 2) * 192))
    color = RGB_to_hex([red, green, 0])
    badge = anybadge.Badge('.' + type, makeUnitLabel(migratedBytes, totalBytes, 'bytes', percent), default_color=color)
    badge.write_badge('progress/' + type + '_percent_' + overlay + '.svg',overwrite=True)

def countCodeBytes():
    codeBytes = {
        'total': 0,
    }
    with open('decompressed.us.yaml') as f:
        config = yaml.load(f.read(), Loader=yaml.SafeLoader)
        if 'segments' in config:
            for segmentIndex, segment in enumerate(config['segments']):
                if 'name' in segment and segment['name'] in overlays:
                    if 'subsegments' in segment:
                        for subsegmentIndex, subseg in enumerate(segment['subsegments']):
                            # Get next address
                            next_offset = 0x21DE360 # End of ROM (fallback)
                            if (subsegmentIndex + 1) < len(segment['subsegments']):
                                next_subseg = segment['subsegments'][subsegmentIndex + 1]
                                next_offset = next_subseg['start' if 'start' in next_subseg else 0]
                            elif (segmentIndex + 1) < len(config['segments']):
                                next_seg = config['segments'][segmentIndex + 1]
                                next_offset = next_seg['start' if 'start' in next_seg else 0]
                            offset = subseg['start' if 'start' in subseg else 0]
                            type = subseg['type' if 'type' in subseg else 1]
                            size = next_offset - offset
                            if type in ['c']:
                                codeBytes['total'] += size
                                if not segment['name'] in codeBytes:
                                    codeBytes[segment['name']] = 0
                                codeBytes[segment['name']] += size
    return codeBytes

def computeDataOverlays():
    with open('decompressed.us.yaml') as f:
        config = yaml.load(f.read(), Loader=yaml.SafeLoader)
        if 'segments' in config:
            for segmentIndex, segment in enumerate(config['segments']):
                if 'name' in segment and segment['name'] in overlays:
                    if 'subsegments' in segment:
                        data =   {'found': False, 'start': 0, 'migrated': 0, 'not_migrated': 0}
                        rodata = {'found': False, 'start': 0, 'migrated': 0, 'not_migrated': 0}
                        for subsegmentIndex, subseg in enumerate(segment['subsegments']):
                            # Get next address
                            next_offset = 0x21DE360 # End of ROM (fallback)
                            if (subsegmentIndex + 1) < len(segment['subsegments']):
                                next_subseg = segment['subsegments'][subsegmentIndex + 1]
                                next_offset = next_subseg['start' if 'start' in next_subseg else 0]
                            elif (segmentIndex + 1) < len(config['segments']):
                                next_seg = config['segments'][segmentIndex + 1]
                                next_offset = next_seg['start' if 'start' in next_seg else 0]
                            offset = subseg['start' if 'start' in subseg else 0]
                            type = subseg['type' if 'type' in subseg else 1]
                            size = next_offset - offset
                            if type in ['data', '.data']:
                                if not data['found']:
                                    data['found'] = True
                                    data['start'] = offset
                                if type == 'data':
                                    data['not_migrated'] = data['not_migrated'] + size
                                elif type == '.data':
                                    data['migrated'] = data['migrated'] + size
                            elif type in ['rodata', '.rodata']:
                                if not rodata['found']:
                                    rodata['found'] = True
                                    rodata['start'] = offset
                                if type == 'rodata':
                                    rodata['not_migrated'] = rodata['not_migrated'] + size
                                elif type == '.rodata':
                                    rodata['migrated'] = rodata['migrated'] + size
                        data['size'] = data['migrated'] + data['not_migrated']
                        data['end'] = data['start'] + data['size']
                        writeDataBadges(segment['name'], 'data', data['migrated'], data['size'])
                        rodata['size'] = rodata['migrated'] + rodata['not_migrated']
                        rodata['end'] = rodata['start'] + rodata['size']
                        writeDataBadges(segment['name'], 'rodata', rodata['migrated'], rodata['size'])

def main(csv_name, version, overlay):
    with open(csv_name, mode='r') as csv_file:
        csv_reader = csv.DictReader(csv_file)
        total_func = 0
        incomplete_func = 0
        incomplete_byte = 0
        codeBytes = countCodeBytes()
        total_byte = codeBytes[overlay] or 0
        if overlay == 'total':
            computeDataOverlays()
        for row in csv_reader:
            if(row["version"] == version):
                total_func += 1
                if row['matching'] != 'yes':
                    incomplete_func += 1
                    incomplete_byte += int(row['length'])
        done_byte = total_byte - incomplete_byte
        done_func = total_func - incomplete_func
        percent = ((done_byte/total_byte) * 100)
        if total_byte > 0 and total_func > 0:
            print("%s: bytes: %3.4f%% (%d/%d), nonstatic funcs: %3.4f%% (%d/%d)" % (overlay, percent, done_byte, total_byte,((done_func/total_func) *100), done_func, total_func ))
            green = min(255, round(min(1, (percent / 100) * 2) * 192))
            red = min(255, round(min(1, ((100 - percent) / 100) * 2) * 192))
            color = RGB_to_hex([red, green, 0])
            if overlay == 'total':
                badge = anybadge.Badge("Donkey Kong 64 (US)", makeUnitLabel(total_func - incomplete_func, total_func, 'funcs', percent), default_color=color)
            else:
                badge = anybadge.Badge(overlay, makeUnitLabel(total_func - incomplete_func, total_func, 'funcs', percent), default_color=color)
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
