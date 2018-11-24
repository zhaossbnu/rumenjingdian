#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <stack>
#include <queue>
#include <iterator>
#include <cmath>
using namespace std;

struct Building
{
    int id;
    double x, y, width, depth, height;
    bool operator<(const Building & b) const
    {
        return x < b.x || (x == b.x && y < b.y);
    }
};

bool cover(const Building & b, double midx)
{
    return midx >= b.x && midx <= b.x + b.width;
}

bool judge(vector<Building> bds, int i, double midx)
{
    if (!cover(bds[i], midx))
    {
        return false;
    }
    for (int j = 0; j < bds.size(); ++j)
    {
        if (cover(bds[j], midx) && bds[i].y > bds[j].y && bds[i].height <= bds[j].height)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    int Case = 0;
    while (cin >> n && n)
    {
        vector<Building> bds(n);
        vector<double> locx;
        for (int i = 0; i < n; ++i)
        {
            bds[i].id = i + 1;
            cin >> bds[i].x >> bds[i].y >> bds[i].width >> bds[i].depth >> bds[i].height;
            locx.push_back(bds[i].x);
            locx.push_back(bds[i].x + bds[i].width);
        }
        sort(bds.begin(), bds.end());
        sort(locx.begin(), locx.end());

        vector<double>::iterator it = unique(locx.begin(), locx.end());
        locx.resize(distance(locx.begin(), it));

        if (Case++)
        {
            cout << endl;
        }
        printf("For map #%d, the visible buildings are numbered as follows:\n", Case);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < locx.size() - 1; ++j)
            {
                if (judge(bds, i, (locx[j] + locx[j + 1])/ 2))
                {
                    cout << bds[i].id << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

