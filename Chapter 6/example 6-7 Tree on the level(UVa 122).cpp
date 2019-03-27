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

typedef  long long LL;
bool error = false;


struct Node
{
	bool have_value;
	int val;
	Node *left, *right;
	Node():have_value(false), left(NULL), right(NULL) {}
};

Node * root = new Node();

void addnode(string str)
{
	istringstream iss(str.substr(1));
	int val;
	iss >> val;
	char ch;
	Node * cur = root;
	while (iss >> ch)
	{
		if (ch == 'L')
		{
			if (cur->left == NULL)
			{
				Node * node = new Node();
				cur->left = node;
			}
			cur = cur->left;
		}
		else if (ch == 'R')
		{
			if (cur->right == NULL)
			{
				Node * node = new Node();
				cur->right = node;
			}
			cur = cur->right;
		}
	}
	if (cur->have_value)
	{
		error = true;
	}
	cur->val = val;
	cur->have_value = true;
}


void bfs(Node * root, vector<int> & ans)
{
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while (!q.empty())
	{
		Node * cur = q.front();
		q.pop();
		if (!cur->have_value)
		{
			error = true;
			return;
		}
		ans.push_back(cur->val);
		if (cur->left != NULL)
		{
			q.push(cur->left);
		}
		if (cur->right != NULL)
		{
			q.push(cur->right);
		}
	}
}

void del(Node * root)
{
	if (root == NULL)
	{
		return;
	}
	del(root->left);
	del(root->right);
	delete(root);
}


int main(void)
{
	freopen("input.in", "r", stdin);
#ifndef _DEBUG
	freopen("output.out", "w", stdout);
#endif

	string str;

	while (cin >> str)
	{
		if (str == "()")
		{
			vector<int> ans;
			bfs(root, ans);
			if (error)
			{
				cout << "not complete" << endl;
			}
			else
			{
				for (int i = 0; i < ans.size(); ++i)
				{
					cout << ans[i] << " ";
				}
				cout << endl;
			}
			del(root);
			root = new Node();
		}
		else
		{
			addnode(str);
		}
	}
	return 0;
}


/*
input:
(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
(3,L) (4,R) ()

output:
5 4 8 11 13 4 7 2 1
not complete
*/

/*
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

typedef  long long LL;
bool error = false;


struct Node
{
    bool have_value;
    int val;
    int left, right;
    Node():have_value(false), left(0), right(0) {}
};

vector<Node> root(2);

void addnode(string str)
{
    istringstream iss(str.substr(1));
    int val;
    iss >> val;
    char ch;
    int cur = 1;
    while (iss >> ch)
    {
        if (ch == 'L')
        {
            if (root[cur].left == 0)
            {
                root.push_back(Node());

                root[cur].left = root.size() - 1;
            }
            cur = root[cur].left;
        }
        else if (ch == 'R')
        {
            if (root[cur].right == 0)
            {
                root.push_back(Node());

                root[cur].right = root.size() - 1;
            }
            cur = root[cur].right;
        }
    }
    if (root[cur].have_value)
    {
        error = true;
    }
    root[cur].val = val;
    root[cur].have_value = true;
}


void bfs(vector<Node> root, vector<int> & ans)
{
    queue<Node> q;
    ans.clear();
    q.push(root[1]);
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (!cur.have_value)
        {
            error = true;
            return;
        }
        ans.push_back(cur.val);
        if (cur.left)
        {
            q.push(root[cur.left]);
        }
        if (cur.right)
        {
            q.push(root[cur.right]);
        }
    }
}



int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif

    string str;

    while (cin >> str)
    {
        if (str == "()")
        {
            vector<int> ans;
            bfs(root, ans);
            if (error)
            {
                cout << "not complete" << endl;
            }
            else
            {
                for (int i = 0; i < ans.size(); ++i)
                {
                    cout << ans[i] << " ";
                }
                cout << endl;
            }
            root.resize(1);
            root.push_back(Node());
        }
        else
        {
            addnode(str);
        }
    }
    return 0;
}
*/