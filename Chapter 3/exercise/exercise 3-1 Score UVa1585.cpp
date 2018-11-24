#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    int total = 0;
    int c_o = 0;
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == 'X')
        {
            c_o = 0;
        }
        else
        {
            total += (++c_o);
        }
    }
    cout << total << endl;
    return 0;
}
