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

typedef pair<int, int> PII;

int vis[10][10];
int ans[10][10];

int mov[8][2] = { {-1, -2},{1, -2},{2, -1},{2, 1},{1, 2},{-1, 2},{-2, 1},{-2, -1} };

bool inside(PII l)
{
    return l.first >= 1 && l.first <= 8 && l.second >= 1 && l.second <= 8;
}


void bfs(PII s, PII e)
{
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    queue<PII > q;
    q.push(s);
    vis[s.first][s.second] = 1;
    ans[s.first][s.second] = 0;
    while (!q.empty())
    {
        PII t = q.front(); q.pop();
        
        for (int i = 0; i < 8; ++i)
        {
            PII nt(t.first + mov[i][0], t.second + mov[i][1]);
            if (inside(nt) && !vis[nt.first][nt.second])
            {
                q.push(nt);
                vis[nt.first][nt.second] = 1;
                ans[nt.first][nt.second] = ans[t.first][t.second] + 1;
                if (nt == e) return;
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
    string st, ed;
    while (cin >> st >> ed)
    {
        PII s(st[0] - 'a' + 1, st[1] - '0');
        PII e(ed[0] - 'a' + 1, ed[1] - '0');
        bfs(s, e);
        printf("To get from %s to %s takes %d knight moves.\n", st.c_str(), ed.c_str(), ans[e.first][e.second]);
    }
    return 0;
}


