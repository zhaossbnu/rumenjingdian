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
    set<string> s;
    vector<string> words;
    string t;
    while (cin >> t)
    {
        s.insert(t);
        words.push_back(t);
    }
    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it)
    {
        for (int i = 1; i < it->size(); ++i)
        {
            if (s.find(it->substr(0, i)) != s.end() && s.find(it->substr(i, it->size() - i)) != s.end())
            {
                cout << *it << endl;
            }
        }
    }
    return 0;
}

