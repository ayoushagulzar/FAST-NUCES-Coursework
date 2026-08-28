# Lab 01 – Introduction to Assembly Language (MASM)

This lab introduces the setup and basic concepts of Assembly Language programming using Visual Studio and the Microsoft Macro Assembler (MASM) environment along with the Irvine32 library.

## Topics Covered

- Environment Setup & Project Configuration
- Data Definition & Strings (`BYTE`, `OFFSET`)
- Basic I/O Procedures (`WriteString`, `Crlf`, `DumpRegs`)
- Register Operations & Data Transfer (`MOV`, `ADD`)
- Execution Tracing & Debugging
- Assembler vs. Linker Workflow

---

## Tasks

### Task 01 – Environment Setup & Configuration
- Configure Visual Studio Community Edition with a Visual C++ Empty Project for MASM assembly development.
- Verify project configuration and runtime output via setup screenshots.

### Task 02 – Personalized Message Output
- Display student credentials (Full Name and NU-ID) on separate lines using `WriteString` and `Crlf`.
- Extend the program to include an additional custom personalized message.

### Task 03 – Register Operations & Debugging
- Load hexadecimal values into registers (`EAX`, `EBX`) and perform addition.
- Step through execution line-by-line using a debugger to record register state changes.
- Refactor code using alternate registers (`ECX`, `EDX`) and expand logic to sum three values.
- Analyze the functionality of `DumpRegs` and register behavior pre/post `ADD`.

### Task 04 – Compilation Process & Conceptual Summary
- Explain the role of MASM (translating source code to object code) and the Linker (combining `.obj` files with `Irvine32.lib` into an executable).
- Summarize key register and instruction concepts learned during the lab.

### Task 05 – Importance of Assembly Language
- Discuss the relevance of low-level assembly in modern software development, hardware interfacing, memory control, and performance optimization.

---

## Learning Outcomes

- Understand the basic structure and execution flow of a MASM program.
- Manipulate general-purpose registers (`EAX`, `EBX`, `ECX`, `EDX`).
- Use `Irvine32` procedures to print text, line breaks, and inspect register states.
- Grasp how assembly code compiles, links, and executes at the hardware level.

> **Note:** Task code and detailed answers are organized within their respective `.asm` source files and documentation files.