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

struct Stu
{
    int a, b;
    Stu(int a = 0, int b = 0):a(a), b(b) { }
    bool operator<(const Stu & s) const
    {
        return a < s.a || (a == s.a && b < s.b);
    }
};

int main(void)
{
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    while (cin >> n && n)
    {
        map<Stu, int> table;
        Stu t;
        for (int i = 0; i < n; ++i)
        {
            cin >> t.a >> t.b;
            ++table[t];
        }
        while (table.size() != 0)
        {
            map<Stu, int>::iterator stu_a = table.begin();
            Stu t(stu_a->first.b, stu_a->first.a);
            map<Stu, int>::iterator stu_b = table.find(t);
            if (stu_b == table.end() || stu_b->second != stu_a->second)
            {
                cout << "NO" << endl;
                break;
            }
            table.erase(stu_a);
            table.erase(stu_b);
            if (table.size() == 0)
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}

