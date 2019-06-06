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

int bin(string &str)
{
    int ans = 0;
    int p = str.size() - 1;
    for (char ch : str)
    {
        if (ch == '1')
        {
            ans += pow(2, p);
        }
        --p;
    }
    return ans;
}



int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    int n, m;
    int T = 0;
    while (cin >> n && n)
    {
        getchar();
        if (T) cout << endl;
        printf("S-Tree #%d:\n", ++T);
        string str; getline(cin, str); getline(cin, str);
        int m; cin >> m;
        string op;
        for (int i = 1; i <= m; ++i)
        {
            cin >> op;
            cout << str[bin(op)];
        }
        cout << endl;
    }
    return 0;
}


