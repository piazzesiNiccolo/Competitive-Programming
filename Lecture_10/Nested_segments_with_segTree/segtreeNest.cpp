#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>

#define left(i) (2*i+1)
#define right(i) (2*i+2)
using namespace std;

class Seg_Tree{
    int n;
    vector<int64_t> tree, lazy;

public:
    Seg_Tree(int size){
        n = size;
        int s = (int)ceil(log2(size));
        int tree_size = 2*(int)pow(2,s) - 1;
        tree.resize(tree_size,0);
        lazy.resize(tree_size, 0);
        
    }

    void add(int l, int r,int64_t val){
        addUtil(0, n-1,l, r,0, val);
    }

    int64_t sum(int l, int r){
        return sumUtil( 0,n-1,l, r, 0);
    }

private:

   

    void lazyUpdate(int pos, int start, int end)
    {
        if (lazy[pos] != 0)
        {
            tree[pos] += lazy[pos];
            if (start != end)
            {
                lazy[left(pos)] += lazy[pos];
                lazy[right(pos)] += lazy[pos];
            }
            lazy[pos] = 0;
        }
    }

    void addUtil( int start, int end, int low, int high,int pos, int64_t val){
        lazyUpdate(pos, start, end);
        if (start > high || end < low)
            return;

        if (start >= low && end <= high)
        {
            tree[pos] += val;
            if (start != end)
            {
                lazy[left(pos)] += val;
                lazy[right(pos)] += val;
            }
        }
        else
        {
            int mid = (start + end) / 2;
            addUtil(start, mid, low, high, left(pos), val);
            addUtil(mid + 1, end, low, high,right(pos), val);
            tree[pos] += val;
        }
    }

    int64_t sumUtil(int start, int end, int low, int high, int pos){
        lazyUpdate(pos, start, end);
        if (start >= low && end <= high)
        {
            return tree[pos]; //total overlap
        }
        else if (start > high || start > end || end < low)
        {
            return 0; // no overlap
        }
        int mid = (start + end) / 2;
        return sumUtil(start, mid, low, high,left(pos)) + sumUtil(mid + 1, end, low, high, right(pos));
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<tuple<int64_t, int64_t, int>> segments(n);
    vector<int64_t> elems;
    
    
    int64_t l, r;
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
    Seg_Tree tree(elems.size());
    for(int i = 0; i < n; i++){
        tree.add(get<1>(segments[i]),get<1>(segments[i]), 1);
    }
    vector<int64_t> sol(n);
    for(int i = 0; i < n; i++){
        sol[get<2>(segments[i])] = tree.sum(get<0>(segments[i]), get<1>(segments[i])) - 1;
        tree.add(get<1>(segments[i]), get<1>(segments[i]), -1);
    }
    for(auto s: sol) cout << s << endl; 
}