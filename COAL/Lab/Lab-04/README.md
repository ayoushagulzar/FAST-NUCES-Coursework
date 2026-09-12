# Lab 04 – Working with Operators, Instructions and Symbolic Constants

This lab focuses on arithmetic and data manipulation in Assembly Language using MASM and the Irvine32 library. It covers arithmetic instructions, register operations, data movement, sign and zero extension, symbolic constants, exchange operations, and basic expression evaluation.

## Topics Covered

* Arithmetic Instructions
* `ADD` and `SUB` Instructions
* `INC` and `DEC` Instructions
* Register-Based Arithmetic
* Signed and Unsigned Data Extension
* `MOVSX` and `MOVZX`
* Symbolic Constants
* Equal-Sign Directive (`=`)
* Arithmetic Expressions in Constants
* Register Exchange using `XCHG`
* Data Swapping
* Working with Byte, Word, and Doubleword Values
* Hexadecimal Data Representation

---

## Tasks

### Task 01 – Marks Calculation

* Store marks of two subjects.
* Use `ADD` to calculate the total marks.
* Use `SUB` to calculate the difference between the marks.

### Task 02 – Account Balance

* Initialize a customer's account balance.
* Use `ADD` to perform a deposit.
* Use `SUB` to perform a withdrawal.
* Update the final account balance.

### Task 03 – Temperature Calculation

* Store day and night temperatures.
* Calculate their difference using `SUB`.
* Increment the night temperature using `INC`.

### Task 04 – Inventory Update

* Initialize the number of items in inventory.
* Use `SUB` to update the inventory after a purchase.
* Use `ADD` to update the inventory after restocking.

### Task 05 – Sign and Zero Extension

* Load a signed byte value into a register.
* Extend the value to word size using `MOVSX`.
* Perform zero extension using `MOVZX`.
* Observe the difference between sign extension and zero extension.

### Task 06 – Increment and Decrement

* Initialize a value.
* Increment the value multiple times using `INC`.
* Decrement the value using `DEC`.
* Observe the final result after the arithmetic operations.

### Task 07 – Symbolic Constant

* Define a symbolic constant `PI` using the equal-sign directive.
* Use the constant in an arithmetic expression.
* Calculate `PI * 4`.

### Task 08 – Register Exchange

* Initialize values in `AX` and `BX`.
* Use the `XCHG` instruction to swap their contents.
* Observe the values after the exchange.

### Task 09 – Arithmetic Expression in a Symbolic Constant

* Declare a symbolic constant named `SecondsInDay`.
* Use the equal-sign directive to assign an arithmetic expression.
* Calculate the total number of seconds in a 24-hour period.

### Task 10 – Swapping Values

* Initialize two hexadecimal values.
* Swap their contents using Assembly Language instructions.
* Verify the values after swapping.

### Task 11 – Register and Memory Operations

* Work with byte, word, and doubleword variables.
* Increment the value stored in a word variable.
* Subtract a doubleword value from the `EAX` register.
* Subtract one word variable from another.
* Move a byte value into the `BL` register.

---

## Learning Outcomes

* Understand the use of basic arithmetic instructions in Assembly Language.
* Perform addition and subtraction using registers and memory operands.
* Use `INC` and `DEC` for increment and decrement operations.
* Understand the difference between sign extension and zero extension.
* Apply `MOVSX` and `MOVZX` to extend smaller data types.
* Define and use symbolic constants with the equal-sign directive.
* Evaluate arithmetic expressions during assembly time.
* Use `XCHG` to exchange register contents.
* Perform basic data swapping operations.
* Work with different operand sizes including byte, word, and doubleword values.
* Develop familiarity with MASM operators and instructions for manipulating data.

> **Note:** Task implementations are provided in their respective `.asm` source files. The original task statements are included as comments within the source files for reference.
