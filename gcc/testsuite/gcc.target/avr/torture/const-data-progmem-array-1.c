/* Verify that -mconst-data-in-progmem places and reads const arrays
   from progmem. */

/* { dg-do run } */
/* { dg-options "-save-temps -mconst-data-in-progmem" } */
/* { dg-require-effective-target avr_progmem_insn_for_progmem } */

const volatile _Bool ba[] = {1, 0, 1};

const volatile signed char sca[] = {1, 0, 1};
const volatile unsigned char uca[] = {255, 0, 1};

const volatile signed short ssa[] = {1, 0, 1};
const volatile unsigned short usa[] = {65535, 0, 1};

const volatile signed int sia[] = {1, 0, 1};
const volatile unsigned int uia[] = {65535, 0, 1};

const volatile signed long sla[] = {1, 0, 1};
const volatile unsigned long ula[] = {1UL << 31, 0, 1};

enum E { ONE, TWO };
const volatile enum E ea[] = {TWO, ONE};

const volatile float fca[] = {0.5F, 0.1F, 1.1F};
const volatile double dca[] = {0.5F, 0.1, 1.1};

volatile int i;

int main() {
  if (ba[i] != 1)
    __builtin_abort();

  if (sca[i] != 1)
    __builtin_abort();

  if (uca[i] != 255)
    __builtin_abort();

  if (ssa[i] != 1)
    __builtin_abort();

  if (usa[i] != 65535)
    __builtin_abort();

  if (sia[i] != 1)
    __builtin_abort();

  if (uia[i] != 65535)
    __builtin_abort();

  if (sla[i] != 1)
    __builtin_abort();

  if (ula[i] != (1UL << 31))
    __builtin_abort();

  if (ea[i] != TWO)
    __builtin_abort();

  if (fca[i] != 0.5F)
    __builtin_abort();

  if (dca[i] != 0.5F)
    __builtin_abort();

  return 0;
}

/* 2 for sca/uca and 1 for _Bool */
/* { dg-final { scan-assembler-times "call __xload_1" 3 } } */
/* 2 each for ssa/usa and sia/uia, and 1 for enum */
/* { dg-final { scan-assembler-times "call __xload_2" 5 } } */
/* { dg-final { scan-assembler-times "call __xload_4" 4 } } */

/* { dg-final { scan-assembler ".global	ba\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	sca\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	uca\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	ssa\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	usa\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	sia\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	uia\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	sla\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	ula\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	fca\n\t.section	.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global	dca\n\t.section	.progmemx.data,progmemx" } } */
