# README.md for the "uneviedefourmi" Repository

## Introduction

This project aims to simulate the movement of ants within an underground anthill, organized into various rooms connected by tunnels.
The colony consists of a specified number of ants (f), and the primary objective is to safely guide all ants from the vestibule (v) to the dormitory (d) in the least number of steps while adhering to certain movement rules.

## Problem Statement

In an anthill, the two largest rooms are the vestibule (Sv) and the dormitory (Sd).
The other rooms (S1, S2, ..., Sn) vary in size and can accommodate a certain number of ants.
The movement of ants is restricted by the following rules:

1. Ants move at the same speed.
2. Only one ant can occupy a room at a time, except for the vestibule and dormitory.
3. An ant can only enter a tunnel if the destination room is empty or the ant currently occupying it is leaving.
4. Tunnels are crossed instantly.
5. All ants must reach the dormitory in the minimum number of steps.

## Solution Overview

The solution consists of multiple components that include C++ classes and functions to manage the movement of ants within the anthill.
The repository includes:

- `ants.cpp` & `ants.hpp`: Definitions of classes and functions for managing ant movements.
- `main.cpp`: The implementation of the anthill resolution.
- Visual representations of the anthills and stepwise movements of the ants.

## Anthill Configurations

Here are the representations and movements for each anthill scenario:

### Anthill 0
Consider an anthill housing two ants whose rooms (Sv, S1, S2, and Sd)
are connected to each other as follows:

* Sv - S1
* Sv - S2
* S1 - Sd
* S2 - Sd

**Graph Representation:**
```
Sv __ S1 __ Sd
  |        |
  |__ S2 __|
```

**Steps to Move Ants:**

| Step  | Ant Movements  | Step  | Ant Movements  |
|-------|----------------|-------|----------------|
| E1    | f1 -- Sv -- S1 | E2    | f1 -- S1 -- Sd |
|       | f2 -- Sv -- S2 |       | f2 -- S2 -- Sd |
| _____ | ______________ | _____ | ______________ |

Total steps: 2

---

### Anthill 1
Consider an anthill housing 5 ants whose rooms
(Sv, S1, S2, and Sd) are connected to each other as follows:

* Sv - S1
* S1 - S2
* S2 - Sd

**Graph Representation:**
```
Sv __ S1 __ Sd
  |        |
  |__ S2 __|
```

**Steps to Move Ants:**

| Step   | Ant Movements    | Step   | Ant Movements    |
|--------|------------------|--------|------------------|
| E1     | f1 -- Sv -- S1   | E2     | f1 -- S1 -- Sd   |
|        | f2 -- Sv -- S2   |        | f2 -- S2 -- Sd   |
| ------ | ---------------- |        | f3 -- Sv -- S1   |
| E3     | f3 -- S1 -- Sd   |        | f4 -- Sv -- S2   |
|        | f4 -- S2 -- Sd   | ------ | ---------------- |
|        | f5 -- Sv -- S1   | E4     | f5 -- S1 -- Sd   |
| ______ | ________________ | ______ | ________________ |

Total steps: 4

---

### Anthill 2
Consider an anthill housing 5 ants whose rooms
(Sv, S1, S2, and Sd) are connected to each other as follows:

* Sv - S1
* S1 - S2
* S2 - Sd
* Sd - Sv

**Graph Representation:**
```
     ________
    |        |
Sv _|__ S1 __|_ Sd
    |        |
    |__ S2 __|
```

**Steps to Move Ants:**

| Step  | Ant Movements  |
|-------|----------------|
| E1    | f1 -- Sv -- Sd |
|       | f2 -- Sv -- Sd |
|       | f3 -- Sv -- Sd |
|       | f4 -- Sv -- Sd |
|       | f5 -- Sv -- Sd |
| _____ | ______________ |

Total steps: 1

---

### Anthill 3
Consider an anthill housing 5 ants whose rooms
(Sv, S1, S2, S3, S4, and Sd) are connected to each other as follows:

* Sv - S1
* S1 - S2
* S4 - Sd
* S1 - S4
* S2 - S3

