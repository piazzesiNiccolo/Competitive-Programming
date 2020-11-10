# Solution
We can use an auxiliary array where we keep the leaders found.
Scan the array from right to  the left while keeping track of the maximum until that point. If the current element is greater than the maximum, add it to the leaders. At the end, return the leaders vector  reversed.

## Time complexity
The algorithm scans the array only once, the time complexity is O(n).

## Space complexity
We need O(n) space to store the leaders array.