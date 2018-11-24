#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    int c = 0;
    for(int i = 111; i <= 999; ++i)
    {
        for(int j = 11; j <= 99; ++j)
        {
            int x = i * (j % 10), y = i * (j / 10), z = i * j;
            ostringstream oss;
            oss << i << j << x << y << z;
            string str1 = oss.str();
            bool flag = true;
            for(int k = 0; k < str1.size(); ++k)
            {
                if(str.find(str1[k]) == string::npos)
                {
                    flag = false;
                }
            }
            if(flag)
            {
                printf("<%d>\n", ++c);
                printf("%5d\n", i);
                printf("X%4d\n", j);
                printf("-----\n");
                printf("%5d\n", x);
                printf("%4d\n", y);
                printf("-----\n");
                printf("%5d\n\n", z);
            }
        }
    }
    cout << "The number of solutions = " << c << endl;
    return 0;
}
