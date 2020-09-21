#include<iostream>
#include <vector>
#include <algorithm>

void  total_rain_trapped(std::vector<int> const& vec){
    std::vector<int> left_max;
    std::vector<int> right_max;
    left_max.reserve(vec.size());
    right_max.reserve(vec.size());
    int max = 0;
    int rain = 0;
    for (auto const& el: vec)
    {   
        max = std::max(max, el);
        left_max.push_back(max);
    }
    max = 0;
    for (auto j = vec.rbegin(); j < vec.rend() ; ++j)
    {   
        max = std::max(max,*j);
        right_max.push_back(max);
    }

    for (auto i = 0; i < vec.size(); i++)
    {
        rain += std::min(left_max.at(i),right_max.at(vec.size() - i -1)) - vec.at(i);
    }
    std::cout << rain;
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
        total_rain_trapped(vec);
        std::cout << std::endl;
        vec.clear();
    }
    return 0;
}   