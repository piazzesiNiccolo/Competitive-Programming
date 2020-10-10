# Solution
sort the heights of the towers and then scan the sequence left to right.

- If the current length is the same as the last iteration increment the current height by one and check if  the height is the new maximum
- if we find a different length increase the counter of towers by one  and reset the current height to one

## Time complexity

O(n logn) to sort the array

O(n) to scan the array

O(n logn) + O(n) =  O(n logn) 

## Space complexity 

O(1)