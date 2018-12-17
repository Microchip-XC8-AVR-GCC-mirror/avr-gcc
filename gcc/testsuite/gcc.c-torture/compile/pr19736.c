/* We used to ICE because we had forgot to update the immediate_uses
   information after foldding the last strcpy in Reduce PHI.
   This was PR tree-opt/19763. */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
extern char *strcpy (char *, const char *);
void sdbout_one_type (char *p)
{
  int i, t = 1;
  __CONST char *q;
  for (i = 0; i < 2; i++)
    {
      strcpy (p, "1");
      p += sizeof ("1");
    }
  if (t)
    q = "2";
  else
    q = "3";
  strcpy (p, q);
}

