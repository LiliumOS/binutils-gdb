/* Include file for stabs debugging format support functions.
   Copyright (C) 1986-2025 Free Software Foundation, Inc.

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

#ifndef GDB_STABSREAD_H
#define GDB_STABSREAD_H

struct objfile;
struct legacy_psymtab;
enum language;

/* Definitions, prototypes, etc for stabs debugging format support
   functions.  */

#define HASHSIZE 127		/* Size of things hashed via
				   hashname().  */

/* Compute a small integer hash code for the given name.  */

extern int hashname (const char *name);

/* Count symbols as they are processed, for error messages.  */

extern unsigned int symnum;

#define next_symbol_text(objfile) (*next_symbol_text_func)(objfile)

/* Function to invoke get the next symbol.  Return the symbol name.  */

extern const char *(*next_symbol_text_func) (struct objfile *);

/* Global variable which, when set, indicates that we are processing a
   .o file compiled with gcc */

extern unsigned char processing_gcc_compilation;

/* Nonzero if within a function (so symbols should be local, if
   nothing says specifically).  */

extern int within_function;

/* Hash table of global symbols whose values are not known yet.
   They are chained through the SYMBOL_VALUE_CHAIN, since we don't
   have the correct data for that slot yet.

   The use of the LOC_BLOCK code in this chain is nonstandard--
   it refers to a FORTRAN common block rather than the usual meaning, and
   the such LOC_BLOCK symbols use their fields in nonstandard ways.  */

extern struct symbol *global_sym_chain[HASHSIZE];

extern void common_block_start (const char *, struct objfile *);
extern void common_block_end (struct objfile *);

/* Kludge for xcoffread.c */

struct pending_stabs
  {
    int count;
    int length;
    char *stab[1];
  };

extern struct pending_stabs *global_stabs;

/* The type code that process_one_symbol saw on its previous invocation.
   Used to detect pairs of N_SO symbols.  */

extern int previous_stab_code;

/* Support for Sun changes to dbx symbol format.  */

/* For each identified header file, we have a table of types defined
   in that header file.

   header_files maps header file names to their type tables.
   It is a vector of n_header_files elements.
   Each element describes one header file.
   It contains a vector of types.

   Sometimes it can happen that the same header file produces
   different results when included in different places.
   This can result from conditionals or from different
   things done before including the file.
   When this happens, there are multiple entries for the file in this table,
   one entry for each distinct set of results.
   The entries are distinguished by the INSTANCE field.
   The INSTANCE field appears in the N_BINCL and N_EXCL symbol table and is
   used to match header-file references to their corresponding data.  */

struct header_file
  {

    /* Name of header file */

    char *name;

    /* Numeric code distinguishing instances of one header file that
       produced different results when included.  It comes from the
       N_BINCL or N_EXCL.  */

    int instance;

    /* Pointer to vector of types */

    struct type **vector;

    /* Allocated length (# elts) of that vector */

    int length;

  };

/* The table of header_files of this OBJFILE.  */
#define HEADER_FILES(OBJFILE) (DBX_SYMFILE_INFO (OBJFILE)->header_files)

/* The actual length of HEADER_FILES.  */
#define N_HEADER_FILES(OBJFILE) (DBX_SYMFILE_INFO (OBJFILE)->n_header_files)

/* The allocated length of HEADER_FILES.  */
#define N_ALLOCATED_HEADER_FILES(OBJFILE) \
  (DBX_SYMFILE_INFO (OBJFILE)->n_allocated_header_files)

/* Within each object file, various header files are assigned numbers.
   A type is defined or referred to with a pair of numbers
   (FILENUM,TYPENUM) where FILENUM is the number of the header file
   and TYPENUM is the number within that header file.
   TYPENUM is the index within the vector of types for that header file.

   FILENUM == 0 is special; it refers to the main source of the object file,
   and not to any header file.  FILENUM != 1 is interpreted by looking it up
   in the following table, which contains indices in header_files.  */

extern int *this_object_header_files;

extern int n_this_object_header_files;

extern int n_allocated_this_object_header_files;

extern void cleanup_undefined_stabs_types (struct objfile *);

extern long read_number (char **, int);

extern struct symbol *define_symbol (CORE_ADDR, const char *, int, int,
				     struct objfile *);

extern void stabsread_init (void);

extern void stabsread_new_init (void);

extern void start_stabs (void);

extern void end_stabs (void);

extern void finish_global_stabs (struct objfile *objfile);

class psymtab_storage;

/* Functions exported by dbxread.c.  These are not in stabsread.c because
   they are only used by some stabs readers.  */

extern legacy_psymtab *stabs_end_psymtab
  (struct objfile *objfile, psymtab_storage *partial_symtabs,
   legacy_psymtab *pst,
   const char **include_list, int num_includes,
   int capping_symbol_offset, unrelocated_addr capping_text,
   legacy_psymtab **dependency_list, int number_dependencies,
   int textlow_not_set);

