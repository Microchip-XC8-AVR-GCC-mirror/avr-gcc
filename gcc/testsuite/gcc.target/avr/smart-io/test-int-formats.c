/* Test smart-io printf variant for int formats */

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

/* %c Format */
void test_c()
{
    printf ("%c", c);
    fprintf (fp, "%c", c);
    sprintf (buf, "%c", c);
    snprintf (buf, len, "%c", c);

    vprintf ("%c", _va);
    vfprintf (fp, "%c", _va);
    vsprintf (buf, "%c", _va);
    vsnprintf (buf, len, "%c", _va);

}

/* %d Format */
void test_d()
{
    printf ("%d", d);
    fprintf (fp, "%d", d);
    sprintf (buf, "%d", d);
    snprintf (buf, len, "%d", d);

    vprintf ("%d", _va);
    vfprintf (fp, "%d", _va);
    vsprintf (buf, "%d", _va);
    vsnprintf (buf, len, "%d", _va);
}

/* %n Format */
void test_n()
{
    printf ("%n", n);
    fprintf (fp, "%n", n);
    sprintf (buf, "%n", n);
    snprintf (buf, len, "%n", n);

    vprintf ("%n", _va);
    vfprintf (fp, "%n", _va);
    vsprintf (buf, "%n", _va);
    vsnprintf (buf, len, "%n", _va);
}

/* %o Format */
void test_o()
{
    printf ("%o", o);
    fprintf (fp, "%o", o);
    sprintf (buf, "%o", o);
    snprintf (buf, len, "%o", o);

    vprintf ("%o", _va);
    vfprintf (fp, "%o", _va);
    vsprintf (buf, "%o", _va);
    vsnprintf (buf, len, "%o", _va);
}

/* %p Format */
void test_p()
{
    printf ("%p", p);
    fprintf (fp, "%p", p);
    sprintf (buf, "%p", p);
    snprintf (buf, len, "%p", p);

    vprintf ("%p", _va);
    vfprintf (fp, "%p", _va);
    vsprintf (buf, "%p", _va);
    vsnprintf (buf, len, "%p", _va);
}

/* %u Format */
void test_u()
{
    printf ("%u", u);
    fprintf (fp, "%u", u);
    sprintf (buf, "%u", u);
    snprintf (buf, len, "%u", u);

    vprintf ("%u", _va);
    vfprintf (fp, "%u", _va);
    vsprintf (buf, "%u", _va);
    vsnprintf (buf, len, "%u", _va);
}

/* %x Format */
void test_x()
{
    printf ("%x", x);
    fprintf (fp, "%x", x);
    sprintf (buf, "%x", x);
    snprintf (buf, len, "%x", x);

    vprintf ("%x", _va);
    vfprintf (fp, "%x", _va);
    vsprintf (buf, "%x", _va);
    vsnprintf (buf, len, "%x", _va);
}

/* %X Format */
void test_X()
{
    printf ("%X", X);
    fprintf (fp, "%X", X);
    sprintf (buf, "%X", X);
    snprintf (buf, len, "%X", X);

    vprintf ("%X", _va);
    vfprintf (fp, "%X", _va);
    vsprintf (buf, "%X", _va);
    vsnprintf (buf, len, "%X", _va);
}

int main()
{
    test_c();
    test_d();
    test_n();
    test_o();
    test_p();
    test_u();
    test_x();
    test_X();

    return 0;
}

/* { dg-final { scan-assembler "call putchar" } } */
/* { dg-final { scan-assembler "call fputc" } } */
/* { dg-final { scan-assembler "call _sprintf_cdnopuxX" } } */  
/* { dg-final { scan-assembler "call _snprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdnopuxX" } } */

/* { dg-final { scan-assembler "call _printf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdnopuxX" } } */  
/* { dg-final { scan-assembler "call _snprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdnopuxX" } } */

/* { dg-final { scan-assembler "call _printf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdnopuxX" } } */  
/* { dg-final { scan-assembler "call _snprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdnopuxX" } } */

/* { dg-final { scan-assembler "call _printf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdnopuxX" } } */  
/* { dg-final { scan-assembler "call _snprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdnopuxX" } } */

/* { dg-final { scan-assembler "call _printf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdnopuxX" } } */  
/* { dg-final { scan-assembler "call _snprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdnopuxX" } } */

/* { dg-final { scan-assembler "call _printf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdnopuxX" } } */  
/* { dg-final { scan-assembler "call _snprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdnopuxX" } } */

/* { dg-final { scan-assembler "call _printf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdnopuxX" } } */  
/* { dg-final { scan-assembler "call _snprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdnopuxX" } } */

/* { dg-final { scan-assembler "call _printf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdnopuxX" } } */  
/* { dg-final { scan-assembler "call _snprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdnopuxX" } } */
