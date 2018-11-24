#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a[10] = {0};
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int t = i;
        while(t != 0)
        {
            ++a[t % 10];
            t /= 10;
        }
    }
    for(int i = 0; i <= 9; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}
