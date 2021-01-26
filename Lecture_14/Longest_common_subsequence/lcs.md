# Solution

We use dynamic programming with a bottom-up approach. Given the two string s1 and s2 we build the matrix M of size (|s1|+1)*(|s2|+1).
At position M[i,j] the matrix store the longest common subsequence between the prefixes s1[1,i] and s2[1,j].
To compute the value M[i,j] let's assume that we already computed M[i-1][j], M[i][j-1] and M[i-1,j-1]:

-if s1[i] == s2[j], we can extend the current longest common subsequence of s1[1, i] and s2[1, j] by one character so M[i][j] = 1 + M[i-1][j-1]

-if s1[i] != s2[j], we take the maximum between M[i-1][j], M[i][j-1] and M[i-1,j-1]

To actually fill the matrix we can observe that we have two trivial cases when we take 0 characters from s1 or s2.
In this situation we have m[0][j] = 0 and M[i][0] for any i and j.

The final solution will be the value M[|s1|][|s2|].

## Time complexity

O(|s1|*|s2|)

## Space complexity

O(|s1|*|s2|)

