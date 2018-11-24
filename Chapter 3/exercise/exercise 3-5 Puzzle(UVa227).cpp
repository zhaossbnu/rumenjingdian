#include <bits/stdc++.h>

using namespace std;

int main(void)
{
        char grid[5][10];
        for (int i = 0; i < 5; ++i)
        {
            cin.getline(grid[i], 10);
        }
        int x = -1, y = -1;
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if (grid[i][j] == ' ')
                {
                    x = i, y = j;
                }
            }
        }
        char ch;
        bool legal = true;
        while (cin >> ch && ch != '0' && legal)
        {
            switch (ch)
            {
            case 'A':
                if (x >= 1)
                {
                    grid[x][y] = grid[x - 1][y];
                    --x;
                    grid[x][y] = ' ';
                }
                else
                {
                    cout << "This puzzle has no final configuration." << endl;
                    legal = false;
                }
                break;
            case 'B':
                if (x <= 3)
                {
                    grid[x][y] = grid[x + 1][y];
                    ++x;
                    grid[x][y] = ' ';
                }
                else
                {
                    cout << "This puzzle has no final configuration." << endl;
                    legal = false;
                }
                break;
            case 'L':
                if (y >= 1)
                {
                    grid[x][y] = grid[x][y - 1];
                    --y;
                    grid[x][y] = ' ';
                }
                else
                {
                    cout << "This puzzle has no final configuration." << endl;
                    legal = false;
                }
                break;
            case 'R':
                if (y <= 3)
                {
                    grid[x][y] = grid[x][y + 1];
                    ++y;
                    grid[x][y] = ' ';
                }
                else
                {
                    cout << "This puzzle has no final configuration." << endl;
                    legal = false;
                }
                break;
            }

        }
        if (legal)
        {
            for (int i = 0; i < 5; ++i)
            {
                for (int j = 0; j < 5; ++j)
                {
                    cout << grid[i][j] << " ";
                }
                cout << endl;
            }
        }
    return 0;
}
