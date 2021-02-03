# Solution

Sort the meetings by their end time and then scan them: if a meeting does not overlap with the previous one, add 1 to the result.

## Time complexity

O(nlogn) to sort the meetings + O(n) to scan them = O(nlogn).

## Space complexity
O(1).