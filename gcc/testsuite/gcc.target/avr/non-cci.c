/* Verify that no changes to char and bitfield types by default.  */
/* { dg-do run } */
/* { dg-options "" } */

char c = 0xff;
struct st {
  int bit:3;
} obj = {7};

int main ()
{
  if ((c != 0xffff) || (obj.bit != 0xffff))
    __builtin_abort();
  return 0;
}

