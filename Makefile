### Configuration ###
BASENAME := donkeykong64
VERSION  ?= us

ifeq ($(VERSION),us)
	C_VERSION=0
endif

### Tools ###

# System tools
MKDIR := mkdir
CP := cp
CD := cd
RM := rm
CAT := cat
DIFF := diff

# Build tools
CROSS   := mips-linux-gnu-
CC      := ido/ido5.3_recomp/cc
CPP     := cpp
GCC     := $(CROSS)gcc
AS      := $(CROSS)as
LD      := $(CROSS)ld -b elf32-tradbigmips
OBJDUMP := $(CROSS)objdump
OBJCOPY := $(CROSS)objcopy
PYTHON  := python3
GREP    := grep -rl
SPLAT   := $(PYTHON) tools/n64splat/split.py
PRINT   := printf
ASM_PROCESSOR_DIR := tools/asm-processor
DK_ROM_COMPRESS   := $(PYTHON) tools/generate_compressed_rom.py
DK_ROM_DECOMPRESS := $(PYTHON) tools/generate_decompressed_rom.py
ASM_PROCESSOR     := $(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py
SPLAT_INPUTS      := $(PYTHON) tools/splat_inputs.py
PROGRESS          := $(PYTHON) tools/progress.py
PROGRESS_READ     := $(PYTHON) tools/progress_read.py

### Files and Directories ###

# Inputs
OVERLAYS := global_asm menu multiplayer minecart race bonus critter arcade jetpac boss

# Source files
SRC_ROOT          := src
ASM_ROOT          := asm
BIN_ROOT          := bin
NONMATCHINGS      := nonmatchings
NONMATCHING_DIR   := $(ASM_ROOT)/$(NONMATCHINGS)
BUILD_ROOT        := build
BUILD_DIR         := $(BUILD_ROOT)/$(VERSION)
C_SRCS            := $(shell find $(SRC_ROOT) -type f -iname '*.c' 2> /dev/null)
BOOT_C_SRCS       := $(wildcard $(SRC_ROOT)/done/*.c)
ALL_ASM_SRCS      := $(filter-out $(ASM_ROOT)/$(NONMATCHINGS), $(shell find $(ASM_ROOT) -name $(NONMATCHINGS) -prune -o -iname '*.s' 2> /dev/null))
ALL_BINS          := $(shell find $(BIN_ROOT) -type f -iname '*.bin' 2> /dev/null)
# Files referenced in the splat file
YAML_CALL := $(SPLAT_INPUTS) decompressed.$(VERSION).yaml
YAML_SRCS   := $(sort $(shell $(SPLAT_INPUTS) decompressed.$(VERSION).yaml))
YAML_C_SRCS := $(filter %.c, $(YAML_SRCS))
YAML_ASM_SRCS := $(filter %.s, $(YAML_SRCS))
YAML_BINS := $(filter %.bin, $(YAML_SRCS))
# Files that need to be extracted
NEW_C_SRCS := $(filter-out $(C_SRCS), $(YAML_C_SRCS))
NEW_ASM_SRCS := $(filter-out $(ALL_ASM_SRCS), $(YAML_ASM_SRCS))
NEW_BINS := $(filter-out $(ALL_BINS), $(YAML_BINS))
NEW_FILES := $(NEW_C_SRCS) $(NEW_ASM_SRCS) $(NEW_BINS)
BOOT_ASM_SRCS := $(filter-out asm/global_asm/%,$(NEW_ASM_SRCS) $(ALL_ASM_SRCS))
# Any source files that have GLOBAL_ASM in them or do not exist before splitting
GLOBAL_ASM_C_SRCS := $(shell $(GREP) GLOBAL_ASM $(SRC_ROOT) </dev/null) $(NEW_C_SRCS)

# Build folders
C_DIRS         := $(sort $(dir $(C_SRCS) $(NEW_C_SRCS)))
ASM_DIRS       := $(sort $(dir $(ALL_ASM_SRCS) $(NEW_ASM_SRCS)))
BIN_DIRS       := $(sort $(dir $(ALL_BINS) $(NEW_BINS)))
C_BUILD_DIRS   := $(addprefix $(BUILD_DIR)/,$(C_DIRS))
ASM_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(ASM_DIRS))
BIN_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(BIN_DIRS))
ALL_DIRS       := $(C_BUILD_DIRS) $(ASM_BUILD_DIRS) $(BIN_BUILD_DIRS) $(BUILD_DIR)

# Build files
BASEROM              := baserom.$(VERSION).z64
DECOMPRESSED_BASEROM := $(BASEROM).decompressed.z64
C_OBJS               := $(addprefix $(BUILD_DIR)/,$(C_SRCS:.c=.c.o))
BOOT_C_OBJS          := $(addprefix $(BUILD_DIR)/,$(BOOT_C_SRCS:.c=.c.o))
GLOBAL_ASM_C_OBJS    := $(addprefix $(BUILD_DIR)/,$(GLOBAL_ASM_C_SRCS:.c=.c.o))
C_DEPS               := $(C_OBJS:.o=.d)
ASM_OBJS             := $(addprefix $(BUILD_DIR)/,$(ALL_ASM_SRCS:.s=.s.o) $(NEW_ASM_SRCS:.s=.s.o))
BOOT_ASM_OBJS        := $(addprefix $(BUILD_DIR)/,$(BOOT_ASM_SRCS:.s=.s.o))
BIN_OBJS             := $(addprefix $(BUILD_DIR)/,$(ALL_BINS:.bin=.bin.o) $(NEW_BINS:.bin=.bin.o))
PRELIM_Z64           := $(addprefix $(BUILD_DIR)/,$(BASENAME).$(VERSION).prelim.z64)
PRELIM_ELF           := $(PRELIM_Z64:.z64=.elf)
UNCOMPRESSED_Z64     := $(addprefix $(BUILD_DIR)/,$(BASENAME).$(VERSION).uncompressed.z64)
FINAL_Z64            := $(addprefix $(BUILD_DIR)/,$(BASENAME).$(VERSION).z64)
ELF                  := $(FINAL_Z64:.z64=.elf)
LD_SCRIPT            := $(BASENAME).ld
ALL_OBJS             := $(C_OBJS) $(ASM_OBJS) $(BIN_OBJS)
SYMBOL_ADDRS         := symbol_addrs.$(VERSION).txt
MIPS3_OBJS           := $(BUILD_DIR)/$(SRC_ROOT)/global_asm/ll.c.o
BOOT_MIPS3_OBJS      := $(BUILD_DIR)/$(SRC_ROOT)/done/ll.c.o
BOOT_C_OBJS          := $(filter-out $(BOOT_MIPS3_OBJS),$(BOOT_C_OBJS))
COMPRESSED_SYMBOLS   := $(BUILD_DIR)/compressed_symbols.txt

# Progress files
MAIN_PROG_CSV     := progress/progress.dk64_boot.csv
MAIN_PROG_SVG     := progress/progress_dk64_boot.svg
TOTAL_PROG_CSV    := progress/progress.total.csv
TOTAL_PROG_SVG    := progress/progress_total.svg
OVERLAY_PROG_CSVS := $(addprefix progress/progress., $(addsuffix .csv, $(OVERLAYS)))
OVERLAY_PROG_SVGS := $(addprefix progress/progress_, $(addsuffix .svg, $(OVERLAYS)))

### Functions ###

# Colorful text printing
NO_COL  := \033[0m
RED     := \033[0;31m
GREEN   := \033[0;32m
BLUE    := \033[0;34m
YELLOW  := \033[0;33m
BLINK   := \033[33;5m

# Print message with zero arguments (i.e. message)
define print0
  @$(PRINT) "$(GREEN)$(1)$(NO_COL)\n"
endef

# Print message with one argument (i.e. message arg)
define print1
  @$(PRINT) "$(GREEN)$(1) $(BLUE)$(2)$(NO_COL)\n"
endef

# Print message with two arguments (i.e. message arg1 -> arg2)
define print2
  @$(PRINT) "$(GREEN)$(1) $(YELLOW)$(2)$(GREEN) -> $(BLUE)$(3)$(NO_COL)\n"
endef

### Flags ###

# Build tool flags
CFLAGS         := -c -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -signed $(OPT_FLAGS) $(MIPSBIT) -D_FINALROM -DF3DEX_GBI_2 -DTARGET_N64 -DVERSION='$(C_VERSION)'
CFLAGS         += -woff 649,654,838,807
CPPFLAGS       := -D_FINALROM -DN_MICRO -DF3DEX_GBI_2x
INCLUDE_CFLAGS := -I . -I include -I include/2.0L -I include/2.0L/PR -I include/libc
OPT_FLAGS      := -O2 
MIPSBIT        := -mips2
ASFLAGS        := -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include
GCC_ASFLAGS    := -c -x assembler-with-cpp -mabi=32 -ffreestanding -mtune=vr4300 -march=vr4300 -mfix4300 -G 0 -O -mno-shared -fno-PIC -mno-abicalls
LDFLAGS        := -T $(LD_SCRIPT) -Map $(ELF:.elf=.map) --no-check-sections --accept-unknown-input-arch -T undefined_syms_auto.$(VERSION).txt -T undefined_funcs_auto.$(VERSION).txt
BINOFLAGS      := -I binary -O elf32-tradbigmips

### Rules ###

# Default target, all
all: verify

# Shows progress for all overlays, boot, and total
progress: $(OVERLAY_PROG_CSVS) $(MAIN_PROG_CSV) $(TOTAL_PROG_CSV) 
	@$(foreach overlay,$(OVERLAYS),$(PROGRESS_READ) progress/progress.$(overlay).csv $(VERSION) $(overlay) &&) \
	$(PROGRESS_READ) $(MAIN_PROG_CSV) $(VERSION) dk64_boot
	@$(PROGRESS_READ) $(TOTAL_PROG_CSV) $(VERSION) total

# Shows progress for a single overlay (e.g. progress-SM)
$(addprefix progress-,$(OVERLAYS)) : progress-% : progress/progress.%.csv
	@$(PROGRESS_READ) $< $(VERSION) $*

# Verify that the roms match, also sets up diff_settings
verify: $(DECOMPRESSED_BASEROM) $(UNCOMPRESSED_Z64)
	@$(DIFF) $(DECOMPRESSED_BASEROM) $(UNCOMPRESSED_Z64) > /dev/null && \
	$(PRINT) "$(YELLOW)        _\n      _( )_\n     [     ]_\n      ) _   _)\n     [_( )_]\n$(BLUE)$(UNCOMPRESSED_Z64).z64$(NO_COL): $(GREEN)OK$(NO_COL)\n" || \
	$(PRINT) "$(BLUE)$(DECOMPRESSED_BASEROM) $(RED)differs$(NO_COL)\n"
	@$(PRINT) "def apply(config, args):\n" > diff_settings.py
	@$(PRINT) "\tconfig[\"baseimg\"] = \"$(DECOMPRESSED_BASEROM)\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"myimg\"] = \"$(Z64)\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"mapfile\"] = \"$(Z64:.z64=.map)\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"source_directories\"] = ['$(SRC_ROOT)', 'include']\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"makeflags\"] = ['-s']\n" >> diff_settings.py

$(OVERLAY_PROG_SVGS) : progress/progress_%.svg: progress/progress.%.csv
	$(call print1,Creating progress svg for:,$*)
	@$(PROGRESS_READ) $< $(VERSION) $*

$(OVERLAY_PROG_CSVS) : progress/progress.%.csv: $(ELF)
	$(call print1,Calculating progress for:,$*)
	@$(PROGRESS) . $(ELF) .$* --version $(VERSION) --subcode $* > $@

$(MAIN_PROG_SVG): $(MAIN_PROG_CSV)
	$(call print1,Creating progress svg for:,boot)
	@$(PROGRESS_READ) $< $(VERSION) dk64_boot

$(MAIN_PROG_CSV): $(ELF)
	$(call print1,Calculating progress for:,boot)
	@$(PROGRESS) . $< .boot_dk64_boot --version $(VERSION) > $@

$(TOTAL_PROG_SVG): $(TOTAL_PROG_CSV)
	$(call print0,Creating total progress svg)
	@$(PROGRESS_READ) $< $(VERSION) total

$(TOTAL_PROG_CSV): $(OVERLAY_PROG_CSVS) $(MAIN_PROG_CSV)
	$(call print0,Calculating total progress)
	@cat $^ > $@

# mkdir
$(ALL_DIRS) :
	$(call print1,Making folder:,$@)
	@$(MKDIR) -p $@

# .s -> .o (assemble with gcc for preprocessor support)
$(BUILD_DIR)/%.s.o: %.s | $(ASM_BUILD_DIRS)
	$(call print2,Assembling:,$<,$@)
	@$(GCC) $(GCC_ASFLAGS) $(INCLUDE_CFLAGS) -o $@ $<

# .s -> .o (boot)
$(BOOT_ASM_OBJS) : $(BUILD_DIR)/%.s.o : %.s | $(ASM_BUILD_DIRS)
	$(call print2,Assembling:,$<,$@)
	@$(GCC) $(GCC_ASFLAGS) $(INCLUDE_CFLAGS) -o $@ $<
	@$(OBJCOPY) $@

# .bin -> .o
$(BIN_OBJS) : $(BUILD_DIR)/%.bin.o : %.bin | $(BIN_BUILD_DIRS)
	$(call print2,Objcopying:,$<,$@)
	@$(OBJCOPY) $(BINOFLAGS) $< $@

# .c -> .o
$(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling:,$<,$@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $<

# .c -> .o (mips3)
$(MIPS3_OBJS) : $(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling:,$<,$@)
	@$(CC) -c -32 $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) $(MIPSBIT) -o $@ $<
	@tools/set_o32abi_bit.py $@

# .c -> .o with asm processor
$(GLOBAL_ASM_C_OBJS) : $(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling (with ASM Processor):,$<,$@)
	$(ASM_PROCESSOR) $(OPT_FLAGS) $< > $(BUILD_DIR)/$<
	@$(CC) -32 $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $(BUILD_DIR)/$<
	$(ASM_PROCESSOR) $(OPT_FLAGS) $< --post-process $@ \
		--assembler "$(AS) $(ASFLAGS)" --asm-prelude include/prelude.s

# .c -> .o (boot)
$(BOOT_C_OBJS) : $(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling:,$<,$@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $<
	mips-linux-gnu-strip $@ -N asdasdasasdasd
	$(OBJCOPY) $@
	$(OBJCOPY) --strip-unneeded $@

# .c -> .o (mips3, boot)
$(BOOT_MIPS3_OBJS) : $(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling:,$<,$@)
	@$(CC) -c -32 $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) $(MIPSBIT) -o $@ $<
	@tools/set_o32abi_bit.py $@
	$(OBJCOPY) $@
	$(OBJCOPY) --strip-unneeded $@

# Split baserom
$(BUILD_DIR)/SPLAT_TIMESTAMP: decompressed.$(VERSION).yaml $(SYMBOL_ADDRS) $(DECOMPRESSED_BASEROM) | $(BUILD_DIR)
	$(call print1,Splitting rom:,$<)
	@$(RM) -rf $(ASM_ROOT)
	@$(SPLAT) decompressed.$(VERSION).yaml
	@touch $@
	@touch $(LD_SCRIPT)

# Dummy target to make the LD script and overlay rzips depend on splat being run
#   without causing it to be rerun once for every overlay
# Bin files are also dependent on the splat timestamp since they get overwritten on resplit
$(NEW_FILES) $(LD_SCRIPT) $(ALL_BINS) : $(BUILD_DIR)/SPLAT_TIMESTAMP
	@:
# Dummy target to make sure extraction happens before compilation, mainly for extracted asm
$(C_SRCS) $(ASM_SRCS) : | $(BUILD_DIR)/SPLAT_TIMESTAMP
	@:

# decompress baserom
$(DECOMPRESSED_BASEROM): $(BASEROM)
	@$(DK_ROM_DECOMPRESS) $< $@
	
# .o -> .elf (dummy symbols)
$(PRELIM_ELF): $(ALL_OBJS) $(LD_SCRIPT)
	$(call print1,Linking elf:,$@)
	@$(LD) $(LDFLAGS) -o $@

# .elf -> .z64 (dummy symbols)
$(PRELIM_Z64) : $(PRELIM_ELF)
	$(call print1,Creating z64:,$@)
	@$(OBJCOPY) $< $@ -O binary $(OCOPYFLAGS)

# generate compressed ROM symbols
#$(COMPRESSED_SYMBOLS): $(PRELIM_ELF) $(PRELIM_Z64) $(BK_ROM_COMPRESS)
#	@$(BK_ROM_COMPRESS) --symbols $(PRELIM_ELF) $(PRELIM_Z64) $@

# .o -> .elf (game)
$(ELF): $(ALL_OBJS) $(LD_SCRIPT)
	$(call print1,Linking elf:,$@)
	@$(LD) $(LDFLAGS) -o $@

# .elf -> .z64 (uncompressed)
$(UNCOMPRESSED_Z64) : $(ELF)
	$(call print1,Creating z64:,$@)
	@$(OBJCOPY) $< $@ -O binary $(OCOPYFLAGS)

# .z64 (uncompressed) + .elf -> .z64 (final)
#$(FINAL_Z64) : $(UNCOMPRESSED_Z64) $(ELF) $(BK_ROM_COMPRESS)
#	@$(BK_ROM_COMPRESS) $(ELF) $(UNCOMPRESSED_Z64) $@

clean:
	$(call print0,Cleaning build artifacts)
	@$(RM) -rf $(BUILD_ROOT)
	@$(RM) -rf $(DECOMPRESSED_BASEROM)
	@$(RM) -rf $(BIN_ROOT)
	@$(RM) -rf $(NONMATCHING_DIR)
	@$(RM) -rf $(ASM_ROOT)
	@$(RM) -f undefined_syms_auto* undefined_funcs_auto*
	@$(RM) -f *.ld

# Per-file flag definitions
build/us/src/dk64_boot/dk64_boot_3390.c.o: OPT_FLAGS = -O1
build/us/src/dk64_boot/dk64_boot_3D20.c.o: OPT_FLAGS = -O1
build/us/src/dk64_boot/dk64_boot_3C00.c.o: OPT_FLAGS = -O1
build/us/src/dk64_boot/dk64_boot_5C70.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/dk64_boot_61D0.c.o: OPT_FLAGS = -O1
build/us/src/dk64_boot/dk64_boot_62F0.c.o: OPT_FLAGS = -O1
build/us/src/dk64_boot/dk64_boot_7F60.c.o: OPT_FLAGS = -O1
build/us/src/dk64_boot/dk64_boot_CA20.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/gu/%.c.o: OPT_FLAGS = -O3
build/us/src/dk64_boot/gu/nonmatching/%.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/%.c.o: OPT_FLAGS = -O1

build/us/src/dk64_boot/io/conteepprobe.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/conteepwrite.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/conteepread.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/contreaddata.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/sirawdma.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/pimgr.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/pfsgetstatus.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/epirawwrite.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/crc.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/viswapcontext.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/contpfs.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/contpfs.c.o: MIPSISET := -mips3 -o32
build/us/src/dk64_boot/io/motor.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/crc.c.o: OPT_FLAGS = -O2

build/us/src/dk64_boot/libc/%.c.o: OPT_FLAGS = -O3
build/us/src/dk64_boot/libc/ll%.o: MIPSISET := -mips3 -o32
build/us/src/dk64_boot/libc/ll%.o: OPT_FLAGS := -O1
build/us/src/dk64_boot/os/%.c.o: OPT_FLAGS = -O1

build/us/src/global_asm/audio/%.c.o: OPT_FLAGS = -g

#build/us/src/dk64_boot/gu/%.c.o: INCLUDE_CFLAGS = -I . -I include -I include/2.0L -I include/2.0L/PR

# Disable implicit rules
MAKEFLAGS += -r

# Disable built-in rules
.SUFFIXES:

# Phony targets
.PHONY: all clean verify $(OVERLAYS) progress $(addprefix progress-,$(OVERLAYS))

# Set up pipefail
SHELL = /bin/bash -e -o pipefail

# Debug variable print target
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
