/* Copyright (C) 2002  Free Software Foundation.
   by Hans-Peter Nilsson  <hp@bitrange.com>, derived from mzero2.c

   In the MMIX port, negdf2 was bogusly expanding -x into 0 - x.  */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
extern int memcmp (const void *, const void *expected, __SIZE_TYPE__);
#endif

double nzerod = -0.0;
float nzerof = -0.0;
double zerod = 0.0;
float zerof = 0.0;

void expectd (double, double);
void expectf (float, float);
double negd (double);
float negf (float);

main ()
{
  expectd (negd (zerod), nzerod);
  expectf (negf (zerof), nzerof);
  expectd (negd (nzerod), zerod);
  expectf (negf (nzerof), zerof);
  exit (0);
}

void
expectd (double value, double expected)
{
  if (value != expected
      || memcmp ((void *)&value, (void *) &expected, sizeof (double)) != 0)
    abort ();
}

void
expectf (float value, float expected)
{
  if (value != expected
      || memcmp ((void *)&value, (void *) &expected, sizeof (float)) != 0)
    abort ();
}

double
negd (double v)
{
  return -v;
}

float
negf (float v)
{
  return -v;
}
