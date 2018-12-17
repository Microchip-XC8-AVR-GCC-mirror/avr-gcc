#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

typedef struct
{
  __CONST char *key;
  char *value;
} T1;

typedef struct
{
  long type;
  char *value;
} T3;

T1 a[] =
{
  {
    "",
    ((char *)&((T3) {1, (char *) 1}))
  }
};
