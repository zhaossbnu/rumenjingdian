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

const int N = 30;
int mov[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

struct Node
{
    int x, y, k, step;
    Node(int x = 0, int y = 0, int k = 0, int step = 0) : x(x), y(y), k(k), step(step) {}
};

int m, n, k;
int ans;


int g[N][N];

int vis[N][N];

bool inside(int x, int y)
{
    return x >= 1 && x <= m && y >= 1 && y <= n;
}


void bfs()
{
    Node st(1, 1, k, 0);
    queue<Node> q;
    q.push(st);
    while (!q.empty())
    {
        Node t = q.front(); q.pop();
        vis[t.x][t.y] = 1; // 设置访问一定在此处
        if (t.x == m && t.y == n)
        {
            ans = t.step;
            return;
        }
        for (int i = 0; i < 4; ++i)
        {
            int nx = t.x + mov[i][0], ny = t.y + mov[i][1];
            if (inside(nx, ny) && !vis[nx][ny])
            {
                if (g[nx][ny] == 0)
                {
                    // 遇到空白 不要忘记 连续跨越的数目要恢复
                    Node nt(nx, ny, k, t.step + 1);
                    q.push(nt);
                }
                else if (t.k > 0) // 要跨越障碍必须要减少 k
                {
                    Node nt(nx, ny, t.k - 1, t.step + 1);
                    q.push(nt);
                }
                
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
    int T; cin >> T;
    while (T--)
    {
        cin >> m >> n >> k;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> g[i][j];
            }
        }
        memset(vis, 0, sizeof(vis));
        bfs();
        if (!vis[m][n]) cout << "-1" << endl;
        else cout << ans << endl;
    }
    return 0;
}


