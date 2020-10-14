#include <iostream>
#include <vector>
#include <algorithm>

bool try_strength(std::vector<int64_t> const &v, int64_t strength)
{
    for (int64_t i = 1; i < v.size(); i++)
    {
        if (v.at(i) - v.at(i - 1) > strength)
        {
            return false;
        }
        else if (v.at(i) - v.at(i - 1) == strength)
        {
            strength--;
        }
    }
    return true;
}

int64_t find_strength(std::vector<int64_t> &v)
{
    int64_t m, l = 1, r = *(v.end() - 1) - *(v.begin() + 1), final_value = 0;

    while (l < r)
    {
        m = (l + r)  / 2;

        if (try_strength(v, m))
        {
            r = m;
            final_value = m;
        }
        else
        {
            l = m+1;
        }
    }

    // if we reach here, then element was
    // not present
    return final_value;
}
int main(int argc, char const *argv[])
{

    int64_t tests;
    std::vector<int64_t> vec;
    std::cin >> tests;
    for (auto i = 0; i < tests; i++)
    {
        int64_t n;
        std::cin >> n;
        vec.reserve(n);
        vec.push_back(0);
        for (auto i = 0; i < n; i++)
        {
            int64_t x;
            std::cin >> x;
            vec.push_back(x);
        }
        std::sort(vec.begin(),vec.end());
        int64_t min_strength = find_strength(vec);
        std::cout << min_strength << std::endl;
        vec.clear();
    }
    return 0;
}