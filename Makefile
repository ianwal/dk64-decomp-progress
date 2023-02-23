### Configuration ###
BASENAME = donkeykong64
VERSION ?= us

### Tools ###

# System tools
MKDIR := mkdir
CP := cp
CD := cd
RM := rm
CAT := cat
DIFF := diff
GUNZIP := gunzip

# Build tools
CROSS = mips-linux-gnu-
CC = ido/ido5.3_recomp/cc #!!! CORRECT COMPILER TO BE DETERMINED
CPP = cpp
GCC = $(CROSS)gcc
AS = $(CROSS)as
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy
PYTHON = python3
GREP := grep -rl
SPLAT = $(PYTHON) tools/n64splat/split.py
PRINT   := printf
ASM_PROCESSOR_DIR := tools/asm-processor
GZIP_DIR          := tools/gzip-1.2.4

GZIP              := $(GZIP_DIR)/gzip
ASM_PROCESSOR     := $(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py
SPLAT_INPUTS      := $(PYTHON) tools/splat_inputs.py
PROGRESS          := $(PYTHON) tools/progress.py
PROGRESS_READ     := $(PYTHON) tools/progress_read.py
PNG_TO_INCC       := $(PYTHON) tools/build/img/build.py

### Files and Directories ###

# Inputs
OVERLAYS := global_asm menu multiplayer minecart race bonus water arcade jetpac boss

# Creates a list of all the source files for the given overlay (e.g. BGS_C_SRCS)
# Appends that list to OVERLAY_C_FILES
define get_overlay_sources
  $(1)_C_SRCS      := $(filter $(SRC_ROOT)/$(1)/%,$(ALL_C_SRCS))
  $(1)_ASM_SRCS    := $(filter $(ASM_ROOT)/$(1)/%,$(ALL_ASM_SRCS))
  $(1)_BINS        := $(filter $(BIN_ROOT)/$(1)/%,$(ALL_BINS))
  $(1)_IMGS        := $(filter $(BIN_ROOT)/$(1)/%,$(ALL_IMGS))
  OVERLAY_C_SRCS   += $$($(1)_C_SRCS)
  OVERLAY_ASM_SRCS += $$($(1)_ASM_SRCS)
  OVERLAY_BINS     += $$($(1)_BINS)
  OVERLAY_IMGS     += $$($(1)_IMGS)
  # Overlay inputs
  $(1)_NEW_FILES := $$(filter $(BIN_ROOT)/$(1)/%, $(NEW_BINS)) $$(filter $(BIN_ROOT)/$(1)/%, $(NEW_IMGS)) $$(filter $(SRC_ROOT)/$(1)/%, $(NEW_C_SRCS)) $$(filter $(ASM_ROOT)/$(1)/%, $(NEW_ASM_SRCS))
  OVERLAY_NEW_FILES += $$($(1)_NEW_FILES)
endef

# Source files
SRC_ROOT          := src
ASM_ROOT          := asm
BIN_ROOT          := bin
SUBYAML           := subyaml
NONMATCHINGS      := nonmatchings
NONMATCHING_DIR   := $(ASM_ROOT)/$(NONMATCHINGS)
BUILD_ROOT        := build
BUILD_DIR         := $(BUILD_ROOT)/$(VERSION)
ALL_C_SRCS        := $(shell find $(SRC_ROOT) -type f -iname '*.c' 2> /dev/null)
ALL_ASM_SRCS      := $(filter-out $(ASM_ROOT)/$(NONMATCHINGS), $(shell find $(ASM_ROOT) -name $(NONMATCHINGS) -prune -o -iname '*.s' 2> /dev/null))
ALL_BINS          := $(shell find $(BIN_ROOT) -type f -iname '*.bin' 2> /dev/null)
ALL_IMGS          := $(shell find $(BIN_ROOT) -type f -iname '*.png' 2> /dev/null)
# Files referenced in the splat files
YAML_CALL := $(SPLAT_INPUTS) $(BASENAME).$(VERSION).yaml $(addprefix $(SUBYAML)/, $(addsuffix .$(VERSION).yaml, $(OVERLAYS)))
YAML_SRCS   := $(shell $(SPLAT_INPUTS) $(BASENAME).$(VERSION).yaml $(addprefix $(SUBYAML)/, $(addsuffix .$(VERSION).yaml, $(OVERLAYS))))
YAML_C_SRCS := $(filter %.c, $(YAML_SRCS))
YAML_ASM_SRCS := $(filter %.s, $(YAML_SRCS))
YAML_BINS := $(filter %.bin, $(YAML_SRCS))
YAML_IMGS := $(filter %.png, $(YAML_SRCS))
# Files that need to be extracted
NEW_C_SRCS := $(filter-out $(ALL_C_SRCS), $(YAML_C_SRCS))
NEW_ASM_SRCS := $(filter-out $(ALL_ASM_SRCS), $(YAML_ASM_SRCS))
NEW_BINS := $(filter-out $(ALL_BINS), $(YAML_BINS))
NEW_IMGS := $(filter-out $(ALL_IMGS), $(YAML_IMGS))
NEW_FILES := $(NEW_C_SRCS) $(NEW_ASM_SRCS) $(NEW_BINS) $(NEW_IMGS)
$(foreach overlay,$(OVERLAYS),$(eval $(call get_overlay_sources,$(overlay))))
# Files for the rom itself
MAIN_C_SRCS   := $(filter-out $(OVERLAY_C_SRCS),$(ALL_C_SRCS))
MAIN_ASM_SRCS := $(filter-out $(OVERLAY_ASM_SRCS),$(ALL_ASM_SRCS))
MAIN_BINS     := $(filter-out $(OVERLAY_BINS),$(ALL_BINS))
MAIN_IMGS     := $(filter-out $(OVERLAY_IMGS),$(ALL_IMGS))
# Files that need to be extracted for the rom itself
MAIN_NEW_FILES := $(filter-out $(OVERLAY_NEW_FILES), $(NEW_FILES))
# Any source files that have GLOBAL_ASM in them or do not exist before splitting
GLOBAL_ASM_C_SRCS := $(shell $(GREP) GLOBAL_ASM $(SRC_ROOT) </dev/null) $(NEW_C_SRCS)

# Build folders
C_DIRS         := $(sort $(dir $(ALL_C_SRCS) $(NEW_C_SRCS)))
ASM_DIRS       := $(sort $(dir $(ALL_ASM_SRCS) $(NEW_ASM_SRCS)))
BIN_DIRS       := $(sort $(dir $(ALL_BINS) $(NEW_BINS)))
IMG_DIRS       := $(sort $(dir $(ALL_IMGS) $(NEW_IMGS)))
C_BUILD_DIRS   := $(addprefix $(BUILD_DIR)/,$(C_DIRS))
ASM_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(ASM_DIRS))
BIN_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(BIN_DIRS))
IMG_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(IMG_DIRS))
ALL_DIRS       := $(C_BUILD_DIRS) $(ASM_BUILD_DIRS) $(BIN_BUILD_DIRS) $(BUILD_DIR) $(IMG_BUILD_DIRS)

