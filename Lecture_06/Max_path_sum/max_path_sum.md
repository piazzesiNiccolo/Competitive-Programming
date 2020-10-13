# Solution

We can use recursive tree traversal. For every node X,find the maximum root to leaf sum in left and right subtree. Add these two values with the value in X. If this sum is greater than the  maximum path sum found so far, it becomes the new maximum.

## Time complexity

O(n) to traverse each node of the tree

## Space complexity

O(1)