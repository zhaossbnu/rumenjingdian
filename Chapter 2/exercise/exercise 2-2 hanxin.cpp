#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b, c;
    int Case = 1;
    while(cin >> a >> b >> c)
    {
        int i;
        for(i = 10; i <= 100; ++i)
        {
            if(i % 3 == a && i % 5 == b && i % 7 == c)
            {
                cout << "Case " << Case++ << ": " << i << endl;
                break;
            }
        }
        if(i > 100)
        {
            cout << "Case " << Case++ << ": No answer" << endl;
        }
    }
    return 0;
}
