/* { dg-do compile } */
/* { dg-options "-w" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
extern int strlen(const char *);
void WriteTextDots(int len);

void OnDisplay(__CONST char * string)
{
  if (!string)
    string = "(none)";
  WriteTextDots(strlen(string));
}

