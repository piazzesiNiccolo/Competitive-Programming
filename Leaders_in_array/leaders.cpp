#include <iostream>
#include <vector>

void show_leaders(std::vector<int> const &vec)
{
    std::vector<int> leaders;
    int n = vec.size();
    leaders.reserve(n);
    int max = vec.back();
    leaders.push_back(max);
    for (auto i = 2; i < n; i++)
    {
        if (vec.at(n - i) > max)
        {
            max = vec.at(n - i);
            leaders.push_back(max);
        }
    }
    for (auto i = 0; i < leaders.size(); i++)
    {
        std::cout << leaders.at(leaders.size() - i - 1) << " ";
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
        vec.clear();
    }
    return 0;
}
