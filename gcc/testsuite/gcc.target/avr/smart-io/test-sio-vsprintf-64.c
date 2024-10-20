/* Test smart-io 64 variants of vsprintf for compilation or link errors. */

/* { dg-do link } */
/* { dg-options "-mno-smart-io" } */

#include "sio_test.h"

int _vsprintf_aAcdeEfFgGnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdeEfFgGnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdeEfFnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdeEfFnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdeEgGnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdeEgGnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdeEnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdeEnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdfFgGnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdfFgGnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdfFnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdfFnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdgGnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdgGnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAcdnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAeEfFgGs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAeEfFgG (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAeEfFs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAeEfF (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAeEgGs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAeEgG (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAeEs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAeE (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAfFgGs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAfFgG (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAfFs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAfF (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAgGs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAgG (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aAs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_aA (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdeEfFgGnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdeEfFgGnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdeEfFnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdeEfFnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdeEgGnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdeEgGnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdeEnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdeEnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdfFgGnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdfFgGnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdfFnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdfFnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdgGnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdgGnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdnopsuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_cdnopuxX (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_eEfFgGs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_eEfFgG (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_eEfFs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_eEfF (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_eEgGs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_eEgG (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_eEs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_eE (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_fFgGs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_fFgG (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_fFs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_fF (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_gGs (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_gG (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_s (char *__restrict, const char *__restrict, __isoc_va_list);
int _vsprintf_0 (char *__restrict, const char *__restrict, __isoc_va_list);

int main()
{
  _vsprintf_aAcdeEfFgGnopsuxX (buf, "%a,%d,%e,%f,%g,%s", _va);
  _vsprintf_aAcdeEfFgGnopuxX (buf, "%a,%d,%e,%f,%g", _va);
  _vsprintf_aAcdeEfFnopsuxX (buf, "%a,%d,%e,%f,%s", _va);
  _vsprintf_aAcdeEfFnopuxX (buf, "%a,%d,%e,%f", _va);
  _vsprintf_aAcdeEgGnopsuxX (buf, "%a,%d,%e,%g,%s", _va);
  _vsprintf_aAcdeEgGnopuxX (buf, "%a,%d,%e,%g", _va);
  _vsprintf_aAcdeEnopsuxX (buf, "%a,%d,%e,%s", _va);
  _vsprintf_aAcdeEnopuxX (buf, "%a,%d,%e", _va);
  _vsprintf_aAcdfFgGnopsuxX (buf, "%a,%d,%f,%g,%s", _va);
  _vsprintf_aAcdfFgGnopuxX (buf, "%a,%d,%f,%g", _va);
  _vsprintf_aAcdfFnopsuxX (buf, "%a,%d,%f,%s", _va);
  _vsprintf_aAcdfFnopuxX (buf, "%a,%d,%f", _va);
  _vsprintf_aAcdgGnopsuxX (buf, "%a,%d,%g,%s", _va);
  _vsprintf_aAcdgGnopuxX (buf, "%a,%d,%g", _va);
  _vsprintf_aAcdnopsuxX (buf, "%a,%d,%s", _va);
  _vsprintf_aAcdnopuxX (buf, "%a,%d", _va);
  _vsprintf_aAeEfFgGs (buf, "%a,%e,%f,%g,%s", _va);
  _vsprintf_aAeEfFgG (buf, "%a,%e,%f,%g", _va);
  _vsprintf_aAeEfFs (buf, "%a,%e,%f,%s", _va);
  _vsprintf_aAeEfF (buf, "%a,%e,%f", _va);
  _vsprintf_aAeEgGs (buf, "%a,%e,%g,%s", _va);
  _vsprintf_aAeEgG (buf, "%a,%e,%g", _va);
  _vsprintf_aAeEs (buf, "%a,%e,%s", _va);
  _vsprintf_aAeE (buf, "%a,%e", _va);
  _vsprintf_aAfFgGs (buf, "%a,%f,%g,%s", _va);
  _vsprintf_aAfFgG (buf, "%a,%f,%g", _va);
  _vsprintf_aAfFs (buf, "%a,%f,%s", _va);
  _vsprintf_aAfF (buf, "%a,%f", _va);
  _vsprintf_aAgGs (buf, "%a,%g,%s", _va);
  _vsprintf_aAgG (buf, "%a,%g", _va);
  _vsprintf_aAs (buf, "%a,%s", _va);
  _vsprintf_aA (buf, "%a", _va);
  _vsprintf_cdeEfFgGnopsuxX (buf, "%d,%e,%f,%g,%s", _va);
  _vsprintf_cdeEfFgGnopuxX (buf, "%d,%e,%f,%g", _va);
  _vsprintf_cdeEfFnopsuxX (buf, "%d,%e,%f,%s", _va);
  _vsprintf_cdeEfFnopuxX (buf, "%d,%e,%f", _va);
  _vsprintf_cdeEgGnopsuxX (buf, "%d,%e,%g,%s", _va);
  _vsprintf_cdeEgGnopuxX (buf, "%d,%e,%g", _va);
  _vsprintf_cdeEnopsuxX (buf, "%d,%e,%s", _va);
  _vsprintf_cdeEnopuxX (buf, "%d,%e", _va);
  _vsprintf_cdfFgGnopsuxX (buf, "%d,%f,%g,%s", _va);
  _vsprintf_cdfFgGnopuxX (buf, "%d,%f,%g", _va);
  _vsprintf_cdfFnopsuxX (buf, "%d,%f,%s", _va);
  _vsprintf_cdfFnopuxX (buf, "%d,%f", _va);
  _vsprintf_cdgGnopsuxX (buf, "%d,%g,%s", _va);
  _vsprintf_cdgGnopuxX (buf, "%d,%g", _va);
  _vsprintf_cdnopsuxX (buf, "%d,%s", _va);
  _vsprintf_cdnopuxX (buf, "%d", _va);
  _vsprintf_eEfFgGs (buf, "%e,%f,%g,%s", _va);
  _vsprintf_eEfFgG (buf, "%e,%f,%g", _va);
  _vsprintf_eEfFs (buf, "%e,%f,%s", _va);
  _vsprintf_eEfF (buf, "%e,%f", _va);
  _vsprintf_eEgGs (buf, "%e,%g,%s", _va);
  _vsprintf_eEgG (buf, "%e,%g", _va);
  _vsprintf_eEs (buf, "%e,%s", _va);
  _vsprintf_eE (buf, "%e", _va);
  _vsprintf_fFgGs (buf, "%f,%g,%s", _va);
  _vsprintf_fFgG (buf, "%f,%g", _va);
  _vsprintf_fFs (buf, "%f,%s", _va);
  _vsprintf_fF (buf, "%f", _va);
  _vsprintf_gGs (buf, "%g,%s", _va);
  _vsprintf_gG (buf, "%g", _va);
  _vsprintf_s (buf, "%s", _va);
  _vsprintf_0 (buf, "%X", _va);

  return 0;
}

