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

int in[30], out[30];

int g[30][30];
int in_g[30];
int vis[30];

void dfs(int i)
{
    vis[i] = 1;
    for (int j = 0; j < 26; ++j)
    {
        if (g[i][j] && !vis[j]) dfs(j);
    }
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    int Case; cin >> Case;
    while (Case--)
    {
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(g, 0, sizeof(g));
        memset(in_g, 0, sizeof(in_g));
        memset(vis, 0, sizeof(vis));
        int n; cin >> n;
        string str;
        while (n--)
        {
            cin >> str;
            int u = *(str.begin()) - 'a', v = *(str.rbegin()) - 'a';
            ++out[u]; ++in[v];
            in_g[u] = in_g[v] = 1;
            if(u != v) g[u][v] = g[v][u] = 1;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (in_g[i])
            {
                dfs(i);
                break;
            }
        }
        bool is_direct = true;
        for (int i = 0; i < 26; ++i)
        {
            if (in_g[i] && !vis[i])
            {
                is_direct = false;
                break;
            }
        }
        if (!is_direct)
        {
            cout << "The door cannot be opened." << endl;
        }
        else
        {
            vector<int> degree_illegal;
            for (int i = 0; i < 26; ++i)
            {
                if (in[i] != out[i]) degree_illegal.push_back(i);
            }
            if (degree_illegal.size() != 0 && degree_illegal.size() != 2)
            {
                cout << "The door cannot be opened." << endl;
            }
            else if (degree_illegal.size() == 0)
            {
                cout << "Ordering is possible." << endl;
            }
            else
            {
                int f = degree_illegal[0], s = degree_illegal[1];
                if (in[f] - out[f] == 1 && out[s] - in[s] == 1 || out[f] - in[f] == 1 && in[s] - out[s] == 1)
                {
                    cout << "Ordering is possible." << endl;
                }
                else
                {
                    cout << "The door cannot be opened." << endl;
                }
            }

        }

    }
    return 0;
}
