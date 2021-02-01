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
    for(auto &f : frogs) cout << f.eaten_m << " " << f.reach - f.pos << endl;

}
int main(){
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