**Graph Representation:**
```
            ___ S4 __ Sd
           |
Sv __ S1 __|__ S2 __ S3
```

**Steps to Move Ants:**

| Step   | Ant Movements    | Step   | Ant Movements    | Step   | Ant Movements    |
|--------|------------------|--------|------------------|--------|------------------|
| E1     | f1 -- Sv -- S1   | E2     | f1 -- S1 -- S4   | E3     | f1 -- S4 -- Sd   |
| ------ | ---------------- |        | f2 -- Sv -- S1   |        | f2 -- S1 -- S4   |
| E4     | f2 -- S4 -- Sd   | ------ | ---------------- |        | f3 -- Sv -- S1   |
|        | f3 -- S1 -- S4   | E5     | f3 -- S4 -- Sd   | ------ | ---------------- |
|        | f4 -- Sv -- S1   |        | f4 -- S1 -- S4   | E6     | f4 -- S4 -- Sd   |
| ------ | ---------------- |        | f5 -- Sv -- S1   |        | f5 -- S1 -- S4   |
| E7     | f5 -- S4 -- Sd   |        |                  |        |                  |
| _____  | _______________  | ______ | ________________ | ______ | ________________ |

Total steps: 7

---

### Anthill 4
Consider an anthill housing 10 ants whose rooms
(Sv, S1, S2, S3, S4, S5, S6, and Sd) are connected to each other as follows:

* S3 - S4
* Sv - S1
* S1 - S2
* S2 - S4
* S4 - S5
* S5 - Sd
* S4 - S6
* S6 - Sd
* S1 - S3

**Graph Representation:**
```
     
Sv __ S1(2) __ S2 __ S4(2) __ S5 __ Sd
           |        |     |        |
           |__ S3 __|     |__ S6 __|
```

**Steps to Move Ants:**

| Step   | Ant Movements     | Step   | Ant Movements     | Step   | Ant Movements     |
|--------|-------------------|--------|-------------------|--------|-------------------|
| E1     | f1 -- Sv -- S1    | E2     | f1 -- S1 -- S2    | E3     | f1 -- S2 -- S4    |
|        | f2 -- Sv -- S1    |        | f2 -- S1 -- S3    |        | f2 -- S3 -- S4    |
| ------ | ----------------- |        | f3 -- Sv -- S1    |        | f3 -- S1 -- S2    |
| E4     | f1 -- S4 -- S5    |        | f4 -- Sv -- S1    |        | f4 -- S1 -- S3    |
|        | f2 -- S4 -- S6    | ------ | ----------------- |        | f5 -- Sv -- S1    |
|        | f3 -- S2 -- S4    | E5     | f1 -- S5 -- Sd    |        | f6 -- Sv -- S1    |
|        | f4 -- S3 -- S4    |        | f2 -- S6 -- Sd    | ------ | ----------------- |
|        | f5 -- S1 -- S2    |        | f3 -- S4 -- S5    | E6     | f3 -- S5 -- Sd    |
|        | f6 -- S1 -- S3    |        | f4 -- S4 -- S6    |        | f4 -- S6 -- Sd    |
|        | f7 -- Sv -- S1    |        | f5 -- S2 -- S4    |        | f5 -- S4 -- S5    |
|        | f8 -- Sv -- S1    |        | f6 -- S3 -- S4    |        | f6 -- S4 -- S6    |
| ------ | ----------------- |        | f7 -- S1 -- S2    |        | f7 -- S2 -- S4    |
| E7     | f5 -- S5 -- Sd    |        | f8 -- S1 -- S3    |        | f8 -- S3 -- S4    |
|        | f6 -- S6 -- Sd    |        | f9 -- Sv -- S1    |        | f9 -- S1 -- S2    |
|        | f7 -- S4 -- S5    |        | f10 -- SV -- S1   |        | f10 -- S1 -- S3   |
|        | f8 -- S4 -- S6    | ------ | ----------------- | ------ | ----------------- |
|        | f9 -- S2 -- S4    | E8     | f7 -- S5 -- Sd    | E9     | f9 -- S5 -- Sd    |
|        | f10 -- S3 -- S4   |        | f8 -- S6 -- Sd    |        | f10 -- S6 -- Sd   |
|        |                   |        | f9 -- S4 -- S5    |        |                   |
|        |                   |        | f10 -- S4 -- S6   |        |                   |
| ______ | _________________ | ______ | _________________ | ______ | _________________ |

