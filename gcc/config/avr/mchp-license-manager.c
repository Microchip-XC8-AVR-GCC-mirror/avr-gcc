/* Subroutines used for Microchip AVR code generation.
   Copyright (C) 1989, 1990, 1991, 1993, 1994, 1995, 1996, 1997, 1998,
   1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007
   Free Software Foundation, Inc.
   Contributed by Rathish C (rathish.chamukuttan@microchip.com)

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "insn-config.h"
#include "conditions.h"
#include "insn-attr.h"
#include "insn-codes.h"
#include "flags.h"
#include "reload.h"
#include "hash-set.h"
#include "machmode.h"
#include "vec.h"
#include "double-int.h"
#include "input.h"
#include "alias.h"
#include "symtab.h"
#include "wide-int.h"
#include "inchash.h"
#include "tree.h"
#include "fold-const.h"
#include "varasm.h"
#include "print-tree.h"
#include "calls.h"
#include "stor-layout.h"
#include "stringpool.h"
#include "output.h"
#include "hashtab.h"
#include "function.h"
#include "statistics.h"
#include "real.h"
#include "fixed-value.h"
#include "expmed.h"
#include "dojump.h"
#include "explow.h"
#include "emit-rtl.h"
#include "stmt.h"
#include "expr.h"
#include "c-family/c-common.h"
#include "c-family/c-pragma.h"
#include "diagnostic-core.h"
#include "obstack.h"
#include "recog.h"
#include "optabs.h"
#include "ggc.h"
#include "langhooks.h"
#include "tm_p.h"
#include "target.h"
#include "target-def.h"
#include "params.h"
#include "dominance.h"
#include "cfg.h"
#include "cfgrtl.h"
#include "cfganal.h"
#include "lcm.h"
#include "cfgbuild.h"
#include "cfgcleanup.h"
#include "predict.h"
#include "basic-block.h"
#include "df.h"
#include "context.h"
#include "tree-pass.h"
#include "opts.h"
#include "version.h"

#define XCLM_FULL_CHECKOUT 1
#if !defined(SKIP_LICENSE_MANAGER)
#include "xclm_public.h"
#include "mchp_sha.h"
#else
#define MCHP_XCLM_NO_CCOV_LICENSE 0x8
#endif  /* SKIP_LICENSE_MANAGER */


#ifndef MCHP_XCLM_FREE_LICENSE
 #define MCHP_XCLM_FREE_LICENSE 0x0
 #warning MCHP_XCLM_FREE_LICENSE not defined by API
#endif

/* Static Variables to modify the optimizatrion option levels */

static int nullify_Os = 0;
static int nullify_O3 = 0;
static int nullify_lto = 0;
//static const char *invalid = (const char*) "invalid";

static const char *disabled_option_message = NULL;
static int message_displayed = 0;
static int message_purchase_display = 0;
static const char *invalid_license = "due to an invalid XC8 license";

#define NULLIFY(X,S) \
    if (X) { \
      if ((S != NULL) && (disabled_option_message == NULL)) { \
          disabled_option_message = S; \
          message_displayed++;         \
        } \
    } \
    X

#define xstr(s) str(s)
#define str(s) #s

/* DO NOT SUPPORT license.conf */
#undef MCHP_USE_LICENSE_CONF

#ifdef MCHP_USE_LICENSE_CONF
#define MCHP_LICENSE_CONF_FILENAME "license.conf"
#define MCHP_LICENSEPATH_MARKER "license_dir"
#endif /* MCHP_USE_LICENSE_CONF */


/* Set the License manager */

#ifdef __MINGW32__
#define MCHP_MAX_LICENSEPATH_LINE_LENGTH 1024
#define MCHP_XCLM_FILENAME "xclm.exe"
#else
#define MCHP_XCLM_FILENAME "xclm"
#endif /* __MINGW32__*/


/* TBD = "to be defined" meaning that the license status is unresolved yet */
#define MCHP_LICENSE_TBD -1

#ifdef SKIP_LICENSE_MANAGER
#if defined(MCHP_XCLM_VALID_PRO_LICENSE)
  HOST_WIDE_INT mchp_avr_license_valid = MCHP_XCLM_VALID_PRO_LICENSE;
#else
  HOST_WIDE_INT mchp_avr_license_valid = 0x2;
#endif /* MCHP_XCLM_VALID_PRO_LICENSE */

#if defined(MCHP_XCLM_VALID_CCOV_LICENSE)
  HOST_WIDE_INT mchp_xccov_license_valid = MCHP_XCLM_VALID_CCOV_LICENSE;
