#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cctype>
#include <stack>
#include <queue>
#include <iterator>
#include <cmath>
#include <numeric>
using namespace std;

struct Theme
{
    int tid, num, t0, t, dt;
    int last;
};

struct Server
{
    int pid, k;
    vector<int> tids;
    int last;
    int serving_idx;
    bool operator<(const Server & b) const
    {
        return last < b.last || (last == b.last && pid < b.pid);
    }
};

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif
    int n;
    int Case = 0;
    while (cin >> n && n)
    {
        vector<Theme> themes(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> themes[i].tid >> themes[i].num >> themes[i].t0 >> themes[i].t >> themes[i].dt;
            themes[i].last = 0x3fffffff;
        }
        int m;
        cin >> m;
        vector<Server> servers(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> servers[i].pid >> servers[i].k;
            servers[i].tids.resize(servers[i].k);
            for (int j = 0; j < servers[i].k; ++j)
            {
                cin >> servers[i].tids[j];
            }
            servers[i].last = servers[i].serving_idx = -1;
        }
        int time = 0;
        bool is_end = false;
        while (!is_end)
        {
            for (int i = 0; i < n; ++i)
            {
                if (themes[i].num)
                {
                    if (themes[i].t0 == time || time - themes[i].last == themes[i].dt)
                    {
                        --themes[i].num;
                        themes[i].last = time;
                    }
                }
            }
            for (int i = 0; i < m; ++i)
            {
                if (servers[i].serving_idx != -1)
                {
                    if (time - servers[i].last == themes[servers[i].serving_idx].t)
                    {
                        servers[i].serving_idx = -1;
                    }
                }
            }
            sort(servers.begin(), servers.end());
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (servers[j].serving_idx == -1 && themes[i].last == time &&
                        find(servers[j].tids.begin(), servers[j].tids.end(), themes[i].tid) != servers[j].tids.end())
                    {
                        servers[j].serving_idx = i;
                        servers[j].last = themes[i].last;
                    }
                }
            }
            is_end = true;
            for (int i = 0; i < n; ++i)
            {
                if (themes[i].num)
                {
                    is_end = false;
                }
            }
            for (int i = 0; i < m; ++i)
            {
                if (servers[i].serving_idx != -1)
                {
                    is_end = false;
                }
            }
            ++time;
        }
        printf("Scenario %d: All requests are serviced within %d minutes.\n", ++Case, time - 1);
    }
    
    return 0;
}