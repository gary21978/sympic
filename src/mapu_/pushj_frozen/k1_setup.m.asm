/* Full-hand K1 candidate: tools/k1_full_hand_schedule.py; ISA0.359.
 * KI0=bank, KI1=state, KI2=particle_dm, KI3=g_inner, KI4=load0, KI5=ctx.
 * KI15=return; native960B gather frame; T4..9 saved/restored in M250..255, T10..14 untouched.
 * T15 native descriptor restored exactly from M249; KI15 stays unchanged.
 * Full/tail gather uses src=(g_inner+lane<load0)?g_inner+lane:0, no overread.
 * Requires valid staged particle0, nonnegative bounded native32-bit indices,
 * native MReg depth256 and JumpMode0. No new K/mode/DM-accumulate configuration.
 * Reused hand coordinate/floor/path body, five inline strict weight DAGs.
 * Only six shared floor8 calls remain. No compiler-gather text is read/copied.
 * Static DC excludes floor execution/stalls: NOT measured cycles or target PASS.
 */
.section .text.m0.candidate_k1, "ax", @progbits
.file "k1-full-hand-3buffer-20260918.m.asm"
.global candidate_k1
.type candidate_k1,@function
candidate_k1:
BIU0: 0(L)(E) -> BIU.T0[0](MODE1) ||
BIU1: 0x8000(E) -> BIU.T0[1](MODE1);
MFETCH: Repeat @(3);
BIU0: KGDWORD(T0[0]) -> FMA0.T7 & FMA1.T7(MODE1);
BIU0: KGDWORD(T0[0]) -> FMA2.T7 & FMA3.T7(MODE1);
MFETCH: Repeat @(3);
FALU0: T7 | 0 -> FMA0.T11(MODE1) ||
FALU1: T7 | 0 -> FMA1.T11(MODE1) ||
FALU2: T7 | 0 -> FMA2.T11(MODE1) ||
FALU3: T7 | 0 -> FMA3.T11(MODE1);
MFETCH: Repeat @(5);
_MPU_PUSHJ_K1_FULL_GATHER_START:
    BIU2: KG(T15) -> M[249](MODE1) || BIU0: T15[15] -> BIU.T15[14] || BIU1: 960(E)(L)(U) -> BIU.T0[7]; // gather DC 0
    MFETCH: KI0 -> BIU.T3[2] || BIU1: 48(E)(L)(U) -> BIU.T0[6]; // gather DC 1
    MFETCH: KI1 -> BIU.T3[0] || BIU1: 0(E)(L)(U) -> BIU.T0[2]; // gather DC 2
    BIU0: T15[15] + T0[7] -> BIU.T15[15] || MFETCH: KI2 -> BIU.T0[3] || BIU1: 0x3ff0(E) -> BIU.T0[1]; // gather DC 3
    MFETCH: KI3 -> BIU.T0[4]; // gather DC 4
    MFETCH: KI4 -> BIU.T0[5]; // gather DC 5
    MFETCH: KI5 -> BIU.T0[0]; // gather DC 6
    MFETCH: NOP; // gather DC 7
BIU0: V(0) -> BIU.T2(MODE1); // r52 gather address 0
BIU0: T0[4] + 0(U) -> BIU.T0[8] || BIU1: T0[4] + 1(U) -> BIU.T0[9] || BIU2: T0[4] + 2(U) -> BIU.T0[10] || BIU3: T0[4] + 3(U) -> BIU.T0[11]; // r52 gather address 1
BIU0: T0[4] + 4(U) -> BIU.T0[12] || BIU1: T0[4] + 5(U) -> BIU.T0[13] || BIU2: T0[4] + 6(U) -> BIU.T0[14] || BIU3: T0[4] + 7(U) -> BIU.T0[15]; // r52 gather address 2
NOP; // r52 gather address 3
BIU0: T0[8] < T0[5] -> BIU.T3[8] || BIU1: T0[9] < T0[5] -> BIU.T3[9] || BIU2: T0[10] < T0[5] -> BIU.T3[10] || BIU3: T0[11] < T0[5] -> BIU.T3[11]; // r52 gather address 4
BIU0: T0[12] < T0[5] -> BIU.T3[12] || BIU1: T0[13] < T0[5] -> BIU.T3[13] || BIU2: T0[14] < T0[5] -> BIU.T3[14] || BIU3: T0[15] < T0[5] -> BIU.T3[15]; // r52 gather address 5
NOP; // r52 gather address 6
BIU0: T3[8] ? T0[8] : T0[2] -> BIU.T0[8] || BIU1: T3[9] ? T0[9] : T0[2] -> BIU.T0[9] || BIU2: T3[10] ? T0[10] : T0[2] -> BIU.T0[10] || BIU3: T3[11] ? T0[11] : T0[2] -> BIU.T0[11]; // r52 gather address 7
BIU0: T3[12] ? T0[12] : T0[2] -> BIU.T0[12] || BIU1: T3[13] ? T0[13] : T0[2] -> BIU.T0[13] || BIU2: T3[14] ? T0[14] : T0[2] -> BIU.T0[14] || BIU3: T3[15] ? T0[15] : T0[2] -> BIU.T0[15]; // r52 gather address 8
BIU0: T3[8] ? T0[1] : T0[2] -> BIU.T2[1] || BIU1: T3[9] ? T0[1] : T0[2] -> BIU.T2[3] || BIU2: T3[10] ? T0[1] : T0[2] -> BIU.T2[5] || BIU3: T3[11] ? T0[1] : T0[2] -> BIU.T2[7]; // r52 gather address 9
BIU0: T3[12] ? T0[1] : T0[2] -> BIU.T2[9] || BIU1: T3[13] ? T0[1] : T0[2] -> BIU.T2[11] || BIU2: T3[14] ? T0[1] : T0[2] -> BIU.T2[13] || BIU3: T3[15] ? T0[1] : T0[2] -> BIU.T2[15]; // r52 gather address 10
BIU0: T0[8] * T0[6](U) -> BIU.T0[8] || BIU1: T0[9] * T0[6](U) -> BIU.T0[9] || BIU2: T0[10] * T0[6](U) -> BIU.T0[10] || BIU3: T0[11] * T0[6](U) -> BIU.T0[11]; // r52 gather address 11
BIU0: T0[12] * T0[6](U) -> BIU.T0[12] || BIU1: T0[13] * T0[6](U) -> BIU.T0[13] || BIU2: T0[14] * T0[6](U) -> BIU.T0[14] || BIU3: T0[15] * T0[6](U) -> BIU.T0[15]; // r52 gather address 12
BIU2: Store(T2, T3[0] + 0); // r52 gather address 13
BIU0: T0[3] + T0[8] -> BIU.T0[8] || BIU1: T0[3] + T0[9] -> BIU.T0[9] || BIU2: T0[3] + T0[10] -> BIU.T0[10] || BIU3: T0[3] + T0[11] -> BIU.T0[11]; // r52 gather address 14
BIU0: T0[3] + T0[12] -> BIU.T0[12] || BIU1: T0[3] + T0[13] -> BIU.T0[13] || BIU2: T0[3] + T0[14] -> BIU.T0[14] || BIU3: T0[3] + T0[15] -> BIU.T0[15]; // r52 gather address 15
NOP; // r52 gather address 16
NOP; // r52 gather address 17
NOP; // r52 gather address 18
    BIU0: LoadI64(T0[8] + 0) -> BIU.T1; // gather DC 52
    BIU0: LoadI64(T0[9] + 0) -> BIU.T2; // gather DC 53
    BIU0: LoadI64(T0[10] + 0) -> BIU.T3; // gather DC 54
    BIU0: LoadI64(T0[11] + 0) -> BIU.T1; // gather DC 55
    BIU0: LoadI64(T0[12] + 0) -> BIU.T2; // gather DC 56
    BIU0: LoadI64(T0[13] + 0) -> BIU.T3; // gather DC 57
    BIU0: LoadI64(T0[14] + 0) -> BIU.T1; // gather DC 58
    BIU0: LoadI64(T0[15] + 0) -> BIU.T2; // gather DC 59
    BIU0: LoadI64(T0[8] + 8) -> BIU.T3; // gather DC 60
    BIU0: LoadI64(T0[9] + 8) -> BIU.T1; // gather DC 61
    BIU0: LoadI64(T0[10] + 8) -> BIU.T2; // gather DC 62
    BIU0: LoadI64(T0[11] + 8) -> BIU.T3; // gather DC 63
    BIU0: LoadI64(T0[12] + 8) -> BIU.T1; // gather DC 64
    BIU2: StoreI64(T1, T15[14] + 128) || BIU0: LoadI64(T0[13] + 8) -> BIU.T2; // gather DC 65
    BIU2: StoreI64(T2, T15[14] + 136) || BIU0: LoadI64(T0[14] + 8) -> BIU.T3; // gather DC 66
    BIU2: StoreI64(T3, T15[14] + 144) || BIU0: LoadI64(T0[15] + 8) -> BIU.T1; // gather DC 67
    BIU2: StoreI64(T1, T15[14] + 152) || BIU0: LoadI64(T0[8] + 16) -> BIU.T2; // gather DC 68
    BIU2: StoreI64(T2, T15[14] + 160) || BIU0: LoadI64(T0[9] + 16) -> BIU.T3; // gather DC 69
    BIU2: StoreI64(T3, T15[14] + 168) || BIU0: LoadI64(T0[10] + 16) -> BIU.T1; // gather DC 70
    BIU2: StoreI64(T1, T15[14] + 176) || BIU0: LoadI64(T0[11] + 16) -> BIU.T2; // gather DC 71
    BIU2: StoreI64(T2, T15[14] + 184) || BIU0: LoadI64(T0[12] + 16) -> BIU.T3; // gather DC 72
    BIU2: StoreI64(T3, T15[14] + 192) || BIU0: LoadI64(T0[13] + 16) -> BIU.T1; // gather DC 73
    BIU2: StoreI64(T1, T15[14] + 200) || BIU0: LoadI64(T0[14] + 16) -> BIU.T2; // gather DC 74
    BIU2: StoreI64(T2, T15[14] + 208) || BIU0: LoadI64(T0[15] + 16) -> BIU.T3; // gather DC 75
    BIU2: StoreI64(T3, T15[14] + 216) || BIU0: LoadI64(T0[8] + 24) -> BIU.T1; // gather DC 76
    BIU2: StoreI64(T1, T15[14] + 224) || BIU0: LoadI64(T0[9] + 24) -> BIU.T2; // gather DC 77
    BIU2: StoreI64(T2, T15[14] + 232) || BIU0: LoadI64(T0[10] + 24) -> BIU.T3; // gather DC 78
    BIU2: StoreI64(T3, T15[14] + 240) || BIU0: LoadI64(T0[11] + 24) -> BIU.T1; // gather DC 79
    BIU2: StoreI64(T1, T15[14] + 248) || BIU0: LoadI64(T0[12] + 24) -> BIU.T2; // gather DC 80
    BIU2: StoreI64(T2, T15[14] + 256) || BIU0: LoadI64(T0[13] + 24) -> BIU.T3; // gather DC 81
    BIU2: StoreI64(T3, T15[14] + 264) || BIU0: LoadI64(T0[14] + 24) -> BIU.T1; // gather DC 82
    BIU2: StoreI64(T1, T15[14] + 272) || BIU0: LoadI64(T0[15] + 24) -> BIU.T2; // gather DC 83
    BIU2: StoreI64(T2, T15[14] + 280) || BIU0: LoadI64(T0[8] + 32) -> BIU.T3; // gather DC 84
    BIU2: StoreI64(T3, T15[14] + 288) || BIU0: LoadI64(T0[9] + 32) -> BIU.T1; // gather DC 85
    BIU2: StoreI64(T1, T15[14] + 296) || BIU0: LoadI64(T0[10] + 32) -> BIU.T2; // gather DC 86
    BIU2: StoreI64(T2, T15[14] + 304) || BIU0: LoadI64(T0[11] + 32) -> BIU.T3; // gather DC 87
    BIU2: StoreI64(T3, T15[14] + 312) || BIU0: LoadI64(T0[12] + 32) -> BIU.T1; // gather DC 88
    BIU2: StoreI64(T1, T15[14] + 320) || BIU0: LoadI64(T0[13] + 32) -> BIU.T2; // gather DC 89
    BIU2: StoreI64(T2, T15[14] + 328) || BIU0: LoadI64(T0[14] + 32) -> BIU.T3; // gather DC 90
    BIU2: StoreI64(T3, T15[14] + 336) || BIU0: LoadI64(T0[15] + 32) -> BIU.T1; // gather DC 91
    BIU2: StoreI64(T1, T15[14] + 344) || BIU0: LoadI64(T0[8] + 40) -> BIU.T2; // gather DC 92
    BIU2: StoreI64(T2, T15[14] + 352) || BIU0: LoadI64(T0[9] + 40) -> BIU.T3; // gather DC 93
    BIU2: StoreI64(T3, T15[14] + 360) || BIU0: LoadI64(T0[10] + 40) -> BIU.T1; // gather DC 94
    BIU2: StoreI64(T1, T15[14] + 368) || BIU0: LoadI64(T0[11] + 40) -> BIU.T2; // gather DC 95
    BIU2: StoreI64(T2, T15[14] + 376) || BIU0: LoadI64(T0[12] + 40) -> BIU.T3; // gather DC 96
    BIU2: StoreI64(T3, T15[14] + 384) || BIU0: LoadI64(T0[13] + 40) -> BIU.T1; // gather DC 97
    BIU2: StoreI64(T1, T15[14] + 392) || BIU0: LoadI64(T0[14] + 40) -> BIU.T2; // gather DC 98
    BIU2: StoreI64(T2, T15[14] + 400) || BIU0: LoadI64(T0[15] + 40) -> BIU.T3; // gather DC 99
    BIU2: StoreI64(T3, T15[14] + 408); // gather DC 100
    BIU2: StoreI64(T1, T15[14] + 416); // gather DC 101
    BIU2: StoreI64(T2, T15[14] + 424); // gather DC 102
    BIU2: StoreI64(T3, T15[14] + 432); // gather DC 103
    BIU2: StoreI64(T1, T15[14] + 440); // gather DC 104
    BIU2: StoreI64(T2, T15[14] + 448); // gather DC 105
    BIU2: StoreI64(T3, T15[14] + 456); // gather DC 106
    BIU2: StoreI64(T1, T15[14] + 464); // gather DC 107
    BIU2: StoreI64(T2, T15[14] + 472); // gather DC 108
    BIU2: StoreI64(T3, T15[14] + 480); // gather DC 109
    BIU2: StoreI64(T1, T15[14] + 488); // gather DC 110
    BIU2: StoreI64(T2, T15[14] + 496); // gather DC 111
    BIU2: StoreI64(T3, T15[14] + 504); // gather DC 112
    MFETCH: NOP; // gather DC 113
    MFETCH: NOP; // gather DC 114
    MFETCH: NOP; // gather DC 115
    MFETCH: NOP; // gather DC 116
    MFETCH: KI0 -> BIU.T3[2]; // gather DC 117
    MFETCH: KI1 -> BIU.T3[0]; // gather DC 118
    MFETCH: NOP; // gather DC 119
    MFETCH: NOP; // gather DC 120
    MFETCH: NOP; // gather DC 121
    MFETCH: NOP; // gather DC 122
    MFETCH: NOP; // gather DC 123

