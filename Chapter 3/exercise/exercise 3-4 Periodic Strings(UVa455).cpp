#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    int len = str.size();
    for(int k = 1; k <= len; ++k)
    {
        if(len % k == 0)
        {
            int ok = true;
            for(int i = 1; i <=  len / k -1; ++i)
            {
                for(int j = 0; j <=  k -1; ++j)
                {
                    if(str[j] != str[i * k + j])
                    {
                        ok = false;
                    }
                }
            }
            if(ok)
            {
                cout << k << endl;
                return 0;
            }
        }
    }
    return 0;
}
