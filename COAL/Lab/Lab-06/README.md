# Lab 06 – Jump Instructions, Loops, Nested Loops, and Irvine32 Procedures

This lab focuses on controlling program execution and repeating instructions in Assembly Language using MASM and the Irvine32 library. It introduces unconditional jumps, counted loops, nested loops, loop-counter management, and practical applications of control flow in repetitive tasks and user interaction.

## Topics Covered

* Unconditional Control Transfer Using `JMP`
* Counted Repetition Using the `LOOP` Instruction
* Automatic Decrementing of the `ECX` Counter
* Nested Loops and Inner/Outer Loop Control
* Preserving the Outer Loop Counter During Nested Loops
* Skipping Instructions and Redirecting Program Execution
* Repetitive Output and Pattern Generation
* Reading Variable-Length User Input Using `ReadString`
* Managing Register Values Across Output Operations

---

## Tasks

### Task 01 – String Copying with Manual Null Termination

* Copy exactly 15 characters from `Source` to `Target` using indexed addressing and `LOOP`.
* Manually append a null terminator to `Target`.
* Display both strings.

### Task 02 – String Copying with a Null Terminator

* Copy a null-terminated source string into a target array using a loop and indexed addressing.

### Task 03 – Skipping Instructions Using JMP

* Use `JMP` to bypass an advertisement message and proceed directly to the billing notice.

### Task 04 – Multiples of Five Using LOOP

* Display the first ten multiples of 5 using `LOOP`.
* Update the value by 5 in each iteration.

### Task 05 – Star Pattern Using Nested Loops

* Use nested loops to display the required star pattern.
* Preserve the outer loop counter while executing the inner loop.

### Task 06 – Skipping a Message Using JMP

* Use `JMP` to bypass the second message and continue execution at the target label.

### Task 07 – Countdown Using LOOP

* Display the values from 10 down to 1 using the `LOOP` instruction.

### Task 08 – Array Traversal Using Indexed Addressing

* Traverse an integer array using indexed addressing and `LOOP`.
* Display each element.

### Task 09 – Student Records Using ReadString

* Accept the names and departments of three students using `ReadString`.
* Store each student's name and department in separate memory buffers.
* Display the collected records in the required format.

### Task 10 – Even Numbers Using LOOP

* Display the first ten even numbers, starting from 2.
* Increment the value by 2 in each iteration and separate the output with spaces.

---

## Learning Outcomes

* Understand how `JMP` redirects program execution without checking a condition.
* Use `LOOP` to implement counted repetition through automatic `ECX` decrementing.
* Construct nested loops and manage the outer loop counter while the inner loop executes.
* Apply loop-based control flow to generate patterns, sequences, and repeated output.
* Use unconditional jumps to skip selected instructions.
* Accept string input using `ReadString` and manage multiple student records.
* Recognize when register values must be preserved across output operations.

> **Note:** Task implementations are provided in their respective `.asm` source files. The original task statements are included as comments within the source files for reference.