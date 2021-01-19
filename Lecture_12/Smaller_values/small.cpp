#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct query{
    int l, r;
    int64_t x;

    query(int l, int r, int64_t x) : l(l), r(r), x(x){}
};

void smaller_values(const vector<int64_t> &v,vector<pair<query, int>> &q){
    const int BLOCK = sqrt(v.size());
    vector<int64_t> results(q.size(), 0);
    auto compare = [BLOCK](const pair<query, int> &q1, const pair<query, int> &q2) {
        return make_pair(q1.first.l / BLOCK, q1.first.r) < make_pair(q2.first.l / BLOCK, q2.first.r);
    };
    sort(q.begin(), q.end(), compare);
    int currL = 0, currR=-1, l, r;
    int64_t sum = 0,k;
    for (int i = 0; i < q.size(); i++)
    {
        l = q[i].first.l, r = q[i].first.r;
        k = q[i].first.x;
        while (currL < l)
        {
            if(v[currL] <= k){
                sum--;
            }
            currL++;
        }
        while (currL > l)
        {
            currL--;
            if(v[currL] <= k){
                sum++;
            }
            
        }
        while (currR < r)
        {
            currR++;
            if(v[currR] <= k){
                sum++;
            }
            
        }while (currR > r)
        {
            if(v[currR] <= k){
                sum--;
            }
            currR--;
        }
        results[q[i].second] = sum;
    }
    for (auto r : results)
    {
        cout << r << endl;
    }
    

}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int64_t> values(n);
    vector<pair<query, int>> queries(m);
    for(int i = 0; i< n; i++){
        cin >> values[i];
    }
    int l, r;
    int64_t x;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r >> x;
        query q(l, r, x);
        queries.emplace_back( q, i);
    }
    smaller_values(values, queries);
    return 0;
}