#else
  HOST_WIDE_INT mchp_xccov_license_valid = 0x9;
#endif /* MCHP_XCLM_VALID_CCOV_LICENSE */
#else
HOST_WIDE_INT mchp_avr_license_valid = MCHP_LICENSE_TBD;
HOST_WIDE_INT mchp_xccov_license_valid = MCHP_LICENSE_TBD;
#endif /* SKIP_LICENSE_MANAGER*/


#ifndef SKIP_LICENSE_MANAGER

static char*
get_license_manager_path (void)
{
  extern struct cl_decoded_option *save_decoded_options;
  char *xclmpath = NULL;
  char* bindir = NULL;
  FILE *fptr = NULL;
  struct stat filestat;
  int xclmpath_length;

#ifdef MCHP_USE_LICENSE_CONF
  char *conf_dir, *conf_fname;
  FILE *fptr = NULL;
  char line [MCHP_MAX_LICENSEPATH_LINE_LENGTH] = {0};

  /* MCHP_LICENSE_CONF_FILENAME must reside in the same directory as xc32-gcc */
  conf_dir = make_relative_prefix(save_decoded_options[0].arg,
                                  "/libexec/gcc/avr/"
                                  str(BUILDING_GCC_MAJOR) "."
                                  str(BUILDING_GCC_MINOR) "."
                                  str(BUILDING_GCC_PATCHLEVEL),
                                  "/../bin/");

  /* alloc space for the filename: directory + '/' + MCHP_LICENSE_CONF_FILENAME
   */
  conf_fname = (char*)alloca (strlen (conf_dir) + 1 +
                              strlen (MCHP_LICENSE_CONF_FILENAME) + 1);
  strcpy (conf_fname, conf_dir);
  if (conf_fname [strlen (conf_fname) - 1] != '/'
      && conf_fname [strlen (conf_fname) - 1] != '\\')
    strcat (conf_fname, "/");
  strcat (conf_fname, MCHP_LICENSE_CONF_FILENAME);

  if ((fptr = fopen (conf_fname, "rb")) != NULL)
    {
      while (get_line (line, sizeof (line), fptr) != NULL)
        {
          char *pch0, *pch1;
          /* Find the line with the license directory */
          if (strstr (line, MCHP_LICENSEPATH_MARKER))
            {
              /* Find the quoted string on that line */
              pch0 = strchr (line,'"') +1;
              pch1 = strrchr (line,'"');
              if ((pch1-pch0) > 2)
                strncpy (xclmpath, pch0, pch1-pch0);
              break;
            }
        }
      /* Append the xclm executable name to the directory. */
      if (xclmpath [strlen (xclmpath) - 1] != '/'
          && xclmpath [strlen (xclmpath) - 1] != '\\')
        strcat (xclmpath, "/");
      strcat (xclmpath, MCHP_XCLM_FILENAME);

    }

  if (fptr != NULL)
    {
      fclose (fptr);
      fptr = NULL;
    }
#endif /* MCHP_USE_LICENSE_CONF */

#ifdef MCHP_USE_LICENSE_CONF
  if (-1 == stat (xclmpath, &filestat))
#endif /* MCHP_USE_LICENSE_CONF */
    {
      /*  Try the compiler bin directory.
       *
       */
      bindir = make_relative_prefix(save_decoded_options[0].arg,
                                          "/libexec/gcc/avr/"
                                          str(BUILDING_GCC_MAJOR) "."
                                          str(BUILDING_GCC_MINOR) "."
                                          str(BUILDING_GCC_PATCHLEVEL),
                                          "/../bin/");
#if defined(MCHP_DEBUG)
      fprintf(stderr, "bindir = %s\n", bindir);
#endif

      xclmpath_length = strlen(bindir) + 1 + strlen(MCHP_XCLM_FILENAME) + 1;
      xclmpath = (char*)xcalloc(xclmpath_length+1,sizeof(char));
      strncpy (xclmpath, bindir, xclmpath_length);
      /* Append the xclm executable name to the directory. */
      if (xclmpath [strlen (xclmpath) - 1] != '/'
          && xclmpath [strlen (xclmpath) - 1] != '\\')
        strcat (xclmpath, "/");
      strcat (xclmpath, MCHP_XCLM_FILENAME);

      if (-1 == stat (xclmpath, &filestat))
        {
          free (xclmpath);
          /*  Try the old common directory
           */
          xclmpath_length = strlen("/opt/Microchip/xclm/bin/") + strlen(MCHP_XCLM_FILENAME) + 1;
          xclmpath = (char*)xcalloc(xclmpath_length+1,sizeof(char));
          strncpy (xclmpath, "/opt/Microchip/xclm/bin/", xclmpath_length);
          /* Append the xclm executable name to the directory. */
          strcat (xclmpath, MCHP_XCLM_FILENAME);
        }
      if (-1 == stat (xclmpath, &filestat))
        {
          /*  Try the build directory
           */
          strncpy (xclmpath, "/build/xc8/xclm/bin/", xclmpath_length);
          /* Append the xclm executable name to the directory. */
          strcat (xclmpath, MCHP_XCLM_FILENAME);
        }
    }

#if defined(__MINGW32__)
  {
    char *convert;
    convert = xclmpath;
    while (*convert != '\0')
      {
        if (*convert == '\\')
          *convert = '/';
        convert++;
      }
  }
#endif /* __MINGW32__ */

  if (-1 == stat (xclmpath, &filestat))
    return NULL;

#if defined(MCHP_DEBUG)
  fprintf (stderr, "%d Final xclmpath: %s\n", __LINE__, xclmpath);
#endif /* MCHP_DEBUG */
  return xclmpath;
}
#ifdef MCHP_USE_LICENSE_CONF
#undef MCHP_MAX_LICENSEPATH_LINE_LENGTH
#undef MCHP_LICENSE_CONF_FILENAME
#undef MCHP_LICENSEPATH_MARKER
#endif /* MCHP_USE_LICENSE_CONF */

