# Solution

Use two Binary Indexed Trees L and R, one to count the number of elements in the prefix of the current element that are smaller and one to count the number of elements in the suffix that are bigger. Now scan the vector v from left to right. The answer will be sum(L[v[i]]*R[v[i]]) for 0 <= i < n where n is the vector length.

## Time complexity

O(nlogn)

## Space complexity

As we know Binary Indexed Trees do not use auxiliary space so the space complexity is O(1).