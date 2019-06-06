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

struct Node
{
    char ch;
    int l, r;
};

Node tree[N];

int cnt = 0;


int build(string pre, string mid)
{
    if (pre.size() == 0) return 0;
    Node rt;
    rt.ch = pre[0];
    int id = mid.find(rt.ch);
    rt.l = build(pre.substr(1, id), mid.substr(0, id));
    rt.r = build(pre.substr(id + 1, mid.size() - id), mid.substr(id + 1, mid.size() - id));
    ++cnt;
    tree[cnt] = rt;
    return cnt;

}

void dfs(int rt)
{
    if (rt == 0) return;
    dfs(tree[rt].l);
    dfs(tree[rt].r);
    cout << tree[rt].ch;
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    string line;
    while (getline(cin, line))
    {
        istringstream iss(line);
        string pre, mid; iss >> pre >> mid;
        int rt = build(pre, mid);
        dfs(rt);
        cout << endl;
    }
    return 0;
}


/*
int build(int pl, int pr, int ml, int mr)
{
    if (pr < pl) return 0;
    Node rt;
    rt.ch = pre[pl];
    int id = mid.find(rt.ch);
    rt.l = build(pl + 1, pl + id - ml, ml, id - 1);
    rt.r = build(pl + id - ml + 1, pr, id + 1, mr);
    ++cnt;
    tree[cnt] = rt;
    return cnt;

}
*/