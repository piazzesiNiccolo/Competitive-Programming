#include <iostream>
using namespace std;
bool isMagic(string n){
    bool r = true;
    int i = 0;
    while (r && i < n.size())
    {
        if (n.substr(i,3) == "144")
        {
            i += 3;
        }
        else if (n.substr(i,2) == "14")
        {
            i += 2;
        }
        else if (n.substr(i, 1) == "1")
        {
            i+=1;
        } else {
            r = false;
        }
        
    }
    
    return r;
}
int main(){
    string n;
    cin >> n;
    string res = isMagic(n) ? "YES" : "NO";
    cout << res << endl;
}