#include <iostream>
#include <vector>
void show_max_sum(std::vector<int> const &vec)
{
    int max, sum;
    sum = vec.front();
    max = sum;
    for (auto i = 1; i < vec.size(); i++)
    {
        if (sum > 0)
        {
            sum += vec.at(i);
        }
        else
        {
            sum = vec.at(i);
        }

        if (sum > max)
        {
            max = sum;
        }
    }
    std::cout << max << "\n";
}
int main(int argc, char const *argv[])
{
    int tests, arr_size, n;
    std::vector<int> vec;
    std::cin >> tests;
    for (auto i = 0; i < tests; i++)
    {
        n = 0;
        std::cin >> n;
        vec.reserve(n);
        for (auto i = 0; i < n; i++)
        {
            int x;
            std::cin >> x;
            vec.push_back(x);
        }
        show_max_sum(vec);
        vec.clear();
    }
    return 0;
}
