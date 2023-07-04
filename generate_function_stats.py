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

print("file function bytes flags cutscenes cc_array actor getPointerTableFile maps exits D_807FBB70 matrix rand malloc jalratio labelratio floatratio doable regalloc stack")

matrixFunctions = [
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
]

actors = [
    "current_actor_pointer",
    "player_pointer",
    "D_807FBB44",
    "D_807FBB48",
    "D_807FBB4C",
    "D_807FBD6C",
    "D_807FDC94"
]

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
                                size = 0
                                jals = 0
                                setFlagCount = 0
                                isFlagSet = 0
                                cutscene = 0
                                current_actor_pointer = 0
                                getPointerTableFile = 0
                                labels = 0
                                floats = 0
                                maps = 0
                                exits = 0
                                d_807FBB70 = 0
                                cc_array = 0
                                matrixFunctionCount = 0
                                rand = 0
                                malloc = 0
                                for line in fh_asm:
                                    if "// " in line:
                                        if "Jumptable" in line:
                                            jumptable = True
                                        if "Displaylist stuff" in line:
                                            displaylist = True
                                    matrixFunctionCount += sum(matrixFunction in line for matrixFunction in matrixFunctions)
                                    current_actor_pointer += sum(actor in line for actor in actors)
                                    if "rand" in line:
                                        rand += 1
                                    if "malloc" in line:
                                        malloc += 1
                                    if "jal" in line:
                                        jals += 1
                                    if "setFlag" in line:
                                        setFlagCount += 1
                                    if "isFlagSet" in line:
                                        isFlagSet += 1
                                    if "playCutscene" in line or "is_cutscene_active" in line:
                                        cutscene += 1
                                    if "character_change_array" in line or "cc_player_index" in line or "cc_number_of_players" in line or "current_character_index" in line:
                                        cc_array += 1
                                    if "D_807FBB70" in line:
                                        d_807FBB70 += 1
                                    if "getPointerTableFile" in line:
                                        getPointerTableFile += 1
                                    if "current_map" in line or "next_map" in line:
                                        maps += 1
                                    if "current_exit" in line or "next_exit" in line:
                                        exits += 1
                                    if line.startswith("/* "):
                                        size += 4
                                    if line.startswith(".L80"):
                                        labels += 1
                                    if " mtc1 " in line or " mfc1 " in line:
                                        floats += 1
                                    if " lwc1 " in line or " ldc1 " in line:
                                        floats += 1
                                    if " swc1 " in line or " sdc1 " in line:
                                        floats += 1

                                ASMFilePath = ASMFile.split("/")
                                print(ASMFile.replace(ASMFilePath[-1], ""),
                                    ASMFilePath[-1].replace(".s", ""),
                                    size,
                                    setFlagCount + isFlagSet,
                                    cutscene,
                                    cc_array,
                                    current_actor_pointer,
                                    getPointerTableFile,
                                    maps,
                                    exits,
                                    d_807FBB70,
                                    matrixFunctionCount,
                                    rand,
                                    malloc,
                                    round(jals / size, precision),
                                    round(labels / size, precision),
                                    round(floats / size, precision),
                                    "True" if doable else "-",
                                    "True" if regalloc else "-",
                                    "True" if stack else "-")
                        continue

                    jumptable = False
                    rodata = False
                    displaylist = False
                    doable = False
                    regalloc = False
                    stack = False
