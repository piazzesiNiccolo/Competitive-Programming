# Solution

Sort the array positions by their frequency in the queries set and assign the biggest values to the most frequent positions.

To calculate the frequencies we use an array F,initialized with all zeroes. For each query (l, r) we add 1 to F[l] and subtract 1 from F[r+1]. When all queries are read we do a prefix sum of F. Now for each position i F[i] contains the frequency of the position.

## Time complexity

Calculating the frequency of the positions takes O(q + n) where q is the number of queries and n the size of the array.
Sorting takes O(nlogn) time in general.

## Space complexity

O(n) for the array F.