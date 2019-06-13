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

const int N = 1e4 + 10;


int v, e, t;
vector<int> g[N];
int vis[N];

// 返回该子图中度数为奇数的点个数
int dfs(int x)
{
    if (vis[x]) return 0;
    vis[x] = 1;
    int cnt = 0;
    if (g[x].size() % 2) cnt = 1;
    for (int y : g[x]) cnt += dfs(y);
    return cnt;
}

int cal(int x)
{
    int res = 0, cnt = dfs(x);
    if (cnt > 2) res = (cnt - 2) / 2;
    return res;
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    int T = 0;
    while (cin >> v >> e >> t && !(v == 0 && e == 0 && t == 0))
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < N; ++i) g[i].clear();
        for (int i = 1; i <= e; ++i)
        {
            int x, y; cin >> x >> y;
            g[x].push_back(y); g[y].push_back(x);
        }
        int ans = e, cnt = 0;
        for (int i = 1; i <= v; ++i)
        {
            if (vis[i] || g[i].empty()) continue;
            ans += cal(i);
            ++cnt;
        }
        if(cnt) printf("Case %d: %d\n", ++T, t * (ans + cnt - 1));
        else printf("Case %d: 0\n", ++T);

    }
    return 0;
}


