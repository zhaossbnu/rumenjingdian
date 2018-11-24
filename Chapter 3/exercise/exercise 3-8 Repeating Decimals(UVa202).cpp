#include <bits/stdc++.h>

using namespace std;
const int N = 10005;
int main(void)
{
	int a, b;
	bool first_case = true;
	while (cin >> a >> b)
	{
	    int old_a = a;
		int decimal[N];
		if(first_case)
        {
            first_case = !first_case;
        }
        else
        {
            printf("\n");
        }
		printf("%d/%d = %d.", old_a, b, a / b);
		a %= b;

		int wei = 0;
		while (wei <= 10000)
		{
			a *= 10;
			decimal[wei] = a / b;
			if (a % b == 0)
			{
				break;
			}
			a %= b;
			++wei;
		}
		if (wei <= 10000)
		{
			for (int i = 0; i <= wei; ++i)
			{
				cout << decimal[i];
			}
			cout << "(0)" << endl;
			cout << "   1 = number of digits in repeating cycle" << endl;
		}
		else
		{
			int first_loop_start = 0;
			int second_loop_start = 1;
			bool is_loop = true;
			for (first_loop_start = 0; first_loop_start <= 10000; ++first_loop_start)
			{
				is_loop = true;
				for (second_loop_start = first_loop_start + 1; second_loop_start <= 10000; ++second_loop_start)
				{
					int loop_size = second_loop_start - first_loop_start;
					is_loop = true;
					for (int p = 1; p <= 10; ++p)
					{
						if (decimal[first_loop_start] != decimal[p * loop_size + first_loop_start])
						{
							is_loop = false;
							break;
						}
					}
					if (is_loop)
						break;
				}
				if (is_loop)
					break;
			}

			int loop_size = second_loop_start - first_loop_start;

			for (int i = 0; i < first_loop_start; ++i)
			{
				cout << decimal[i];
			}
			if (loop_size <= 50)
			{
				cout << "(";
				for (int i = first_loop_start; i < second_loop_start; ++i)
				{
					cout << decimal[i];
				}
				cout << ")" << endl;
			}
			else
			{
				cout << "(";
				for (int i = first_loop_start; i < first_loop_start + 50; ++i)
				{
					cout << decimal[i];
				}
				cout << "...)" << endl;
			}


			cout << "   " << loop_size << " number of digits in repeating cycle" << endl;

		}
	}

	return 0;
}
/*
// 只需要看余数有没有重复出现即可
#include<stdio.h>
#include<string.h>
#define maxn 3005

int main()
	{
		int a, b;
		int reminder_pos[maxn], reminder_exist[maxn],digit[maxn];
		int quot, reminder; //分别为商和余数
		int cycle_len, cycle_begin;//分别保存 循环节长度和 循环起始点索引
		while(scanf("%d%d",&a,&b) == 2 && b != 0){
			memset(reminder_pos, 0, sizeof(reminder_pos));
			memset(reminder_exist, 0, sizeof(reminder_exist));
			int i;
			int orig_numerator = a;//保留初始的分子 便于输出
			int integer = a/b; 得到整数部分
			reminder = a%b;//第一个余数
			cycle_len = 0;
			cycle_begin = 0;
			for(i = 0; i < maxn; i++ ){
				if(reminder_exist[reminder] == 1){
					cycle_begin = reminder_pos[reminder];//记录该循环开始位置
					cycle_len = i-cycle_begin;//记录循环节长度
					break;
				}
				else{
					reminder_exist[reminder] = 1;
					reminder_pos[reminder] = i;
				}
				a = reminder*10;//辗转 相除（类比竖式除法）
				quot = a/b;
				reminder = a%b;
				digit[i] = quot;//记录 小数部分
			}
			printf("%d/%d = %d.", orig_numerator, b, integer);
			for(int j = 0; j < cycle_begin && j < 50; j++)
				printf("%d",digit[j]);
				printf("(");
			if(i <= 50){//不能把把此处改为i < 50 同时 j <= i (原因下面有解释)
				for(int j = cycle_begin; j < i; j++ ){ //i取 49 时候刚好50 个数
					printf("%d",digit[j]);
				}
			}
			else if(i > 50){
				for(int j = cycle_begin; j < 50; j++ ){
					printf("%d",digit[j]);
				}
				printf("...");
			}
			printf(")\n");
			printf("   %d = number of digits in repeating cycle\n\n",cycle_len);

		}

		return 0;
	}
*/
