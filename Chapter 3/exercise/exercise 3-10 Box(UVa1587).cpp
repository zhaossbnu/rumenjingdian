#include <bits/stdc++.h>

using namespace std;
int w[6], h[6];
int main(void)
{
    while(!cin.eof())
    {
        for(int i = 0; i < 6; ++i)
        {
            cin >> w[i] >> h[i];
            if(w[i] < h[i])
            {
                swap(w[i], h[i]);
            }

        }
        sort(w, w + 6);
        sort(h, h + 6);
        if(w[0] == w[1] && w[2] == w[5] && h[0] == h[3] && h[4] == h[5] && w[0] == h[5])
        {
            cout << "POSSIBLE" << endl;
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
