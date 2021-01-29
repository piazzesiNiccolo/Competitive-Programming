#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <math.h>
using namespace std;

/*NOTE: on codeforces if i used the normal g++17 compiler the execution went 
over the time limit, using the 64 bit compiler instead made the program execute  faster(around 3500 ms)
*/

void powerful(const vector<int> &v, vector<tuple<int, int, int>> &queries)
{
    const int BLOCK_SIZE = sqrt(v.size());
    vector<int64_t> freq(1000000);
    vector<int64_t> results(queries.size());
    auto compare = [BLOCK_SIZE](const tuple<int, int, int> &q1, const tuple<int, int, int> &q2) {
        return get<0>(q1) / BLOCK_SIZE !=  get<0>(q2) / BLOCK_SIZE ? get<0>(q1) / BLOCK_SIZE < get<0>(q2) / BLOCK_SIZE:
                                                                    get<1>(q1) < get<1>(q2);
    };

    sort(queries.begin(), queries.end(), compare);
    int currL = 0, currR = -1, l, r;
   
    int64_t sum = 0;
    function<void(int)> add = [&](int i){
         
        
        sum += (2LL * freq[v[i]] + 1)*v[i];
        freq[v[i]]++;

    };

    function<void(int)> remove = [&](int i){
        sum -= (2LL * freq[v[i]] - 1)*v[i];
        freq[v[i]]--;

    };
    for (int i = 0; i < queries.size(); i++)
    {
        
        
        l = get<0>(queries[i]);
        r = get<1>(queries[i]);
        while (currL < l)
        {   
            remove(currL++);
        }
        
        while (currL > l)
        {
           add(--currL);
            
        }
        while (currR < r)
        {
           add(++currR);
            
        }
        while (currR > r)
        {
            remove(currR--);
        }
        results[get<2>(queries[i])] = sum;
    }

    for (auto const& r: results)
    {
            cout << r << endl; 
    }
}
int main()
{
    int n, t;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;

    vector<int> v(n);
    for (size_t i = 0; i < n; i++)
    {
        
        cin >> v[i];
    }
    vector<tuple<int, int, int>> queries(t);
    int l, r;
    for(int i = 0; i < t; i++) {
        cin >> l >> r;
        queries[i] =  make_tuple(l-1, r-1, i);
    }
    powerful(v, queries);
    
    
    return 0;
}