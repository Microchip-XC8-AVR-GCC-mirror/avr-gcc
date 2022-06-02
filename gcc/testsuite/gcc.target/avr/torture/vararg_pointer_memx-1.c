/* { dg-do run } */
/* { dg-options "-std=gnu99" } */
/* { dg-skip-if "Too big to fit for AVRTINY" { "avr-*-*" } { "-mmcu=attiny40" } { "" } } */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char body[5];
    char a[] = "ab";
    char b[] = "c";
    snprintf(body, sizeof(body), "%s%s", a, b);
    if (strncmp(body, "abc", 3) != 0)
      abort();
    int d = 6;
    int e = 12;
    snprintf(body, sizeof(body), "%d%d", d, e);
    if (strncmp(body, "612", 3) != 0)
      abort();

    exit(0);
}
