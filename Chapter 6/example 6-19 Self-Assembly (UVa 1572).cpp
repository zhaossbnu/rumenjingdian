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

const int N = 60;
int g[N][N];

int in[N];
int vis[N];

int id(char a1, char a2)
{
    return (a1 - 'A') * 2 + (a2 == '+' ? 0 : 1);
}

// 例如a1a2为A+ b1b2为B+
// 则A+可以通过本正方形的B+连接到其他正方形的B-
// 通过这种粘合 如果B-通过粘合若干个正方形再次能连到A+
// 此时说明中间的粘合序列可以无限重复
void edge(char a1, char a2, char b1, char b2)
{
    if (a1 == '0' || b1 == '0') return;
    int x = id(a1, a2), y = id(b1, b2) ^ 1;
    g[x][y] = 1;
}

void cal()
{
    memset(in, 0, sizeof(in));
    for (int i = 0; i < 52; ++i)
    {
        for (int j = 0; j < 52; ++j)
        {
            if (g[i][j]) ++in[j];
        }
    }
}

void bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    for (int i = 0; i < 52; ++i)
    {
        if (in[i] == 0) q.push(i), vis[i] = 1;
    }
    while (!q.empty())
    {
        int t = q.front(); q.pop();
        for (int j = 0; j < 52; ++j)
        {
            if (g[t][j] == 1 && !vis[j])
            {
                --in[j];
                if (in[j] == 0) q.push(j), vis[j] = 1;
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
    int n;
    while (cin >> n)
    {
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= n; ++i)
        {
            string str;
            cin >> str;
            for (int j = 0; j < 4; ++j)
            {
                for (int k = 0; k < 4; ++k)
                {
                    if (j != k)
                    {
                        edge(str[j * 2], str[j * 2 + 1], str[k * 2], str[k * 2 + 1]);
                    }
                }
            }
        }
        cal();
        bfs();
        bool flag = 1;
        for (int i = 0; i < 52; ++i)
        {
            if (!vis[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag) cout << "bounded" << endl;
        else cout << "unbounded" << endl;
    }
    return 0;
}


