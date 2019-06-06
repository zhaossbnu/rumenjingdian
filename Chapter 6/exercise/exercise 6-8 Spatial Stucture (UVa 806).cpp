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

const int N = 70;

#define OTHER -1
#define WHITE 0
#define BLACK 2
#define GRAY 1

#define NW 1
#define NE 2
#define SW 3
#define SE 4

struct Node
{
    int type;
    Node *nw, *ne, *sw, *se;
    Node(int type = OTHER) : type(type), nw(NULL), ne(NULL), sw(NULL), se(NULL) {}
};

int g[N][N];
int n;
vector<int> code;

// 根据黑白图建树
Node * build(int x, int y, int sz)
{
    Node *root = new Node();
    int cnt_w = 0, cnt_b = 0;
    for (int i = x; i <= x + sz - 1; ++i)
    {
        for (int j = y; j <= y + sz - 1; ++j)
        {
            if (g[i][j] == 0) ++cnt_w;
            else ++cnt_b;
        }
    }
    if (cnt_w == 0) root->type = BLACK;
    else if (cnt_b == 0) root->type = WHITE;
    else
    {
        root->type = GRAY;
        int nsz = sz >> 1;
        root->nw = build(x, y, nsz);
        root->ne = build(x, y + nsz, nsz);
        root->sw = build(x + nsz, y, nsz);
        root->se = build(x + nsz, y + nsz, nsz);
    }
    return root;
}

// 释放树内存
void del(Node *root)
{
    if (root == NULL) return;
    del(root->nw); del(root->ne); del(root->sw); del(root->se);
    delete(root);
}

int mypow(int a, int b)
{
    if (b == 0) return 1;
    int rs = 1;
    for (int i = 1; i <= b; ++i) rs *= a;
    return rs;
}

// 根据树获取黑点值
vector<int> bfs(Node * root)
{
    vector<int> ans;
    // 第一个int是当前的值 第二个int是层次数
    queue<pair<Node*, pair<int, int>>> q;
    q.push({ root, {0, 0} });
    while (!q.empty())
    {
        pair<Node*, pair<int, int>> t = q.front(); q.pop();
        if (t.first->type == BLACK) ans.push_back(t.second.first);
        if (t.first->nw != NULL) q.push({ t.first->nw, { t.second.first + 1 * mypow(5, t.second.second), t.second.second + 1 } });
        if (t.first->ne != NULL) q.push({ t.first->ne, { t.second.first + 2 * mypow(5, t.second.second), t.second.second + 1 } });
        if (t.first->sw != NULL) q.push({ t.first->sw, { t.second.first + 3 * mypow(5, t.second.second), t.second.second + 1 } });
        if (t.first->se != NULL) q.push({ t.first->se, { t.second.first + 4 * mypow(5, t.second.second), t.second.second + 1 } });
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// 利用一个数字填树
void rebuild(Node *root, int i)
{
    if (i == 0) return;
    if (i % 5 == NW)
    {
        if (i / 5 == 0) root->nw = new Node(BLACK);
        else
        {
            if (root->nw == NULL) root->nw = new Node(GRAY);
            rebuild(root->nw, i / 5);
        }
    }
    else if (i % 5 == NE)
    {
        if (i / 5 == 0) root->ne = new Node(BLACK);
        else
        {
            if (root->ne == NULL) root->ne = new Node(GRAY);
            rebuild(root->ne, i / 5);
        }
    }
    else if (i % 5 == SW)
    {
        if (i / 5 == 0) root->sw = new Node(BLACK);
        else
        {
            if (root->sw == NULL) root->sw = new Node(GRAY);
            rebuild(root->sw, i / 5);
        }
    }
    else if (i % 5 == SE)
    {
        if (i / 5 == 0) root->se = new Node(BLACK);
        else
        {
            if(root->se == NULL) root->se = new Node(GRAY);
            rebuild(root->se, i / 5);
        }
    }

}

// 将树中原来的白点填好
void format(Node * root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *t = q.front(); q.pop();
        if (t->type == GRAY)
        {
            if (t->nw == NULL) t->nw = new Node(WHITE);
            else if (t->nw->type == GRAY) q.push(t->nw);
            if (t->ne == NULL) t->ne = new Node(WHITE);
            else if (t->ne->type == GRAY) q.push(t->ne);
            if (t->sw == NULL) t->sw = new Node(WHITE);
            else if (t->sw->type == GRAY) q.push(t->sw);
            if (t->se == NULL) t->se = new Node(WHITE);
            else if (t->se->type == GRAY) q.push(t->se);
        }
    }
}

// 利用数组重建树
Node * rebuild(vector<int> &v)
{
    if (v.empty()) return new Node(WHITE);
    if (v.size() == 1 & v[0] == 0) return new Node(BLACK);
    Node * root = new Node(GRAY);
    for (int i : v) rebuild(root, i);
    format(root);
    return root;
}

// 将树的情况反映在黑白图中
void print_to_g(Node * root, int x, int y, int sz)
{
    if (root == NULL) return;
    if (root->type == BLACK || root->type == WHITE)
    {
        for (int i = x; i <= x + sz - 1; ++i)
            for (int j = y; j <= y + sz - 1; ++j)
                g[i][j] = root->type;
    }
    else if (root->type == GRAY)
    {
        int nsz = sz >> 1;
        print_to_g(root->nw, x, y, nsz);
        print_to_g(root->ne, x, y + nsz, nsz);
        print_to_g(root->sw, x + nsz, y, nsz);
        print_to_g(root->se, x + nsz, y + nsz, nsz);
    }
}


int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    int T = 0;
    while (cin >> n && n)
    {
        printf("Image %d\n", ++T);
        memset(g, -1, sizeof(g));
        if (n > 0)
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    scanf("%1d", &g[i][j]);
                }
            }
            Node * root = build(1, 1, n);
            vector<int> ans = bfs(root);
            if (ans.size() > 0)
            {
                for (int i : ans) printf("%d ", i);
                printf("\n");
            }
            printf("Total number of black nodes = %d\n\n", ans.size());
            del(root);
        }
        else
        {
            code.clear();
            n = -n;
            int tmp;
            while (cin >> tmp && tmp != -1) code.push_back(tmp);
            Node * root = rebuild(code);
            print_to_g(root, 1, 1, n);
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    cout << (g[i][j] ? '*' : '.');
                }
                cout << endl;
            }    
            cout << endl;
            del(root);
        }
    }
    return 0;
}


