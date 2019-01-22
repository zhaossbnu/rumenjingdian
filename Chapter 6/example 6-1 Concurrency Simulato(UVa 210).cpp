#include <bits/stdc++.h>

using namespace std;

int n, t[6], quota;
int var[26] = {0};
int pids[6] = {0};
vector<vector<string> > codes;
deque<int> ready;
queue<int> block;
bool is_lock = false;

void run(int pid)
{
    int q = quota;
    while(q > 0)
    {
        string code = codes[pid][pids[pid]];
        if (code.find('=') != string::npos)
        {
            istringstream iss(code.substr(4));
            int tmp;
            iss >> tmp;
            var[code[0]-97] = tmp;
            q -= t[1];
        }
        else if (code.find("print") != string::npos)
        {
            cout << pid << ": " <<  var[code[6] - 97] << endl;
            q -= t[2];
        }
        else if (code == "lock")
        {
            if(is_lock)
            {
                block.push(pid);
                return ;
            }
            is_lock = true;
            q -= t[3];
        }
        else if (code == "unlock")
        {
            is_lock = false;
            if(!block.empty())
            {
                int pid2 = block.front();
                block.pop();
                ready.push_front(pid2);
            }
            q -= t[4];
        }
        else if (code == "end")
        {
            return ;
        }
        ++pids[pid];
    }
    ready.push_back(pid);
}


int main(void)
{
    freopen("input.in", "r", stdin);
    int Case;
    cin >> Case;
    while(Case --)
    {
        cin >> n >> t[1] >> t[2] >> t[3] >> t[4] >> t[5] >> quota;
        codes.resize(n + 1);
        getchar();
        string t_str;
        for(int i = 1; i <= n; ++i)
        {
            while(getline(cin, t_str))
            {
                codes[i].push_back(t_str);
                if(t_str == "end")
                {
                    break;
                }
            }
            ready.push_back(i);
        }
        while(!ready.empty())
        {
            int pid = ready.front();
            ready.pop_front();
            run(pid);
        }
        if(Case)
        {
            cout << endl;
        }
    }
}


/*
input:
1

3 1 1 1 1 1 1
a = 4
print a
lock
b = 9
print b
unlock
print b
end
a = 3
print a
lock
b = 8
print b
unlock
print b
end
b = 5
a = 17
print a
print b
lock
b = 21
print b
unlock
print b
end


output:
1: 3
2: 3
3: 17
3: 9
1: 9
1: 9
2: 8
2: 8
3: 21
3: 21
*/
