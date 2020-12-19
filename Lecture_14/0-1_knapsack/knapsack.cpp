#include<iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,W;
    cin >> W >> n;
    vector<int> values, weights;
    values.reserve(n);
    weights.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int p,v;
        cin >> p >> v;
        values.push_back(v);
        weights.push_back(p);
    }
    int sol[n+1][W+1];
    for (int i = 0; i <=n; i++)
    {
        sol[i][0] = 0;
    }
    for (int j = 0; j <=W; j++)
    {
        sol[0][j] = 0;
    }
    
    for (int i = 1; i <=n; i++)
    {
        for (int w = 0; w <=W; w++)
        {
            if (weights.at(i-1) <= w)
            {
                sol[i][w]= max(sol[i-1][w-weights.at(i-1)] + values.at(i-1),sol[i-1][w]);
            } else{
                sol[i][w] = sol[i-1][w];
            }
            
        }
        
    }
    
    cout << sol[n][W];


    return 0;
}
