        #include <iostream>
        #include <vector>
        #include <stack>
        
        void next_larger_element(std::vector<int64_t> const& v)
        {
            int64_t next = 0;
            std::vector<int64_t> nexts;
            nexts.reserve(v.size());
            std::stack<int64_t> q;
        
            for (auto i = v.rbegin(); i < v.rend(); ++i)
            {
                while (!q.empty() && *i > q.top())
                {
                    q.pop();
                }
                next = q.empty() ? -1 : q.top();
                nexts.push_back(next);
                q.push(*i);
                
            }
            for (auto it = nexts.rbegin(); it < nexts.rend(); ++it)
            {
                std::cout << *it << " ";
            }
            
            
        }
        int main(int argc, char const *argv[])
        {

            int tests = 0;
            std::cin >> tests;
            std::vector<int64_t> vec;
            for (auto i = 0; i < tests; ++i)
            {
                int64_t n = 0;
                std::cin >> n;
                vec.reserve(n);
                for (auto j = 0; j < n; ++j)
                {
                    int x = 0;
                    std::cin >> x;
                    vec.push_back(x);
                }
                next_larger_element(vec);
                std::cout << std::endl;
                vec.clear();
            }
            return 0;
        }
