#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
int sprintf (char *s, const char *format, ...);

int foo(int i, int j)
{
   char *buf; __CONST char *str;

   if (i)
     str = "";
   else if (j)
     str = "";
   else
     return 1;

   /* We were propagating &""[0] here and not calling fold_stmt with a
      proper statement pointer.  */
   sprintf(buf, str);
   return 0;
}
