# Solution

We can compute the highest bars in linear time using two auxiliary arrays left_max and right_max. 
First scan the array V from left to right while keeping a variable max that stores the highest bar until that point.
The highest bar to the left of an element in position i will be max(max, V[i]). Store this value inside left_max[i].
To find the highest bar to the right repeat the same process with two main differences: scan the array from right to left and store max inside right_max[i]. Now scan the array one last time and compute the total rain trapped in the following way: for each element V[i] add min(left_max[i], right_max[i]) - V[i] to the total.

## Time complexity

Scanning the array takes linear time. Since the algorithm scans it a costant amount of times, time complexity is O(n).

## Space Complexity

The algorithm  needs O(n) space to store left_max and right_max. 