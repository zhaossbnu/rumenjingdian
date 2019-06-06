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

map<char, int> m = { {'(', -2},{')', 2},{'[', -1},{']', 1} };

bool judge(string &str)
{
    if (str.size() == 0) return true;
    stack<int> st;
    for (char ch : str)
    {
        if (st.empty()) st.push(m[ch]);
        else if (st.top() + m[ch] == 0) st.pop();
        else st.push(m[ch]);
    }
    return st.empty();
}


int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    int T; cin >> T;
    while (T--)
    {
        string str; cin >> str;
        cout << (judge(str) ? "Yes" : "No") << endl;
    }
    return 0;
}


