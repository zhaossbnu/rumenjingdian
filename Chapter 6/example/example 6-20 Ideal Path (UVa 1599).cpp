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

struct Node
{
    vector<pair<int, int> > out;
    //vector<pair<int, int> > in;
};

const int N = 100010;
const int INF = 0x3f3f3f3f;

vector<Node> g(N);

int d[N];
int vis[N];
int n, m;

vector<int> ans;

void bfs1()
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(n); vis[n] = 1; d[n] = 0;
    while (!q.empty())
    {
        int t = q.front(); q.pop();
        for (int i = 0; i < g[t].out.size(); ++i)
        {
            int nt = g[t].out[i].first;
            if (!vis[nt])
            {
                d[nt] = d[t] + 1;
                q.push(nt);
                vis[nt] = 1;
            }
        }
    }
    cout << d[1] << endl;
}

void bfs2()
{
    memset(vis, 0, sizeof(vis));
    ans.clear();

    vector<int> q;
    q.push_back(1); vis[1] = 1;
    for(int i = 1; i <= d[1]; ++i)
    {
        int min_color = INF;
        for (int j = 0; j < q.size(); ++j)
        {
            int t = q[j];            
            for (int k = 0; k < g[t].out.size(); ++k)
            {
                int nt = g[t].out[k].first, c = g[t].out[k].second;
                if (d[t] == d[nt] + 1)
                {
                    min_color = min(min_color, c);
                }
            }
        }
        ans.push_back(min_color);

        vector<int> q2;
        for (int j = 0; j < q.size(); ++j)
        {
            int t = q[j];
            for (int k = 0; k < g[t].out.size(); ++k)
            {
                int nt = g[t].out[k].first, c = g[t].out[k].second;
                if (!vis[nt] && d[t] == d[nt] + 1 && c == min_color)
                {
                    q2.push_back(nt); vis[nt] = 1;
                }
            }
        }
        q = q2;
    }
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
    cout << endl;
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; ++i) g[i].out.clear();
        memset(d, 0x3f, sizeof(d));
        for (int i = 1; i <= m; ++i)
        {
            int a, b, c; cin >> a >> b >> c;
            if(a == b) continue;
            g[a].out.push_back(pair<int, int>(b, c));
            g[b].out.push_back(pair<int, int>(a, c));
        }
        bfs1();
        bfs2();
    }
    return 0;
}


