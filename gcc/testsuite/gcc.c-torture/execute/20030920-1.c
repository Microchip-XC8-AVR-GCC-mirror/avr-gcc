extern void abort (void);
#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

int main()
{
  int hicount = 0;
  __CONST unsigned char *c;
  __CONST char *str = "\x7f\xff";
  for (c = (__CONST unsigned char *)str; *c ; c++) {
    if (!(((unsigned int)(*c)) < 0x80)) hicount++;
  }
  if (hicount != 1)
    abort ();
  return 0;
}

