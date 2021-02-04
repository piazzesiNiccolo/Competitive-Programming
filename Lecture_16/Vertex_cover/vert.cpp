#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    size_t n;
    cin >> n;
    vector<size_t> dp[2];
    vector<vector<size_t>> tree;
    tree = vector<vector<size_t>>(n);
    dp[0] = vector<size_t>(n, 0);
    dp[1] = vector<size_t>(n, 0);
    size_t u, v;
    for (size_t i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    function<void(size_t, size_t)> vertex_cover = [&](size_t node, size_t parent) {
        for (auto child : tree[node])
        {
            if (child != parent)
            {
                vertex_cover(child, node);
                dp[0][node] += dp[1][child];
                dp[1][node] += min(dp[0][child], dp[1][child]);
            }
        }

        dp[1][node]++;
    };

    vertex_cover(0, -1);

    cout << min(dp[0][0], dp[1][0]) << endl;
    return 0;
}