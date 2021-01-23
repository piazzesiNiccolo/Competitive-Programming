# Solution

We reuse [the solution used for normal range minimum query](https://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/). Just keep a segment tree updated with lazy propagation with the following modification:

- if we have a min query **(l, r)** with l > r we simply return the minimum between two queries **(0, r)** and **(l, n-1)**.
- if we have an update  **(l, r, k)** with l > r we execute the two updates **(0, r, k)** and **(l, n-1, k)**.

## Time complexity

Tree construction takes O(n). Each query takes O(log n). We can upperbound the total complexity at O(n logn).

## Space complexity

O(n) to store the tree.
