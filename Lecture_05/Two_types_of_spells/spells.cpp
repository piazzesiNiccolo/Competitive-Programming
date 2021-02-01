#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;



void power(vector<pair<long, long>> &changes)
{
    map<long, long> top, others;
    int topFire = 0, fireSpells = 0;
    long long sum = 0, actual_sum = 0;

    function<void(pair<long, long> &)> add_spell = [&](pair<long, long> &s) {
        if (s.first != 0)
        {
            if (!others.empty())
            {
                long max = others.rbegin()->first;
                if (s.second > max)
                {
                    top.insert({s.second, s.first});
                    sum += s.second * 2;
                }
                else
                {
                    long t_max = others.rbegin()->second;
                    others.erase(max);
                    top.insert({max, t_max});
                    others.insert({s.second, s.first});
                    if (t_max == 0)
                        topFire++;
                    sum += max;
                    sum += s.second;
                }
            }
            else
            {
                top.insert({s.second, s.first});
                sum += s.second * 2;
            }
        }
        else
        {
            fireSpells++;
            if (!top.empty())
            {
                long min = top.begin()->first;
                if (s.second < min)
                {
                    others.insert({s.second, s.first});
                    sum += s.second;
                }
                else
                {
                    long t_min = top.begin()->second;
                    top.erase(min);
                    others.insert({min, t_min});
                    top.insert({s.second, s.first});
                    topFire++;
                    if (t_min == 0)
                        topFire--;
                    sum -= min;
                    sum += s.second * 2;
                }
            }
            else
            {
                others.insert({s.second, s.first});
                sum += s.second;
            }
        }
    };

    function<void(pair<long, long> &)> remove_spell = [&](pair<long, long> &s) {
        if (s.first)
        {
            if (top.find(s.second) != top.end())
            {
                top.erase(s.second);
                sum -= s.second * 2;
            }
            else
            {
                others.erase(s.second);
                long min = top.begin()->first;
                long t_min = top.begin()->second;
                top.erase(min);
                others.insert({min, t_min});
                if (t_min == 0)
                    topFire--;
                sum -= s.second;
                sum -= min;
            }
        }
        else
        {
            fireSpells--;
            if (top.find(s.second) != top.end())
            {
                top.erase(s.second);
                topFire--;
                long max = others.rbegin()->first;
                long t_max = others.rbegin()->second;
                others.erase(max);
                top.insert({max, t_max});
                if (t_max == 0)
                    topFire++;
                sum -= s.second * 2;
                sum += max;
            }
            else
            {
                others.erase(s.second);
                sum -= s.second;
            }
        }
    };

    for (int i = 0; i < changes.size(); i++)
    {
        pair<long, long> c = changes[i];
        if (c.second > 0)
        {
            add_spell(c);
        }
        else
        {
            c.second = -1L * c.second;
            remove_spell(c);
        }
        actual_sum = sum;
        if (topFire == 0 && fireSpells != 0)
        {
            if (!top.empty() && !others.empty())
            {
                actual_sum -= top.begin()->first;
                actual_sum += others.rbegin()->first;
            }
        }
        else if (fireSpells == 0)
        {
            actual_sum -= top.begin()->first;
        }

        cout << actual_sum << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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