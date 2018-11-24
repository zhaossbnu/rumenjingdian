#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    char ch;
    bool is_left_quote = true;
    while((ch = getchar()) != EOF)
    {
        if(ch == '\"')
        {
            is_left_quote ? cout << "``" : cout << "\'\'";
            is_left_quote = !is_left_quote;
        }
        else
        {
            cout << ch;
        }
    }
    return 0;
}
