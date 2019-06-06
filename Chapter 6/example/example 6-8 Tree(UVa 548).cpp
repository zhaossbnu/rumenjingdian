#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
struct Node
{
    int ls, rs;
};
vector<int> in_order, post_order;
vector<Node> tree(N);

int build(int l1, int r1, int l2, int r2)
{
   if(l1 > r1) return 0;
   int root = post_order[r2];
   int cur = l1;
   while(in_order[cur] != root) ++cur;
   tree[root].ls = build(l1, cur - 1, l2, l2 + cur - l1 - 1);
   tree[root].rs = build(cur + 1, r1, l2 + cur - l1, r2 -1);
   return root;

}

int ans = 0x3f3f3f3f, best_l = 0x3f3f3f3f;

void dfs(int root, int sum)
{
    sum += root;
    if(!tree[root].ls && !tree[root].rs)
    {
        if(sum < ans || sum == ans && root < best_l)
        {
            ans = sum, best_l = root;
        }
    }
    if(tree[root].ls) dfs(tree[root].ls, sum);
    if(tree[root].rs) dfs(tree[root].rs, sum);
}

int main(void)
{
    string line;
    while(getline(cin, line))
    {
        int x;
        in_order.resize(0);
        post_order.resize(0);
        istringstream iss1(line);
        while(iss1 >> x) in_order.push_back(x);
        getline(cin, line);
        istringstream iss2(line);
        while(iss2 >> x) post_order.push_back(x);
        build(0, in_order.size() - 1, 0, post_order.size() -1);
        ans = best_l = 0x3f3f3f3f;
        dfs(post_order[post_order.size() - 1], 0);
        cout << best_l << endl;

    }

    return 0;
}

/*
input
3 2 1 4 5 7 6
3 1 2 5 6 7 4
7 8 11 3 5 16 12 18
8 3 11 7 16 18 12 5
255
255
output
1
3
255
*/
