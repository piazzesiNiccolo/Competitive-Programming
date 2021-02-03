# Solution

Given an array a[1..n] first we compute the sum **s** of all the elements in the array.

If **s** is an odd number we can already say that the array can not be divided in two parts with equal sum.

If **s** is even, we can observe that our problem is reduced to finding a subarray with sum equal to a specific value, in this case n/2. This problem is solved using a bottom-up dynamic programming approach. We construct a boolean matrix M of size (n+1)*(s/2+1) and we fill it in the following way:

- M[i][0] = *True* for 0 <= i <= n
- M[0][j] = *False* for 1 <= j <= s/2
- M[i][j] = 

    M[i-1][j]   *if a[i-1] > j**
            
    M[i-1][j] **or** M[i-1][j-a[i-1]] *otherwise**
    
    (the element checked is the one in position i-1 because the first row of the matrix corresponds to the empty subarray)

The final answer is the element M[n][s/2].
## Time complexity

O(n*s) where n is the array length and s the total sum of the elements

## Space complexity

O(n*s)