Total steps: 9

---

### Anthill 5
Consider an anthill housing 50 ants whose rooms
(Sv, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S14, and Sd)
are connected to each other as follows:

* S1 - S2
* S2 - S3
* S3 - S4
* S4 - Sd
* Sv - S1
* S2 - S5
* S5 - S4
* S13 - Sd
* S8 - S12
* S12 - S13
* S6 - S7
* S7 - S9
* S9 - S14
* S14 - Sd
* S7 - S10
* S10 - S14
* S1 - S6
* S6 - S8
* S8 - S11
* S11 - S13

* Room S1 has a capacity of 8 ants. 
* Rooms S3, S5, S7, and S14 each have a maximum capacity of two ants.
* Rooms S2, S4, S6, and S13 each have a maximum capacity of four ants.
* Room S8 has a capacity of five ants.
* The remaining rooms have a capacity of one ant (S9, S10, S11, and S12).

**Graph Representation:**
```
Sv __ S1(8) __ S2(4) __ S3(2) __ S4(4) _________  Sd
           |        |           |                 |
           |        |__ S5(2) __|                 |
           |                                      |
           |__ S6(4) __ S7(2) __ S9 ___           |   
                    |        |         |          |
                    |        |__ S10 __| S14(2) __|
                    |                             |
                    |__ S8(5) __ S11 __ S13(4) ___|
                             |         |
                             |__ S12 __|
```

**Steps to Move Ants:**

