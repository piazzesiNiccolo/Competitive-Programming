# Solution

We use Mo's algorithm. Reorder the queries and keep an array of counters c[0..N-1]. Given the query (i, j, X) we add 1 
to each counter c[v[k]]  where v is the input array and  i<= k <= j. The answer for our query will be a prefix sum up to position X on the counters array.

## Time complexity

O((n+m)sqrt(n)logn)

## Space complexity

O(n)