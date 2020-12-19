#include <iostream>
#include <set>
using namespace std;
struct frog
{
    int position;
    int tongue_length;
    frog(int position, int tongue_length) : position(position), tongue_length(tongue_length) {}
};

bool operator<(const frog &x, const frog &y)
{
    return x.position < y.position;
}
struct mosquito
{
    int position;
    int size;
    mosquito(int position, int size) : position(position), size(size) {}
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, m;
    set<frog> frogs;
    set<mosquito> uneaten;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, t;
        cin >> x >> t;
        frogs.emplace(x, t);
    }

    

    return 0;
}
