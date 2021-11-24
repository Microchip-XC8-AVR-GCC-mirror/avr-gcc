
void test_01()
{
  printf (QUOTE(PRINT_FMT), PRINT_ARG);
}

void test_02()
{
  fprintf (fp, QUOTE(PRINT_FMT), PRINT_ARG);
}

void test_03()
{
  sprintf (buf, QUOTE(PRINT_FMT), PRINT_ARG);
}

void test_04()
{
  snprintf (buf, len, QUOTE(PRINT_FMT), PRINT_ARG);
}

void vprintf_wrap(int dummy, ...)
{
  va_list va;
  va_start(va, dummy);
  vprintf(QUOTE(PRINT_FMT), va);
  va_end(va);
}

void test_05()
{
  vprintf_wrap (0, PRINT_ARG);
}


void vfprintf_wrap(FILE *_fp, int dummy, ...)
{
  va_list va;
  va_start(va, dummy);
  vfprintf(_fp, QUOTE(PRINT_FMT), va);
  va_end(va);
}
void test_06()
{
  vfprintf_wrap (fp, 0, PRINT_ARG);
}

void vsprintf_wrap(char *_buf, int dummy, ...)
{
  va_list va;
  va_start(va, dummy);
  vsprintf(_buf, QUOTE(PRINT_FMT), va);
  va_end(va);
}
void test_07()
{
  vsprintf_wrap (buf, 0, PRINT_ARG);
}


void vsnprintf_wrap(char *_buf, int _len, int dummy, ...)
{
  va_list va;
  va_start(va, dummy);
  vsnprintf(_buf, _len, QUOTE(PRINT_FMT), va);
  va_end(va);
}
void test_08()
{
  vsnprintf_wrap (buf, len, 0, PRINT_ARG);
}

int main()
{
  test_01();
  test_02();
  test_03();
  test_04();
  test_05();
  test_06();
  test_07();
  test_08();

  return 0;
}

