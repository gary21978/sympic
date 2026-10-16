.section ".text.m0.k2_reciprocal_rn.@public","axr",@progbits
.global k2_reciprocal_rn
.type k2_reciprocal_rn,@function
k2_reciprocal_rn:
R1: M[0] -> FMA1.T0(MODE1);
BIU0: 0x0 (L)(E) -> BIU.T0[0](MODE1);
BIU0: 0x3ff0 (E) -> BIU.T0[1](MODE1);
BIU0: 0x1 (L)(E) -> BIU.T0[2](MODE1);
BIU0: 0x0 (L)(E) -> BIU.T0[3](MODE1);
MFETCH: Repeat @(2);
BIU0: KGDWORD(T0[0]) -> FMA1.T1(MODE1);
BIU0: KGDWORD(T0[0]) -> FMA1.T3(MODE1);
BIU0: KGDWORD(T0[2]) -> FMA1.T5(MODE1);
MFETCH: Repeat @(2);
FALU1: FDIV(FMA1.T1,FMA1.T0) (FP64) -> NONE(MODE1);
MFETCH: Repeat @(60);
FALU1: FREADQ (FP64) -> FMA1.T4(MODE1);
NOP;
FALU1: FMA1.T4 + FMA1.T5 (I64)(T) -> FMA1.T6(MODE1);
NOP;
FMA1: FMA1.T6 - FMA1.T4 * 1 (FP64) -> FMA0.T4(MODE1);
FMA1: FMA1.T3 - FMA1.T4 * FMA1.T0 (FP64) -> FMA0.T5(MODE1);
FALU1: FMA1.T0 + 0 (I32) -> FMA0.T6(MODE1);
NOP;
NOP;
FMA0: FMA0.T7 + FMA0.T6 * FMA0.T4 (FP64) -> FMA1.T2(MODE1);
FMA0: FMA0.T5 + FMA0.T5 * 1 (FP64) -> FMA1.T3(MODE1);
MFETCH: Repeat @(4);
FALU1: FMA1.T2 < FMA1.T3 (FP64) -> FMA1.T2(MODE1);
NOP;
FALU1: COMPSEL1(FMA1.T2,FMA1.T6,FMA1.T4) (FP64) -> M[0](MODE1);
MFETCH: Repeat @(8);
MFETCH: JUMP KI15;
NOP;
.Lk2_recip_end:
.size k2_reciprocal_rn,.Lk2_recip_end-k2_reciprocal_rn