_MPU_PUSHJ_K1_FULL_PRESERVE_AND_SETUP:
    BIU2: KG(T4) -> M[250](MODE1); // h0000 preserve BIU.T4
    BIU2: KG(T5) -> M[251](MODE1); // h0001 preserve BIU.T5
    BIU2: KG(T6) -> M[252](MODE1); // h0002 preserve BIU.T6
    BIU2: KG(T7) -> M[253](MODE1); // h0003 preserve BIU.T7
    BIU2: KG(T8) -> M[254](MODE1); // h0004 preserve BIU.T8
    BIU2: KG(T9) -> M[255](MODE1); // h0005 preserve BIU.T9
    BIU0: T3[2] -> BIU.T4[0] || BIU1: T3[0] -> BIU.T4[1] || BIU2: T0[0] -> BIU.T4[2]; // h0006 persistent bank, state, ctx
    MFETCH: NOP; // h0007 dependency / output-port gap
    BIU0: 0(E)(L)(U) -> BIU.T9[0] || BIU1: 0xbfe0(E) -> BIU.T9[1]; // h0008 
    BIU0: LoadI64(T4[2] + 0) -> BIU.T5; // h0009 Deltat
    MFETCH: NOP; // h0010 dependency / output-port gap
    BIU0: LoadI64(T4[2] + 112) -> BIU.T6; // h0011 Midx
    MFETCH: NOP; // h0012 dependency / output-port gap
    BIU0: LoadI64(T4[2] + 120) -> BIU.T7; // h0013 Midy
    MFETCH: NOP; // h0014 dependency / output-port gap
    BIU0: LoadI64(T4[2] + 128) -> BIU.T8; // h0015 Midz
    BIU1: Load(T4[0] + 0)(I32) -> BIU.T4[4]; // h0016 independent axis-bank pointer
    MFETCH: NOP; // h0017 dependency / output-port gap
    BIU1: Load(T4[0] + 4)(I32) -> BIU.T4[5]; // h0018 independent axis-bank pointer
    MFETCH: NOP; // h0019 dependency / output-port gap
    BIU1: Load(T4[0] + 8)(I32) -> BIU.T4[6]; // h0020 independent axis-bank pointer

