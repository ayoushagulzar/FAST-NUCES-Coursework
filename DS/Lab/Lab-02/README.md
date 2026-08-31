# Lab-02 – Arrays

This lab focuses on dynamic memory management, object-oriented design, safe 2D array implementations, operator overloading, deep copying, and image processing using matrix convolution in C++.

## Topics Covered

* Dynamic Memory Allocation (`new`, `delete`, `new[]`, `delete[]`)
* Rule of Three (Destructor, Copy Constructor, Copy Assignment Operator)
* 1D Flattened Arrays vs. Pointer-to-Pointer 2D Arrays
* Pointer Arithmetic & Row-Major Memory Layout
* Function & Operator Overloading (`operator()`)
* Boundary Checking & Exception Management
* Deep Copying & Memory Safety
* 2D Image Filtering & Matrix Convolution

---

## Tasks

### Task 01 – 1D Flattened Dynamic 2D Array

* Implement a `twoDarray` class using a single contiguous dynamically allocated 1D array.
* Calculate element locations using the row-major offset formula:
  `offset = (i * nCols) + j`.
* Overload `operator()(int i, int j)` for intuitive 2D indexing.
* Perform boundary checking and safely terminate the program using `exit(1)` when an invalid index is accessed.
* Implement the Rule of Three using a destructor, copy constructor, and copy assignment operator.
* Perform deep copying using `memcpy` to prevent shallow-copy and memory-management issues.

### Task 02 – Pointer-to-Pointer Dynamic 2D Array

* Implement an `atype` class using a pointer-to-pointer structure (`int **dynamicArray`).
* Dynamically allocate memory for each row separately.
* Implement proper memory cleanup using `delete[]` for every allocated row and the outer pointer array.
* Overload `operator()(int i, int j)` for direct 2D matrix access.
* Add boundary checking to prevent invalid row and column access.
* Implement deep copying across individual row pointers to avoid pointer aliasing and double-free errors.
* Apply the Rule of Three for safe dynamic memory management.

### Task 03 – Image Processing & Matrix Convolution

* Implement an `Image` class for storing and processing image data using a dynamic 2D matrix.
* Initialize matrix elements and provide bounds-checked access through `operator()(int row, int col)`.
* Implement a `3 × 3` kernel convolution algorithm using `applyKernel()`.
* Slide the kernel across an `N × M` input matrix to produce an `(N - 2) × (M - 2)` output matrix.
* Apply a `3 × 3` averaging kernel to a sample `5 × 5` image matrix.
* Calculate the scalar products for each kernel position and store the filtered values in a new `3 × 3` result matrix.

---

## Learning Outcomes

* Understand the difference between contiguous 1D memory allocation and pointer-to-pointer 2D dynamic arrays.
* Apply the Rule of Three to safely manage dynamically allocated memory.
* Implement deep copying to prevent memory leaks, dangling pointers, and double-free errors.
* Use operator overloading to provide intuitive and safe matrix indexing.
* Perform runtime boundary checking for dynamically allocated arrays.
* Understand the sliding-window mechanism used in matrix convolution.
* Implement basic image filtering using a `3 × 3` averaging kernel.
* Strengthen understanding of low-level memory management and object-oriented programming in C++.