| Step   | Ant Movements       | Step   | Ant Movements       | Step   | Ant Movements       |
|--------|---------------------|--------|---------------------|--------|---------------------|
| E1     | f1 -- Sv -- S1      | E2     | f1 -- S1 -- S2      | E3     | f1 -- S2 -- S3      |
|        | f2 -- Sv -- S1      |        | f2 -- S1 -- S2      |        | f2 -- S2 -- S3      |
|        | f3 -- Sv -- S1      |        | f3 -- S1 -- S2      |        | f3 -- S2 -- S5      |
|        | f4 -- Sv -- S1      |        | f4 -- S1 -- S2      |        | f4 -- S2 -- S5      |
|        | f5 -- Sv -- S1      |        | f5 -- S1 -- S6      |        | f5 -- S6 -- S7      |
|        | f6 -- Sv -- S1      |        | f6 -- S1 -- S6      |        | f6 -- S6 -- S7      |
|        | f7 -- Sv -- S1      |        | f7 -- S1 -- S6      |        | f7 -- S6 -- S8      |
|        | f8 -- Sv -- S1      |        | f8 -- S1 -- S6      |        | f8 -- S6 -- S8      |
| ------ | ------------------- |        | f9 -- Sv -- S1      |        | f9 -- S1 -- S2      |
| E4     | f1 -- S3 -- S4      |        | f10 -- Sv -- S1     |        | f10 -- S1 -- S2     |
|        | f2 -- S3 -- S4      |        | f11 -- Sv -- S1     |        | f11 -- S1 -- S2     |
|        | f3 -- S5 -- S4      |        | f12 -- Sv -- S1     |        | f12 -- S1 -- S2     |
|        | f4 -- S5 -- S4      |        |                     |        |                     |
|        | f5 -- S7 -- S9      |        | f13 -- Sv -- S1     |        | f13 -- S1 -- S6     |
|        | f6 -- S7 -- S10     |        | f14 -- Sv -- S1     |        | f14 -- S1 -- S6     |
|        | f7 -- S8 -- S11     |        | f15 -- Sv -- S1     |        | f15 -- S1 -- S6     |
|        | f8 -- S8 -- S12     |        | f16 -- Sv -- S1     |        | f16 -- S1 -- S6     |
|        | f9 -- S2 -- S3      | ------ | ------------------- |        | f17 -- Sv -- S1     |
|        | f10 -- S2 -- S3     | E5     | f1 -- S4 -- Sd      |        | f18 -- Sv -- S1     |
|        | f11 -- S2 -- S5     |        | f2 -- S4 -- Sd      |        | f19 -- Sv -- S1     |
|        | f12 -- S2 -- S5     |        | f3 -- S4 -- Sd      |        | f20 -- Sv -- S1     |
|        | f13 -- S4 -- S7     |        | f4 -- S4 -- Sd      |        | f21 -- Sv -- S1     |
|        | f14 -- S4 -- S7     |        | f5 -- S9 -- S14     |        | f22 -- Sv -- S1     |
|        | f15 -- S4 -- S8     |        | f6 -- S10 -- S14    |        | f23 -- Sv -- S1     |
|        | f16 -- S4 -- S8     |        | f7 -- S11 -- S13    |        | f24 -- Sv -- S1     |
|        | f17 -- S1 -- S2     |        | f8 -- S12 -- S13    | ------ | ------------------- |
|        | f18 -- S1 -- S2     |        | f9 -- S3 -- S4      | E6     | f5 -- S14 -- Sd     |
|        | f19 -- S1 -- S2     |        | f10 -- S3 -- S4     |        | f6 -- S14 -- Sd     |
|        | f20 -- S1 -- S2     |        | f11 -- S5 -- S4     |        | f7 -- S13 -- Sd     |
|        | f21 -- S1 -- S6     |        | f12 -- S5 -- S4     |        | f8 -- S13 -- Sd     |
|        | f22 -- S1 -- S6     |        | f13 -- S7 -- S9     |        | f9 -- S4 -- Sd      |
|        | f23 -- S1 -- S6     |        | f14 -- S7 -- S10    |        | f10 -- S4 -- Sd     |
|        | f24 -- S1 -- S6     |        | f15 -- S8 -- S11    |        | f11 -- S4 -- Sd     |
|        | f25 -- Sv -- S1     |        | f16 -- S8 -- S12    |        | f12 -- S4 -- Sd     |
|        | f26 -- Sv -- S1     |        | f17 -- S2 -- S3     |        | f13 -- S9 -- S14    |
|        | f27 -- Sv -- S1     |        | f18 -- S2 -- S3     |        | f14 -- S10 -- S14   |
|        | f28 -- Sv -- S1     |        | f19 -- S2 -- S5     |        | f15 -- S11 -- S13   |
|        | f29 -- Sv -- S1     |        | f20 -- S2 -- S5     |        | f16 -- S12 -- S13   |
|        | f30 -- Sv -- S1     |        | f21 -- S6 -- S7     |        | f17 -- S3 -- S4     |
|        | f31 -- Sv -- S1     |        | f22 -- S6 -- S7     |        | f18 -- S3 -- S4     |
|        | f32 -- Sv -- S1     |        | f23 -- S6 -- S8     |        | f19 -- S5 -- S4     |
| ------ | ------------------- |        | f24 -- S6 -- S8     |        | f20 -- S5 -- S4     |
| E7     | f13 -- S14 -- Sd    |        | f25 -- S1 -- S2     |        | f21 -- S7 -- S9     |
|        | f14 -- S14 -- Sd    |        | f26 -- S1 -- S2     |        | f22 -- S7 -- S10    |
|        | f15 -- S13 -- Sd    |        | f27 -- S1 -- S2     |        | f23 -- S8 -- S11    |
|        | f16 -- S13 -- Sd    |        | f28 -- S1 -- S2     |        | f24 -- S8 -- S12    |
|        | f17 -- S4 -- Sd     |        | f29 -- S1 -- S6     |        | f25 -- S2 -- S3     |
|        | f18 -- S4 -- Sd     |        | f30 -- S1 -- S6     |        | f26 -- S2 -- S3     |
|        | f19 -- S4 -- Sd     |        | f32 -- S1 -- S6     |        | f27 -- S2 -- S5     |
|        | f20 -- S4 -- Sd     |        | f33 -- Sv -- S1     |        | f28 -- S2 -- S5     |
|        | f21 -- S9 -- S14    |        | f34 -- Sv -- S1     |        | f29 -- S6 -- S7     |
|        | f22 -- S10 -- S14   |        | f35 -- Sv -- S1     |        | f30 -- S6 -- S7     |
|        | f23 -- S11 -- S13   |        | f36 -- Sv -- S1     |        | f31 -- S6 -- S8     |
|        | f24 -- S12 -- S13   |        | f37 -- Sv -- S1     |        | f32 -- S6 -- S8     |
|        | f25 -- S3 -- S4     |        | f38 -- Sv -- S1     |        | f33 -- S1 -- S2     |
|        | f26 -- S3 -- S4     |        | f39 -- Sv -- S1     |        | f34 -- S1 -- S2     |
|        | f27 -- S5 -- S4     |        | f40 -- Sv -- S1     |        | f35 -- S1 -- S2     |
|        | f28 -- S5 -- S4     | ------ | ------------------- |        | f36 -- S1 -- S2     |
|        | f29 -- S7 -- S9     | E8     | f21 -- S14 -- Sd    |        | f37 -- S1 -- S6     |
|        | f30 -- S7 -- S10    |        | f22 -- S14 -- Sd    |        | f38 -- S1 -- S6     |
|        | f31 -- S8 -- S11    |        | f23 -- S13 -- Sd    |        | f39 -- S1 -- S6     |
|        | f32 -- S8 -- S12    |        | f24 -- S13 -- Sd    |        | f40 -- S1 -- S6     |
|        | f33 -- S2 -- S3     |        | f25 -- S4 -- Sd     |        | f41 -- Sv -- S1     |
|        | f34 -- S2 -- S3     |        | f26 -- S4 -- Sd     |        | f42 -- Sv -- S1     |
|        | f35 -- S2 -- S5     |        | f27 -- S4 -- Sd     |        | f43 -- Sv -- S1     |
|        | f36 -- S2 -- S5     |        | f28 -- S4 -- Sd     |        | f44 -- Sv -- S1     |
|        | f37 -- S6 -- S7     |        | f29 -- S9 -- S14    |        | f45 -- Sv -- S1     |
|        | f38 -- S6 -- S7     |        | f30 -- S10 -- S14   |        | f46 -- Sv -- S1     |
|        | f39 -- S6 -- S8     |        | f31 -- S11 -- S13   |        | f47 -- Sv -- S1     |
|        | f40 -- S6 -- S8     |        | f32 -- S12 -- S13   |        | f48 -- Sv -- S1     |
|        | f41 -- S1 -- S2     |        | f33 -- S3 -- S4     | ------ | ------------------- |
|        | f42 -- S1 -- S2     |        | f34 -- S3 -- S4     | E9     | f29 -- S14 -- Sd    |
|        | f43 -- S1 -- S2     |        | f35 -- S5 -- S4     |        | f30 -- S14 -- Sd    |
|        | f44 -- S1 -- S2     |        | f36 -- S5 -- S4     |        | f31 -- S13 -- Sd    |
|        | f45 -- S1 -- S6     |        | f37 -- S7 -- S9     |        | f32 -- S13 -- Sd    |
|        | f46 -- S1 -- S6     |        | f38 -- S7 -- S10    |        | f33 -- S4 -- Sd     |
|        | f47 -- S1 -- S6     |        | f39 -- S8 -- S11    |        | f34 -- S4 -- Sd     |
|        | f48 -- S1 -- S6     |        | f40 -- S8 -- S12    |        | f35 -- S4 -- Sd     |
|        | f49 -- Sv -- S1     |        | f41 -- S2 -- S3     |        | f36 -- S4 -- Sd     |
|        | f50 -- Sv -- S1     |        | f42 -- S2 -- S3     |        | f37 -- S9 -- S14    |
| ------ | ------------------- |        | f43 -- S2 -- S5     |        | f38 -- S10 -- S14   |
| E10    | f37 -- S14 -- Sd    |        | f44 -- S2 -- S5     |        | f39 -- S11 -- S13   |
|        | f38 -- S14 -- Sd    |        | f45 -- S6 -- S7     |        | f40 -- S12 -- S13   |
|        | f39 -- S13 -- Sd    |        | f46 -- S6 -- S7     |        | f41 -- S3 -- S4     |
|        | f40 -- S13 -- Sd    |        | f47 -- S6 -- S8     |        | f42 -- S3 -- S4     |
|        | f41 -- S4 -- Sd     |        | f48 -- S6 -- S8     |        | f43 -- S5 -- S4     |
|        | f42 -- S4 -- Sd     |        | f49 -- S1 -- S2     |        | f44 -- S5 -- S4     |
|        | f43 -- S4 -- Sd     |        | f50 -- S1 -- S2     |        | f45 -- S7 -- S9     |
|        | f44 -- S4 -- Sd     | ------ | ------------------- |        | f46 -- S7 -- S10    |
|        | f45 -- S9 -- S14    | E11    | f45 -- S14 -- Sd    |        | f47 -- S8 -- S11    |
|        | f46 -- S10 -- S14   |        | f46 -- S14 -- Sd    |        | f48 -- S8 -- S12    |
|        | f47 -- S11 -- S13   |        | f47 -- S13 -- Sd    |        | f49 -- S2 -- S3     |
|        | f48 -- S12 -- S13   |        | f48 -- S13 -- Sd    |        | f50 -- S2 -- S3     |
|        | f49 -- S3 -- S4     |        | f49 -- S4 -- Sd     |        |                     |
|        | f50 -- S3 -- S4     |        | f50 -- S4 -- Sd     |        |                     |
| ______ | ___________________ | ______ | __________________  | ______ | ___________________ |

