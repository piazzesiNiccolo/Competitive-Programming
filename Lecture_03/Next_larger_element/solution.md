# Solution

The algorithm computes the solution using a stack q and a support array nexts to store the answer for each position. Traverse the array v from right to left and for every element x:

- pop any element of the stack smaller than x

- if the stack is now empty insert -1 in nexts, otherwise insert the top of the stack

- push x in the stack

When the array is fully scanned print from right to left the array nexts

## Time complexity

The algorithm scans the array v once and the array nexts once . The stack operations takes constant time. The total time complexity is O(n).

## Space complexity
