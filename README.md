
# Data Structures and Algorithms 

## Overview
This repository contains the implementations and documentation for three projects on Data Structures and Algorithms. Each project involves the implementation and analysis of various data structures and algorithms.

## Projects

### A2: Binary Search Trees

**Description:**
This project focuses on implementing and analyzing operations on Binary Search Trees (BSTs). The tasks include:
1. Implementing additional member functions (`displayLinks()`, `height()`, and `depth()`) for the BST.
2. Conducting an experiment to compare the performance of a "tall and skinny" BST and a "realistic" BST in terms of membership test times and average search depths.

**Files:**
- `BinarySearchTree.h`: Modified to include new member functions.
- `DLtest.cpp`: Demonstrates correctness of `displayLinks()`.
- `Htest.cpp`: Demonstrates correctness of `height()`.
- `Dtest.cpp`: Demonstrates correctness of `depth()`.
- `Exp1.cpp`: Carries out the experiment for Part 1.
- `Exp2.cpp`: Carries out the experiment for Part 2.
- `report.pdf`: Contains the experiment reports.
- `Makefile`: Ensures proper compilation and cleaning of the project.

### A3: Priority Queues with Indexed Heaps

**Description:**
This project involves implementing a priority queue using an indexed heap to efficiently handle priority updates. The tasks include:
1. Implementing a `PQ` class with operations such as `insert`, `deleteMin`, `findMin`, `updatePriority`, `isEmpty`, `size`, and `makeEmpty`.
2. Documenting the design and demonstrating the correctness of the implementation.
3. Conducting an experiment to compare the performance of the indexed heap with a simple heap for various operations.

**Files:**
- `PQ.h`: Implementation of the `PQ` class.
- `PQdemo.cpp`: Demonstrates correctness of the `PQ` class.
- `Doc.pdf`: Contains the design documentation and optional experiment report.
- `Makefile`: Ensures proper compilation and cleaning of the project.

### A4: Experiments on CPU Cache Effects

**Description:**
This project involves conducting experiments to observe and quantify the effects of CPU cache on data structure performance. The tasks include:
1. Implementing the following experiments
   - Experiment 1: Demonstrates cache effects using loops with different array access patterns.
   - Experiment 3: Compares traversal times of lists implemented as arrays, simple linked lists, and unrolled linked lists.
2. Writing a report detailing the experimental setup, data, and interpretations.

**Files:**
- `exp1.cpp`: Implementation for Experiment 1.
- `exp3.cpp`: Implementation for Experiment 3.
- `report.pdf`: Contains the experiment reports.
- `Makefile`: Ensures proper compilation and cleaning of the project.

## Requirements
- C++ Compiler (GCC recommended)
- Unix-like Operating System

## Compilation and Execution
To compile the projects, navigate to the respective project directory and run:
```bash
make
```
To clean up compiled files, run:
```bash
make clean
```

## License
This project is licensed under the MIT License.
