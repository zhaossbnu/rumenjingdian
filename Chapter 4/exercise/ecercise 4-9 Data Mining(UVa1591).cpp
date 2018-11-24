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
    long long n, sp, sq;
    while (cin >> n >> sp >> sq)
    {
        int a = 0, b = 0;
        long long k = (1LL << 62);
        for (int i = 0; i < 32; ++i)
        {
            for (int j = 0; j < 32; ++j)
            {
                // 第n位元素的位移 + 第n位元素的大小 也就是花费空间
                long long tk = (((n-1) * sp + (((n-1) * sp)<<i))>>j) + sq;
                if (tk >= n * sq)
                {
                    if (k > tk)
                    {
                        k = tk;
                        a = i;
                        b = j;
                    }
                }
            }
        }
        cout << k << " " << a << " " << b << endl;
    }
    return 0;
}