# Build files
BASEROM           := baserom.$(VERSION).z64
C_OBJS            := $(addprefix $(BUILD_DIR)/,$(ALL_C_SRCS:.c=.c.o))
GLOBAL_ASM_C_OBJS := $(addprefix $(BUILD_DIR)/,$(GLOBAL_ASM_C_SRCS:.c=.c.o))
C_DEPS            := $(C_OBJS:.o=.d)
ASM_OBJS          := $(addprefix $(BUILD_DIR)/,$(ALL_ASM_SRCS:.s=.s.o) $(NEW_ASM_SRCS:.s=.s.o))
BIN_OBJS          := $(addprefix $(BUILD_DIR)/,$(ALL_BINS:.bin=.bin.o) $(NEW_BINS:.bin=.bin.o))
IMG_BINS          := $(addprefix $(BUILD_DIR)/,$(ALL_IMGS:.png=.png.bin) $(NEW_IMGS:.png=.png.bin))
IMG_OBJS          := $(IMG_BINS:.bin=.o)
Z64               := $(addprefix $(BUILD_DIR)/,$(BASENAME).$(VERSION).z64)
ELF               := $(Z64:.z64=.elf)
LD_SCRIPT         := $(BASENAME).ld
OVERLAY_ELFS      := $(addprefix $(BUILD_DIR)/,$(addsuffix .elf,$(OVERLAYS)))
OVERLAY_CODE_BINS := $(OVERLAY_ELFS:.elf=.code)
OVERLAY_DATA_BINS := $(OVERLAY_ELFS:.elf=.data)
OVERLAY_BINS      := $(addprefix $(BUILD_DIR)/,$(addsuffix .$(VERSION).bin,$(OVERLAYS)))
OVERLAY_RZIPS     := $(addprefix $(BIN_ROOT)/,$(addsuffix .$(VERSION).rzip.bin,$(OVERLAYS)))
OVERLAY_RZIP_OUTS := $(addprefix $(BUILD_DIR)/,$(addsuffix .rzip.bin,$(OVERLAYS)))
OVERLAY_RZIP_OBJS := $(addprefix $(BUILD_DIR)/$(BIN_ROOT)/,$(addsuffix .$(VERSION).rzip.bin.o,$(OVERLAYS)))
BIN_OBJS          := $(filter-out $(OVERLAY_RZIP_OBJS),$(BIN_OBJS))
ALL_OBJS          := $(C_OBJS) $(ASM_OBJS) $(BIN_OBJS) $(OVERLAY_RZIP_OBJS)
SYMBOL_ADDRS      := symbol_addrs.$(VERSION).txt
SYMBOL_ADDR_FILES := $(filter-out $(SYMBOL_ADDRS), $(wildcard symbol_addrs.*.$(VERSION).txt))
MIPS3_OBJS        := $(BUILD_DIR)/$(SRC_ROOT)/done/ll.c.o $(BUILD_DIR)/$(SRC_ROOT)/global_asm/done/ll.c.o
# Object files for the rom itself
MAIN_C_OBJS       := $(addprefix $(BUILD_DIR)/,$(MAIN_C_SRCS:.c=.c.o))
MAIN_ASM_OBJS     := $(addprefix $(BUILD_DIR)/,$(MAIN_ASM_SRCS:.s=.s.o))
MAIN_BIN_OBJS     := $(addprefix $(BUILD_DIR)/,$(MAIN_BINS:.bin=.bin.o))
MAIN_IMG_OBJS     := $(addprefix $(BUILD_DIR)/,$(MAIN_IMGS:.png=.png.o))
MAIN_OBJS         := $(MAIN_C_OBJS) $(MAIN_ASM_OBJS) $(MAIN_BIN_OBJS) $(MAIN_IMG_OBJS)
# Includes the build artifacts of any files to be extracted
MAIN_ALL_OBJS := $(MAIN_OBJS) $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(MAIN_NEW_FILES)))

