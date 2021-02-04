# Solution

### DP solution

Use  an auxiliary array **jumps** which stores the minimum number of jumps to reach each element of the input array a.

When at position i, loop from 0 to i-1 to find the minimum number of jumps needed to reach i. Jumps[i] will be min(jumps[j] + 1) where j represent the generic position between 0 and i-1 such that j + a[j] >= i. The final answer will be jumps[n-1]. This solution has O(n^2) time complexity and O(n) space complexity.

### Linear solution

The DP solution went over the time limit on GeeksForGeeks. The actual solution implemented is described [here](https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/).

## Time complexity
O(n)

## Space complexity

O(1)