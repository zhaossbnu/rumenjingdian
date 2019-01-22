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

int main(void)
{
	freopen("input.in", "r", stdin);
#ifndef _DEBUG
	freopen("output.out", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<pair<int, int> > mts(26);
	for (int i = 0; i < n; ++i)
	{
		char ch;
		cin >> ch;
		cin >> mts[ch - 65].first >> mts[ch - 65].second;
	}
	getchar();
	string line;
	while (getline(cin, line))
	{
		int cont = 0;
		stack<pair<int, int> > st;
		bool error = false;
		for (int i = 0; i < line.size(); ++i)
		{
			if (line[i] == ')')
			{
				pair<int, int> l, r;
				if (!st.empty())
				{
					r = st.top();
					st.pop();
				}
				if (!st.empty())
				{
					l = st.top();
					st.pop();
				}
				if (l.second != r.first)
				{
					error = true;
					break;
				}
				cont += l.first * l.second * r.second;
				st.push(pair<int, int>(l.first, r.second));
			}
			else if (line[i] == '(')
			{
				continue;
			}
			else
			{
				st.push(mts[line[i] - 65]);
			}
		}
		if (error || st.size() > 1)
		{
			cout << "error" << endl;
		}
		else
		{
			cout << cont << endl;
		}
	}
	return 0;
}

/*
input:
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))


output:
0
0
0
error
10000
error
3500
15000
40500
47500
15125

*/
