#include <bits/stdc++.h>
using namespace std;

// 注意199 1000 2的情况
int main(void)
{
    int wei[110] = {0};
    int a, b, c;
    while(cin >> a >> b >> c && a != 0 && b != 0 && c != 0)
    {
        if(a >= b)
        {
            cout << a / b << ".";
            a %= b;
        }
        else
        {
            cout << "0.";
        }
        for(int i = 1; i <= c + 1; ++i)
        {
            a *= 10;
            wei[i] = a / b;
            a %= b;
        }
        if(wei[c + 1] >= 5)
        {
            ++wei[c];
        }
        for(int i = c; i >= 2; --i)
        {
            if(wei[i] < 10)
            {
                break;
            }
            else
            {
                ++wei[i - 1];
                wei[i] %= 10;
            }
        }
        for(int i = 1; i <= c; ++i)
        {
            cout << wei[i];
        }
        cout << endl;
    }
    return 0;
}
