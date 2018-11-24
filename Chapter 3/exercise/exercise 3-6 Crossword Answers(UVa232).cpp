#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int r, c;
    cin >> r >> c;
    vector<string> ch(r);
    getchar();
    for(int i = 0; i < r; ++i)
    {
        getline(cin, ch[i]);
    }
    vector<vector<int> > mark(r + 2);
    for(int i = 0; i < r + 2; ++i)
    {
        mark[i].resize(c + 2);
    }
    int index = 0;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(ch[i][j] == '*')
            {
                mark[i + 1][j + 1] = 0;
            }
            else if(mark[i][j + 1] == 0 || mark[i + 1][j] == 0)
            {
                mark[i + 1][j + 1] = ++index;
            }
            else
            {
                mark[i + 1][j + 1] = -1;
            }
        }
    }
    cout << "Across";
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(mark[i + 1][j + 1] != 0)
            {
                if(mark[i + 1][j] == 0)
                {
                    printf("\n%3d.%c", mark[i + 1][j + 1], ch[i][j]);
                }
                else
                {
                    cout << ch[i][j];
                }
            }
        }
    }
    cout << endl << "Down";
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(mark[i + 1][j + 1] > 0 && mark[i][j + 1] == 0)
            {
                printf("\n%3d.%c", mark[i + 1][j + 1], ch[i][j]);
                for(int k = i + 1; k < r; ++k)
                {
                    if(mark[k + 1][j + 1] != 0)
                    {
                        cout << ch[k][j];
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
