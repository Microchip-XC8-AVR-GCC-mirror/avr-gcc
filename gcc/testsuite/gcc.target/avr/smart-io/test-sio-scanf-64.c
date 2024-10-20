/* Test smart-io 64 variants of scanf for compilation or link errors. */

/* { dg-do link } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

int _scanf_aAcdeEfFgGnopsuxX (const char *__restrict, ...);
int _scanf_aAcdeEfFgGnopuxX (const char *__restrict, ...);
int _scanf_aAcdeEfFnopsuxX (const char *__restrict, ...);
int _scanf_aAcdeEfFnopuxX (const char *__restrict, ...);
int _scanf_aAcdeEgGnopsuxX (const char *__restrict, ...);
int _scanf_aAcdeEgGnopuxX (const char *__restrict, ...);
int _scanf_aAcdeEnopsuxX (const char *__restrict, ...);
int _scanf_aAcdeEnopuxX (const char *__restrict, ...);
int _scanf_aAcdfFgGnopsuxX (const char *__restrict, ...);
int _scanf_aAcdfFgGnopuxX (const char *__restrict, ...);
int _scanf_aAcdfFnopsuxX (const char *__restrict, ...);
int _scanf_aAcdfFnopuxX (const char *__restrict, ...);
int _scanf_aAcdgGnopsuxX (const char *__restrict, ...);
int _scanf_aAcdgGnopuxX (const char *__restrict, ...);
int _scanf_aAcdnopsuxX (const char *__restrict, ...);
int _scanf_aAcdnopuxX (const char *__restrict, ...);
int _scanf_aAeEfFgGs (const char *__restrict, ...);
int _scanf_aAeEfFgG (const char *__restrict, ...);
int _scanf_aAeEfFs (const char *__restrict, ...);
int _scanf_aAeEfF (const char *__restrict, ...);
int _scanf_aAeEgGs (const char *__restrict, ...);
int _scanf_aAeEgG (const char *__restrict, ...);
int _scanf_aAeEs (const char *__restrict, ...);
int _scanf_aAeE (const char *__restrict, ...);
int _scanf_aAfFgGs (const char *__restrict, ...);
int _scanf_aAfFgG (const char *__restrict, ...);
int _scanf_aAfFs (const char *__restrict, ...);
int _scanf_aAfF (const char *__restrict, ...);
int _scanf_aAgGs (const char *__restrict, ...);
int _scanf_aAgG (const char *__restrict, ...);
int _scanf_aAs (const char *__restrict, ...);
int _scanf_aA (const char *__restrict, ...);
int _scanf_cdeEfFgGnopsuxX (const char *__restrict, ...);
int _scanf_cdeEfFgGnopuxX (const char *__restrict, ...);
int _scanf_cdeEfFnopsuxX (const char *__restrict, ...);
int _scanf_cdeEfFnopuxX (const char *__restrict, ...);
int _scanf_cdeEgGnopsuxX (const char *__restrict, ...);
int _scanf_cdeEgGnopuxX (const char *__restrict, ...);
int _scanf_cdeEnopsuxX (const char *__restrict, ...);
int _scanf_cdeEnopuxX (const char *__restrict, ...);
int _scanf_cdfFgGnopsuxX (const char *__restrict, ...);
int _scanf_cdfFgGnopuxX (const char *__restrict, ...);
int _scanf_cdfFnopsuxX (const char *__restrict, ...);
int _scanf_cdfFnopuxX (const char *__restrict, ...);
int _scanf_cdgGnopsuxX (const char *__restrict, ...);
int _scanf_cdgGnopuxX (const char *__restrict, ...);
int _scanf_cdnopsuxX (const char *__restrict, ...);
int _scanf_cdnopuxX (const char *__restrict, ...);
int _scanf_eEfFgGs (const char *__restrict, ...);
int _scanf_eEfFgG (const char *__restrict, ...);
int _scanf_eEfFs (const char *__restrict, ...);
int _scanf_eEfF (const char *__restrict, ...);
int _scanf_eEgGs (const char *__restrict, ...);
int _scanf_eEgG (const char *__restrict, ...);
int _scanf_eEs (const char *__restrict, ...);
int _scanf_eE (const char *__restrict, ...);
int _scanf_fFgGs (const char *__restrict, ...);
int _scanf_fFgG (const char *__restrict, ...);
int _scanf_fFs (const char *__restrict, ...);
int _scanf_fF (const char *__restrict, ...);
int _scanf_gGs (const char *__restrict, ...);
int _scanf_gG (const char *__restrict, ...);
int _scanf_s (const char *__restrict, ...);
int _scanf_0 (const char *__restrict, ...);

int main()
{
  _scanf_aAcdeEfFgGnopsuxX ("%a,%d,%e,%f,%g,%s", &a,&d,&e,&f,&g,&s);
  _scanf_aAcdeEfFgGnopuxX ("%a,%d,%e,%f,%g", &a,&d,&e,&f,&g);
  _scanf_aAcdeEfFnopsuxX ("%a,%d,%e,%f,%s", &a,&d,&e,&f,&s);
  _scanf_aAcdeEfFnopuxX ("%a,%d,%e,%f", &a,&d,&e,&f);
  _scanf_aAcdeEgGnopsuxX ("%a,%d,%e,%g,%s", &a,&d,&e,&g,&s);
  _scanf_aAcdeEgGnopuxX ("%a,%d,%e,%g", &a,&d,&e,&g);
  _scanf_aAcdeEnopsuxX ("%a,%d,%e,%s", &a,&d,&e,&s);
  _scanf_aAcdeEnopuxX ("%a,%d,%e", &a,&d,&e);
  _scanf_aAcdfFgGnopsuxX ("%a,%d,%f,%g,%s", &a,&d,&f,&g,&s);
  _scanf_aAcdfFgGnopuxX ("%a,%d,%f,%g", &a,&d,&f,&g);
  _scanf_aAcdfFnopsuxX ("%a,%d,%f,%s", &a,&d,&f,&s);
  _scanf_aAcdfFnopuxX ("%a,%d,%f", &a,&d,&f);
  _scanf_aAcdgGnopsuxX ("%a,%d,%g,%s", &a,&d,&g,&s);
  _scanf_aAcdgGnopuxX ("%a,%d,%g", &a,&d,&g);
  _scanf_aAcdnopsuxX ("%a,%d,%s", &a,&d,&s);
  _scanf_aAcdnopuxX ("%a,%d", &a,&d);
  _scanf_aAeEfFgGs ("%a,%e,%f,%g,%s", &a,&e,&f,&g,&s);
  _scanf_aAeEfFgG ("%a,%e,%f,%g", &a,&e,&f,&g);
  _scanf_aAeEfFs ("%a,%e,%f,%s", &a,&e,&f,&s);
  _scanf_aAeEfF ("%a,%e,%f", &a,&e,&f);
  _scanf_aAeEgGs ("%a,%e,%g,%s", &a,&e,&g,&s);
  _scanf_aAeEgG ("%a,%e,%g", &a,&e,&g);
  _scanf_aAeEs ("%a,%e,%s", &a,&e,&s);
  _scanf_aAeE ("%a,%e", &a,&e);
  _scanf_aAfFgGs ("%a,%f,%g,%s", &a,&f,&g,&s);
  _scanf_aAfFgG ("%a,%f,%g", &a,&f,&g);
  _scanf_aAfFs ("%a,%f,%s", &a,&f,&s);
  _scanf_aAfF ("%a,%f", &a,&f);
  _scanf_aAgGs ("%a,%g,%s", &a,&g,&s);
  _scanf_aAgG ("%a,%g", &a,&g);
  _scanf_aAs ("%a,%s", &a,&s);
  _scanf_aA ("%a", a);
  _scanf_cdeEfFgGnopsuxX ("%d,%e,%f,%g,%s", &d,&e,&f,&g,&s);
  _scanf_cdeEfFgGnopuxX ("%d,%e,%f,%g", &d,&e,&f,&g);
  _scanf_cdeEfFnopsuxX ("%d,%e,%f,%s", &d,&e,&f,&s);
  _scanf_cdeEfFnopuxX ("%d,%e,%f", &d,&e,&f);
  _scanf_cdeEgGnopsuxX ("%d,%e,%g,%s", &d,&e,&g,&s);
  _scanf_cdeEgGnopuxX ("%d,%e,%g", &d,&e,&g);
  _scanf_cdeEnopsuxX ("%d,%e,%s", &d,&e,&s);
  _scanf_cdeEnopuxX ("%d,%e", &d,&e);
  _scanf_cdfFgGnopsuxX ("%d,%f,%g,%s", &d,&f,&g,&s);
  _scanf_cdfFgGnopuxX ("%d,%f,%g", &d,&f,&g);
  _scanf_cdfFnopsuxX ("%d,%f,%s", &d,&f,&s);
  _scanf_cdfFnopuxX ("%d,%f", &d,&f);
  _scanf_cdgGnopsuxX ("%d,%g,%s", &d,&g,&s);
  _scanf_cdgGnopuxX ("%d,%g", &d,&g);
  _scanf_cdnopsuxX ("%d,%s", &d,&s);
  _scanf_cdnopuxX ("%d", &d);
  _scanf_eEfFgGs ("%e,%f,%g,%s", &e,&f,&g,&s);
  _scanf_eEfFgG ("%e,%f,%g", &e,&f,&g);
  _scanf_eEfFs ("%e,%f,%s", &e,&f,&s);
  _scanf_eEfF ("%e,%f", &e,&f);
  _scanf_eEgGs ("%e,%g,%s", &e,&g,&s);
  _scanf_eEgG ("%e,%g", &e,&g);
  _scanf_eEs ("%e,%s", &e,&s);
  _scanf_eE ("%e", &e);
  _scanf_fFgGs ("%f,%g,%s", &f,&g,&s);
  _scanf_fFgG ("%f,%g", &f,&g);
  _scanf_fFs ("%f,%s", &f,&s);
  _scanf_fF ("%f", &f);
  _scanf_gGs ("%g,%s", &g,&s);
  _scanf_gG ("%g", &g);
  _scanf_s ("%s", &s);
  _scanf_0 ("%X", &X);

  return 0;
}

