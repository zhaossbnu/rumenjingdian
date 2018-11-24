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
#include <numeric>
using namespace std;

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0):x(x), y(y){}
    bool operator<(const Point  & b) const 
    {
        return x < b.x;
    }
};

bool less_y(const Point &a, const Point &b)
{
    return a.x < b.x && (a.x == b.x && a.y < b.y);
}

bool greater_y(const Point &a, const Point &b)
{
    return a.x < b.x && (a.x == b.x && a.y > b.y);
}

int main(void)
{
    freopen("input.in", "r", stdin);
    #ifndef _DEBUG
    freopen("output.out", "w", stdout);
    #endif
    int Case;
    cin >> Case;
    while (Case--)
    {
        int n;
        cin >> n;
        vector<Point> a(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i].x >> a[i].y;
        }
        int len = a.size();
        sort(a.begin(), a.end());
        vector<Point>::iterator mid = a.begin() + len / 2;
        sort(a.begin(), mid, greater_y);
        sort(mid, a.end(), less_y);
        int double_mid = 0; 
        if (len % 2 == 1)
        {
            double_mid = a[len / 2].x * 2;
        }
        else
        {
            double_mid = a[len / 2].x + a[len / 2 - 1].x ;
        }
        bool flag = true;
        for (int i = 0; i <= len / 2; ++i)
        {
            if (a[i].x + a[len - 1 - i].x != double_mid || a[i].y != a[len - 1 - i].y)
            {
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}

