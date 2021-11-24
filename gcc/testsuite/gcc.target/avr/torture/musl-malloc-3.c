/* { dg-options "-std=c99" } */
/* { dg-do run } */

/* Test the simple malloc from MUSL.
   The malloc pointers will accomodate size_t field only
   when the free function is used in the application.
   This test uses free.
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// minimum size assumed in malloc when free is used
#define MIN_SIZE (sizeof(size_t) + sizeof(intptr_t))
#define SZ_SIZE_FIELD (sizeof(size_t))

// heap start used by expand_heap
extern char *__malloc_heap_start;

char* ptrs[5];
int lengths[5] = { 4,5,6,7,8 };

int main ()
{
  for (int i = 0; i < 5; i++)
	{
	  ptrs[i] = (char*)malloc(lengths[i]);
	  //printf ("p: 0x%x %d\n", ptrs[i], lengths[i]);
	}

  if (ptrs[0] != __malloc_heap_start + SZ_SIZE_FIELD)
	exit(1);
  
  char* next_addr = __malloc_heap_start + 4+5+6+7+8 + (5 * SZ_SIZE_FIELD);
  //printf ("next_addr: 0x%x \n", next_addr);
  
  for (int i = 0; i < 5; i++)
	free(ptrs[i]);

  // check if free'd memory used for malloc
  // if the requested size is available in free list
  char *ptr1 = (char*)malloc(7);
  //printf ("ptr1: 0x%x \n", ptr1);
  if (ptr1 != ptrs[0])
	exit(2);

  char *ptr2 = (char*)malloc(32);
  //printf ("ptr2: 0x%x \n", ptr2);
  if (ptr2 != (next_addr + SZ_SIZE_FIELD))
	exit(3);

  return 0;
}
