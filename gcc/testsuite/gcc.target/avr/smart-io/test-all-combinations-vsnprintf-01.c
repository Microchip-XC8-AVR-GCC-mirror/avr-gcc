/* Test smart-io vsnprintf variant for various formats */

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"
#include "all-printf-comb.h"

void test_1() { vsnprintf (buf, len, QUOTE(FMT_1), _va); }
void test_2() { vsnprintf (buf, len, QUOTE(FMT_2), _va); }
void test_3() { vsnprintf (buf, len, QUOTE(FMT_3), _va); }
void test_4() { vsnprintf (buf, len, QUOTE(FMT_4), _va); }
void test_5() { vsnprintf (buf, len, QUOTE(FMT_5), _va); }
void test_6() { vsnprintf (buf, len, QUOTE(FMT_6), _va); }
void test_7() { vsnprintf (buf, len, QUOTE(FMT_7), _va); }
void test_8() { vsnprintf (buf, len, QUOTE(FMT_8), _va); }
void test_9() { vsnprintf (buf, len, QUOTE(FMT_9), _va); }
void test_10() { vsnprintf (buf, len, QUOTE(FMT_10), _va); }
void test_11() { vsnprintf (buf, len, QUOTE(FMT_11), _va); }
void test_12() { vsnprintf (buf, len, QUOTE(FMT_12), _va); }
void test_13() { vsnprintf (buf, len, QUOTE(FMT_13), _va); }
void test_14() { vsnprintf (buf, len, QUOTE(FMT_14), _va); }
void test_15() { vsnprintf (buf, len, QUOTE(FMT_15), _va); }
void test_16() { vsnprintf (buf, len, QUOTE(FMT_16), _va); }
void test_17() { vsnprintf (buf, len, QUOTE(FMT_17), _va); }
void test_18() { vsnprintf (buf, len, QUOTE(FMT_18), _va); }
void test_19() { vsnprintf (buf, len, QUOTE(FMT_19), _va); }
void test_20() { vsnprintf (buf, len, QUOTE(FMT_20), _va); }
void test_21() { vsnprintf (buf, len, QUOTE(FMT_21), _va); }
void test_22() { vsnprintf (buf, len, QUOTE(FMT_22), _va); }
void test_23() { vsnprintf (buf, len, QUOTE(FMT_23), _va); }
void test_24() { vsnprintf (buf, len, QUOTE(FMT_24), _va); }
void test_25() { vsnprintf (buf, len, QUOTE(FMT_25), _va); }
void test_26() { vsnprintf (buf, len, QUOTE(FMT_26), _va); }
void test_27() { vsnprintf (buf, len, QUOTE(FMT_27), _va); }
void test_28() { vsnprintf (buf, len, QUOTE(FMT_28), _va); }
void test_29() { vsnprintf (buf, len, QUOTE(FMT_29), _va); }
void test_30() { vsnprintf (buf, len, QUOTE(FMT_30), _va); }
void test_31() { vsnprintf (buf, len, QUOTE(FMT_31), _va); }
void test_32() { vsnprintf (buf, len, QUOTE(FMT_32), _va); }
void test_33() { vsnprintf (buf, len, QUOTE(FMT_33), _va); }
void test_34() { vsnprintf (buf, len, QUOTE(FMT_34), _va); }
void test_35() { vsnprintf (buf, len, QUOTE(FMT_35), _va); }
void test_36() { vsnprintf (buf, len, QUOTE(FMT_36), _va); }
void test_37() { vsnprintf (buf, len, QUOTE(FMT_37), _va); }
void test_38() { vsnprintf (buf, len, QUOTE(FMT_38), _va); }
void test_39() { vsnprintf (buf, len, QUOTE(FMT_39), _va); }
void test_40() { vsnprintf (buf, len, QUOTE(FMT_40), _va); }
void test_41() { vsnprintf (buf, len, QUOTE(FMT_41), _va); }
void test_42() { vsnprintf (buf, len, QUOTE(FMT_42), _va); }
void test_43() { vsnprintf (buf, len, QUOTE(FMT_43), _va); }
void test_44() { vsnprintf (buf, len, QUOTE(FMT_44), _va); }
void test_45() { vsnprintf (buf, len, QUOTE(FMT_45), _va); }
void test_46() { vsnprintf (buf, len, QUOTE(FMT_46), _va); }
void test_47() { vsnprintf (buf, len, QUOTE(FMT_47), _va); }
void test_48() { vsnprintf (buf, len, QUOTE(FMT_48), _va); }
void test_49() { vsnprintf (buf, len, QUOTE(FMT_49), _va); }
void test_50() { vsnprintf (buf, len, QUOTE(FMT_50), _va); }
void test_51() { vsnprintf (buf, len, QUOTE(FMT_51), _va); }
void test_52() { vsnprintf (buf, len, QUOTE(FMT_52), _va); }
void test_53() { vsnprintf (buf, len, QUOTE(FMT_53), _va); }
void test_54() { vsnprintf (buf, len, QUOTE(FMT_54), _va); }
void test_55() { vsnprintf (buf, len, QUOTE(FMT_55), _va); }
void test_56() { vsnprintf (buf, len, QUOTE(FMT_56), _va); }
void test_57() { vsnprintf (buf, len, QUOTE(FMT_57), _va); }
void test_58() { vsnprintf (buf, len, QUOTE(FMT_58), _va); }
void test_59() { vsnprintf (buf, len, QUOTE(FMT_59), _va); }
void test_60() { vsnprintf (buf, len, QUOTE(FMT_60), _va); }
void test_61() { vsnprintf (buf, len, QUOTE(FMT_61), _va); }
void test_62() { vsnprintf (buf, len, QUOTE(FMT_62), _va); }
void test_63() { vsnprintf (buf, len, QUOTE(FMT_63), _va); }
void test_64() { vsnprintf (buf, len, QUOTE(FMT_64), _va); }
void test_65() { vsnprintf (buf, len, QUOTE(FMT_65), _va); }
void test_66() { vsnprintf (buf, len, QUOTE(FMT_66), _va); }
void test_67() { vsnprintf (buf, len, QUOTE(FMT_67), _va); }
void test_68() { vsnprintf (buf, len, QUOTE(FMT_68), _va); }
void test_69() { vsnprintf (buf, len, QUOTE(FMT_69), _va); }
void test_70() { vsnprintf (buf, len, QUOTE(FMT_70), _va); }
void test_71() { vsnprintf (buf, len, QUOTE(FMT_71), _va); }
void test_72() { vsnprintf (buf, len, QUOTE(FMT_72), _va); }
void test_73() { vsnprintf (buf, len, QUOTE(FMT_73), _va); }
void test_74() { vsnprintf (buf, len, QUOTE(FMT_74), _va); }
void test_75() { vsnprintf (buf, len, QUOTE(FMT_75), _va); }
void test_76() { vsnprintf (buf, len, QUOTE(FMT_76), _va); }
void test_77() { vsnprintf (buf, len, QUOTE(FMT_77), _va); }
void test_78() { vsnprintf (buf, len, QUOTE(FMT_78), _va); }
void test_79() { vsnprintf (buf, len, QUOTE(FMT_79), _va); }
void test_80() { vsnprintf (buf, len, QUOTE(FMT_80), _va); }
void test_81() { vsnprintf (buf, len, QUOTE(FMT_81), _va); }
void test_82() { vsnprintf (buf, len, QUOTE(FMT_82), _va); }
void test_83() { vsnprintf (buf, len, QUOTE(FMT_83), _va); }
void test_84() { vsnprintf (buf, len, QUOTE(FMT_84), _va); }
void test_85() { vsnprintf (buf, len, QUOTE(FMT_85), _va); }
void test_86() { vsnprintf (buf, len, QUOTE(FMT_86), _va); }
void test_87() { vsnprintf (buf, len, QUOTE(FMT_87), _va); }
void test_88() { vsnprintf (buf, len, QUOTE(FMT_88), _va); }
void test_89() { vsnprintf (buf, len, QUOTE(FMT_89), _va); }
void test_90() { vsnprintf (buf, len, QUOTE(FMT_90), _va); }
void test_91() { vsnprintf (buf, len, QUOTE(FMT_91), _va); }
void test_92() { vsnprintf (buf, len, QUOTE(FMT_92), _va); }
void test_93() { vsnprintf (buf, len, QUOTE(FMT_93), _va); }
void test_94() { vsnprintf (buf, len, QUOTE(FMT_94), _va); }
void test_95() { vsnprintf (buf, len, QUOTE(FMT_95), _va); }
void test_96() { vsnprintf (buf, len, QUOTE(FMT_96), _va); }
void test_97() { vsnprintf (buf, len, QUOTE(FMT_97), _va); }
void test_98() { vsnprintf (buf, len, QUOTE(FMT_98), _va); }
void test_99() { vsnprintf (buf, len, QUOTE(FMT_99), _va); }
void test_100() { vsnprintf (buf, len, QUOTE(FMT_100), _va); }
void test_101() { vsnprintf (buf, len, QUOTE(FMT_101), _va); }
void test_102() { vsnprintf (buf, len, QUOTE(FMT_102), _va); }
void test_103() { vsnprintf (buf, len, QUOTE(FMT_103), _va); }
void test_104() { vsnprintf (buf, len, QUOTE(FMT_104), _va); }
void test_105() { vsnprintf (buf, len, QUOTE(FMT_105), _va); }
void test_106() { vsnprintf (buf, len, QUOTE(FMT_106), _va); }
void test_107() { vsnprintf (buf, len, QUOTE(FMT_107), _va); }
void test_108() { vsnprintf (buf, len, QUOTE(FMT_108), _va); }
void test_109() { vsnprintf (buf, len, QUOTE(FMT_109), _va); }
void test_110() { vsnprintf (buf, len, QUOTE(FMT_110), _va); }
void test_111() { vsnprintf (buf, len, QUOTE(FMT_111), _va); }
void test_112() { vsnprintf (buf, len, QUOTE(FMT_112), _va); }
void test_113() { vsnprintf (buf, len, QUOTE(FMT_113), _va); }
void test_114() { vsnprintf (buf, len, QUOTE(FMT_114), _va); }
void test_115() { vsnprintf (buf, len, QUOTE(FMT_115), _va); }
void test_116() { vsnprintf (buf, len, QUOTE(FMT_116), _va); }
void test_117() { vsnprintf (buf, len, QUOTE(FMT_117), _va); }
void test_118() { vsnprintf (buf, len, QUOTE(FMT_118), _va); }
void test_119() { vsnprintf (buf, len, QUOTE(FMT_119), _va); }
void test_120() { vsnprintf (buf, len, QUOTE(FMT_120), _va); }
void test_121() { vsnprintf (buf, len, QUOTE(FMT_121), _va); }
void test_122() { vsnprintf (buf, len, QUOTE(FMT_122), _va); }
void test_123() { vsnprintf (buf, len, QUOTE(FMT_123), _va); }
void test_124() { vsnprintf (buf, len, QUOTE(FMT_124), _va); }
void test_125() { vsnprintf (buf, len, QUOTE(FMT_125), _va); }
void test_126() { vsnprintf (buf, len, QUOTE(FMT_126), _va); }
void test_127() { vsnprintf (buf, len, QUOTE(FMT_127), _va); }

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

/* { dg-final { scan-assembler-times "call _vsnprintf_aAcdeEfFgGnopsuxX"  127 } } */
  