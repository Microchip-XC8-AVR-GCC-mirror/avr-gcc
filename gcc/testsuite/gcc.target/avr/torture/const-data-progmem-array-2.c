/* Verify that -mconst-data-in-progmem places and reads multi-dimensional
	 const global and static local arrays from progmem. */

/* { dg-do run } */
/* { dg-options "-save-temps -mconst-data-in-progmem" } */
/* { dg-require-effective-target avr_progmem_insn_for_progmem } */

const volatile char arr[2][5] = { "ABCD", "EFGH" };

volatile int i, j;

int main() {
  if (arr[0][0] != 'A')
    __builtin_abort();

  if (arr[0][3] != 'D')
    __builtin_abort();

  if (arr[1][0] != 'E')
    __builtin_abort();

  if (arr[1][3] != 'H')
    __builtin_abort();

	static const volatile char sarr[2][5] = { "ABCD", "EFGH" };

  if (sarr[0][0] != 'A')
    __builtin_abort();

  if (sarr[0][3] != 'D')
    __builtin_abort();

  if (sarr[1][0] != 'E')
    __builtin_abort();

  if (sarr[1][3] != 'H')
    __builtin_abort();

  return 0;
}

/* { dg-final { scan-assembler-times "call __xload_1" 8 } } */
/* { dg-final { scan-assembler "\t.section	.progmemx.data,progmemx\n\t.type\tsarr" } } */
/* { dg-final { scan-assembler ".global	arr\n\t.section	.progmemx.data,progmemx" } } */