Total steps: 11

---

### Anthill 6
Consider an anthill housing 50 ants whose rooms
(Sv, S1, S2, S3, S4, S5, S6, S7, S8, S9 and Sd)
are connected to each other as follows:

* Sv - S1
* Sv - S2
* S1 - S6
* S1 - S8
* S2 - S7
* S3 - S4
* S3 - S5
* S3 - S8
* S3 - S9
* S4 - S5
* S4 - Sd
* S5 - S6
* S6 - S7
* S7 - S9
* S9 - Sd

* Room S1 and S7 has a capacity of 5 ants.
* S2 : 6 ants.
* S3 : one ant.
* S4: 3 ants.
* S5 and S9 : 2 ants each.
* S6 and S8 : 4 ants each.

**Graph Representation:**
```

Sv __ S1(5) ___ S8(4) __ S3(1) __ S4(3) ___ Sd
  |     |                 |       |        |
  |     |_____ S6(4) _____|____ S5(2)      |
  |              |        |                |
  |__ S2(6) __ S7(5) ___ S9(2) ____________|

```
### Anthill 7
Consider an anthill housing 100 ants whose rooms
(Sv, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S13, S14, S15, S16, S17, S18, S19, S20, S21 and Sd)
are connected to each other as follows:

* Sv - S1
* S1 - S2
* S2 - S3
* S3 - S4
* S4 - S5
* S5 - Sd
* Sv - S6  
* S6 - S7
* S7 - S8
* S8 - S9
* S9 - S10
* S10 - Sd
* Sv - S11
* S11 - S12
* S12 - S13
* S13 - S14
* S14 - S15
* S15 - Sd
* Sv - S16
* S16 - S17
* S17 - S18
* S18 - S19
* S19 - S20
* S20 - Sd
* S21 - S3
* S21 - S8
* S21 - S13
* S21 - S18

