#include <iostream>
#include <vector>

int maxSubarraySum(int arr[], int n)
{
    int max, sum;
    sum = arr[0];
    max = sum;
    for (int i = 1; i < n; i++)
    {
        if (sum > 0)
        {
            sum += arr[i];
        }
        else
        {
            sum = arr[i];
        }
        if (sum > max)
        {
            max = sum;
        }
    }

    return max;
}
