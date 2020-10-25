# Solution

First we scan the array and find the longest jump between two consecutive rungs. This is already a working solution for every case except the one in which we have multiple jumps of maximum length. In this situation the strength gets decreased after the first one, making it impossible to do the next longest jump. The correct value of this case is the longest jump increased by one.  

To solve this problem in our algorithm we assign the found maximum <b>final_value</b> to a temporary variable <b>temp_strength</b> and rescan the array; when we find the first max jump we decrease temp_strength. If we find a jump longer than temp_strength we increment by one final_value and this is the correct strenght value.

## Time complexity

O(n) to scan the array 

## Space complexity

O(1)