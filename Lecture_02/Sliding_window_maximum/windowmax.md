# Solution
The algorithm computes the maximum of every window using a deque Q. For each element x of the array:

- move the window a position to the right
- remove from head of Q any element that is outside of the window
- remove from the tail of q all the elements that are smaller or equal to x.
- insert x at the tail of Q.
- report the head of Q, which is the maximum of the current window.


## Time complexity

The algorithm takes O(n) time to traverse the array.


## Space complexity