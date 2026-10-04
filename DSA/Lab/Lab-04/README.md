# Lab 04 – Linked Lists and Types of Linked Lists

This lab focuses on linked lists and their different types and implementations in C++. It covers singly linked lists, doubly linked lists, circular linked lists, and circular doubly linked lists through insertion, deletion, traversal, and modification operations.

## Topics Covered

* Linked Lists
* Singly Linked Lists
* Doubly Linked Lists
* Circular Linked Lists
* Circular Doubly Linked Lists
* Node insertion and deletion
* Linked list traversal

---

## Tasks

### Task 01 – Even and Odd Separation

* Implement a singly linked list and rearrange its elements while preserving their relative order.

### Task 02 – Circular Linked List

* Implement a circular singly linked list with insertion, deletion, and traversal operations.

### Task 03 – Circular Doubly Linked List

* Implement a circular doubly linked list with insertion, deletion, and traversal operations.

---

## Learning Outcomes

* Understand the structure and working of linked lists.
* Implement nodes using dynamic memory and pointers.
* Differentiate between singly, doubly, and circular linked lists.
* Implement insertion and deletion operations.
* Traverse circular linked lists correctly.
* Maintain both `next` and `prev` links in a circular doubly linked list.
* Modify linked lists while preserving the required element order.

---

## Cheat Sheet

| Linked List Type | Key Idea | Key Point |
| ---------------- | -------- | --------- |
| **Singly Linked List** | Each node points to the next node | Forward traversal |
| **Doubly Linked List** | Each node has `next` and `prev` pointers | Forward and backward traversal |
| **Circular Linked List** | Last node points to the first node | No `NULL` at the end |
| **Circular Doubly Linked List** | Nodes have both `next` and `prev` links | `tail->next = head` and `head->prev = tail` |

> **Note:** Task implementations are provided in their respective `.cpp` source files. The original task statements are included as comments within the source files for reference.