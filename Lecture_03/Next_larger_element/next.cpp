#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<long long> nextLargerElement(long long arr[], int n)
{
   long long next = 0;
   vector<long long> nexts;
   stack<long long> q;
   nexts.reserve(n);
   for (int i = n-1; i >=0; i--)
   {
        while (!q.empty() && arr[i] > q.top())
        {
            q.pop();
        }
        next = q.empty() ? -1 : q.top();
        nexts.push_back(next);
        q.push(arr[i]);
   }
   reverse(nexts.begin(),nexts.end());
   return nexts;
}
