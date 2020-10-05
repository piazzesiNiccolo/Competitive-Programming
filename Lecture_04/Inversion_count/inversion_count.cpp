#include <iostream>
#include <vector>
int64_t merge_count(std::vector<int64_t> & v, int64_t l, int64_t m, int64_t r)
{
    int64_t icount = 0;
    auto i = v.begin() + l;
    auto j = v.begin() + m + 1;
    std::vector<int64_t> remains;
    remains.reserve(r - l + 1);
    while ((i <= v.begin() + m) and (j <= v.begin() + r))
    {
        if (*i < *j)
        {
            remains.push_back(*i);
            i++;
        }
        else
        {
            remains.push_back(*j);
            j++;
            int64_t d = std::distance(v.begin(), i);
            icount += m - d + 1;
        }
    }
    while (i <= v.begin() + m)
    {
        remains.push_back(*i);
        i++;
    }
    while (j <= v.begin() + r)
    {
        remains.push_back(*j);
        j++;
    }
    std::copy(remains.begin(), remains.end(),v.begin() + l);
    return icount;
}
int64_t inversion_count(std::vector<int64_t> & v, int64_t l, int64_t r)
{
    int64_t count = 0;
    if (l < r)
    {
        int64_t m = (l + r) / 2;
        count += inversion_count(v, l, m);
        count += inversion_count(v, m+1, r);
        count += merge_count(v, l, m, r);
    }
    return count;
}
int main(int64_t argc, char const *argv[])
{
    int64_t tests, count;
    std::vector<int64_t> vec;
    std::cin >> tests;
    for (auto i = 0; i < tests; i++)
    {
        int64_t n;
        std::cin >> n;
        vec.reserve(n);
        for (auto i = 0; i < n; i++)
        {
            int64_t x;
            std::cin >> x;
            vec.push_back(x);
        }
        count = inversion_count(vec, 0, vec.size() - 1);
        std::cout << count << std::endl;
        vec.clear();
    }
    return 0;
}