# Progress files
MAIN_PROG_CSV     := progress/progress.dk64_boot.csv
MAIN_PROG_SVG     := progress/progress_dk64_boot.svg
TOTAL_PROG_CSV    := progress/progress.total.csv
TOTAL_PROG_SVG    := progress/progress_total.svg
OVERLAY_PROG_CSVS := $(addprefix progress/progress., $(addsuffix .csv, $(OVERLAYS)))
OVERLAY_PROG_SVGS := $(addprefix progress/progress_, $(addsuffix .svg, $(OVERLAYS)))

# Creates a list of all the object files for the given overlay
define get_overlay_objects
  $(1)_C_OBJS      := $(addprefix $(BUILD_DIR)/,$($(1)_C_SRCS:.c=.c.o))
  $(1)_ASM_OBJS    := $(addprefix $(BUILD_DIR)/,$($(1)_ASM_SRCS:.s=.s.o))
  $(1)_BIN_OBJS    := $(addprefix $(BUILD_DIR)/,$($(1)_BINS:.bin=.bin.o))
  $(1)_IMG_OBJS    := $(addprefix $(BUILD_DIR)/,$($(1)_IMGS:.png=.png.o))
  $(1)_OBJS        := $$($(1)_C_OBJS) $$($(1)_ASM_OBJS) $$($(1)_BIN_OBJS) $$($(1)_IMG_OBJS)
  $(1)_ALL_OBJS    := $$($(1)_OBJS) $$(addprefix $(BUILD_DIR)/, $$(addsuffix .o, $$($(1)_NEW_FILES)))
  OVERLAY_OBJS     += $$($(1)_OBJS)
