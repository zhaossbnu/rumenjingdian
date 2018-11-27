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
using namespace std;

struct Index
{
    int aid, nid;
    Index(int aid = -1, int nid = -1) :aid(aid), nid(nid) { }
    bool operator==(const Index & b)
    {
        return aid == b.aid && nid == b.nid;
    }
    bool operator<(const Index & b)
    {
        return aid < b.aid || (aid == b.aid && nid < b.nid);
    }
};

//bool comp(const Index & a, const Index & b)
//{
//  return a.aid < b.aid;
//}

vector<vector<string> > articles;
map<string, vector<Index> > indexs;

void make_index(string line, int aid, int nid)
{
    for (int i = 0; i < line.size(); ++i)
    {
        line[i] = isalpha(line[i]) ? tolower(line[i]) : ' ';
    }
    istringstream iss(line);
    string word;
    while (iss >> word)
    {
        Index t = Index(aid, nid);
        if (find(indexs[word].begin(), indexs[word].end(), t) == indexs[word].end())
        {
            indexs[word].push_back(Index(aid, nid));
        }
    }
}

void print(const vector<Index> & result)
{
    if (result.size())
    {
        int last_id = result[0].aid;        
        for (int i = 0; i < result.size(); ++i)
        {
            if (result[i].aid != last_id)
            {
                cout << "---------" << endl;
            }
            last_id = result[i].aid;
            cout << articles[result[i].aid][result[i].nid] << endl;
        }
    }
    else
    {
        cout << "Sorry, I found nothing." << endl;
    }
    
}

void to_lower(string & word)
{
    for (int i = 0; i < word.size(); ++i)
    {
        word[i] = tolower(word[i]);
    }
}

int main(void)
{
    freopen("input.in", "r", stdin);
#ifndef _DEBUG
    freopen("output.out", "w", stdout);
#endif
    int n;
    cin >> n;
    getchar();
    articles.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        string line;
        articles[i].resize(1);
        int line_num = 0;
        while (getline(cin, line) && line[0] != '*')
        {
            ++line_num;
            articles[i].push_back(line);
            make_index(line, i, line_num);
        }
    }
    int m;
    cin >> m;
    string line;
    getchar();
    while (m--)
    {
        getline(cin, line);
        if (line.find(' ') == string::npos)
        {
            to_lower(line);
            vector<Index> result;
            if (indexs.find(line) != indexs.end())
            {
                result = indexs[line];
            }
            print(result);
        }
        else if (line.substr(0, 3) == "NOT")
        {
            string word = line.substr(4);
            to_lower(word);
            vector<int> pa;
            for (int i = 1; i <= n; ++i)
            {
                pa.push_back(i);
            }
            if (indexs.find(word) != indexs.end())
            {
                vector<Index> result = indexs[word];
                set<int> ia;
                for (int i = 0; i < result.size(); ++i)
                {
                    ia.insert(result[i].aid);
                }
                vector<int>::iterator it = set_difference(pa.begin(), pa.end(), ia.begin(), ia.end(), pa.begin());
                pa.resize(it - pa.begin());
            }
            if (pa.size())
            {
                for (int j = 1; j < articles[pa[0]].size(); ++j)
                {
                    cout << articles[pa[0]][j] << endl;
                }
                if (pa.size() > 1)
                {
                    cout << "---------" << endl;
                    for (int i = 1; i < pa.size(); ++i)
                    {
                        for (int j = 1; j < articles[pa[i]].size(); ++j)
                        {
                            cout << articles[pa[i]][j] << endl;
                        }
                    }
                }
            }
        }
        else if (line.find("AND") != string::npos)
        {
            string left = line.substr(0, line.find(' '));
            string right = line.substr(line.rfind(' ') + 1, line.size() - line.rfind(' ') - 1);
            to_lower(left);
            to_lower(right);
            vector<Index> l, r;
            if (indexs.find(left) != indexs.end())
            {
                l = indexs[left];
            }
            if (indexs.find(right) != indexs.end())
            {
                r = indexs[right];
            }
            set<int> aids;
            for (int i = 0, j = 0; i < l.size() && j < r.size();)
            {
                if (l[i].aid < r[j].aid)
                {
                    ++i;
                }
                else if (l[i].aid > r[j].aid)
                {
                    ++j;
                }  
                else if (l[i].aid == r[j].aid)
                {
                    aids.insert(l[i].aid);
                    ++i, ++j;
                }
            }
            //vector<Index>::iterator it = set_intersection(l.begin(), l.end(), r.begin(), r.end(), result.begin(), comp);
            //result.resize(it - result.begin());
            vector<Index> result;
            for (int i = 0; i < l.size(); ++i)
            {
                if (aids.find(l[i].aid) != aids.end())
                {
                    result.push_back(l[i]);
                }
            }
            for (int i = 0; i < r.size(); ++i)
            {
                if (aids.find(r[i].aid) != aids.end())
                {
                    result.push_back(r[i]);
                }
            }
            sort(result.begin(), result.end());
            vector<Index>::iterator it = unique(result.begin(), result.end());
            result.resize(it - result.begin());
            print(result);

        }
        else if (line.find("OR") != string::npos)
        {
            string left = line.substr(0, line.find(' '));
            string right = line.substr(line.rfind(' ') + 1, line.size() - line.rfind(' ') - 1);
            to_lower(left);
            to_lower(right);
            vector<Index> l, r;
            if (indexs.find(left) != indexs.end())
            {
                l = indexs[left];
            }
            if (indexs.find(right) != indexs.end())
            {
                r = indexs[right];
            }
            vector<Index> result(l.size() + r.size());
            vector<Index>::iterator it = set_union(l.begin(), l.end(), r.begin(), r.end(), result.begin());
            result.resize(it - result.begin());
            print(result);
        }
        cout << "==========" << endl;
    }
    return 0;
}

