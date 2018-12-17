#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

__CONST char* doit(int flag)
{
  return 1 + (flag ? "\0wrong\n" : "\0right\n");
}
int main()
{
  __CONST char *result = doit(0);
  if (*result == 'r' && result[1] == 'i')
    exit(0);
  abort();
}
