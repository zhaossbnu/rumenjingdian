//#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int Case;
	while (cin >> Case && Case != -1)
	{
		cout << "Round " << Case << endl;
		string answer, guess;
		cin >> answer >> guess;
		int wrong = 0;
		int left = answer.size();
		for (int i = 0; i < guess.size(); ++i)
		{
			bool wrong_flag = true;;
			for (int j = 0; j < answer.size(); ++j)
			{
				if (guess[i] == answer[j])
				{
					--left;
					answer[j] = ' ';
					wrong_flag = false;
				}
			}
			if (wrong_flag)
			{
				++wrong;
			}
			if (left == 0)
			{
				cout << "You Win." << endl;
				break;
			}
			if (wrong == 7)
			{
				cout << "You lose." << endl;
				break;
			}
		}
		if (left != 0 && wrong != 7)
		{
			cout << "You clicked out." << endl;
		}
	}
	return 0;
}
