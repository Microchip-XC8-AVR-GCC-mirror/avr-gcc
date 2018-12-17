/* { dg-do compile  }*/
/* { dg-options "-O2" } */

char *const f(void)
{
#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
	char *const line = (char*)"/dev/ptyXX";
#else
	char *const line = "/dev/ptyXX";
#endif
        line[8] = 1;
        return line;
}
