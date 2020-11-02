#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int64_t> elems;
    elems.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int64_t e;
        cin >> e;
        elems.push_back(e);
    }
    vector<int> frequencies(n+1);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        frequencies[l - 1] += 1;
        frequencies[r] -= 1;
    }
    partial_sum(frequencies.begin(),frequencies.end(),frequencies.begin());
    sort(elems.begin(),elems.end());
    sort(frequencies.begin(),frequencies.end() - 1);
    int64_t res = 0;
    for (int i = 0; i < n; i++)
    {
        res += frequencies[i]*elems[i];
    }
    cout << res;
    return 0;
}
