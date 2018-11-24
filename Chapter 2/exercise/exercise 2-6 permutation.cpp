#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    for(int abc= 123; abc <= 345; ++abc)
    {
        bool visit[10] ={false};
        visit[abc / 100] = visit[abc / 10 % 10] = visit[abc % 10] = true;
        int def = abc * 2;
        visit[def / 100] = visit[def / 10 % 10] = visit[def % 10] = true;
        int ghi = abc * 3;
        visit[ghi / 100] = visit[ghi / 10 % 10] = visit[ghi % 10] = true;
        bool flag = true;
        for(int i = 1; i <= 9; ++i)
        {
            if(!visit[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << abc << " " << def << " " << ghi << endl;
        }
    }
    return 0;
}
