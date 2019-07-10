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

const int SZ = 20;
const int N = 256;
int w, h, n;
int mov[5][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}, { 0, 0 } };


// 起点和终点的位置
vector<int> s(3, 0), e(3, 0);
// 空白格子组成的图
vector<int> g[N];

// 与初始状态的距离和与结束状态的距离
int d[N][N][N], rd[N][N][N];

bool conflict(int a, int b, int a2, int b2) {
    // 两个鬼的下一个位置相同或者他们位置互换
    return a2 == b2 || (a2 == b && b2 == a);
}

int Bbfs()
{
    memset(d, -1, sizeof(d));
    memset(rd, -1, sizeof(rd));
    // q1 正序队列  q2 逆序队列
    queue<vector<int>> q1, q2;
    q1.push(s), q2.push(e);
    d[s[0]][s[1]][s[2]] = 0, rd[e[0]][e[1]][e[2]] = 0;
    while (!q1.empty() || !q2.empty())
    {
        vector<int> t1 = q1.front(), t2 = q2.front(); q1.pop(), q2.pop();
        // 如果正向搜索到终点或逆向搜索到起点
        if (t1 == e) return d[t1[0]][t1[1]][t1[2]];
        if (t2 == s) return rd[t2[0]][t2[1]][t2[2]];
        for (int i = 0; i < g[t1[0]].size(); ++i)
        {
            int na = g[t1[0]][i];
            for (int j = 0; j < g[t1[1]].size(); ++j)
            {
                int nb = g[t1[1]][j];
                if (conflict(t1[0], t1[1], na, nb)) continue;
                for (int k = 0; k < g[t1[2]].size(); ++k)
                {
                    int nc = g[t1[2]][k];
                    if (conflict(t1[0], t1[2], na, nc)) continue;
                    if (conflict(t1[1], t1[2], nb, nc)) continue;
                    if (d[na][nb][nc] != -1) continue;
                    d[na][nb][nc] = d[t1[0]][t1[1]][t1[2]] + 1;
                    // 正逆搜索 相遇
                    if (rd[na][nb][nc] != -1) return d[na][nb][nc] + rd[na][nb][nc];
                    q1.push({na, nb, nc});
                }
            }
        }
        for (int i = 0; i < g[t2[0]].size(); ++i)
        {
            int na = g[t2[0]][i];
            for (int j = 0; j < g[t2[1]].size(); ++j)
            {
                int nb = g[t2[1]][j];
                if (conflict(t2[0], t2[1], na, nb)) continue;
                for (int k = 0; k < g[t2[2]].size(); ++k)
                {
                    int nc = g[t2[2]][k];
                    if (conflict(t2[0], t2[2], na, nc)) continue;
                    if (conflict(t2[1], t2[2], nb, nc)) continue;
                    if (rd[na][nb][nc] != -1) continue;
                    rd[na][nb][nc] = rd[t2[0]][t2[1]][t2[2]] + 1;
                    // 正逆搜索 相遇
                    if (d[na][nb][nc] != -1) return d[na][nb][nc] + rd[na][nb][nc];
                    q2.push({ na, nb, nc });
                }
            }
        }
    }
    return -1;
}


int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif
    while (cin >> w >> h >> n && w)
    {
        for (int i = 0; i < N; ++i) g[i].clear();
        getchar();
        char maze[SZ][SZ];
        for (int i = 0; i < h; ++i) cin.getline(maze[i], 20);

        int cnt = 0;
        vector<pair<int, int>> nodes(260);
        int id[SZ][SZ];
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (maze[i][j] != '#')
                {
                    ++cnt;
                    nodes[cnt] = { i, j };
                    id[i][j] = cnt;
                    if (islower(maze[i][j])) s[maze[i][j] - 'a'] = cnt;
                    if (isupper(maze[i][j])) e[maze[i][j] - 'A'] = cnt;
                }
            }
        }

        // 建图
        for (int i = 1; i <= cnt; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                int nx = nodes[i].first + mov[j][0], ny = nodes[i].second + mov[j][1];
                if (maze[nx][ny] != '#')
                    g[i].push_back(id[nx][ny]);
            }
        }

        if (n <= 2) { ++cnt; g[cnt].push_back(cnt); s[2] = e[2] = cnt; }
        if (n <= 1) { ++cnt; g[cnt].push_back(cnt); s[1] = e[1] = cnt; }
        long long start_t = clock();
        cout << Bbfs() << endl;
        long long end_t = clock();
        cout << (double)(end_t - start_t) / CLOCKS_PER_SEC << endl;
    }
    return 0;
}