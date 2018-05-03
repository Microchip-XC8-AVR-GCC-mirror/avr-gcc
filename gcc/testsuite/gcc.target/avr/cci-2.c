/* Verify that plain char and bitfield are considered
   unsigned when cci enabled.  */
/* { dg-do run } */
/* { dg-options "-mext=CCI" } */

char c = 0xff;
struct st {
  int bit:3;
} obj = {7};

int main ()
{
  if ((c != 0x00ff) || (obj.bit != 0x0007))
    __builtin_abort();
  return 0;
}

