#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int64_t> end(n);
    int64_t ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }
    ans = abs(end[0]);
    for (int i = 1; i < n; i++)
    {
        
        ans += abs(end[i] - end[i - 1]);
        
    }
    cout << ans << endl;
}