#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
#define A "This is a long test that tests the structure initialization"
#define B A,A
#define C B,B,B,B
#define D C,C,C,C
int main()
{
  __CONST char *subs[]={ D, D, D, D, D, D, D, D, D, D, D, D, D, D, D};
}
