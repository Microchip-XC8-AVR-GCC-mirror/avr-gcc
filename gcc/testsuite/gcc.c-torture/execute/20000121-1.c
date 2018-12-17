#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
void big(long long u) { }

void doit(unsigned int a,unsigned int b,__CONST char *id)
{
  big(*id);
  big(a);
  big(b);
}

int main(void)
{
  doit(1,1,"\n");
  return 0;
}
