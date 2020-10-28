#include <iostream>
#include <set>

struct frog
{
    int position;
    int tongue_length;
    frog(int position, int tongue_length) : position(position), tongue_length(tongue_length) {}
};

struct mosquito
{
    int position;
    int size;
    mosquito(int position, int size) : position(position), size(size) {}
};

int main(int argc, char const *argv[])
{
    int n,m;
    std::set<frog> frogs;
    std::set<mosquito> uneaten;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x,t;
        std::cin >> x >> t;
        frogs.emplace(x,t);
       
    }
    
    for (int i = 0; i < m; i++)
    {
        int p,b;
        std::
    }
    
    return 0;
}
