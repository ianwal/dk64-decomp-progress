# DK64 Decomp Style Guide
## Naming
### Functions and Variables
- ```camelCase``` is preferred for function, argument, and local/global variable names
- Globals should be prefixed with 'g', eg. ```s8 gCrashDebuggerEnabled;``` 
- Pointer asterisks go on the right, eg ```void *gSomePointer = NULL;```
- Macros and preprocessor constants use ```CONSTANT_CASE```
### Structs, Unions, and Enums
- Struct and Enum typedefs use ```PascalCase``` for the names
- Struct and Union members use ```camelCase``` for the names
- Enum members use ```CONSTANT_CASE``` for the names
- If you need a Vector of 3 floats, we currently have it defined as 'tuple_f' in structs.h
    - This may change to "Vec3f" in the future depending on which is more common and whether we decide to break away from BK's conventions
- If a ```malloc()``` call is allocating space for a struct, please use the ```sizeof(struct)``` as the size of the buffer, with a multiplication by number of elements if allocating for an array, eg.
```TODO```

## Types
- Prefer ultratypes over C types, eg.

| C Type | Ultratype |
| -------- | ------- |
| ```unsigned char``` | ```u8```|
| ```char``` | ```s8```|
| ```unsigned short``` | ```u16```|
| ```short``` | ```s16```|
| ```unsigned int``` | ```u32```|
| ```int``` | ```s32```|
| ```float``` | ```f32```|
| ```double``` | ```f64```|

- Eliminate explicit typecasts where possible and appropriate
- Use ```U``` suffix for unsigned comparisons
- Use ```f``` suffix for floats, and ensure decimal point is present (and trailing 0 if no fractional part)
- Use no suffix for doubles, but ensure decimal point is present (and trailing 0 if no fractional part)
## Control Flow
- Eliminate labels and gotos where possible
- Eliminate temporary variables where possible and appropriate
### Switch Case
Please indent your case blocks as follows
```TODO```
### Large Function Calls
- Function calls with many parameters may be broken up into multiple lines as follows to improve readability
```TODO```
- There are no explicit rules as to when this needs to happen, use your best judgement
### Chained Boolean Expressions
- Chained boolean expressions may be broken up into multiple lines as follows
```TODO```
- There are no explicit rules as to when this needs to happen, use your best judgement