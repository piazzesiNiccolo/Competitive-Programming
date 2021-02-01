#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

class RMQSegTree
{
    int N;
    vector<int64_t> tree, lazy;

public:
    RMQSegTree(const std::vector<int64_t> &V)
    {
        N = V.size();
        int x = (int)ceil(log2(N));
        int max_size = 2 * (int)pow(2, x) - 1;
        tree.resize(max_size, 0);
        lazy.resize(max_size, 0);
        build(V, 0, 0, N - 1);
    }

    
    void update(int low, int high, int64_t val)
    {
        if (low > high)
        {
            updUtil(0, N - 1, low, N - 1, 0, val);
            updUtil(0, N - 1, 0, high, 0, val);
        }
        else
        {
            updUtil(0, N - 1, low, high, 0, val);
        }
    }
    int64_t rmq(int l, int r)
    {
        int64_t sol;
        if (l > r)
        {
            sol = min(rmq(0, r), rmq(l, N - 1));
        }
        else
        {
            sol = rmqUtil(0, N - 1, l, r, 0);
        }
        return sol;
    }

private:
    void build(const vector<int64_t> &v, int pos, int low, int high)
    {
        if (low > high)
        {
            return;
        }
        if (low == high)
        {
            tree[pos] = v[low];
            return;
        }
        int mid = (high + low) / 2;
        build(v, 2 * pos + 1, low, mid);
        build(v, 2 * pos + 2, mid + 1, high);
        tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
        return;
    }
    void lazyUpdate(int pos, int start, int end)
    {
        if (lazy[pos] != 0)
        {
            tree[pos] += lazy[pos];
            if (start != end)
            {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }
    }
    void updUtil(int start, int end, int low, int high, int pos, int64_t val)
    {
        lazyUpdate(pos, start, end);
        if (start > high || end < low)
            return;

        if (start >= low && end <= high)
        {
            tree[pos] += val;
            if (start != end)
            {
                lazy[2 * pos + 1] += val;
                lazy[2 * pos + 2] += val;
            }
        }
        else
        {
            int mid = (start + end) / 2;
            updUtil(start, mid, low, high, 2 * pos + 1, val);
            updUtil(mid + 1, end, low, high, 2 * pos + 2, val);
            tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
        }
    }

    int64_t rmqUtil(int start, int end, int low, int high, int pos)
    {
        lazyUpdate(pos, start, end);
        if (start >= low && end <= high)
        {
            return tree[pos]; //total overlap
        }
        else if (start > high || start > end || end < low)
        {
            return (INT64_MAX); // no overlap
        }
        int mid = (start + end) / 2;
        return min(rmqUtil(start, mid, low, high, 2 * pos + 1), rmqUtil(mid + 1, end, low, high, 2 * pos + 2));
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n;
    vector<int64_t> v;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int64_t e;
        cin >> e;
        v.push_back(e);
    }
    cin >> q;

    RMQSegTree t(v);
    string line;
    vector<int64_t> words;
    cin.ignore(256, '\n');
    while (q--)
    {

        getline(cin, line);
        stringstream ss(line);
        int64_t word;
        while (ss >> word)
        {
		
            words.push_back(word);
        }

        if (words.size() == 2)
        {
            cout << t.rmq(words[0], words[1]) << endl;
        }
        else if (words.size() == 3)
        {
            t.update(words[0], words[1], words[2]);
        }
        words.clear();
    }

    return 0;
}
