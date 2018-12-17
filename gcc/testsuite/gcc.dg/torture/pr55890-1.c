/* { dg-do compile } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
extern void *memmove(void *, __CONST void *, __SIZE_TYPE__);
typedef int (*_TEST_fun_) ();
static _TEST_fun_ i = (_TEST_fun_) memmove;
int main() { i(); }
