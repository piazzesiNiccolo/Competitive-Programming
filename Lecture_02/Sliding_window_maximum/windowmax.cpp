#include <iostream>
#include <vector>

void solve(){
    
    int k, N;
    std::cout << "window size:\n";
    std::cin >> k;
    std::cout << "Array size:\n";
    std::cin >> N;
    std::vector<int> v;
    std::cout << "Insert array values:\n";
    for (auto i = 0; i < N; i++)
    {
        int val;
        std::cin >> val;
        v.push_back(val);
    }
    
    int max = 0;
    std::cout << "\nmaximums in subarrays of size " << k << std::endl;
    for (auto i = 0; i <= N - k; i++)
    { 
        max = 0;
        for (auto j = i; j < i + k; j++)
        {
            if (v[j] > max)
            {
                max = v[j];
            }
            
        }
        std::cout << max << std::endl;
    }
}
int main(int argc, char const *argv[])
{
    
    solve();
}
