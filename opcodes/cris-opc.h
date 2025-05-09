/* Instruction opcode header for cris.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 1996-2025 Free Software Foundation, Inc.

This file is part of the GNU Binutils and/or GDB, the GNU debugger.

   This file is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.

*/

#ifndef CRIS_OPC_H
#define CRIS_OPC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Enum declaration for cris instruction types.  */
typedef enum cgen_insn_type {
  CRIS_INSN_INVALID, CRIS_INSN_NOP, CRIS_INSN_MOVE_B_R, CRIS_INSN_MOVE_W_R
 , CRIS_INSN_MOVE_D_R, CRIS_INSN_MOVEPCR, CRIS_INSN_MOVEQ, CRIS_INSN_MOVS_B_R
 , CRIS_INSN_MOVS_W_R, CRIS_INSN_MOVU_B_R, CRIS_INSN_MOVU_W_R, CRIS_INSN_MOVECBR
 , CRIS_INSN_MOVECWR, CRIS_INSN_MOVECDR, CRIS_INSN_MOVSCBR, CRIS_INSN_MOVSCWR
 , CRIS_INSN_MOVUCBR, CRIS_INSN_MOVUCWR, CRIS_INSN_ADDQ, CRIS_INSN_SUBQ
 , CRIS_INSN_CMP_R_B_R, CRIS_INSN_CMP_R_W_R, CRIS_INSN_CMP_R_D_R, CRIS_INSN_CMP_M_B_M
 , CRIS_INSN_CMP_M_W_M, CRIS_INSN_CMP_M_D_M, CRIS_INSN_CMPCBR, CRIS_INSN_CMPCWR
 , CRIS_INSN_CMPCDR, CRIS_INSN_CMPQ, CRIS_INSN_CMPS_M_B_M, CRIS_INSN_CMPS_M_W_M
 , CRIS_INSN_CMPSCBR, CRIS_INSN_CMPSCWR, CRIS_INSN_CMPU_M_B_M, CRIS_INSN_CMPU_M_W_M
 , CRIS_INSN_CMPUCBR, CRIS_INSN_CMPUCWR, CRIS_INSN_MOVE_M_B_M, CRIS_INSN_MOVE_M_W_M
 , CRIS_INSN_MOVE_M_D_M, CRIS_INSN_MOVS_M_B_M, CRIS_INSN_MOVS_M_W_M, CRIS_INSN_MOVU_M_B_M
 , CRIS_INSN_MOVU_M_W_M, CRIS_INSN_MOVE_R_SPRV0, CRIS_INSN_MOVE_R_SPRV3, CRIS_INSN_MOVE_R_SPRV8
 , CRIS_INSN_MOVE_R_SPRV10, CRIS_INSN_MOVE_R_SPRV32, CRIS_INSN_MOVE_SPR_RV0, CRIS_INSN_MOVE_SPR_RV3
 , CRIS_INSN_MOVE_SPR_RV8, CRIS_INSN_MOVE_SPR_RV10, CRIS_INSN_MOVE_SPR_RV32, CRIS_INSN_RET_TYPE
 , CRIS_INSN_MOVE_M_SPRV0, CRIS_INSN_MOVE_M_SPRV3, CRIS_INSN_MOVE_M_SPRV8, CRIS_INSN_MOVE_M_SPRV10
 , CRIS_INSN_MOVE_M_SPRV32, CRIS_INSN_MOVE_C_SPRV0_P5, CRIS_INSN_MOVE_C_SPRV0_P9, CRIS_INSN_MOVE_C_SPRV0_P10
 , CRIS_INSN_MOVE_C_SPRV0_P11, CRIS_INSN_MOVE_C_SPRV0_P12, CRIS_INSN_MOVE_C_SPRV0_P13, CRIS_INSN_MOVE_C_SPRV0_P6
 , CRIS_INSN_MOVE_C_SPRV0_P7, CRIS_INSN_MOVE_C_SPRV3_P5, CRIS_INSN_MOVE_C_SPRV3_P9, CRIS_INSN_MOVE_C_SPRV3_P10
 , CRIS_INSN_MOVE_C_SPRV3_P11, CRIS_INSN_MOVE_C_SPRV3_P12, CRIS_INSN_MOVE_C_SPRV3_P13, CRIS_INSN_MOVE_C_SPRV3_P6
 , CRIS_INSN_MOVE_C_SPRV3_P7, CRIS_INSN_MOVE_C_SPRV3_P14, CRIS_INSN_MOVE_C_SPRV8_P5, CRIS_INSN_MOVE_C_SPRV8_P9
 , CRIS_INSN_MOVE_C_SPRV8_P10, CRIS_INSN_MOVE_C_SPRV8_P11, CRIS_INSN_MOVE_C_SPRV8_P12, CRIS_INSN_MOVE_C_SPRV8_P13
 , CRIS_INSN_MOVE_C_SPRV8_P14, CRIS_INSN_MOVE_C_SPRV10_P5, CRIS_INSN_MOVE_C_SPRV10_P9, CRIS_INSN_MOVE_C_SPRV10_P10
 , CRIS_INSN_MOVE_C_SPRV10_P11, CRIS_INSN_MOVE_C_SPRV10_P12, CRIS_INSN_MOVE_C_SPRV10_P13, CRIS_INSN_MOVE_C_SPRV10_P7
 , CRIS_INSN_MOVE_C_SPRV10_P14, CRIS_INSN_MOVE_C_SPRV10_P15, CRIS_INSN_MOVE_C_SPRV32_P2, CRIS_INSN_MOVE_C_SPRV32_P3
 , CRIS_INSN_MOVE_C_SPRV32_P5, CRIS_INSN_MOVE_C_SPRV32_P6, CRIS_INSN_MOVE_C_SPRV32_P7, CRIS_INSN_MOVE_C_SPRV32_P9
 , CRIS_INSN_MOVE_C_SPRV32_P10, CRIS_INSN_MOVE_C_SPRV32_P11, CRIS_INSN_MOVE_C_SPRV32_P12, CRIS_INSN_MOVE_C_SPRV32_P13
 , CRIS_INSN_MOVE_C_SPRV32_P14, CRIS_INSN_MOVE_C_SPRV32_P15, CRIS_INSN_MOVE_SPR_MV0, CRIS_INSN_MOVE_SPR_MV3
 , CRIS_INSN_MOVE_SPR_MV8, CRIS_INSN_MOVE_SPR_MV10, CRIS_INSN_MOVE_SPR_MV32, CRIS_INSN_SBFS
 , CRIS_INSN_MOVE_SS_R, CRIS_INSN_MOVE_R_SS, CRIS_INSN_MOVEM_R_M, CRIS_INSN_MOVEM_R_M_V32
 , CRIS_INSN_MOVEM_M_R, CRIS_INSN_MOVEM_M_PC, CRIS_INSN_MOVEM_M_R_V32, CRIS_INSN_ADD_B_R
 , CRIS_INSN_ADD_W_R, CRIS_INSN_ADD_D_R, CRIS_INSN_ADD_M_B_M, CRIS_INSN_ADD_M_W_M
 , CRIS_INSN_ADD_M_D_M, CRIS_INSN_ADDCBR, CRIS_INSN_ADDCWR, CRIS_INSN_ADDCDR
 , CRIS_INSN_ADDCPC, CRIS_INSN_ADDS_B_R, CRIS_INSN_ADDS_W_R, CRIS_INSN_ADDS_M_B_M
 , CRIS_INSN_ADDS_M_W_M, CRIS_INSN_ADDSCBR, CRIS_INSN_ADDSCWR, CRIS_INSN_ADDSPCPC
 , CRIS_INSN_ADDU_B_R, CRIS_INSN_ADDU_W_R, CRIS_INSN_ADDU_M_B_M, CRIS_INSN_ADDU_M_W_M
 , CRIS_INSN_ADDUCBR, CRIS_INSN_ADDUCWR, CRIS_INSN_SUB_B_R, CRIS_INSN_SUB_W_R
 , CRIS_INSN_SUB_D_R, CRIS_INSN_SUB_M_B_M, CRIS_INSN_SUB_M_W_M, CRIS_INSN_SUB_M_D_M
 , CRIS_INSN_SUBCBR, CRIS_INSN_SUBCWR, CRIS_INSN_SUBCDR, CRIS_INSN_SUBS_B_R
 , CRIS_INSN_SUBS_W_R, CRIS_INSN_SUBS_M_B_M, CRIS_INSN_SUBS_M_W_M, CRIS_INSN_SUBSCBR
 , CRIS_INSN_SUBSCWR, CRIS_INSN_SUBU_B_R, CRIS_INSN_SUBU_W_R, CRIS_INSN_SUBU_M_B_M
 , CRIS_INSN_SUBU_M_W_M, CRIS_INSN_SUBUCBR, CRIS_INSN_SUBUCWR, CRIS_INSN_ADDC_R
 , CRIS_INSN_ADDC_M, CRIS_INSN_ADDC_C, CRIS_INSN_LAPC_D, CRIS_INSN_LAPCQ
 , CRIS_INSN_ADDI_B_R, CRIS_INSN_ADDI_W_R, CRIS_INSN_ADDI_D_R, CRIS_INSN_NEG_B_R
 , CRIS_INSN_NEG_W_R, CRIS_INSN_NEG_D_R, CRIS_INSN_TEST_M_B_M, CRIS_INSN_TEST_M_W_M
 , CRIS_INSN_TEST_M_D_M, CRIS_INSN_MOVE_R_M_B_M, CRIS_INSN_MOVE_R_M_W_M, CRIS_INSN_MOVE_R_M_D_M
 , CRIS_INSN_MULS_B, CRIS_INSN_MULS_W, CRIS_INSN_MULS_D, CRIS_INSN_MULU_B
 , CRIS_INSN_MULU_W, CRIS_INSN_MULU_D, CRIS_INSN_MCP, CRIS_INSN_MSTEP
 , CRIS_INSN_DSTEP, CRIS_INSN_ABS, CRIS_INSN_AND_B_R, CRIS_INSN_AND_W_R
 , CRIS_INSN_AND_D_R, CRIS_INSN_AND_M_B_M, CRIS_INSN_AND_M_W_M, CRIS_INSN_AND_M_D_M
 , CRIS_INSN_ANDCBR, CRIS_INSN_ANDCWR, CRIS_INSN_ANDCDR, CRIS_INSN_ANDQ
 , CRIS_INSN_ORR_B_R, CRIS_INSN_ORR_W_R, CRIS_INSN_ORR_D_R, CRIS_INSN_OR_M_B_M
 , CRIS_INSN_OR_M_W_M, CRIS_INSN_OR_M_D_M, CRIS_INSN_ORCBR, CRIS_INSN_ORCWR
 , CRIS_INSN_ORCDR, CRIS_INSN_ORQ, CRIS_INSN_XOR, CRIS_INSN_NOT
 , CRIS_INSN_SWAP, CRIS_INSN_ASRR_B_R, CRIS_INSN_ASRR_W_R, CRIS_INSN_ASRR_D_R
 , CRIS_INSN_ASRQ, CRIS_INSN_LSRR_B_R, CRIS_INSN_LSRR_W_R, CRIS_INSN_LSRR_D_R
 , CRIS_INSN_LSRQ, CRIS_INSN_LSLR_B_R, CRIS_INSN_LSLR_W_R, CRIS_INSN_LSLR_D_R
 , CRIS_INSN_LSLQ, CRIS_INSN_BTST, CRIS_INSN_BTSTQ, CRIS_INSN_SETF
 , CRIS_INSN_CLEARF, CRIS_INSN_RFE, CRIS_INSN_SFE, CRIS_INSN_RFG
 , CRIS_INSN_RFN, CRIS_INSN_HALT, CRIS_INSN_BCC_B, CRIS_INSN_BA_B
 , CRIS_INSN_BCC_W, CRIS_INSN_BA_W, CRIS_INSN_JAS_R, CRIS_INSN_JUMP_R
 , CRIS_INSN_JAS_C, CRIS_INSN_JUMP_M, CRIS_INSN_JUMP_C, CRIS_INSN_JUMP_P
 , CRIS_INSN_BAS_C, CRIS_INSN_JASC_R, CRIS_INSN_JASC_C, CRIS_INSN_BASC_C
 , CRIS_INSN_BREAK, CRIS_INSN_BOUND_R_B_R, CRIS_INSN_BOUND_R_W_R, CRIS_INSN_BOUND_R_D_R
 , CRIS_INSN_BOUND_M_B_M, CRIS_INSN_BOUND_M_W_M, CRIS_INSN_BOUND_M_D_M, CRIS_INSN_BOUND_CB
 , CRIS_INSN_BOUND_CW, CRIS_INSN_BOUND_CD, CRIS_INSN_SCC, CRIS_INSN_LZ
 , CRIS_INSN_ADDOQ, CRIS_INSN_BDAPQPC, CRIS_INSN_BDAP_32_PC, CRIS_INSN_MOVE_M_PCPLUS_P0
 , CRIS_INSN_MOVE_M_SPPLUS_P8, CRIS_INSN_ADDO_M_B_M, CRIS_INSN_ADDO_M_W_M, CRIS_INSN_ADDO_M_D_M
 , CRIS_INSN_ADDO_CB, CRIS_INSN_ADDO_CW, CRIS_INSN_ADDO_CD, CRIS_INSN_DIP_M
 , CRIS_INSN_DIP_C, CRIS_INSN_ADDI_ACR_B_R, CRIS_INSN_ADDI_ACR_W_R, CRIS_INSN_ADDI_ACR_D_R
 , CRIS_INSN_BIAP_PC_B_R, CRIS_INSN_BIAP_PC_W_R, CRIS_INSN_BIAP_PC_D_R, CRIS_INSN_FIDXI
 , CRIS_INSN_FTAGI, CRIS_INSN_FIDXD, CRIS_INSN_FTAGD
} CGEN_INSN_TYPE;

