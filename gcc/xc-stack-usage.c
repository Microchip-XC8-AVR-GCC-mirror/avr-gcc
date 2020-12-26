#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "target.h"
#include "bversion.h" /* for BUILDING_GCC_MAJOR, BUILDING_GCC_VERSION */

/* this header madness affects only GCC 5.x, it seems */
#if (BUILDING_GCC_MAJOR == 5)
#include "hash-set.h"
#include "vec.h"
#include "double-int.h"
#include "input.h"
#include "alias.h"
#include "symtab.h"
#include "inchash.h"
#include "ipa-ref.h"
#include "tree-core.h"
#include "tree-ssa-alias.h"
#include "is-a.h"
#include "predict.h"
#include "function.h"
#include "basic-block.h"
#include "tree.h"
#include "gimple-expr.h"
#include "fold-const.h"
#include "gimple.h"
#include "lto-streamer.h"
#include "dominance.h"
#else
#include "tree.h"
#include "function.h"
#include "basic-block.h"
#endif

#include "tree-pass.h"
#include "cgraph.h"
#include "toplev.h"     /* error() prototype is here on older GCCs */
#include "diagnostic.h" /* for error() on newer versions */
#include "langhooks.h"
#include "cppdefault.h"
#include "rtl.h"
#include "emit-rtl.h"
#include "bitmap.h"
#if (BUILDING_GCC_VERSION >= 5000)
#include "cfg.h"
#endif
#include "df.h"
#include "tm_p.h"
#include "output.h"
#include "dwarf2asm.h"
#include "tree-pretty-print.h"

/* Given a CALL_INSN, find and return the nested CALL. */
/* (copied from final.c) */
static rtx
call_from_call_insn (rtx_call_insn *insn)
{
  rtx x;
  gcc_assert (CALL_P (insn));
  x = PATTERN (insn);

  while (GET_CODE (x) != CALL)
    {
      switch (GET_CODE (x))
        {
        default:
          gcc_unreachable ();
        case COND_EXEC:
          x = COND_EXEC_CODE (x);
          break;
        case PARALLEL:
          x = XVECEXP (x, 0, 0);
          break;
        case SET:
          x = XEXP (x, 1);
          break;
        }
    }
  return x;
}

// called from "pro_and_epilogue" pass i.e. once the stack usage
// is determined for the current function;
//   stack_usage      - maximum stack usage in bytes
//   stack_usage_kind - 0 (static), 1 (dynamic,unbounded), 2 (dynamic,bounded)
//                      as calculated/reported by -fstack-usage
void
xc_output_stack_guidance (HOST_WIDE_INT stack_usage, int stack_usage_kind)
{
  const char *name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (current_function_decl));

  bool indirect_calls = false;
  bool inline_asm = false;

  for (rtx_insn *insn = get_insns (); insn != NULL_RTX; insn = next_insn (insn))
    {
      if (INSN_P (insn))
        {
          rtx body = PATTERN (insn);
          if (INSN_CODE (insn) < 0
               && (GET_CODE (body) == ASM_INPUT || asm_noperands (body) >= 0))
            {
              inline_asm = true;
              continue;
            }
        }

      rtx call_insn = insn;
      if (NONJUMP_INSN_P (insn) && GET_CODE (PATTERN (insn)) == SEQUENCE)
        call_insn = XVECEXP (PATTERN (insn), 0, 0);

      if (!CALL_P (call_insn))
        continue;

      rtx x = call_from_call_insn ((rtx_call_insn *)call_insn);
      x = XEXP (x, 0);

      const char *callee_name = 0;

      /* SYMBOL_REF_DECL can be NULL for an indirect call to an intrinsic
         or a libgcc function, like below, so consider SYMBOL_REF itself
         to indicate direct call. Indirect calls have a reg (Z) in place
         of the SYMBOL_REF.
         (call_insn/u 7 3 8 2
           (parallel [(set (reg:SF 22 r22)
                           (call (mem:HI (symbol_ref:HI ("__floatunsisf") [flags 0x41]) [0  S2 A8])
                                 (const_int 0 [0])))
                      (use (const_int 0 [0]))]) */
      if (!(x && MEM_P (x) && GET_CODE (XEXP (x, 0)) == SYMBOL_REF))
        {
          indirect_calls = true;
        }
    }

  /*  These must match linker's definition */
  enum STACK_GUIDANCE_FLAGS
  {
   SU_INDIRECT_CALLS  = 0x1 << 0,
   SU_INLINE_ASM      = 0x1 << 1,
   SU_INACCURATE      = 0x1 << 5,
   SU_INTERRUPT       = 0x1 << 6,
   SU_UNINTERRUPTIBLE = 0x1 << 8
  };

  uint32_t flags = 0x0;

  if (indirect_calls)
    flags |= SU_INDIRECT_CALLS;
  if (inline_asm)
    flags |= SU_INLINE_ASM;
  if (cfun->machine->is_interrupt
       || cfun->machine->is_signal
       || cfun->machine->is_nmi)
    flags |= SU_INTERRUPT;
  if (cfun->machine->is_OS_main)
    flags |= SU_UNINTERRUPTIBLE;

  const int SU_DYNAMIC_UNBOUNDED_T = 1;
  if (stack_usage_kind == SU_DYNAMIC_UNBOUNDED_T)
    flags |= SU_INACCURATE;

  TARGET_STACK_GUIDANCE_SECTION (".stack.descriptors");

  // function addr and name
  dw2_asm_output_addr (4, name, "function");

  int namelen = strlen (name) + 1; /*  Include trailing zero. */

  /* Mimic what assemble_name_raw does with a leading '*'.  */
  if (name[0] == '*')
    {
      name = &name[1]; namelen--;
    }

  ASM_OUTPUT_ASCII (asm_out_file, name, namelen);

  // stack usage for this function
  dw2_asm_output_data (4, stack_usage, "size");

  dw2_asm_output_data (4, flags, "flags");
  dw2_asm_output_data (1, stack_usage_kind, "kind");
}

void xc_output_stack_guidance_header(void)
{
  TARGET_STACK_GUIDANCE_SECTION (".stack.descriptors.hdr");

  dw2_asm_output_data (1, 0xE, "Size");
  dw2_asm_output_data (4, 0x1, "Version");

  dw2_asm_output_data (1, 0, "Reserved");
  dw2_asm_output_data (4, 0, "Reserved");
  dw2_asm_output_data (4, 0, "Reserved");
}
