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
#include <unordered_set>
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

const int N = 210;
struct Node
{
    int v[3], dist;
    // 建立小根堆
    bool operator<(const Node &b) const
    {
        return dist > b.dist;
    }
};

int cap[3], d;

int vis[N][N], ans[N];

void update_ans(const Node & a)
{
    for (int i = 0; i < 3; ++i)
    {
        int d = a.v[i];
        if (ans[d] < 0 || a.dist < ans[d]) ans[d] = a.dist;
    }
}


void bfs()
{
    memset(vis, 0, sizeof(vis));
    memset(ans, -1, sizeof(ans));
    priority_queue<Node> pq;
    Node start;
    start.v[0] = 0, start.v[1] = 0, start.v[2] = cap[2], start.dist = 0;
    pq.push(start);
    vis[0][0] = 1;
    while (!pq.empty())
    {
        Node t = pq.top(); pq.pop();
        update_ans(t);
        if (ans[d] >= 0) break;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i == j) continue;
                // i杯没有水 j杯水满
                if (t.v[i] == 0 || t.v[j] == cap[j]) continue;
                // 可以倒的水量
                int wa = min(cap[j] - t.v[j], t.v[i]);
                Node nt; memcpy(&nt, &t, sizeof(t));
                nt.dist = t.dist + wa;
                nt.v[i] -= wa, nt.v[j] += wa;
                if (!vis[nt.v[0]][nt.v[1]])
                {
                    vis[nt.v[0]][nt.v[1]] = 1;
                    pq.push(nt);
                }
            }
        }
    }
    while (d >= 0)
    {
        if (ans[d] >= 0)
        {
            cout << ans[d] << " " << d << endl;
            return;
        }
    }
}


int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif
    int T; cin >> T;
    while (T--)
    {
        cin >> cap[0] >> cap[1] >> cap[2] >> d;
        bfs();
    }
    return 0;
}