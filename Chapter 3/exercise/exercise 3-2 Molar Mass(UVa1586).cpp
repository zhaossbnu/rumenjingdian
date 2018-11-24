#include <bits/stdc++.h>

using namespace std;

double mass(char ch)
{
    if(ch == 'C')
        return 12.01;
    else if (ch == 'H')
        return 1.008;
    else if (ch == 'O')
        return 16;
    else if (ch == 'N')
        return 14.01;
    else
        return 0;
}

int main(void)
{
    string str;
    cin >> str;
    double last_molar = 0;
    double total = 0;
    for(int i = 0; i < str.size(); ++i)
    {
        if(mass(str[i]))
        {
            total += last_molar;
            last_molar = mass(str[i]);
        }
        else
        {
            total += (last_molar * (str[i] - '0'));
            last_molar = 0;
        }
    }
    cout << total << endl;
    return 0;
}
