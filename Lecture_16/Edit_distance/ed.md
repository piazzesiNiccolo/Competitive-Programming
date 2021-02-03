# Solution

Dynamic programming with a bottom-up approach. Given the two strings s1 and s2 we fill a matrix M of size (|s1|)*(|s2|)
in the following way:

- M[i][0] = i for 0 <= i <= |s1|
- M[0][j] = j for 0 <= j <= |s2|
- M[i][j] = 

    M[i-1][j-1] *if s1[i-1] == s2[j-1]*
    1 + min(M[i-1][j-1],M[i][j-1],M[i-1][j]) *otherwhise*
    
    (the positions are i-1 and j-1 because the first row and the first colum corresponds to the substring of length 0 of s1 and the substring of length 0 of s2 respectively)

## Time complexity

O(|s1|*|s2|)

## Space complexity



O(|s1|*|s2|)
        