/* Verify that section anchor based addressing does not fail for
   non-generic address space access. Ensure no anchor symbol is
   generated, and ensure no ICE in convert_memory_address_addr_space_1 */

/* { dg-do compile } */
/* { dg-options "-Os -mconst-data-in-progmem -fsection-anchors" } */
/* { dg-require-effective-target avr_progmem_insn_for_progmem } */

const char arr[] = {0xA, 0xB, 0xC};

char foo(int x) {
  return arr[x];
}

char bar(int x) {
  return "Hello"[x];
}

/* { dg-final { scan-assembler-not ".set	\\.LANCHOR\\d+, \\. \\+ 0" } } */
