#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct team
{
    int first;
    int second;
    int strength;
    team(int f, int s, int st) : first(f),second(s),strength(st){}
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    vector<team> teams;
    cin >> n;
    for (int i = 0; i < 2*n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int strength;
            cin >> strength;
            teams.emplace_back(i,j,strength);
        }
        
    }
    sort(teams.begin(),teams.end(), [](team const& a, team const& b){return a.strength > b.strength;});
    vector<int>  paired(2*n);
    for (struct team e : teams)
    {
        if (paired[e.first] == 0 && paired[e.second] == 0)
        {
            paired[e.first] = e.second + 1;
            paired[e.second] = e.first + 1;
        }
        
        
    }
    
    for (auto p : paired)
    {
        cout << p << " ";
    }
    
    return 0;
}
