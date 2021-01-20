#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n, las = 1;
    string s;
    cin >> n;
    cin >> s;

    for(int i = 1; i < n; i++){
        if (s[i] != s[i - 1])
        {
            las++;
        }
        
    }
    cout << min(n, las + 2) << endl;

}