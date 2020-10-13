#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
  int queries,l,r;
  std::string S;
  std::cin >> S >> queries;
  std::vector<int> sol;
  sol.reserve(S.size() + 2);
  sol.push_back(0);
  for (auto i = 0; i < S.size()-1; i++)
  {
    int next = S[i] == S[i+1] ? 1 : 0;
    sol.push_back(next);
  }
  
  std::partial_sum(sol.begin(),sol.end(),sol.begin());

  for (int i = 0; i < queries; i++)
  {
    std::cin >> l >> r;
    std::cout << sol[r-1] - sol[l-1] << std::endl;
  }
  
  
  
  
}