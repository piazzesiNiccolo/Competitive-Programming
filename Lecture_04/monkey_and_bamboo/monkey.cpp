#include <iostream>
#include <vector>
#include <algorithm>

int64_t find_strength(std::vector<int64_t> &v)
{
    int64_t temp_strength = 0, final_value = 0;

    for (auto i = 1; i < v.size(); i++)
    {
        if (v.at(i) - v.at(i - 1) > final_value)
        {
            final_value = v.at(i) - v.at(i - 1);
        }
      
    }
    
    temp_strength = final_value;
    
    for (auto i = 1; i < v.size(); i++)
    {
        if (v.at(i) - v.at(i - 1) == temp_strength)
        {
            temp_strength--;
        }
        else if (v.at(i) - v.at(i - 1) > temp_strength)
        {
            final_value++;
            break;
        }
        
      
    }
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
        vec.reserve(n + 1);
        vec.push_back(0);
        for (auto j = 0; j < n; j++)
        {
            int64_t x;
            std::cin >> x;
            vec.push_back(x);
        }
        std::sort(vec.begin(), vec.end());
        int64_t min_strength = find_strength(vec);
        std::cout << "Case " << i + 1 << ": " << min_strength << std::endl;
        vec.clear();
    }
    return 0;
}