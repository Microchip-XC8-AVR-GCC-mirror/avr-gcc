/* { dg-do compile } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST
#else
#define __CONST const
#endif
typedef int Embryo_Cell;
int
embryo_program_run(Embryo_Cell *cip)
{
    unsigned char op;
    Embryo_Cell offs;
    static __CONST void *switchtable[256] = {
	&&SWITCHTABLE_EMBRYO_OP_NONE, &&SWITCHTABLE_EMBRYO_OP_LOAD_PRI
    };
    for (;;)
      {
	op = *cip++;
	while (1) {
	    goto *switchtable[op];
SWITCHTABLE_EMBRYO_OP_LOAD_PRI:
	    offs = *(Embryo_Cell *)cip++;
SWITCHTABLE_EMBRYO_OP_NONE:
	    break;
	};
      }
    return offs;
}
