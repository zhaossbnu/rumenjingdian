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

map<long long, int> m;
int cnt = 0;

void build(string str, int dp)
{
    if (str[0] == '[') // 是一棵树
    {
        int p = 0;
        for (int i = 1; i <= str.size(); ++i)
        {
            if (str[i] == '[') ++p;
            if (str[i] == ']') --p;
            // 如果之前已经走过了一棵树 而且当前符号是,
            // 说明前后两个子串就是本树的左右子树
            if (p == 0 && str[i] == ',')
            {
                build(str.substr(1, i - 1), dp + 1);
                build(str.substr(i + 1, str.size() - i - 2), dp + 1);
            }
        }
    }
    else // 是数字
    {
        istringstream iss(str);
        int num; iss >> num;
        ++m[num << dp];
        ++cnt;
    }
}


int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    int T; cin >> T;
    getchar();
    while (T--)
    {
        m.clear();
        cnt = 0;
        string line; getline(cin, line);
        build(line, 0);
        int max_c = 0;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            max_c = max(max_c, it->second);
        }
        cout << cnt - max_c << endl;
    }
    return 0;
}


