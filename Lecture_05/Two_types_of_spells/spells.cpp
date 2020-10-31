#include <iostream>
#include <set>
using namespace std;
int find_max(set<int> const &light, set<int> const &fire)
{
    int max = 0;
    bool doubled = false;
    auto i = light.begin();
    auto j = fire.begin();
    while (i != light.end() || j != fire.end())
    {
        if ((i != light.end() && *i <= *j) || j == fire.end())
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
        else if ((*i > *j && j != fire.end()) || i == light.end())
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

    cout << "max: " << max;
    return max;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    set<int> fire, light;
    for (int i = 0; i < n; i++)
    {
        int type, value;
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
        find_max(light, fire);
    }

    return 0;
}
