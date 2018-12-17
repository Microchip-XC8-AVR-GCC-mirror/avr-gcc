#include        <stdio.h>
#include        <stdlib.h>
extern void abort();
#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

typedef struct foo
{
        int     uaattrid;
        __CONST char    *name;
} FOO;

FOO     Upgrade_items[] =
{
        {1, "1"},
        {2, "2"},
        {0, NULL}
};

int     *Upgd_minor_ID = 
        (int *) &((Upgrade_items + 1)->uaattrid);

int     *Upgd_minor_ID1 = 
        (int *) &((Upgrade_items)->uaattrid);

int
main(int argc, char **argv)
{
	if (*Upgd_minor_ID != 2)
	  abort();

	if (*Upgd_minor_ID1 != 1)
	  abort();
	return 0;
}
