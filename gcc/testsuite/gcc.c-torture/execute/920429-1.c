#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
typedef unsigned char t;int i,j;
__CONST t*f(__CONST t*p){t c;c=*p++;i=((c&2)?1:0);j=(c&7)+1;return p;}
main(){__CONST t*p0="ab",*p1;p1=f(p0);if(p0+1!=p1)abort();exit(0);}
