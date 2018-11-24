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
using namespace std;

int main(void)
{
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int t;
    int Case = 0;
    while (cin >> t && t)
    {
        printf("Scenario #%d\n", ++Case);
        map<int, int> team;
        for (int i = 1; i <= t; ++i)
        {
            int n, x;
            cin >> n;
            while (n--)
            {
                cin >> x;
                team[x] = i;
            }
        }

        queue<int> q, q2[1010];
        while (true)
        {
            string op;
            int player;
            cin >> op;
            if (op == "STOP")
            {
                break;
            }
            else if (op == "ENQUEUE")
            {
                cin >> player;
                int team_id = team[player];
                if (q2[team_id].empty())
                {
                    q.push(team_id);
                }
                q2[team_id].push(player);
            }
            else if (op == "DEQUEUE")
            {
                int team_id = q.front();
                printf("%d\n", q2[team_id].front());
                q2[team_id].pop();
                if (q2[team_id].empty())
                {
                    q.pop();
                }
            }
        }
        cout << endl;
    }
    
    return 0;
}