_MPU_PUSHJ_K1_FULL_COORDINATES:
// r53 original coordinate DAG, velocity bits and rounded head reused directly.
BIU0: LOAD(T15[14]+128) -> FMA0.T0(MODE1); // r53 coordinate 0
BIU0: LOAD(T15[14]+320) -> FMA0.T2(MODE1); // r53 coordinate 1
BIU0: LOAD(T15[14]+192) -> FMA1.T0(MODE1); // r53 coordinate 2
BIU0: LOAD(T15[14]+384) -> FMA1.T2(MODE1); // r53 coordinate 3
BIU0: LOAD(T15[14]+256) -> FMA2.T0(MODE1); // r53 coordinate 4
BIU0: LOAD(T15[14]+448) -> FMA2.T2(MODE1); // r53 coordinate 5
BIU3: KGDWORD(T9[0]) -> FMA[0,1,2].T1(MODE1); // r53 coordinate 6
NOP; // r53 coordinate 7
BIU3: KGDWORD(T5[0]) -> FMA[0,1,2].T3(MODE1); // r53 coordinate 8
NOP; // r53 coordinate 9
NOP; // r53 coordinate 10
NOP; // r53 coordinate 11
NOP; // r53 coordinate 12
FMA0: T0 + T1 * 1(FP64) -> FMA0.T4 & M[0](MODE1); // r53 coordinate 13
FMA0: T11 + T3 * T2(FP64) -> FMA0.T5(MODE1); // r53 coordinate 14
FMA1: T0 + T1 * 1(FP64) -> FMA1.T4 & M[32](MODE1); // r53 coordinate 15
FALU0: T2 | 0 -> BIU.T1(MODE1) || FMA1: T11 + T3 * T2(FP64) -> FMA1.T5(MODE1); // r53 coordinate 16
FMA2: T0 + T1 * 1(FP64) -> FMA2.T4 & M[64](MODE1); // r53 coordinate 17
FALU1: T2 | 0 -> BIU.T2(MODE1) || FMA2: T11 + T3 * T2(FP64) -> FMA2.T5(MODE1); // r53 coordinate 18
BIU2: STORE(T1,T4[1]+256)(MODE1) || FMA0: T4 - T5 * 1(FP64) -> FMA0.T0 & BIU.T1(MODE1); // r53 coordinate 19
FALU2: T2 | 0 -> BIU.T3(MODE1); // r53 coordinate 20
FALU0: T4 | 0 -> BIU.T1(MODE1) || BIU2: STORE(T2,T4[1]+320)(MODE1) || FMA1: T4 - T5 * 1(FP64) -> FMA1.T0 & BIU.T2(MODE1); // r53 coordinate 21
NOP; // r53 coordinate 22
FALU1: T4 | 0 -> BIU.T2(MODE1) || BIU2: STORE(T3,T4[1]+384)(MODE1) || FMA2: T4 - T5 * 1(FP64) -> FMA2.T0 & BIU.T3(MODE1); // r53 coordinate 23
BIU2: STORE(T1,T4[1]+64)(MODE1); // r53 coordinate 24
BIU2: STORE(T1,T4[1]+448)(MODE1) || FALU2: T4 | 0 -> BIU.T3(MODE1); // r53 coordinate 25
BIU2: STORE(T2,T4[1]+128)(MODE1); // r53 coordinate 26
BIU2: STORE(T2,T4[1]+512)(MODE1); // r53 coordinate 27
BIU2: STORE(T3,T4[1]+192)(MODE1); // r53 coordinate 28
BIU2: STORE(T3,T4[1]+576)(MODE1); // r53 coordinate 29
_MPU_PUSHJ_K1_BATCH_FLOOR_POS0:
// r55 exact coordinate bits forwarded into unchanged integer floor graph.
FALU0: VE(1075)(L)(U) -> FMA0.T2 || FALU1: VE(1075)(L)(U) -> FMA1.T2 || FALU2: VE(1075)(L)(U) -> FMA2.T2; // r55 batch0 issue 0
FALU0: VE(1)(L)(U) -> FMA0.T3 || FALU1: VE(1)(L)(U) -> FMA1.T3 || FALU2: VE(1)(L)(U) -> FMA2.T3; // r55 batch0 issue 1
FALU0: T2 >> 32(I64)(U) -> FMA0.T2 || FALU1: T2 >> 32(I64)(U) -> FMA1.T2 || FALU2: T2 >> 32(I64)(U) -> FMA2.T2; // r55 batch0 issue 2
FALU0: T3 >> 32(I64)(U) -> FMA0.T3 || FALU1: T3 >> 32(I64)(U) -> FMA1.T3 || FALU2: T3 >> 32(I64)(U) -> FMA2.T3; // r55 batch0 issue 3
FALU0: VE(63)(L)(U) -> FMA0.T4 || FALU1: VE(63)(L)(U) -> FMA1.T4 || FALU2: VE(63)(L)(U) -> FMA2.T4; // r55 batch0 issue 4
FALU0: VE(0xbff0)(L)(U) -> FMA0.T7 || FALU1: VE(0xbff0)(L)(U) -> FMA1.T7 || FALU2: VE(0xbff0)(L)(U) -> FMA2.T7; // r55 batch0 issue 5
FALU0: T4 >> 32(I64)(U) -> FMA0.T4 || FALU1: T4 >> 32(I64)(U) -> FMA1.T4 || FALU2: T4 >> 32(I64)(U) -> FMA2.T4; // r55 batch0 issue 6
FALU0: T7 << 48(I64)(U)(T) -> FMA0.T7 || FALU1: T7 << 48(I64)(U)(T) -> FMA1.T7 || FALU2: T7 << 48(I64)(U)(T) -> FMA2.T7; // r55 batch0 issue 7
FALU0: T0 << 1(I64)(U)(T) -> FMA0.T1 || FALU1: T0 << 1(I64)(U)(T) -> FMA1.T1 || FALU2: T0 << 1(I64)(U)(T) -> FMA2.T1; // r55 batch0 issue 8
FALU0: T0 < 0(I64) -> FMA0.T9 || FALU1: T0 < 0(I64) -> FMA1.T9 || FALU2: T0 < 0(I64) -> FMA2.T9; // r55 batch0 issue 9
FALU0: T1 >> 53(I64)(U) -> FMA0.T1 || FALU1: T1 >> 53(I64)(U) -> FMA1.T1 || FALU2: T1 >> 53(I64)(U) -> FMA2.T1; // r55 batch0 issue 10
FALU0: T0 << 1(I64)(U)(T) -> FMA0.T10 || FALU1: T0 << 1(I64)(U)(T) -> FMA1.T10 || FALU2: T0 << 1(I64)(U)(T) -> FMA2.T10; // r55 batch0 issue 11
FALU0: T2 - T1(I64)(U)(T) -> FMA0.T5 || FALU1: T2 - T1(I64)(U)(T) -> FMA1.T5 || FALU2: T2 - T1(I64)(U)(T) -> FMA2.T5; // r55 batch0 issue 12
FALU0: T10 != 0(I64U) -> FMA0.T10 || FALU1: T10 != 0(I64U) -> FMA1.T10 || FALU2: T10 != 0(I64U) -> FMA2.T10; // r55 batch0 issue 13
FALU0: T5 & T4 -> FMA0.T5 || FALU1: T5 & T4 -> FMA1.T5 || FALU2: T5 & T4 -> FMA2.T5; // r55 batch0 issue 14
FALU0: T10 & T9 -> FMA0.T10 || FALU1: T10 & T9 -> FMA1.T10 || FALU2: T10 & T9 -> FMA2.T10; // r55 batch0 issue 15
FALU0: T3 << T5(I64)(U)(T) -> FMA0.T5 || FALU1: T3 << T5(I64)(U)(T) -> FMA1.T5 || FALU2: T3 << T5(I64)(U)(T) -> FMA2.T5; // r55 batch0 issue 16
FALU0: CompSel1(T10,T7,0)(I64U) -> FMA0.T7 || FALU1: CompSel1(T10,T7,0)(I64U) -> FMA1.T7 || FALU2: CompSel1(T10,T7,0)(I64U) -> FMA2.T7; // r55 batch0 issue 17
FALU0: T5 - T3(I64)(U)(T) -> FMA0.T6 || FALU1: T5 - T3(I64)(U)(T) -> FMA1.T6 || FALU2: T5 - T3(I64)(U)(T) -> FMA2.T6; // r55 batch0 issue 18
FALU0: VE(1023)(L)(U) -> FMA0.T4 || FALU1: VE(1023)(L)(U) -> FMA1.T4 || FALU2: VE(1023)(L)(U) -> FMA2.T4; // r55 batch0 issue 19
FALU0: T0 & T6 -> FMA0.T6 || FALU1: T0 & T6 -> FMA1.T6 || FALU2: T0 & T6 -> FMA2.T6; // r55 batch0 issue 20
FALU0: T4 >> 32(I64)(U) -> FMA0.T4 || FALU1: T4 >> 32(I64)(U) -> FMA1.T4 || FALU2: T4 >> 32(I64)(U) -> FMA2.T4; // r55 batch0 issue 21
FALU0: T0 ^ T6 -> FMA0.T8 || FALU1: T0 ^ T6 -> FMA1.T8 || FALU2: T0 ^ T6 -> FMA2.T8; // r55 batch0 issue 22
FALU0: T6 != 0(I64U) -> FMA0.T6 || FALU1: T6 != 0(I64U) -> FMA1.T6 || FALU2: T6 != 0(I64U) -> FMA2.T6; // r55 batch0 issue 23
NOP; // r55 batch0 issue 24
FALU0: T6 & T9 -> FMA0.T6 || FALU1: T6 & T9 -> FMA1.T6 || FALU2: T6 & T9 -> FMA2.T6; // r55 batch0 issue 25
NOP; // r55 batch0 issue 26
FALU0: CompSel1(T6,T5,0)(I64U) -> FMA0.T5 || FALU1: CompSel1(T6,T5,0)(I64U) -> FMA1.T5 || FALU2: CompSel1(T6,T5,0)(I64U) -> FMA2.T5; // r55 batch0 issue 27
NOP; // r55 batch0 issue 28
FALU0: T8 + T5(I64)(U)(T) -> FMA0.T6 || FALU1: T8 + T5(I64)(U)(T) -> FMA1.T6 || FALU2: T8 + T5(I64)(U)(T) -> FMA2.T6; // r55 batch0 issue 29
NOP; // r55 batch0 issue 30
FALU0: CompSel2(T1,T2,T0,T6)(I64U) -> FMA0.T6 || FALU1: CompSel2(T1,T2,T0,T6)(I64U) -> FMA1.T6 || FALU2: CompSel2(T1,T2,T0,T6)(I64U) -> FMA2.T6; // r55 batch0 issue 31
NOP; // r55 batch0 issue 32
FALU0: CompSel2(T1,T4,T6,T7)(I64U) -> FMA0.T6 || FALU1: CompSel2(T1,T4,T6,T7)(I64U) -> FMA1.T6 || FALU2: CompSel2(T1,T4,T6,T7)(I64U) -> FMA2.T6; // r55 batch0 issue 33
BIU1: KGDWORD(T6[0]) -> FMA0.T1(MODE1); // r55 batch0 issue 34
BIU1: KGDWORD(T7[0]) -> FMA1.T1(MODE1); // r55 batch0 issue 35
BIU1: KGDWORD(T8[0]) -> FMA2.T1(MODE1); // r55 batch0 issue 36
FMA0: FMA0.T0 - FMA0.T6 * 1 (FP64) -> BIU.T1(MODE1); // r55 batch0 issue 37
FMA0: FMA0.T6 - FMA0.T1 * 1 (FP64) -> BIU.T2(MODE1); // r55 batch0 issue 38
FMA1: FMA1.T0 - FMA1.T6 * 1 (FP64) -> BIU.T1(MODE1); // r55 batch0 issue 39
FMA1: FMA1.T6 - FMA1.T1 * 1 (FP64) -> BIU.T2(MODE1); // r55 batch0 issue 40
FMA2: FMA2.T0 - FMA2.T6 * 1 (FP64) -> BIU.T1(MODE1); // r55 batch0 issue 41
FMA2: FMA2.T6 - FMA2.T1 * 1 (FP64) -> BIU.T2(MODE1); // r55 batch0 issue 42
BIU2: STORE(T1,T4[1]+640)(MODE1); // r55 batch0 issue 43
BIU2: STORE(T2,T4[1]+1408)(MODE1); // r55 batch0 issue 44
BIU2: STORE(T1,T4[1]+704)(MODE1); // r55 batch0 issue 45
BIU2: STORE(T2,T4[1]+1472)(MODE1); // r55 batch0 issue 46
BIU2: STORE(T1,T4[1]+768)(MODE1); // r55 batch0 issue 47
BIU2: STORE(T2,T4[1]+1536)(MODE1); // r55 batch0 issue 48
_MPU_PUSHJ_K1_BATCH_FLOOR_POS1:
// r55 exact coordinate bits forwarded into unchanged integer floor graph.
FALU0: VE(1075)(L)(U) -> FMA0.T2 || FALU1: VE(1075)(L)(U) -> FMA1.T2 || FALU2: VE(1075)(L)(U) -> FMA2.T2 || R0: M[0] -> FMA0.T0(MODE1) || R1: M[32] -> FMA1.T0(MODE1) || R2: M[64] -> FMA2.T0(MODE1); // r55 batch1 issue 0
FALU0: VE(1)(L)(U) -> FMA0.T3 || FALU1: VE(1)(L)(U) -> FMA1.T3 || FALU2: VE(1)(L)(U) -> FMA2.T3; // r55 batch1 issue 1
FALU0: T2 >> 32(I64)(U) -> FMA0.T2 || FALU1: T2 >> 32(I64)(U) -> FMA1.T2 || FALU2: T2 >> 32(I64)(U) -> FMA2.T2; // r55 batch1 issue 2
FALU0: T3 >> 32(I64)(U) -> FMA0.T3 || FALU1: T3 >> 32(I64)(U) -> FMA1.T3 || FALU2: T3 >> 32(I64)(U) -> FMA2.T3; // r55 batch1 issue 3
FALU0: VE(63)(L)(U) -> FMA0.T4 || FALU1: VE(63)(L)(U) -> FMA1.T4 || FALU2: VE(63)(L)(U) -> FMA2.T4; // r55 batch1 issue 4
FALU0: VE(0xbff0)(L)(U) -> FMA0.T7 || FALU1: VE(0xbff0)(L)(U) -> FMA1.T7 || FALU2: VE(0xbff0)(L)(U) -> FMA2.T7; // r55 batch1 issue 5
FALU0: T4 >> 32(I64)(U) -> FMA0.T4 || FALU1: T4 >> 32(I64)(U) -> FMA1.T4 || FALU2: T4 >> 32(I64)(U) -> FMA2.T4; // r55 batch1 issue 6
FALU0: T7 << 48(I64)(U)(T) -> FMA0.T7 || FALU1: T7 << 48(I64)(U)(T) -> FMA1.T7 || FALU2: T7 << 48(I64)(U)(T) -> FMA2.T7; // r55 batch1 issue 7
FALU0: T0 << 1(I64)(U)(T) -> FMA0.T1 || FALU1: T0 << 1(I64)(U)(T) -> FMA1.T1 || FALU2: T0 << 1(I64)(U)(T) -> FMA2.T1; // r55 batch1 issue 8
FALU0: T0 < 0(I64) -> FMA0.T9 || FALU1: T0 < 0(I64) -> FMA1.T9 || FALU2: T0 < 0(I64) -> FMA2.T9; // r55 batch1 issue 9
FALU0: T1 >> 53(I64)(U) -> FMA0.T1 || FALU1: T1 >> 53(I64)(U) -> FMA1.T1 || FALU2: T1 >> 53(I64)(U) -> FMA2.T1; // r55 batch1 issue 10
FALU0: T0 << 1(I64)(U)(T) -> FMA0.T10 || FALU1: T0 << 1(I64)(U)(T) -> FMA1.T10 || FALU2: T0 << 1(I64)(U)(T) -> FMA2.T10; // r55 batch1 issue 11
FALU0: T2 - T1(I64)(U)(T) -> FMA0.T5 || FALU1: T2 - T1(I64)(U)(T) -> FMA1.T5 || FALU2: T2 - T1(I64)(U)(T) -> FMA2.T5; // r55 batch1 issue 12
FALU0: T10 != 0(I64U) -> FMA0.T10 || FALU1: T10 != 0(I64U) -> FMA1.T10 || FALU2: T10 != 0(I64U) -> FMA2.T10; // r55 batch1 issue 13
FALU0: T5 & T4 -> FMA0.T5 || FALU1: T5 & T4 -> FMA1.T5 || FALU2: T5 & T4 -> FMA2.T5; // r55 batch1 issue 14
FALU0: T10 & T9 -> FMA0.T10 || FALU1: T10 & T9 -> FMA1.T10 || FALU2: T10 & T9 -> FMA2.T10; // r55 batch1 issue 15
FALU0: T3 << T5(I64)(U)(T) -> FMA0.T5 || FALU1: T3 << T5(I64)(U)(T) -> FMA1.T5 || FALU2: T3 << T5(I64)(U)(T) -> FMA2.T5; // r55 batch1 issue 16
FALU0: CompSel1(T10,T7,0)(I64U) -> FMA0.T7 || FALU1: CompSel1(T10,T7,0)(I64U) -> FMA1.T7 || FALU2: CompSel1(T10,T7,0)(I64U) -> FMA2.T7; // r55 batch1 issue 17
FALU0: T5 - T3(I64)(U)(T) -> FMA0.T6 || FALU1: T5 - T3(I64)(U)(T) -> FMA1.T6 || FALU2: T5 - T3(I64)(U)(T) -> FMA2.T6; // r55 batch1 issue 18
FALU0: VE(1023)(L)(U) -> FMA0.T4 || FALU1: VE(1023)(L)(U) -> FMA1.T4 || FALU2: VE(1023)(L)(U) -> FMA2.T4; // r55 batch1 issue 19
FALU0: T0 & T6 -> FMA0.T6 || FALU1: T0 & T6 -> FMA1.T6 || FALU2: T0 & T6 -> FMA2.T6; // r55 batch1 issue 20
FALU0: T4 >> 32(I64)(U) -> FMA0.T4 || FALU1: T4 >> 32(I64)(U) -> FMA1.T4 || FALU2: T4 >> 32(I64)(U) -> FMA2.T4; // r55 batch1 issue 21
FALU0: T0 ^ T6 -> FMA0.T8 || FALU1: T0 ^ T6 -> FMA1.T8 || FALU2: T0 ^ T6 -> FMA2.T8; // r55 batch1 issue 22
FALU0: T6 != 0(I64U) -> FMA0.T6 || FALU1: T6 != 0(I64U) -> FMA1.T6 || FALU2: T6 != 0(I64U) -> FMA2.T6; // r55 batch1 issue 23
NOP; // r55 batch1 issue 24
FALU0: T6 & T9 -> FMA0.T6 || FALU1: T6 & T9 -> FMA1.T6 || FALU2: T6 & T9 -> FMA2.T6; // r55 batch1 issue 25
NOP; // r55 batch1 issue 26
FALU0: CompSel1(T6,T5,0)(I64U) -> FMA0.T5 || FALU1: CompSel1(T6,T5,0)(I64U) -> FMA1.T5 || FALU2: CompSel1(T6,T5,0)(I64U) -> FMA2.T5; // r55 batch1 issue 27
NOP; // r55 batch1 issue 28
FALU0: T8 + T5(I64)(U)(T) -> FMA0.T6 || FALU1: T8 + T5(I64)(U)(T) -> FMA1.T6 || FALU2: T8 + T5(I64)(U)(T) -> FMA2.T6; // r55 batch1 issue 29
NOP; // r55 batch1 issue 30
FALU0: CompSel2(T1,T2,T0,T6)(I64U) -> FMA0.T6 || FALU1: CompSel2(T1,T2,T0,T6)(I64U) -> FMA1.T6 || FALU2: CompSel2(T1,T2,T0,T6)(I64U) -> FMA2.T6; // r55 batch1 issue 31
NOP; // r55 batch1 issue 32
FALU0: CompSel2(T1,T4,T6,T7)(I64U) -> FMA0.T6 || FALU1: CompSel2(T1,T4,T6,T7)(I64U) -> FMA1.T6 || FALU2: CompSel2(T1,T4,T6,T7)(I64U) -> FMA2.T6; // r55 batch1 issue 33
BIU1: KGDWORD(T6[0]) -> FMA0.T1(MODE1); // r55 batch1 issue 34
BIU1: KGDWORD(T7[0]) -> FMA1.T1(MODE1); // r55 batch1 issue 35
BIU1: KGDWORD(T8[0]) -> FMA2.T1(MODE1); // r55 batch1 issue 36
FMA0: FMA0.T0 - FMA0.T6 * 1 (FP64) -> BIU.T1(MODE1); // r55 batch1 issue 37
FMA0: FMA0.T6 - FMA0.T1 * 1 (FP64) -> BIU.T2(MODE1); // r55 batch1 issue 38
FMA1: FMA1.T0 - FMA1.T6 * 1 (FP64) -> BIU.T1(MODE1); // r55 batch1 issue 39
FMA1: FMA1.T6 - FMA1.T1 * 1 (FP64) -> BIU.T2(MODE1); // r55 batch1 issue 40
FMA2: FMA2.T0 - FMA2.T6 * 1 (FP64) -> BIU.T1(MODE1); // r55 batch1 issue 41
FMA2: FMA2.T6 - FMA2.T1 * 1 (FP64) -> BIU.T2(MODE1); // r55 batch1 issue 42
BIU2: STORE(T1,T4[1]+832)(MODE1); // r55 batch1 issue 43
BIU2: STORE(T2,T4[1]+1600)(MODE1); // r55 batch1 issue 44
BIU2: STORE(T1,T4[1]+896)(MODE1); // r55 batch1 issue 45
BIU2: STORE(T2,T4[1]+1664)(MODE1); // r55 batch1 issue 46
BIU2: STORE(T1,T4[1]+960)(MODE1); // r55 batch1 issue 47
BIU2: STORE(T2,T4[1]+1728)(MODE1); // r55 batch1 issue 48

