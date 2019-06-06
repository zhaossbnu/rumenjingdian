#include <bits/stdc++.h>

using namespace std;

int buf[32][32], cnt, cur;

void dfs(string &s, int r, int c, int w)
{
    char ch = s[cur++];
    if(ch == 'p')
    {
        dfs(s, r, c + (w >> 1), w >> 1);
        dfs(s, r, c           , w >> 1);
        dfs(s, r + (w >> 1), c, w >> 1);
        dfs(s, r + (w >> 1), c + (w >> 1), w >> 1);

    }
    else if(ch == 'f')
    {
        for(int i = r; i < r + w; ++i)
        {
            for(int j = c; j < c + w; ++j)
            {
                if(buf[i][j] == 0) buf[i][j] = 1, ++cnt;
            }
        }
    }

}

int main(void)
{
    int Case; cin >> Case;
    while(Case --)
    {
        cnt = 0;
        memset(buf, 0, sizeof(buf));
        string line;
        cin >> line; cur = 0; dfs(line, 0, 0, 32);
        cin >> line; cur = 0; dfs(line, 0, 0, 32);
        printf("There are %d black pixels.\n", cnt);
    }
    return 0;
}


/*
input
3
ppeeefpffeefe
pefepeefe
peeef
peefe
peeef
peepefefe
output
There are 640 black pixels.
There are 512 black pixels.
There are 384 black pixels.
*/
