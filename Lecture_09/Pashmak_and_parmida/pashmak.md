# Solution

We use a Binary Indexed Tree B and two auxiliary vectors counter and suffix_counter.

We remap each element in the vector v to their rank in the sorted array in order to have values in the range [1..n].

We then scan the vector from right the left and fill a vector **suffix_counter** such that suffix_counter[i] = f(i, n, v). In the same loop we build the BIT B in order to have B[i] = the number of elements in suffix_counter equal to i. This means that B.sum(k) gives the number of time f(i, n, v[i]) < k.

Now we traverse v from left to right. When we are processing v[i] we can observe that we can easily compute f(1, i, v[i]) by using the counter vector.  If f(1, i, v[i]) = k, we have to count the number of indices j  such that f(j, n, v[i]) and this is B.sum(k-i). To get the actual answer we have to consider only those indices j that are bigger than i, so we have to remove the values suffix_counter[1..i]. This is done step by step  by subtracting 1 from B[suffix_counter[i]].

## Time complexity

O(nlogn)

## Space complexity

O(n)