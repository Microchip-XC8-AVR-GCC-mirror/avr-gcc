#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
#include <stdarg.h>

typedef double TYPE;

void vafunction (__CONST char *dummy, ...)
{
  va_list ap;

  va_start(ap, dummy);
  if (va_arg (ap, TYPE) != 1.)
    abort();
  if (va_arg (ap, TYPE) != 2.)
    abort();
  if (va_arg (ap, TYPE) != 3.)
    abort();
  if (va_arg (ap, TYPE) != 4.)
    abort();
  if (va_arg (ap, TYPE) != 5.)
    abort();
  if (va_arg (ap, TYPE) != 6.)
    abort();
  if (va_arg (ap, TYPE) != 7.)
    abort();
  if (va_arg (ap, TYPE) != 8.)
    abort();
  if (va_arg (ap, TYPE) != 9.)
    abort();
  va_end(ap);
}


int main (void)
{
  vafunction( "", 1., 2., 3., 4., 5., 6., 7., 8., 9. );
  exit(0);
  return 0;
}
