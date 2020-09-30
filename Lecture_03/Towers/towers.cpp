#include <iostream>
#include <vector>
#include <algorithm>

void towers(std::vector<int> &towers)
{
    int towers_count = 1, currT = 0, currH = 1, maxH = 1;
    std::sort(towers.begin(), towers.end());
    currT = *towers.begin();
    for (auto i = towers.begin() + 1; i < towers.end(); i++)
    {
        if (*i == currT)
        {
            currH++;
            if (currH > maxH)
            {
                maxH = currH;
            }
        }
        else
        {
            towers_count++;
            currT = *i;
            currH = 1;
        }
    }
    std::cout << maxH << " " << towers_count;
}
int main(int argc, char const *argv[])
{

    std::vector<int> vec;
    int n = 0;
    std::cin >> n;
    vec.reserve(n);
    for (auto j = 0; j < n; ++j)
    {
        int x = 0;
        std::cin >> x;
        vec.push_back(x);
    }
    towers(vec);
    std::cout << std::endl;
    vec.clear();
    return 0;
}