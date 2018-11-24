#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct LegalPlace
{
    int x;
    int y;
    LegalPlace(int x, int y) :x(x), y(y) {}
};

const int N = 8;
char g[10][10];

char player;

int mov[2][8] = { {-1, -1, 0, 1, 1, 1, 0, -1}, {0, 1, 1, 1, 0, -1, -1, -1} };
vector<LegalPlace> places;

bool check_op(int x, int y)
{
    if (g[x][y] != '-')
    {
        return false;
    }
    for (int i = 0; i < 8; ++i)
    {
        int tx = x, ty = y;
        do
        {
            tx += mov[0][i];
            ty += mov[1][i];
        } while (g[tx][ty] != '\0' && g[tx][ty] != '-' && g[tx][ty] != player);
        if ((tx != x + mov[0][i] || ty != y + mov[1][i]) && g[tx][ty] == player)
        {
            return true;
        }
    }
    return false;
}

void list_op()
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (check_op(i, j))
            {
                LegalPlace place(i, j);
                places.push_back(place);
            }
        }
    }
}

void print()
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cout << g[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void change_player()
{
    if (player == 'B')
    {
        player = 'W';
    }
    else
    {
        player = 'B';
    }
    places.clear();
    list_op();
}

void mrc(int x, int y)
{
    
    for (int i = 0; i < 8; ++i)
    {
        int tx = x, ty = y;
        do
        {
            tx += mov[0][i];
            ty += mov[1][i];
        } while (g[tx][ty] != '\0' && g[tx][ty] != '-' && g[tx][ty] != player);
        if ((tx != x + mov[0][i] || ty != y + mov[1][i]) && g[tx][ty] == player)
        {
            int tx2 = x, ty2 = y;
            while (tx2 != tx || ty2 != ty)
            {           
                g[tx2][ty2] = player;
                tx2 += mov[0][i];
                ty2 += mov[1][i];
            }
            
        }
    }
    int numb = 0, numw = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (g[i][j] == 'B')
            {
                ++numb;
            }
            else if (g[i][j] == 'W')
            {
                ++numw;
            }
        }
    }
    printf("Black - %d White - %d\n", numb, numw);
}

int main(void)
{
    freopen("linet.in", "r", stdin);
    int Case;
    cin >> Case;
    while (Case--)
    {
        memset(g, 0, sizeof(g));
        places.clear();
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                cin >> g[i][j];
            }
        }
        cin >> player;
        list_op();
        char op;
        while (true)
        {
            cin >> op;
            if (op == 'L')
            {
                if (places.size())
                {
                    for (int i = 0; i < places.size(); ++i)
                    {
                        printf("(%d,%d)", places[i].x, places[i].y);
                    }
                    cout << endl;
                }
                else
                {
                    cout << "No legal move." << endl;
                }
            }
            else if (op == 'M')
            {
                int op_x, op_y;
                scanf("%1d%1d", &op_x, &op_y);
                if (places.size())
                {
                    mrc(op_x, op_y);
                }
                else
                {
                    change_player();
                    mrc(op_x, op_y);
                }
                change_player();
            }
            else if (op == 'Q')
            {
                print();
                break;
            }
        }
    }
    return 0;
}