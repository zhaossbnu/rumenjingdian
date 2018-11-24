#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    string str1;
    string str2;
    while(cin >> str1 >> str2 && str1 != "-1")
    {
        bool flag = true;
        int a[26] = {0}, b[26] = {0};
        for(int i = 0 ; i < str1.size(); ++i)
        {
            ++a[str1[i] - 65];
            ++b[str2[i] - 65];
        }
        sort(a, a + 26);
        sort(b, b + 26);
        for(int i = 0; i < 26; ++i)
        {
            if(a[i] != b[i])
            {
                flag = false;
            }
        }
        if(flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
