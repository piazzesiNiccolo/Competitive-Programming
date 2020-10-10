# Solution
We can modify MergeSort to count inversions. At each recursive step, we count the number of inversions in the left subarray, the number of inversions in the right subarray and sum them together. Now we have to add the number of inversions given by the merge step. This can be done by modifying the merge procedure. If i is used for indexing the left subarray and j for the right subarray,if at any point v[i] > v[j] we have to add m-i inversions, where m is the rightmost index of the left subarray. This is explained by observing that the two subarrays are sorted: any element on the right of v[i] will also be bigger than v[j], causing an inversion.

## Time complexity
The algorithm runs in O(nlogn), the same complexity as mergesort .

## Space complexity
