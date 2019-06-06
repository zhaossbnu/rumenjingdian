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

const int N = 110;
int g[N][N];
int in[N];

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    int n, m;
    while (cin >> n >> m && n && m)
    {
        memset(g, 0, sizeof(g));
        memset(in, 0, sizeof(in));
        for (int i = 1; i <= m; ++i)
        {
            int x, y; cin >> x >> y;
            g[x][y] = 1;
            ++in[y];
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i)
        {
            if (in[i] == 0) q.push(i);
        }
        while (!q.empty())
        {
            int t = q.front(); q.pop();
            cout << t << " ";
            for (int i = 1; i <= n; ++i)
            {
                if (g[t][i] && in[i] > 0)
                {
                    --in[i];
                    if (in[i] == 0) q.push(i);
                }
            }
        }
        cout << endl;

    }
    return 0;
}
