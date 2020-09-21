#include <iostream>
#include <vector>

void show_leaders(std::vector<int> const &vec)
{
    std::vector<int> leaders;
    int n = vec.size();
    leaders.reserve(n);
    int max = INT32_MIN;
    for (auto i = vec.rbegin() ; i < vec.rend(); ++i)
    {
        if (*i >= max)
        {
            max = *i;
            leaders.push_back(max);
        }
    }
    for (auto it = leaders.rbegin(); it < leaders.rend(); ++it)
    {
        std::cout << *it << " ";
    }
}
int main(int argc, char const *argv[])
{
    int tests, arr_size;
    std::vector<int> vec;
    std::cin >> tests;
    for (auto i = 0; i < tests; i++)
    {
        int n;
        std::cin >> n;
        vec.reserve(n);
        for (auto i = 0; i < n; i++)
        {
            int x;
            std::cin >> x;
            vec.push_back(x);
        }
        show_leaders(vec);
        std::cout << std::endl;
        vec.clear();
    }
    return 0;
}