#undef MCHP_XCLM_FILENAME

#endif /* SKIP_LICENSE_MANAGER */

/* Misc. Return Codes */
#ifndef MCHP_XCLM_EXPIRED_DEMO
#define MCHP_XCLM_EXPIRED_DEMO 0x10
#endif /* MCHP_XCLM_EXPIRED_DEMO*/

#if defined(MCHP_XCLM_VALID_STANDARD_LICENSE)
#define AVR_EXPIRED_LICENSE        MCHP_XCLM_EXPIRED_DEMO
#define AVR_FREE_LICENSE           MCHP_XCLM_FREE_LICENSE
#define AVR_VALID_STANDARD_LICENSE MCHP_XCLM_VALID_STANDARD_LICENSE
#define AVR_VALID_PRO_LICENSE      MCHP_XCLM_VALID_PRO_LICENSE
#else
#define AVR_EXPIRED_LICENSE        MCHP_XCLM_EXPIRED_DEMO
#define AVR_FREE_LICENSE           0
#define AVR_VALID_STANDARD_LICENSE 1
#define AVR_VALID_PRO_LICENSE      2
#endif /* MCHP_XCLM_VALID_PRO_LICENSE */

static int
avr_get_license (bool xccov)
{
  /* If license type already determined for the corresponding product, 
     just return it */
  HOST_WIDE_INT license_type = xccov ? mchp_xccov_license_valid
                           : mchp_avr_license_valid ;
  if (license_type != MCHP_LICENSE_TBD)
  {
    return license_type;
  }

  if (!xccov && avr_mafrlcsj)
    return AVR_VALID_PRO_LICENSE;

  /* assume free/no license for now */
  license_type = xccov ? MCHP_XCLM_NO_CCOV_LICENSE : MCHP_XCLM_FREE_LICENSE;

  /*
   *  On systems where we have a licence manager, call it
   */

#ifndef SKIP_LICENSE_MANAGER
  {
    char *exec;
#if XCLM_FULL_CHECKOUT
    char kopt[] = "-fcfc";
    char kopt_analysis[] = "-fc";
#else
    char kopt[] = "-checkout";
#endif /* XCLM_FULL_CHECKOUT */
    char productc[] = "swxc8";
    char xccov_product[] = "swanaly";
    char version[9] = "1.0"; /* 1.0 works for xccov; for xc8, the version is determined below */
    char date[] = __DATE__;

#if XCLM_FULL_CHECKOUT
    char * args[] = { NULL, NULL, NULL, NULL, NULL, NULL};
#else
    char * args[] = { NULL, NULL, NULL, NULL, NULL};
#endif /* XCLM_FULL_CHECKOUT */

    //char *err_msg=(char*)"", *err_arg=(char*)"";
    const char *failure = NULL;
    int status = 0;
    int err = 0;
    int major_ver =0, minor_ver=0;
    //extern struct cl_decoded_option *save_decoded_options;
    struct stat filestat;
    int found_xclm = 0, xclm_tampered = 1;

    /* Get the version number string from the entire version string */
    if (!xccov && (version_string != NULL) && *version_string)
      {
        char *Microchip;
        gcc_assert(strlen(version_string) < 80);
        Microchip = strrchr ((char*)version_string, 'v');
        if (Microchip)
          {
            while ((*Microchip) &&
                   ((*Microchip < '0') ||
                    (*Microchip > '9')))
              {
                Microchip++;
              }
            if (*Microchip)
              {
                major_ver = strtol (Microchip, &Microchip, 0);
              }
            if ((*Microchip) &&
                ((*Microchip=='_') || (*Microchip=='.')))
              {
                Microchip++;
                minor_ver = strtol(Microchip, &Microchip, 0);
              }
          }
        snprintf (version, 6, "%d.%02d", major_ver, minor_ver);
      }

    /* Arguments to pass to xclm */
    args[1] = xccov ? kopt_analysis : kopt;
    args[2] = xccov ? xccov_product : productc;
    args[3] = version;
    
#if XCLM_FULL_CHECKOUT
	if (!xccov)
      args[4] = date;
#endif /* XCLM_FULL_CHECKOUT */

    /* Get a path to the license manager to try */
    exec = get_license_manager_path();

#if defined(MCHP_DEBUG)
    fprintf (stderr, "exec is %s\n", exec);
#endif

    if (exec == NULL)
      {
         /*Set free edition if the license manager isn't available.*/
        license_type = AVR_FREE_LICENSE;
        warning (0, "Could not retrieve compiler license");
        inform (input_location, "Please reinstall the compiler");
      }
    else if (-1 == stat (exec, &filestat))
      {
         /*Set free edition if the license manager execution fails. */
        license_type = AVR_FREE_LICENSE;
        warning (0, "Could not retrieve compiler license");
        inform (input_location, "Please reinstall the compiler");
      }
    else
      {
        /* Found xclm */
          found_xclm = 1;
      }

#undef xstr
#undef str
#undef MCHP_XCLM_SHA256_DIGEST_QUOTED

#define xstr(s) str(s)
#define str(s) #s

#define MCHP_XCLM_SHA256_DIGEST_QUOTED xstr(MCHP_XCLM_SHA256_DIGEST)

    /* Verify SHA sum and call xclm to determine the license */
    if (found_xclm &&
        (mchp_avr_license_valid == -1 || mchp_xccov_license_valid == -1) &&
        !TARGET_SKIP_LICENSE_CHECK)
      {
        /* Verify that xclm executable is untampered */
        xclm_tampered = mchp_sha256_validate(exec, (const unsigned char*)MCHP_XCLM_SHA256_DIGEST_QUOTED);
        if (xclm_tampered != 0)
          {
            /* Set free edition if the license manager SHA digest does not
               match. The free edition disables optimization options without an
               eval period. */
            license_type = AVR_FREE_LICENSE;
            warning (0, "Detected corrupt executable file");
            inform (input_location, "Please reinstall the compiler");
          }
        else
          {
            args[0] = exec;
            failure = pex_one(0, exec, args, "MPLAB XC8 Compiler", 0, 0, &status, &err);

            if (failure != NULL)
              {
                /* Set free edition if the license manager isn't available.
                   The free edition disables optimization options without an
                   eval period. */
                license_type = AVR_FREE_LICENSE;
                warning (0, "Could not retrieve compiler license (%s)", failure);
                inform (input_location, "Please reinstall the compiler");
              }
            else if (WIFEXITED(status))
              {
                license_type = WEXITSTATUS(status);
              }
          }
      }
  }
#undef xstr
#undef str
#undef MCHP_XCLM_SHA256_DIGEST_QUOTED

#endif /* SKIP_LICENSE_MANAGER */

  return license_type ;
}