/* Index of `invalid' insn place holder.  */
#define CGEN_INSN_INVALID CRIS_INSN_INVALID

/* Total number of insns in table.  */
#define MAX_INSNS ((int) CRIS_INSN_FTAGD + 1)

/* This struct records data prior to insertion or after extraction.  */
struct cgen_fields
{
  int length;
  long f_nil;
  long f_anyof;
  long f_operand1;
  long f_size;
  long f_opcode;
  long f_mode;
  long f_operand2;
  long f_memmode;
  long f_membit;
  long f_b5;
  long f_opcode_hi;
  long f_dstsrc;
  long f_u6;
  long f_s6;
  long f_u5;
  long f_u4;
  long f_s8;
  long f_disp9_hi;
  long f_disp9_lo;
  long f_disp9;
  long f_qo;
  long f_indir_pc__byte;
  long f_indir_pc__word;
  long f_indir_pc__word_pcrel;
  long f_indir_pc__dword;
  long f_indir_pc__dword_pcrel;
};

#define CGEN_INIT_PARSE(od) \
{\
}
#define CGEN_INIT_INSERT(od) \
{\
}
#define CGEN_INIT_EXTRACT(od) \
{\
}
#define CGEN_INIT_PRINT(od) \
{\
}


   #ifdef __cplusplus
   }
   #endif

#endif /* CRIS_OPC_H */
