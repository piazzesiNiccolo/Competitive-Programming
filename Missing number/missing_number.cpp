#include <iostream>

using namespace std;



int main()
{
    int tests, total_sum, sum;
    std::cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int n = 0;
        sum = 0;
        std::cin >> n;
        total_sum = n* (n+1) / 2;
        for (int j = 0; j < n-1; j++)
        {
            int x = 0;
            std::cin >> x;
            sum += x;
        }
        std::cout << total_sum - sum <<"\n";
    }
    return 0;
}