endef

$(foreach overlay,$(OVERLAYS),$(eval $(call get_overlay_objects,$(overlay))))

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

define print3
  @$(PRINT) "$(RED)$(1) $(BLUE)$(2)$(NO_COL)\n"
endef

### Flags ###

# Build tool flags
CFLAGS         := -c -Wab,-r4300_mul -non_shared -G 0 -Xfullwarn -Xcpluscomm  -signed $(OPT_FLAGS) $(MIPSBIT) -D_FINALROM -DF3DEX2_GBI
CFLAGS         += -woff 649,838,807
CPPFLAGS       := -D_FINALROM -DN_MICRO -DF3DEX_GBI_2x
INCLUDE_CFLAGS := -I . -I include -I include/2.0L -I include/2.0L/PR
OPT_FLAGS      := -O2 
MIPSBIT        := -mips2
ASFLAGS        := -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include
GCC_ASFLAGS    := -c -x assembler-with-cpp -mabi=32 -ffreestanding -mtune=vr4300 -march=vr4300 -mfix4300 -G 0 -O -mno-shared -fno-PIC -mno-abicalls
LDFLAGS_COMMON := --no-check-sections --accept-unknown-input-arch -T symbol_addrs.dk64_boot.$(VERSION).txt
LDFLAGS        := -T $(LD_SCRIPT) -T symbol_addrs.rom.$(VERSION).txt -Map $(ELF:.elf=.map)  --no-check-sections --accept-unknown-input-arch
BINOFLAGS      := -I binary -O elf32-big

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
verify: $(Z64) | $(ALL_DIRS)
	@$(DIFF) $(BASEROM) $(Z64) > /dev/null && \
	$(PRINT) "$(YELLOW) _\n//\\ \nV  \\ \n \\  \\_\n  \\,'.'-.\n   |\\ '. '.\n   ( \\  '. '-.                        _,.-:\\ \n    \\ \\   '.  '-._             __..--' ,-';/\n     \\ '.   '-.   '-..___..---'   _.--' ,'/\n      '. '.    '-._        __..--'    ,' /\n        '. '-_     ''--..''       _.-' ,'\n          '-_ '-.___        __,--'   ,'\n             '-.__  '----\"\"\"    __.-'\n                  '--..____..--'\n$(BLUE)$(BASENAME).$(VERSION).z64$(NO_COL): $(GREEN)OK$(NO_COL)\n" || \
	$(PRINT) "$(BLUE)$(BASEROM) $(RED)differs$(NO_COL)\n"
	@$(PRINT) "def apply(config, args):\n" > diff_settings.py
	@$(PRINT) "\tconfig[\"baseimg\"] = \"$(BASEROM)\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"myimg\"] = \"$(Z64)\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"mapfile\"] = \"$(Z64:.z64=.map)\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"source_directories\"] = ['$(SRC_ROOT)', 'include']\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"makeflags\"] = ['-s']\n" >> diff_settings.py

# Musical note print for individual overlays
# Need to figure out how to print this only when building a single overlay
# $(YELLOW)    ╒════╕\n    │    │\n   _│   _│\n  └─┘  └─┘\n

# Verify that any given overlay matches, also sets up diff_settings

verify-%: $(BUILD_DIR)/%.rzip.bin $(BIN_ROOT)/%.$(VERSION).rzip.bin $(BUILD_DIR)/%.full progress/progress_%.svg
	@$(DIFF) $< $(BIN_ROOT)/$*.$(VERSION).rzip.bin > /dev/null && \
	$(PRINT) "$(BLUE)%-10s$(NO_COL): $(GREEN)OK$(NO_COL)\n" "$*" || \
	$(PRINT) "$(BLUE)$* $(RED)differs$(NO_COL)\n"
	@$(PRINT) "def apply(config, args):\n" > diff_settings.py
	@$(PRINT) "\tconfig[\"baseimg\"] = \"$(BUILD_DIR)/$*.$(VERSION).bin\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"myimg\"] = \"$(BUILD_DIR)/$*.full\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"mapfile\"] = \"$(BUILD_DIR)/$*.map\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"source_directories\"] = ['$(SRC_ROOT)/$*', 'include']\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"makeflags\"] = ['TARGET=$*','-s']\n" >> diff_settings.py

