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
using namespace std;

void set_map(map<string, string> &a, string str)
{
    str.pop_back();
    istringstream iss(str);
    char ch;
    iss >> ch;
    string para;
    while (getline(iss, para, ','))
    {
        int index = para.find(':');
        string key = para.substr(0, index);
        string value = para.substr(index + 1, para.size() - index - 1);
        if (value[0] != '-' && value[0] != '0' && value[0] != '+')
        {
            a[key] = value;
        }
    }
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif
    int n;
    cin >> n;
    getchar();
    for(int i = 1; i <= n; ++i)
    {
        if (i > 1)
        {
            cout << endl;
        }
        map<string, string> a, b;
        vector<string> add, del, change;
        string line;
        getline(cin, line);
        set_map(a, line);
        getline(cin, line);
        set_map(b, line);
        for (map<string, string>::iterator it = b.begin(); it != b.end(); ++it)
        {
            map<string, string>::iterator ait = a.find(it->first);
            if (ait == a.end())
            {
                a.insert(*it);
                add.push_back(it->first);
            }
            else
            {
                if (ait->second != it->second)
                {
                    ait->second = it->second;
                    change.push_back(ait->first);
                }
            }
        }
        for (map<string, string>::iterator it = a.begin(); it != a.end(); ++it)
        {
            map<string, string>::iterator bit = b.find(it->first);
            if (bit == b.end())
            {
                del.push_back(it->first);
            }
        }
        bool found = false;
        if (add.size())
        {
            found = true;
            cout << "+";
            cout << add[0];
            for (int j = 1; j < add.size(); ++j)
            {
                cout << "," << add[j];
            }
            cout << endl;
        }
        if (del.size())
        {
            found = true;
            cout << "-";
            cout << del[0];
            for (int j = 1; j < del.size(); ++j)
            {
                cout << "," << del[j];
            }
            cout << endl;
        }
        if (change.size())
        {
            found = true;
            cout << "*";
            cout << change[0];
            for (int j = 1; j < change.size(); ++j)
            {
                cout << "," << change[j];
            }
            cout << endl;
        }
        if (!found)
        {
            cout << "No changes" << endl;
        }
        
    }
    return 0;
}

