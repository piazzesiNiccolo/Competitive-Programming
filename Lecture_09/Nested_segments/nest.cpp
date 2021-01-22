 #include <iostream>
 #include <vector>
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
         //start from one to not loop indefinitely
        for(idx++; idx <= elems.size(); idx += idx & -idx){
            elems[idx] += val;
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<pair<pair<int, int>,int>> segments;
    Femwick_Tree tree(n);
    
        int l, r;
    for (int i = 0; i < n; i++)
    {
     cin >> l >> r;
     segments.emplace_back(make_pair(l, r), i);   
    }

    
    sort(segments.begin(), segments.end(),
        [](auto p1, auto p2){return p1.first.second < p2.first.second;});
    
    for(int i = 0; i < n; i++){segments[i].first.second = i;}

    sort(segments.begin(), segments.end(),
        [](auto p1, auto p2){return p1.first.first < p2.first.first;});
    
    vector<int64_t> sol(n);
    for(int i = n-1;i >= 0; i--){
        sol[segments[i].second] = tree.sum(segments[i].first.second);
        tree.add(segments[i].first.second, 1);
    }
    
    for(auto s: sol) cout << s << endl; 
}