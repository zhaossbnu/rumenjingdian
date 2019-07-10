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


int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif
    int n, T = 0;
    while (cin >> n && n)
    {
        if (T++) puts("");
        bool flag = false;
        for (int j = 1234; j <= 98765; ++j)
        {
            int i = j * n;
            ostringstream oss;
            oss << setw(5) << setfill('0') << i << setw(5) << setfill('0') << j;
            string str = oss.str();
            if (str.size() > 10) break;
            sort(str.begin(), str.end());
            bool ok = true;
            for (int i = 0; i < 10; ++i)
            {
                if (str[i] - '0' != i) { ok = false; break; }
            }
            if (ok)
            {
                flag = true;
                printf("%05d / %05d = %d\n", i, j, n);
            }
        }
        if (!flag) printf("There are no solutions for %d.\n", n);
    }
    return 0;
}