class Solution
{
	public:
		int editDistance(string s, string t)
		{
		    int n = s.size() + 1, m = t.size() + 1;
		    int editDistance[n][m];
		    
		    for(int i = 0;i<n;i++){
		        editDistance[i][0] = i;
		    }
		    
		    for(int j = 0;j<m;j++){
		        editDistance[0][j] = j;
		    }
		    for(int i = 1; i<n;i++){
		        for(int j = 1; j<m;j++){
		           if(s[i-1] == t[j-1]){
		               editDistance[i][j] = editDistance[i-1][j-1];
		           } else{
		               editDistance[i][j] = 1 + min({editDistance[i-1][j],editDistance[i][j-1],editDistance[i-1][j-1]});
		           }
		        }
		        
		    }
		  return editDistance[n-1][m-1];      
		}
};