/* xc-coverage.c uses this to check for a valid codecov license.
   XCLM 3.02 introduces an analysis license (MCHP_XCLM_VALID_ANATS_LICENSE),
   and does the heavy lifting of checking for either that or a ccov license
   internally. Just extend check to allow ccov if analysis license is valid. */
int
avr_licensed_xccov_p ()
{
#ifdef SKIP_LICENSE_MANAGER
#if defined(MCHP_XCLM_VALID_CCOV_LICENSE)
  return mchp_xccov_license_valid == MCHP_XCLM_VALID_CCOV_LICENSE
	|| mchp_xccov_license_valid == MCHP_XCLM_VALID_ANATS_LICENSE;
#else
  return mchp_xccov_license_valid == 0x9
	|| mchp_xccov_license_valid == 0xB;
#endif
#else
  return mchp_xccov_license_valid == MCHP_XCLM_VALID_CCOV_LICENSE
	|| mchp_xccov_license_valid == MCHP_XCLM_VALID_ANATS_LICENSE;
#endif
}

void avr_override_options_after_change(void) {
    if (nullify_Os)
      {
        /* Disable -Os optimization(s) */
        /* flag_web and flag_inline_functions already disabled */
        if (optimize_size)
          {
            optimize = 2;
          }
        NULLIFY(optimize_size, "Optimize for size") = 0;
      }
    if (nullify_O3)
      {
        if (optimize >= 3)
          {
            NULLIFY(optimize, "Optimization level > 2") = 2;
          }
        /* Disable -O3 optimizations */
        NULLIFY(flag_predictive_commoning, "predictive commoning") = 0;
        NULLIFY(flag_inline_functions, "inline functions") = 0;
        NULLIFY(flag_unswitch_loops, "unswitch loops") = 0;
        NULLIFY(flag_gcse_after_reload, "gcse after reload") = 0;
        NULLIFY(flag_tree_vectorize, "tree vectorize") = 0;
        NULLIFY(flag_ipa_cp_clone, "ipa cp clone") = 0;
        flag_ipa_cp = 0;
       }

    if (nullify_lto)
      {
        NULLIFY(flag_lto, "Link-time optimization") = 0;
        NULLIFY(flag_whole_program, "Whole-program optimizations") = 0;
        NULLIFY(flag_generate_lto, "Link-time optimization") = 0;
      }
}

