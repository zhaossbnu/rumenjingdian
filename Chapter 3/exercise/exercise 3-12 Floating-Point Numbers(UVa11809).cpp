//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
// 10^16
const long long N = 10000000000000000;
int main(void)
{
	long long al, ar;
	char ch;
	int b;
	while (cin >> al >> ch >> ar >> ch >> b)
	{
		long long a = ar;
		if (al != 0)
		{
			++b;
			a += (al * N / 10);
		}
		int jie = b / log10(2) + 1;
		int e = 1;
		for (e = 1; e <= 30; ++e)
		{
			int pow = 1;
			for (int i = 1; i <= e; ++i)
			{
				pow *= 2;
			}
			if (pow == jie)
			{
				break;
			}
		}
		/*
		a * 10^b = m * 2^e
		lg(a) + b = lg(m) + e * lg(2)
		lg(m) = lg(a) + b - e * lg(2)
		*/
		double lgwei = log10((double)a / N) + b - (jie-1) * log10(2);
		double wei = pow(10, lgwei);
		int m = 0;
		// 为什么wei<0.5结束？
		// 如果wei=0.4 那么wei*2的值为0.8不足以构成一位
		// 最后的wei是浮点数运算的误差
		while (abs(wei) >= 0.5)
		{
			wei *= 2;
			wei -= 1;
			++m;
		}
		cout << m << " " << e << endl;
	}
	return 0;
}
