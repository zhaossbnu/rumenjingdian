#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<char, string> encode;
map<string, char> decode;
vector<string> words;
multimap<string, string> code_word;

void decoding(string &code)
{
    int cnt = code_word.count(code);
    if (cnt == 1)
    {
        cout << code_word.find(code)->second << endl;
    }
    else if (cnt > 1)
    {
        cout << code_word.find(code)->second << "!" << endl;
    }
    else
    {
        int add = 100000, de = 100000;
        string add_word = "", de_word = "";
        for (multimap<string, string>::iterator it = code_word.begin(); it != code_word.end(); ++it)
        {
            string tstr = it->first;
            if (tstr.size() > code.size() && tstr.find(code) != string::npos && add > tstr.size() - code.size())
            {
                add = tstr.size() - code.size();
                add_word = it->second;
            }
            else if (tstr.size() < code.size() && code.find(tstr) != string::npos && de > code.size() - tstr.size())
            {
                de = code.size() - tstr.size();
                de_word = it->second;
            }
        }
        if (add < de)
        {
            cout << add_word << "?" << endl;
        }
        else if (add > de)
        {
            cout << de_word << "?" << endl;
        }
        else
        {
            if (add_word == "" && de_word == "")
            {
                cout << words[0] << "?" << endl;
            }
            else
            {
                cout << min(add_word, de_word) << "?" << endl;
            }
        }
    }

}


int main(void)
{
    freopen("linet.in", "r", stdin);
    char ch;
    string code;
    while (cin >> ch && ch != '*')
    {
        cin >> code;
        encode[ch] = code;
        decode[code] = ch;
    }
    string word;
    while (cin >> word && word != "*")
    {
        words.push_back(word);
        code = "";
        for (int i = 0; i < word.size(); ++i)
        {
            code += encode[word[i]];
        }
        code_word.insert(pair<string, string>(code, word));
    }
    while (cin >> code && code != "*")
    {
        decoding(code);
    }
    return 0;
}
