/* Copyright (C) 2019-2025 Free Software Foundation, Inc.

   This file is part of GDB.

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

#ifndef GDB_AARCH32_TDEP_H
#define GDB_AARCH32_TDEP_H

struct target_desc;

/* Get the AArch32 target description.  */

const target_desc *aarch32_read_description (bool tls);

#endif /* GDB_AARCH32_TDEP_H */
