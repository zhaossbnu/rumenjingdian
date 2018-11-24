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

string repr(const string &str)
{
    string ans = str;
    for (size_t i = 0; i < str.size(); ++i)
    {
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(void)
{
    freopen("linet.in", "r", stdin);
    string str;
    vector<string> words;
    map<string, int> cnt;
    while (cin >> str && str != "#")
    {
        words.push_back(str);
        str = repr(str);
        if (!cnt.count(str))
        {
            cnt[str] = 0;
        }
        ++cnt[str];
    }
    vector<string> ans;
    for (size_t i = 0; i < words.size(); ++i)
    {
        if (cnt[repr(words[i])] == 1)
        {
            ans.push_back(words[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (size_t i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << endl;
    }
    return 0;
}