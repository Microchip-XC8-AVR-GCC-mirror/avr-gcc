/* Test smart-io snprintf variant for various formats */

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"
#include "all-printf-comb.h"

void test_127() { snprintf (buf, len, QUOTE(FMT_127), ARG_127); }
void test_126() { snprintf (buf, len, QUOTE(FMT_126), ARG_126); }
void test_125() { snprintf (buf, len, QUOTE(FMT_125), ARG_125); }
void test_124() { snprintf (buf, len, QUOTE(FMT_124), ARG_124); }
void test_123() { snprintf (buf, len, QUOTE(FMT_123), ARG_123); }
void test_122() { snprintf (buf, len, QUOTE(FMT_122), ARG_122); }
void test_121() { snprintf (buf, len, QUOTE(FMT_121), ARG_121); }
void test_120() { snprintf (buf, len, QUOTE(FMT_120), ARG_120); }
void test_119() { snprintf (buf, len, QUOTE(FMT_119), ARG_119); }
void test_118() { snprintf (buf, len, QUOTE(FMT_118), ARG_118); }
void test_117() { snprintf (buf, len, QUOTE(FMT_117), ARG_117); }
void test_116() { snprintf (buf, len, QUOTE(FMT_116), ARG_116); }
void test_115() { snprintf (buf, len, QUOTE(FMT_115), ARG_115); }
void test_114() { snprintf (buf, len, QUOTE(FMT_114), ARG_114); }
void test_113() { snprintf (buf, len, QUOTE(FMT_113), ARG_113); }
void test_112() { snprintf (buf, len, QUOTE(FMT_112), ARG_112); }
void test_111() { snprintf (buf, len, QUOTE(FMT_111), ARG_111); }
void test_110() { snprintf (buf, len, QUOTE(FMT_110), ARG_110); }
void test_109() { snprintf (buf, len, QUOTE(FMT_109), ARG_109); }
void test_108() { snprintf (buf, len, QUOTE(FMT_108), ARG_108); }
void test_107() { snprintf (buf, len, QUOTE(FMT_107), ARG_107); }
void test_106() { snprintf (buf, len, QUOTE(FMT_106), ARG_106); }
void test_105() { snprintf (buf, len, QUOTE(FMT_105), ARG_105); }
void test_104() { snprintf (buf, len, QUOTE(FMT_104), ARG_104); }
void test_103() { snprintf (buf, len, QUOTE(FMT_103), ARG_103); }
void test_102() { snprintf (buf, len, QUOTE(FMT_102), ARG_102); }
void test_101() { snprintf (buf, len, QUOTE(FMT_101), ARG_101); }
void test_100() { snprintf (buf, len, QUOTE(FMT_100), ARG_100); }
void test_99() { snprintf (buf, len, QUOTE(FMT_99), ARG_99); }
void test_98() { snprintf (buf, len, QUOTE(FMT_98), ARG_98); }
void test_97() { snprintf (buf, len, QUOTE(FMT_97), ARG_97); }
void test_96() { snprintf (buf, len, QUOTE(FMT_96), ARG_96); }
void test_95() { snprintf (buf, len, QUOTE(FMT_95), ARG_95); }
void test_94() { snprintf (buf, len, QUOTE(FMT_94), ARG_94); }
void test_93() { snprintf (buf, len, QUOTE(FMT_93), ARG_93); }
void test_92() { snprintf (buf, len, QUOTE(FMT_92), ARG_92); }
void test_91() { snprintf (buf, len, QUOTE(FMT_91), ARG_91); }
void test_90() { snprintf (buf, len, QUOTE(FMT_90), ARG_90); }
void test_89() { snprintf (buf, len, QUOTE(FMT_89), ARG_89); }
void test_88() { snprintf (buf, len, QUOTE(FMT_88), ARG_88); }
void test_87() { snprintf (buf, len, QUOTE(FMT_87), ARG_87); }
void test_86() { snprintf (buf, len, QUOTE(FMT_86), ARG_86); }
void test_85() { snprintf (buf, len, QUOTE(FMT_85), ARG_85); }
void test_84() { snprintf (buf, len, QUOTE(FMT_84), ARG_84); }
void test_83() { snprintf (buf, len, QUOTE(FMT_83), ARG_83); }
void test_82() { snprintf (buf, len, QUOTE(FMT_82), ARG_82); }
void test_81() { snprintf (buf, len, QUOTE(FMT_81), ARG_81); }
void test_80() { snprintf (buf, len, QUOTE(FMT_80), ARG_80); }
void test_79() { snprintf (buf, len, QUOTE(FMT_79), ARG_79); }
void test_78() { snprintf (buf, len, QUOTE(FMT_78), ARG_78); }
void test_77() { snprintf (buf, len, QUOTE(FMT_77), ARG_77); }
void test_76() { snprintf (buf, len, QUOTE(FMT_76), ARG_76); }
void test_75() { snprintf (buf, len, QUOTE(FMT_75), ARG_75); }
void test_74() { snprintf (buf, len, QUOTE(FMT_74), ARG_74); }
void test_73() { snprintf (buf, len, QUOTE(FMT_73), ARG_73); }
void test_72() { snprintf (buf, len, QUOTE(FMT_72), ARG_72); }
void test_71() { snprintf (buf, len, QUOTE(FMT_71), ARG_71); }
void test_70() { snprintf (buf, len, QUOTE(FMT_70), ARG_70); }
void test_69() { snprintf (buf, len, QUOTE(FMT_69), ARG_69); }
void test_68() { snprintf (buf, len, QUOTE(FMT_68), ARG_68); }
void test_67() { snprintf (buf, len, QUOTE(FMT_67), ARG_67); }
void test_66() { snprintf (buf, len, QUOTE(FMT_66), ARG_66); }
void test_65() { snprintf (buf, len, QUOTE(FMT_65), ARG_65); }
void test_64() { snprintf (buf, len, QUOTE(FMT_64), ARG_64); }
void test_63() { snprintf (buf, len, QUOTE(FMT_63), ARG_63); }
void test_62() { snprintf (buf, len, QUOTE(FMT_62), ARG_62); }
void test_61() { snprintf (buf, len, QUOTE(FMT_61), ARG_61); }
void test_60() { snprintf (buf, len, QUOTE(FMT_60), ARG_60); }
void test_59() { snprintf (buf, len, QUOTE(FMT_59), ARG_59); }
void test_58() { snprintf (buf, len, QUOTE(FMT_58), ARG_58); }
void test_57() { snprintf (buf, len, QUOTE(FMT_57), ARG_57); }
void test_56() { snprintf (buf, len, QUOTE(FMT_56), ARG_56); }
void test_55() { snprintf (buf, len, QUOTE(FMT_55), ARG_55); }
void test_54() { snprintf (buf, len, QUOTE(FMT_54), ARG_54); }
void test_53() { snprintf (buf, len, QUOTE(FMT_53), ARG_53); }
void test_52() { snprintf (buf, len, QUOTE(FMT_52), ARG_52); }
void test_51() { snprintf (buf, len, QUOTE(FMT_51), ARG_51); }
void test_50() { snprintf (buf, len, QUOTE(FMT_50), ARG_50); }
void test_49() { snprintf (buf, len, QUOTE(FMT_49), ARG_49); }
void test_48() { snprintf (buf, len, QUOTE(FMT_48), ARG_48); }
void test_47() { snprintf (buf, len, QUOTE(FMT_47), ARG_47); }
void test_46() { snprintf (buf, len, QUOTE(FMT_46), ARG_46); }
void test_45() { snprintf (buf, len, QUOTE(FMT_45), ARG_45); }
void test_44() { snprintf (buf, len, QUOTE(FMT_44), ARG_44); }
void test_43() { snprintf (buf, len, QUOTE(FMT_43), ARG_43); }
void test_42() { snprintf (buf, len, QUOTE(FMT_42), ARG_42); }
void test_41() { snprintf (buf, len, QUOTE(FMT_41), ARG_41); }
void test_40() { snprintf (buf, len, QUOTE(FMT_40), ARG_40); }
void test_39() { snprintf (buf, len, QUOTE(FMT_39), ARG_39); }
void test_38() { snprintf (buf, len, QUOTE(FMT_38), ARG_38); }
void test_37() { snprintf (buf, len, QUOTE(FMT_37), ARG_37); }
void test_36() { snprintf (buf, len, QUOTE(FMT_36), ARG_36); }
void test_35() { snprintf (buf, len, QUOTE(FMT_35), ARG_35); }
void test_34() { snprintf (buf, len, QUOTE(FMT_34), ARG_34); }
void test_33() { snprintf (buf, len, QUOTE(FMT_33), ARG_33); }
void test_32() { snprintf (buf, len, QUOTE(FMT_32), ARG_32); }
void test_31() { snprintf (buf, len, QUOTE(FMT_31), ARG_31); }
void test_30() { snprintf (buf, len, QUOTE(FMT_30), ARG_30); }
void test_29() { snprintf (buf, len, QUOTE(FMT_29), ARG_29); }
void test_28() { snprintf (buf, len, QUOTE(FMT_28), ARG_28); }
void test_27() { snprintf (buf, len, QUOTE(FMT_27), ARG_27); }
void test_26() { snprintf (buf, len, QUOTE(FMT_26), ARG_26); }
void test_25() { snprintf (buf, len, QUOTE(FMT_25), ARG_25); }
void test_24() { snprintf (buf, len, QUOTE(FMT_24), ARG_24); }
void test_23() { snprintf (buf, len, QUOTE(FMT_23), ARG_23); }
void test_22() { snprintf (buf, len, QUOTE(FMT_22), ARG_22); }
void test_21() { snprintf (buf, len, QUOTE(FMT_21), ARG_21); }
void test_20() { snprintf (buf, len, QUOTE(FMT_20), ARG_20); }
void test_19() { snprintf (buf, len, QUOTE(FMT_19), ARG_19); }
void test_18() { snprintf (buf, len, QUOTE(FMT_18), ARG_18); }
void test_17() { snprintf (buf, len, QUOTE(FMT_17), ARG_17); }
void test_16() { snprintf (buf, len, QUOTE(FMT_16), ARG_16); }
void test_15() { snprintf (buf, len, QUOTE(FMT_15), ARG_15); }
void test_14() { snprintf (buf, len, QUOTE(FMT_14), ARG_14); }
void test_13() { snprintf (buf, len, QUOTE(FMT_13), ARG_13); }
void test_12() { snprintf (buf, len, QUOTE(FMT_12), ARG_12); }
void test_11() { snprintf (buf, len, QUOTE(FMT_11), ARG_11); }
void test_10() { snprintf (buf, len, QUOTE(FMT_10), ARG_10); }
void test_9() { snprintf (buf, len, QUOTE(FMT_9), ARG_9); }
void test_8() { snprintf (buf, len, QUOTE(FMT_8), ARG_8); }
void test_7() { snprintf (buf, len, QUOTE(FMT_7), ARG_7); }
void test_6() { snprintf (buf, len, QUOTE(FMT_6), ARG_6); }
void test_5() { snprintf (buf, len, QUOTE(FMT_5), ARG_5); }
void test_4() { snprintf (buf, len, QUOTE(FMT_4), ARG_4); }
void test_3() { snprintf (buf, len, QUOTE(FMT_3), ARG_3); }
void test_2() { snprintf (buf, len, QUOTE(FMT_2), ARG_2); }
void test_1() { snprintf (buf, len, QUOTE(FMT_1), ARG_1); }

