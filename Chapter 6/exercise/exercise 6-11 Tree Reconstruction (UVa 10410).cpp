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



const int N = 1010;

int b[N], d[N];
int n;

vector<int> g[N];

void build()
{
    int root = d[1];
    // 栈是用来模拟dfs过程
    stack<int> st; st.push(root);
    for (int i = 2; i <= n; ++i)
    {
        while (true)
        {
            int x = st.top(), y = d[i];
            // b[x] + 1 < b[y] 说明dfs走到当前节点时 当前节点的bfs序 + 1 <<< 下一个节点的bfs序 说明 y一定是x的孩子而不是兄弟
            // b[x] + 1 == b[y] 说明dfs走到当前节点时 当前节点的bfs序 + 1 = 下一个节点的bfs序 
            // 此时如果当前节点的值比下一个节点大 则说明 y一定是x的孩子而不是兄弟 
            // 假设 x和y是兄弟 那么既然x > y 那么b[x] > b[y] 与b[x] + 1 == b[y]矛盾
            if (b[x] + 1 < b[y] || (b[x] + 1 == b[y] && x > y) || x == root)
            {
                g[x].push_back(y);
                st.push(y);
                break;  
            }
            else // 两种情况 第一x已经没有后代 第二 y是x的兄弟
            {
                st.pop();
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
    while (cin >> n)
    {
        for (int i = 1; i <= n; ++i) g[i].clear();
        int t;
        for (int i = 1; i <= n; ++i) cin >> t, b[t] = i;
        for (int i = 1; i <= n; ++i) cin >> d[i];
        build();
        for (int i = 1; i <= n; ++i)
        {
            printf("%d:", i);
            for (auto j : g[i]) printf(" %d", j);
            puts("");
        }
    }
    return 0;
}


