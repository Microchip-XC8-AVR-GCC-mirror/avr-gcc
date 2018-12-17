/* { dg-options "-I. -Winvalid-pch -Wtrigraphs" } */

#include "valid-4.h"

__CONST char * x = "??/";  /* { dg-warning "trigraph" } */

