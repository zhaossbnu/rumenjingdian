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

const int maxN = 100000 + 5;
char ch[maxN];
int nxt[maxN];


int main(void)
{
	freopen("input.in", "r", stdin);
#ifndef _DEBUG
	freopen("output.out", "w", stdout);
#endif
	while (scanf("%s", ch + 1) == 1)
	{
		int n = strlen(ch + 1);
		nxt[0] = 0;
		int cur = 0, last = 0;;
		for (int i = 1; i <= n; ++i)
		{
			if (ch[i] == '[')
			{
				cur = 0;
			}
			else if (ch[i] == ']')
			{
				cur = last;
			}
			else
			{
				nxt[i] = nxt[cur];
				nxt[cur] = i;
				if (cur == last)
				{
					last = i;
				}
				cur = i;
			}
		}
		for (int i = nxt[0]; i != 0; i = nxt[i])
		{
			cout << ch[i];
		}
		cout << endl;
	}
	return 0;
}
