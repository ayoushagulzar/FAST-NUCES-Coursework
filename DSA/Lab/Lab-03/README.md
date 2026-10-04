# Lab 03 – Elementary Sorting Techniques

This lab focuses on elementary sorting techniques and their implementation in C++. It covers different approaches to sorting data and analyzing their behavior through comparisons, swaps, shifts, passes, and gaps.

## Topics Covered

* Bubble Sort
* Modified Bubble Sort
* Selection Sort
* Comb Sort
* Shell Sort
* Insertion Sort

---

## Tasks

### Task 01 – Standard Bubble Sort

* Implement standard Bubble Sort to arrange product prices in ascending order.
* Analyze the number of passes, comparisons, and swaps performed.
* Display the array after each pass to observe the sorting process.

### Task 02 – Modified Bubble Sort

* Implement Modified Bubble Sort for nearly sorted attendance data.
* Detect when the array becomes sorted and terminate the algorithm early.
* Count the passes, comparisons, and swaps performed before termination.
* Compare its performance with standard Bubble Sort on the same data.

### Task 03 – Comb Sort

* Implement Comb Sort to arrange product quantities in ascending order.
* Use progressively reduced gaps to move elements that are far from their correct positions.
* Display the gap used during each major iteration.

### Task 04 – Shell Sort

* Implement Shell Sort to arrange server load values in ascending order.
* Process the array using gaps starting from `n/2` and repeatedly reduce them by half.
* Display the complete array after processing each gap.
* Count comparisons and shifts separately for each gap.
* Calculate the total comparisons and shifts performed.

### Task 05 – Insertion Sort

* Implement Insertion Sort to arrange student marks in descending order.
* Count the total comparisons and shifts performed during sorting.
* Determine the highest, lowest, and average marks.
* Identify whether any student is a high achiever based on the given threshold.

---

## Learning Outcomes

* Understand and implement different elementary sorting techniques.
* Differentiate between standard and modified Bubble Sort.
* Analyze the effect of early termination on Bubble Sort performance.
* Understand gap-based sorting through Comb Sort and Shell Sort.
* Apply Insertion Sort for descending-order data.
* Analyze sorting algorithms using comparisons, swaps, shifts, passes, and gaps.
* Compare the behavior and performance of different sorting techniques through intermediate results.

---

## Cheat Sheet

| Technique                | Key Idea                                       | Key Point                                    |
| ------------------------ | ---------------------------------------------- | -------------------------------------------- |
| **Bubble Sort**          | Compare adjacent elements and swap when needed | Standard version performs `n - 1` passes     |
| **Modified Bubble Sort** | Bubble Sort with early termination             | Stops when a complete pass makes no swaps    |
| **Selection Sort**       | Select the minimum/maximum for each position   | One swap at the end of each pass             |
| **Comb Sort**            | Compare elements separated by a gap            | Gap gradually decreases to `1`               |
| **Shell Sort**           | Gapped Insertion Sort                          | Gap starts at `n/2` and is repeatedly halved |
| **Insertion Sort**       | Insert each element into the sorted portion    | Uses shifts to place the current element     |


> **Note:** Task implementations are provided in their respective `.cpp` source files. The original task statements are included as comments within the source files for reference.
