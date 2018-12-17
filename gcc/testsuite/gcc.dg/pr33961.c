/* PR tree-optimization/33961 */
/* { dg-do run } */
/* { dg-options "-O2 -ftree-cselim" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CCAST (char*)
#else
#define __CCAST
#endif
void decode(char *d, int len);

void decode(char *d, int len) {
        int i = len - 1;
        while(i >= 0) {
                d[i];
                if(d[i] == 0)
                        d[i]=' ';
		if(d[i] == 1)
			d[i]='x';
                i--;
        }
}

int main(int argc, char **argv)
{
        decode(__CCAST"this bug is really weird", 24);
	return 0;
}
