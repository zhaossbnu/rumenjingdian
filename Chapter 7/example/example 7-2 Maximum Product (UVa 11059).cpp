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

long long a[20];

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif
    int n, T = 0;;
    while (cin >> n)
    {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        long long ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            long long f = 1;
            for (int j = i; j <= n; ++j)
            {
                f *= a[j];
                ans = max(ans, f);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ++T, ans);
    }
    return 0;
}