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
using namespace std;

int main(void)
{
    set<string> dict;
    string str;
    while (cin >> str)
    {
        for (string::size_type i = 0; i < str.size(); ++i)
        {
            str[i] = isalpha(str[i]) ? tolower(str[i]) : ' ';
        }
        istringstream iss(str);
        while (iss >> str)
        {
            dict.insert(str);
        }   
    }
    for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}