# Lab 05 – Working with Data Related Operators, Directives and Addressing

This lab focuses on data manipulation, memory addressing, operators, directives, and flag handling in Assembly Language using MASM and the Irvine32 library. It covers CPU flags, direct-offset addressing, the `OFFSET` and `PTR` operators, indirect and indexed addressing, scale factors, the `TYPE` operator, the `LENGTHOF` operator, and array manipulation.

## Topics Covered

* CPU Flags: Carry Flag (`CF`), Sign Flag (`SF`), Zero Flag (`ZF`), Overflow Flag (`OF`)
* Data-Related Operators: `OFFSET`, `PTR`, `TYPE`, `LENGTHOF`
* Addressing Modes: Direct-Offset, Indirect, IndexedScale Factors
* Byte, WORD, and DWORD Arrays
* Array Traversal, Copying and Reversal
* Array Sorting and Element Swapping
* Loop-Based Array Processing
* Register-Based Array Operations

---

## Tasks

### Task 01 – CPU Flags

* Perform arithmetic operations and examine their effects on the CPU flags.
* Determine the states of the Carry, Sign, Zero, and Overflow flags after execution.
* Observe how different arithmetic results affect individual flags.

### Task 02 – Zero Flag

* Demonstrate the behavior of the Zero Flag using the `SUB` instruction.
* Observe the flag when an arithmetic operation produces a zero result.
* Compare the flag state when the result is non-zero.

### Task 03 – Direct-Offset Array Sorting

* Work with array elements using direct-offset addressing.
* Sort the array elements using registers without loop-based processing.
* Store and work with the sorted data separately.

### Task 04 – Reverse Array Copying

* Work with two arrays and transfer their elements in reverse order.
* Use `ESI` and `EDI` as pointers for accessing the source and destination arrays.
* Demonstrate pointer movement using `INC` and `DEC`.

### Task 05 – Scale Factors and TYPE

* Work with arrays of different data sizes including BYTE, WORD, and DWORD.
* Use the `TYPE` operator and scale factors for indexed memory access.
* Perform calculations on selected array elements and store the results in registers.

### Task 06 – OFFSET Operator

* Work with variables of different data sizes.
* Use the `OFFSET` operator to obtain their memory addresses.
* Display the resulting addresses using the Irvine32 `WriteHex` procedure.

### Task 07 – Direct-Offset Array Access

* Access specific elements of a BYTE array using direct-offset addressing.
* Move the selected values into registers for processing.
* Display the accessed values using the Irvine32 `WriteInt` procedure.

### Task 08 – PTR Operator

* Work with a DWORD value and access portions of it using different operand sizes.
* Use `BYTE PTR` and `WORD PTR` to extract specific parts of the value.
* Display the extracted byte and word values using `WriteHex`.

### Task 09 – Indexed Addressing

* Access elements of a WORD array using indexed addressing.
* Use register-based indexing to select specific array elements.
* Perform an arithmetic operation on the selected elements and display the result.

### Task 10 – LENGTHOF Operator

* Work with BYTE and WORD arrays of different lengths.
* Use the `LENGTHOF` operator to determine the number of elements.
* Display the calculated array lengths.

### Task 11 – Indirect Addressing and Loop

* Traverse a DWORD array using indirect addressing.
* Use `ESI` or `EDI` as an index pointer during traversal.
* Apply a loop to process the array elements and calculate their sum.

### Task 12 – Array Sorting Using Indirect Addressing

* Sort a BYTE array in ascending order using indirect addressing.
* Use `ESI` and `EDI` to access and manipulate array elements.
* Use comparisons, swapping, and loops to perform the sorting process.

### Task 13 – TYPE and Scale Factors

* Work with a DWORD array using indexed addressing.
* Apply the `TYPE` operator and scale factors to access array elements.
* Perform separate calculations on selected pairs of elements and display the results.

---


## Learning Outcomes

* Understand the purpose and behavior of CPU flags such as `CF`, `SF`, `ZF`, and `OF`.
* Understand and apply direct-offset addressing.
* Use the `OFFSET` operator to obtain memory addresses.
* Use the `PTR` operator to access data with a specific operand size.
* Use the `TYPE` operator to determine the size of data elements.
* Use `LENGTHOF` to determine the number of elements in an array.
* Understand indirect and indexed addressing techniques.
* Apply scale factors when accessing BYTE, WORD, and DWORD arrays.
* Traverse arrays using ESI and EDI registers.
* Perform array copying and reversal using memory addresses.
* Compare and swap array elements.
* Implement basic ascending-order sorting using Assembly Language.
* Perform arithmetic operations on array elements using different addressing modes.
* Develop familiarity with MASM data-related operators, directives, and addressing techniques.

> **Note:** Task implementations are provided in their respective `.asm` source files. The original task statements are included as comments within the source files for reference.