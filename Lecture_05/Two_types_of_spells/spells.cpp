    #include <iostream>
    #include <set>
    #include <numeric>
    using namespace std;
     
    long long int find_max(set<long long int> &light, set<long long int> &fire)
    {
     
        if (light.empty() && fire.empty())
        {
            return 0;
        }
        else if (light.empty())
        {
            return accumulate(fire.begin(), fire.end(), 0LL);
        }
        else if (fire.empty())
        {
            return 2 * accumulate(light.begin(), light.end(), 0LL) - *(light.begin());
        }
        long long int max = 0;
        bool doubled = false;
        auto i = light.begin();
        auto il = light.end();
        il--;
        auto j = fire.rbegin();
        while (*i < *il)
        {
            max = doubled ? max + 2*(*i) : max + *i;
            max +=  2 * (*il);
            doubled = true;
            if (j != fire.rend())
            {
                max += 2 * (*j);
                j++;
                doubled = false;
            }
            i++;
            il--;
        }
        if (*i == *il)
        {
            max = doubled ? max + 2*(*i) : max + *i;
            if (j != fire.rend())
            {
                max += 2 * (*j);
                j++;
            }
        }
     
        while (j != fire.rend())
        {
            max = doubled ? max + 2*(*j) : max + *j;
            doubled = false;
            j++;
        }
     
        return max;
    }
    int main(int argc, char const *argv[])
    {
        ios_base::sync_with_stdio(false);
        long long int n;
        cin >> n;
        set<long long int> fire, light;
        for (long long int i = 0; i < n; i++)
        {
            long long int type, value;
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