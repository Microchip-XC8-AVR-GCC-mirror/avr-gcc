#!/bin/bash

powers() { eval echo $(printf "{%s,}" "$@"); }

# define is_int_variant function
# $f -> store argument passed to the script
# Check for various int type format specifiers
# Only small case handled for testcases

is_int_variant(){
    local f="$1"
    [[ "${fmt}" == *"c"* || "${fmt}" == *"d"* || "${fmt}" == *"n"* || 
       "${fmt}" == *"o"* || "${fmt}" == *"p"* || "${fmt}" == *"u"* || 
                            "${fmt}" == *"x"* || "${fmt}" == *"X"* ]] && return 0 || return 1
}

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
    #    fgsux --> %f,%g,%s,%u,%x,  --> %f,%g,%s,%u,%x
    fmt_str=$( sed 's/./%&,/g; s/,$//' <<<"$fmt")

    # Generate the variables combination for scanf.
    #    fgsux --> &f,&g,&s,&u,&x,  --> &f,&g,&s,&u,&x
    scanf_var_str=$( sed 's/./\&&,/g; s/,$//' <<<"$fmt")

    echo "$fmt_str    $scanf_var_str     $s" >> test-scanf-input.txt
    i+=1
done


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