$(OVERLAY_PROG_SVGS) : progress/progress_%.svg: progress/progress.%.csv
	$(call print1,Creating progress svg for:,$*)
	@$(PROGRESS_READ) $< $(VERSION) $*

$(OVERLAY_PROG_CSVS) : progress/progress.%.csv: $(BUILD_DIR)/%.elf
	$(call print1,Calculating progress for:,$*)
	@$(PROGRESS) . $(BUILD_DIR)/$*.elf .code --version $(VERSION) --subcode $* > $@

$(MAIN_PROG_SVG): $(MAIN_PROG_CSV)
	$(call print1,Creating progress svg for:,boot)
	@$(PROGRESS_READ) $< $(VERSION) dk64_boot

$(MAIN_PROG_CSV): $(ELF)
	$(call print1,Calculating progress for:,boot)
	@$(PROGRESS) . $< .dk64_boot --version $(VERSION) --subcode dk64_boot > $@

$(TOTAL_PROG_SVG): $(TOTAL_PROG_CSV)
	$(call print0,Creating total progress svg)
	@$(PROGRESS_READ) $< $(VERSION) total

$(TOTAL_PROG_CSV): $(OVERLAY_PROG_CSVS) $(MAIN_PROG_CSV)
	$(call print0,Calculating total progress)
	@cat $^ > $@

# Verify that each overlay matches
verify-each: $(addprefix verify-,$(OVERLAYS)) 

# per-overlay rules
  # .o -> .elf (overlay)
define global_asm_elf_rule
  # .o -> .elf (overlay)
  $(BUILD_DIR)/$(1).elf : $$($(1)_ALL_OBJS) $(1).ld
	$(call print1,Linking elf:,$$@)
	$(LD) -T $(1).ld -Map $(BUILD_DIR)/$(1).map $$(LDFLAGS_COMMON) -T symbol_addrs.$(1).$(VERSION).txt -T undefined_syms_auto.$(1).$(VERSION).txt -T undefined_funcs_auto.$(1).$(VERSION).txt -o $$@
endef

define overlay_elf_rule
  # .o -> .elf (overlay)
  $(BUILD_DIR)/$(1).elf : $$($(1)_ALL_OBJS) $(1).ld
	$(call print1,Linking elf:,$$@)
	$(LD) -T $(1).ld -Map $(BUILD_DIR)/$(1).map $$(LDFLAGS_COMMON) -T symbol_addrs.$(1).$(VERSION).txt -T symbol_addrs.global_asm.$(VERSION).txt -T undefined_syms_auto.$(1).$(VERSION).txt -T undefined_funcs_auto.$(1).$(VERSION).txt -o $$@
endef

define overlay_rules
  # split overlay
  $(BUILD_DIR)/$(1)_SPLAT_TIMESTAMP : $(SUBYAML)/$(1).$(VERSION).yaml $(BUILD_DIR)/$(1).$(VERSION).bin $(SYMBOL_ADDRS)
	$(call print1,Splitting bin:,$$<)
	@$(SPLAT) --target $(BUILD_DIR)/$(1).$(VERSION).bin $(SUBYAML)/$(1).$(VERSION).yaml --basedir . > /dev/null
	@touch $$@
	@touch $(1).ld
  # Dummy target to make sure extraction happens before compilation, mainly for extracted asm
  $$($(1)_C_SRCS) $$($(1)_ASM_SRCS) $$($(1)_BINS) : | $(BUILD_DIR)/$(1)_SPLAT_TIMESTAMP
	@:
  # Dummy target to make sure extraction happens before processing extracted files and linking
  $$($(1)_NEW_FILES) $(1).ld: $(BUILD_DIR)/$(1)_SPLAT_TIMESTAMP
	@:
