#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <stack>
#include <queue>
#include <iterator>
#include <cmath>
#include <numeric>
using namespace std;

struct Job
{
    int id, pr;
};

int main(void)
{
    freopen("input.in", "r", stdin);
    #ifndef _DEBUG
    freopen("output.out", "w", stdout);
    #endif
    
    int Case;
    cin >> Case;
    while (Case--)
    {
        int n, m;
        cin >> n >> m;
        deque<Job> dq(n);
        for (int i = 0; i < n; ++i)
        {
            dq[i].id = i;
            cin >> dq[i].pr;
        }
        int time = 0;
        while (true)
        {
            Job j = dq.front();
            dq.pop_front();
            deque<Job>::iterator it;
            for (it = dq.begin(); it != dq.end(); ++it)
            {
                if (it->pr > j.pr)
                {
                    break;
                }
            }
            if (it != dq.end())
            {
                dq.push_back(j);
            }
            else
            {
                if (j.id == m)
                {
                    cout << ++time << endl;
                    break;
                }
                else
                {
                    ++time;
                }
            }
        }

    }
    return 0;
}

