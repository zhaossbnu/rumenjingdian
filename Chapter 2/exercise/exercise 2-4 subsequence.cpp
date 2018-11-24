#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long n, m;
    while(cin >> n >> m && n !=0 && m != 0)
    {
        double s = 0;
        for(long long i = n; i <= m; ++i)
        {
            s += 1.0 / (i * i);
        }
        cout << fixed << setprecision(5) << s << endl;
    }
    return 0;
}
