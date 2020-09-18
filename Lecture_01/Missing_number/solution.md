# Solution

First compute the total sum from 1 to N using gauss formula: $\sum_{i=1}^ni = \frac{n(n+1)}{2} $. After that sum the input numbers and subtract this value from the toal sum. The result will be the missing number

## Time complexity

The total sum is computed in O(1) time. To sum the input numbers you need to access them one by one and this takes O(n) time. The subtraction takes O(1). In total the algorithm runs in O(n) time. 

## Space complexity

The algorithm does not use additional space, therefore the space complexity is O(1).
