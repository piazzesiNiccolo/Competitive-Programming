
int lcs(int x, int y, string s1, string s2){
    
    int n = x+1, m = y+1;
    int lcs[n][m];
    for(int i = 0; i < n; i++){lcs[i][0] = 0;}
    for(int j = 0; j < m; j++){lcs[0][j] = 0;}
    
    for(int i = 1;i < n; i++){
        for(int j = 1 ; j<m; j++){
            if(s1[i-1] == s2[j-1]){
                lcs[i][j] = 1 + lcs[i-1][j-1];
            } else{
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    return lcs[n-1][m-1];
}