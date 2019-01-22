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
	int d, i;
	while (cin >> d >> i)
	{
		int loc = 1;
		while (--d)
		{
			if (i % 2)
			{
				loc = 2 * loc;
				i = i / 2 + 1;
			}
			else
			{
				loc = 2 * loc + 1;
				i = i / 2;
			}
		}
		cout << loc << endl;
	}

	return 0;
}
