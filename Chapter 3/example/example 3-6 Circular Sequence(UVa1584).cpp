#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        int ans = 0;
        int len = str.size();
        for(int i = 1; i < len; ++i)
        {
            for(int j = 0; j < len; ++j)
            {
                if(str[(i + j) % len] != str[(ans + j) % len])
                {
                    if(str[(i + j) % len] < str[(ans + j) % len])
                    {
                        ans = i;
                    }
                    break;
                }
            }
        }
        for(int i = 0; i < len; ++i)
        {
            cout << str[(ans + i) % len];
        }
        cout << endl;
    }
    return 0;
}
