/* Blackfin NAND Flash Memory Controller (NFC) model

   Copyright (C) 2010-2025 Free Software Foundation, Inc.
   Contributed by Analog Devices, Inc.

   This file is part of simulators.

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

/* This must come before any other includes.  */
#include "defs.h"

#include "sim-main.h"
#include "devices.h"
#include "dv-bfin_nfc.h"

/* XXX: This is merely a stub.  */

struct bfin_nfc
{
  /* This top portion matches common dv_bfin struct.  */
  bu32 base;
  struct hw *dma_master;
  bool acked;

  struct hw_event *handler;
  char saved_byte;
  int saved_count;

  /* Order after here is important -- matches hardware MMR layout.  */
  bu16 BFIN_MMR_16(ctl);
  bu16 BFIN_MMR_16(stat);
  bu16 BFIN_MMR_16(irqstat);
  bu16 BFIN_MMR_16(irqmask);
  bu16 BFIN_MMR_16(ecc0);
  bu16 BFIN_MMR_16(ecc1);
  bu16 BFIN_MMR_16(ecc2);
  bu16 BFIN_MMR_16(ecc3);
  bu16 BFIN_MMR_16(count);
  bu16 BFIN_MMR_16(rst);
  bu16 BFIN_MMR_16(pgctl);
  bu16 BFIN_MMR_16(read);
  bu32 _pad0[4];
  bu16 BFIN_MMR_16(addr);
  bu16 BFIN_MMR_16(cmd);
  bu16 BFIN_MMR_16(data_wr);
  bu16 BFIN_MMR_16(data_rd);
};
#define mmr_base()      offsetof(struct bfin_nfc, ctl)
#define mmr_offset(mmr) (offsetof(struct bfin_nfc, mmr) - mmr_base())
#define mmr_idx(mmr)    (mmr_offset (mmr) / 4)

static const char * const mmr_names[] =
{
  "NFC_CTL", "NFC_STAT", "NFC_IRQSTAT", "NFC_IRQMASK", "NFC_ECC0", "NFC_ECC1",
  "NFC_ECC2", "NFC_ECC3", "NFC_COUNT", "NFC_RST", "NFC_PGCTL", "NFC_READ",
  [mmr_idx (addr)] = "NFC_ADDR", "NFC_CMD", "NFC_DATA_WR", "NFC_DATA_RD",
};
#define mmr_name(off) (mmr_names[(off) / 4] ? : "<INV>")

static unsigned
bfin_nfc_io_write_buffer (struct hw *me, const void *source, int space,
			  address_word addr, unsigned nr_bytes)
{
  struct bfin_nfc *nfc = hw_data (me);
  bu32 mmr_off;
  bu32 value;
  bu16 *valuep;

  /* Invalid access mode is higher priority than missing register.  */
  if (!dv_bfin_mmr_require_16 (me, addr, nr_bytes, true))
    return 0;

  value = dv_load_2 (source);
  mmr_off = addr - nfc->base;
  valuep = (void *)((uintptr_t)nfc + mmr_base() + mmr_off);

  HW_TRACE_WRITE ();

  switch (mmr_off)
    {
    case mmr_offset(ctl):
    case mmr_offset(stat):
    case mmr_offset(irqmask):
    case mmr_offset(ecc0):
    case mmr_offset(ecc1):
    case mmr_offset(ecc2):
    case mmr_offset(ecc3):
    case mmr_offset(count):
    case mmr_offset(rst):
    case mmr_offset(pgctl):
    case mmr_offset(read):
    case mmr_offset(addr):
    case mmr_offset(cmd):
    case mmr_offset(data_wr):
      *valuep = value;
      break;
    case mmr_offset(data_rd):
      nfc->irqstat |= RD_RDY;
      *valuep = value;
      break;
    case mmr_offset(irqstat):
      dv_w1c_2 (valuep, value, -1);
      break;
    default:
      dv_bfin_mmr_invalid (me, addr, nr_bytes, true);
      return 0;
    }

  return nr_bytes;
}

