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

int main(void)
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    while (cin >> n)
    {
        cout << "------------------------------------------------------------" << endl;
        int M = 0;
        vector<string> files(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> files[i];
            M = max(M, (int)files[i].size());
        }
        sort(files.begin(), files.end());
        int col = (60 - M) / (M + 2) + 1;
        int row = (n - 1) / col + 1;
        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < col; ++c)
            {
                int index = c * row + r;
                if (index < n)
                {
                    if (c == col - 1)
                    {
                        cout << files[index];
                    }
                    else
                    {
                        cout << files[index] + string(M - files[index].size(), ' ') << "  ";
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}

