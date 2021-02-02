#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


struct query
{
    int64_t l, r;
    int i;
    query(int64_t l, int64_t r, int i) : l(l), r(r), i(i) {};
};

void powerful(const vector<int64_t> &v, vector<query> &queries)
{
    const int64_t block = (int64_t)sqrt(v.size());
    int64_t freq[10000001];
    vector<int64_t> res(queries.size());
    sort(queries.begin(), queries.end(),[&block](const query &q1, const query &q2){
        return q1.l/block != q2.l/block ? q1.l / block < q2.l/block : q1.r < q2.r;
    });
    int64_t currL = 0, currR=-1,sum = 0;
    for(int i = 0; i < queries.size(); i++){
        int64_t l = queries[i].l;
        int64_t r = queries[i].r;
        while (currL < l)
        {
            sum -= (2*(freq[v[currL]]) - 1)*v[currL];
            freq[v[currL]]--;
            currL++;
        }
        while (currL > l)
        {
            currL--;
            sum += (2*(freq[v[currL]]) + 1)*v[currL];
            freq[v[currL]]++;
            
        }
        while (currR < r)
        {
            currR++;
            sum += (2*(freq[v[currR]]) + 1)*v[currR];
            freq[v[currR]]++;
            
        }
        
        while (currR > r)
        {
            sum -= (2*(freq[v[currR]]) - 1)*v[currR];
            freq[v[currR]]--;
            currR--;
        }
        res[queries[i].i] = sum;
    }
    for(auto &r:res) cout << r << endl;
}
int main()
{
    int n, t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;

    vector<int64_t> v(n);
    for (int i = 0; i < n; i++)
    {
        
        cin >> v[i];
    }
    vector<query> queries;
    queries.reserve(t);
    int64_t l, r;
    for(int i = 0; i < t; i++) {
        cin >> l >> r;
        queries.emplace_back(l-1, r-1, i);
    }
    powerful(v, queries);
    
    
    return 0;
}