endef
$(foreach overlay,$(OVERLAYS),$(eval $(call overlay_rules,$(overlay))))
$(foreach overlay,$(filter-out global_asm, $(OVERLAYS)),$(eval $(call overlay_elf_rule,$(overlay))))
$(eval $(call global_asm_elf_rule,global_asm))


# mkdir
$(ALL_DIRS) :
	$(call print1,Making folder:,$@)
	@$(MKDIR) -p $@

# .s -> .o (assemble with gcc for preprocessor support)
$(BUILD_DIR)/%.s.o: %.s | $(ASM_BUILD_DIRS)
	$(call print2,Assembling:,$<,$@)
	@$(GCC) $(GCC_ASFLAGS) $(INCLUDE_CFLAGS) -o $@ $<

# .png -> .png.bin
$(IMG_BINS) : $(BUILD_DIR)/%.png.bin : %.png | $(IMG_BUILD_DIRS)
	$(call print2,Converting image:,$<,$@)
	@tools/build/img/build.py auto $< $@

# .png.bin -> .png.o
$(IMG_OBJS) : $(BUILD_DIR)/%.png.o : $(BUILD_DIR)/%.png.bin
	$(call print2,Objcopying:,$<,$@)
	@$(OBJCOPY) $(BINOFLAGS) $< $@

# .bin -> .o
$(BIN_OBJS) : $(BUILD_DIR)/%.bin.o : %.bin | $(BIN_BUILD_DIRS)
	$(call print2,Objcopying:,$<,$@)
	@$(OBJCOPY) $(BINOFLAGS) $< $@

# .bin -> .o (overlay)
$(OVERLAY_RZIP_OBJS) : $(BUILD_DIR)/$(BIN_ROOT)/%.$(VERSION).rzip.bin.o : $(BUILD_DIR)/%.rzip.bin 
	$(call print2,Objcopying:,$<,$@)
	@$(OBJCOPY) $(BINOFLAGS) $< $@

# .c -> .o
$(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling:,$<,$@)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $<

# .c -> .o (mips3)
$(MIPS3_OBJS) : $(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling:,$<,$@)
	@$(CC) -c -32 $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) $(MIPSBIT) -o $@ $<
	@tools/set_o32abi_bit.py $@

# .c -> .o with asm processor
$(GLOBAL_ASM_C_OBJS) : $(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling (with ASM Processor):,$<,$@)
	@$(ASM_PROCESSOR) $(OPT_FLAGS) $< > $(BUILD_DIR)/$<
	@$(CC) -32 $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $(BUILD_DIR)/$<
	@$(ASM_PROCESSOR) $(OPT_FLAGS) $< --post-process $@ \
		--assembler "$(AS) $(ASFLAGS)" --asm-prelude $(ASM_PROCESSOR_DIR)/prelude.s

# Split baserom
$(BUILD_DIR)/SPLAT_TIMESTAMP: $(BASENAME).$(VERSION).yaml $(SYMBOL_ADDRS) | $(BUILD_DIR)
	$(call print1,Splitting rom:,$<)
	@touch $@
	@$(SPLAT) $(BASENAME).$(VERSION).yaml
	@touch $(LD_SCRIPT)
# Dummy target to make the LD script and overlay rzips depend on splat being run
#   without causing it to be rerun once for every overlay
# Bin files are also dependent on the splat timestamp since they get overwritten on resplit
$(MAIN_NEW_FILES) $(LD_SCRIPT) $(MAIN_BINS) : $(BUILD_DIR)/SPLAT_TIMESTAMP
	@:
# Dummy target to make sure extraction happens before compilation, mainly for extracted asm
$(MAIN_C_SRCS) $(MAIN_ASM_SRCS) : | $(BUILD_DIR)/SPLAT_TIMESTAMP
	@:

# .rzip.bin -> .bin
$(OVERLAY_BINS) : $(BUILD_DIR)/%.$(VERSION).bin : $(BIN_ROOT)/%.$(VERSION).rzip.bin | $(BUILD_DIR)
	$(call print1,Decompressing rzip:,$<)
	$(GUNZIP) -cf -S .rzip.bin $< > $@


