/* Verify that section anchor based addressing works with const decls
   on archs with memory mapped progmem. */

/* { dg-do compile } */
/* { dg-options "-Os -fsection-anchors" } */
/* { dg-skip-if "Only if consts are in data address space" { avr_progmem_insn_for_progmem && avr_const_data_in_progmem } } */

const char arr[] = {0xA, 0xB, 0xC};

char foo(int x) {
  return arr[x];
}

char bar(int x) {
  return "Hello"[x];
}

/* { dg-final { scan-assembler "foo:" } } */
/* { dg-final { scan-assembler "subi r\\d+,lo8\\(-\\(\\.LANCHOR0\\)\\)" } } */
/* { dg-final { scan-assembler "sbci r\\d+,hi8\\(-\\(\\.LANCHOR0\\)\\)" } } */

/* { dg-final { scan-assembler "bar:" } } */
/* { dg-final { scan-assembler "subi r\\d+,lo8\\(-\\(\\.LANCHOR0\\)\\)" } } */
/* { dg-final { scan-assembler "sbci r\\d+,hi8\\(-\\(\\.LANCHOR0\\)\\)" } } */

/* { dg-final { scan-assembler ".set	\\.LANCHOR\\d+, \\. \\+ 0" } } */
