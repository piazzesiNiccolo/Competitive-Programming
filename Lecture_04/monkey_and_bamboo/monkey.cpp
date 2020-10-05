#include <iostream>
#include <vector>
#include <algorithm>
int find_strength(std::vector<int> & v)
{
    int strength = 0,last_rung = 0,min = 0;
    std::sort(v.begin(),v.end());
    for (auto i : v)
    {
        if (i - last_rung > strength)
        {
            strength = i-last_rung;
        }
        last_rung = i;
    }

    min = strength;
    last_rung = 0;
    
    for (auto i : v)
    {
        if (i-last_rung == strength)
        {
            strength--;
        }
        else if (i-last_rung > strength)
        {
            min++;
            break;
            
        }
        last_rung = i;
    }
    
    return min;
}
int main(int argc, char const *argv[])
{

    int tests;
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
    int min_strength = find_strength(vec);
    std::cout << min_strength << std::endl;
    vec.clear();
    }
    return 0;
}