#include <bits/stdc++.h>

using namespace std;
int ans[100005] = {0};
int main(void)
{
    for(int i = 1; i <= 100005; ++i)
    {
        int x = i, y = i;
        while(x > 0)
        {
            y += x % 10;
            x /= 10;
        }
        if(ans[y]  == 0 || i < ans[y])
        {
            ans[y] = i;
        }
    }
    int n;
    cin >> n;
    while(n--)
    {
        int num;
        cin >> num;
        cout << ans[num] << endl;
    }
    return 0;
}
