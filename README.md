# Push Swap

This repository contains the implementation of the Push Swap project, which is part of the curriculum at 42 School. The Push Swap project focuses on algorithmic problem-solving and sorting algorithms.

## Project Description

Push Swap is a sorting algorithm that takes an unordered list of integers as input and sorts the list using two stacks and a set of specific operations. The goal is to sort the integers in the least number of moves.

The project also includes a checker program that validates the sorting order.

## Usage

To use this program, follow these steps:

1. Clone the repository or download the relevant files.
2. Compile the code using the provided Makefile to generate both the push_swap and checker executables.
3. Run the push_swap executable, providing a list of integers to sort.
4. Optionally, run the checker executable with the generated output to verify the sorting.

Example usage:
```bash
./push_swap 4 2 7 1
./checker 4 2 7 1
```

## Code Structure

The code is structured to handle the following main tasks:

1. Parsing and validating input arguments.
2. Implementing sorting algorithms using stacks and specific operations (e.g., swap, push, rotate).
3. Generating the optimal set of instructions to sort the list.
4. Checking the correctness of the sorting using the checker program.

The main sorting algorithm and program are contained in the `push_swap.c` file, and relevant functions are organized in separate C files.

## Documentation

For more detailed information about the project, including its requirements and specifics, please refer to the official project documentation and subject provided by 42 School.
