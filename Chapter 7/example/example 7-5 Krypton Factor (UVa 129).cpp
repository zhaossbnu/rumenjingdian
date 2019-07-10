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

int n, L;

int s[100];
int cnt = 0;
int dfs(int cur)
{
    // 每次只要能dfs说明找到了一个困难串
    if (cnt++ == n)
    {
        // 注意当前位置cur待填所以有效的串位置是0~cur-1
        for (int i = 0; i < cur; ++i) printf("%c", 'A' + s[i]);
        puts("");
        return 0;
    }
    else
    {
        // 在当前位置上填入每一个字符
        for (int i = 0; i < L; ++i)
        {
            s[cur] = i;
            bool hard = true;
            // 注意当前串的总长度为cur + 1
            for (int j = 1; j * 2 <= cur + 1; ++j)
            {
                // 判断是否对称
                bool equal = true;
                for (int k = 0; k < j; ++k)
                {
                    if (s[cur - k] != s[cur - j - k])
                    {
                        equal = false;
                        break;
                    }
                }
                // 如果对称 就说明不是困难串
                if (equal) { hard = false; break; }
            }
            // 如果当前是困难串 但不一定是第n小 所以继续向下搜索
            if (hard) if (!dfs(cur + 1)) return 0;
        }
        return 1;
    }
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif
    while (cin >> n >> L && n && L)
    {
        cnt = 0;
        memset(s, -1, sizeof(s));
        dfs(0);
    }
    return 0;
}