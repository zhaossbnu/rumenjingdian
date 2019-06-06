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

const int N = 210;
char buf[N][N];

int n = 0;

void dfs(int i, int j)
{
    cout << buf[i][j] << "(";
    if (i + 1 < n && buf[i + 1][j] == '|')
    {
        int left = j, right = j;
        while (left - 1 >= 0 && buf[i + 2][left - 1] == '-') --left;
        while (buf[i + 2][right + 1] == '-') ++right;
        for (int k = left; k <= right; ++k)
        {
            if (buf[i + 3][k] != ' ') dfs(i + 3, k);
        }
    }
    cout << ")";
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    int Case; cin >> Case;
    getchar();
    while (Case--)
    {
        memset(buf, ' ', sizeof(buf));
        n = 0;
        while (true)
        {
            cin.getline(buf[n], N);
            if (buf[n][0] == '#') break;
            else ++n;
        }
        cout << "(";
        if (n)
        {
            for (int i = 0; i < strlen(buf[0]); ++i)
            {
                if (buf[0][i] != ' ')
                {
                    dfs(0, i);
                    break;
                }
            }
        }
        cout << ")" << endl;
    }
    return 0;
}
