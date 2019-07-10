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

const int N = 10;
const int INF = 0x3f3f3f3f;

int g[N][N];

int n = 0;

map<char, int> ch2int;
char ch[N];

int vis[N];
int t[N],ans[N];
int mink = 0x3f3f3f3f;

void dfs(int cur, int cb)
{
    if (cur == n + 1)
    {
        if (cb < mink)
        {
            mink = cb;
            for (int i = 1; i <= n; ++i) ans[i] = t[i];
        }
        return;
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i]) continue;
            t[cur] = i;
            vis[i] = 1;
            int tcb = cb;
            for (int j = 1; j < cur; ++j)
            {
                if (g[i][t[j]])
                {
                    tcb = max(tcb, cur - j);
                }
            }
            if (tcb > mink)
            {
                vis[i] = 0;
                return;
            }
            dfs(cur + 1, tcb);
            vis[i] = 0;
        }
    }
}



int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif
    string line;
    while (getline(cin, line) && line[0] != '#')
    {
        memset(g, 0, sizeof(g));
        memset(ans, 0, sizeof(ans));
        memset(vis, 0, sizeof(vis));
        n = 0, mink = 0x3f3f3f3f;
        for (int i = 0; i < line.size(); ++i)
        {
            if (line[i] == ':' || line[i] == ';') line[i] = ' ';
            else
            {
                if (ch2int.find(line[i]) == ch2int.end())
                {
                    ++n;
                    ch2int[line[i]] = 0;
                }
            }
        }
        int i = 0;
        for (auto it = ch2int.begin(); it != ch2int.end(); ++it)
        {
            ++i;
            it->second = i;
            ch[i] = it->first;
        }
        istringstream iss(line);
        string t1, t2;
        while (iss >> t1 >> t2)
        {
            int x = ch2int[t1[0]];
            for (char y : t2) g[x][ch2int[y]] = 1, g[ch2int[y]][x] = 1;
        }
        dfs(1, 0);
        for (int i = 1; i <= n; ++i) cout << ch[ans[i]] << " ";
        cout << "-> " << mink << endl;
    }
    return 0;
}