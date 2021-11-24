#!/bin/bash

powers() { eval echo $(printf "{%s,}" "$@"); }

# define is_int_variant function
# $f -> store argument passed to the script
# Check for various int type format specifiers
# Only small case handled for testcases

is_int_variant(){
    local f="$1"
    [[ "${fmt}" == *"c"* || "${fmt}" == *"d"* || "${fmt}" == *"n"* || "${fmt}" == *"o"* || "${fmt}" == *"p"* || "${fmt}" == *"u"* || "${fmt}" == *"x"* || "${fmt}" == *"X"* ]] && return 0 || return 1
}

rm test-prinf-input.txt
rm test-scanf-input.txt

# all non-empty sets of these format specifiers
fmts="$(powers a d e f g s u x)"

for fmt in ${fmts}; do
    s=""

    if [[ "${fmt}" == *"a"* ]]; then
        s="${s}aA"
    fi

    if ( is_int_variant "$fmt" )
    then
        s="${s}cd"
    fi

    if [[ "${fmt}" == *"e"* ]]; then
      s="${s}eE"
    fi

    if [[ "${fmt}" == *"f"* ]]; then
      s="${s}fF"
    fi

    if [[ "${fmt}" == *"g"* ]]; then
        s="${s}gG"
    fi

    if ( is_int_variant "$fmt" )
    then
        s="${s}nop"
    fi

    if [[ "${fmt}" == *"s"* ]]; then
        s="${s}s"
    fi

    if ( is_int_variant "$fmt" )
    then
        s="${s}uxX"
    fi

    # Generate the format string.
    fmt_str=$( sed 's/./%&,/g; s/,$//' <<<"$fmt")

    # Generate the variables combination for printf.
    printf_var_str=$( sed 's/./&,/g; s/,$//' <<<"$fmt")

    # Generate the variables combination for scanf.
    scanf_var_str=$( sed 's/./\&&,/g; s/,$//' <<<"$fmt")

    echo "$fmt_str    $printf_var_str    $s" >> test-prinf-input.txt
    echo "$fmt_str    $scanf_var_str     $s" >> test-scanf-input.txt
    i+=1
done



declare -i i=1

while IFS=" " read a b c; do

  file="test-sio-printf-${i}-${c}.c"
  i+=1
echo Generating $file ...

  cat <<EOF >$file
/*
  Test smart-io printf variants : $file
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT ${a}
#define PRINT_ARG ${b}

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_$c" } } */
/* { dg-final { scan-assembler "call _fprintf_$c" } } */
/* { dg-final { scan-assembler "call _sprintf_$c" } } */
/* { dg-final { scan-assembler "call _snprintf_$c" } } */
/* { dg-final { scan-assembler "call _vprintf_$c" } } */
/* { dg-final { scan-assembler "call _vfprintf_$c" } } */
/* { dg-final { scan-assembler "call _vsprintf_$c" } } */
/* { dg-final { scan-assembler "call _vsnprintf_$c" } } */

EOF

done < test-prinf-input.txt





declare -i i=1

while IFS=" " read a b c; do

  file="test-sio-scanf-${i}-${c}.c"
  i+=1

echo Generating $file ...

  cat <<EOF >$file
/*
  Test smart-io scanf variants : $file
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT ${a}
#define SCANF_ARG ${b}

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_$c" } } */
/* { dg-final { scan-assembler "call _sscanf_$c" } } */
/* { dg-final { scan-assembler "call _fscanf_$c" } } */
/* { dg-final { scan-assembler "call _vscanf_$c" } } */
/* { dg-final { scan-assembler "call _vfscanf_$c" } } */
/* { dg-final { scan-assembler "call _vsscanf_$c" } } */

EOF

done < test-scanf-input.txt
