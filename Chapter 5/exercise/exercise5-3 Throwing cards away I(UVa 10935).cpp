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
#include <cctype>
#include <stack>
#include <queue>
#include <iterator>
#include <cmath>
#include <numeric>
using namespace std;


int main(void)
{
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    int a[55];
    for (int i = 0; i < 55; ++i)
    {
        a[i] = i + 1;
    }
    int n;
    while (cin >> n && n)
    {

        deque<int> cards(a, a + n);
        bool first = true;
        cout << "Discarded cards: ";
        while (cards.size() >= 2)
        {
            if (!first)
            {
                cout << ", ";
            }
            else
            {
                first = false;
            }
            cout << cards.front();
            cards.pop_front();
            cards.push_back(cards.front());
            cards.pop_front();
        }
        cout << endl;
        cout << "Remaining card: " << cards.front() << endl;
    }
    return 0;
}

