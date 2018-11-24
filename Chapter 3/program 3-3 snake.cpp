#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, x = 0, y = 0, s[31][31] = { 0 }, q = 1;
	cin >> n;
	y = n - 1;
	s[0][y] = 1;
	while (q < n*n)
	{
		while (x + 1 < n && !s[x + 1][y])
			s[++x][y] = ++q;//down
		while (y - 1 >= 0 && !s[x][y - 1])
			s[x][--y] = ++q;//left
		while (x + 1 >= 0 && !s[x - 1][y])
			s[--x][y] = ++q;//up
		while (y + 1 < n && !s[x][y + 1])
			s[x][++y] = ++q;//right
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << s[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
