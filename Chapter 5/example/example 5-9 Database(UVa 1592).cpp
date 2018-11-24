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
using namespace std;
string db[10010][12];
int main(void)
{
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n, m;
    while (cin >> n >> m)
    {
        getchar();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m-1; ++j)
            {
                getline(cin, db[i][j], ',');
            }
            getline(cin, db[i][m]);
        }
        map<pair<string, string>, int> table;
        bool found = false;
        for (int c1 = 1; c1 <= m - 1; ++c1)
        {
            for (int c2 = c1 + 1; c2 <= m; ++c2)
            {
                for (int r = 1; r <= n; ++r)
                {
                    if (table.find(pair<string, string>(db[r][c1], db[r][c2])) != table.end())
                    {
                        cout << "NO" << endl;
                        cout << table[pair<string, string>(db[r][c1], db[r][c2])] << " " << r << endl;
                        cout << c1 << " " << c2 << endl;
                        found = true;
                    }
                    else
                    {
                        table[pair<string, string>(db[r][c1], db[r][c2])] = r;
                    }
                }
                
            }
        }
        if (!found)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}

