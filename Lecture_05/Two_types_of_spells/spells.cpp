#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

map<long, long> doubled, others;
int doubledFire = 0, fireSpells = 0;
long long sum = 0, actual_sum = 0;

void add_spell(pair<long, long> &s) {
        if (s.first != 0)
        {
            if (!others.empty())
            {
                long max = others.rbegin()->first;
                if (s.second > max)
                {
                    doubled.insert({s.second, s.first});
                    sum += s.second * 2;
                }
                else
                {
                    long t_max = others.rbegin()->second;
                    others.erase(max);
                    doubled.insert({max, t_max});
                    others.insert({s.second, s.first});
                    if(t_max == 0) doubledFire++;
                    sum += max;
                    sum += s.second;
                }
            }
            else
            {
                doubled.insert({s.second, s.first});
                sum += s.second * 2;
            }
        }
        else
        {
            fireSpells++;
            if (!doubled.empty())
            {
                long min = doubled.begin()->first;
                if (s.second < min)
                {
                    others.insert({s.second, s.first});
                    sum += s.second;
                }
                else
                {
                    long t_min = doubled.begin()->second;
                    doubled.erase(min);
                    others.insert({min, t_min});
                    doubled.insert({s.second, s.first});
                    doubledFire++;
                    if(t_min == 0) doubledFire--;
                    sum -= min;
                    sum += s.second * 2;
                }
            }
            else
            {
                others.insert({s.second,s.first});
                sum += s.second;
            }
        }
    }


    void remove_spell(pair<long, long> &s) {
        if (s.first)
        {
            if (doubled.find(s.second) != doubled.end())
            {
                doubled.erase(s.second);
                sum -= s.second * 2;
            }
            else
            {
                others.erase(s.second);
                auto min = doubled.begin();
                doubled.erase(min->first);
                others.insert({min->first, min->second});
                if( min->second == 0) doubledFire--;
                sum -= s.second;
                sum -= min->first;
            }
        }
        else
        {
            fireSpells--;
            if (doubled.find(s.second) != doubled.end())
            {
                doubled.erase(s.second);
                doubledFire--;
                auto max = others.rbegin();
                others.erase(max->first);
                doubled.insert({max->first, max->second});
                if(max->second == 0) doubledFire++;
                sum -= s.second*2;
                sum += max->first;
            }
            else
            {
                others.erase(s.second);
                sum -= s.second;
            }
            
        }
    }

void power(vector<pair<long, long>> &changes)
{
    

    


    for (int i = 0; i < changes.size(); i++)
    {
        pair<long, long> c = changes[i];
        if (c.second > 0)
        {
            add_spell(c);
        }
        else
        {
            c.second = -1L*c.second;
            remove_spell(c);
        }
        actual_sum = sum;
        if (doubledFire == 0 && fireSpells != 0)
        {
            if (!doubled.empty() && !others.empty())
            {
                actual_sum -= doubled.begin()->first;
                actual_sum += others.rbegin()->first;
            }
        }
        else if (fireSpells == 0)
        {
            actual_sum -= doubled.begin()->first;
        }

        cout << actual_sum << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<long, long>> changes;
    long t, d;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> d;
        changes.emplace_back(t, d);
    }
    power(changes);
    return 0;
}