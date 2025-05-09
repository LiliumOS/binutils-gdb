/* This testcase is part of GDB, the GNU debugger.

   Copyright 2015-2025 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* This source file was generated by:
   gcc -o gdb.arch/amd64-tailcall-self.S -S gdb.arch/amd64-tailcall-self.c -Wall -g -dA -Os
   */

	.file	"amd64-tailcall-self.c"
	.text
.Ltext0:
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.section	.text.unlikely
.Ltext_cold0:
	.text
	.type	b, @function
b:
.LFB0:
	.file 1 "amd64-tailcall-self.c"
	# amd64-tailcall-self.c:1
	.loc 1 1 0
	.cfi_startproc
# BLOCK 2 freq:10000 seq:0
# PRED: ENTRY [100.0%]  (FALLTHRU)
	# amd64-tailcall-self.c:2
	.loc 1 2 0
# SUCC: EXIT [100.0%] 
	ret
	.cfi_endproc
.LFE0:
	.size	b, .-b
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.globl	c
	.type	c, @function
c:
.LFB1:
	# amd64-tailcall-self.c:7
	.loc 1 7 0
	.cfi_startproc
.LVL0:
# BLOCK 2 freq:10000 seq:0
# PRED: ENTRY [100.0%]  (FALLTHRU)
	# amd64-tailcall-self.c:8
	.loc 1 8 0
	leal	1(%rdi), %eax
# SUCC: EXIT [100.0%] 
	# amd64-tailcall-self.c:9
	.loc 1 9 0
	ret
	.cfi_endproc
.LFE1:
	.size	c, .-c
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text.unlikely
.LCOLDB2:
	.text
.LHOTB2:
	.globl	a
	.type	a, @function
a:
.LFB2:
	# amd64-tailcall-self.c:11
	.loc 1 11 0
	.cfi_startproc
.LVL1:
# BLOCK 2 freq:10000 seq:0
# PRED: ENTRY [100.0%]  (FALLTHRU) 3 [100.0%]  (DFS_BACK,CAN_FALLTHRU)
.L5:
	# amd64-tailcall-self.c:12
	.loc 1 12 0
#APP
# 12 "amd64-tailcall-self.c" 1
	nop;nop;nop
# 0 "" 2
	# amd64-tailcall-self.c:13
	.loc 1 13 0
#NO_APP
	movl	i(%rip), %edi
	leal	-1(%rdi), %eax
	cmpl	$9, %eax
# SUCC: 3 [91.0%]  (FALLTHRU,CAN_FALLTHRU) 4 [9.0%]  (CAN_FALLTHRU,LOOP_EXIT)
	ja	.L4
# BLOCK 3 freq:9100 seq:1
# PRED: 2 [91.0%]  (FALLTHRU,CAN_FALLTHRU)
	# amd64-tailcall-self.c:14
	.loc 1 14 0
	orl	$1, %edi
	movl	%edi, i(%rip)
# SUCC: 2 [100.0%]  (DFS_BACK,CAN_FALLTHRU)
	jmp	.L5
.Lfirsttailcall:
# BLOCK 4 freq:900 seq:2
# PRED: 2 [9.0%]  (CAN_FALLTHRU,LOOP_EXIT)
.L4:
	# amd64-tailcall-self.c:16
	.loc 1 16 0
	cmpl	$0, %edi
# SUCC: 5 [19.9%]  (FALLTHRU,CAN_FALLTHRU) 6 [80.1%]  (CAN_FALLTHRU)
	jne	.L3
# BLOCK 5 freq:179 seq:3
# PRED: 4 [19.9%]  (FALLTHRU,CAN_FALLTHRU)
# SUCC: EXIT [100.0%]  (ABNORMAL,SIBCALL)
	# amd64-tailcall-self.c:17
	.loc 1 17 0
	jmp	b
.LVL2:
# BLOCK 6 freq:721 seq:4
# PRED: 4 [80.1%]  (CAN_FALLTHRU)
.L3:
# SUCC: EXIT [100.0%] 
	ret
	.cfi_endproc
.LFE2:
	.size	a, .-a
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.text.unlikely
.LCOLDB3:
	.section	.text.startup,"ax",@progbits
.LHOTB3:
	.globl	main
	.type	main, @function
main:
.LFB3:
	# amd64-tailcall-self.c:20
	.loc 1 20 0
	.cfi_startproc
