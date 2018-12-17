/* Verify that -mno-const-data-in-progmem places and reads arithmetic 
   constants from progmem. */

/* { dg-do run } */
/* { dg-options "-mno-const-data-in-progmem -save-temps" } */
/* { dg-require-effective-target avr_progmem_insn_for_progmem } */
/* { dg-skip-if "skip if global option is to enable const data in progmem" { *-*-* } { "-mconst-data-in-progmem" } { "" } } */

const volatile _Bool b = 1;
const volatile signed char sc = 1;
const volatile unsigned char uc = 255;

const volatile signed short ss = 1;
const volatile unsigned short us = 65535;

const volatile signed int si = 1;
const volatile unsigned int ui = 65535;

const volatile signed long sl = 1;
const volatile unsigned long ul = (1UL << 31);

enum E { ONE, TWO };
const volatile enum E e = TWO;

int main() {
  if (b != 1)
    __builtin_abort();

  if (sc != 1)
    __builtin_abort();

  if (uc != 255)
    __builtin_abort();

  if (ss != 1)
    __builtin_abort();

  if (us != 65535)
    __builtin_abort();

  if (si != 1)
    __builtin_abort();

  if (ui != 65535)
    __builtin_abort();

  if (sl != 1)
    __builtin_abort();

  if (ul != (1UL << 31))
    __builtin_abort();

  if (e != TWO)
    __builtin_abort();

  return 0;
}

/* { dg-final { scan-assembler-not "call __xload_*" } } */

/* { dg-final { scan-assembler-not ".global	b\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler-not ".global	sc\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler-not ".global	uc\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler-not ".global	ss\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler-not ".global	us\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler-not ".global	si\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler-not ".global	ui\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler-not ".global	sl\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler-not ".global	ul\n\t.section	.progmemx.data,progmemx" } } */
