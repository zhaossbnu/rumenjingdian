#include <bits/stdc++.h>

using namespace std;
map<char, int> dna;
char ch[4] = {'A', 'C', 'G', 'T'};
int main(void)
{
    dna['A'] = 0, dna['C'] = 1, dna['G'] = 2, dna['T'] = 3;
    int m, n;
    cin >> m >> n;
    int c[4][55] = {0};
    while(m--)
    {
        string  str;
        cin >> str;
        for(int i = 0; i < str.size(); ++i)
        {
            ++c[dna[str[i]]][i];
        }
    }
    string result = "";
    int hamming = 0;
    for(int i = 0; i < n; ++i)
    {
        int index = 3;
        for(int j = 2; j >= 0; --j)
        {
            if(c[j][i] >= c[index][i])
            {
                index = j;
            }
        }
        result += ch[index];

        for(int j = 0; j < 4; ++j)
        {
            if(j != index)
            {
                hamming += c[j][i];
            }
        }
    }
    cout << result << endl;
    cout << hamming << endl;
    return 0;
}
