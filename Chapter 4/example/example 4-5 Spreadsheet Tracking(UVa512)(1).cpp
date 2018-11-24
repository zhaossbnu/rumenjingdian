#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int N = 60;
const int BIG = 10000;

int d[N + 5][N + 5] = { 0 }, d2[N + 5][N + 5] = { 0 }, ans[N + 5][N + 5] = { 0 };
int oprc[N + 5] = { 0 };


void del(char type)
{
	memcpy(d2, d, sizeof(d));
	memset(d, 0, sizeof(d));
	int j = 1;
	if (type == 'R')
	{
		for (int i = 1; i <= N; ++i)
		{
			if (!oprc[i])
			{
				memcpy(d[j++], d2[i], sizeof(int) * N);
			}
		}
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			if (!oprc[i])
			{
				for (int k = 1; k <= N; ++k)
				{
					d[k][j] = d2[k][i];
				}
				++j;
			}
		}
	}
}

void ins(char type)
{
	memcpy(d2, d, sizeof(d));
	memset(d, 0, sizeof(d));
	int j = 1;
	if (type == 'R')
	{
		for(int i = 1; i <= N; ++i)
		{
			if (oprc[i])
			{
				memset(d[j++], 0, sizeof(int) * (N + 5));
			}
			memcpy(d[j++], d2[i], sizeof(int) * N);
		}
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			if (oprc[i])
			{
				for (int k = 1; k <= N; ++k)
				{
					d[k][j] = 0;
				}
				++j;
			}
			for (int k = 1; k <= N; ++k)
			{
				d[k][j] = d2[k][i];
			}
			++j;
		}
	}
	int a = 1;
}

int main(void)
{
	int r, c, n;
	while (cin >> r >> c >> n && r)
	{
		for (int i = 1; i <= r; ++i)
		{
			for (int j = 1; j <= c; ++j)
			{
				d[i][j] = i * BIG + j;
			}
		}
		while (n--)
		{
			string op;
			cin >> op;
			if (op == "EX")
			{
				int r1, c1, r2, c2;
				cin >> r1 >> c1 >> r2 >> c2;
				swap(d[r1][c1], d[r2][c2]);
			}
			else
			{
				int op_num, op_r_c;
				cin >> op_num;
				memset(oprc, 0, sizeof(oprc));
				for (int i = 0; i < op_num; ++i)
				{
					cin >> op_r_c;
					oprc[op_r_c] = 1;
				}
				if (op[0] == 'D')
				{
					del(op[1]);
				}
				else
				{
					ins(op[1]);
				}
			}
		}
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				ans[d[i][j] / BIG][d[i][j] % BIG] = i * BIG + j;
			}
		}
		int q;
		cin >> q;
		while (q--)
		{
			int r1, c1;
			cin >> r1 >> c1;
			printf("Cell data in (%d,%d) ", r1, c1);
			if (ans[r1][c1] == 0)
			{
				cout << "GONE" << endl;
			}
			else
			{
				printf("moved to (%d,%d)\n", ans[r1][c1] / BIG, ans[r1][c1] % BIG);
			}
		}
	}

	return 0;
}
