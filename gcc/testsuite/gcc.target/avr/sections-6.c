/* Verify that switch jump table sections generated with valid attributes.  */
/* { dg-do run } */
/* { dg-options "-mext=cci -ffunction-sections -save-temps" } */

#include<xc.h>

int i1 = 2, i2 = 21, i3 = 32;

void test_1 (int a)
{
  switch(a)
  {
	case 0:
		i1 = 12;
		break;
	case 1:
		i2 = 23;
		break;
	case 2:
		i1 = 23;
		break;
	case 3:
		i3 = i1 + i2;
		break;
	case 4:
		i2 = 0;
		break;
	case 5:
		i3 = 0;
		break;
	case 6:
		i2 = 40;
		break;
	default:
			break;
  }
}

int main ()
{
	test_1(0);
	test_1(1);
	test_1(3);
	if (i3 != 35)
		__builtin_abort();

	test_1(2);
	test_1(4);
	if (i1 != 23 || i2 != 0)
		__builtin_abort();

	return 0;
}

/* { dg-final { scan-assembler "jmp __tablejump2__\[\n\r\]+\t.section\t.progmem.gcc_sw_table.test_1,progmem" } } */