.LVL3:
# BLOCK 2 freq:10000 seq:0
# PRED: ENTRY [100.0%]  (FALLTHRU)
	# amd64-tailcall-self.c:21
	.loc 1 21 0
	call	a
.LVL4:
	# amd64-tailcall-self.c:23
	.loc 1 23 0
	xorl	%eax, %eax
# SUCC: EXIT [100.0%] 
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE3:
	.section	.text.startup
.LHOTE3:
	.comm	i,4,4
	.text
.Letext0:
	.section	.text.unlikely
.Letext_cold0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	2f-1f	# Length of Compilation Unit Info
1:
	.value	0x4	# DWARF version number
	.long	.Ldebug_abbrev0	# Offset Into Abbrev. Section
	.byte	0x8	# Pointer Size (in bytes)
	.uleb128 0x1	# (DIE (0xb) DW_TAG_compile_unit)
	.long	.LASF4	# DW_AT_producer: "GNU C 4.9.2 20150212 (Red Hat 4.9.2-6) -mtune=generic -march=x86-64 -g -Os"
	.byte	0x1	# DW_AT_language
	.long	.LASF5	# DW_AT_name: "amd64-tailcall-self.c"
	.long	.LASF6	# DW_AT_comp_dir: "/home/jkratoch/t"
	.long	.Ldebug_ranges0+0	# DW_AT_ranges
	.quad	0	# DW_AT_low_pc
	.long	.Ldebug_line0	# DW_AT_stmt_list
die29:
	.uleb128 0x2	# (DIE (0x29) DW_TAG_subprogram)
	.ascii "b\0"	# DW_AT_name
	.byte	0x1	# DW_AT_decl_file (amd64-tailcall-self.c)
	.byte	0x1	# DW_AT_decl_line
			# DW_AT_prototyped
	.quad	.LFB0	# DW_AT_low_pc
	.quad	.LFE0-.LFB0	# DW_AT_high_pc
	.uleb128 0x1	# DW_AT_frame_base
	.byte	0x9c	# DW_OP_call_frame_cfa
			# DW_AT_GNU_all_call_sites
	.uleb128 0x3	# (DIE (0x40) DW_TAG_subprogram)
			# DW_AT_external
	.ascii "c\0"	# DW_AT_name
	.byte	0x1	# DW_AT_decl_file (amd64-tailcall-self.c)
	.byte	0x7	# DW_AT_decl_line
			# DW_AT_prototyped
	.long	die6b - .Ldebug_info0	# DW_AT_type
	.quad	.LFB1	# DW_AT_low_pc
	.quad	.LFE1-.LFB1	# DW_AT_high_pc
	.uleb128 0x1	# DW_AT_frame_base
	.byte	0x9c	# DW_OP_call_frame_cfa
			# DW_AT_GNU_all_call_sites
	.uleb128 0x4	# (DIE (0x5f) DW_TAG_formal_parameter)
	.ascii "q\0"	# DW_AT_name
	.byte	0x1	# DW_AT_decl_file (amd64-tailcall-self.c)
	.byte	0x7	# DW_AT_decl_line
	.long	die6b - .Ldebug_info0	# DW_AT_type
	.uleb128 0x1	# DW_AT_location
	.byte	0x55	# DW_OP_reg5
	.byte	0	# end of children of DIE 0x40
die6b:
	.uleb128 0x5	# (DIE (0x6b) DW_TAG_base_type)
	.byte	0x4	# DW_AT_byte_size
	.byte	0x5	# DW_AT_encoding
	.ascii "int\0"	# DW_AT_name
