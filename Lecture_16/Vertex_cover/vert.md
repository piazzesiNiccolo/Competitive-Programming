# Solution

Dynamic programming with a top-down recursive approach.
We use a memoization matrix M of size(2)*(n) where n is the number of nodes.
For each node i the entry M[0][i] stores the minimum vertex cover not covering node i and entry M[1][i] considers the opposite case.

We visit the tree with a DFS, at each node i we can decide to cover it or not:

- *If* we don't cover i, we must cover all of his children. Given the generic children j we add M[1][j] to M[0][i].
- *Else* we can choose to cover them or not. The minimum between these two cases is the actual value. Given the generic children j we add min(M[0][j], M[1][j]) to M[1][i].

The final answer will be min(M[0][0],M[1][0]) where 0 is the root node.

## Time complexity

We visit each node only once so the total complexity is O(n).

## Space complexity

O(n) to store the answer for each node.
