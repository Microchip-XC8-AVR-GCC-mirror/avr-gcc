static inline void do_bitaddress (void)
{
  *((volatile char *)0x0 + __AVR_SFR_OFFSET__) |= 1;      // sbi 0x0,0
  *((volatile char *)0xA + __AVR_SFR_OFFSET__) |= 1;      // sbi 0xa,0
  *((volatile char *)0x1F + __AVR_SFR_OFFSET__) |= 1;     // sbi 0x1f,0

  *((volatile char *)0x0 + __AVR_SFR_OFFSET__) &= 0xFE;   // cbi 0x0,0
  *((volatile char *)0xA + __AVR_SFR_OFFSET__) &= 0xFE;   // cbi 0xa,0
  *((volatile char *)0x1F + __AVR_SFR_OFFSET__) &= 0xFE;  // cbi 0x1f,0

  if (*((volatile char *)3 + __AVR_SFR_OFFSET__) & 8)     // sbis 0x3,3
    *((volatile char *)1 + __AVR_SFR_OFFSET__) |= 4;      // sbi 0x1,2
  if (!(*((volatile char *)4 + __AVR_SFR_OFFSET__) & 4))  // sbic 0x4,2
    *((volatile char *)2 + __AVR_SFR_OFFSET__) &= 0xfe;   // cbi 0x2,0
}
