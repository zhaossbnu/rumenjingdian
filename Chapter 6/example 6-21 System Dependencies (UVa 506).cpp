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

const int N = 10010;
map<string, int> mp;
string name[N];
// 邻接表 逆邻接表
vector<int> depend[N], depended[N];
int status[N];
int cnt = 0;
vector<int> installed;

int id(string &str)
{
    if (mp.find(str) == mp.end())
    {
        ++cnt;
        name[cnt] = str;
        mp[str] = cnt;
    }
    return mp[str];
}

void install(int item, int xian)
{
    if (!status[item])
    {
        for (int i = 0; i < depend[item].size(); ++i)
        {
            install(depend[item][i], 0);
        }
        cout << "   Installing " << name[item] << endl;
        status[item] = (xian ? 1 : 2);
        installed.push_back(item);
    }
}

void ls()
{
    cout << "LIST" << endl;
    for (int i = 0; i < installed.size(); ++i)
    {
        cout << "   " << name[installed[i]] << endl;
    }
}

bool needed(int item)
{
    for (int i = 0; i < depended[item].size(); ++i)
    {
        if (status[depended[item][i]]) return true;
    }
    return false;
}
void remove(int item, int xian)
{
    if ((xian || status[item] == 2) && !needed(item))
    {
        status[item] = 0;
        auto it = find(installed.begin(), installed.end(), item);
        installed.erase(it);
        cout << "   Removing " << name[item] << endl;
        for (int i = 0; i < depend[item].size(); ++i)
        {
            remove(depend[item][i], 0);
        }
    }
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    memset(status, 0, sizeof(status));
    string op;
    while (cin >> op)
    {
        if (op[0] == 'E')
        {
            cout << op << endl;
        }
        else if (op[0] == 'D')
        {
            cout << op;
            string item1; cin >> item1;
            int id1 = id(item1);
            cout << " " << item1;
            string line;  getline(cin, line);
            istringstream iss(line);
            string item2;
            while (iss >> item2)
            {
                cout << " " << item2;
                int id2 = id(item2);
                depend[id1].push_back(id2);
                depended[id2].push_back(id1);
            } 
            cout << endl;
        }
        else if (op[0] == 'I')
        {
            string soft; cin >> soft;
            cout << "INSTALL " << soft << endl;
            int sid = id(soft);
            if (status[sid]) cout << "   " << soft << " is already installed." << endl;
            else install(id(soft), 1);
        }
        else if (op[0] == 'R')
        {
            string soft; cin >> soft;
            cout << "REMOVE " << soft << endl;
            int sid = id(soft);
            if (!status[sid]) cout << "   " << soft << " is not installed." << endl;
            else if (needed(sid)) cout << "   " << soft << " is still needed." << endl;
            else remove(id(soft), 1);
        }
        else if (op[0] == 'L')
        {
            ls();
        }
    }
    return 0;
}


