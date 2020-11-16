#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector <int> max_of_subarrays(int *arr, int n, int k){
    deque<int> current;
    vector<int> maxs;
    for (int i = 0; i < n; i++)
    {
        while (!current.empty() && current.front() <= i - k)
        {
            current.pop_front();
        }
        while (!current.empty() && arr[i] >= arr[current.back()])
        {
            current.pop_back();
        }
        current.push_back(i);
        if (i >= k - 1)
        {
            maxs.push_back(arr[current.front()]);
        }
    }
    return maxs;
}