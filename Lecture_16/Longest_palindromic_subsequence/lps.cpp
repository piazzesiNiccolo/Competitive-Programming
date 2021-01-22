#include <iostream>
#include <algorithm>
using namespace std;

int lps(string s){
    string srev(s);
	reverse(srev.begin(), srev.end());
	int n = s.size();
	int lps[n+1][n+1];
	for(int i = 0; i <= n; i++){lps[i][0] = 0;}
	for(int i = 0; i <= n; i++){lps[0][i] = 0;}
	
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <=n; j++)
	        if(s[i-1] == srev[j-1]){
                lps[i][j] = 1 + lps[i-1][j-1];
            } else{
                lps[i][j] = max(lps[i-1][j],lps[i][j-1]);
            }
	}
return lps[n][n];

}
int main() {
	int t;
	cin >> t;
	string s;
	while(t--){
	    cin >> s;
	    cout << lps(s) << endl;
	    
    	}
	return 0;
}