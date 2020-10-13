#include <iostream>
#include <set>
#include <vector>

int main()
{
    int n, k;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::vector<int> v;
    std::cin >> n >> k;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int e;
        std::cin >> e;
        v.push_back(e);
    }
    int l = 0, r = 0, max_l = 0, max_r = 0, uniques = 0;
    std::vector<int> freq(1000001, 0); 
    /* NOTE: i would usually use a multiset to store the unique values, but since the  elements of the input array  on codeforces
    are said to be <= 10^6 i used a vector for major time efficiency
    */

    while (r < n)
    {
        if (uniques <= k)
        {
            if (freq[v[r]] == 0)
            {
                uniques++;
            }
            freq[v[r]]++;
            if (uniques <= k && r - l > max_r - max_l)
            {
                max_l = l;
                max_r = r;
            }
            r++;
        }
        else
        {
            if (freq[v[l]] == 1)
            {
                uniques--;
            }

            freq[v[l]]--;
            l++;
        }
    }
    std::cout << max_l + 1 << " " << max_r + 1;
    return 0;
}
