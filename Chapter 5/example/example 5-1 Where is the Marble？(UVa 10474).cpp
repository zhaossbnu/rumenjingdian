#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    freopen("linet.in", "r", stdin);
    int n, q;
    int Case = 0;
    while (cin >> n >> q && n && q)
    {
        printf("CASE# %d:\n", ++Case);
        int a[10000];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        while (q--)
        {
            int t;
            cin >> t;
            int loc = find(a, a + n, t) - a;
            if (loc == n)
            {
                printf("%d not found\n", t);
            }
            else
            {
                printf("%d found at %d\n", t, loc + 1);
            }
        }
    }

    return 0;
}