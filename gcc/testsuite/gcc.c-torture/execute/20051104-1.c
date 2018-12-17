/* PR rtl-optimization/23567 */

struct
{
  int len;
  char *name;
} s;

int
main (void)
{
  s.len = 0;
#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
  s.name = (char*)"";
#else
  s.name = "";
#endif
  if (s.name [s.len] != 0)
    s.name [s.len] = 0;
  return 0;
}
