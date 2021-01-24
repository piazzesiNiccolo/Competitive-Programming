#include <iostream>
#include <vector>

using namespace std;
class femwick_tree{
     vector<size_t> elems;
public:
     femwick_tree(size_t n){
         elems = vector<size_t>(n+1, 0);
     }

     size_t sum(size_t i){
         size_t sum = 0;
         for(i++; i > 0; i-= i & -i){
             sum += elems[i];
         }
         return sum;
     }

     void add(size_t i, size_t val){
         for(i++; i <= elems.size(); i+= i & -i ){
             elems[i] += val;
         }
     }

};

size_t triplets(const vector<size_t> &v){
    size_t total = 0;
    femwick_tree left(v.size()), right(v.size());
    for(size_t i = 0; i < v.size();i++){
        right.add(v[i],1);
    }
    for(size_t i = 0; i < v.size();i++){
        total += left.sum(v[i]-1)*(right.sum(v.size()-1)-right.sum(v[i]));
        left.add(v[i],1);
        right.add(v[i],-1);
    }
    return total;
}
int main(){
    size_t n;
    cin >> n;
    vector<size_t> v(n);

    for (size_t  i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    cout << triplets(v) << endl;
    return 0;
}