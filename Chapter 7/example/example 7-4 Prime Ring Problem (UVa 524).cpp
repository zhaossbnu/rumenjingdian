#include <iostream>
#include <iomanip>
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

int isp[32] = { 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1 };

int a[20];
int vis[20];
int n;

void dfs(int cur)
{
    if (cur == n + 1 && isp[a[1] + a[n]])
    {
        for (int i = 1; i <= n; ++i) cout << a[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i = 2; i <= n; ++i)
        {
            if (!vis[i] && isp[i + a[cur - 1]])
            {
                a[cur] = i;
                vis[i] = 1;
                dfs(cur + 1);
                vis[i] = 0;
            }
        }
    }
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif
    int T = 0;
    while (cin >> n)
    {
        if (T) puts("");
        printf("Case %d:\n", ++T);
        memset(vis, 0, sizeof(vis));
        a[1] = 1; vis[1] = 1;
        dfs(2);
    }
    return 0;
}