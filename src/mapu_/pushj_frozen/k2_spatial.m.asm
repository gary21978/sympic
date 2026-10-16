// r44 tail jump to weights preserves original parent KI15; no intermediate return.
// KI0 stage0..5, FMA3.T4 physicalcoordinate; immutableT12rootcontext. T10 holds this stage metadata acrosscallees.
.section ".text.m0.k2_spatial_update.@public","axr",@progbits
.global k2_spatial_update
.type k2_spatial_update,@function
k2_spatial_update:
// r27: parent preloads descriptor T10, axis bank T11[4] and offset FMA3.T5.
// r39: inline audited integer floor; original rounded rx/dix forwarded to all weight FMA groups.
NOP; // r60 physical coordinate arrives directly in FMA3.T4; first consume at entry+4
BIU0: T12[1]+T10[0] -> BIU.T11[0](MODE1); // r39 spatial issue 1
BIU0: T12[7]+T10[1] -> BIU.T11[1](MODE1); // r39 spatial issue 2
BIU0: T12[1]+T10[2] -> BIU.T11[2](MODE1); // r39 spatial issue 3
BIU0: T12[1]+T10[3] -> BIU.T11[3](MODE1) || FALU3: FMA3.T4 + 0 (I32) -> BIU.T4(MODE1); // r39 spatial issue 4
BIU0: LOAD(T11[1]+192) -> FMA3.T5(MODE1) || FMA3: FMA3.T4 - FMA3.T5 * 1 (FP64) -> FMA0.T0 & M[0](MODE1); // r39 spatial issue 5
BIU0: T10[5] ? T12[7] : T11[4] -> BIU.T11[5](MODE1); // r39 spatial issue 6
BIU0: T10[7] ? T12[7] : T11[4] -> BIU.T11[6](MODE1); // r39 spatial issue 7
BIU2: STORE(T4,T11[0]+0)(MODE1) || FALU1: VE(0xbff0)(L)(U) -> FMA1.T2 || FALU2: VE(1075)(L)(U) -> FMA2.T0 || FALU3: VE(1)(L)(U) -> FMA3.T0; // r39 spatial issue 8
BIU0: T11[5]+T10[6] -> BIU.T11[5](MODE1) || FALU2: VE(63)(L)(U) -> FMA2.T1; // r39 spatial issue 9
BIU0: T11[6]+T10[8] -> BIU.T11[6](MODE1) || FALU1: T2 << 48(I64)(U)(T) -> FMA1.T2 || FALU2: T0 >> 32(I64)(U) -> FMA0.T2 || FALU3: T0 >> 32(I64)(U) -> FMA0.T3 || FALU0: T0 | 0 -> FMA1.T0; // r39 spatial issue 10
BIU0: T11[4]+T10[9] -> BIU.T11[7](MODE1) || FALU2: T1 >> 32(I64)(U) -> FMA0.T4; // r39 spatial issue 11
BIU0: KG(T11[5]) -> KI0(MODE1) || FALU0: T0 << 1(I64)(U)(T) -> FMA0.T1 || FALU1: T0 << 1(I64)(U)(T) -> FMA1.T1 || FALU2: VE(1023)(L)(U) -> FMA2.T2; // r39 spatial issue 12
BIU0: KG(T11[6]) -> KI1(MODE1) || FALU1: T0 < 0(I64) -> FMA1.T3 & FMA[3].T3; // r39 spatial issue 13
BIU0: KG(T11[7]) -> KI2(MODE1) || FALU0: T1 >> 53(I64)(U) -> FMA0.T1 || FALU2: T2 >> 32(I64)(U) -> FMA2.T2; // r39 spatial issue 14
FALU1: T1 != 0(I64U) -> FMA1.T1; // r39 spatial issue 15
FALU0: T2 - T1(I64)(U)(T) -> FMA0.T5; // r39 spatial issue 16
FALU1: T1 & T3 -> FMA1.T1; // r39 spatial issue 17
FALU0: T5 & T4 -> FMA0.T5; // r39 spatial issue 18
FALU1: CompSel1(T1, T2, 0)(I64U) -> FMA0.T7 || FALU2: T2 | 0 -> FMA0.T4; // r39 spatial issue 19
FALU0: T3 << T5(I64)(U)(T) -> FMA0.T5 & FMA[3].T1; // r39 spatial issue 20
NOP; // r39 spatial issue 21
FALU0: T5 - T3(I64)(U)(T) -> FMA0.T6; // r39 spatial issue 22
NOP; // r39 spatial issue 23
FALU0: T0 & T6 -> FMA0.T6 & FMA[3].T0; // r39 spatial issue 24
NOP; // r39 spatial issue 25
FALU0: T0 ^ T6 -> FMA0.T8 || FALU3: T0 != 0(I64U) -> FMA3.T2; // r39 spatial issue 26
NOP; // r39 spatial issue 27
FALU3: T2 & T3 -> FMA3.T2; // r39 spatial issue 28
NOP; // r39 spatial issue 29
FALU3: CompSel1(T2, T1, 0)(I64U) -> FMA0.T5; // r39 spatial issue 30
NOP; // r39 spatial issue 31
FALU0: T8 + T5(I64)(U)(T) -> FMA0.T6; // r39 spatial issue 32
NOP; // r39 spatial issue 33
FALU0: CompSel2(T1, T2, T0, T6)(I64U) -> FMA0.T6; // r39 spatial issue 34
FALU3: T5 | 0 -> FMA0.T5; // r39 spatial issue 35
FALU0: CompSel2(T1, T4, T6, T7)(I64U) -> FMA0.T1; // r39 spatial issue 36
FALU3: T7 | 0 -> FMA0.T7; // r39 spatial issue 37
FMA0: T0 - T1 * 1(FP64) -> BIU.T4; // r39 spatial issue 38
FMA0: T1 - T5 * 1(FP64) -> BIU.T5; // r39 spatial issue 39
FALU0: T7 | 0 -> FMA0.T11 || FALU1: T7 | 0 -> FMA1.T11 || FALU2: T7 | 0 -> FMA2.T11 || MFETCH: JUMP KI9; // r39 spatial issue 40
NOP;
.Lk2_spatial_end:
.size k2_spatial_update,.Lk2_spatial_end-k2_spatial_update
