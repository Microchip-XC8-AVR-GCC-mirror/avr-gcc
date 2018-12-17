#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
static inline __CONST char *getstring(void)
{
  return "hello";
}
