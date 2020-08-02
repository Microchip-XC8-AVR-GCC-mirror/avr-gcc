/* Verify that user defined section names are emitted with progmem* sections.
*/

/* { dg-do compile } */
/* { dg-options "-mext=cci" } */
/* { dg-skip-if "Skip if global option is to enable const data in progmem" { *-*-* } { "-mconst-data-in-progmem" } { "" } } */

#include<xc.h>
#include <avr/pgmspace.h>

__flash const int F1 = 100;
__flash const int F2 = 0;

__section("S01") __flash const int S1_01 = 100;
__section("S01") __flash const int S1_02 = 0;

__at(0xA14) __section("S02") __flash const int SA1_01 = 100;
__at(0xA24) __section("S04") __flash const int SA1_02 = 0;


PROGMEM const int P1 = 100;
PROGMEM const int P2 = 0;

__section("P01") PROGMEM const int P1_01 = 100;
__section("P01") PROGMEM const int P1_02 = 0;

__at(0xA34) __section("P02") PROGMEM const int SAP1_01 = 100;
__at(0xA44) __section("P04") PROGMEM const int SAP1_02 = 0;


__at(0xA54) __flash const int AP1_01 = 100;
__at(0xA64) PROGMEM const int AP1_02 = 0;


void main()
{}


/* { dg-final { scan-assembler "\t\.section\t\.progmem0\.data,progmem0" } } */
/* { dg-final { scan-assembler "\t\.section\t.progmem0\.data,progmem0" } } */
/* { dg-final { scan-assembler "\t\.section\tS01,progmem0" } } */
/* { dg-final { scan-assembler "\t\.section\tS01,progmem0" } } */
/* { dg-final { scan-assembler "\t\.section\tS02,progmem0,address\\(0xa14\\)" } } */
/* { dg-final { scan-assembler "\t\.section\tS04,progmem0,address\\(0xa24\\)" } } */
/* { dg-final { scan-assembler "\t\.section\tprogmem\.data,progmem" } } */
/* { dg-final { scan-assembler "\t\.section\tprogmem\.data,progmem" } } */
/* { dg-final { scan-assembler "\t\.section\tP01,progmem" } } */
/* { dg-final { scan-assembler "\t\.section\tP01,progmem" } } */
/* { dg-final { scan-assembler "\t\.section\tP02,progmem,address\\(0xa34\\)" } } */
/* { dg-final { scan-assembler "\t\.section\tP04,progmem,address\\(0xa44\\)" } } */
/* { dg-final { scan-assembler "\t\.section\t\\*_\[0-9a-f\]+,progmem0,address\\(0xa54\\)" } } */
/* { dg-final { scan-assembler "\t\.section\t\\*_\[0-9a-f\]+,progmem,address\\(0xa64\\)" } } */
