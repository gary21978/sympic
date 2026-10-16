.section ".text.m0.candidate_K2.@public","axr",@progbits
.global candidate_K2
.type candidate_K2,@function
candidate_K2:
// r45 native preservation in reserved M243..255. T15 remains untouched.
BIU0: KG(T3) -> M[244](MODE1) || MFETCH: KI0 -> BIU.T0[7]; // r45 entry 0
BIU0: KG(T4) -> M[245](MODE1) || MFETCH: KI5 -> BIU.T0[6]; // r45 entry 1
BIU0: KG(T5) -> M[246](MODE1); // r45 entry 2
BIU0: KG(T6) -> M[247](MODE1) || BIU1: LOAD(T0[7]+12) (I32) -> BIU.T12[7](MODE1); // r45 entry 3; owned-bank v1
BIU0: KG(T7) -> M[248](MODE1) || MFETCH: KI0 -> BIU.T3[0] || BIU1: LOAD(T0[7]+16) (I32) -> BIU.T12[11](MODE1); // r45 entry 4; owned-bank v1
BIU0: KG(T8) -> M[249](MODE1) || MFETCH: KI1 -> BIU.T3[1] || BIU1: LOAD(T0[7]+20) (I32) -> BIU.T12[12](MODE1); // r45 entry 5; owned-bank v1
BIU0: KG(T9) -> M[250](MODE1) || MFETCH: KI2 -> BIU.T3[2] || BIU1: LOAD(T0[7]+24) (I32) -> BIU.T12[13](MODE1); // r45 entry 6; owned-bank v1
BIU0: KG(T10) -> M[251](MODE1) || MFETCH: KI3 -> BIU.T3[3] || BIU1: LOAD(T0[7]+28) (I32) -> BIU.T12[15](MODE1); // r45 entry 7
BIU0: KG(T11) -> M[252](MODE1) || MFETCH: KI4 -> BIU.T3[4]; // r45 entry 8
BIU0: KG(T12) -> M[253](MODE1) || MFETCH: KI5 -> BIU.T3[5]; // r45 entry 9
BIU0: KG(T13) -> M[254](MODE1) || MFETCH: KI6 -> BIU.T3[6] || BIU1: LOADI64(T0[6]+80) -> BIU.T1(MODE1); // r45 entry 10; r58 ctx prefetch
BIU0: KG(T14) -> M[255](MODE1) || MFETCH: KI7 -> BIU.T3[7] || BIU1: LOADI64(T0[6]+88) -> BIU.T2(MODE1); // r45 entry 11; r58 ctx prefetch
MFETCH: KI8 -> BIU.T3[8] || BIU1: LOADI64(T0[6]+96) -> BIU.T3(MODE1); // r45 entry 12; r58 ctx prefetch
MFETCH: KI9 -> BIU.T3[9] || BIU1: LOADI64(T0[6]+104) -> BIU.T4(MODE1); // r45 entry 13; r58 ctx prefetch
MFETCH: KI10 -> BIU.T3[10] || BIU1: LOADI64(T0[6]+112) -> BIU.T5(MODE1); // r45 entry 14; r58 ctx prefetch
MFETCH: KI11 -> BIU.T3[11] || BIU1: LOADI64(T0[6]+120) -> BIU.T6(MODE1); // r45 entry 15; r58 ctx prefetch
MFETCH: KI12 -> BIU.T3[12] || BIU1: LOADI64(T0[6]+128) -> BIU.T7(MODE1); // r45 entry 16; r58 ctx prefetch
MFETCH: KI13 -> BIU.T3[13]; // r45 entry 17
MFETCH: KI14 -> BIU.T3[14]; // r45 entry 18
MFETCH: KI15 -> BIU.T3[15]; // r45 entry 19
NOP; // r45 entry 20
NOP; // r45 entry 21
NOP; // r45 entry 22
BIU0: KG(T3) -> M[243](MODE1); // r45 entry 23
MFETCH: KI0 -> BIU.T12[0];
MFETCH: KI1 -> BIU.T12[1];
MFETCH: KI2 -> BIU.T12[2];
MFETCH: KI3 -> BIU.T12[3];
MFETCH: KI4 -> BIU.T12[4];
MFETCH: KI5 -> BIU.T12[5];
MFETCH: KI6 -> BIU.T12[6];
MFETCH: %k2_weights -> KI9 (L)(U) || BIU2: LOAD(T12[0] + 0) (I32) -> BIU.T12[8](MODE1);
MFETCH: %k2_weights -> KI9 (U) || BIU2: LOAD(T12[0] + 4) (I32) -> BIU.T12[9](MODE1);
MFETCH: %k2_reciprocal_rn -> KI12 (L)(U) || BIU2: LOAD(T12[0] + 8) (I32) -> BIU.T12[10](MODE1);
MFETCH: %k2_reciprocal_rn -> KI12 (U);
MFETCH: %k2_spatial_update -> KI13 (L)(U);
MFETCH: %k2_spatial_update -> KI13 (U);
BIU1: T12[11] -> BIU.T12[14](MODE1); // caller ROM base
// r54 independent setup covers all three bank-pointer loads before first use.
BIU0: 0x0 (L)(E) -> BIU.T10[0](MODE1);
BIU0: 0x8000 (E) -> BIU.T10[1](MODE1);
NOP;
NOP;
BIU0: KGDWORD(T10[0]) -> FMA0.T7 & FMA1.T7(MODE1);
BIU0: KGDWORD(T10[0]) -> FMA2.T7 & FMA3.T7(MODE1);
BIU0: LOAD(T12[1] + 448) -> FMA0.T0(MODE1);
BIU0: LOAD(T12[1] + 64) -> FMA0.T1(MODE1);
BIU0: LOAD(T12[1] + 512) -> FMA1.T0(MODE1);
BIU0: LOAD(T12[1] + 128) -> FMA1.T1(MODE1);
BIU0: LOAD(T12[1] + 576) -> FMA2.T0(MODE1);
BIU0: LOAD(T12[1] + 192) -> FMA2.T1(MODE1);
// r61 context scalar registers arrived during native preservation; retain KGDWORD broadcast.
BIU1: KGDWORD(T1[0]) -> FMA0.T2(MODE1);
BIU1: KGDWORD(T2[0]) -> FMA1.T2(MODE1);
BIU1: KGDWORD(T3[0]) -> FMA2.T2(MODE1);
BIU1: KGDWORD(T4[0]) -> FMA2.T3(MODE1);
BIU1: KGDWORD(T5[0]) -> FMA3.T0(MODE1);
BIU1: KGDWORD(T6[0]) -> FMA3.T1(MODE1);
BIU1: KGDWORD(T7[0]) -> FMA3.T2(MODE1);
NOP;
NOP;
FMA2: FMA2.T2 - FMA2.T3 * 1 (FP64) -> FMA2.T2(MODE1) || MFETCH: %k2_special_ex -> KI8(L)(U); // r46 initial 0
FALU0: FMA0.T2 + 0 (I32) -> BIU.T4(MODE1) || MFETCH: %k2_special_ex -> KI8(U); // r46 initial 1
FALU1: FMA1.T2 + 0 (I32) -> BIU.T5(MODE1) || MFETCH: %k2_special_iby -> KI10(L)(U); // r46 initial 2
FALU3: FMA3.T0 + 0 (I32) -> BIU.T7(MODE1) || MFETCH: %k2_special_iby -> KI10(U); // r46 initial 3
FALU3: FMA3.T1 + 0 (I32) -> BIU.T8(MODE1) || MFETCH: %k2_special_ibz -> KI11(L)(U); // r46 initial 4
FALU2: FMA2.T2 + 0 (I32) -> BIU.T6(MODE1) || MFETCH: %k2_special_ibz -> KI11(U); // r46 initial 5
FALU3: FMA3.T2 + 0 (I32) -> BIU.T9(MODE1) || MFETCH: %k2_special_iby23 -> KI6(L)(U); // r46 initial 6
BIU2: STORE(T4,T12[7] + 1664) (MODE1) || MFETCH: %k2_special_iby23 -> KI6(U); // r46 initial 7
BIU2: STORE(T5,T12[7] + 1728) (MODE1) || MFETCH: %k2_special_ibx -> KI5(L)(U); // r46 initial 8
FMA0: FMA0.T0 + FMA0.T2 * 1 (FP64) -> BIU.T4(MODE1) || MFETCH: %k2_special_ibx -> KI5(U); // r46 initial 9
FMA0: FMA0.T1 + FMA0.T2 * 1 (FP64) -> BIU.T5(MODE1); // r46 initial 10
BIU2: STORE(T6,T12[7] + 1792) (MODE1) || FMA1: FMA1.T0 + FMA1.T2 * 1 (FP64) -> BIU.T6(MODE1); // r46 initial 11
BIU2: STORE(T7,T12[7] + 1856) (MODE1) || FMA1: FMA1.T1 + FMA1.T2 * 1 (FP64) -> BIU.T7(MODE1); // r46 initial 12
BIU2: STORE(T8,T12[7] + 1920) (MODE1) || FMA2: FMA2.T0 + FMA2.T2 * 1 (FP64) -> BIU.T8(MODE1); // r46 initial 13
BIU2: STORE(T9,T12[7] + 1984) (MODE1) || FMA2: FMA2.T1 + FMA2.T2 * 1 (FP64) -> BIU.T9(MODE1); // r46 initial 14
BIU2: STORE(T4,T12[7] + 0) (MODE1); // r46 initial 15
BIU2: STORE(T5,T12[7] + 192) (MODE1); // r46 initial 16
BIU2: STORE(T6,T12[7] + 64) (MODE1); // r46 initial 17
BIU2: STORE(T7,T12[7] + 256) (MODE1); // r46 initial 18
BIU2: STORE(T8,T12[7] + 128) (MODE1); // r46 initial 19
BIU2: STORE(T9,T12[7] + 320) (MODE1); // r46 initial 20
MFETCH: JUMP KI8(RPC); // r54 invariant call target
NOP;
BIU0: LOAD(T12[7] + 0) -> FMA0.T0(MODE1) ||
BIU1: LOAD(T12[14]+0) -> BIU.T10(MODE1) ||
BIU2: LOAD(T12[7]+1664) -> FMA3.T5(MODE1) ||
BIU3: T12[8] -> BIU.T11[4](MODE1); // r27 parent forwards stage metadata, offset and axis bank
BIU0: LOAD(T12[7] + 192) -> FMA0.T1(MODE1);
BIU0: LOAD(T12[7] + 384) -> FMA0.T2(MODE1);
BIU0: LOADI64(T12[5] + 24) -> BIU.T1(MODE1);
MFETCH: Repeat @(13);
BIU0: KGDWORD(T1[0]) -> FMA0.T3(MODE1);
NOP;
NOP;
FMA0: FMA0.T1 + FMA0.T1 * 1 (FP64) -> FMA0.T4(MODE1); // r19 DAG issue 0
FMA0: FMA0.T7 + FMA0.T3 * FMA0.T2 (FP64) -> FMA0.T5(MODE1); // r19 DAG issue 1
NOP;
NOP;
NOP;
FMA0: FMA0.T4 - FMA0.T0 * 1 (FP64) -> FMA0.T4(MODE1); // r19 DAG issue 5
NOP;
NOP;
NOP;
NOP;
FMA0: FMA0.T4 + FMA0.T5 * 1 (FP64) -> FMA3.T4(MODE1) || MFETCH: JUMP KI13(RPC); // r60 FP coordinate forwarded to spatial entry, latency5
// safe return landing/delay slot; helper has no counter
NOP;
MFETCH: JUMP KI10(RPC); // r54 invariant call target
NOP;
BIU0: LOAD(T12[7] + 0) -> FMA0.T0(MODE1);
BIU0: LOAD(T12[1] + 2176) -> FMA0.T1(MODE1);
BIU0: LOADI64(T12[5] + 16) -> BIU.T1(MODE1);
MFETCH: Repeat @(13);
BIU0: KGDWORD(T1[0]) -> FMA0.T2(MODE1);
NOP;
NOP;
FMA0: FMA0.T2 + FMA0.T0 * 1 (FP64) -> FMA0.T3(MODE1); // r19 DAG issue 0
FMA0: FMA0.T2 + FMA0.T1 * 1 (FP64) -> FMA0.T4(MODE1); // r19 DAG issue 1
NOP;
NOP;
NOP;
FMA0: FMA0.T7 + FMA0.T3 * FMA0.T3 (FP64) -> BIU.T4(MODE1); // r19 DAG issue 5
NOP;
FMA0: FMA0.T7 + FMA0.T4 * FMA0.T4 (FP64) -> M[0](MODE1); // r19 DAG issue 7
NOP;
NOP;
NOP;
BIU2: STORE(T4,T12[7] + 896) (MODE1); // r19 DAG issue 11
MFETCH: Repeat @(5);
MFETCH: JUMP KI12 (RPC);
// safe return landing/delay slot; helper has no counter
NOP;
R0: M[0] -> FMA0.T0(MODE1);
BIU0: LOAD(T12[7] + 896) -> FMA0.T2(MODE1) ||
BIU1: LOAD(T12[14]+64) -> BIU.T10(MODE1) ||
BIU2: LOAD(T12[7]+1728) -> FMA3.T5(MODE1) ||
BIU3: T12[9] -> BIU.T11[4](MODE1); // r27 parent forwards stage metadata, offset and axis bank
BIU0: LOAD(T12[7] + 256) -> FMA1.T0(MODE1);
BIU0: LOAD(T12[7] + 64) -> FMA1.T1(MODE1);
BIU0: LOAD(T12[7] + 448) -> FMA1.T2(MODE1);
BIU0: LOAD(T12[7] + 704) -> FMA1.T3(MODE1);
BIU0: LOADI64(T12[5] + 32) -> BIU.T1(MODE1);
MFETCH: Repeat @(13);
BIU0: KGDWORD(T1[0]) -> FMA0.T1(MODE1);
NOP;
NOP;
FMA0: FMA0.T7 + FMA0.T1 * FMA0.T0 (FP64) -> FMA0.T3 & BIU.T4(MODE1); // r19 DAG issue 0
NOP;
FMA0: FMA0.T7 + FMA0.T2 * FMA0.T0 (FP64) -> FMA0.T4(MODE1); // r19 DAG issue 2
FMA1: FMA1.T0 - FMA1.T1 * 1 (FP64) -> FMA0.T5(MODE1); // r19 DAG issue 3
FMA1: FMA1.T2 - FMA1.T3 * 1 (FP64) -> FMA1.T5(MODE1); // r19 DAG issue 4
NOP;
BIU2: STORE(T4,T12[1] + 320) (MODE1); // r19 DAG issue 6
FALU0: FMA0.T3 + 0 (I32) -> FMA1.T6(MODE1); // r19 DAG issue 7
FMA0: FMA0.T7 + FMA0.T4 * FMA0.T5 (FP64) -> FMA1.T4(MODE1); // r19 DAG issue 8
NOP;
NOP;
NOP;
FMA1: FMA1.T7 + FMA1.T6 * FMA1.T5 (FP64) -> FMA1.T5(MODE1); // r19 DAG issue 12
FMA1: FMA1.T0 + FMA1.T4 * 1 (FP64) -> FMA1.T4(MODE1); // r19 DAG issue 13
NOP;
NOP;
NOP;
NOP;
FMA1: FMA1.T4 + FMA1.T5 * 1 (FP64) -> FMA3.T4(MODE1) || MFETCH: JUMP KI13(RPC); // r60 FP coordinate forwarded to spatial entry, latency5
// safe return landing/delay slot; helper has no counter
NOP;
MFETCH: JUMP KI11(RPC); // r54 invariant call target
NOP;
BIU0: LOAD(T12[7] + 128) -> FMA0.T0(MODE1) ||
BIU1: LOAD(T12[14]+128) -> BIU.T10(MODE1) ||
BIU2: LOAD(T12[7]+1792) -> FMA3.T5(MODE1) ||
BIU3: T12[10] -> BIU.T11[4](MODE1); // r27 parent forwards stage metadata, offset and axis bank
BIU0: LOAD(T12[7] + 320) -> FMA0.T1(MODE1);
BIU0: LOAD(T12[7] + 512) -> FMA0.T2(MODE1);
BIU0: LOAD(T12[7] + 704) -> FMA0.T3(MODE1);
BIU0: LOADI64(T12[5] + 40) -> BIU.T1(MODE1);
MFETCH: Repeat @(13);
BIU0: KGDWORD(T1[0]) -> FMA0.T4(MODE1);
NOP;
NOP;
FMA0: FMA0.T1 + FMA0.T1 * 1 (FP64) -> FMA0.T5(MODE1); // r19 DAG issue 0
FMA0: FMA0.T2 - FMA0.T3 * 1 (FP64) -> FMA0.T3(MODE1); // r19 DAG issue 1
NOP;
NOP;
NOP;
FMA0: FMA0.T5 - FMA0.T0 * 1 (FP64) -> FMA0.T5(MODE1) || MFETCH: %k2_weights_if1 -> KI9(L)(U); // r50 early weight target 2
FMA0: FMA0.T7 + FMA0.T4 * FMA0.T3 (FP64) -> FMA0.T4(MODE1) || MFETCH: %k2_weights_if1 -> KI9(U); // r50 early weight target 2
NOP;
NOP;
NOP;
NOP;
FMA0: FMA0.T5 + FMA0.T4 * 1 (FP64) -> FMA3.T4(MODE1) || MFETCH: JUMP KI13(RPC); // r60 FP coordinate forwarded to spatial entry, latency5
// safe return landing/delay slot; helper has no counter
MFETCH: %k2_weights_f0_if1 -> KI9(L)(U); // r50 early weight target 3
BIU0: LOAD(T12[1] + 2304) -> FMA0.T0(MODE1) ||
BIU1: LOAD(T12[14]+192) -> BIU.T10(MODE1) ||
BIU2: LOAD(T12[7]+1792) -> FMA3.T5(MODE1) ||
BIU3: T12[10] -> BIU.T11[4](MODE1); // r27 parent forwards stage metadata, offset and axis bank
BIU0: LOAD(T12[7] + 320) -> FMA0.T1(MODE1);
MFETCH: Repeat @(13);
FMA0: FMA0.T0 + FMA0.T0 * 1 (FP64) -> FMA0.T4(MODE1) || MFETCH: %k2_weights_f0_if1 -> KI9(U); // r50 early weight target 3
MFETCH: Repeat @(4);
FMA0: FMA0.T4 - FMA0.T1 * 1 (FP64) -> FMA3.T4(MODE1) || MFETCH: JUMP KI13(RPC); // r60 FP coordinate forwarded to spatial entry, latency5
// safe return landing/delay slot; helper has no counter
NOP;
MFETCH: JUMP KI6(RPC); // r54 invariant call target
NOP;
BIU0: LOAD(T12[1] + 2240) -> FMA0.T0(MODE1) ||
BIU1: LOAD(T12[14]+256) -> BIU.T10(MODE1) ||
BIU2: LOAD(T12[7]+1728) -> FMA3.T5(MODE1) ||
BIU3: T12[9] -> BIU.T11[4](MODE1); // r27 parent forwards stage metadata, offset and axis bank
BIU0: LOAD(T12[7] + 256) -> FMA0.T1(MODE1);
BIU0: LOAD(T12[1] + 320) -> FMA0.T2(MODE1);
BIU0: LOAD(T12[7] + 704) -> FMA0.T3(MODE1);
MFETCH: Repeat @(13);
FMA0: FMA0.T0 + FMA0.T0 * 1 (FP64) -> FMA0.T4(MODE1); // r19 DAG issue 0
FMA0: FMA0.T7 + FMA0.T2 * FMA0.T3 (FP64) -> FMA0.T5(MODE1); // r19 DAG issue 1
NOP;
NOP;
MFETCH: %k2_weights_f0_if1 -> KI9(L)(U); // r50 early weight target 4
FMA0: FMA0.T4 - FMA0.T1 * 1 (FP64) -> FMA0.T4(MODE1) || MFETCH: %k2_weights_f0_if1 -> KI9(U); // r50 early weight target 4
NOP;
NOP;
NOP;
NOP;
FMA0: FMA0.T4 - FMA0.T5 * 1 (FP64) -> FMA3.T4(MODE1) || MFETCH: JUMP KI13(RPC); // r60 FP coordinate forwarded to spatial entry, latency5
// safe return landing/delay slot; helper has no counter
NOP;
MFETCH: JUMP KI5(RPC); // r54 invariant call target
NOP;
BIU0: LOAD(T12[1] + 2240) -> FMA0.T0(MODE1) ||
BIU1: LOAD(T12[14]+320) -> BIU.T10(MODE1) ||
BIU2: LOAD(T12[7]+1664) -> FMA3.T5(MODE1) ||
BIU3: T12[8] -> BIU.T11[4](MODE1); // r27 parent forwards stage metadata, offset and axis bank
BIU0: LOAD(T12[1] + 2432) -> FMA0.T1(MODE1);
BIU0: LOAD(T12[7] + 256) -> FMA0.T2(MODE1);
BIU0: LOAD(T12[1] + 2176) -> FMA1.T0(MODE1);
BIU0: LOAD(T12[7] + 192) -> FMA1.T1(MODE1);
BIU0: LOAD(T12[7] + 704) -> FMA1.T2(MODE1);
BIU0: LOADI64(T12[5] + 16) -> BIU.T1(MODE1);
BIU0: LOADI64(T12[5] + 48) -> BIU.T2(MODE1);
BIU0: LOADI64(T12[5] + 24) -> BIU.T3(MODE1);
MFETCH: Repeat @(13);
BIU0: KGDWORD(T1[0]) -> FMA1.T3(MODE1);
BIU0: KGDWORD(T2[0]) -> FMA1.T4(MODE1);
BIU0: KGDWORD(T3[0]) -> FMA1.T5(MODE1);
NOP;
NOP;
FMA0: FMA0.T2 - FMA0.T0 * 1 (FP64) -> FMA0.T3(MODE1); // r59 final DAG 0
FMA0: FMA0.T0 - FMA0.T1 * 1 (FP64) -> FMA0.T4(MODE1); // r59 final DAG 1
FMA1: FMA1.T3 + FMA1.T0 * 1 (FP64) -> FMA1.T3(MODE1); // r59 final DAG 2
FMA1: FMA1.T7 + FMA1.T5 * FMA1.T2 (FP64) -> FMA1.T5(MODE1); // r59 final DAG 3
FMA1: FMA1.T0 + FMA1.T0 * 1 (FP64) -> FMA1.T8(MODE1); // r59b final DAG 4
FMA0: FMA0.T7 + FMA0.T3 * FMA0.T3 (FP64) -> FMA0.T3(MODE1); // r59 final DAG 5
FMA0: FMA0.T7 + FMA0.T4 * FMA0.T4 (FP64) -> FMA0.T4(MODE1); // r59 final DAG 6
NOP; // r59 final DAG 7
NOP; // r59 final DAG 8
FMA1: FMA1.T8 - FMA1.T1 * 1 (FP64) -> FMA1.T8(MODE1); // r59b final DAG 9
NOP; // r59 final DAG 10
FMA0: FMA0.T3 + FMA0.T4 * 1 (FP64) -> FMA1.T6(MODE1); // r59 final DAG 11
NOP; // r59 final DAG 12
NOP; // r59 final DAG 13
NOP; // r59 final DAG 14
NOP; // r59 final DAG 15
FMA1: FMA1.T7 + FMA1.T3 * FMA1.T6 (FP64) -> FMA1.T3(MODE1); // r59 final DAG 16
NOP; // r59 final DAG 17
NOP; // r59 final DAG 18
NOP; // r59 final DAG 19
NOP; // r59 final DAG 20
FMA1: FMA1.T7 + FMA1.T4 * FMA1.T3 (FP64) -> FMA1.T3(MODE1); // r59 final DAG 21
NOP; // r59 final DAG 22
NOP; // r59 final DAG 23
NOP; // r59 final DAG 24
MFETCH: %k2_weights_if1 -> KI9(L)(U); // r59 final DAG 25
FMA1: FMA1.T8 + FMA1.T3 * 1 (FP64) -> FMA1.T4(MODE1) || MFETCH: %k2_weights_if1 -> KI9(U); // r59b final DAG 26
NOP; // r59 final DAG 27
NOP; // r59 final DAG 28
NOP; // r59 final DAG 29
NOP; // r59 final DAG 30
FMA1: FMA1.T4 - FMA1.T5 * 1 (FP64) -> FMA3.T4(MODE1) || MFETCH: JUMP KI13(RPC); // r60 FP coordinate forwarded to spatial entry, latency5
// safe return landing/delay slot; helper has no counter
NOP;
// r45 restore native BIU and KI; timer owns KI14.
R0: M[243] -> BIU.T0(MODE1) || R1: M[245] -> BIU.T4(MODE1) || R2: M[249] -> BIU.T8(MODE1) || R3: M[253] -> BIU.T12(MODE1); // r45 exit 0
R0: M[244] -> BIU.T3(MODE1) || R1: M[246] -> BIU.T5(MODE1) || R2: M[250] -> BIU.T9(MODE1) || R3: M[254] -> BIU.T13(MODE1); // r45 exit 1
R1: M[247] -> BIU.T6(MODE1) || R2: M[251] -> BIU.T10(MODE1) || R3: M[255] -> BIU.T14(MODE1); // r45 exit 2
R1: M[248] -> BIU.T7(MODE1) || R2: M[252] -> BIU.T11(MODE1); // r45 exit 3
NOP; // r45 exit 4
BIU1: KG(T0[0]) -> KI0(MODE1); // r45 exit 5
BIU1: KG(T0[1]) -> KI1(MODE1); // r45 exit 6
BIU1: KG(T0[2]) -> KI2(MODE1); // r45 exit 7
BIU1: KG(T0[3]) -> KI3(MODE1); // r45 exit 8
BIU1: KG(T0[4]) -> KI4(MODE1); // r45 exit 9
BIU1: KG(T0[5]) -> KI5(MODE1); // r45 exit 10
BIU1: KG(T0[6]) -> KI6(MODE1); // r45 exit 11
BIU1: KG(T0[7]) -> KI7(MODE1); // r45 exit 12
BIU1: KG(T0[8]) -> KI8(MODE1); // r45 exit 13
BIU1: KG(T0[9]) -> KI9(MODE1); // r45 exit 14
BIU1: KG(T0[10]) -> KI10(MODE1); // r45 exit 15
BIU1: KG(T0[11]) -> KI11(MODE1); // r45 exit 16
BIU1: KG(T0[12]) -> KI12(MODE1); // r45 exit 17
BIU1: KG(T0[13]) -> KI13(MODE1); // r45 exit 18
BIU1: KG(T0[15]) -> KI15(MODE1); // r45 exit 19
NOP; // r45 exit 20
NOP; // r45 exit 21
NOP; // r45 exit 22
NOP; // r45 exit 23
NOP; // r45 exit 24
NOP; // r45 exit 25
NOP; // r45 exit 26
NOP; // r45 exit 27
MFETCH: JUMP KI15;
NOP;
.Lmanual_k2_end:
.size candidate_K2,.Lmanual_k2_end-candidate_K2
