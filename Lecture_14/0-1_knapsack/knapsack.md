# Solution

We use  weight dynamic programming. Assume that we have n items each with their value v, and a weight limit W. We create a matrix M of size (n+1)*(W+1).

The entry M[i, w] stores the maximum value the knapsack can take with weight limit w (0 <= w <= W) and taking i (0 <= i <= n) items.

How do we fill the matrix? Let's say we want to fill position M[i, w]. We have two options:

- if w<sub>i</sub> > w, M[i, w] = M[i-1, w]. Since w<sub>i</sub> surpass the weight limit  we can't take it, and the maximum value is the same that we computed for the first i-1 items.

- if w<sub>i</sub> <= w, M[i, w] = max(M[i-1]\[w-w<sub>i</sub>\] + v<sub>i</sub>, M[i-1],[w]). When w<sub>i</sub>  doesn't surpass the limit we can choose to add the item i or not. The maximum between the two cases is the value we want.

The final answer will be the value M[n, W].

## Time complexity
O(n*W)

## Space complexity
O(n*W)