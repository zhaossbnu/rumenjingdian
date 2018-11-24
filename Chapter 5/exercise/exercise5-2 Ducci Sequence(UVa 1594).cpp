#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <stack>
#include <queue>
#include <iterator>
#include <cmath>
#include <numeric>
using namespace std;
int main(void)
{
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int Case;
    cin >> Case;
    while (Case--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i =0; i < n; ++i)
        {
            cin >> a[i];
        }
        set<vector<int> > s;
        s.insert(a);
        while (true)
        {
            int t = a[0];
            for (int i = 0; i < n - 1; ++i)
            {
                a[i] = abs(a[i] - a[i + 1]);
            }
            a[n - 1] = abs(a[n - 1] - t);
            if (accumulate(a.begin(), a.end(), 0) == 0)
            {
                cout << "ZERO" << endl;
                break;
            }
            if (s.count(a) != 0)
            {
                cout << "LOOP" << endl;
                break;
            }
            s.insert(a);
        }
        
    }
    return 0;
}