die72:
	.uleb128 0x6	# (DIE (0x72) DW_TAG_subprogram)
			# DW_AT_external
	.ascii "a\0"	# DW_AT_name
	.byte	0x1	# DW_AT_decl_file (amd64-tailcall-self.c)
	.byte	0xb	# DW_AT_decl_line
			# DW_AT_prototyped
	.quad	.LFB2	# DW_AT_low_pc
	.quad	.LFE2-.LFB2	# DW_AT_high_pc
	.uleb128 0x1	# DW_AT_frame_base
	.byte	0x9c	# DW_OP_call_frame_cfa
			# DW_AT_GNU_all_call_sites
	.uleb128 0x4	# (DIE (0x8d) DW_TAG_formal_parameter)
	.ascii "q\0"	# DW_AT_name
	.byte	0x1	# DW_AT_decl_file (amd64-tailcall-self.c)
	.byte	0xb	# DW_AT_decl_line
	.long	die6b - .Ldebug_info0	# DW_AT_type
	.uleb128 0x4	# DW_AT_location
	.byte	0xf3	# DW_OP_GNU_entry_value
	.uleb128 0x1
	.byte	0x55	# DW_OP_reg5
	.byte	0x9f	# DW_OP_stack_value
	.uleb128 0x7	# (DIE () DW_TAG_GNU_call_site)
	.quad	.Lfirsttailcall	# DW_AT_low_pc
			# DW_AT_GNU_tail_call
	.long	die72 - .Ldebug_info0	# DW_AT_abstract_origin
	.uleb128 0x7	# (DIE (0x9b) DW_TAG_GNU_call_site)
	.quad	.LVL2	# DW_AT_low_pc
			# DW_AT_GNU_tail_call
	.long	die29 - .Ldebug_info0	# DW_AT_abstract_origin
	.byte	0	# end of children of DIE 0x72
	.uleb128 0x8	# (DIE (0xa9) DW_TAG_subprogram)
			# DW_AT_external
	.long	.LASF0	# DW_AT_name: "main"
	.byte	0x1	# DW_AT_decl_file (amd64-tailcall-self.c)
	.byte	0x14	# DW_AT_decl_line
			# DW_AT_prototyped
	.long	die6b - .Ldebug_info0	# DW_AT_type
	.quad	.LFB3	# DW_AT_low_pc
	.quad	.LFE3-.LFB3	# DW_AT_high_pc
	.uleb128 0x1	# DW_AT_frame_base
	.byte	0x9c	# DW_OP_call_frame_cfa
			# DW_AT_GNU_all_call_sites
	.uleb128 0x9	# (DIE (0xca) DW_TAG_formal_parameter)
	.long	.LASF1	# DW_AT_name: "argc"
	.byte	0x1	# DW_AT_decl_file (amd64-tailcall-self.c)
	.byte	0x14	# DW_AT_decl_line
	.long	die6b - .Ldebug_info0	# DW_AT_type
	.long	.LLST0	# DW_AT_location
	.uleb128 0x9	# (DIE (0xd9) DW_TAG_formal_parameter)
	.long	.LASF2	# DW_AT_name: "argv"
	.byte	0x1	# DW_AT_decl_file (amd64-tailcall-self.c)
	.byte	0x14	# DW_AT_decl_line
	.long	diefe - .Ldebug_info0	# DW_AT_type
	.long	.LLST1	# DW_AT_location
	.uleb128 0xa	# (DIE (0xe8) DW_TAG_GNU_call_site)
	.quad	.LVL4	# DW_AT_low_pc
	.long	die72 - .Ldebug_info0	# DW_AT_abstract_origin
	.uleb128 0xb	# (DIE (0xf5) DW_TAG_GNU_call_site_parameter)
	.uleb128 0x1	# DW_AT_location
	.byte	0x55	# DW_OP_reg5
	.uleb128 0x3	# DW_AT_GNU_call_site_value
	.byte	0xf3	# DW_OP_GNU_entry_value
	.uleb128 0x1
	.byte	0x55	# DW_OP_reg5
	.byte	0	# end of children of DIE 0xe8
	.byte	0	# end of children of DIE 0xa9
diefe:
	.uleb128 0xc	# (DIE (0xfe) DW_TAG_pointer_type)
	.byte	0x8	# DW_AT_byte_size
	.long	die104 - .Ldebug_info0	# DW_AT_type
die104:
	.uleb128 0xc	# (DIE (0x104) DW_TAG_pointer_type)
	.byte	0x8	# DW_AT_byte_size
	.long	die10a - .Ldebug_info0	# DW_AT_type
die10a:
	.uleb128 0xd	# (DIE (0x10a) DW_TAG_base_type)
	.byte	0x1	# DW_AT_byte_size
	.byte	0x6	# DW_AT_encoding
	.long	.LASF3	# DW_AT_name: "char"
	.uleb128 0xe	# (DIE (0x111) DW_TAG_variable)
	.ascii "i\0"	# DW_AT_name
	.byte	0x1	# DW_AT_decl_file (amd64-tailcall-self.c)
	.byte	0x5	# DW_AT_decl_line
	.long	die6b - .Ldebug_info0	# DW_AT_type
			# DW_AT_external
	.uleb128 0x9	# DW_AT_location
	.byte	0x3	# DW_OP_addr
	.quad	i
	.byte	0	# end of children of DIE 0xb
