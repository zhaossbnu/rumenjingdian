#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    int m, n;
    int Case = 0;
    while (cin >> m >> n && m && n)
    {
        map<double, int> g;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                double t;
                cin >> t;
                g[t] = g[t] + 1;
            }
        }
        g[100000000.0] = 0;
        double water;
        cin >> water;
        water /= 100;
        map<double, int> g_copy = g;
        while (g.size() >= 2 && water > 0)
        {
            pair<double, int> a = *(g.begin());
            g.erase(g.begin());
            pair<double, int> b = *(g.begin());
            if (a.second * (b.first - a.first) >= water)
            {
                a.first += water / a.second;
                water = 0;
                g[a.first] = a.second;
            }
            else
            {
                water = water - a.second * (b.first - a.first);
                g[b.first] += a.second;
            }
        }
        printf("Region %d\n", ++Case);
        printf("Water level is %.2lf meters.\n", g.begin()->first);
        double cnt = 0;
        map<double, int>::iterator ita = g.begin();
        map<double, int>::iterator itb = g_copy.begin();
        for (map<double, int>::iterator itb = g_copy.begin(); itb != g_copy.end(); ++itb)
        {
            if (itb->first < ita->first)
            {
                cnt += itb->second;
            }
        }
        printf("%.2lf percent of the region is under water.\n", cnt * 100 / (m * n));
    }
    return 0;
}
