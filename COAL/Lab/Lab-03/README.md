# Lab 03 – Data and Its Types, Definition Statements & Assembly Instructions

This lab focuses on data representation, data definition statements, arrays, strings, signed and unsigned data types, and basic arithmetic operations in Assembly Language using MASM and the Irvine32 library.

## Topics Covered

* Data Definition Statements
* MASM Intrinsic Data Types
* Signed and Unsigned Integers
* Byte, Word, Doubleword, and String Data
* Array Declaration and Initialization
* One-Dimensional Arrays
* Two-Dimensional Arrays
* Initialized and Uninitialized Data
* String Storage and Null Termination
* Repeated Data Initialization using `DUP`
* Arithmetic Expression Evaluation
* Register-Based Arithmetic using `ADD` and `SUB`

---

## Tasks

### Task 01 – Arithmetic Expression Evaluation

* Translate a high-level arithmetic expression into equivalent Assembly Language instructions.
* Use registers to store intermediate values during expression evaluation.
* Apply addition and subtraction operations to obtain the final result.

### Task 02 – Byte Array Declaration

* Declare and initialize an array using the appropriate unsigned byte data type.
* Understand how multiple byte-sized elements are stored sequentially in memory.

### Task 03 – Repeated String Data

* Define a string containing repeated character sequences.
* Use MASM's `DUP` operator to efficiently initialize repeated data.

### Task 04 – Uninitialized Doubleword Array

* Allocate memory for an array of unsigned doublewords without assigning initial values.
* Understand the distinction between initialized and uninitialized data allocation.

### Task 05 – Multiple Initializers

* Declare an unsigned 16-bit variable using multiple initializers.
* Observe how MASM handles multiple values associated with a single data declaration.

### Task 06 – Two-Dimensional Data Representation

* Represent structured student marks using a two-dimensional array.
* Organize data according to students and their corresponding subjects.
* Understand how multi-dimensional data can be laid out sequentially in Assembly Language memory.

### Task 07 – Signed Integer Array

* Declare an array using a signed integer data type.
* Initialize the array with representative values.
* Understand the use of signed data when representing values that may be positive or negative.

### Task 08 – Signed Doubleword Variables

* Declare signed 32-bit integer variables with initialized and uninitialized storage.
* Understand the relationship between variable declarations and the amount of memory allocated.

### Task 09 – Word Array Initialization

* Declare an array of unsigned 16-bit values.
* Initialize all elements with the same value using the `DUP` operator.

### Task 10 – Null-Terminated String Storage

* Allocate fixed-size storage for a character string.
* Store a specified message as a null-terminated string.
* Understand string termination and reserved memory capacity.

---

## Learning Outcomes

* Understand how different data types are represented and allocated in Assembly Language.
* Select appropriate MASM data types for signed and unsigned values.
* Declare and initialize variables, arrays, and strings using definition statements.
* Differentiate between initialized and uninitialized data.
* Use the `DUP` operator for efficient repeated initialization.
* Represent one-dimensional and two-dimensional data structures in memory.
* Understand fixed-size character storage and null-terminated strings.
* Translate basic arithmetic expressions into Assembly Language instructions.
* Use registers effectively for intermediate arithmetic calculations.
* Develop familiarity with MASM syntax for data declaration and memory allocation.

> **Note:** Task implementations are provided in their respective `.asm` source files. The original task statements are included as comments within the source files for reference.