# .elf -> .code
$(OVERLAY_CODE_BINS) : $(BUILD_DIR)/%.code : $(BUILD_DIR)/%.elf
	$(call print2,Converting overlay code:,$<,$@)
	@$(OBJCOPY) -O binary --only-section .code --only-section .mips3 $< $@

# .elf -> .data
$(OVERLAY_DATA_BINS) : $(BUILD_DIR)/%.data : $(BUILD_DIR)/%.elf
	$(call print2,Converting overlay data:,$<,$@)
	@$(OBJCOPY) -O binary --only-section .data --only-section .*_data_* $< $@

# .elf -> .full
$(BUILD_DIR)/%.full : $(BUILD_DIR)/%.elf
	@$(OBJCOPY) -O binary $< $@

# .data + .code -> .rzip.bin
$(BUILD_DIR)/%.rzip.bin : $(BUILD_DIR)/%.code $(BUILD_DIR)/%.data $(GZIP)
	$(call print1,Compressing overlay:,$@)
	$(GZIP) -cnf -9 $(BUILD_DIR)/$*.code > $@
	$(GZIP) -cnf -9 $(BUILD_DIR)/$*.data >> $@
	truncate -s%16 $@

# .o -> .elf (game)
$(ELF): $(MAIN_ALL_OBJS) $(LD_SCRIPT) $(OVERLAY_RZIP_OBJS) $(addprefix $(BUILD_DIR)/, $(addsuffix .full, $(OVERLAYS)))
	$(call print1,Linking elf:,$@)
	@$(LD) $(LDFLAGS) -T undefined_syms_auto.$(VERSION).txt -o $@

# .elf -> .z64
$(Z64) : $(ELF) $(OVERLAY_PROG_SVGS) $(MAIN_PROG_SVG) $(TOTAL_PROG_SVG)
	$(call print1,Creating z64:,$@)
	@$(OBJCOPY) $< $@ -O binary $(OCOPYFLAGS)

$(GZIP_DIR)/%: $(GZIP_DIR)/Makefile
	$(call print1,Compiling compression tools:,$@)
	@$(CD) $(GZIP_DIR) && $(MAKE) gzip

$(GZIP_DIR)/Makefile:
	@$(CD) $(GZIP_DIR) && ./configure

# Combined symbol addresses file
$(SYMBOL_ADDRS): $(SYMBOL_ADDR_FILES)
	$(call print0,Combining symbol address files)
	@$(CAT) symbol_addrs.*.$(VERSION).txt > $@

# Shorthand rules for each overlay (e.g. SM)
$(OVERLAYS): %: verify-%

clean:
	$(call print0,Cleaning build artifacts)
	@$(RM) -rf $(BUILD_ROOT)
	@$(RM) -rf $(BIN_ROOT)
	@$(RM) -rf $(NONMATCHING_DIR)
	@$(RM) -rf $(ASM_ROOT)/*.s
	@$(RM) -rf $(addprefix $(ASM_ROOT)/,$(filter-out global_asm,$(OVERLAYS)))
	@$(RM) -rf $(ASM_ROOT)/global_asm/*.s
	@$(RM) -rf $(ASM_ROOT)/global_asm/os
	@$(RM) -f undefined_syms_auto* undefined_funcs_auto*
	@$(RM) -f *.ld
	@$(RM) -f $(SYMBOL_ADDRS)

# Per-file flag definitions
build/us/src/dk64_boot/dk64_boot_3C00.c.o: OPT_FLAGS = -O1
build/us/src/dk64_boot/dk64_boot_61D0.c.o: OPT_FLAGS = -O1
build/us/src/dk64_boot/gu/%.c.o: OPT_FLAGS = -O3
build/us/src/dk64_boot/gu/nonmatching/%.c.o: OPT_FLAGS = -O2
build/us/src/dk64_boot/io/%.c.o: OPT_FLAGS = -O1
build/us/src/dk64_boot/io/conteepwrite.c.o: OPT_FLAGS = -O2
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

# Phony targets
.PHONY: all clean verify $(OVERLAYS) progress $(addprefix progress-,$(OVERLAYS))

# Set up pipefail
SHELL = /bin/bash -e -o pipefail

# Debug variable print target
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
