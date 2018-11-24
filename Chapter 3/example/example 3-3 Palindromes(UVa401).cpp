#include <bits/stdc++.h>

using namespace std;

string rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {" -- is not a palindrome", " -- is a regular palindrome", " -- is a mirrored string", " -- is a mirrored palindrome"};

char r(char ch)
{
    if(isalpha(ch))
        return rev[ch - 'A'];
    else
        return rev[ch - '0' + 25];
}

int main(void)
{

    string str;
    while(cin >> str)
    {
        int p = 1, m = 1;
        int len = str.size();
        for(int i = 0; i <= len / 2; ++i)
        {
            if(str[i] != str[len - 1 - i])
            {
                p = 0;
            }
            if(r(str[i]) != str[len - 1 - i])
            {
                m = 0;
            }
        }
        cout << str << msg[2 * m + p] << endl;
    }
    return 0;
}
