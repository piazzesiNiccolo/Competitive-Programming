# Solution

We use a Binary Indexed Tree B. For each update(l,r,val) we add v to B[l] and subtract v from B[r+1]. The query i will return the prefix sum up to B[i].

## Time complexity

if we call S the sum of the updates and the queries in the input the time will be O(S*logn) where n is the number of the elements in the array.

## Space complexity

The BIT is an implicit data strcture so we require O(1) extra space other than the input array.