int main()
{
  test_1(); test_2(); test_3(); test_4(); test_5(); test_6(); test_7();
  test_8(); test_9(); test_10(); test_11(); test_12(); test_13(); test_14();
  test_15(); test_16(); test_17(); test_18(); test_19(); test_20(); test_21();
  test_22(); test_23(); test_24(); test_25(); test_26(); test_27(); test_28();
  test_29(); test_30(); test_31(); test_32(); test_33(); test_34(); test_35();
  test_36(); test_37(); test_38(); test_39(); test_40(); test_41(); test_42();
  test_43(); test_44(); test_45(); test_46(); test_47(); test_48(); test_49();
  test_50(); test_51(); test_52(); test_53(); test_54(); test_55(); test_56(); 
  test_57(); test_58(); test_59(); test_60(); test_61(); test_62(); test_63();
  test_64(); test_65(); test_66(); test_67(); test_68(); test_69(); test_70();
  test_71(); test_72(); test_73(); test_74(); test_75(); test_76(); test_77();
  test_78(); test_79(); test_80(); test_81(); test_82(); test_83(); test_84();
  test_85(); test_86(); test_87(); test_88(); test_89(); test_90(); test_91();
  test_92(); test_93(); test_94(); test_95(); test_96(); test_97(); test_98();
  test_99(); test_100(); test_101(); test_102(); test_103(); test_104();
  test_105(); test_106(); test_107(); test_108(); test_109(); test_110();
  test_111(); test_112(); test_113(); test_114(); test_115(); test_116();
  test_117(); test_118(); test_119(); test_120(); test_121(); test_122();
  test_123(); test_124(); test_125(); test_126(); test_127();

  return 0;
}

/* { dg-final { scan-assembler-times "call _snprintf_s"  1 } } */
  /* { dg-final { scan-assembler-times "call _snprintf_ns"  2 } } */
/* { dg-final { scan-assembler-times "call _snprintf_gGns"  4 } } */
/* { dg-final { scan-assembler-times "call _snprintf_fFgGns"  8 } } */
/* { dg-final { scan-assembler-times "call _snprintf_eEfFgGns"  16 } } */
/* { dg-final { scan-assembler-times "call _snprintf_cdeEfFgGnopsuxX"  32 } } */
/* { dg-final { scan-assembler-times "call _snprintf_aAcdeEfFgGnopsuxX"  64 } } */
