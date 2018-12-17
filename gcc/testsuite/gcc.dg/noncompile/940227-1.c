#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
struct font {
  struct {
    __CONST char *line,*ulmask;
  } c[2];
} character[1] = { { {"", ""}, {"", ""} } }; /* { dg-error "extra|near|excess" } */
