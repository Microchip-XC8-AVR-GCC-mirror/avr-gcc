/* Test smart-io snprintf variant for various formats */

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"
#include "all-printf-comb.h"

void test_01() { snprintf (buf, len, QUOTE(FMT_01), ARG_01); }
void test_02() { snprintf (buf, len, QUOTE(FMT_02), ARG_02); }
void test_03() { snprintf (buf, len, QUOTE(FMT_03), ARG_03); }
void test_04() { snprintf (buf, len, QUOTE(FMT_04), ARG_04); }
void test_05() { snprintf (buf, len, QUOTE(FMT_05), ARG_05); }
void test_06() { snprintf (buf, len, QUOTE(FMT_06), ARG_06); }
void test_07() { snprintf (buf, len, QUOTE(FMT_07), ARG_07); }
void test_08() { snprintf (buf, len, QUOTE(FMT_08), ARG_08); }
void test_09() { snprintf (buf, len, QUOTE(FMT_09), ARG_09); }
void test_10() { snprintf (buf, len, QUOTE(FMT_10), ARG_10); }
void test_11() { snprintf (buf, len, QUOTE(FMT_11), ARG_11); }
void test_12() { snprintf (buf, len, QUOTE(FMT_12), ARG_12); }
void test_13() { snprintf (buf, len, QUOTE(FMT_13), ARG_13); }
void test_14() { snprintf (buf, len, QUOTE(FMT_14), ARG_14); }
void test_15() { snprintf (buf, len, QUOTE(FMT_15), ARG_15); }
void test_16() { snprintf (buf, len, QUOTE(FMT_16), ARG_16); }
void test_17() { snprintf (buf, len, QUOTE(FMT_17), ARG_17); }
void test_18() { snprintf (buf, len, QUOTE(FMT_18), ARG_18); }
void test_19() { snprintf (buf, len, QUOTE(FMT_19), ARG_19); }
void test_20() { snprintf (buf, len, QUOTE(FMT_20), ARG_20); }
void test_21() { snprintf (buf, len, QUOTE(FMT_21), ARG_21); }
void test_22() { snprintf (buf, len, QUOTE(FMT_22), ARG_22); }
void test_23() { snprintf (buf, len, QUOTE(FMT_23), ARG_23); }
void test_24() { snprintf (buf, len, QUOTE(FMT_24), ARG_24); }
void test_25() { snprintf (buf, len, QUOTE(FMT_25), ARG_25); }
void test_26() { snprintf (buf, len, QUOTE(FMT_26), ARG_26); }
void test_27() { snprintf (buf, len, QUOTE(FMT_27), ARG_27); }
void test_28() { snprintf (buf, len, QUOTE(FMT_28), ARG_28); }
void test_29() { snprintf (buf, len, QUOTE(FMT_29), ARG_29); }
void test_30() { snprintf (buf, len, QUOTE(FMT_30), ARG_30); }
void test_31() { snprintf (buf, len, QUOTE(FMT_31), ARG_31); }
void test_32() { snprintf (buf, len, QUOTE(FMT_32), ARG_32); }
void test_33() { snprintf (buf, len, QUOTE(FMT_33), ARG_33); }
void test_34() { snprintf (buf, len, QUOTE(FMT_34), ARG_34); }
void test_35() { snprintf (buf, len, QUOTE(FMT_35), ARG_35); }
void test_36() { snprintf (buf, len, QUOTE(FMT_36), ARG_36); }
void test_37() { snprintf (buf, len, QUOTE(FMT_37), ARG_37); }
void test_38() { snprintf (buf, len, QUOTE(FMT_38), ARG_38); }
void test_39() { snprintf (buf, len, QUOTE(FMT_39), ARG_39); }
void test_40() { snprintf (buf, len, QUOTE(FMT_40), ARG_40); }
void test_41() { snprintf (buf, len, QUOTE(FMT_41), ARG_41); }
void test_42() { snprintf (buf, len, QUOTE(FMT_42), ARG_42); }
void test_43() { snprintf (buf, len, QUOTE(FMT_43), ARG_43); }
void test_44() { snprintf (buf, len, QUOTE(FMT_44), ARG_44); }
void test_45() { snprintf (buf, len, QUOTE(FMT_45), ARG_45); }
void test_46() { snprintf (buf, len, QUOTE(FMT_46), ARG_46); }
void test_47() { snprintf (buf, len, QUOTE(FMT_47), ARG_47); }
void test_48() { snprintf (buf, len, QUOTE(FMT_48), ARG_48); }
void test_49() { snprintf (buf, len, QUOTE(FMT_49), ARG_49); }
void test_50() { snprintf (buf, len, QUOTE(FMT_50), ARG_50); }
void test_51() { snprintf (buf, len, QUOTE(FMT_51), ARG_51); }
void test_52() { snprintf (buf, len, QUOTE(FMT_52), ARG_52); }
void test_53() { snprintf (buf, len, QUOTE(FMT_53), ARG_53); }
void test_54() { snprintf (buf, len, QUOTE(FMT_54), ARG_54); }
void test_55() { snprintf (buf, len, QUOTE(FMT_55), ARG_55); }
void test_56() { snprintf (buf, len, QUOTE(FMT_56), ARG_56); }
void test_57() { snprintf (buf, len, QUOTE(FMT_57), ARG_57); }
void test_58() { snprintf (buf, len, QUOTE(FMT_58), ARG_58); }
void test_59() { snprintf (buf, len, QUOTE(FMT_59), ARG_59); }
void test_60() { snprintf (buf, len, QUOTE(FMT_60), ARG_60); }
void test_61() { snprintf (buf, len, QUOTE(FMT_61), ARG_61); }
void test_62() { snprintf (buf, len, QUOTE(FMT_62), ARG_62); }
void test_63() { snprintf (buf, len, QUOTE(FMT_63), ARG_63); }

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
/* { dg-final { scan-assembler-times "call _snprintf_aAcdeEfFgGnopsuxX"  63 } } */
