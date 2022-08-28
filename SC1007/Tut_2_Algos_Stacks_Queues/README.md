# Tutorial 2: Analysis of Algorithms and Stacks and Queues

## Q1: 
Worst case: θ(mn), where m is the length of the first list, and n is the length of the second.

This worst case will happen when the first linked list is a subset of the second linked list, and the first linked list is filled with the last integer of the second linked list.

To illustrate, eg.

- List1: [1, 1, 1, 1, 1, 1]
- List2: [3, 2, 4, 2, 5, 6, 1]
