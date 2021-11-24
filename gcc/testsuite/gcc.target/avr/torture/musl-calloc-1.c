/* { dg-options "-std=c99" } */
/* { dg-do run } */

/* Test the simple calloc from MUSL.
   calloc uses malloc followed by memset.  */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// heap start used by expand_heap
extern char *__malloc_heap_start;

int main()
{
  char *p = __malloc_heap_start;
  for (int i=0; i < 10; i++)
	{
	  *(p+i) = 'a';
	}

  char *ptr1 = (char*)calloc(10, 1);
  if (ptr1 != __malloc_heap_start)
	exit(1);
  for (int i = 0; i < 10; i++)
	if (*(ptr1+i) != 0)
	  exit(100+i);

  return 0;
}
