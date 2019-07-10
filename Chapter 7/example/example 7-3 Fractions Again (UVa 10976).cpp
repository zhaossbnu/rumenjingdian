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
    int k, T = 0;;
    while (cin >> k)
    {
        vector<pair<int, int>> ans;
        for (int y = k + 1; y <= k << 1; ++y)
        {
            if ((k * y) % (y - k) == 0) ans.push_back({ (k * y) / (y - k), y });
        }
        cout << ans.size() << endl;
        for (auto i : ans) printf("1/%d = 1/%d + 1/%d\n", k, i.first, i.second);

    }
    return 0;
}