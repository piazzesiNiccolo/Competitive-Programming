# Solution

Given the array v, and at each step we compute the sum of the longest increasing subsequence and the longest decreasing subsequence up to position i. 

For the longest increasing subsequence we reuse the solution [described here](../Longest_increasing_subsequence/lis.md). 

For the longest decreasing subsequence, we can observe that it corresponds to the longest increasing subsequence sccaning the array from right to left.

The solution will be the maximum value between all the sums computed.

## Time complexity
O(nlogn)

# Space complexity
O(n)