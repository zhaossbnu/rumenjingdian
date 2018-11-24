//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		vector<int> a(str1.size());
		for (int i = 0; i < a.size(); ++i)
		{
			a[i] = str1[i] - 49;
		}
		vector<int> b(str2.size());
		for (int i = 0; i < b.size(); ++i)
		{
			b[i] = str2[i] - 49;
		}
		if (a.size() < b.size())
		{
			swap(a, b);
		}
		int i = 0;
		for (i = 0; i <= a.size() - 1; ++i)
		{
			bool flag = true;
			for (int j = i; j <= min(i + b.size() - 1, a.size() - 1); ++j)
			{
				if (a[j] && b[j - i])
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				break;
			}
		}
		if (i + b.size() - 1 <= a.size() - 1)
		{
			cout << a.size() << endl;
		}
		else
		{
			cout << b.size() + i << endl;
		}

	}
	return 0;
}
