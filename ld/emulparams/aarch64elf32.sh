source_sh ${srcdir}/emulparams/dt-relr.sh

ARCH="aarch64:ilp32"
MACHINE=
NOP=0x1f2003d5

SCRIPT_NAME=elf
ELFSIZE=32
OUTPUT_FORMAT="elf32-littleaarch64"
BIG_OUTPUT_FORMAT="elf32-bigaarch64"
LITTLE_OUTPUT_FORMAT="elf32-littleaarch64"
NO_REL_RELOCS=yes

TEMPLATE_NAME=elf
EXTRA_EM_FILE=aarch64elf

GENERATE_SHLIB_SCRIPT=yes
GENERATE_PIE_SCRIPT=yes

MAXPAGESIZE="CONSTANT (MAXPAGESIZE)"
COMMONPAGESIZE="CONSTANT (COMMONPAGESIZE)"

ENTRY=_start
EMBEDDED=yes
SEPARATE_GOTPLT=12
IREL_IN_PLT=
TEXT_START_ADDR=0x00400000

DATA_START_SYMBOLS="${CREATE_SHLIB+PROVIDE (}__data_start = .${CREATE_SHLIB+)};"

# AArch64 does not support .s* sections.
NO_SMALL_DATA=yes

OTHER_BSS_SYMBOLS="${CREATE_SHLIB+PROVIDE (}__bss_start__ = .${CREATE_SHLIB+)};"
OTHER_BSS_END_SYMBOLS="${CREATE_SHLIB+PROVIDE (}_bss_end__ = .${CREATE_SHLIB+)}; ${CREATE_SHLIB+PROVIDE (}__bss_end__ = .${CREATE_SHLIB+)};"
OTHER_END_SYMBOLS="${CREATE_SHLIB+PROVIDE (}__end__ = .${CREATE_SHLIB+)};"

OTHER_SECTIONS='.note.gnu.arm.ident 0 : { KEEP (*(.note.gnu.arm.ident)) }'
ATTRS_SECTIONS='.ARM.attributes 0 : { KEEP (*(.ARM.attributes)) KEEP (*(.gnu.attributes)) }'

# This sets the stack to the top of the simulator memory (2^19 bytes).
STACK_ADDR=0x80000
