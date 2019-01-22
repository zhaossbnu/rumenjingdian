#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cctype>
#include <stack>
#include <queue>
#include <iterator>
#include <cmath>
#include <numeric>
#include <ctime>
#include <stack>
using namespace std;

typedef  long long LL;
 
int main(void)
{
	freopen("input.in", "r", stdin);
#ifndef _DEBUG
	freopen("output.out", "w", stdout);
#endif
	int n, m;
	int Case = 0;
	while (cin >> n >> m)
	{
		list<LL> l;
		for (int i = 1; i <= n; ++i)
		{
			l.push_back(i);
		}
		while (m--) 
		{
			int op;
			cin >> op;
			if (op == 1)
			{
				int x, y;
				cin >> x >> y;
				list<LL>::iterator it_y = find(l.begin(), l.end(), y);
				l.remove(x);
				if (it_y == l.begin())
				{
					l.push_front(x);
				}
				else
				{
					l.insert(it_y, x);
				}
			}
			else if (op == 2)
			{
				int x, y;
				cin >> x >> y;
				list<LL>::reverse_iterator it_y = find(l.rbegin(), l.rend(), y);
				l.remove(x);
				if (it_y == l.rbegin())
				{
					l.push_back(x);
				}
				else
				{
					list<LL>::iterator it = find(l.begin(), l.end(), y);
					++it;
					l.insert(it, x);
				}
			}
			else if (op == 3)
			{
				int x, y;
				cin >> x >> y;
				list<LL>::iterator it_x = find(l.begin(), l.end(), x);
				list<LL>::iterator it_y = find(l.begin(), l.end(), y);
				*it_x = y;
				*it_y = x;
			}
			else if (op == 4)
			{
				l.reverse();
			}
		}
		int i = 1;
		LL cnt = 0;
		for (list<LL>::iterator it = l.begin(); it != l.end(); ++it)
		{
			if (i % 2)
			{
				cnt += *it;
			}
			++i;
		}
		printf("Case %d: %lld\n", ++Case, cnt);
	}

	return 0;
}
/*
input:
6 4
1 1 4
2 3 5
3 1 6
4
6 3
1 1 4
2 3 5
3 1 6
100000 1
4
output:
Case 1: 12
Case 2: 9
Case 3: 2500050000
*/