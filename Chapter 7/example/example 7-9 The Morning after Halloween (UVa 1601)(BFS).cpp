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

// 与初始状态的距离
int d[N][N][N];

bool conflict(int a, int b, int a2, int b2) {
    // 两个鬼的下一个位置相同或者他们位置互换
    return a2 == b2 || (a2 == b && b2 == a);
}

int bfs()
{
    memset(d, -1, sizeof(d));
    queue<vector<int>> q;
    q.push(s);
    d[s[0]][s[1]][s[2]] = 0;
    while (!q.empty())
    {
        vector<int> t = q.front(); q.pop();
        // 找到最终状态
        if (t == e) return d[t[0]][t[1]][t[2]];
        // 未来三个位置任意两个位置冲突都不可以
        for (int i = 0; i < g[t[0]].size(); ++i)
        {
            int na = g[t[0]][i];
            for (int j = 0; j < g[t[1]].size(); ++j)
            {
                int nb = g[t[1]][j];
                if (conflict(t[0], t[1], na, nb)) continue;
                for (int k = 0; k < g[t[2]].size(); ++k)
                {
                    int nc = g[t[2]][k];
                    if (conflict(t[0], t[2], na, nc)) continue;
                    if (conflict(t[1], t[2], nb, nc)) continue;
                    // 曾经计算过 肯定是最短的
                    if (d[na][nb][nc] != -1) continue;
                    d[na][nb][nc] = d[t[0]][t[1]][t[2]] + 1;
                    q.push({na, nb, nc});
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

        // 利用白点建图
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
        cout << bfs() << endl;
        long long end_t = clock();
        cout << (double)(end_t - start_t) / CLOCKS_PER_SEC << endl;
    }
    return 0;
}

/*

5 5 2
#####
#A#B#
#   #
#b#a#
#####
16 4 3
################
## ########## ##
#    ABCcba    #
################
16 16 3
################
### ##    #   ##
##  #  ##   # c#
#  ## ########b#
# ##  # #   #  #
#  # ##   # # ##
##  a#  # # #  #
### ## #### ## #
##   #   #  #  #
#  ##### # ## ##
####   #B# #   #
##  C#   #   ###
#  # # ####### #
# ######  A##  #
#        #    ##
################
0 0 0


7
36
77
*/