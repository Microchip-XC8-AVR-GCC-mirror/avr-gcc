/* PR optimization/12640

   We used to get into an infinite loop while trying to
   figure out `strlen (resultString)'.  This showed up as
   a stack overflow while compiling tk.  */

/* { dg-do compile } */
/* { dg-options "-O1" } */ 

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
extern __SIZE_TYPE__ strlen (const char *);

int i; 

static void 
SendEventProc (__CONST char *resultString) 
{ 
  char *p; 
 
  resultString = ""; 
  while (*p == '-') 
    { 
      if (p[2] == ' ') 
	{ 
	  resultString = p + 3; 
	} 
    } 
  for (;;) 
    { 
      i = strlen (resultString) + 1; 
    } 
}
 
