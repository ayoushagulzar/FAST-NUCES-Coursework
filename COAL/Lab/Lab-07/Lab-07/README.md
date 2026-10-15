# Lab 07 – Stack Operations and Procedures

This lab focuses on using stack operations and procedures in Assembly Language with MASM and the Irvine32 library. It covers storing and retrieving values using the stack, performing calculations, and organizing programs using procedures and nested procedure calls.

## Topics Covered

- Stack Operations Using `PUSH` and `POP`
- LIFO (Last-In, First-Out) Principle
- Array Element Transfer Using the Stack
- Arithmetic Operations Using Stack-Stored Values
- Procedure Declaration and Calling
- Returning Results from Procedures
- Nested Procedure Calls
- Pattern Generation Using Procedures
- Using Procedures for Summation and Value Comparison

---

## Tasks

### Task 01 – Moving Word-Type Array Elements Using the Stack

- Transfer 10 word-type numbers from one array to another using `PUSH` and `POP`.
- Display the elements of the destination array.

### Task 02 – Addition of Three Integers Using a Stack

- Take three integers as input.
- Store and retrieve the values using stack operations.
- Calculate and display their sum.

### Task 03 – Sum of Two Arrays Using Nested Procedures

- Calculate the sum of each five-element array in separate procedures.
- Use a third procedure to add both sums.
- Display the final result.

### Task 04 – Pattern Generation Using a Procedure

- Print the required pattern using a procedure.
- Pass the number of columns through a variable.

### Task 05 – Sum of Numbers from 1 to n

- Take a number `n` as input.
- Calculate the sum of numbers from 1 to `n` using a procedure.
- Display the result.

### Task 06 – Code Review Score Evaluation

- Display the code review welcome message.
- Take three integer scores as input.
- Use stack operations and nested procedures to calculate the total score.
- Display the final score.

### Task 07 – IEEE Xtreme Code Champion

- Take the lines of code completed by three participants as input.
- Use procedures and stack operations to compare their scores.
- Display the participant who completed the highest number of lines of code.

---

## Learning Outcomes

- Use `PUSH` and `POP` to store and retrieve values using the stack.
- Apply the LIFO principle when handling data.
- Transfer array elements and perform arithmetic calculations using stack operations.
- Create and call procedures to organize program instructions.
- Use nested procedures to divide calculations into smaller tasks.
- Return and combine calculation results using registers.
- Apply procedures and stack operations to solve problems involving summation, pattern generation, and value comparison.

> **Note:** Each task is implemented in its respective `.asm` source file. The original task statements are included as comments in the source files for reference.