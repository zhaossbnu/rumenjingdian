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
using namespace std;

map<set<int>, int> ids;
vector<set<int>> sets;
int id(const set<int> &s) 
{
    if (ids.find(s) != ids.end())
    {
        return ids[s];
    }
    sets.push_back(s);
    ids[s] = sets.size() - 1;
    return ids[s];
}

int main(void)
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        stack<int> st;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string op;
            cin >> op;
            if (op == "PUSH")
            {
                st.push(id(set<int>()));
            }
            else if (op == "DUP")
            {
                st.push(st.top());
            }
            else
            {
                set<int> set1 = sets[st.top()];
                st.pop();
                set<int> set2 = sets[st.top()];
                st.pop();
                set<int> result;
                if (op == "UNION")
                {
                    set_union(set1.begin(), set1.end(), set2.begin(), set2.end() , inserter(result, result.begin()));
                }
                else if (op == "INTERSECT")
                {
                    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.begin()));
                }
                else if (op == "ADD") { result = set2; result.insert(id(set1)); }
                st.push(id(result));
            }
            cout << sets[st.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    return 0;
}