2:
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1	# (abbrev code)
	.uleb128 0x11	# (TAG: DW_TAG_compile_unit)
	.byte	0x1	# DW_children_yes
	.uleb128 0x25	# (DW_AT_producer)
	.uleb128 0xe	# (DW_FORM_strp)
	.uleb128 0x13	# (DW_AT_language)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x3	# (DW_AT_name)
	.uleb128 0xe	# (DW_FORM_strp)
	.uleb128 0x1b	# (DW_AT_comp_dir)
	.uleb128 0xe	# (DW_FORM_strp)
	.uleb128 0x55	# (DW_AT_ranges)
	.uleb128 0x17	# (DW_FORM_sec_offset)
	.uleb128 0x11	# (DW_AT_low_pc)
	.uleb128 0x1	# (DW_FORM_addr)
	.uleb128 0x10	# (DW_AT_stmt_list)
	.uleb128 0x17	# (DW_FORM_sec_offset)
	.byte	0
	.byte	0
	.uleb128 0x2	# (abbrev code)
	.uleb128 0x2e	# (TAG: DW_TAG_subprogram)
	.byte	0	# DW_children_no
	.uleb128 0x3	# (DW_AT_name)
	.uleb128 0x8	# (DW_FORM_string)
	.uleb128 0x3a	# (DW_AT_decl_file)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x3b	# (DW_AT_decl_line)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x27	# (DW_AT_prototyped)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.uleb128 0x11	# (DW_AT_low_pc)
	.uleb128 0x1	# (DW_FORM_addr)
	.uleb128 0x12	# (DW_AT_high_pc)
	.uleb128 0x7	# (DW_FORM_data8)
	.uleb128 0x40	# (DW_AT_frame_base)
	.uleb128 0x18	# (DW_FORM_exprloc)
	.uleb128 0x2117	# (DW_AT_GNU_all_call_sites)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.byte	0
	.byte	0
	.uleb128 0x3	# (abbrev code)
	.uleb128 0x2e	# (TAG: DW_TAG_subprogram)
	.byte	0x1	# DW_children_yes
	.uleb128 0x3f	# (DW_AT_external)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.uleb128 0x3	# (DW_AT_name)
	.uleb128 0x8	# (DW_FORM_string)
	.uleb128 0x3a	# (DW_AT_decl_file)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x3b	# (DW_AT_decl_line)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x27	# (DW_AT_prototyped)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.uleb128 0x49	# (DW_AT_type)
	.uleb128 0x13	# (DW_FORM_ref4)
	.uleb128 0x11	# (DW_AT_low_pc)
	.uleb128 0x1	# (DW_FORM_addr)
	.uleb128 0x12	# (DW_AT_high_pc)
	.uleb128 0x7	# (DW_FORM_data8)
	.uleb128 0x40	# (DW_AT_frame_base)
	.uleb128 0x18	# (DW_FORM_exprloc)
	.uleb128 0x2117	# (DW_AT_GNU_all_call_sites)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.byte	0
	.byte	0
	.uleb128 0x4	# (abbrev code)
	.uleb128 0x5	# (TAG: DW_TAG_formal_parameter)
	.byte	0	# DW_children_no
	.uleb128 0x3	# (DW_AT_name)
	.uleb128 0x8	# (DW_FORM_string)
	.uleb128 0x3a	# (DW_AT_decl_file)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x3b	# (DW_AT_decl_line)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x49	# (DW_AT_type)
	.uleb128 0x13	# (DW_FORM_ref4)
	.uleb128 0x2	# (DW_AT_location)
	.uleb128 0x18	# (DW_FORM_exprloc)
	.byte	0
	.byte	0
	.uleb128 0x5	# (abbrev code)
	.uleb128 0x24	# (TAG: DW_TAG_base_type)
	.byte	0	# DW_children_no
	.uleb128 0xb	# (DW_AT_byte_size)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x3e	# (DW_AT_encoding)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x3	# (DW_AT_name)
	.uleb128 0x8	# (DW_FORM_string)
	.byte	0
	.byte	0
	.uleb128 0x6	# (abbrev code)
	.uleb128 0x2e	# (TAG: DW_TAG_subprogram)
	.byte	0x1	# DW_children_yes
	.uleb128 0x3f	# (DW_AT_external)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.uleb128 0x3	# (DW_AT_name)
	.uleb128 0x8	# (DW_FORM_string)
	.uleb128 0x3a	# (DW_AT_decl_file)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x3b	# (DW_AT_decl_line)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x27	# (DW_AT_prototyped)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.uleb128 0x11	# (DW_AT_low_pc)
	.uleb128 0x1	# (DW_FORM_addr)
	.uleb128 0x12	# (DW_AT_high_pc)
	.uleb128 0x7	# (DW_FORM_data8)
	.uleb128 0x40	# (DW_AT_frame_base)
	.uleb128 0x18	# (DW_FORM_exprloc)
	.uleb128 0x2117	# (DW_AT_GNU_all_call_sites)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.byte	0
	.byte	0
	.uleb128 0x7	# (abbrev code)
	.uleb128 0x4109	# (TAG: DW_TAG_GNU_call_site)
	.byte	0	# DW_children_no
	.uleb128 0x11	# (DW_AT_low_pc)
	.uleb128 0x1	# (DW_FORM_addr)
	.uleb128 0x2115	# (DW_AT_GNU_tail_call)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.uleb128 0x31	# (DW_AT_abstract_origin)
	.uleb128 0x13	# (DW_FORM_ref4)
	.byte	0
	.byte	0
	.uleb128 0x8	# (abbrev code)
	.uleb128 0x2e	# (TAG: DW_TAG_subprogram)
	.byte	0x1	# DW_children_yes
	.uleb128 0x3f	# (DW_AT_external)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.uleb128 0x3	# (DW_AT_name)
	.uleb128 0xe	# (DW_FORM_strp)
	.uleb128 0x3a	# (DW_AT_decl_file)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x3b	# (DW_AT_decl_line)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x27	# (DW_AT_prototyped)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.uleb128 0x49	# (DW_AT_type)
	.uleb128 0x13	# (DW_FORM_ref4)
	.uleb128 0x11	# (DW_AT_low_pc)
	.uleb128 0x1	# (DW_FORM_addr)
	.uleb128 0x12	# (DW_AT_high_pc)
	.uleb128 0x7	# (DW_FORM_data8)
	.uleb128 0x40	# (DW_AT_frame_base)
	.uleb128 0x18	# (DW_FORM_exprloc)
	.uleb128 0x2117	# (DW_AT_GNU_all_call_sites)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.byte	0
	.byte	0
	.uleb128 0x9	# (abbrev code)
	.uleb128 0x5	# (TAG: DW_TAG_formal_parameter)
	.byte	0	# DW_children_no
	.uleb128 0x3	# (DW_AT_name)
	.uleb128 0xe	# (DW_FORM_strp)
	.uleb128 0x3a	# (DW_AT_decl_file)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x3b	# (DW_AT_decl_line)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x49	# (DW_AT_type)
	.uleb128 0x13	# (DW_FORM_ref4)
	.uleb128 0x2	# (DW_AT_location)
	.uleb128 0x17	# (DW_FORM_sec_offset)
	.byte	0
	.byte	0
	.uleb128 0xa	# (abbrev code)
	.uleb128 0x4109	# (TAG: DW_TAG_GNU_call_site)
	.byte	0x1	# DW_children_yes
	.uleb128 0x11	# (DW_AT_low_pc)
	.uleb128 0x1	# (DW_FORM_addr)
	.uleb128 0x31	# (DW_AT_abstract_origin)
	.uleb128 0x13	# (DW_FORM_ref4)
	.byte	0
	.byte	0
	.uleb128 0xb	# (abbrev code)
	.uleb128 0x410a	# (TAG: DW_TAG_GNU_call_site_parameter)
	.byte	0	# DW_children_no
	.uleb128 0x2	# (DW_AT_location)
	.uleb128 0x18	# (DW_FORM_exprloc)
	.uleb128 0x2111	# (DW_AT_GNU_call_site_value)
	.uleb128 0x18	# (DW_FORM_exprloc)
	.byte	0
	.byte	0
	.uleb128 0xc	# (abbrev code)
	.uleb128 0xf	# (TAG: DW_TAG_pointer_type)
	.byte	0	# DW_children_no
	.uleb128 0xb	# (DW_AT_byte_size)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x49	# (DW_AT_type)
	.uleb128 0x13	# (DW_FORM_ref4)
	.byte	0
	.byte	0
	.uleb128 0xd	# (abbrev code)
	.uleb128 0x24	# (TAG: DW_TAG_base_type)
	.byte	0	# DW_children_no
	.uleb128 0xb	# (DW_AT_byte_size)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x3e	# (DW_AT_encoding)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x3	# (DW_AT_name)
	.uleb128 0xe	# (DW_FORM_strp)
	.byte	0
	.byte	0
	.uleb128 0xe	# (abbrev code)
	.uleb128 0x34	# (TAG: DW_TAG_variable)
	.byte	0	# DW_children_no
	.uleb128 0x3	# (DW_AT_name)
	.uleb128 0x8	# (DW_FORM_string)
	.uleb128 0x3a	# (DW_AT_decl_file)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x3b	# (DW_AT_decl_line)
	.uleb128 0xb	# (DW_FORM_data1)
	.uleb128 0x49	# (DW_AT_type)
	.uleb128 0x13	# (DW_FORM_ref4)
	.uleb128 0x3f	# (DW_AT_external)
	.uleb128 0x19	# (DW_FORM_flag_present)
	.uleb128 0x2	# (DW_AT_location)
	.uleb128 0x18	# (DW_FORM_exprloc)
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST0:
	.quad	.LVL3	# Location list begin address (*.LLST0)
	.quad	.LVL4-1	# Location list end address (*.LLST0)
	.value	0x1	# Location expression size
	.byte	0x55	# DW_OP_reg5
	.quad	.LVL4-1	# Location list begin address (*.LLST0)
	.quad	.LFE3	# Location list end address (*.LLST0)
	.value	0x4	# Location expression size
	.byte	0xf3	# DW_OP_GNU_entry_value
	.uleb128 0x1
	.byte	0x55	# DW_OP_reg5
	.byte	0x9f	# DW_OP_stack_value
	.quad	0	# Location list terminator begin (*.LLST0)
	.quad	0	# Location list terminator end (*.LLST0)
