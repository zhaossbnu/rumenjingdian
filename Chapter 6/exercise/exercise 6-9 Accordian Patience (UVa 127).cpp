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

deque<deque<string>> p;

bool match(string &s1, string &s2)
{
    if (s1[0] == s2[0] || s1[1] == s2[1]) return true;
    else return false;
}


void play()
{
    while (true)
    {
        int i = 0;
        while(i < p.size())
        {
            if (i - 3 >= 0 && match(p[i][0], p[i - 3][0]))
            {
                p[i - 3].push_front(p[i][0]);
                p[i].pop_front();
                if (p[i].empty()) p.erase(p.begin() + i);
                i = i - 3;
                break;
            }
            if (i - 1 >= 0 && match(p[i][0], p[i - 1][0]))
            {
                p[i - 1].push_front(p[i][0]);
                p[i].pop_front();
                if (p[i].empty()) p.erase(p.begin() + i);
                i = i - 1;
                break;
            }
            ++i;
        }
        if (i == p.size()) break;
    }
}

void print()
{
    cout << p.size() << " piles remaining:";
    for (int i = 0; i < p.size(); ++i) cout << " " << p[i].size();
    cout << endl;
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    while (true)
    {
        p.clear();
        p.resize(52);
        string tmp;
        for (int i = 0; i < 52; ++i)
        {
            cin >> tmp;
            if (tmp == "#") return 0;
            p[i].push_back(tmp);
        }
        play();
        print();
    }
    return 0;
}


