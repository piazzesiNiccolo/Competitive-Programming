# Solution

First we find the longest alternating subsequence(**las**) with a greedy approach by counting the number of consecutive values that are different. Next we observe that a flip operation can increasing the length of this subsequence by a exactly 2 if and only if the longest alternating subsequence is smaller than n, where n is the length of the string. So the final answer will be min(n,las+2).

## Time complexity

Finding the longest alternating subsequence takes O(n).

## Space complexity

O(1)