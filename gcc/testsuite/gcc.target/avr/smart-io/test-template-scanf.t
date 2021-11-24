
void test_01()
{
  scanf (QUOTE(SCANF_FMT), SCANF_ARG);
}

void test_02()
{
  sscanf (buf, QUOTE(SCANF_FMT), SCANF_ARG);
}

void test_03()
{
  fscanf (fp, QUOTE(SCANF_FMT), SCANF_ARG);
}


void vscanf_wrap(int dummy, ...)
{
  va_list va;
  va_start(va, dummy);
  vscanf(QUOTE(SCANF_FMT), va);
  va_end(va);
}
void test_04()
{
  vscanf_wrap (0, SCANF_ARG);
}


void vfscanf_wrap(FILE *_fp, int dummy, ...)
{
  va_list va;
  va_start(va, dummy);
  vfscanf(_fp, QUOTE(SCANF_FMT), va);
  va_end(va);
}
void test_05()
{
  vfscanf_wrap (fp, 0, SCANF_ARG);
}


void vsscanf_wrap(char *_buf, int dummy, ...)
{
  va_list va;
  va_start(va, dummy);
  vsscanf(_buf, QUOTE(SCANF_FMT), va);
  va_end(va);
}
void test_06()
{
  vsscanf_wrap (buf, 0, SCANF_ARG);
}


int main()
{
  test_01();
  test_02();
  test_03();
  test_04();
  test_05();
  test_06();

  return 0;
}

