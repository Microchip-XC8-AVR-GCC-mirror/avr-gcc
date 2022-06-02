/* Verify that const volatile var is allocated to rodata on
   devices with flash mapped to program memory. */
/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-skip-if "Only for memory mapped flash devices, others place it in progmemx" { { avr_progmem_insn_for_progmem } || { ! avr_const_data_in_progmem } } } */

const volatile int x = 2;
int main() {
  return x;
}

/* { dg-final { scan-assembler ".global\tx\[\n\r\]+\t.section\t.rodata,rodata" } } */
