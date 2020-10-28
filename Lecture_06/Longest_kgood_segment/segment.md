# Solution

The algorithm uses a two pointers trick: we keep a pointer l for the starting point  of the current longest k good segment and a pointer r for the ending point.

At each iteration we check if the number of distinct elements in the segment is <= k:
- if it is  we increase r and we check if we have to update the starting/end points of the maximum length segment
- otherwise we increase l

## Time complexity

O(n) to scan the array

## Space complexity

O(n) to store the unique values in the current segment