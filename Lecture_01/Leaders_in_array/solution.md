# Solution
We can use an auxiliary array where we keep the leaders found.
Scan the array from right to  the left while keeping track of the maximum until that point. If the current element is greater than the maximum, add it to the leaders. Print leaders from right to left

## Time complexity
The algorithm scans the array only once, the time complexity is O(n).

## Space complexity
We need O(n) space to store the leaders array.