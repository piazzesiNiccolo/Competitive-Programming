#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int64_t n;
    cin >> n;
    vector<int64_t> elements;
    elements.reserve(n);
    for (int64_t i = 0; i < n; i++)
    {
        int64_t e;
        cin >> e;
        elements.push_back(e);
    }
    int64_t sum = 0;
    for (auto i : elements)
    {
      sum += i;  
    }
    
    if (sum % 3 != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        sum /= 3;
        int64_t temp = 0;
        vector<int64_t> suff(n, 0);
        for (int64_t i = n - 1; i >= 0; i--)
        {
            temp += elements.at(i);
            if (temp == sum)
            {
                suff.at(i) = 1;
            }
        }

        partial_sum(suff.rbegin(), suff.rend(), suff.rbegin());
        int64_t ways = 0;
        temp = 0;
        for (int64_t i = 0; i < n - 2; i++)
        {
            temp += elements.at(i);
            if (temp == sum)
            {
                ways += suff.at(i + 2);
            }
        }
        cout << ways << endl;
    }

    return 0;
}
