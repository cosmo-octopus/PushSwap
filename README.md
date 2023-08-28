# Push_Swap

The **Push_Swap** project aims to sort a set of integers using a specific set of instructions on two stacks. This program generates a sequence of push_swap instructions to achieve the desired sorting.

> :warning: **Note:** Understand all code before using it; copying without comprehension is detrimental.

## Instruction Set

The following instructions are utilized for sorting:

Code | Instruction | Action
---- | ----------- | ------
sa   | swap a      | Swaps the top 2 elements of stack a
sb   | swap b      | Swaps the top 2 elements of stack b
ss   | swap a + swap b | Performs both sa and sb
pa   | push a      | Moves the top element of stack b to the top of stack a
pb   | push b      | Moves the top element of stack a to the top of stack b
ra   | rotate a    | Shifts all stack a elements from bottom to top
rb   | rotate b    | Shifts all stack b elements from bottom to top
rr   | rotate a + rotate b | Performs both ra and rb
rra  | reverse rotate a | Shifts all stack a elements from top to bottom
rrb  | reverse rotate b | Shifts all stack b elements from top to bottom
rrr  | reverse rotate a + reverse rotate b | Performs both rra and rrb

## Algorithm

For stacks with a size less than 6, a simple sorting method is employed (found in the `src` folder).

The primary algorithm used is **Radix sort**. This efficient algorithm sorts non-negative integers with a time complexity of O(n). It operates by distributing numbers into "boxes" based on their digits and then rearranging them based on the box order.

- Sort starts from the least significant digit.
- Each number is placed in the box corresponding to its digit.
- Numbers are then connected in order of the boxes.

This process is repeated for each digit, resulting in a fully sorted array.

## Simplifying Numbers

Since negative numbers are present in the project, numbers are simplified before sorting. Each number is assigned an index, with the smallest getting index 0, next smallest getting 1, and so on. This simplifies the range to [0, N), where N is the size of the list.

Additionally, to replicate the boxes used in Radix sort, two stacks are employed, corresponding to 1s and 0s. The process is as follows:

- Start from the rightmost bit.
- If the bit of the top number in stack A is 0, perform pb (push to stack B); else, perform ra (rotate A).
- After all numbers are processed, they are in the box corresponding to their digit.

This procedure is repeated for every bit, resulting in a sorted stack A.

## Algorithm Performance

The push_swap algorithm achieves:

- 3 numbers sorted in a maximum of 3 instructions
- 4 numbers sorted in a maximum of 7 instructions
- 5 numbers sorted in a maximum of 11 instructions
- 100 numbers sorted in a maximum of 1084 instructions (3 points)
- 500 numbers sorted in a maximum of 6785 instructions (4 points)

The algorithm is sufficient for project requirements and can exceed 105% with bonus completion.

## Bonus

The bonus task involves writing a program named **checker** that takes stack A as an argument (formatted as a list of integers). Checker reads instructions from standard input, executes them on the stack, and then verifies the sorting.

- If stack A is sorted and stack B is empty, checker displays "OK."
- Otherwise, it displays "KO."
- Invalid arguments result in an "Error" message.


<img width="147" alt="image" src="https://user-images.githubusercontent.com/119530584/224474718-2df6347d-65a4-4cf7-a025-1a5f865f7b9d.png">
