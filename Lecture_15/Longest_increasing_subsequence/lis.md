# Solution

We exploit the concept of dominant positions. Given positions i and j we say that i dominates j if LIS(i) > LIS(j) and i < j where LIS(i) is the longest increasing subsequence up to position i. Our answer is the number of dominant positions and we can store them in a set. 

Scan the array and update the set so that it keeps only dominant positions. The size of the set at the end is our answer.

## Time complexity

O(nlogn) if we use a BST to implement the set.

## Space complexity

O(n) to store the set.