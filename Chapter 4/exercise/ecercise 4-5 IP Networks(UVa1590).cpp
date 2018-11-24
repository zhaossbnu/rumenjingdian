#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void print(int ip)
{
    cout << (ip >> 24 & 255) << "." << (ip >> 16 & 255) << "." << (ip >> 8 & 255) << "." << (ip & 255) << endl;
}

int main(void)
{
    freopen("linet.in", "r", stdin);
    int m;
    while (cin >> m)
    {
        vector<int> ips(m, 0);
        for (int i = 0; i < m; ++i)
        {
            cin >> ips[i];
            for (int j = 0; j < 3; ++j)
            {
                ips[i] = ips[i] << 8;
                char ch;
                int t;
                cin >> ch >> t;
                ips[i] += t;
            }
        }
        int mask = 0xffffffff;
        for (int i = 0; i < m; ++i)
        {
            mask = mask & ~(ips[0] ^ ips[i]);
        }
        print(mask);
        print(mask & ips[0]);
    }
    return 0;
}