# Solution

We can compute the solution by using static prefix sum. Given the string S = S<sub>1</sub>S<sub>2</sub>....S<sub>n</sub>, first create a binary array <b>sol</b>. sol[i] = 1 if and only if S<sub>i</sub> = S<sub>i+1</sub>. Now do a partial sum of sol and store the values produced back in sol. Given the query Q = l,r the answer will be sol[r] - sol[l-1].

## Time Complexity

Creating the binary array and computing the prefix sum takes O(n) time. Answering a single query takes constant time since we only need to do a subtraction. If q is the number of queries, the total complexity will be O(n+q).

## Space Complexity

O(n) to store the binary array.