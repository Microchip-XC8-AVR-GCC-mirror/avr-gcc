/* Verify that -mno-const-data-in-progmem does not read extern arithmetic 
   constants from progmem. */

/* { dg-do compile } */
/* { dg-options "-mno-const-data-in-progmem -save-temps" } */
/* { dg-require-effective-target avr_progmem_insn_for_progmem } */
/* { dg-skip-if "skip if global option is to enable const data in progmem" { *-*-* } { "-mconst-data-in-progmem" } { "" } } */

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

unsigned long foo() {
  if (b)
    return sc + uc + ss + us + si + ui + sl + ul + e;
  else
    return 0;
}

/* { dg-final { scan-assembler-not "call __xload*" } } */
