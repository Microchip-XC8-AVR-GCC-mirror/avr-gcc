/* Spurious uninit variable warnings, case 3.
   Inspired by cppexp.c (parse_charconst) */
/* { dg-do compile } */
/* { dg-options "-Wuninitialized" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
extern void error (__CONST char *);

int
parse_charconst (const char *start, const char *end)
{
  int c; /* { dg-bogus "c" "uninitialized variable warning" } */
  int nchars, retval;

  nchars = 0;
  retval = 0;
  while (start < end)
    {
      c = *start++;
      if (c == '\'')
	break;
      nchars++;
      retval += c;
      retval <<= 8;
    }

  if (nchars == 0)
    return 0;

  if (c != '\'')
    error ("malformed character constant");

  return retval;
}
