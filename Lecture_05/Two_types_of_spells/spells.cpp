#include <iostream>
#include <set>
using namespace std;


int64_t find_max(set<int64_t>  &light, set<int64_t> & fire)
{
    if(fire.empty()){fire.insert(0);}
    int64_t max = 0;
    bool doubled = false;
    auto i = light.begin();
    auto j = fire.crbegin();
    
    while (i != light.end() || j != fire.crend())
    {
        if ((i != light.end() && *i <= *j) || j == fire.crend())
        {
            if (doubled)
            {
                max += 2 * (*i);
            }
            else
            {
                max += *i;
            }
            doubled = true;
            i++;
        }
        else if ((*i > *j && j != fire.crend()) || i == light.end())
        {
            if (doubled)
            {
                if (i != light.end())
                {
                    max += 2 * (*i) + 2*(*j);
                    i++;
                }
                else
                {
                    max += 2 * (*j);
                }
                doubled = false;
            }
            else
            {
                if (i != light.end())
                {
                    max += *i + 2 *(*j);
                    i++;
                }
                else {
                    max += *j;
                }            
            }
            j++;
        }
    }
    if(fire.size()==1){fire.erase(0);}
   
    return max;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int64_t n;
    cin >> n;
    set<int64_t> fire, light;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t type, value;
        cin >> type >> value;
        if (type)
        {
            if (value > 0)
            {
                light.insert(value);
            }
            else
            {
                light.erase(-value);
            }
        }
        else
        {
            if (value > 0)
            {
                fire.insert(value);
            }
            else
            {
                fire.erase(-value);
            }
        }
        cout << find_max(light, fire) << endl;
    }

    return 0;
}
