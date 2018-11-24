#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


const char HEX[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

int main(void)
{
    freopen("linet.in", "r", stdin);
    int d, s, b;
    char type;
    int Case = 0;
    while (cin >> d >> s >> b >> type && d)
    {
        vector<int> disk[105][8];
        int check[105];
        memset(check, -1, sizeof(check));
        int check_type = 0;
        type == 'E' ? check_type = 0 : check_type = 1;
        
        for (int i = 0, j = 0; i < b; ++i, j = (j + 1) % d)
        {
            check[i] = j;
        }
        char ch;
        for (int i = 0; i < d; ++i)
        {
            for (int j = 0; j < b ; ++j)
            {
                for (int k = 0; k < s; ++k)
                {
                    cin >> ch;
                    ch == 'x' ? disk[j][i].push_back(-1) : disk[j][i].push_back(ch - 48);
                }
                
            }
        }
        bool is_valid = true;
        for (int i = 0; i < b && is_valid; ++i)
        {
            for (int k = 0; k < s && is_valid; ++k)
            {
                int bad_count = 0;
                int bad_index = -1;
                for (int j = 0; j < d; ++j)
                {
                    if (disk[i][j][k] == -1)
                    {
                        ++bad_count;
                        bad_index = j;
                    }
                }
                if (bad_count > 1)
                {
                    is_valid = false;
                }
                else if (bad_count == 1)
                {
                    int re;
                    if (bad_index == 0)
                    {
                        re = disk[i][1][k];
                        for (int j = 2; j < d; ++j)
                        {
                            re = re ^ disk[i][j][k];
                        }
                    }
                    else
                    {
                        re = disk[i][0][k];
                        for (int j = 1; j < d; ++j)
                        {
                            if (disk[i][j][k] != -1)
                            {
                                re = re ^ disk[i][j][k];
                            }
                        }
                    }
                    disk[i][bad_index][k] = re ^ check_type;
                }
                else
                {
                    int re = disk[i][0][k];
                    for (int j = 1; j < d; ++j)
                    {
                        re = re ^ disk[i][j][k];
                    }
                    if (re != check_type)
                    {
                        is_valid = false;
                    }
                }
            }
        }
        if (!is_valid)
        {
            printf("Disk set %d is invalid.\n", ++Case);
        }
        else
        {
            printf("Disk set %d is valid, contents are: ", ++Case);
            vector<int> result;
            for (int i = 0; i < b; ++i)
            {
                for (int j = 0; j < d; ++j)
                {
                    if (j != check[i])
                    {
                        result.insert(result.end(), disk[i][j].begin(), disk[i][j].end());
                    }
                }
            }
            if (result.size() % 4 != 0)
            {
                int add = 4 - result.size() % 4;
                result.insert(result.end(), add, 0);
            }

            for (int i = 0; i < result.size() / 4; ++i)
            {
                int sum = 0;
                for (int j = 0; j < 4; ++j)
                {
                    sum += result[i * 4 + j] << (3-j);
                }
                cout << HEX[sum];
            }
            cout << endl;
        }
    }
    return 0;
}
