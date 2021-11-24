/* { dg-do compile } */
/* { dg-options "-Os"  } */
void __attribute__((__signal__, __interrupt__)) __vector_1 (void) {
   asm ("ret");
}
