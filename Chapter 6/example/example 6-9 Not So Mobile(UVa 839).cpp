#include <bits/stdc++.h>

using namespace std;

bool legal(int &w)
{
    int wl, dl, wr, dr;
    cin >> wl >> dl >> wr >> dr;
    bool al = true, ar = true;
    if(!wl) al = legal(wl);
    if(!wr) ar = legal(wr);
    w = wl + wr;
    return al && ar && (wl * dl == wr * dr);
}

int main(void)
{
    int Case, w;
    cin >> Case;
    while(Case --)
    {
        if(legal(w)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

/*
input
1
0 2 0 4
0 3 0 1
1 1 1 1
2 4 4 2
1 6 3 2
output
YES
*/
