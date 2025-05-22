# README.md for the "uneviedefourmi" Repository (temporary file final version when work is completed)

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

Sv - S1
Sv - S2
S1 - Sd
S2 - Sd

**Graph Representation:**
```
Sv __ S1 __ Sd
  |        |
  |__ S2 __|
```

**Steps to Move Ants:**

| Step  | Ant Movements  | Step  | Ant Movements  |
|-------|----------------|-------|----------------|
| E1    | f1 -- Sv -- S1 | ...   | ...            |
|       | ...            |       | ...            |
| _____ | ______________ | _____ | ______________ |

Total steps: ...

---

### Anthill 1
Consider an anthill housing 5 ants whose rooms
(Sv, S1, S2, and Sd) are connected to each other as follows:

Sv - S1
S1 - S2
S2 - Sd

**Graph Representation:**
```
Sv __ S1 __ Sd
  |        |
  |__ S2 __|
```

**Steps to Move Ants:**

| Step   | Ant Movements    | Step   | Ant Movements    |
|--------|------------------|--------|------------------|
| E1     | f1 -- Sv -- S1   | ...    | ...              |
|        | ...              |        | ...              |
| ------ | ---------------- |        | ...              |
| ...    | ...              |        | ...              |
|        | ...              | ------ | ---------------- |
|        | ...              | ...    | ...              |
| ______ | ________________ | ______ | ________________ |

Total steps: ...

---

### Anthill 2
Consider an anthill housing 5 ants whose rooms
(Sv, S1, S2, and Sd) are connected to each other as follows:

Sv - S1
S1 - S2
S2 - Sd
Sd - Sv

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
|       | ...            |
|       | ...            |
| _____ | ______________ |

Total steps: ...

---

### Anthill 3
Consider an anthill housing 5 ants whose rooms
(Sv, S1, S2, S3, S4, and Sd) are connected to each other as follows:

Sv - S1
S1 - S2
S4 - Sd
S1 - S4
S2 - S3

**Graph Representation:**
```
            ___ S4 __ Sd
           |
Sv __ S1 __|__ S2 __ S3
```

**Steps to Move Ants:**

| Step   | Ant Movements    | Step   | Ant Movements    | Step   | Ant Movements    |
|--------|------------------|--------|------------------|--------|------------------|
| E1     | f1 -- Sv -- S1   | ...    | ...              | ...    | ...              |
| ------ | ---------------- |        | ...              |        | ...              |
| ...    | ...              | ------ | ---------------- |        | ...              |
|        | ...              | ...    | ...              | ------ | ---------------- |
|        | ...              |        | ...              | ...    | ...              |
| ------ | ---------------- |        | ...              |        | ...              |
| ...    | ...              |        |                  |        |                  |
| _____  | _______________  | ______ | ________________ | ______ | ________________ |

Total steps: ...

---

### Anthill 4
Consider an anthill housing 10 ants whose rooms
(Sv, S1, S2, S3, S4, S5, S6, and Sd) are connected to each other as follows:

S3 - S4
Sv - S1
S1 - S2
S2 - S4
S4 - S5
S5 - Sd
S4 - S6
S6 - Sd
S1 - S3

**Graph Representation:**
```
     
Sv __ S1(2) __ S2 __ S4(2) __ S5 __ Sd
           |        |     |        |
           |__ S3 __|     |__ S6 __|
```

**Steps to Move Ants:**

| Step   | Ant Movements     | Step   | Ant Movements     | Step   | Ant Movements     |
|--------|-------------------|--------|-------------------|--------|-------------------|
| E1     | f1 -- Sv -- S1    | ...    | ...               | ...    | ...               |
|        | ...               |        | ...               |        | ...               |
| ------ | ----------------- |        | ...               |        | ...               |
|        | ...               | ------ | ----------------- | ------ | ----------------- |
|        | ...               | ...    | ...               | ...    | ...               |
|        | ...               |        | ...               |        | ...               |
|        |                   |        | ...               |        |                   |
|        |                   |        | ...               |        |                   |
| ______ | _________________ | ______ | _________________ | ______ | _________________ |

Total steps: ...

---

### Anthill 5
Consider an anthill housing 50 ants whose rooms
(Sv, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S14, and Sd)
are connected to each other as follows:

S1 - S2
S2 - S3
S3 - S4
S4 - Sd
Sv - S1
S2 - S5
S5 - S4
S13 - Sd
S8 - S12
S12 - S13
S6 - S7
S7 - S9
S9 - S14
S14 - Sd
S7 - S10
S10 - S14
S1 - S6
S6 - S8
S8 - S11
S11 - S13

Room S1 has a capacity of 8 ants. Rooms S3, S5, S7, and S14 each have a maximum capacity of two ants.
Rooms S2, S4, S6, and S13 each have a maximum capacity of four ants.
Room S8 has a capacity of five ants.
The remaining rooms have a capacity of one ant (S9, S10, S11, and S12).

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
| E1     | f1 -- Sv -- S1      | ...    | ...                 | ...    | ...                 |
|        | ...                 |        | ...                 |        | ...                 |
|        | ...                 |        | ...                 |        | ...                 |
|        | ...                 |        | ...                 |        | ...                 |
|        | ...                 |        | ...                 |        | ...                 |
|        | ...                 |        | ...                 |        | ...                 |
|        | ...                 |        | ...                 |        | ...                 |
|        | ...                 |        | ...                 |        | ...                 |
| ------ | ------------------- |        | ...                 |        | ...                 |
|        | ...                 | ------ | ------------------- |        | ...                 |
|        | ...                 | ...    | ...                 |        | ...                 |
|        | ...                 |        | ...                 |        | ...                 |
|        | ...                 |        | ...                 |        | ...                 |
|        | ...                 |        | ...                 |        | ...                 |
|        | ...                 |        | ...                 |        |                     |
|        | ...                 |        | ...                 |        |                     |
| ______ | ___________________ | ______ | __________________  | ______ | ___________________ |

Total steps: ...

---

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
| + Room                 |
| + getName()            |
| + getCapacity()        |
| + getCurrentOccupants()|
| + setCurrentOccupants()|
| + canAcceptAnt()       |
+------------------------+

+------------------------+
|       Tunnel           |
+------------------------+
| - from_room            |
| - to_room              |
+------------------------+
| + Tunnel               |
| + getFromRoom()        |
| + getToRoom()          |
+------------------------+

+------------------------+
|      PathNode          |
+------------------------+
| - room                 |
| - next                 |
+------------------------+
| + PathNode             |
| + getRoom()            |
| + getNext()            |
| + setNext()            |
+------------------------+

+------------------------+
|        Ant             |
+------------------------+
| - id                   |
| - current_path_node    |
+------------------------+
| + Ant                  |
| + getId()              |
| + getCurrentPathNode() |
| + setCurrentPathNode() |
+------------------------+

+------------------------+
|      AntHill           |
+------------------------+
| - rooms                |
| - tunnels              |
| - ants                 |
+------------------------+
| + AntHill              |
| + addRoom()            |
| + addTunnel()          |
| + addAnt()             |
| + getRoom()            |
| + getAdjacentRooms()   |
| + simulateMovement()   |
| + printState()         |
| + computeOptimalPath() |
+------------------------+
```