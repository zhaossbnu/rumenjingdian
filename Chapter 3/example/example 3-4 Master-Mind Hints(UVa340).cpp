#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    int game = 0;
    while(cin >> n && n)
    {
        printf("Game %d:\n", ++game);
        vector<int> right(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> right[i];
        }
        while(true)
        {
            vector<int> guess(n);
            int a = 0, b = 0;
            for(int i = 0; i< n; ++i)
            {
                cin >> guess[i];
                if(right[i] == guess[i])
                {
                    ++a;
                }
            }
            if(!guess[0])
            {
                break;
            }
            for(int i = 1; i <= 9; ++i)
            {
                int c1 = 0, c2 = 0;
                for(int j = 0; j < n; ++j)
                {
                    if(right[j] == i)
                    {
                        ++c1;
                    }
                    if(guess[j] == i)
                    {
                        ++c2;
                    }
                }
                b += min(c1, c2);
            }
            printf("    (%d,%d)\n", a, b - a);
        }
    }
    return 0;
}
