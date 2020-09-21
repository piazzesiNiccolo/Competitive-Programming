#include <iostream>
#include <vector>
#include <deque>

void max_windows(std::vector<int> const &vec, int k)
{
    std::deque<int> current;
    
    for (auto i = 0; i < vec.size(); i++)
    {
        while (!current.empty() && current.front() <= i - k)
        {
            current.pop_front();
        }

        while (!current.empty() && vec.at(i) >= vec.at(current.back()))
        {
            current.pop_back();
        }

        current.push_back(i);
        if (i >= k - 1)
        {
            std::cout << vec.at(current.front()) << " ";
        }
    }
}
int main(int argc, char const *argv[])
{
    int tests;
    std::vector<int> vec;
    std::cin >> tests;
    for (auto i = 0; i < tests; i++)
    {
        int n,k;
        std::cin >> n;
        std::cin >> k;
        vec.reserve(n);
        for (auto i = 0; i < n; i++)
        {
            int x;
            std::cin >> x;
            vec.push_back(x);
        }
        max_windows(vec,k);
        std::cout << std::endl;
        vec.clear();
    }
    return 0;
}
