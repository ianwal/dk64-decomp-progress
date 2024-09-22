#!/usr/bin/env python3
orphanFunctionsWithSignatures = [
    "func_global_asm_80612790",
    "func_global_asm_80612794",
    "func_global_asm_8061C464",
    "func_global_asm_806A36F4",
    "func_global_asm_806E770C",
    "func_global_asm_8073243C",
    "func_global_asm_80732924",
    "func_global_asm_80735A44",
    "func_global_asm_80737600",
    "func_global_asm_80737630",
    "func_global_asm_80737B48",
    "func_global_asm_80737B50",
    "func_global_asm_80737E9C",
    "func_global_asm_80737F38",
    "func_global_asm_807383EC",
    "func_global_asm_807383F4",
    "func_global_asm_80738BA8",
    "func_global_asm_80738BB0",
    "func_global_asm_8073AD48",
    "func_global_asm_8073E8B4",
]

functionsHLines = []
osHLines = []
progressLines = []

def getSignature(functionName):
    for i, line in enumerate(functionsHLines):
        if functionName in line:
            del functionsHLines[i]
            return line
    functionName = functionName.replace("(", "")
    if isMatched(functionName):
        return f'// TODO: {functionName} has no documented signature but has been matched'
    else:
        return f'// TODO: {functionName} has no documented signature'

def isLibultra(functionName):
    if functionName.startswith("__os") or functionName.startswith("osSp") or functionName.startswith("osPi"):
        return True

    for line in osHLines:
        if functionName in line:
            return True

    return False

def isMatched(functionName):
    for line in progressLines:
        if functionName in line:
            return line.endswith(",yes")
    return False

if __name__ == "__main__":
    with open("./include/functions.h", 'r') as f:
        for line in f:
            functionsHLines.append(line.strip())

    with open("./include/2.0L/PR/os.h", 'r') as f:
        for line in f:
            osHLines.append(line.strip())

    with open("./include/2.0L/PR/gu.h", 'r') as f:
        for line in f:
            osHLines.append(line.strip())

    with open("./progress/progress.total.csv", 'r') as f:
        for line in f:
            progressLines.append(line.strip())

    # header header
    print("#ifndef __FUNCTIONS_H__")
    print("#define __FUNCTIONS_H__")
    print("")
    print('#include "enums.h"')
    print('#include "structs.h"')
    print('#include "variables.h"')
    print("")
    print("/* your function prototype definitions go here */")
    print("")
    print("// Orphaned functions with signatures")
    print("// TODO: Assign these to a .c file")
    for func in orphanFunctionsWithSignatures:
        print(getSignature(func))

    with open("./build/us/donkeykong64.us.map", 'r') as f:
        grabbingFunctions = False
        filename = ''
        sigs = []
        for line in f:
            line = line.strip()
            if line.startswith(".text") and line.endswith(".c.o"):
                if grabbingFunctions:
                    if len(sigs) > 0:
                        print("")
                        print(f"// {filename}")
                        for sig in sigs:
                            print(sig)
                        sigs = []
                info = line.split()
                filename = info[3].replace("build/us/src/", "").replace(".o", "")
                grabbingFunctions = True
            elif line.startswith(".data") or line.startswith(".rodata") or line.endswith("_TEXT_END = ."):
                if grabbingFunctions:
                    grabbingFunctions = False
                    if len(sigs) > 0:
                        print("")
                        print(f"// {filename}")
                        for sig in sigs:
                            print(sig)
                        sigs = []
            elif grabbingFunctions:
                splitLine = line.split()
                if len(splitLine) == 2 and not splitLine[1].startswith(".L"):
                    if not isLibultra(f"{splitLine[1]}("):
                        sig = getSignature(f"{splitLine[1]}(")
                        sigs.append(sig)

    # header footer
    print("#endif")
    print("")
