/* Test smart-io vprintf variant for various formats */

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"
#include "all-printf-comb.h"

void test_63() { vprintf (QUOTE(FMT_63), _va); }
void test_62() { vprintf (QUOTE(FMT_62), _va); }
void test_61() { vprintf (QUOTE(FMT_61), _va); }
void test_60() { vprintf (QUOTE(FMT_60), _va); }
void test_59() { vprintf (QUOTE(FMT_59), _va); }
void test_58() { vprintf (QUOTE(FMT_58), _va); }
void test_57() { vprintf (QUOTE(FMT_57), _va); }
void test_56() { vprintf (QUOTE(FMT_56), _va); }
void test_55() { vprintf (QUOTE(FMT_55), _va); }
void test_54() { vprintf (QUOTE(FMT_54), _va); }
void test_53() { vprintf (QUOTE(FMT_53), _va); }
void test_52() { vprintf (QUOTE(FMT_52), _va); }
void test_51() { vprintf (QUOTE(FMT_51), _va); }
void test_50() { vprintf (QUOTE(FMT_50), _va); }
void test_49() { vprintf (QUOTE(FMT_49), _va); }
void test_48() { vprintf (QUOTE(FMT_48), _va); }
void test_47() { vprintf (QUOTE(FMT_47), _va); }
void test_46() { vprintf (QUOTE(FMT_46), _va); }
void test_45() { vprintf (QUOTE(FMT_45), _va); }
void test_44() { vprintf (QUOTE(FMT_44), _va); }
void test_43() { vprintf (QUOTE(FMT_43), _va); }
void test_42() { vprintf (QUOTE(FMT_42), _va); }
void test_41() { vprintf (QUOTE(FMT_41), _va); }
void test_40() { vprintf (QUOTE(FMT_40), _va); }
void test_39() { vprintf (QUOTE(FMT_39), _va); }
void test_38() { vprintf (QUOTE(FMT_38), _va); }
void test_37() { vprintf (QUOTE(FMT_37), _va); }
void test_36() { vprintf (QUOTE(FMT_36), _va); }
void test_35() { vprintf (QUOTE(FMT_35), _va); }
void test_34() { vprintf (QUOTE(FMT_34), _va); }
void test_33() { vprintf (QUOTE(FMT_33), _va); }
void test_32() { vprintf (QUOTE(FMT_32), _va); }
void test_31() { vprintf (QUOTE(FMT_31), _va); }
void test_30() { vprintf (QUOTE(FMT_30), _va); }
void test_29() { vprintf (QUOTE(FMT_29), _va); }
void test_28() { vprintf (QUOTE(FMT_28), _va); }
void test_27() { vprintf (QUOTE(FMT_27), _va); }
void test_26() { vprintf (QUOTE(FMT_26), _va); }
void test_25() { vprintf (QUOTE(FMT_25), _va); }
void test_24() { vprintf (QUOTE(FMT_24), _va); }
void test_23() { vprintf (QUOTE(FMT_23), _va); }
void test_22() { vprintf (QUOTE(FMT_22), _va); }
void test_21() { vprintf (QUOTE(FMT_21), _va); }
void test_20() { vprintf (QUOTE(FMT_20), _va); }
void test_19() { vprintf (QUOTE(FMT_19), _va); }
void test_18() { vprintf (QUOTE(FMT_18), _va); }
void test_17() { vprintf (QUOTE(FMT_17), _va); }
void test_16() { vprintf (QUOTE(FMT_16), _va); }
void test_15() { vprintf (QUOTE(FMT_15), _va); }
void test_14() { vprintf (QUOTE(FMT_14), _va); }
void test_13() { vprintf (QUOTE(FMT_13), _va); }
void test_12() { vprintf (QUOTE(FMT_12), _va); }
void test_11() { vprintf (QUOTE(FMT_11), _va); }
void test_10() { vprintf (QUOTE(FMT_10), _va); }
void test_09() { vprintf (QUOTE(FMT_09), _va); }
void test_08() { vprintf (QUOTE(FMT_08), _va); }
void test_07() { vprintf (QUOTE(FMT_07), _va); }
void test_06() { vprintf (QUOTE(FMT_06), _va); }
void test_05() { vprintf (QUOTE(FMT_05), _va); }
void test_04() { vprintf (QUOTE(FMT_04), _va); }
void test_03() { vprintf (QUOTE(FMT_03), _va); }
void test_02() { vprintf (QUOTE(FMT_02), _va); }
void test_01() { vprintf (QUOTE(FMT_01), _va); }

int main()
{
  test_01(); test_02(); test_03(); test_04(); test_05(); test_06(); test_07();
  test_08(); test_09(); test_10(); test_11(); test_12(); test_13(); test_14();
  test_15(); test_16(); test_17(); test_18(); test_19(); test_20(); test_21();
  test_22(); test_23(); test_24(); test_25(); test_26(); test_27(); test_28();
  test_29(); test_30(); test_31(); test_32(); test_33(); test_34(); test_35();
  test_36(); test_37(); test_38(); test_39(); test_40(); test_41(); test_42();
  test_43(); test_44(); test_45(); test_46(); test_47(); test_48(); test_49();
  test_50(); test_51(); test_52(); test_53(); test_54(); test_55(); test_56(); 
  test_57(); test_58(); test_59(); test_60(); test_61(); test_62(); test_63();
  return 0;
}

/* { dg-final { scan-assembler-times "call _vprintf_s"  1 } } */
/* { dg-final { scan-assembler-times "call _vprintf_gGs"  2 } } */
/* { dg-final { scan-assembler-times "call _vprintf_fFgGs"  4 } } */
/* { dg-final { scan-assembler-times "call _vprintf_eEfFgGs"  8 } } */
/* { dg-final { scan-assembler-times "call _vprintf_cdeEfFgGnopsuxX"  16 } } */
/* { dg-final { scan-assembler-times "call _vprintf_aAcdeEfFgGnopsuxX"  32 } } */
