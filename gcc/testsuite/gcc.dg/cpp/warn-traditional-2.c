// { dg-do compile }
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Werror=traditional -Wno-deprecated -Wno-long-long" }
/* { dg-message "some warnings being treated as errors" "" {target "*-*-*"} 0 } */
#assert x(x)         // { dg-error "suggest hiding #assert from traditional C with an indented # .-Werror=traditional." }

 #define X X         // { dg-error "traditional C ignores #define with the # indented .-Werror=traditional." }

#if 0
#elif 1              // { dg-error "suggest not using #elif in traditional C .-Werror=traditional." }
#endif

#define f(X) X
int f;               // { dg-error "function-like macro \"f\" must be used with arguments in traditional C .-Werror=traditional." }

#if 0U               // { dg-error "traditional C rejects the \"U\" suffix .-Werror=traditional." }
#endif

#if +1               // { dg-error " traditional C rejects the unary plus operator .-Werror=traditional." }
#endif

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

__CONST char *x = "\x0";     // { dg-error "the meaning of '.x' is different in traditional C .-Werror=traditional." }
__CONST char *y = "\a";      // { dg-error "the meaning of '.a' is different in traditional C .-Werror=traditional." }
__CONST char *z = "\u0F43";  // { dg-error "the meaning of '.u' is different in traditional C .-Werror=traditional." }
