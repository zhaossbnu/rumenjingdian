#include <bits/stdc++.h>

using namespace std;

int go(vector<int> &p, int loc, int step, int t)
{
	while (t--)
	{
		do
		{
			loc = (loc + step + p.size()) % p.size();
		} while (p[loc] == 0);
	}
	return loc;
}

int main(void)
{
	int n, k, m;
	while (cin >> n >> k >> m && n && k && m)
	{
		vector<int> p(n);
		for (int i = 0; i < n; ++i)
		{
			p[i] = i + 1;
		}
		int left = n;
		int a = n - 1, b = 0;
		while (left)
		{
			a = go(p, a, 1, k);
			b = go(p, b, -1, m);
			printf("%3d", p[a]);
			--left;
			if (a != b)
			{
				printf("%3d", p[b]);
				--left;
			}
			p[a] = p[b] = 0;
			if (left)
			{
				cout << ",";
			}
		}
		cout << endl;
	}
	return 0;
}
