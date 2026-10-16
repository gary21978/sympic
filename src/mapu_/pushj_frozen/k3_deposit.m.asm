/* Whole K3 fusion: strict FDIV plus embedded paired Jx/JyJz pipelines.
 * Native KI0 bank, KI1 state, KI2 ctx, KI3 J, KI4 particleDM, KI5 g_inner,
 * KI6 load0, KI15 return. Preserves KI0..15, BIU.T3..15 and configuration.
 * Scratch M0..255, BIU.T0..2, FMA/FMAC/FALU caller-saved arithmetic state.
 * No counters, nested calls, stack writes, or pre-window arithmetic.
 * Native MReg256, JumpMode0; all stores and return dependencies drain.
 * Generated tools/k3_fused_schedule.py; see reports/k3-next-audit.md.
 */
.section .text.m0.candidate_k3.@public, "ax", @progbits
.file "candidate_k3.m.asm"
.global candidate_k3
.type candidate_k3,@function
candidate_k3:
BIU0: 0(L)(E) -> BIU.T0[0](MODE1) ||
BIU1: 0x8000(E) -> BIU.T0[1](MODE1);
MFETCH: Repeat @(3);
BIU0: KGDWORD(T0[0]) -> FMA0.T7 & FMA1.T7(MODE1);
BIU0: KGDWORD(T0[0]) -> FMA2.T7 & FMA3.T7(MODE1);
// T5 is otherwise first written after DC282, past the final FMAC at DC260.
BIU0: KGDWORD(T0[0]) -> FMA0.T5 & FMA2.T5(MODE1);
MFETCH: Repeat @(3);
FALU0: T7 | 0 -> FMA0.T9(MODE1) ||
FALU1: T7 | 0 -> FMA1.T9(MODE1) ||
FALU2: T7 | 0 -> FMA2.T9(MODE1) ||
FALU3: T7 | 0 -> FMA3.T9(MODE1);
MFETCH: Repeat @(5);
    BIU0: KG(T3) -> M[255]; // entry DC 0
    BIU0: KG(T4) -> M[249]; // entry DC 1
    BIU0: KG(T5) -> M[250]; // entry DC 2
    BIU0: KG(T6) -> M[251]; // entry DC 3
    BIU0: KG(T7) -> M[252]; // entry DC 4
    BIU0: KG(T8) -> M[253] || MFETCH: KI15 -> BIU.T3[15]; // entry DC 5
    BIU0: KG(T9) -> M[254] || MFETCH: KI0 -> BIU.T3[0]; // entry DC 6
    MFETCH: KI1 -> BIU.T3[1]; // entry DC 7
    MFETCH: KI2 -> BIU.T3[2]; // entry DC 8
    MFETCH: KI3 -> BIU.T3[3]; // entry DC 9
    MFETCH: KI4 -> BIU.T3[4]; // entry DC 10
    MFETCH: KI5 -> BIU.T3[5]; // entry DC 11
    MFETCH: KI6 -> BIU.T3[6]; // entry DC 12
// r11: all finite full-batch mask lanes are1; share masked arithmetic.
k3_tail_dispatch:
// KI14 is the measurement scratch register; K3 has no live KI14 value.
MFETCH: %k3_tail_body -> KI14(L)(U);
MFETCH: %k3_tail_body -> KI14(U);
MFETCH: Repeat @(6);
MFETCH: JUMP KI14;
NOP;
.size candidate_k3,.-candidate_k3
