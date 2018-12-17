#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

unsigned char lookup_table [257];

static int 
build_lookup (pattern)
     __CONST unsigned char *pattern;
{
  int m;

  m = strlen (pattern) - 1;
  
  memset (lookup_table, ++m, 257);
  return m;
}

int main(argc, argv)
     int argc;
     char **argv;
{
  if (build_lookup ("bind") != 4)
    abort ();
  else
    exit (0);
}

