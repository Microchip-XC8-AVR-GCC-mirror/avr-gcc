/* Verify that -mconst-data-in-progmem reads extern arithmetic 
   constants from progmem. */

/* { dg-do compile } */
/* { dg-options "-save-temps -mconst-data-in-progmem" } */
/* { dg-require-effective-target avr_progmem_insn_for_progmem } */

extern const _Bool b;
extern const signed char sc;
extern const unsigned char uc;

extern const signed short ss;
extern const unsigned short us;

extern const signed int si;
extern const unsigned int ui;

extern const signed long sl;
extern const unsigned long ul;

enum E { ONE, TWO};
extern const enum E e;

extern const float fc;
extern const double dc;

unsigned long foo() {
  if (b)
    return sc + uc + ss + us + si + ui + sl + ul + e;
  else
    return fc > dc;
}

/* See const-data-progmem-scalar-1.c for explanation of numbers */
/* { dg-final { scan-assembler-times "call __xload_1" 3 } } */
/* { dg-final { scan-assembler-times "call __xload_2" 5 } } */
/* { dg-final { scan-assembler-times "call __xload_4" 4 } } */
