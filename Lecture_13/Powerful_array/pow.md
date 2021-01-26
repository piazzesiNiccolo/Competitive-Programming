# Solution

We just use [Mo's algorithm](https://blog.anudeep2011.com/mos-algorithm/) and modify the add and remove functions to compute what we want.


## Time complexity

O((n+q)sqrt(n))

## Space complexity

Given the input array A we need O(max(A)) extra space to store the frequency of each element. This can be improved to O(n), for example by storing the frequency  of each distinct element. This could be done by remapping the values to their rank in the sorted array and assigning the same rank to equal values ( or by using an hashmap as lookup table). I didn't see major improvements when comparing the two solutions, so i decided to go with the simplest one.