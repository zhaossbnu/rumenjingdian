#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for(int i = 5; i >= 1; --i)
    {
        for(int j = 1; j <= n - i; ++j)
        {
            cout << " ";
        }
        for(int j = 1; j <= 2 * i - 1; ++j)
        {
            cout << "#";
        }
        cout << endl;
    }
    return 0;
}
