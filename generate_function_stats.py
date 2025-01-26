#!/usr/bin/env python3

import os;

precision = 4
totalCodeBytes = 1647440 # Used to calculate how much percentage a function is worth

searchPath = "src"
excludePaths = [
    "src/dk64_boot",
    "src/global_asm/audio/done",
    "src/global_asm/done",
    "src/global_asm/heap.c",
    "src/global_asm/hud.c",
    "src/global_asm/code_15010.c",
    "src/global_asm/code_77B90.c",
]

commentSearch = {
    "jumptable": [
        "jump table",
        "jumptable",
    ],
    "displaylist": [
        "display list",
        "displaylist",
    ],
    "rodata": [
        "rodata",
    ],
    "doable": [
        "doable",
    ],
    "close": [
        "close",
    ],
    "regalloc": [
        "regalloc",
    ],
    "stack": [
        "stack",
    ],
}

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
    "actor": [
        "current_actor_pointer",
        "player_pointer",
        "last_spawned_actor",
        "current_player",
        "D_global_asm_807FBB4C",
        "D_global_asm_807FBD6C",
        "D_global_asm_807FDC94",
    ],
    "rand": [
        "rand",
        "func_global_asm_806119A0",
    ],
    "malloc": [
        "malloc",
    ],
    "flag": [
        "setFlag",
        "isFlagSet",
    ],
    "CS": [
        "playCutscene",
        "is_cutscene_active",
    ],
    "cc": [
        "character_change_array",
        "cc_player_index",
        "cc_number_of_players",
        "current_character_index",
    ],
    "renderActor": [
        "renderActor",
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
    "scratch",
    "bytes",
    "worth",
    end=" "
)

# For each column, print the name of the column
for column in standardSearchColumns:
    print(column, end=" ")

print(
    "jalratio",
    "labelratio",
    "floatratio",
    end=" "
)

# For each comment search term, print the name of the search
for comment in commentSearch:
    print(comment, end=" ")

# Newline
print()

for root, dirs, files in os.walk(searchPath):
    for file in files:
        fullFile = os.path.join(root, file)
        if sum(excludePath in fullFile for excludePath in excludePaths) == 0 and file.endswith('.c'):
            with open(fullFile, "r") as fh_c:
                comments = {}
                scratch = ''
                for comment in commentSearch:
                    comments[comment] = False

                for line in fh_c:
                    if line.startswith("//"):
                        if line.startswith('// https://decomp.me/scratch/'):
                            scratch = line.replace('// ', '').replace('\n', '')
                        lowerCaseComment = line.lower()
                        for comment in commentSearch:
                            check = sum(searchTerm in lowerCaseComment for searchTerm in commentSearch[comment])
                            if check > 0:
                                comments[comment] = True
                        continue

                    if "#pragma GLOBAL_ASM(" in line:
                        # Parse ASM and compute row for function
                        ASMFile = line.replace("#pragma GLOBAL_ASM(\"", "").replace("\")\n", "")
                        with open(ASMFile, "r") as fh_asm:
                            # Reset function stats
                            size = 0
                            countingSize = False
                            jals = 0
                            labels = 0
                            
                            ASMFilePath = ASMFile.split("/")
                            functionName = ASMFilePath[-1].replace(".s", "")

                            columns = {}
                            for column in standardSearchColumns:
                                columns[column] = 0

                            for line in fh_asm:
                                for column in standardSearchColumns:
                                    columns[column] += sum(searchTerm in line for searchTerm in standardSearchColumns[column])
                                if line.startswith(f"glabel {functionName}"):
                                    countingSize = True
                                if "jal" in line:
                                    jals += 1
                                if countingSize and line.startswith("/* "):
                                    size += 4
                                if line.startswith(".L"):
                                    labels += 1

                            print(
                                ASMFile.replace(ASMFilePath[-1], ""),
                                functionName,
                                scratch,
                                size,
                                f"{str(round(size / totalCodeBytes * 100, precision)).ljust(precision + 2, '0')}%",
                                end=" ")

                            # For each column, print the value
                            for column in columns:
                                print(columns[column], end=" ")

                            print(
                                round(jals / size, precision),
                                round(labels / size, precision),
                                round(columns["floats"] / size, precision),
                                end=" "
                            )

                            # For each comment search, print the value
                            for comment in comments:
                                print(comment if comments[comment] else "-", end=" ")

                            # Newline
                            print()
                        continue

                    scratch = ''
                    for comment in commentSearch:
                        comments[comment] = False
