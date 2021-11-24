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
#define SZ_SIZE_FIELD (sizeof(size_t))

void fill_heap(int sz, int skip_sz)
{
  char *p = __malloc_heap_start + skip_sz;
  for (int i=0; i < sz; i++)
	{
	  *(p+i) = 'a';
	}
}

int main()
{
  fill_heap(10, 12); // skip first 12 bytes and fill 'a' in next 10 bytes of heap

  #define FIRST_MALLOC_ADDR (__malloc_heap_start + SZ_SIZE_FIELD)

  #define MSIZE1 10
  char *ptr1 = (char*)calloc(MSIZE1, 1);
  if (ptr1 != FIRST_MALLOC_ADDR)
	exit(1);
  for (int i = 0; i < MSIZE1; i++)
	if (*(ptr1+i) != 0)
	  exit(100+i);
  free(ptr1);

  fill_heap(MSIZE1, SZ_SIZE_FIELD); // fill 'a' in 10 bytes from heap_start+size_field

  #define MSIZE2 16
  fill_heap(MSIZE2, MSIZE1 + SZ_SIZE_FIELD); // fill 'a' in 16 bytes from heap_start + 12
  
  // requesting a size which is greater than already free'd pointer
  char *ptr2 = (char*)calloc(4, 4); // MSIZE2 
  if (ptr2 != FIRST_MALLOC_ADDR + MSIZE1 + SZ_SIZE_FIELD)
	exit(2);
  for (int i = 0; i < MSIZE2; i++)
	if (*(ptr2+i) != 0)
	  exit(200+i);
  free(ptr2);

  // request same memory as already free'd pointer
  char *ptr3 = (char*)calloc(5, 2);
  if (ptr3 != ptr1) //FIRST_MALLOC_ADDR)
	exit(3);
  for (int i = 0; i < MSIZE1; i++)
	if (*(ptr1+i) != 0)
	  exit(100+i);
  free(ptr3);
  
  return 0;
}
