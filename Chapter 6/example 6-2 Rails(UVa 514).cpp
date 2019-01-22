#include <bits/stdc++.h>

using namespace std;


int main(void)
{
    freopen("input.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> result(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> result[i];
    }
    int a = 1, b = 1;
    bool flag = false;
    stack<int> s;
    while(b <= n)
    {
        if(a == result[b])
        {
            ++a, ++b;
        }
        else if(!s.empty() && s.top() == result[b])
        {
            s.pop();
            ++b;
        }
        else if(a <= n)
        {
            s.push(a++);
        }
        else
        {
            flag = true;
        }
    }
    cout << (flag ? "No" : "Yes") << endl;
    return 0;
}