* Room S1, S2, S3 :  has a capacity of 50 ants each.
* Room S4, S5, S15, S16 :  has a capacity of 1 ant each.
* Room S6, S7, S11, S12 : has a capacity of 3 ants each.
* Room S8 has a capacity of 7 ants.
* Room S9, S10, S19, S20 has a capacity of 5 ants.
* Room S13, S18 has a capacity of 10 ants each.
* Room S14 has a capacity of 20 ants.
* Room S17, S21 has a capacity of 30 ants each.

**Graph Representation:**
```

   __S16(1) __S17(30) __ S18(10) __ S19(5) __ S20(5) _______
  |                       \                                 |
  | ___ S11(3) __ S12(3) __\_ S13(10) __ S14(20) __ S15(1)_ |
  ||                        \  |                           ||
  ||                         S21(30)                       ||
  ||                        /  |                           ||
  Sv __ S1(50) __ S2(50) __/_ S3(50) __ S4(1) __ S5(1) ___ Sd
  |                       /                                |
  |_ S6(3) __ S7(3) __ S8(7) __ S9(5) __ S10(5) ___________|
 

```
### Anthill 8
Consider an anthill housing 30 ants whose rooms
(Sv, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10 and Sd)
are connected to each other as follows:

* Sv - S1
* Sv - S2
* Sv - S3
* Sv - S4
* Sv - S5
* Sv - S6
* Sv - S7
* Sv - S8
* S1 - S2
* S1 - S3
* S1 - S4
* S1 - S5
* S1 - S6
* S1 - S7
* S1 - S8
* S1 - S9
* S2 - S3
* S2 - S4
* S2 - S5
* S2 - S6
* S2 - S7
* S2 - S8
* S2 - S9
* S3 - S4
* S3 - S5
* S3 - S6
* S3 - S7
* S3 - S8
* S3 - S9
* S4 - S5
* S4 - S6
* S4 - S7
* S4 - S8
* S4 - S9
* S5 - S6
* S5 - S7
* S5 - S8
* S5 - S9
* S6 - S7
* S6 - S8
* S6 - S9
* S7 - S8
* S7 - S9
* S8 - S9
* S9 - S10
* S10 - Sd

