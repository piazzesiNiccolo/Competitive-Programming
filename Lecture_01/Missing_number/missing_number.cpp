#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int MissingNumber(vector<int>& array, int n) {
    int total_sum = n*(n+1) / 2;
    int sum = accumulate(array.begin(),array.end(), 0);
    return total_sum - sum;
}

