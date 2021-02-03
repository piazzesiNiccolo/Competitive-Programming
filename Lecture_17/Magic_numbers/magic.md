# Solution

Simple greedy approach. Scan the string representing the number and at each step, check if we find one of the wanted substring. If we find one jump by a number of character equal to the length of the substring. The substring are checked in decreasing order of their length. If we don't find any of the substring the number is not a magic number and we stop iterating. The answer is yes only if we arrive at the end of the string.

## Time complexity

THe worst case is when we have a magic number. Scanning the whole string takes O(n).

## Space complexity 
O(1)
