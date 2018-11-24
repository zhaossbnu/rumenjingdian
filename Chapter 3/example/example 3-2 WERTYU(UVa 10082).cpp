#include <bits/stdc++.h>

using namespace std;

string table = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
int main(void)
{
    string str;
    getline(cin, str);
    for(int i = 0; i < str.size(); ++i)
    {
        int loc = table.find(str[i]);
        if(loc != string::npos)
        {
            cout << table[loc - 1];
        }
        else
        {
            cout << str[i];
        }

    }
    return 0;
}
