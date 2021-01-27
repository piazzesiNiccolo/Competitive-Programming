#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;

struct query{
    int64_t v, x, i;

    query(int64_t v, int64_t x, int64_t i) : v(v), x(x), i(i){}
};

void tree_and_queries(vector<vector<int64_t>> &tree, vector<int64_t> &colours, vector<query> &q){
    vector<int64_t> flat;
    flat.reserve(tree.size());
    vector<pair<int64_t, int64_t>> range(tree.size());


    function<void(int64_t, int64_t)> dfs = [&](int64_t n, int64_t p){
        int64_t start = flat.size();
        flat.push_back(colours[n]);
        for(auto u: tree[n]) if(u != p) dfs(u, n);
        int64_t end = flat.size() - 1;
        range[n] = make_pair(start, end);
    };

    dfs(0,-1);

    const int64_t BLOCK = (int64_t)sqrt(flat.size());

    sort(q.begin(), q.end(), [&](const query &q1, const query &q2){
        return make_pair(range[q1.v].first/BLOCK, range[q1.v].second) < make_pair(range[q2.v].first/BLOCK, range[q2.v].second);
    });
    vector<int64_t> freq(1e5+1,0), morethanX(1e5+1,0);
    int64_t currL = 0, currR = -1;

    auto add = [&](int64_t pos){
        freq[flat[pos]]++;
        morethanX[freq[flat[pos]]]++;
    };
    
    auto remove = [&](int64_t pos){
       
        morethanX[freq[flat[pos]]]--;
        freq[flat[pos]]--;

    };
    int64_t l, r;
    vector<int64_t> sol(q.size());
    
    for(int64_t i = 0; i < q.size(); i++){
        l = range[q[i].v].first;
        r = range[q[i].v].second;
        while(currL < l) remove(currL++);
        while(currL > l) add(--currL);
        while(currR < r) add(++currR);
        while(currR > r) remove(currR--);
        sol[q[i].i] = q[i].x >= colours.size() ? 0 : morethanX[q[i].x];
    }
    for(auto s: sol) cout << s << endl;

}
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n, m;
    cin >> n >> m;
    vector<int64_t> colours(n);
    for(int64_t i = 0;  i < n; i++) cin >> colours[i];
    vector<vector<int64_t>> tree;
    tree.resize(n);
    int64_t p, c;
    for (int64_t i = 0; i < n-1; i++)
    {
        cin >> p >> c;
        tree[--p].push_back(--c);
        tree[c].push_back(p);
        
    }
    
    vector<query> queries;
    int64_t v, x;
    for(int64_t i = 0; i < m; i++){
        cin >> v >> x;
        queries.emplace_back(--v, x, i);
    }

    tree_and_queries(tree, colours, queries);
    return 0;

}