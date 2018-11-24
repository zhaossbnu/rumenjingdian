// copy from https://blog.csdn.net/qq1337715208/article/details/79321885
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

char board[11][10];//车 R 马 H 炮 C 将帅 G
int rx, ry; //红方帅坐标

int chessPieces(int x1, int y1, int x2, int y2)
{
    int cnt = 0;
    if (x1 == x2)
    {
        if (y1 > y2)
            swap(y1, y2);
        for (int i = y1 + 1; i < y2; i++)
        {
            if (board[x1][i] != 0)
                cnt++;
        }
    }
    else if (y1 == y2)
    {
        if (x1 > x2)
            swap(x1, x2);
        for (int i = x1 + 1; i < x2; i++)
        {
            if (board[i][y1] != 0)
                cnt++;
        }
    }
    else
        cnt = -1;
    return cnt;
}
//炮判断
bool checkCannon(int x, int y)
{
    for (int i = 1; i <= 9; i++)
    {
        if (board[x][i] == 'C' && chessPieces(x, i, x, y) == 1)
            return true;
    }
    for (int i = 1; i <= 10; i++)
    {
        if (board[i][y] == 'C' && chessPieces(i, y, x, y) == 1)
            return true;
    }
    return false;
}
//车判断
bool checkChariot(int x, int y)
{
    for (int i = 1; i <= 9; i++)
    {
        if (i == y)
            continue;
        if (board[x][i] == 'R' && chessPieces(x, i, x, y) == 0)
            return true;
    }
    for (int i = 1; i <= 10; i++)
    {
        if (i == x)
            continue;
        if (board[i][y] == 'R' && chessPieces(i, y, x, y) == 0)
            return true;
    }
    return false;
}
// 马判断
bool checkHorse(int x, int y)
{
    if (x == 3 && ((board[1][y - 1] == 'H' && board[2][y - 1] == 0) || (board[1][y + 1] == 'H' && board[2][y + 1] == 0)))
        return true;
    if ((board[x - 1][y - 2] == 'H' && board[x - 1][y - 1] == 0) || (board[x - 1][y + 2] == 'H' && board[x - 1][y + 1] == 0))
        return  true;
    if (board[x + 1][y - 1] == 0 && (board[x + 1][y - 2] == 'H' || board[x + 2][y - 1] == 'H'))
        return true;
    if (board[x + 1][y + 1] == 0 && (board[x + 1][y + 2] == 'H' || board[x + 2][y + 1] == 'H'))
        return true;
    return false;
}
// 检查（x，y）是否对帅
bool checkGeneral(int x, int y)
{
    return y == ry && chessPieces(x, y, rx, ry) == 0;
}
bool canMoveTo(int x, int y)
{
    if (x < 1 || x > 3 || y < 4 || y > 6)
        return false;
    if (checkGeneral(x, y) || checkChariot(x, y) || checkHorse(x, y) || checkCannon(x, y))
        return false;
    return true;
}

int main()
{
    freopen("linet.in", "r", stdin);
    int n, x, y, a, b;
    while (cin >> n >> x >> y, n != 0)
    {
        memset(board, 0, sizeof(board));
        for (int i = 0; i < n; i++)
        {
            char ch;
            cin >> ch >> a >> b;
            board[a][b] = ch;
            if (ch == 'G')
                rx = a, ry = b;
        }
        if (checkGeneral(x, y))
            cout << "NO\n";
        else
            cout << (canMoveTo(x - 1, y) || canMoveTo(x + 1, y) || canMoveTo(x, y - 1) || canMoveTo(x, y + 1) ? "NO\n" : "YES\n");
    }
    return 0;
}