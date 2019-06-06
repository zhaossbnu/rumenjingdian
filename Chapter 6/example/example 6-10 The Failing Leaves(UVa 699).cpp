#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
struct Node
{
	int val, ls, rs;
	Node(int val = 0, int ls = 0, int rs = 0) : val(val), ls(ls), rs(rs)
	{

	}
};

Node tree[N];
int cnt = 0;

int build()
{
    int x; cin >> x;
	if (x == -1) return 0;
	++cnt;
	tree[cnt].val = x, tree[cnt].ls = 0, tree[cnt].rs = 0;
	int t = cnt;
	tree[t].ls = build();
	tree[t].rs = build();
	return t;
}

bool input()
{
	cnt = 0;
	int root; cin >> root;
	if (root == -1) return false;
    ++cnt;
    tree[1].val = root;
	tree[1].ls = build();
	tree[1].rs = build();
	return true;
}

int ans[N], root_loc, ans_len;

void cal()
{
	int cur = 1;
	ans_len = 1;
	while (tree[cur].ls) ++ans_len, cur = tree[cur].ls;
	root_loc = ans_len;
	cur = 1;
	while (tree[cur].rs) ++ans_len, cur = tree[cur].rs;
}


void dfs(int root, int loc)
{
	ans[loc] += tree[root].val;
	if (tree[root].ls) dfs(tree[root].ls, loc - 1);
	if (tree[root].rs) dfs(tree[root].rs, loc + 1);
}


int main(void)
{
	freopen("input.in", "r", stdin);
	int Case = 1;
	while (input())
	{
	    memset(ans, 0, sizeof(ans));
		if (Case != 1) puts("\n");
		printf("Case %d:\n", Case++);
		cal();
		dfs(1, root_loc);
		for (int i = 1; i <= ans_len; ++i)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}

	return 0;
}

/*
input

5 7 -1 6 -1 -1 3 -1 -1
8 2 9 -1 -1 6 5 -1 -1 12 -1 -1 3 7 -1 -1 -1
-1

output
Case 1:
7 11 3

Case 2:
9 7 21 15
*/
