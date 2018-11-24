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
using namespace std;

pair<string, string> parse(const string & addr)
{
    int k = addr.find('@');
    string user = addr.substr(0, k);
    string mta = addr.substr(k + 1);
    return pair<string, string>(user, mta);
}

int main(void)
{
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    string mta_flag;
    set<pair<string, string> > users;
    while (cin >> mta_flag && mta_flag != "*")
    {
        string server, t_user;
        int num_of_user;
        cin >> server >> num_of_user;
        while (num_of_user--)
        {
            cin >> t_user;
            users.insert(pair<string, string>(t_user, server));
        }
    }

    for (;;)
    {
        string t_send;
        cin >> t_send;
        if (t_send == "*")
        {
            break;
        }
        pair<string, string> send = parse(t_send);
        string t_receviers;
        vector<pair<string, string> > receivers;
        vector<string> mtas;
        while (cin >> t_receviers && t_receviers != "*")
        {
            receivers.push_back(parse(t_receviers));
            if (find(mtas.begin(), mtas.end(), receivers.rbegin()->second) == mtas.end())
            {
                mtas.push_back(receivers.rbegin()->second);
            }
        }
        getchar();

        string data = "", t_data;
        while (getline(cin, t_data) && t_data != "*")
        {
            data += ("     " + t_data + "\n");
        }

        for (int i = 0; i < mtas.size(); ++i)
        {
            cout << "Connection between " << send.second << " and " << mtas[i] << endl;
            cout << "     HELO " << send.second << endl;
            cout << "     250" << endl;
            cout << "     MAIL FROM:<" << send.first << "@" << send.second << ">" << endl;
            cout << "     250" << endl;
            int cnt = 0;
            for (int j = 0; j < receivers.size(); ++j)
            {
                if (receivers[j].second == mtas[i])
                {
                    cout << "     RCPT TO:<" << receivers[i].first << "@" << receivers[i].second << ">" << endl;
                    if (users.find(receivers[j]) != users.end())
                    {
                        cout << "     250" << endl;
                        ++cnt;
                    }
                    else
                    {
                        cout << "     550" << endl;
                    }
                }
            }
            if (cnt)
            {
                cout << "     DATA" << endl;
                cout << data;
                cout << "     ." << endl;
                cout << "     250" << endl;
            }
            cout << "     QUIT" << endl;
            cout << "     221" << endl;
        }
    }
    return 0;
}

