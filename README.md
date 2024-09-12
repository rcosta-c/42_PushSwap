# Push Swap - 42 Porto

![C](https://img.shields.io/badge/C-Language-blue?style=for-the-badge)
![Sorting Algorithms](https://img.shields.io/badge/Sorting-Algorithms-green?style=for-the-badge)
![42 School](https://img.shields.io/badge/42-Porto-black?style=for-the-badge)

## 📝 Description

The **Push Swap** project is about sorting a stack of integers using a set of predefined operations with the least number of moves possible. This project allows you to explore and implement various sorting algorithms and optimize their performance, focusing on stack-based data manipulation.

## 🚀 Features

- Implementation of stack-based sorting algorithms.
- Use of a limited set of operations to sort the numbers in ascending order.
- Efficient handling and sorting of small to large sets of integers.

## 📂 File Structure

ft_median.c    ft_stacking.c    ft_ops.c    ft_stack_utils.c
ft_order.c    main.c    ft_rotate.c      Makefile    ft_limits.c	
ft_find_error.c    ft_sort.c    push_swap.h    ft_sort_stack.c  

## 🛠️ Technologies Used

- **C** - Programming Language
- **Stack Data Structure** - To manipulate integers using push and pop operations.
- **Makefile** - To compile and manage the project.
- **GCC** - C Compiler.

📚 How to Use
Running the Program
After compiling, you can run the program to sort a list of integers:

bash
Copiar código
./push_swap <list of integers>
Example:

bash
Copiar código
./push_swap 5 2 9 1 3
The program will output a series of instructions that describe how to sort the list using predefined operations.

Operations
sa - Swap the first two elements at the top of stack A.
sb - Swap the first two elements at the top of stack B.
ss - Perform sa and sb simultaneously.
pa - Push the top element of stack B to stack A.
pb - Push the top element of stack A to stack B.
ra - Rotate all elements of stack A upwards.
rb - Rotate all elements of stack B upwards.
rr - Perform ra and rb simultaneously.
rra - Reverse rotate all elements of stack A downwards.
rrb - Reverse rotate all elements of stack B downwards.
rrr - Perform rra and rrb simultaneously.
Sorting Logic
Small Sets: For small sets of integers (e.g., 3 or 5 numbers), use a brute-force approach to find the optimal sequence of moves.
Large Sets: For larger sets, use more sophisticated algorithms like the Quicksort or Radix Sort adapted to a stack-based structure to optimize the number of moves.




