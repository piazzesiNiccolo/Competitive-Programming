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

void map_to_rank(vector<int64_t> &v, vector<int64_t> &aux){
    sort(aux.begin(), aux.end());
    for(int i = 0; i < v.size(); i++){
        //the first element not less than v[i] in the sorted array is the first occurence of v[i].
        //we take this value since we want same values to have the same rank
        v[i] = lower_bound(aux.begin(),aux.end(),v[i]) - aux.begin();  //lower bound returns an iterator. To get the rank we simply compute the distance
        //from the start of the sorted array
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int64_t> v(n), aux(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        aux[i] = v[i];
    }
    
    map_to_rank(v, aux);
    vector<int> suffix_counter(n+1, 0),  counter(n+1, 0);
    Femwick_Tree tree(n);
    for (int i = n - 1; i >= 0; i--)
    {
        counter[v[i]]++;
        suffix_counter[i] = counter[v[i]];
        tree.add(counter[v[i]], 1);

    }
    fill(counter.begin(), counter.end(), 0);
    int64_t sol = 0;
    for (int i = 0; i < n; i++)
    {
        tree.add(suffix_counter[i], -1);
        counter[v[i]]++;
        sol += tree.sum(counter[v[i]] - 1);

        
    }
    
    cout << sol << endl;
    
}