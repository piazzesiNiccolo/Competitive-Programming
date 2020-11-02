#include <iostream>
#include <vector>
using namespace std;

struct femwick_tree
{
    
    vector<int> elems;

    femwick_tree(int size){ elems.assign(size + 1, 0); }

    int query(int b)
    {
        int sum = 0;
        for (; b > 0; b -= (b & (-b)))
        {
            sum += elems.at(b);
        }
        return sum;
    }

    void add(int k, int v)
    {
        for (; k < elems.size(); k += (k & (-k)))
        {
            elems[k] += v;
        }
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n, u;
        cin >> n >> u;
        femwick_tree tree(n);
        int l, r, val;
        for (int i = 0; i < u; i++)
        {
            cin >> l >> r >> val;
            tree.add(l+1, val);
            tree.add(r + 2, -val);
        }
        int q;
        cin >> q;
        for (int j = 0; j < q; j++)
        {
            int k;
            cin >> k;
            cout << tree.query(k+1) << endl;
        }
    }
    return 0;
}
