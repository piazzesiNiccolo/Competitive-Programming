 #include <iostream>
 #include <vector>
 #include <tuple>
 #include <algorithm>

 using namespace std;
 class Femwick_Tree{
    vector<int64_t> elems;
    public:
    
    Femwick_Tree(int n) : elems(n+1, 0) {}

    int64_t sum(int idx){
        
        int64_t sum = 0;
        for(idx++; idx > 0; idx -= idx & -idx){
            sum += elems[idx];
        }
        return sum;
    }
    
    void add(int idx, int64_t val){
        for(idx++; idx <= elems.size(); idx += idx & -idx){
            elems[idx] += val;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> segments(n);
    vector<int> elems;
    
    
    int l, r;
    for (int i = 0; i < n; i++)
    {
     cin >> l >> r;
     segments[i] = make_tuple(l, r, i);
     elems.push_back(l);
     elems.push_back(r);   
    }
    sort(elems.begin(), elems.end());
    
    for (int i = 0; i < n; i++)
    {
        get<0>(segments[i]) = lower_bound(elems.begin(), elems.end(), get<0>(segments[i])) - elems.begin();
        get<1>(segments[i]) = lower_bound(elems.begin(), elems.end(), get<1>(segments[i])) - elems.begin();
        
    }
    sort(segments.begin(), segments.end(),[](const tuple<int, int, int> & s1,  const tuple<int, int, int> & s2){
        return get<0>(s1) < get<0>(s2);
    });
    Femwick_Tree tree(elems.size());
    for(int i = 0; i < n; i++){
        tree.add(get<1>(segments[i]), 1);
    }
    vector<int> sol(n);
    for(int i = 0; i < n; i++){
        sol[get<2>(segments[i])] = tree.sum(get<1>(segments[i])) - 1;
        tree.add(get<1>(segments[i]), -1);
    }
    for(auto s: sol) cout << s << endl; 
}