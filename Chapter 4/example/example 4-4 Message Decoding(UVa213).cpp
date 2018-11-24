//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

char code[8][300];

void set_code(const string &code_str)
{
	memset(code, 0, sizeof(code));
	int i = 0;
	code[1][0] = code_str[i++];
	for (int len = 2; len <= 8; ++len)
	{
		for (int j = 0; j < (1 << len) - 1; ++j)
		{
			if (i == code_str.size())
			{
				break;
			}
			code[len][j] = code_str[i++];
		}
	}
}

char readchar()
{
	while (true)
	{
		char ch = getchar();
		if (ch != '\n' && ch != '\r')
		{
			return ch;
		}
	}
}

int readint(int len)
{
	int result = 0;
	while (len--)
	{
		result = result * 2 + readchar() - '0';
	}
	return result;
}

int main(void)
{
	string code_str;
	while (getline(cin, code_str) && !cin.eof())
	{
		set_code(code_str);
		while (true)
		{
			int len = readint(3);
			if (len == 0)
			{
				break;
			}
			while (true)
			{
				int v = readint(len);
				if (v == (1 << len) - 1)
				{
					break;
				}
				cout << code[len][v];
			}
		}
		cout << endl;
		getchar();
	}
	return 0;
}
