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
#include <ctime>
#include <stack>
using namespace std;

const int N = 1010;

struct Node
{
    double x, y, r;
};

Node g[N];
double l = 1000, r = 1000;
int vis[N];
int n;

bool intersection(int i, int j)
{
    return (g[i].x - g[j].x) * (g[i].x - g[j].x) +
        (g[i].y - g[j].y) * (g[i].y - g[j].y) <=
        (g[i].r + g[j].r) * (g[i].r + g[j].r);
}

void update(int cur)
{
    if (g[cur].x - g[cur].r <= 0)
        l = min(l, g[cur].y - sqrt(g[cur].r * g[cur].r - g[cur].x * g[cur].x));
    if (g[cur].x + g[cur].r >= 1000)
        r = min(r, g[cur].y - sqrt(g[cur].r * g[cur].r - (1000 - g[cur].x) * (1000 -g[cur].x)));
}

// 如果从上向下有通路  说明左右没有通路
// 否则 左右有通路
bool dfs(int cur)
{
    if (vis[cur]) return false;
    vis[cur] = 1;
    if (g[cur].y + g[cur].r <= 0) return true;
    for (int i = 1; i <= n; ++i)
    {
        if (i != cur && !vis[i] && intersection(cur, i))
            return dfs(i);
    }
    // 对于那些失败的圈  才有可能会影响到出发点和离开点
    update(cur);
    return false;
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> g[i].x >> g[i].y >> g[i].r;
    }
    memset(vis, 0, sizeof(vis));
    bool flag = true;
    for (int i = 1; i <= n; ++i)
    {
        if (g[i].y + g[i].r >= 1000 && dfs(i))
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        printf("0.00 %.2lf 1000.00 %.2lf\n", l, r);
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}


