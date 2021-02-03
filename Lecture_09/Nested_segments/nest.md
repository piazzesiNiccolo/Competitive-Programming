# Solution
First map the segments to the range [1, 2n] and sort them by their starting point. Now we use a BIT and a sweeping line algorithm. First we scan each segment (l<sub>i</sub>,r<sub>i</sub>) and add 1 to position r<sub>i</sub>. Now we scan the segments again. When we process the segment (l<sub>i</sub>, r<sub>i</sub>) we can observe that the segments already processed are only the ones that start before the current one(because they are sorted). The answer that we want is the number of these segments that also ends before (l<sub>i</sub>, r<sub>i</sub>) and this is computed  with a query sum(r<sub>i</sub>) on the BIT. After computing the solution for the current segment we subtract 1 to position r<sub>i</sub>.

## Time complexity

Sorting the segments takes O(nlogn). Each of the n sum query takes O(log n) so the total time complexity is O(nlogn).

## Space complexity

We use an auxiliary array a[1..2n]  that is needed in the remapping phase. Given the segment (l<sub>i</sub>, r<sub>i</sub>) we  remap the two values to their rank in the sorted array. THe BIT does not take any extra space so the total space complexity is O(n).