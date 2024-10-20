/* Test smart-io 64 variants of vsscanf for compilation or link errors. */

/* { dg-do link } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

int _vsscanf_aAcdeEfFgGnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdeEfFgGnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdeEfFnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdeEfFnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdeEgGnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdeEgGnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdeEnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdeEnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdfFgGnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdfFgGnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdfFnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdfFnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdgGnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdgGnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAcdnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAeEfFgGs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAeEfFgG (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAeEfFs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAeEfF (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAeEgGs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAeEgG (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAeEs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAeE (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAfFgGs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAfFgG (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAfFs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAfF (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAgGs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAgG (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aAs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_aA (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdeEfFgGnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdeEfFgGnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdeEfFnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdeEfFnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdeEgGnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdeEgGnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdeEnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdeEnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdfFgGnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdfFgGnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdfFnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdfFnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdgGnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdgGnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdnopsuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_cdnopuxX (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_eEfFgGs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_eEfFgG (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_eEfFs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_eEfF (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_eEgGs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_eEgG (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_eEs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_eE (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_fFgGs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_fFgG (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_fFs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_fF (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_gGs (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_gG (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_s (const char *__restrict, const char *__restrict, __isoc_va_list);
int _vsscanf_0 (const char *__restrict, const char *__restrict, __isoc_va_list);

int main()
{
  _vsscanf_aAcdeEfFgGnopsuxX (buf, "%a,%d,%e,%f,%g,%s", _va);
  _vsscanf_aAcdeEfFgGnopuxX (buf, "%a,%d,%e,%f,%g", _va);
  _vsscanf_aAcdeEfFnopsuxX (buf, "%a,%d,%e,%f,%s", _va);
  _vsscanf_aAcdeEfFnopuxX (buf, "%a,%d,%e,%f", _va);
  _vsscanf_aAcdeEgGnopsuxX (buf, "%a,%d,%e,%g,%s", _va);
  _vsscanf_aAcdeEgGnopuxX (buf, "%a,%d,%e,%g", _va);
  _vsscanf_aAcdeEnopsuxX (buf, "%a,%d,%e,%s", _va);
  _vsscanf_aAcdeEnopuxX (buf, "%a,%d,%e", _va);
  _vsscanf_aAcdfFgGnopsuxX (buf, "%a,%d,%f,%g,%s", _va);
  _vsscanf_aAcdfFgGnopuxX (buf, "%a,%d,%f,%g", _va);
  _vsscanf_aAcdfFnopsuxX (buf, "%a,%d,%f,%s", _va);
  _vsscanf_aAcdfFnopuxX (buf, "%a,%d,%f", _va);
  _vsscanf_aAcdgGnopsuxX (buf, "%a,%d,%g,%s", _va);
  _vsscanf_aAcdgGnopuxX (buf, "%a,%d,%g", _va);
  _vsscanf_aAcdnopsuxX (buf, "%a,%d,%s", _va);
  _vsscanf_aAcdnopuxX (buf, "%a,%d", _va);
  _vsscanf_aAeEfFgGs (buf, "%a,%e,%f,%g,%s", _va);
  _vsscanf_aAeEfFgG (buf, "%a,%e,%f,%g", _va);
  _vsscanf_aAeEfFs (buf, "%a,%e,%f,%s", _va);
  _vsscanf_aAeEfF (buf, "%a,%e,%f", _va);
  _vsscanf_aAeEgGs (buf, "%a,%e,%g,%s", _va);
  _vsscanf_aAeEgG (buf, "%a,%e,%g", _va);
  _vsscanf_aAeEs (buf, "%a,%e,%s", _va);
  _vsscanf_aAeE (buf, "%a,%e", _va);
  _vsscanf_aAfFgGs (buf, "%a,%f,%g,%s", _va);
  _vsscanf_aAfFgG (buf, "%a,%f,%g", _va);
  _vsscanf_aAfFs (buf, "%a,%f,%s", _va);
  _vsscanf_aAfF (buf, "%a,%f", _va);
  _vsscanf_aAgGs (buf, "%a,%g,%s", _va);
  _vsscanf_aAgG (buf, "%a,%g", _va);
  _vsscanf_aAs (buf, "%a,%s", _va);
  _vsscanf_aA (buf, "%a", _va);
  _vsscanf_cdeEfFgGnopsuxX (buf, "%d,%e,%f,%g,%s", _va);
  _vsscanf_cdeEfFgGnopuxX (buf, "%d,%e,%f,%g", _va);
  _vsscanf_cdeEfFnopsuxX (buf, "%d,%e,%f,%s", _va);
  _vsscanf_cdeEfFnopuxX (buf, "%d,%e,%f", _va);
  _vsscanf_cdeEgGnopsuxX (buf, "%d,%e,%g,%s", _va);
  _vsscanf_cdeEgGnopuxX (buf, "%d,%e,%g", _va);
  _vsscanf_cdeEnopsuxX (buf, "%d,%e,%s", _va);
  _vsscanf_cdeEnopuxX (buf, "%d,%e", _va);
  _vsscanf_cdfFgGnopsuxX (buf, "%d,%f,%g,%s", _va);
  _vsscanf_cdfFgGnopuxX (buf, "%d,%f,%g", _va);
  _vsscanf_cdfFnopsuxX (buf, "%d,%f,%s", _va);
  _vsscanf_cdfFnopuxX (buf, "%d,%f", _va);
  _vsscanf_cdgGnopsuxX (buf, "%d,%g,%s", _va);
  _vsscanf_cdgGnopuxX (buf, "%d,%g", _va);
  _vsscanf_cdnopsuxX (buf, "%d,%s", _va);
  _vsscanf_cdnopuxX (buf, "%d", _va);
  _vsscanf_eEfFgGs (buf, "%e,%f,%g,%s", _va);
  _vsscanf_eEfFgG (buf, "%e,%f,%g", _va);
  _vsscanf_eEfFs (buf, "%e,%f,%s", _va);
  _vsscanf_eEfF (buf, "%e,%f", _va);
  _vsscanf_eEgGs (buf, "%e,%g,%s", _va);
  _vsscanf_eEgG (buf, "%e,%g", _va);
  _vsscanf_eEs (buf, "%e,%s", _va);
  _vsscanf_eE (buf, "%e", _va);
  _vsscanf_fFgGs (buf, "%f,%g,%s", _va);
  _vsscanf_fFgG (buf, "%f,%g", _va);
  _vsscanf_fFs (buf, "%f,%s", _va);
  _vsscanf_fF (buf, "%f", _va);
  _vsscanf_gGs (buf, "%g,%s", _va);
  _vsscanf_gG (buf, "%g", _va);
  _vsscanf_s (buf, "%s", _va);
  _vsscanf_0 (buf, "%X", _va);

  return 0;
}

