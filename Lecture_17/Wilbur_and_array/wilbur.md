# Solution

The minimum number of operations is equal to the sum of the absolute values of differences between consecutive elements.

Given an array V[1..n] we have sol = v<sub>1</sub> + sum(|v<sub>i</sub> - v<sub>i-1</sub>|) for 2 <= i <=n

## Time complexity

O(n) to scan the array

## Space complexity

O(1)