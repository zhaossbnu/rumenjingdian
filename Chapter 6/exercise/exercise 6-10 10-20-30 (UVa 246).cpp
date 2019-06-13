#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cctype>
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
#include <ctime>
#include <stack>
using namespace std;

#define PLAYING 0
#define WIN     1
#define LOSS    2
#define DRAW    3

deque<int> a;
deque<deque<int>> h;

set<deque<deque<int>>> s;

bool judge(int i)
{
    if (h[i].size() < 3) return false;
    int first = h[i][0] + h[i][1] + h[i].back();
    int second = h[i][0] + *(h[i].rbegin() + 1) + h[i].back();
    int third = h[i].back() + *(h[i].rbegin() + 1) + *(h[i].rbegin() + 2);
    if (first == 10 || first == 20 || first == 30)
    {
        a.push_back(h[i][0]); a.push_back(h[i][1]); a.push_back(h[i].back());
        h[i].pop_front(); h[i].pop_front(); h[i].pop_back();
        return true;
    }
    else if (second == 10 || second == 20 || second == 30)
    {
        a.push_back(h[i][0]); a.push_back(*(h[i].rbegin() + 1)); a.push_back(h[i].back());
        h[i].pop_front(); h[i].pop_back(); h[i].pop_back();
        return true;
    }
    else if (third == 10 || third == 20 || third == 30)
    {
        a.push_back(*(h[i].rbegin() + 2)); a.push_back(*(h[i].rbegin() + 1)); a.push_back(h[i].back());
        h[i].pop_back(); h[i].pop_back(); h[i].pop_back();
        return true;
    }
    else
    {
        return false;
    }
}


void play()
{
    int state = PLAYING;
    for (int i = 0; i < 7; ++i)
    {
        h[i].push_back(a[0]);
        a.pop_front();
    }
    int cnt = 7;
    int i = 0;
    while (state == PLAYING)
    {
        
        h[i].push_back(a[0]);
        a.pop_front();
        ++cnt;
        while (true)
        {
            bool res = judge(i);
            if (res)
            {
                res = judge(i);
            }
            else
            {
                if (h[i].empty())
                {
                    h.erase(h.begin() + i);
                    if (h.empty())
                    {
                        state = WIN;
                        break;
                    }
                    i %= h.size();
                }
                else
                {
                    i = (i + 1) % h.size();
                }
                break;
            }
            
        }
        if (a.empty()) state = WIN;
        if (s.find(h) != s.end()) { state = DRAW; break; }
        s.insert(h);
    }
    if (state == WIN) printf("WIN : %d\n", cnt);
    else if (state == LOSS) printf("LOSS: %d\n", cnt);
    else if (state == DRAW) printf("DRAW: %d\n", cnt);
}


int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif  
    while (true)
    {
        a.clear();
        a.resize(52);
        h.resize(7);
        for (int i = 0; i < 7; ++i) h[i].clear();
        s.clear();
        for (int i = 0; i < 52; ++i)
        {
            cin >> a[i];
            if (a[i] == 0) return 0;
        }
        play();
    }
    return 0;
}


