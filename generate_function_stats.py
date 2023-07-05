#!/usr/bin/env python3

import os;

searchPath = "src"
excludePaths = [
    "src/dk64_boot",
    "src/global_asm/audio",
    "src/global_asm/done",
    "src/global_asm/heap.c",
    "src/global_asm/hud.c",
    "src/global_asm/code_15010.c",
    "src/global_asm/code_77B90.c",
]

precision = 4

standardSearchColumns = {
    "matrix": [
        "guMtxIdent",
        "guMtxIdentF",
        "guOrtho",
        "guOrthoF",
        "guFrustum",
        "guFrustumF",
        "guPerspective",
        "guPerspectiveF",
        "guLookAt",
        "guLookAtF",
        "guLookAtReflect",
        "guLookAtReflectF",
        "guLookAtHilite",
        "guLookAtHiliteF",
        "guLookAtStereo",
        "guLookAtStereoF",
        "guRotate",
        "guRotateF",
        "guRotateRPY",
        "guRotateRPYF",
        "guAlign",
        "guAlignF",
        "guScale",
        "guScaleF",
        "guTranslate",
        "guTranslateF",
        "guPosition",
        "guPositionF",
        "guMtxF2L",
        "guMtxL2F",
        "guMtxCatF",
        "guMtxCatL",
        "guMtxXFMF",
        "guMtxXFML",
    ],
    "actors": [
        "current_actor_pointer",
        "player_pointer",
        "D_807FBB44",
        "D_807FBB48",
        "D_807FBB4C",
        "D_807FBD6C",
        "D_807FDC94",
    ],
    "rand": [
        "rand",
        "func_806119A0",
    ],
    "malloc": [
        "malloc",
    ],
    "flags": [
        "setFlag",
        "isFlagSet",
    ],
    "cutscene": [
        "playCutscene",
        "is_cutscene_active",
    ],
    "cc": [
        "character_change_array",
        "cc_player_index",
        "cc_number_of_players",
        "current_character_index",
    ],
    "D_807FBB70": [
        "D_807FBB70",
    ],
    "D_807F5FD4": [
        "D_807F5FD4",
    ],
    "pointerTable": [
        "getPointerTableFile",
    ],
    "map": [
        "current_map",
        "next_map",
    ],
    "exit": [
        "current_exit",
        "next_exit",
    ],
    "floats": [
        " mtc1 ", " mfc1 ",
        " lwc1 ", " ldc1 ",
        " swc1 ", " sdc1 ",
    ],
}

# Print CSV header
print(
    "file",
    "function",
    "bytes",
    end=" "
)

# For each column, print the value
for column in standardSearchColumns:
    print(column, end=" ")

print(
    "jalratio",
    "labelratio",
    "floatratio",
    "doable",
    "regalloc",
    "stack",
)

for root, dirs, files in os.walk(searchPath):
    for file in files:
        fullFile = os.path.join(root, file)
        if sum(excludePath in fullFile for excludePath in excludePaths) == 0 and file.endswith('.c'):
            with open(fullFile, "r") as fh_c:
                jumptable = False
                rodata = False
                displaylist = False
                doable = False
                regalloc = False
                stack = False
                for line in fh_c:
                    if line.startswith("//"):
                        lowerCaseComment = line.lower()
                        if "jump table" in lowerCaseComment or "jumptable" in lowerCaseComment:
                            jumptable = True
                        if "rodata" in lowerCaseComment:
                            rodata = True
                        if "display list" in lowerCaseComment or "displaylist" in lowerCaseComment:
                            displaylist = True
                        if "doable" in lowerCaseComment:
                            doable = True
                        if "regalloc" in lowerCaseComment:
                            regalloc = True
                        if "stack" in lowerCaseComment:
                            stack = True
                        continue

                    if "#pragma GLOBAL_ASM(" in line:
                        if not jumptable and not rodata and not displaylist:
                            # Parse ASM and compute row for function
                            ASMFile = line.replace("#pragma GLOBAL_ASM(\"", "").replace("\")\n", "")
                            with open(ASMFile, "r") as fh_asm:
                                # Reset function stats
                                size = 0
                                jals = 0
                                labels = 0
                                columns = {}
                                for column in standardSearchColumns:
                                    columns[column] = 0

                                for line in fh_asm:
                                    if "// " in line:
                                        if "Jumptable" in line:
                                            jumptable = True
                                        if "Displaylist stuff" in line:
                                            displaylist = True
                                    for column in standardSearchColumns:
                                        columns[column] += sum(searchTerm in line for searchTerm in standardSearchColumns[column])
                                    if "jal" in line:
                                        jals += 1
                                    if line.startswith("/* "):
                                        size += 4
                                    if line.startswith(".L80"):
                                        labels += 1

                                ASMFilePath = ASMFile.split("/")

                                print(
                                    ASMFile.replace(ASMFilePath[-1], ""),
                                    ASMFilePath[-1].replace(".s", ""),
                                    size,
                                    end=" ")

                                # For each column, print the value
                                for column in columns:
                                    print(columns[column], end=" ")

                                print(
                                    round(jals / size, precision),
                                    round(labels / size, precision),
                                    round(columns["floats"] / size, precision),
                                    "True" if doable else "-",
                                    "True" if regalloc else "-",
                                    "True" if stack else "-"
                                )
                        continue

                    jumptable = False
                    rodata = False
                    displaylist = False
                    doable = False
                    regalloc = False
                    stack = False
