#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
 
struct frog
{
    int64_t pos, reach, i,eaten_m;
 
    frog(int64_t pos, int64_t reach, int64_t i, int64_t eaten_m): pos(pos), reach(reach), i(i), eaten_m(eaten_m){}
};
 
struct mosquito
{
    int64_t land_pos, val;
 
    mosquito(int64_t land_pos,int64_t val) : land_pos(land_pos), val(val){}
};
 
void frogs_and_mosquitoes(vector<frog> frogs, vector<mosquito> mosquitoes){
    map<int64_t, frog> pond;
    multimap<int64_t, int64_t> uneaten;
    
    
    sort(frogs.begin(), frogs.end(), [&](frog &f1, frog &f2){return f1.pos < f2.pos; });
    pond.insert({frogs[0].pos, frogs[0]});
    int64_t curr_end = frogs[0].reach;
    for(int i = 1; i < frogs.size(); i++){
         if(frogs[i].reach > curr_end)
        {
            
            pond.insert({max(curr_end+1, frogs[i].pos), frogs[i]});
            curr_end= frogs[i].reach;
        }
        
    }
    sort(frogs.begin(), frogs.end(),[&](frog &f1, frog &f2){return f1.i < f2.i;});
 
    for( mosquito &m : mosquitoes){
        
        auto f = pond.upper_bound(m.land_pos);
        f = prev(f);
        auto next_m = uneaten.insert({m.land_pos,m.val});
        while (f != pond.end() && next_m != uneaten.end()
                && f->first <= next_m->first && next_m->first <=f->second.reach)
        {
            f->second.reach += next_m->second;
            frogs[f->second.i].reach += next_m->second;
            frogs[f->second.i].eaten_m++;
            next_m = uneaten.erase(next_m);
            
        }
        if (f != pond.end())
        {
            auto curr_reach = f->second.reach;
            for(++f;f !=pond.end() && f->first <= curr_reach;){
                auto frog = f->second;
                f = pond.erase(f);
                if (frog.reach > curr_reach)
                {
                    pond.insert({curr_reach+1,frog});
                    curr_reach = frog.reach;
                }
                
            }
        }
        
        
    }
 
    
    for(auto &f : frogs) cout << f.eaten_m << " " << f.reach - f.pos << endl;
 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<frog> frogs;
    frogs.reserve(n);
    int64_t x, t;
    for(int i = 0; i < n; i++){
        cin >> x >> t;
        frogs.emplace_back(x, x+t,i,0);
    }
    vector<mosquito> mosquitoes;
    mosquitoes.reserve(m);
    for(int i = 0; i < m; i++){
        cin >> x >> t;
        mosquitoes.emplace_back(x,t);
    }
 
    frogs_and_mosquitoes(frogs, mosquitoes);
}