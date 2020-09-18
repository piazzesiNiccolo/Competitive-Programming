#include<iostream>
#include <vector>


int main(int argc, char const *argv[])
{
    std::vector<int> v{7,4,0,9};

    int max= 0;
    int sum = 0;
    int n = v.size();
    for (auto i = 0; i < n; i++)
    {   
        
        if (v[i] >= max)
        {
            max = v[i];
        }
        else
        {
            sum += max - v[i];
        }
        
        
    }
    std::cout << sum << std::endl;
    
    return 0;
}



