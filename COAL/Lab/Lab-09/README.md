

# Lab 09 – Integer Arithmetic

This lab focuses on performing integer arithmetic operations in Assembly Language using MASM and the Irvine32 library. It covers bitwise shifting and rotation, multiplication and division, signed and unsigned arithmetic, extended addition, bit extraction, and basic data encryption using byte rotations.

## Topics Covered

- Bitwise Shift Operations Using `SHL` and `SHR`
- Bit Rotation Using `ROL` and `ROR`
- Variable Rotation Using the `CL` Register
- Multiplication and Division Using Shift Instructions
- Unsigned Multiplication Using Shifting and Addition
- Signed and Unsigned Integer Arithmetic
- Extended 64-bit Addition Using `ADD` and `ADC`
- Binary Multiplication
- Bit Extraction Using Shift and Mask Operations
- Signed Division and Multiplication
- Simple Encryption Using Variable Byte Rotations

---

## Tasks

### Task 01 – Rotating a Byte Left

- Take a byte value.
- Rotate it left by one bit using `ROL`.
- Display the original and rotated values.

### Task 02 – Shifting an Integer

- Shift an integer left by 3 bits using `SHL`.
- Shift the result right by 2 bits using `SHR`.
- Display the result after each operation.

### Task 03 – Variable Bit Rotation

- Take an 8-bit value and a rotation count as input.
- Rotate the value by the specified number of bits.
- Display the original and rotated values.

### Task 04 – Multiplication Using Left Shift

- Multiply a given number by 4 using left shifts.
- Display the result.

### Task 05 – Division Using Right Shift

- Divide a 16-bit unsigned integer by 8 using `SHR`.
- Display the result.

### Task 06 – Unsigned Multiplication Using Shifting and Addition

- Implement a procedure to perform unsigned 32-bit multiplication.
- Use only shifting and addition operations.
- Call the procedure with a multiplier and display the product.

### Task 07 – Addition of Two 16-bit Integers

- Take two 16-bit integers.
- Add them using the `ADD` instruction.
- Display the result.

### Task 08 – Subtraction of Two Signed 32-bit Integers

- Subtract two signed 32-bit integers.
- Display the result.

### Task 09 – Extended Addition of 64-bit Integers

- Implement a procedure named `ExtendedAdd`.
- Add two 64-bit integers using 32-bit registers.
- Handle the carry between the lower and upper halves.

### Task 10 – Multiplication Using Binary Representation

- Calculate `EAX * 21` using binary multiplication.
- Perform the calculation using shift and addition instructions.

### Task 11 – Extracting Minutes from a Timestamp

- Extract the minutes field from a file directory timestamp.
- Use bits 5 through 10.
- Store the extracted value in a byte variable named `bMinutes`.

### Task 12 – Implementing a C++ Expression

- Translate the given C++ arithmetic expression into Assembly Language.
- Use 32-bit signed operands.

### Task 13 – Simple Encryption Using Byte Rotation (Bonus)

- Implement simple encryption by rotating plaintext bytes.
- Use an encryption key array to determine the rotation count and direction.
- Rotate bytes left for negative key values and right for positive key values.
- Apply the key to the first 10 plaintext bytes, then repeat it for each subsequent group of 10 bytes.

---

## Learning Outcomes

- Perform integer arithmetic using Assembly Language instructions.
- Understand and apply bitwise shifting and rotation operations.
- Use variable rotation counts through the `CL` register.
- Implement multiplication and division using shift operations.
- Perform signed and unsigned arithmetic operations.
- Implement procedures for multiplication and extended addition.
- Handle carry propagation when working with 64-bit integers.
- Extract specific bit fields using shifting and masking.
- Apply binary multiplication techniques to arithmetic expressions.
- Understand the use of byte rotations in basic encryption.

> **Note:** Each task is implemented in its respective `.asm` source file. The original task statements are included as comments in the source files for reference.

