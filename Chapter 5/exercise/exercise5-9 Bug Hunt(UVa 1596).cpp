#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
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
using namespace std;

map<char, long long> table;
map<char, map<long long, long long> > value;
int line_num = 0;

pair<long long, bool> get_value(const string &str)
{
    // 如果是数字
    if (str[0] >= '0' && str[0] <= '9')
    {
        istringstream ss(str);
        long long num;
        ss >> num;
        return pair<long long, bool>(num, true);
    }
    else
    {
        // 如果是数组元素
        char array_name = str[0];
        pair<long long, bool> result = get_value(str.substr(str.find('[') + 1, str.rfind(']') - str.find('[') - 1));
        if (result.second)
        {
            map<char, map<long long, long long> >::iterator value_it = value.find(array_name);
            if (value_it == value.end())
            {
                return pair<long long, bool>(-1, false);
            }
            else
            {
                map<long long, long long>::iterator index_it = value_it->second.find(result.first);
                if (index_it == value_it->second.end())
                {
                    return pair<long long, bool>(-1, false);
                }
                else
                {
                    return pair<long long, bool>(index_it->second, true);
                }
            }
        }
        else
        {
            return pair<long long, bool>(-1, false);
        }

    }
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif
    string line;
    bool mark = false;
    bool is_first = true;
    while (getline(cin, line))
    {
        if (line == ".")
        {
            if (!mark)
            {
                break;
            }
            mark = false;
            if (is_first)
            {
                cout << 0 << endl;
            }
            table.clear();
            value.clear();
            line_num = 0;
            is_first = true;
        }
        else
        {
            mark = true;
            ++line_num; 
            if (line.find('=') == string::npos)
            {
                istringstream ss(line);
                char ch, t;
                long long len;
                ss >> ch >> t >> len >> t;
                table[ch] = len;
            }
            else
            {
                int loc = line.find('=');
                string left_str = line.substr(0, loc);
                pair<char, long long> left_array(left_str[0], -1);

                pair<long long, bool> result_left = get_value(left_str.substr(left_str.find('[') + 1, left_str.rfind(']') - left_str.find('[') - 1));
                if (result_left.second)
                {
                    map<char, long long>::iterator table_it = table.find(left_array.first);
                    if (table_it == table.end())
                    {
                        if (is_first)
                        {
                            cout << line_num << endl;
                            is_first = false;
                        }       
                    }
                    else
                    {
                        if (result_left.first >= 0 && result_left.first < table_it->second)
                        {
                            left_array.second = result_left.first;
                        }
                    }
                }
                else
                {
                    if (is_first)
                    {
                        cout << line_num << endl;
                        is_first = false;
                    }
                }
                string right_str = line.substr(loc + 1, line.size() - loc);
                pair<long long, bool> result_right = get_value(right_str);
                if (left_array.second != -1 && result_right.second)
                {
                    value[left_array.first][left_array.second] = result_right.first;
                }
                else
                {
                    if (is_first)
                    {
                        cout << line_num << endl;
                        is_first = false;
                    }
                }
            }
        }
    }
    return 0;
}

