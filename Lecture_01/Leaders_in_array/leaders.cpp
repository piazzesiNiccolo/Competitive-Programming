#include <iostream>
#include <vector>
#include <algorithm>

vector<int> leaders(int arr[], int n){
    
    // Your code here
    
    /******************
     * You just need to complete this
     * function and return the vector
     * containing the leaders.
     * ***************/

    std::vector<int> leaders;
    leaders.reserve(n);
    int max = INT32_MIN;
    for (int i = n-1; i >=0 ; i--)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
            leaders.push_back(max);
        }
        
    }
    std::reverse(leaders.begin(),leaders.end());
    return leaders;
     
    
}

