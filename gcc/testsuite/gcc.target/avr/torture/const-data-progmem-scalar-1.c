/* Verify that -mconst-data-in-progmem places and reads arithmetic 
   constants from progmem. */

/* { dg-do run } */
/* { dg-options "-save-temps -mconst-data-in-progmem" } */
/* { dg-require-effective-target avr_progmem_insn_for_progmem } */

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

const volatile float fc = 0.5F;
const volatile double dc = 0.5F;

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

  if (fc != 0.5F)
    __builtin_abort();

  if (dc != 0.5F)
    __builtin_abort();

  return 0;
}

/* 2 for sc/uc and 1 for _Bool */
/* { dg-final { scan-assembler-times "call __xload_1" 3 } } */
/* 2 each for ss/us and si/ui, and 1 for enum */
/* { dg-final { scan-assembler-times "call __xload_2" 5 } } */
/* { dg-final { scan-assembler-times "call __xload_4" 4 } } */

/* { dg-final { scan-assembler ".global	b\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	sc\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	uc\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	ss\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	us\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	si\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	ui\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	sl\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	ul\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	fc\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	dc\n\t.section	.progmemx.data,progmemx" } } */
