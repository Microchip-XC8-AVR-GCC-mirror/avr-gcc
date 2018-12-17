/* { dg-options "-std=gnu99 -mconst-data-in-progmem" } */
/* { dg-do run } */
extern void *memcpy (void *, const void *, unsigned int);
extern void abort();
volatile int x;
extern int
__attribute__((noinline))
bar (const char *p)
{
	return p[x];
}

struct t_s {
  char s[14];
};

static const struct t_s t[] = { {"abc"} };

volatile int count = 1;
int main()
{
  struct t_s tt;
  for (int i = 0; i<count; i++) {
    memcpy (&tt, t+i, sizeof(tt));
    if (bar(tt.s) != 'a')
			abort();
  }
}