.LLST1:
	.quad	.LVL3	# Location list begin address (*.LLST1)
	.quad	.LVL4-1	# Location list end address (*.LLST1)
	.value	0x1	# Location expression size
	.byte	0x54	# DW_OP_reg4
	.quad	.LVL4-1	# Location list begin address (*.LLST1)
	.quad	.LFE3	# Location list end address (*.LLST1)
	.value	0x4	# Location expression size
	.byte	0xf3	# DW_OP_GNU_entry_value
	.uleb128 0x1
	.byte	0x54	# DW_OP_reg4
	.byte	0x9f	# DW_OP_stack_value
	.quad	0	# Location list terminator begin (*.LLST1)
	.quad	0	# Location list terminator end (*.LLST1)
	.section	.debug_aranges,"",@progbits
	.long	0x3c	# Length of Address Ranges Info
	.value	0x2	# DWARF Version
	.long	.Ldebug_info0	# Offset of Compilation Unit Info
	.byte	0x8	# Size of Address
	.byte	0	# Size of Segment Descriptor
	.value	0	# Pad to 16 byte boundary
	.value	0
	.quad	.Ltext0	# Address
	.quad	.Letext0-.Ltext0	# Length
	.quad	.LFB3	# Address
	.quad	.LFE3-.LFB3	# Length
	.quad	0
	.quad	0
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.quad	.Ltext0	# Offset 0
	.quad	.Letext0
	.quad	.LFB3	# Offset 0x10
	.quad	.LFE3
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF1:
	.string	"argc"
.LASF0:
	.string	"main"
.LASF4:
	.string	"GNU C 4.9.2 20150212 (Red Hat 4.9.2-6) -mtune=generic -march=x86-64 -g -Os"
.LASF5:
	.string	"amd64-tailcall-self.c"
.LASF6:
	.string	""
.LASF3:
	.string	"char"
.LASF2:
	.string	"argv"
	.ident	"GCC: (GNU) 4.9.2 20150212 (Red Hat 4.9.2-6)"
	.section	.note.GNU-stack,"",@progbits
