#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
void percent_x(int ch, char *p, char* ok_chars)
{
  __CONST char *cp = ch == 'a' ? p : "";
  for (;*(cp += __builtin_strspn (cp, ok_chars));)
    ;
}