extern void process_one_symbol (int, int, CORE_ADDR, const char *,
				const section_offsets &,
				struct objfile *, enum language);

/* Setup partial_symtab's describing each source file for which
   debugging information is available.  */

void
read_stabs_symtab (struct objfile *, symfile_add_flags);

extern void elfstab_build_psymtabs (struct objfile *objfile,
				    asection *stabsect,
				    file_ptr stabstroffset,
				    unsigned int stabstrsize);

extern void coffstab_build_psymtabs
  (struct objfile *objfile,
   CORE_ADDR textaddr, unsigned int textsize,
   const std::vector<asection *> &stabs,
   file_ptr stabstroffset, unsigned int stabstrsize);

extern int symbol_reference_defined (const char **);

extern void ref_add (int, struct symbol *, const char *, CORE_ADDR);

extern struct symbol *ref_search (int);

extern void free_header_files (void);

extern void init_header_files (void);

/* Scan through all of the global symbols defined in the object file,
   assigning values to the debugging symbols that need to be assigned
   to.  Get these symbols from the minimal symbol table.  */

extern void scan_file_globals (struct objfile *objfile);

/* Complaints about the symbols we have encountered.  */

void
unknown_symtype_complaint (const char *);

void
lbrac_mismatch_complaint (int);

void
repeated_header_complaint (const char *, int);

bound_minimal_symbol
find_stab_function (const char *, const char *, struct objfile *);

/* This handles a single symbol from the symbol-file, building symbols
   into a GDB symtab.  It takes these arguments and an implicit argument.

   TYPE is the type field of the ".stab" symbol entry.
   DESC is the desc field of the ".stab" entry.
   VALU is the value field of the ".stab" entry.
   NAME is the symbol name, in our address space.
   SECTION_OFFSETS is a set of amounts by which the sections of this
   object file were relocated when it was loaded into memory.  Note
   that these section_offsets are not the objfile->section_offsets but
   the pst->section_offsets.  All symbols that refer to memory
   locations need to be offset by these amounts.
   OBJFILE is the object file from which we are reading symbols.  It
   is used in end_compunit_symtab.
   LANGUAGE is the language of the symtab.
*/

void
process_one_symbol (int, int, CORE_ADDR, const char *,
		    const section_offsets &,
		    struct objfile *, enum language);

#define LDSYMOFF(p) (((struct symloc *)((p)->read_symtab_private))->ldsymoff)
#define LDSYMLEN(p) (((struct symloc *)((p)->read_symtab_private))->ldsymlen)
#define SYMLOC(p) ((struct symloc *)((p)->read_symtab_private))
#define SYMBOL_SIZE(p) (SYMLOC(p)->symbol_size)
#define SYMBOL_OFFSET(p) (SYMLOC(p)->symbol_offset)
#define STRING_OFFSET(p) (SYMLOC(p)->string_offset)
#define FILE_STRING_OFFSET(p) (SYMLOC(p)->file_string_offset)
#define PST_LANGUAGE(p) (SYMLOC(p)->pst_language)

#define INTERNALIZE_SYMBOL(intern, extern, abfd)			\
  {									\
    (intern).n_strx = bfd_h_get_32 (abfd, (extern)->e_strx);		\
    (intern).n_type = bfd_h_get_8 (abfd, (extern)->e_type);		\
    (intern).n_other = 0;						\
    (intern).n_desc = bfd_h_get_16 (abfd, (extern)->e_desc);  		\
    if (bfd_get_sign_extend_vma (abfd))					\
      (intern).n_value = bfd_h_get_signed_32 (abfd, (extern)->e_value);	\
    else								\
      (intern).n_value = bfd_h_get_32 (abfd, (extern)->e_value);	\
  }

/* We put a pointer to this structure in the read_symtab_private field
   of the psymtab.  */

struct symloc
  {
    /* Offset within the file symbol table of first local symbol for this
       file.  */

    int ldsymoff;

    /* Length (in bytes) of the section of the symbol table devoted to
       this file's symbols (actually, the section bracketed may contain
       more than just this file's symbols).  If ldsymlen is 0, the only
       reason for this thing's existence is the dependency list.  Nothing
       else will happen when it is read in.  */

    int ldsymlen;

    /* The size of each symbol in the symbol file (in external form).  */

    int symbol_size;

    /* Further information needed to locate the symbols if they are in
       an ELF file.  */

    int symbol_offset;
    int string_offset;
    int file_string_offset;
    enum language pst_language;
  };

static inline void
stabs_deprecated_warning ()
{
  warning (_("Stabs support is deprecated and will be removed soon."));
}
#endif /* GDB_STABSREAD_H */