static unsigned
bfin_nfc_io_read_buffer (struct hw *me, void *dest, int space,
			 address_word addr, unsigned nr_bytes)
{
  struct bfin_nfc *nfc = hw_data (me);
  bu32 mmr_off;
  bu16 *valuep;

  /* Invalid access mode is higher priority than missing register.  */
  if (!dv_bfin_mmr_require_16 (me, addr, nr_bytes, false))
    return 0;

  mmr_off = addr - nfc->base;
  valuep = (void *)((uintptr_t)nfc + mmr_base() + mmr_off);

  HW_TRACE_READ ();

  switch (mmr_off)
    {
    case mmr_offset(ctl):
    case mmr_offset(stat):
    case mmr_offset(irqstat):
    case mmr_offset(irqmask):
    case mmr_offset(ecc0):
    case mmr_offset(ecc1):
    case mmr_offset(ecc2):
    case mmr_offset(ecc3):
    case mmr_offset(count):
    case mmr_offset(rst):
    case mmr_offset(read):
      dv_store_2 (dest, *valuep);
      break;
    case mmr_offset(pgctl):
    case mmr_offset(addr):
    case mmr_offset(cmd):
    case mmr_offset(data_wr):
    case mmr_offset(data_rd):
      /* These regs are write only.  */
    default:
      dv_bfin_mmr_invalid (me, addr, nr_bytes, false);
      return 0;
    }

  return nr_bytes;
}

static unsigned
bfin_nfc_dma_read_buffer (struct hw *me, void *dest, int space,
			  unsigned_word addr, unsigned nr_bytes)
{
  HW_TRACE_DMA_READ ();
  return 0;
}

static unsigned
bfin_nfc_dma_write_buffer (struct hw *me, const void *source,
			   int space, unsigned_word addr,
			   unsigned nr_bytes,
			   int violate_read_only_section)
{
  HW_TRACE_DMA_WRITE ();
  return nr_bytes;
}

static const struct hw_port_descriptor bfin_nfc_ports[] =
{
  { "stat", 0, 0, output_port, },
  { NULL, 0, 0, 0, },
};

static void
attach_bfin_nfc_regs (struct hw *me, struct bfin_nfc *nfc)
{
  address_word attach_address;
  int attach_space;
  unsigned attach_size;
  reg_property_spec reg;

  if (hw_find_property (me, "reg") == NULL)
    hw_abort (me, "Missing \"reg\" property");

  if (!hw_find_reg_array_property (me, "reg", 0, &reg))
    hw_abort (me, "\"reg\" property must contain three addr/size entries");

  hw_unit_address_to_attach_address (hw_parent (me),
				     &reg.address,
				     &attach_space, &attach_address, me);
  hw_unit_size_to_attach_size (hw_parent (me), &reg.size, &attach_size, me);

  if (attach_size != BFIN_MMR_NFC_SIZE)
    hw_abort (me, "\"reg\" size must be %#x", BFIN_MMR_NFC_SIZE);

  hw_attach_address (hw_parent (me),
		     0, attach_space, attach_address, attach_size, me);

  nfc->base = attach_address;
}

static void
bfin_nfc_finish (struct hw *me)
{
  struct bfin_nfc *nfc;

  nfc = HW_ZALLOC (me, struct bfin_nfc);

  set_hw_data (me, nfc);
  set_hw_io_read_buffer (me, bfin_nfc_io_read_buffer);
  set_hw_io_write_buffer (me, bfin_nfc_io_write_buffer);
  set_hw_dma_read_buffer (me, bfin_nfc_dma_read_buffer);
  set_hw_dma_write_buffer (me, bfin_nfc_dma_write_buffer);
  set_hw_ports (me, bfin_nfc_ports);

  attach_bfin_nfc_regs (me, nfc);

  /* Initialize the NFC.  */
  nfc->ctl     = 0x0200;
  nfc->stat    = 0x0011;
  nfc->irqstat = 0x0004;
  nfc->irqmask = 0x001F;
}

const struct hw_descriptor dv_bfin_nfc_descriptor[] =
{
  {"bfin_nfc", bfin_nfc_finish,},
  {NULL, NULL},
};
