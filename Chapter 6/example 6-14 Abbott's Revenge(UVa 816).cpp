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

struct State
{
    int x, y;
    int dir;
    State(int x = 0, int y = 0, int dir = -1) :x(x), y(y), dir(dir) {}
};


map<char, int> dirs = { {'N', 0}, {'E', 1}, {'S', 2}, {'W', 3} };
map<char, int> turns = { { 'F', 0 },{ 'L', 1 },{ 'R', 2 } };

const int mov[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int can[4][4][4][3]; // 每一个位置根据来的方向可以如何走

int vis[4][4][4]; //某一位的某一方向是否走过
State fa[4][4][4]; // 前一个节点



State walk(State &a, int turn)
{
    State b;
    if (turn == 0) b.dir = a.dir;
    else if (turn == 1) b.dir = (a.dir + 3) % 4;
    else if (turn == 2) b.dir = (a.dir + 1) % 4;

    b.x = a.x + mov[b.dir][0];
    b.y = a.y + mov[b.dir][1];
    return b;
}


void print(State ans)
{
    vector<State> sts;
    while (true)
    {
        sts.push_back(ans);
        if (vis[ans.x][ans.y][ans.dir] == 0) break;
        ans = fa[ans.x][ans.y][ans.dir];
    }
    for (auto it = sts.rbegin(); it != sts.rend(); ++it)
    {
        printf("(%d,%d)\n", it->x, it->y);
    }
}


int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    string maze_name;
    while (cin >> maze_name && maze_name != "END")
    {
        memset(can, 0, sizeof(can));
        memset(vis, -1, sizeof(vis));
        cout << maze_name << endl;
        string line;
        int start_x, start_y, end_x, end_y;
        char start_d;
        cin >> start_x >> start_y >> start_d >> end_x >> end_y;
        State st(start_x + mov[dirs[start_d]][0], start_y + mov[dirs[start_d]][1], dirs[start_d]);

        while (getline(cin, line) && line != "0")
        {
            istringstream iss(line);
            int x, y; iss >> x >> y;
            string t;
            while (iss >> t && t != "*")
            {
                for (int i = 1; i < t.size(); ++i)
                {
                    can[x][y][dirs[t[0]]][turns[t[i]]] = 1;
                }
            }
        }
        queue<State> q; q.push(st);
        vis[st.x][st.y][st.dir] = 1;
        while (!q.empty())
        {
            State t = q.front();
            q.pop();
            if (t.x == end_x && t.y == end_y)
            {
                printf("(%d,%d)\n", start_x, start_y);
                print(t);  
                break;
            }
            for (int i = 0; i < 3; ++i)
            {
                if (can[t.x][t.y][t.dir][i])
                {
                    State nxt = walk(t, i);
                    if (nxt.x >= 1 && nxt.x <= 3 && nxt.y >= 1 && nxt.y <= 3 && vis[nxt.x][nxt.y][nxt.dir] < 0)
                    {
                        vis[nxt.x][nxt.y][nxt.dir] = vis[t.x][t.y][t.dir] + 1;
                        fa[nxt.x][nxt.y][nxt.dir] = t;
                        q.push(nxt);
                    }
                }
            }     
        }
    }
    return 0;
}
