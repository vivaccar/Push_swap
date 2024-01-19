# PushSwap
## Description
PushSwap is a sorting algorithm project that involves organizing a random stack of numbers in ascending order using two stacks, named 'a' and 'b.' The goal is to achieve the desired order through a set of predefined operations. The operations include swapping elements, pushing elements between stacks, and rotating elements within a stack.

## Rules
You have two stacks named a and b.
At the beginning:
Stack a contains a random amount of negative and/or positive numbers, which cannot be duplicated.
Stack b is initially empty.
The objective is to sort the numbers in ascending order into stack a.
## Available Operations
sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

ss: Perform sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

rr: Perform ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

rrr: Perform rra and rrb at the same time.

# Turkish Algorithm
Here's a step-by-step breakdown of the algorithm:

Initial Setup: Push two numbers from STACK_A to STACK_B.

Finding the Cheapest Number:

For each number in STACK_A, calculate the number of operations needed to push it into the correct position in STACK_B.
Operations may include rotations of the stacks and pushing elements.
Keep track of the cheapest number.
Push the Cheapest Number:

Push the cheapest number found in step 2 to STACK_B.
Repeat step 2 for the remaining numbers in STACK_A until it is empty.
Stop at Three Elements:

Stop the algorithm when there are three elements left in STACK_A.
These three elements can be sorted with one or two operations.
Push Everything Back to STACK_A:

Push all elements from STACK_B back to STACK_A.
Before pushing each element, check if it's in the correct position; if not, rotate STACK_A until the correct position is reached.
Final Arrangement:

Ensure that the minimum number is at the top of STACK_A to ensure the entire stack is sorted.
