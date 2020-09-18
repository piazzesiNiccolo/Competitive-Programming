# Solution

We can solve this problem by simply using Kadane's algorithm. Keep two variables: max to store the current maximum sum and  sum to store the current sum. Scan the array from left to right. For each element if sum is > 0  add the element  to it otherwise assign the element to the sum variable itself. If sum is greather than max, update max to its value.

## Time complexity

O(n) to scan the array.

## Space complexity

O(1)
