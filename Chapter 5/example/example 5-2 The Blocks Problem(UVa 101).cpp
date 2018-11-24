#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector<vector<int> > pile;

pair<int, int> find_loc(int num)
{
    for (size_t i = 0; i < pile.size(); ++i)
    {
        for (size_t j = 0; j < pile[i].size(); ++j)
        {
            if (pile[i][j] == num)
            {
                return pair<int, int>(i, j);
            }
        }
    }
}

void clear_block(const pair<int, int> &loc)
{
    for (size_t j = loc.second + 1; j < pile[loc.first].size(); ++j)
    {
        pile[pile[loc.first][j]].push_back(pile[loc.first][j]);
    }
    pile[loc.first].resize(loc.second + 1);
}

void pile_onto(const pair<int, int> &loca, const pair<int, int> &locb)
{
    for (size_t j = loca.second; j < pile[loca.first].size(); ++j)
    {
        pile[locb.first].push_back(pile[loca.first][j]);
    }
    pile[loca.first].resize(loca.second);
}


int main(void)
{
    int n;
    cin >> n;
    pile.resize(n);
    for (size_t i = 0; i < pile.size(); ++i)
    {
        pile[i].resize(0);
        pile[i].push_back(i);
    }
    string str1, str2;
    int a, b;
    while (cin >> str1 >> a >> str2 >> b && str1 != "quit")
    {
        pair<int, int> loca = find_loc(a);
        pair<int, int> locb = find_loc(b);
        if (loca.first != locb.first)
        {
            if (str2 == "onto")
            {
                clear_block(locb);
            }
            if (str1 == "move")
            {
                clear_block(loca);
            }
            pile_onto(loca, locb);
        }
    }
    for (size_t i = 0; i < pile.size(); ++i)
    {
        printf("%d:", i);
        for (size_t j = 0; j < pile[i].size(); ++j)
        {
            cout << pile[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}