_MPU_PUSHJ_K1_FULL_WEIGHTS:

// r47: twelve independent original weight graphs on four FMA groups, in three waves.
_MPU_PUSHJ_K1_R47_WEIGHT_WAVE0:
BIU0: 0(E)(L)(U) -> BIU.T0[0] || BIU3: LOAD(T4[1]+640) -> FMA0.T0(MODE1); // r47 wave0 issue 0
BIU0: 0x3fd0(E) -> BIU.T0[1] || BIU3: LOAD(T4[1]+1408) -> FMA0.T1(MODE1); // r47 wave0 issue 1
BIU3: LOAD(T4[1]+960) -> FMA1.T0(MODE1); // r47 wave0 issue 2
BIU1: KGDWord(T0[0]) -> FMA[0,1,2,3].T2 || BIU3: LOAD(T4[1]+1728) -> FMA1.T1(MODE1); // r47 wave0 issue 3
BIU0: 0x3fe0(E) -> BIU.T0[1] || BIU3: LOAD(T4[1]+640) -> FMA2.T0(MODE1); // r47 wave0 issue 4
BIU3: LOAD(T4[1]+1408) -> FMA2.T1(MODE1); // r47 wave0 issue 5
BIU1: KGDWord(T0[0]) -> FMA[0,1,2,3].T3 || BIU3: LOAD(T4[1]+704) -> FMA3.T0(MODE1); // r47 wave0 issue 6
BIU0: 0x3ff0(E) -> BIU.T0[1] || BIU3: LOAD(T4[1]+1472) -> FMA3.T1(MODE1); // r47 wave0 issue 7
NOP; // r47 wave0 issue 8
BIU1: KGDWord(T0[0]) -> FMA[0,1,2,3].T4; // r47 wave0 issue 9
NOP; // r47 wave0 issue 10
NOP; // r47 wave0 issue 11
NOP; // r47 wave0 issue 12
FMA1: T3 + 0 * 1(FP64) -> FMA1.T6; // r47 wave0 issue 13
NOP; // r47 wave0 issue 14
NOP; // r47 wave0 issue 15
FMA0: T1 + T4 * 1(FP64) -> FMA0.T7 || FMA1: T1 + T4 * 1(FP64) -> FMA1.T7; // r47 wave0 issue 16
FMA0: T4 - T0 * 1(FP64) -> FMA0.T5 || FMA1: T4 - T0 * 1(FP64) -> FMA1.T5; // r47 wave0 issue 17
FMA0: T11 + T0 * T0(FP64) -> FMA0.T6 || FALU1: T4 << 11(I64)(U)(T) -> FMA1.T8 || FMA2: T1 + T4 * 1(FP64) -> FMA2.T7; // r47 wave0 issue 18
FALU0: T4 << 11(I64)(U)(T) -> FMA0.T8 || FMA1: T11 + T3 * T0(FP64) -> FMA1.T0 || FMA2: T4 - T0 * 1(FP64) -> FMA2.T5; // r47 wave0 issue 19
FMA0: T11 + T3 * T0(FP64) -> FMA0.T0 || FMA2: T11 + T0 * T0(FP64) -> FMA2.T6; // r47 wave0 issue 20
FALU1: T1 ^ T8 -> FMA1.T1 || FALU2: T4 << 11(I64)(U)(T) -> FMA2.T8 || FMA3: T1 + T4 * 1(FP64) -> FMA3.T7; // r47 wave0 issue 21
FALU0: T1 ^ T8 -> FMA0.T1 || FMA1: T11 + T3 * T5(FP64) -> FMA1.T5 || FMA2: T11 + T3 * T0(FP64) -> FMA2.T0 || FMA3: T4 - T0 * 1(FP64) -> FMA3.T5; // r47 wave0 issue 22
FMA0: T11 + T5 * T5(FP64) -> FMA0.T5 || FMA1: T11 + T6 * T1(FP64) -> FMA1.T4 || FMA3: T11 + T0 * T0(FP64) -> FMA3.T6; // r47 wave0 issue 23
FMA0: T11 + T2 * T6(FP64) -> FMA0.T6 || FMA1: T11 + T6 * T7(FP64) -> FMA1.T8 || FALU2: T1 ^ T8 -> FMA2.T1 || FALU3: T4 << 11(I64)(U)(T) -> FMA3.T8; // r47 wave0 issue 24
FMA0: T2 + T0 * 1(FP64) -> FMA0.T0 || FMA1: T11 + T0 * T1(FP64) -> FMA1.T9 || FMA2: T11 + T5 * T5(FP64) -> FMA2.T5 || FMA3: T11 + T3 * T0(FP64) -> FMA3.T0; // r47 wave0 issue 25
FMA1: T11 + T0 * T7(FP64) -> BIU.T2 || FMA2: T11 + T2 * T6(FP64) -> FMA2.T6; // r47 wave0 issue 26
FMA1: T11 + T5 * T7(FP64) -> FMA1.T2 || FMA2: T2 + T0 * 1(FP64) -> FMA2.T0 || FALU3: T1 ^ T8 -> FMA3.T1; // r47 wave0 issue 27
FMA0: T11 + T2 * T5(FP64) -> FMA0.T5 || FMA1: T11 + T5 * T1(FP64) -> BIU.T2 || FALU2: 0 | 0 -> BIU.T3 || FMA3: T11 + T5 * T5(FP64) -> FMA3.T5; // r47 wave0 issue 28
FMA0: T3 - T6 * 1(FP64) -> FMA0.T3 || FMA3: T11 + T2 * T6(FP64) -> FMA3.T6; // r47 wave0 issue 29
FMA0: T0 - T6 * 1(FP64) -> FMA0.T0 || FMA1: T8 + T9 * 1(FP64) -> BIU.T2 || FMA2: T11 + T2 * T5(FP64) -> FMA2.T5 || FMA3: T2 + T0 * 1(FP64) -> FMA3.T0; // r47 wave0 issue 30
FMA0: T11 + T6 * T1(FP64) -> FMA0.T6 || FMA2: T11 + T6 * T1(FP64) -> FMA2.T9 || BIU2: Store(T3, T4[4] + 896) || FALU3: 0 | 0 -> BIU.T0; // r47 wave0 issue 31
FMA0: T11 + T6 * T7(FP64) -> BIU.T1 || BIU2: Store(T2, T4[6] + 1472) || FMA2: T11 + T0 * T7(FP64) -> FMA2.T8; // r47 wave0 issue 32
FMA0: T11 + T5 * T7(FP64) -> FMA0.T2 || FMA1: T2 + T4 * 1(FP64) -> BIU.T2 || FMA2: T11 + T6 * T7(FP64) -> BIU.T3 || FMA3: T11 + T2 * T5(FP64) -> FMA3.T5; // r47 wave0 issue 33
FMA0: T11 + T5 * T1(FP64) -> BIU.T1 || BIU2: Store(T2, T4[6] + 1280) || FMA3: T11 + T6 * T1(FP64) -> FMA3.T9 || BIU3: Store(T0, T4[5] + 896); // r47 wave0 issue 34
FMA0: T11 + T3 * T1(FP64) -> FMA0.T4 || FMA2: T4 - T5 * 1(FP64) -> FMA2.T5 || FMA3: T11 + T0 * T7(FP64) -> FMA3.T8; // r47 wave0 issue 35
FMA0: T11 + T3 * T7(FP64) -> FMA0.T8 || BIU2: Store(T2, T4[6] + 1408) || FMA2: T11 + T0 * T1(FP64) -> FMA2.T4 || FMA3: T11 + T6 * T7(FP64) -> BIU.T0; // r47 wave0 issue 36
FMA0: T11 + T0 * T1(FP64) -> FMA0.T9 || FMA2: T8 + T9 * 1(FP64) -> BIU.T3; // r47 wave0 issue 37
FMA0: T11 + T0 * T7(FP64) -> FMA0.T10 || BIU2: Store(T1, T4[4] + 256) || FALU1: 0 | 0 -> BIU.T2 || FMA3: T4 - T5 * 1(FP64) -> FMA3.T5; // r47 wave0 issue 38
BIU2: Store(T2, T4[6] + 1344) || BIU3: Store(T3, T4[4] + 832) || FMA3: T11 + T0 * T1(FP64) -> FMA3.T4; // r47 wave0 issue 39
FMA0: T2 + T4 * 1(FP64) -> BIU.T1 || BIU2: Store(T1, T4[4] + 0) || FMA2: T11 + T5 * T1(FP64) -> FMA2.T2 || FMA3: T8 + T9 * 1(FP64) -> BIU.T0; // r47 wave0 issue 40
FMA2: T11 + T5 * T7(FP64) -> FMA2.T3; // r47 wave0 issue 41
FMA0: T8 + T9 * 1(FP64) -> BIU.T1 || BIU2: Store(T2, T4[6] + 1536) || BIU3: Store(T0, T4[5] + 832); // r47 wave0 issue 42
BIU2: Store(T3, T4[4] + 768) || FMA3: T11 + T5 * T1(FP64) -> FMA3.T2; // r47 wave0 issue 43
FMA0: T10 + T6 * 1(FP64) -> BIU.T1 || FMA3: T11 + T5 * T7(FP64) -> FMA3.T3; // r47 wave0 issue 44
FMA2: T7 + T2 * 1(FP64) -> BIU.T3; // r47 wave0 issue 45
BIU2: Store(T1, T4[4] + 64) || BIU3: Store(T0, T4[5] + 768); // r47 wave0 issue 46
FMA2: T3 + T4 * 1(FP64) -> BIU.T3; // r47 wave0 issue 47
BIU2: Store(T1, T4[4] + 128) || FMA3: T7 + T2 * 1(FP64) -> BIU.T0; // r47 wave0 issue 48
NOP; // r47 wave0 issue 49
BIU2: Store(T1, T4[4] + 192) || FMA3: T3 + T4 * 1(FP64) -> BIU.T0; // r47 wave0 issue 50
BIU2: Store(T3, T4[4] + 640); // r47 wave0 issue 51
NOP; // r47 wave0 issue 52
BIU2: Store(T3, T4[4] + 704); // r47 wave0 issue 53
BIU2: Store(T0, T4[5] + 640); // r47 wave0 issue 54
NOP; // r47 wave0 issue 55
BIU2: Store(T0, T4[5] + 704); // r47 wave0 issue 56
_MPU_PUSHJ_K1_R47_WEIGHT_WAVE1:
BIU0: 0(E)(L)(U) -> BIU.T0[0] || BIU3: LOAD(T4[1]+832) -> FMA0.T0(MODE1); // r47 wave1 issue 0
BIU0: 0x3fd0(E) -> BIU.T0[1] || BIU3: LOAD(T4[1]+1600) -> FMA0.T1(MODE1); // r47 wave1 issue 1
BIU3: LOAD(T4[1]+896) -> FMA1.T0(MODE1); // r47 wave1 issue 2
BIU1: KGDWord(T0[0]) -> FMA[0,1,2,3].T2 || BIU3: LOAD(T4[1]+1664) -> FMA1.T1(MODE1); // r47 wave1 issue 3
BIU0: 0x3fe0(E) -> BIU.T0[1] || BIU3: LOAD(T4[1]+832) -> FMA2.T0(MODE1); // r47 wave1 issue 4
BIU3: LOAD(T4[1]+1600) -> FMA2.T1(MODE1); // r47 wave1 issue 5
BIU1: KGDWord(T0[0]) -> FMA[0,1,2,3].T3 || BIU3: LOAD(T4[1]+896) -> FMA3.T0(MODE1); // r47 wave1 issue 6
BIU0: 0x3ff0(E) -> BIU.T0[1] || BIU3: LOAD(T4[1]+1664) -> FMA3.T1(MODE1); // r47 wave1 issue 7
NOP; // r47 wave1 issue 8
BIU1: KGDWord(T0[0]) -> FMA[0,1,2,3].T4; // r47 wave1 issue 9
NOP; // r47 wave1 issue 10
NOP; // r47 wave1 issue 11
NOP; // r47 wave1 issue 12
FMA1: T3 + 0 * 1(FP64) -> FMA1.T6; // r47 wave1 issue 13
NOP; // r47 wave1 issue 14
NOP; // r47 wave1 issue 15
FMA0: T1 + T4 * 1(FP64) -> FMA0.T7 || FMA1: T1 + T4 * 1(FP64) -> FMA1.T7; // r47 wave1 issue 16
FMA0: T4 - T0 * 1(FP64) -> FMA0.T5 || FMA1: T4 - T0 * 1(FP64) -> FMA1.T5; // r47 wave1 issue 17
FMA0: T11 + T0 * T0(FP64) -> FMA0.T6 || FALU1: T4 << 11(I64)(U)(T) -> FMA1.T8 || FMA2: T1 + T4 * 1(FP64) -> FMA2.T7; // r47 wave1 issue 18
FALU0: T4 << 11(I64)(U)(T) -> FMA0.T8 || FMA1: T11 + T3 * T0(FP64) -> FMA1.T0 || FMA2: T4 - T0 * 1(FP64) -> FMA2.T5; // r47 wave1 issue 19
FMA0: T11 + T3 * T0(FP64) -> FMA0.T0 || FMA2: T11 + T0 * T0(FP64) -> FMA2.T6; // r47 wave1 issue 20
FALU1: T1 ^ T8 -> FMA1.T1 || FALU2: T4 << 11(I64)(U)(T) -> FMA2.T8; // r47 wave1 issue 21
FALU0: T1 ^ T8 -> FMA0.T1 || FMA1: T11 + T3 * T5(FP64) -> FMA1.T5 || FMA2: T11 + T3 * T0(FP64) -> FMA2.T0 || FMA3: T1 + T4 * 1(FP64) -> FMA3.T7; // r47 wave1 issue 22
FMA0: T11 + T5 * T5(FP64) -> FMA0.T5 || FMA1: T11 + T6 * T1(FP64) -> FMA1.T4 || FMA3: T4 - T0 * 1(FP64) -> FMA3.T5; // r47 wave1 issue 23
FMA0: T11 + T2 * T6(FP64) -> FMA0.T6 || FMA1: T11 + T6 * T7(FP64) -> FMA1.T8 || FALU2: T1 ^ T8 -> FMA2.T1 || FMA3: T11 + T0 * T0(FP64) -> FMA3.T6; // r47 wave1 issue 24
FMA0: T2 + T0 * 1(FP64) -> FMA0.T0 || FMA1: T11 + T0 * T1(FP64) -> FMA1.T9 || FMA2: T11 + T5 * T5(FP64) -> FMA2.T5 || FALU3: T4 << 11(I64)(U)(T) -> FMA3.T8; // r47 wave1 issue 25
FMA1: T11 + T0 * T7(FP64) -> BIU.T2 || FMA2: T11 + T2 * T6(FP64) -> FMA2.T6 || FMA3: T11 + T3 * T0(FP64) -> FMA3.T0; // r47 wave1 issue 26
FMA1: T11 + T5 * T7(FP64) -> FMA1.T2 || FMA2: T2 + T0 * 1(FP64) -> FMA2.T0; // r47 wave1 issue 27
FMA0: T11 + T2 * T5(FP64) -> FMA0.T5 || FMA1: T11 + T5 * T1(FP64) -> BIU.T2 || FALU2: 0 | 0 -> BIU.T3 || FALU3: T1 ^ T8 -> FMA3.T1; // r47 wave1 issue 28
FMA0: T3 - T6 * 1(FP64) -> FMA0.T3 || FMA3: T11 + T5 * T5(FP64) -> FMA3.T5; // r47 wave1 issue 29
FMA0: T0 - T6 * 1(FP64) -> FMA0.T0 || FMA1: T8 + T9 * 1(FP64) -> BIU.T2 || FMA2: T11 + T2 * T5(FP64) -> FMA2.T5 || FMA3: T11 + T2 * T6(FP64) -> FMA3.T6; // r47 wave1 issue 30
FMA0: T11 + T6 * T1(FP64) -> FMA0.T6 || FMA2: T11 + T6 * T1(FP64) -> FMA2.T9 || BIU2: Store(T3, T4[4] + 1856) || FMA3: T2 + T0 * 1(FP64) -> FMA3.T0; // r47 wave1 issue 31
FMA0: T11 + T6 * T7(FP64) -> BIU.T1 || BIU2: Store(T2, T4[5] + 1472) || FMA2: T11 + T0 * T7(FP64) -> FMA2.T8; // r47 wave1 issue 32
FMA0: T11 + T5 * T7(FP64) -> FMA0.T2 || FMA1: T2 + T4 * 1(FP64) -> BIU.T2 || FMA2: T11 + T6 * T7(FP64) -> BIU.T3; // r47 wave1 issue 33
FMA0: T11 + T5 * T1(FP64) -> BIU.T1 || BIU2: Store(T2, T4[5] + 1280) || FMA3: T11 + T2 * T5(FP64) -> FMA3.T5; // r47 wave1 issue 34
FMA0: T11 + T3 * T1(FP64) -> FMA0.T4 || FMA2: T4 - T5 * 1(FP64) -> FMA2.T5 || FMA3: T3 - T6 * 1(FP64) -> FMA3.T3; // r47 wave1 issue 35
FMA0: T11 + T3 * T7(FP64) -> FMA0.T8 || BIU2: Store(T2, T4[5] + 1408) || FMA2: T11 + T0 * T1(FP64) -> FMA2.T4 || FMA3: T0 - T6 * 1(FP64) -> FMA3.T0; // r47 wave1 issue 36
FMA0: T11 + T0 * T1(FP64) -> FMA0.T9 || FMA2: T8 + T9 * 1(FP64) -> BIU.T3 || FMA3: T11 + T6 * T1(FP64) -> FMA3.T6; // r47 wave1 issue 37
FMA0: T11 + T0 * T7(FP64) -> FMA0.T10 || BIU2: Store(T1, T4[4] + 1216) || FALU1: 0 | 0 -> BIU.T2 || FMA3: T11 + T6 * T7(FP64) -> BIU.T0; // r47 wave1 issue 38
BIU2: Store(T2, T4[5] + 1344) || BIU3: Store(T3, T4[4] + 1792) || FMA3: T11 + T5 * T7(FP64) -> FMA3.T2; // r47 wave1 issue 39
FMA0: T2 + T4 * 1(FP64) -> BIU.T1 || BIU2: Store(T1, T4[4] + 960) || FMA2: T11 + T5 * T1(FP64) -> FMA2.T2 || FMA3: T11 + T5 * T1(FP64) -> BIU.T0; // r47 wave1 issue 40
FMA2: T11 + T5 * T7(FP64) -> FMA2.T3 || FMA3: T11 + T3 * T1(FP64) -> FMA3.T4; // r47 wave1 issue 41
FMA0: T8 + T9 * 1(FP64) -> BIU.T1 || BIU2: Store(T2, T4[5] + 1536) || FMA3: T11 + T3 * T7(FP64) -> FMA3.T8; // r47 wave1 issue 42
BIU2: Store(T3, T4[4] + 1728) || FMA3: T11 + T0 * T1(FP64) -> FMA3.T9; // r47 wave1 issue 43
FMA0: T10 + T6 * 1(FP64) -> BIU.T1 || FMA3: T11 + T0 * T7(FP64) -> FMA3.T10 || BIU2: Store(T0, T4[5] + 1216); // r47 wave1 issue 44
FMA2: T7 + T2 * 1(FP64) -> BIU.T3; // r47 wave1 issue 45
BIU2: Store(T1, T4[4] + 1024) || FMA3: T2 + T4 * 1(FP64) -> BIU.T0 || BIU3: Store(T0, T4[5] + 960); // r47 wave1 issue 46
FMA2: T3 + T4 * 1(FP64) -> BIU.T3; // r47 wave1 issue 47
BIU2: Store(T1, T4[4] + 1088) || FMA3: T8 + T9 * 1(FP64) -> BIU.T0; // r47 wave1 issue 48
NOP; // r47 wave1 issue 49
BIU2: Store(T1, T4[4] + 1152) || FMA3: T10 + T6 * 1(FP64) -> BIU.T0; // r47 wave1 issue 50
BIU2: Store(T3, T4[4] + 1600); // r47 wave1 issue 51
BIU2: Store(T0, T4[5] + 1024); // r47 wave1 issue 52
BIU2: Store(T3, T4[4] + 1664); // r47 wave1 issue 53
BIU2: Store(T0, T4[5] + 1088); // r47 wave1 issue 54
NOP; // r47 wave1 issue 55
BIU2: Store(T0, T4[5] + 1152); // r47 wave1 issue 56
_MPU_PUSHJ_K1_R47_WEIGHT_WAVE2:
BIU0: 0(E)(L)(U) -> BIU.T0[0] || BIU3: LOAD(T4[1]+960) -> FMA0.T0(MODE1); // r47 wave2 issue 0
BIU0: 0x3fd0(E) -> BIU.T0[1] || BIU3: LOAD(T4[1]+1728) -> FMA0.T1(MODE1); // r47 wave2 issue 1
BIU3: LOAD(T4[1]+832) -> FMA1.T0(MODE1); // r47 wave2 issue 2
BIU1: KGDWord(T0[0]) -> FMA[0,1,2,3].T2 || BIU3: LOAD(T4[1]+1600) -> FMA1.T1(MODE1); // r47 wave2 issue 3
BIU0: 0x3fe0(E) -> BIU.T0[1] || BIU3: LOAD(T4[1]+896) -> FMA2.T0(MODE1); // r47 wave2 issue 4
BIU3: LOAD(T4[1]+1664) -> FMA2.T1(MODE1); // r47 wave2 issue 5
BIU1: KGDWord(T0[0]) -> FMA[0,1,2,3].T3 || BIU3: LOAD(T4[1]+960) -> FMA3.T0(MODE1); // r47 wave2 issue 6
BIU0: 0x3ff0(E) -> BIU.T0[1] || BIU3: LOAD(T4[1]+1728) -> FMA3.T1(MODE1); // r47 wave2 issue 7
NOP; // r47 wave2 issue 8
BIU1: KGDWord(T0[0]) -> FMA[0,1,2,3].T4; // r47 wave2 issue 9
NOP; // r47 wave2 issue 10
NOP; // r47 wave2 issue 11
NOP; // r47 wave2 issue 12
FMA1: T3 + 0 * 1(FP64) -> FMA1.T6; // r47 wave2 issue 13
NOP; // r47 wave2 issue 14
NOP; // r47 wave2 issue 15
FMA0: T1 + T4 * 1(FP64) -> FMA0.T7 || FMA1: T1 + T4 * 1(FP64) -> FMA1.T7; // r47 wave2 issue 16
FMA0: T4 - T0 * 1(FP64) -> FMA0.T5 || FMA1: T4 - T0 * 1(FP64) -> FMA1.T5; // r47 wave2 issue 17
FMA0: T11 + T0 * T0(FP64) -> FMA0.T6 || FALU1: T4 << 11(I64)(U)(T) -> FMA1.T8; // r47 wave2 issue 18
FALU0: T4 << 11(I64)(U)(T) -> FMA0.T8 || FMA1: T11 + T3 * T0(FP64) -> FMA1.T0 || FMA2: T1 + T4 * 1(FP64) -> FMA2.T7; // r47 wave2 issue 19
FMA0: T11 + T3 * T0(FP64) -> FMA0.T0 || FMA2: T4 - T0 * 1(FP64) -> FMA2.T5 || FMA3: T1 + T4 * 1(FP64) -> FMA3.T7; // r47 wave2 issue 20
FALU1: T1 ^ T8 -> FMA1.T1 || FMA2: T11 + T0 * T0(FP64) -> FMA2.T6 || FMA3: T4 - T0 * 1(FP64) -> FMA3.T5; // r47 wave2 issue 21
FALU0: T1 ^ T8 -> FMA0.T1 || FMA1: T11 + T3 * T5(FP64) -> FMA1.T5 || FALU2: T4 << 11(I64)(U)(T) -> FMA2.T8 || FMA3: T11 + T0 * T0(FP64) -> FMA3.T6; // r47 wave2 issue 22
FMA0: T11 + T5 * T5(FP64) -> FMA0.T5 || FMA1: T11 + T6 * T1(FP64) -> FMA1.T4 || FMA2: T11 + T3 * T0(FP64) -> FMA2.T0 || FALU3: T4 << 11(I64)(U)(T) -> FMA3.T8; // r47 wave2 issue 23
FMA0: T11 + T2 * T6(FP64) -> FMA0.T6 || FMA1: T11 + T6 * T7(FP64) -> FMA1.T8 || FMA3: T11 + T3 * T0(FP64) -> FMA3.T0; // r47 wave2 issue 24
FMA0: T2 + T0 * 1(FP64) -> FMA0.T0 || FMA1: T11 + T0 * T1(FP64) -> FMA1.T9 || FALU2: T1 ^ T8 -> FMA2.T1; // r47 wave2 issue 25
FMA1: T11 + T0 * T7(FP64) -> BIU.T2 || FMA2: T11 + T5 * T5(FP64) -> FMA2.T5 || FALU3: T1 ^ T8 -> FMA3.T1; // r47 wave2 issue 26
FMA1: T11 + T5 * T7(FP64) -> FMA1.T2 || FMA2: T11 + T2 * T6(FP64) -> FMA2.T6 || FMA3: T11 + T5 * T5(FP64) -> FMA3.T5; // r47 wave2 issue 27
FMA0: T11 + T2 * T5(FP64) -> FMA0.T5 || FMA1: T11 + T5 * T1(FP64) -> BIU.T2 || FMA2: T2 + T0 * 1(FP64) -> FMA2.T0 || FMA3: T11 + T2 * T6(FP64) -> FMA3.T6; // r47 wave2 issue 28
FMA0: T3 - T6 * 1(FP64) -> FMA0.T3 || FALU2: 0 | 0 -> BIU.T3 || FMA3: T2 + T0 * 1(FP64) -> FMA3.T0; // r47 wave2 issue 29
FMA0: T0 - T6 * 1(FP64) -> FMA0.T0 || FMA1: T8 + T9 * 1(FP64) -> BIU.T2 || FALU3: 0 | 0 -> BIU.T0; // r47 wave2 issue 30
FMA0: T11 + T6 * T1(FP64) -> FMA0.T6 || FMA2: T11 + T2 * T5(FP64) -> FMA2.T5; // r47 wave2 issue 31
FMA0: T11 + T6 * T7(FP64) -> BIU.T1 || BIU2: Store(T2, T4[4] + 1472) || FMA2: T11 + T6 * T1(FP64) -> FMA2.T9 || BIU3: Store(T3, T4[5] + 1856) || FMA3: T11 + T2 * T5(FP64) -> FMA3.T5; // r47 wave2 issue 32
FMA0: T11 + T5 * T7(FP64) -> FMA0.T2 || FMA1: T2 + T4 * 1(FP64) -> BIU.T2 || FMA2: T11 + T0 * T7(FP64) -> FMA2.T8 || FMA3: T11 + T6 * T1(FP64) -> FMA3.T9 || BIU2: Store(T0, T4[6] + 1856); // r47 wave2 issue 33
FMA0: T11 + T5 * T1(FP64) -> BIU.T1 || BIU2: Store(T2, T4[4] + 1280) || FMA2: T11 + T6 * T7(FP64) -> BIU.T3 || FMA3: T11 + T0 * T7(FP64) -> FMA3.T8; // r47 wave2 issue 34
FMA0: T11 + T3 * T1(FP64) -> FMA0.T4 || FMA3: T11 + T6 * T7(FP64) -> BIU.T0; // r47 wave2 issue 35
FMA0: T11 + T3 * T7(FP64) -> FMA0.T8 || BIU2: Store(T2, T4[4] + 1408) || FMA2: T4 - T5 * 1(FP64) -> FMA2.T5; // r47 wave2 issue 36
FMA0: T11 + T0 * T1(FP64) -> FMA0.T9 || FMA2: T11 + T0 * T1(FP64) -> FMA2.T4 || FMA3: T4 - T5 * 1(FP64) -> FMA3.T5; // r47 wave2 issue 37
FMA0: T11 + T0 * T7(FP64) -> FMA0.T10 || BIU2: Store(T1, T4[6] + 1216) || FALU1: 0 | 0 -> BIU.T2 || FMA2: T8 + T9 * 1(FP64) -> BIU.T3 || FMA3: T11 + T0 * T1(FP64) -> FMA3.T4; // r47 wave2 issue 38
BIU2: Store(T2, T4[4] + 1344) || FMA3: T8 + T9 * 1(FP64) -> BIU.T0; // r47 wave2 issue 39
FMA0: T2 + T4 * 1(FP64) -> BIU.T1 || BIU2: Store(T1, T4[6] + 960) || BIU3: Store(T3, T4[5] + 1792); // r47 wave2 issue 40
FMA2: T11 + T5 * T1(FP64) -> FMA2.T2 || BIU2: Store(T0, T4[6] + 1792); // r47 wave2 issue 41
FMA0: T8 + T9 * 1(FP64) -> BIU.T1 || BIU2: Store(T2, T4[4] + 1536) || FMA2: T11 + T5 * T7(FP64) -> FMA2.T3 || FMA3: T11 + T5 * T1(FP64) -> FMA3.T2; // r47 wave2 issue 42
FMA3: T11 + T5 * T7(FP64) -> FMA3.T3; // r47 wave2 issue 43
FMA0: T10 + T6 * 1(FP64) -> BIU.T1 || BIU2: Store(T3, T4[5] + 1728); // r47 wave2 issue 44
BIU2: Store(T0, T4[6] + 1728); // r47 wave2 issue 45
BIU2: Store(T1, T4[6] + 1024) || FMA2: T7 + T2 * 1(FP64) -> BIU.T3; // r47 wave2 issue 46
FMA3: T7 + T2 * 1(FP64) -> BIU.T0; // r47 wave2 issue 47
BIU2: Store(T1, T4[6] + 1088) || FMA2: T3 + T4 * 1(FP64) -> BIU.T3; // r47 wave2 issue 48
FMA3: T3 + T4 * 1(FP64) -> BIU.T0; // r47 wave2 issue 49
BIU2: Store(T1, T4[6] + 1152); // r47 wave2 issue 50
NOP; // r47 wave2 issue 51
BIU2: Store(T3, T4[5] + 1600); // r47 wave2 issue 52
BIU2: Store(T0, T4[6] + 1600); // r47 wave2 issue 53
BIU2: Store(T3, T4[5] + 1664); // r47 wave2 issue 54
BIU2: Store(T0, T4[6] + 1664); // r47 wave2 issue 55
MFETCH: Repeat @(9); // final bank stores visible before path loads
_MPU_PUSHJ_K1_FULL_PATHS:
BIU0: LOAD(T4[4]+1600) -> FMA0.T0(MODE1) || BIU1: LOAD(T4[5]+1600) -> FMA0.T2(MODE1); // r24 path pipeline issue 0
BIU0: LOAD(T4[4]+640) -> FMA0.T1(MODE1) || BIU1: LOAD(T4[5]+640) -> FMA0.T3(MODE1); // r24 path pipeline issue 1
BIU0: LOAD(T4[4]+1664) -> FMA1.T0(MODE1) || BIU1: LOAD(T4[5]+1664) -> FMA1.T2(MODE1); // r24 path pipeline issue 2
BIU0: LOAD(T4[4]+704) -> FMA1.T1(MODE1) || BIU1: LOAD(T4[5]+704) -> FMA1.T3(MODE1); // r24 path pipeline issue 3
BIU0: LOAD(T4[4]+1728) -> FMA2.T0(MODE1) || BIU1: LOAD(T4[5]+1728) -> FMA2.T2(MODE1); // r24 path pipeline issue 4
BIU0: LOAD(T4[4]+768) -> FMA2.T1(MODE1) || BIU1: LOAD(T4[5]+768) -> FMA2.T3(MODE1); // r24 path pipeline issue 5
BIU0: LOAD(T4[4]+1792) -> FMA3.T0(MODE1) || BIU1: LOAD(T4[5]+1792) -> FMA3.T2(MODE1); // r24 path pipeline issue 6
BIU0: LOAD(T4[4]+832) -> FMA3.T1(MODE1) || BIU1: LOAD(T4[5]+832) -> FMA3.T3(MODE1); // r24 path pipeline issue 7
BIU0: LOAD(T4[4]+1856) -> FMA0.T4(MODE1) || BIU1: LOAD(T4[5]+1856) -> FMA0.T6(MODE1); // r24 path pipeline issue 8
BIU0: LOAD(T4[4]+896) -> FMA0.T5(MODE1) || BIU1: LOAD(T4[5]+896) -> FMA0.T7(MODE1); // r24 path pipeline issue 9
NOP; // r24 path pipeline issue 10
NOP; // r24 path pipeline issue 11
NOP; // r24 path pipeline issue 12
NOP; // r24 path pipeline issue 13
FMA0: FMA0.T0 - FMA0.T1 * 1 (FP64) -> BIU.T0(MODE1); // r24 path pipeline issue 14
FMA0: FMA0.T2 - FMA0.T3 * 1 (FP64) -> BIU.T1(MODE1); // r24 path pipeline issue 15
FMA1: FMA1.T0 - FMA1.T1 * 1 (FP64) -> BIU.T0(MODE1); // r24 path pipeline issue 16
FMA1: FMA1.T2 - FMA1.T3 * 1 (FP64) -> BIU.T1(MODE1); // r24 path pipeline issue 17
FMA2: FMA2.T0 - FMA2.T1 * 1 (FP64) -> BIU.T0(MODE1); // r24 path pipeline issue 18
FMA2: FMA2.T2 - FMA2.T3 * 1 (FP64) -> BIU.T1(MODE1); // r24 path pipeline issue 19
BIU2: STORE(T0,T4[4]+320)(MODE1) || FMA3: FMA3.T0 - FMA3.T1 * 1 (FP64) -> BIU.T0(MODE1); // r24 path pipeline issue 20
BIU2: STORE(T1,T4[5]+0)(MODE1) || FMA3: FMA3.T2 - FMA3.T3 * 1 (FP64) -> BIU.T1(MODE1); // r24 path pipeline issue 21
BIU2: STORE(T0,T4[4]+384)(MODE1) || FMA0: FMA0.T4 - FMA0.T5 * 1 (FP64) -> BIU.T0(MODE1); // r24 path pipeline issue 22
BIU2: STORE(T1,T4[5]+64)(MODE1) || FMA0: FMA0.T6 - FMA0.T7 * 1 (FP64) -> BIU.T1(MODE1); // r24 path pipeline issue 23
BIU2: STORE(T0,T4[4]+448)(MODE1); // r24 path pipeline issue 24
BIU2: STORE(T1,T4[5]+128)(MODE1); // r24 path pipeline issue 25
BIU2: STORE(T0,T4[4]+512)(MODE1); // r24 path pipeline issue 26
BIU2: STORE(T1,T4[5]+192)(MODE1); // r24 path pipeline issue 27
BIU2: STORE(T0,T4[4]+576)(MODE1); // r24 path pipeline issue 28
BIU2: STORE(T1,T4[5]+256)(MODE1); // r24 path pipeline issue 29

_MPU_PUSHJ_K1_FULL_END:
// r48: K1 never changes KI15; restore exact incoming descriptor and native BIU registers.
R1: M[250] -> BIU.T4(MODE1) || R2: M[254] -> BIU.T8(MODE1) || R3: M[249] -> BIU.T15(MODE1);
R1: M[251] -> BIU.T5(MODE1) || R2: M[255] -> BIU.T9(MODE1);
R1: M[252] -> BIU.T6(MODE1);
R1: M[253] -> BIU.T7(MODE1);
_MPU_PUSHJ_K1_FULL_RETURN:
MFETCH: Repeat @(8);
    MFETCH: Jump KI15; // h0803 
    MFETCH: NOP; // h0804 safe return delay slot
.size candidate_k1, .-candidate_k1
