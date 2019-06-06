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


const int N = 110;

struct Node
{
    int in[N], out[N];
    bool active;
};


int np, nt, nf;
int p[N];
Node t[N];

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    int Case = 0;
    while (cin >> np && np)
    {
        ++Case;
        for (int i = 1; i <= np; ++i) cin >> p[i];
        cin >> nt;
        for (int i = 1; i <= nt; ++i)
        {
            memset(t[i].in, 0, sizeof(t[i].in));
            memset(t[i].out, 0, sizeof(t[i].out));
            int tmp; 
            while (cin >> tmp && tmp)
            {
                if (tmp > 0) ++t[i].out[tmp];
                else ++t[i].in[-tmp];
            }
            t[i].active = true;
            for (int j = 1; j <= np; ++j)
            {
                if (t[i].in[j] > p[j]) t[i].active = false;
            }
        }
        cin >> nf;
        int dead = 0;
        for (int i = 1; i <= nf; ++i)
        {
            int id = 0;
            for (int j = 1; j <= nt; ++j) if (t[j].active) id = j;
            if (id == 0) { dead = i; break; }
            for (int j = 1; j <= np; ++j)
            {
                if (t[id].in[j] > 0) p[j] -= t[id].in[j];
                if (t[id].out[j] > 0) p[j] += t[id].out[j];
            }
            for (int j = 1; j <= nt; ++j)
            {
                t[j].active = true;
                for (int k = 1; k <= np; ++k)
                {
                    if (t[j].in[k] > p[k]) t[j].active = false;
                }
            }
        }
        if (dead) printf("Case %d: dead after %d transitions\n", Case, dead - 1);
        else printf("Case %d: still live after %d transitions\n", Case, nf);
        
        printf("Places with tokens: ");
        for (int i = 1; i <= np; ++i) if (p[i] > 0) printf(" %d (%d)", i, p[i]);
        puts("\n\n");

    }
    return 0;
}


