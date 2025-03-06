# DK64 Decomp Style Guide
## Matches > Style
- Sometimes, due to how the compiler works internally, it is not possible to get a bit perfect match while following all style guidelines.
- Matching the original binary bit perfectly takes precedence over adhering to any of the following style guidelines.
## Naming Conventions
### Functions and Variables
- Functions, arguments, and local/global variables use ```camelCase``` for the names
- Global variable names should be prefixed with ```g```, eg. ```s8 gCrashDebuggerEnabled;``` 
- Pointer asterisks go on the right, eg ```void *gSomePointer = NULL;```
- C preprocessor macros and constants use ```CONSTANT_CASE``` for the names
- Functions that are only used within one C file should be marked as ```static``` where possible
- Variables that are only used within one C file should be marked as ```static``` where possible
### Structs, Unions, and Enums
- Struct and Enum typedefs use ```PascalCase``` for the names
- Struct and Union members use ```camelCase``` for the names
- Enum members use ```CONSTANT_CASE``` for the names
- Enum typedefs should be used where possible for variables, function parameters, and struct/union members
- Enum members should replace integer literals where appropriate
- Should padding > 4 bytes be required between 2 members, please use ```u8 unkXX[0xPaddingEndOffset - 0xPaddingStartOffset];``` as the padding member
- Definitions for structs, enums, macros, and constants that are used in only one C file should live at the top of that C file
- Definitions for structs that are used in multiple C files should live in ```include/structs.h```
- Definitions for enums that are used in multiple C files should live in ```include/enums.h```
- If you need a Vector of 3 floats, we currently have it defined as ```tuple_f``` in ```include/structs.h```
    - This may change to ```Vec3f``` in the future depending on which is more common and whether we decide to break away from BK's conventions
- If a ```malloc()``` call is allocating space for a struct, please use the ```sizeof(struct)``` as the size of the buffer, with a multiplication by number of elements if allocating for an array, eg.
```TODO```

## Types
- Prefer ultratypes over C types, eg.

| C Type | Ultratype |
| ------ | --------- |
| ```unsigned char``` | ```u8``` |
| ```char``` | ```s8``` |
| ```unsigned short``` | ```u16``` |
| ```short``` | ```s16``` |
| ```unsigned int``` | ```u32``` |
| ```int``` | ```s32``` |
| ```unsigned long long int``` | ```u64``` |
| ```long long int``` | ```s64``` |
| ```float``` | ```f32``` |
| ```double``` | ```f64``` |

- Eliminate explicit typecasts where possible and appropriate
- Use ```U``` suffix for integer literals involved in explicitly unsigned assignments/expressions/comparisons
- Use ```f``` suffix for floats, and ensure decimal point is present (and trailing 0 if no fractional part)
- Use no suffix for doubles, but ensure decimal point is present (and trailing 0 if no fractional part)
- Prefer ```TRUE``` and ```FALSE``` over ```1``` and ```0``` for explicitly boolean assignments, expressions, and comparisons

## Control Flow
- Eliminate labels and gotos where possible
- Eliminate temporary variables where possible and appropriate
### Switch Case
- Prefer switch cases over ```else if``` chains where appropriate
Please indent your case blocks as follows
```TODO```
### Large Function Calls
- Function calls with many parameters may be broken up into multiple lines as follows to improve readability
```TODO```
- There are no explicit rules as to when this needs to happen, use your best judgement
### Comparisons
- Prefer ```if (expression)``` over ```if (expression != 0)``` where expression is boolean
- Prefer ```if (!expression)``` over ```if (expression == 0)``` where expression is boolean
- Prefer ```if (ptr)``` over ```if (ptr != NULL)```
- Prefer ```if (!ptr)``` over ```if (ptr == NULL)```
- Chained boolean expressions may be broken up into multiple lines as follows
```TODO```
- There are no explicit rules as to when this needs to happen, use your best judgement

## Expressions
- Prefer ```var += n``` over ```var = var + n``` for addition
- Prefer ```var -= n``` over ```var = var - n``` for subtraction
- Prefer ```var *= n``` over ```var = var * n``` for multiplication
- Prefer ```var /= n``` over ```var = var / n``` for division
- Same for ```^=```, ```|=```, ```&=```, ```>>=```, and ```<<=```
- Prefer ```var++``` over ```var += 1``` for single increments
- Prefer ```var--``` over ```var -= 1``` for single decrements
- Prefer prefix increment/decrement ```++i``` and ```--i``` for loop indices where possible
- Use ```MIN()```, ```MAX()```, ```ABS()```, and ```SQ()``` macros where possible and appropriate
- Use ```reinterpret_cast()``` macro where appropriate
- Prefer ternary expressions for simple assignments and function parameters where appropriate

## Metadata
- The python script ```generate_function_stats.py``` can be used to generate a CSV of remaining functions to match, including details scraped from special comments left in C files
- Meaningful comments above the ```#pragma GLOBAL_ASM()``` lines include
    - ```// jumptable```
    - ```// displaylist```
    - ```// rodata```
    - ```// close```
    - ```// doable```
    - ```// regalloc```
    - ```// stack```
    - ```// https://decomp.me/scratch/*```
- Meaningful comments should be combined into one line, except for the scratch link which should be on a second line directly above/below the other meaningful comments