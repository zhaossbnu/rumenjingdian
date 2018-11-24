#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int maxN = 15;

bool h[maxN][maxN] = { 0 }, v[maxN][maxN] = { 0 };
int sq[maxN] = { 0 };

int main(void)
{
    freopen("linet.in", "r", stdin);
    int n, m;
    int Case = 1;
    while (cin >> n >> m)
    {
        memset(h, 0, sizeof(h));
        memset(v, 0, sizeof(v));
        memset(sq, 0, sizeof(sq));
        if (Case > 1)
        {
            cout << endl;
            cout << "**********************************" << endl;
            cout << endl;
        }
        cout << "Problem #" << Case++ << endl << endl;
        for (int i = 1; i <= m; ++i)
        {
            char ch;
            int a, b;
            cin >> ch >> a >> b;
            ch == 'H' ? h[a][b] = true : v[b][a] = true;
        }
        for (int len = 1; len <= n; ++len)
        {
            for (int i = 1; i <= n - len; ++i)
            {
                for (int j = 1; j <= n - len; ++j)
                {
                    int sum = 0;
                    for (int k = j; k < j + len; ++k)
                    {
                        sum += h[i][k];
                        sum += h[i + len][k];
                    }
                    for (int k = i; k < i + len; ++k)
                    {
                        sum += v[k][j];
                        sum += v[k][j + len];
                    }
                    if (sum == len * 4)
                    {
                        ++sq[len];
                    }
                }
            }
        }
        bool found = false;
        for (int i = 1; i <= n; ++i)
        {
            if (sq[i])
            {
                found = true;
                printf("%d square (s) of size %d\n", sq[i], i);
            }
        }
        if (!found)
        {
            printf("No completed squares can be found.\n");
        }
    }
    return 0;
}