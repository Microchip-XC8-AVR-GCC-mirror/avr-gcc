#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

#define k(a) #a
__CONST char *s = k(k(1,2));
__CONST char *t = k(#) k(#undef k) k(x);

f(){}
