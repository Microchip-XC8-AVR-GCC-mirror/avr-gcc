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

char* ptrs[10];
int lengths[10] = { 2,3,4,8,5,6,3,4,9,10 };
const char *strs[10] = {
				  "aa",
				  "bbb",
				  "cccc",
				  "dddddddd",
				  "eeeee",
				  "ffffff",
				  "ggg",
				  "hhhh",
				  "iiiiiiiii",
				  "jjjjjjjjjj"
};


void test_special_cases()
{
  #define MSIZE1 4
  
  char *exp_ptr = __malloc_heap_start + SZ_SIZE_FIELD;
  // first allocation starts at __malloc_heap_start
  char *p = (char*)malloc(MSIZE1);
  if (p != exp_ptr)
	exit(1);

  // 0 bytes request will allocate minimum 1 byte
  exp_ptr += MSIZE1 + SZ_SIZE_FIELD;
  if ((char*)malloc(0) != exp_ptr)
	exit(2);

  // for n < min_size byte requests, heap expanded to min_size
  exp_ptr += MIN_SIZE; // min size include size field size
  char *p3 = (char*)malloc(4);
  if (p3 != exp_ptr)
	exit(3);

  // does nothing
  free(0);
}

void test_mem_allocs()
{
  int i = 0;
  for (; i < 10; i++)
    {
      ptrs[i] = (char*)malloc(lengths[i]);
      memset(ptrs[i],'a'+i,lengths[i]);
    }
  for (i = 0; i < 10; i++)
    {
	  if (strncmp(ptrs[i], strs[i], lengths[i]))
		exit(100+i+1);
    }
}

void test_alloc_pointer_size()
{
  for (int i = 0; i < 10; i++)
    {
      ptrs[i] = (char*)malloc(lengths[i]);
	  //printf ("p: 0x%x \n", (unsigned int)ptrs[i]);
    }

  /* check the allocated pointer addresses.
	 When free is not used, the size field shouldn't be 
	 accounted in the allocated pointer.  */ 
  unsigned int next_addr = (unsigned int)ptrs[0] +
	((lengths[0] + SZ_SIZE_FIELD) < MIN_SIZE ? MIN_SIZE : lengths[0] + SZ_SIZE_FIELD);
  for (int i = 1; i < 10; i++)
    {
	  //printf ("p: 0x%x 0x%x\n", next_addr, (unsigned int)ptrs[i]);
	  if ((unsigned int)ptrs[i] != next_addr)
		exit(200+i);
	  next_addr += ((lengths[i] + SZ_SIZE_FIELD) < MIN_SIZE ? MIN_SIZE :
					lengths[i] + SZ_SIZE_FIELD);
    }

  for (int i = 0; i < 10; i++)
	free(ptrs[i]);
}

int main()
{
  test_special_cases();
  test_mem_allocs();
  test_alloc_pointer_size();
  return 0;
}
