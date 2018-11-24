#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Stu
{
    int a, b, c;
};

int main(void)
{
    int n;
    int Case = 0;
    while (cin >> n && n)
    {
        Stu stus[15];
        int sleep = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> stus[i].a >> stus[i].b >> stus[i].c;
            if (stus[i].c > stus[i].a)
            {
                ++sleep;
            }
        }
        int time = 1;
        while (++time <= 10000)
        {
            int t_sleep = sleep;
            for (int i = 1; i <= n; ++i)
            {
                if (stus[i].c == stus[i].a)
                {
                    if (sleep > n - sleep)
                    {
                        ++t_sleep;
                        ++stus[i].c;
                    }
                    else
                    {
                        stus[i].c = 1;
                    }
                }
                else if (stus[i].c > stus[i].a)
                {
                    if (stus[i].c == stus[i].a + stus[i].b)
                    {
                        stus[i].c = 1;
                        --t_sleep;
                    }
                    else
                    {
                        ++stus[i].c;
                    }
                }
                else if (stus[i].c < stus[i].a)
                {
                    ++stus[i].c;
                }
            }
            sleep = t_sleep;
            if (sleep == 0)
            {
                break;
            }
        }
        if (time <= 10000)
        {
            printf("Case %d: %d\n", ++Case, time);
        }
        else
        {
            printf("Case %d: %d\n", ++Case, -1);
        }
        
    }
    return 0;
}