* Room S1, S5 :  has a capacity of 4 ants each.
* Room S2, S4, S8 :  has a capacity of 3 ants each.
* Room S3, S6, S7 : has a capacity of 2 ants each.
* Room S9, S10 has a capacity of 5 ants each.

**Graph Representation:**
```
  Sv   _____________________________________  S1(4) 
|||||||                                     ||||||||
|||||||________  S2(3)   ___________________||||||||
||||||        //////   |                     |||||||
||||||_______//////    S3(2)  _______________|||||||
|||||       //////  /////  |                  ||||||
|||||______///// |_/////   S4(3) _____________||||||
||||      /////   /////  //// |                |||||
||||_____//// |__//// |_////  S5(4) ___________|||||
|||     ////    ////   ////  /// |              ||||  
|||____/// |___/// |__/// |_///  S6(2) _________||||
||    ///     ///    ///   ///  // |             |||
||__ // |____// |___// |__// |_//  S7(2) ________|||
|   //      //     //    //   //   / |            ||
|_ / |_____/ |____/ |___/ |__/ |__/ S8(3) ________||
  /       /      /     /    /    /   |             |
  |_______|______|____ |___ |___ |_ S9(5) _________|
                                     |
                                    S10(5)
                                     |
                                     Sd						

```


## Conclusion

This project effectively demonstrates the management of ant movement through various anthill configurations.
The implementation ensures that all rules are respected while optimizing the number of steps
required for all ants to reach safety in the dormitory.
The provided code, diagrams, and stepwise movements offer a comprehensive understanding of the anthill simulation.

## Repository Structure

```
antsfamilylife/
├── include/
│   ├── AntHillConfig.h
│   ├── ants.h
│   └── menu.h
│
├── source/
│   ├── AntHillConfig.cpp
│   ├── ants.cpp
│   ├── main.cpp
│   └── menu.cpp
│
├── .gitignore
└── README.md
```

## Class Diagram

```
+------------------------+
|       Room             |
+------------------------+
| - name                 |
| - capacity             |
| - current_occupants    | 
+------------------------+
| + canAcceptAnt()       |
| + arrive()             |
| + depart()             |
+------------------------+

+------------------------+
|       Tunnel           |
+------------------------+
| - from_room            |
| - to_room              |
+------------------------+

+------------------------+
|        Ant             |
+------------------------+
| - id                   |
| - current_room         |
+------------------------+

+------------------------+
|      AntHill           |
+------------------------+
| - rooms                |
| - tunnels              |
| - ants                 |
+------------------------+
| + addRoom()            |
| + addTunnel()          |
| + addAnt()             | 
| + getRoom()            |
| + simulateMovement()   |
| + canReachSd()         |
+------------------------+

```