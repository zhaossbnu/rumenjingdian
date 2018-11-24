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
using namespace std;


int main(void)
{
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    string line;
    vector<string> str[1000];
    int rows = 0;
    int cols = 0;
    while (getline(cin, line))
    {
        istringstream iss(line);
        string t;
        while (iss >> t)
        {
            str[rows].push_back(t);
        }
        if (cols < str[rows].size())
        {
            cols = str[rows].size();
        }
        ++rows;
        
    }
    vector<int> col_size(cols, 0);
    for (int j = 0; j < cols; ++j)
    {
        for (int i = 0; i < rows; ++i)
        {
            if (str[i].size() - 1 >= j && col_size[j] < str[i][j].size())
            {
                col_size[j] = str[i][j].size();
            }
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < str[i].size() - 1; ++j)
        {
            cout << str[i][j] << string(col_size[j] - str[i][j].size(), ' ') << " ";
        }
        cout << *(str[i].rbegin()) << endl;
    }
    return 0;
}

