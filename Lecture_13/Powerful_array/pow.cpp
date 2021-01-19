#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <math.h>
using namespace std;

vector<int64_t> powerful(const vector<int64_t> &v, vector<pair<pair<int, int>, int>> &queries)
{
    const int BLOCK_SIZE = sqrt(v.size());
    vector<int64_t> freq(1e6 + 1, 0);
    vector<int64_t> results(queries.size(), 0);
    auto compare = [BLOCK_SIZE](const pair<pair<int, int>, int> &q1, const pair<pair<int, int>, int> &q2) {
        return make_pair(q1.first.first / BLOCK_SIZE, q1.first.second) < make_pair(q2.first.first / BLOCK_SIZE, q2.first.second);
    };

    sort(queries.begin(), queries.end(), compare);
    int currL = 0, currR = -1, l, r;
    int64_t sum = 0;
    for (int i = 0; i < queries.size(); i++)
    {
        
        
        l = queries[i].first.first;
        r = queries[i].first.second;
        while (currL < l)
        {   int64_t old = freq[v[currL]];
            freq[v[currL]]--;
            int64_t cur = freq[v[currL]];
            
            sum  = sum - (old*old - cur*cur) * v[currL];
            ++currL;
        }
        
        while (currL > l)
        {
            currL--;
            int64_t old = freq[v[currL]];
            freq[v[currL]]++;
            int64_t cur = freq[v[currL]];
            
            sum  = sum + (cur*cur - old*old) * v[currL];
            
        }
        while (currR < r)
        {
            currR++;
            int64_t old = freq[v[currR]];
            freq[v[currR]]++;
            int64_t cur = freq[v[currR]];
            
            sum  = sum + (cur*cur - old*old) * v[currR];
            
        }
        while (currR > r)
        {
            int64_t old = freq[v[currR]];
            freq[v[currR]]--;
            int64_t cur = freq[v[currR]];
            
            sum  = sum - (old*old - cur*cur) * v[currR];
            --currR;
        }
        results[queries[i].second] = sum;
    }

    return results;
}
int main()
{
    int n, t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;

    vector<int64_t> v;
    v.reserve(n);
    for (size_t i = 0; i < n; i++)
    {
        int64_t e;
        cin >> e;
        v.push_back(e);
    }
    vector<pair<pair<int, int>, int>> queries;
    int l, r;
    for(int i = 0; i < t; i++) {
        cin >> l >> r;
        queries.emplace_back(make_pair(l-1, r-1), i);
    }
    for (auto const& r: powerful(v, queries))
    {
            printf("%I64d\n",r);
    }
    
    return 0;
}