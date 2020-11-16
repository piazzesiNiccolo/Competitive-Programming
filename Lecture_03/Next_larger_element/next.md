# Solution

The algorithm computes the solution using a stack q and a support array nexts to store the answer for each position. Traverse the array v from right to left and for every element x:

- pop any element of the stack smaller than x

- if the stack is now empty insert -1 in nexts, otherwise insert the top of the stack

- push x in the stack

At the end return the array nexts reversed in order to output the solution from left to right

## Time complexity

O(n)

## Space complexity

O(n)
