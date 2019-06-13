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

int maze[15][15];
// 上面和前面定下 向右转的情况下上面的值
int to[7][7];
int r, c, sx, sy, st, sf;

struct Node
{
    int x, y;
    int t, f;
    int pre;
    Node(int x = 0, int y = 0, int t = 0, int f = 0, int pre = 0) :x(x), y(y), t(t), f(f), pre(pre) {}
};

Node steps[10010];
vector<pair<int, int>> ans;

int mov[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int vis[15][15][10][10];

// 转动筛子
pair<int, int> rotate(int t, int f, int i)
{
    // 上
    if (i == 0) return pair<int, int>(f, 7 - t);
    // 右
    else if (i == 1) return pair<int, int>(to[t][f], f);
    // 下
    else if (i == 2) return pair<int, int>(7 - f, t);
    // 左
    else if (i == 3) return pair<int, int>(7 - to[t][f], f);
}

void print()
{
    int i = 1;
    printf("  ");
    for (auto it = ans.rbegin(); it != ans.rend(); ++it, ++i)
    {
        printf("(%d,%d)", it->first, it->second);
        if (i != ans.size()) printf(",");
        if (i % 10 == 0) printf("\n  ");
    }
    puts("");
}


void bfs()
{
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    steps[++cnt] = Node(sx, sy, st, sf, 0);
    vis[sx][sy][st][sf] = 1;
    queue<int> q; q.push(cnt);
    while (!q.empty())
    {
        int id = q.front(); q.pop();
        Node tp = steps[id];

        for (int i = 0; i < 4; ++i)
        {
            int nx = tp.x + mov[i][0], ny = tp.y + mov[i][1];
            // 下一个格子如果没有数字
            if (!maze[nx][ny]) continue;
            // 下一个格子 如果不是-1(不是星星) 并且 当前筛子的顶部数字和下一个格子的数字不同
            if (maze[nx][ny] != -1 && tp.t != maze[nx][ny]) continue;
            // 可以到达下一个格子 此时一定要先判断是否回到源点
            if (nx == sx && ny == sy)
            {
                ans.push_back(pair<int, int>(sx, sy));
                while (id)
                {
                    ans.push_back(pair<int, int>(steps[id].x, steps[id].y));
                    id = steps[id].pre;
                }
                print();
                return;
            }
            // 旋转筛子
            pair<int, int> tmp = rotate(tp.t, tp.f, i);
            int nt = tmp.first, nf = tmp.second;
            if (vis[nx][ny][nt][nf]) continue;
            steps[++cnt] = Node(nx, ny, nt, nf, id);
            q.push(cnt);
            vis[nx][ny][nt][nf] = 1;
        }
    }
    cout << "  No Solution Possible" << endl;
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif

    to[1][2] = 4; to[1][3] = 2; to[1][4] = 5; to[1][5] = 3;
    to[2][1] = 3; to[2][3] = 6; to[2][4] = 1; to[2][6] = 4;
    to[3][1] = 5; to[3][2] = 1; to[3][5] = 6; to[3][6] = 2;
    to[4][1] = 2; to[4][2] = 6; to[4][5] = 1; to[4][6] = 5;
    to[5][1] = 4; to[5][3] = 1; to[5][4] = 6; to[5][6] = 3;
    to[6][2] = 3; to[6][3] = 5; to[6][4] = 2; to[6][5] = 4;
    string T;
    while (cin >> T && T[0] != 'E')
    {
        memset(maze, 0, sizeof(maze));
        ans.clear();
        cout << T << endl;
        cin >> r >> c >> sx >> sy >> st >> sf;
        for (int i = 1; i <= r; ++i)
        {
            for (int j = 1; j <= c; ++j)
            {
                cin >> maze[i][j];
            }
        }
        bfs();
    }
    return 0;
}