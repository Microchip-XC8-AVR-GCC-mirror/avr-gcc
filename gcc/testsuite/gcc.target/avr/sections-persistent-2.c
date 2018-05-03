/* Verify diagnostics related to persistent attribute.  */
/* { dg-do compile } */
/* { dg-options "" } */

#ifndef __persistent
#define __persistent __attribute__((persistent))
#endif

__persistent const int var1; /* { dg-error "read only variables can not be specified as persistent" } */
__persistent int var2 = 10; /* { dg-error "persistent qualified variables should not be initialized" } */
__flash const int __persistent var3; /* { dg-warning "'persistent' attribute can not be applied to flash address space variables" } */
__persistent int const __flash var4;  /* { dg-warning "'persistent' attribute can not be applied to flash address space variables" } */

int __persistent func ()  /* { dg-warning "'persistent' attribute only applies to variables" } */
{
  __persistent short volatile lvar1; /* { dg-warning "'persistent' attribute only applies to static duration variables" } */
}

int main ()
{
  func();
  return 0;
}

