# Lab 02 – Assembly Language Fundamentals & Debugging

This lab focuses on Assembly Language fundamentals, debugging, memory allocation, data definition, number systems, and register-level execution tracing using Visual Studio, MASM, and the Irvine32 library.

## Topics Covered

- Assembly Language Debugging & Breakpoints
- Single Stepping & Code Stepping
- Register State Analysis
- Assembly Language Directives (`.data`, `.code`)
- Identifiers, Instructions, Mnemonics & Comments
- Integer Constants & Number Systems (Decimal, Binary, Hexadecimal, Octal)
- Character & String Constants
- Data Definition & Memory Allocation
- Intrinsic Data Types (`BYTE`, `WORD`, `DWORD`, `QWORD`)
- Signed & Unsigned Data Types
- Arithmetic Operations & Expression Evaluation

---

## Tasks

### Task 01 – Arithmetic Expressions

- Implement arithmetic expressions using MASM instructions.
- Work with decimal, hexadecimal, binary, and octal constants.
- Perform addition and subtraction using general-purpose registers.

### Task 02 – Debugging & Breakpoints

- Set and use breakpoints in Visual Studio.
- Execute assembly instructions step-by-step using the debugger.
- Observe register values before and after instruction execution.

### Task 03 – Memory Allocation

- Define arrays, strings, and QWORD variables in the data segment.
- Calculate the memory allocated based on the size of each data type.
- Observe memory-related values through register operations.

### Task 04 – Error Code Arithmetic

- Perform arithmetic operations using constants represented in different number systems.
- Store the calculated result in a general-purpose register.
- Understand the interpretation of decimal, hexadecimal, binary, and octal constants.

### Task 05 – Register-Based Expressions

- Implement mathematical expressions involving CPU registers and immediate constants.
- Apply `ADD` and `SUB` instructions to evaluate expressions.
- Preserve and manipulate register values appropriately during calculations.

### Task 06 – Instruction-Level Register Tracing

- Debug an assembly program instruction by instruction.
- Record register values after the execution of each instruction.
- Analyze how arithmetic and data-transfer instructions affect register states.

### Task 07 – Lab Reflection

- Summarize the key concepts learned throughout the lab.
- Reflect on debugging, register manipulation, memory allocation, and Assembly Language fundamentals.

---

## Learning Outcomes

- Understand the fundamentals of debugging Assembly Language programs.
- Use breakpoints and single stepping to trace program execution.
- Analyze changes in CPU registers during instruction execution.
- Define and initialize data using appropriate intrinsic data types.
- Calculate memory allocation based on data type sizes.
- Work with decimal, binary, hexadecimal, and octal constants.
- Understand signed and unsigned data representation.
- Implement arithmetic expressions using MASM instructions.

> **Note:** Task implementations and relevant code are provided in their respective `.asm` source files. The task statements are included as comments within the source files for reference.