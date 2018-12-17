/* PR rtl-optimization/51495 */
/* { dg-require-effective-target indirect_jumps } */
/* { dg-require-effective-target label_values } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST
#else
#define __CONST const
#endif
void bar (void);

int
foo (int i)
{
  static __CONST void *const table[] = { &&begin, &&end };
  goto *(table[i]);
begin:
  bar ();
end:
  return 0;
}
