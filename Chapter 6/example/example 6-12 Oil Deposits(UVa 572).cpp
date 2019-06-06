#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
int m, n;

char pic[N][N];
int vis[N][N];
int ans  = 0;
int mov[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};


void dfs(int r, int c)
{
    if(r < 1 || r > m || c < 1 || c > n) return ;
    if(vis[r][c] || pic[r][c] == '*') return ;
    vis[r][c] = 1;
    for(int i = 0; i < 8; ++i)
    {
        dfs(r + mov[i][0], c + mov[i][1]);
    }
}

int main(void)
{
    while(cin >> m >> n && m != 0 && n != 0)
    {
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j) cin >> pic[i][j];
        }
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(!vis[i][j] && pic[i][j] == '@') ++ans, dfs(i, j);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
input
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
output
0
1
2
2
*/
