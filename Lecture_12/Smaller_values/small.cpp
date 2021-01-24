#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
using namespace std;

struct query{
    int l, r,i;
    int64_t x;

    query(int l, int r,int i, int64_t x) : l(l), r(r),i(i), x(x){}
};

void smaller_values(const vector<int64_t> &v,vector<query> &q){
    const int BLOCK = sqrt(v.size());
    vector<int64_t> results(q.size(), 0);
    vector<int64_t> smaller(v.size());
    auto compare = [BLOCK](const query &q1, const query &q2) {
        return make_pair(q1.l / BLOCK, q1.r) < make_pair(q2.l / BLOCK, q2.r);
    };
    sort(q.begin(), q.end(), compare);
    int currL = 0, currR=-1, l, r;
    int64_t sum = 0,k;
    for (int i = 0; i < q.size(); i++)
    {
        l = q[i].l, r = q[i].r;
        k = q[i].x;
        while (currL < l)
        {
            smaller[v[currL]]--;
            currL++;
        }
        while (currL > l)
        {
            currL--;
            smaller[v[currL]]++;
            
        }
        while (currR < r)
        {
            currR++;
            smaller[v[currR]]++;
            
        }while (currR > r)
        {
            smaller[v[currR]]--;
            currR--;
        }
        results[q[i].i] = accumulate(smaller.begin(),smaller.begin() + k+1, 0);
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
    vector<query> queries;
    for(int i = 0; i< n; i++){
        cin >> values[i];
    }
    int l, r;
    int64_t x;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r >> x;
        queries.emplace_back(l,r,i,x);
    }
    smaller_values(values, queries);
    return 0;
}