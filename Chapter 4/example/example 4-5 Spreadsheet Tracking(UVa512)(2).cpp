#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std; 

struct Command
{
    string op;
    vector<int> ops;
};

vector<Command> cmds;
int simulate(int &r0, int &c0)
{
    for (size_t i = 0; i < cmds.size(); ++i)
    {
        if (cmds[i].op == "EX")
        {
            if (cmds[i].ops[0] == r0 && cmds[i].ops[1] == c0)
            {
                r0 = cmds[i].ops[2], c0 = cmds[i].ops[3];
            }
            else if (cmds[i].ops[2] == r0 && cmds[i].ops[3] == c0)
            {
                r0 = cmds[i].ops[0], c0 = cmds[i].ops[1];
            }
        }
        else
        {
            int dr = 0, dc = 0;
            if (cmds[i].op[0] == 'D')
            {
                if (cmds[i].op[1] == 'R')
                {
                    for (size_t j = 0; j < cmds[i].ops.size() && cmds[i].ops[j] <= r0; ++j)
                    {
                        if (cmds[i].ops[j] == r0)
                        {
                            return 0;
                        }
                        else
                        {
                            --dr;
                        }
                    }
                }
                else if (cmds[i].op[1] == 'C')
                {
                    for (size_t j = 0; j < cmds[i].ops.size() && cmds[i].ops[j] <= c0; ++j)
                    {
                        if (cmds[i].ops[j] == c0)
                        {
                            return 0;
                        }
                        else
                        {
                            --dc;
                        }
                    }
                }
            }
            else if (cmds[i].op[0] == 'I')
            {
                if (cmds[i].op[1] == 'R')
                {
                    for (size_t j = 0; j < cmds[i].ops.size() && cmds[i].ops[j] <= r0; ++j)
                    {
                        ++dr;
                    }
                }
                else if (cmds[i].op[1] == 'C')
                {
                    for (size_t j = 0; j < cmds[i].ops.size() && cmds[i].ops[j] <= c0; ++j)
                    {
                        ++dc;
                    }
                }
            }
            r0 += dr, c0 += dc;
        }
    }
    return 1;
}



int main(void)
{
    int r, c, n;
    while (cin >> r >> c >> n && r)
    {
        cmds.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> cmds[i].op;
            if (cmds[i].op == "EX")
            {
                cmds[i].ops.resize(4);
                for (int j = 0; j < 4; ++j)
                {
                    cin >> cmds[i].ops[j];
                }
            }
            else
            {
                int op_c;
                cin >> op_c;
                cmds[i].ops.resize(op_c);
                for (int j = 0; j < op_c; ++j)
                {
                    cin >> cmds[i].ops[j];
                }
                sort(cmds[i].ops.begin(), cmds[i].ops.end());
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int r0, c0;
            cin >> r0 >> c0;
            printf("Cell data in (%d,%d) ", r0, c0);
            if (simulate(r0, c0))
            {
                printf("moved to (%d,%d)\n", r0, c0);
            }
            else
            {
                printf("GONE\n");
            }
        }
    }
    
    return 0;
}