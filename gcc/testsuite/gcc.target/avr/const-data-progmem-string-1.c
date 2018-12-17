/* Verify that string literal allocated to program memory.  */
/* { dg-do compile } */
/* { dg-options "--std=gnu99 -mconst-data-in-progmem" } */

const char __memx * ptrToMemx = "hello";
const char __memx * const __memx memxPtrToMemx = "world";

extern void foo (const char __memx*, const char __memx* const);

void test1 ()
{
  static const char __memx * sptrToMemx = "ello";
  static const char __memx * const __memx smemxPtrToMemx = "world";
  foo (sptrToMemx, smemxPtrToMemx);
}

/* { dg-final { scan-assembler ".section\t.progmemx.data,progmemx\n.LC0:\n\t.string\t\"hello\"" } } */
/* { dg-final { scan-assembler ".section\t.data,data\n\t.type.*\n\t.size\tptrToMemx, 3\nptrToMemx:\n\t.byte\tlo8\\(.LC0\\) .*\n\t.byte\thi8\\(.LC0\\) .*\n\t.byte\thh8\\(.LC0\\)" } } */
/* { dg-final { scan-assembler ".section\t.progmemx.data,progmemx\n.LC1:\n\t.string\t\"world\"" } } */
/* { dg-final { scan-assembler ".section\t.progmemx.data,progmemx\n\t.type.*\n\t.size\tmemxPtrToMemx, 3\nmemxPtrToMemx:\n\t.byte\tlo8\\(.LC1\\) .*\n\t.byte\thi8\\(.LC1\\) .*\n\t.byte\thh8\\(.LC1\\)" } } */

/* { dg-final { scan-assembler ".section\t.progmemx.data,progmemx\n.LC2:\n\t.string\t\"ello\"" } } */
/* { dg-final { scan-assembler ".section\t.data,data\n\t.type.*\n\t.size\tsptrToMemx.*, 3\nsptrToMemx.*:\n\t.byte\tlo8\\(.LC2\\) .*\n\t.byte\thi8\\(.LC2\\) .*\n\t.byte\thh8\\(.LC2\\)" } } */
/* { dg-final { scan-assembler ".section\t.progmemx.data,progmemx\n\t.type.*\n\t.size\tsmemxPtrToMemx.*, 3\nsmemxPtrToMemx.*:\n\t.byte\tlo8\\(.LC1\\) .*\n\t.byte\thi8\\(.LC1\\) .*\n\t.byte\thh8\\(.LC1\\)" } } */