static void mchp_print_license_warning (void)
{
    switch (mchp_avr_license_valid)
      {
      case AVR_EXPIRED_LICENSE:
        invalid_license = "because the XC8 evaluation period has expired";
        break;
      case AVR_FREE_LICENSE:
      case AVR_VALID_STANDARD_LICENSE:
        invalid_license = "because this feature requires the MPLAB XC8 PRO compiler";
        break;
      default:
        invalid_license = "due to an invalid XC8 license";
        break;
      }

    if (message_displayed && TARGET_LICENSE_WARNING)
      {
        /* Display a warning for the Standard option first */
        if (disabled_option_message != NULL)
          warning (0,"Compiler option (%s) ignored %s",
                   disabled_option_message, invalid_license);
        disabled_option_message = NULL;
        message_purchase_display++;
      }
}

void avr_override_licensed_options (void)
{
 
  extern struct cl_decoded_option *save_decoded_options;

#ifndef SKIP_LICENSE_MANAGER
  nullify_O3     = 1;
  nullify_Os     = 1;
  nullify_lto    = 1;
#endif /* SKIP_LICENSE_MANAGER */

  if (TARGET_SKIP_LICENSE_CHECK) {
    TARGET_LICENSE_WARNING = 0;
  }

  if (TARGET_SKIP_LICENSE_CHECK)
  {
    mchp_avr_license_valid = AVR_FREE_LICENSE;
    mchp_xccov_license_valid = MCHP_XCLM_NO_CCOV_LICENSE;
  }
  else 
  {
    mchp_avr_license_valid   = avr_get_license (0);
    mchp_xccov_license_valid = avr_get_license (1);
  }

  if ((mchp_avr_license_valid == AVR_VALID_STANDARD_LICENSE) ||
      (mchp_avr_license_valid == AVR_VALID_PRO_LICENSE))
  {
    nullify_lto = nullify_O3 = nullify_Os = 0;
  }

  if (mchp_avr_license_valid != AVR_VALID_PRO_LICENSE)
	{
      NULLIFY(avr_mchp_stack_guidance, "Report stack usage guidance") = 0;
	}

  if (avr_mchp_stack_guidance)
	flag_stack_usage_info = 1;

  /*
   *  On systems where we have a licence manager, call it
   */

  {
    /*
     * Prior to v1.40 (gcc upgrade from 4.5.2 to 4.8.3),
     * mchp_override_options_after_change() was called from optimization_option()
     * through OPTIMIZATION_OPTION target macro which is poisoned in 4.8.3. Hence
     * optimization_option() was removed. Call to  mchp_override_options_after_change()
     * added here to fix XC32-546
     */

    avr_override_options_after_change();
    if (TARGET_LICENSE_WARNING)
    {
      mchp_print_license_warning();
    }
    
    if (nullify_lto)
    {
      if (optimize_size)
      {
        optimize = 2;
      }
      if (optimize >= 3)
      {
        NULLIFY(optimize, "Optimization level > 2") = 2;
      }
      
      NULLIFY(optimize_size, "Optimize for size") = 0;
      NULLIFY(optimize_fast, "Optimize fast") = 0;
      /* Disable everything enabled at OPT_LEVELS_3_PLUS in
         opts.c:default_options_table. */
      NULLIFY(flag_tree_loop_distribution, "tree loop distribution") = 0;
      NULLIFY(flag_predictive_commoning, "predictive commoning") = 0;
      NULLIFY(flag_inline_functions, "inline functions") = 0;
      NULLIFY(flag_unswitch_loops, "unswitch loops") = 0;
      NULLIFY(flag_gcse_after_reload, "gcse after reload") = 0;
      NULLIFY(flag_tree_vectorize, "tree vectorize") = 0;
      NULLIFY(flag_tree_loop_vectorize, "tree loop vectorize") = 0;
      NULLIFY(flag_tree_slp_vectorize, "tree slp vectorize") = 0;
      /* Not using NULLIFY for flags set to non-zero values because NULLIFY
         emits a "Pro compiler option xxx ignored" message if passed in flag
         is non-zero. */
      flag_vect_cost_model = VECT_COST_MODEL_CHEAP;
      NULLIFY(flag_ipa_cp_clone, "ipa cp clone") = 0;
      NULLIFY(flag_tree_partial_pre, "tree partial pre") = 0;

      /* Disable all -ffast-math optimizations enabled automatically at -O3.
         Reset everything set in opts.c:set_fast_math_flags to the default
         values for the options. Negating everything will turn on signaling
         nans and rounding-math (not the default), and will prevent _delay_ms
         from compiling (XC8-2774). */
      NULLIFY(flag_unsafe_math_optimizations, "unsafe math optimizations") = 0;
      flag_trapping_math = 1;
      flag_signed_zeros = 1;
      NULLIFY(flag_associative_math, "associative math") = 0;
      NULLIFY(flag_reciprocal_math, "reciprocal math") = 0;
      NULLIFY(flag_finite_math_only, "finite math only") = 0;
      flag_errno_math = 1;
	  /* set_fast_math_flags sets flag_signaling_nans and flag_rounding_math to
         their default values only (0), so don't bother resetting those two. */
      NULLIFY(flag_cx_limited_range, "cx limited range") = 0;

      flag_ipa_cp = 0;

      NULLIFY(flag_lto, "Link-time optimization") = 0;
      NULLIFY(flag_whole_program, "Whole-program optimizations") = 0;
      NULLIFY(flag_generate_lto, "Link-time optimization") = 0;

      /* Resets maybe_set_param_value (PARAM_MIN_CROSSJUMP_INSNS) to what
         it would have been if opts->x_optimize_size was false in
         opts.c:default_options_optimization. */

      set_param_value ("min-crossjump-insns",
		      default_param_value (PARAM_MIN_CROSSJUMP_INSNS),
		      global_options.x_param_values,
		      global_options_set.x_param_values);
    }
    
    if (message_displayed && TARGET_LICENSE_WARNING)
    {
      /*Now display a warning for the Pro option */
      if (disabled_option_message != NULL)
        warning (0,"Pro Compiler option (%s) ignored %s", disabled_option_message,
                   invalid_license);
      message_purchase_display++;
      message_displayed=0;
    }
    
    if ((message_purchase_display > 0) && (TARGET_LICENSE_WARNING))
    {
      inform (0, "Disable the option or visit http://www.microchip.com/mplab/compilers "
                "to purchase a new MPLAB XC compiler license.");

      /* If the -mno-fallback option was specified, abort compilation. */
      if (TARGET_NO_FALLBACKLICENSE)
          error ("Unable to find a valid license, aborting");

      message_purchase_display = 0;
    }

    /*Require a Standard or Pro license */
    if (TARGET_NO_FALLBACKLICENSE &&
        (mchp_avr_license_valid == AVR_FREE_LICENSE))
      error ("Unable to find a valid license, aborting");
  }
 
#undef AVR_EXPIRED_LICENSE
#undef AVR_VALID_STANDARD_LICENSE
#undef AVR_VALID_PRO_LICENSE

}

#undef NULLIFY
