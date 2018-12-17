/* PR tree-optimization/35468 */
/* { dg-do compile  }*/
/* { dg-options "-O2 -fno-tree-dce" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CCAST (char*)
#else
#define __CCAST
#endif
char *const f(void)
{
  char *const line = __CCAST"/dev/ptyXX";
  line[8] = 1;
  return line;
}
