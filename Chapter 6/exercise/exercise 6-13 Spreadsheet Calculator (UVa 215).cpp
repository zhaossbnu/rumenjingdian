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

string tb[25][15];
int vis[25][15];
int circle[25][15];
int r, c;

int str2int(string str)
{
    int t;
    istringstream iss(str);
    iss >> t;
    return t;
}

void dfs(int row, int col)
{
    // 如果已经在环中或者本身是数字
    if (circle[row][col] || isdigit(tb[row][col][0])) return;
    // 本身不是数字而且以前曾经计算过但是没计算出来
    if (vis[row][col]) { circle[row][col] = 1; return; };
    vis[row][col] = 1;
    string str = tb[row][col];
    // 单操作数
    if (str.size() == 2)
    {
        dfs(str[0] - 'A', str[1] - '0');
        if(!circle[str[0] - 'A'][str[1] - '0']) tb[row][col] = tb[str[0] - 'A'][str[1] - '0'];
        else circle[row][col] = 1;
    }
    else // 两个操作数  要注意第二个操作数是数字还是单元格表示
    {
        dfs(str[0] - 'A', str[1] - '0');
        if(!isdigit(str[3])) dfs(str[3] - 'A', str[4] - '0');
        // 两个操作数必须能计算出来
        if (!circle[str[0] - 'A'][str[1] - '0'] && !circle[str[3] - 'A'][str[4] - '0'])
        {
            int l = str2int(tb[str[0] - 'A'][str[1] - '0']), r = 0;
            if (isdigit(str[3])) r = str2int(str.substr(3));
            else r = str2int(tb[str[3] - 'A'][str[4] - '0']);
            int res = (str[2] == '+' ? l + r : l - r);
            ostringstream os; os << res;
            tb[row][col] = os.str();
        }
        else
        {
            circle[row][col] = 1;
        }
        
    }
}


int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    while (cin >> r >> c && r && c)
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cin >> tb[i][j];
            }
        }
        bool flag = true;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (!vis[i][j]) dfs(i, j);
                if (circle[i][j]) flag = false;
            }
        }
        if (flag)
        {
            printf(" ");
            for (int j = 0; j < c; ++j) printf("%6d", j);
            puts("");
            for (int i = 0; i < r; ++i)
            {
                printf("%c", (char)('A' + i));
                for (int j = 0; j < c; ++j)
                {
                    printf("%6d", str2int(tb[i][j]));
                }
                puts("");
            }
        }
        else
        {
            for (int i = 0; i < r; ++i)
            {
                for (int j = 0; j < c; ++j)
                {
                    if (!isdigit(tb[i][j][0]))
                    {
                        printf("%c%c:%s\n", (char)('A' + i), (char)('0' + j), tb[i][j].c_str());
                    }
                }
            }

        }
        puts("");
    }
    return 0;
}


