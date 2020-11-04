# Solution

First we compute the sum **s** of all the elements in the array E. If s is not a multiple of three the final result is 0.
Otherwise, we compute the array **suff**. In position i, suff[i]  will store the number of suffixes of every position after i that sum to s/3. As a last step we compute the prefix sum of E. If E[i] = s/3  we add suff[i+2] to the final result.
## Time complexity

Each step costs O(n) time, so the total complexity is O(n).

## Space complexity

O(n) to store the array suff.