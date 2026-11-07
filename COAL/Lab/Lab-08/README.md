

# Lab 08 – Conditional Processing

This lab focuses on conditional processing and decision-making in Assembly Language using MASM and the Irvine32 library. It covers comparison instructions, conditional jumps, searching and sorting arrays, character validation, grading systems, and counting positive, negative, and zero values.

## Topics Covered

- Comparison Using the `CMP` Instruction
- Conditional and Unconditional Jump Instructions
- Equality and Inequality Checking
- Array Traversal Using Loops
- Sequential Search
- Bubble Sort
- Character Validation Using ASCII Values
- Conditional Processing and Decision-Making
- Grade Calculation Using Conditional Jumps
- Signed Integer Comparison
- Counting Positive, Negative, and Zero Values

---

## Tasks

### Task 01 – Comparing Four Integers

- Take four integers as input from the user.
- Compare all four values using conditional instructions.
- Display whether all integers are equal or not.

### Task 02 – Finding the First Non-Zero Array Element

- Traverse the given signed word array using a loop.
- Use `CMP` and conditional jumps to find the first non-zero element.
- Display the first non-zero value.

### Task 03 – Conditional Processing Using Assembly Instructions

- Implement the given code in Assembly Language.
- Consider `var = 0`.
- Use appropriate comparison and conditional jump instructions.

### Task 04 – Sequential Search

- Take an integer as input from the user.
- Search for the input value in the given word array.
- Display whether the value is found or not.

### Task 05 – Bubble Sort

- Implement bubble sort on the given word array.
- Compare adjacent elements and swap them when necessary.
- Display the sorted array in ascending order.

### Task 06 – Character Validation

- Take a character as input from the user.
- Check whether the character is an alphabet or not.
- Display the appropriate message.

### Task 07 – Grade Calculation

- Take marks between 0 and 100 as input.
- Assign grades according to the following criteria:
  - 90–100 → A
  - 80–89 → B
  - 70–79 → C
  - 60–69 → D
  - Below 60 → F
- Display "Invalid marks" if the input is below 0 or above 100.

### Task 08 – Counting Positive, Negative, and Zero Values

- Traverse the given signed doubleword array.
- Count the positive, negative, and zero elements separately.
- Display all three counts.

---

## Learning Outcomes

- Use `CMP` to compare values and make decisions.
- Apply conditional jumps to control program execution.
- Implement equality and inequality checks.
- Traverse arrays using loops and conditional instructions.
- Perform sequential searching and bubble sorting.
- Validate characters using ASCII ranges.
- Implement grading logic using conditional processing.
- Compare signed integers correctly.
- Count positive, negative, and zero values in an array.

> **Note:** Each task is implemented in its respective `.asm` source file. The original task statements are included as comments in the source files for reference.

