#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    string str;
    while (getline(cin, str))
    {
        string ca = str.substr(0, 6);
        string cb = str.substr(6, 6);
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                if (cb[j] == ca[i])
                {
                    if (ca[5 - i] == cb[5 - j])
                    {
                        cb[j] = cb[5 - j] = ' ';
                        break;
                    }
                }
            }
        }
        if (cb == "      ")
        {
            cout << "TRUE" << endl;
        }
        else
        {
            cout << "FALSE" << endl;
        }
    }
    return 0;
}
