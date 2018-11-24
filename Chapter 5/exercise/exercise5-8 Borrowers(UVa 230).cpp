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

struct Book
{
    string name, author;
    bool on_shelf;
    Book(string name = "", string author = "", bool on_shelf = false) :name(name), author(author), on_shelf(on_shelf) { }
    bool operator<(const Book &b) const
    {
        return author < b.author || (author == b.author && name < b.name);
    }
    bool operator==(const Book &b) const
    {
        return author == b.author && name == b.name;
    }
    bool operator>(const Book &b) const
    {
        return author > b.author || (author == b.author && name > b.name);
    }
};


int main(void)
{
    freopen("input.in", "r", stdin);
    #ifndef _DEBUG
    freopen("output.out", "w", stdout);
    #endif
    string line;
    list<Book> books;
    while (getline(cin, line) && line != "END")
    {
        int by = line.find("by");
        Book book;
        book.name = line.substr(0, by - 1);
        book.author = line.substr(by + 3, line.length() - by - 3);
        books.push_front(book);
    }
    books.sort(less<Book>());
    list<Book> borrow;
    priority_queue<Book, vector<Book>, greater<Book> > return_pq;
    string op;
    while (cin >> op && op[0] != 'E')
    {
        string book_name;
        
        if (op[0] == 'B')
        {
            getchar();
            getline(cin, book_name);
            list<Book>::iterator it;
            for (it = books.begin(); it != books.end(); ++it)
            {
                if (it->name == book_name)
                {
                    borrow.push_front(*it);
                    break;
                }
            }
            books.erase(it);
        }
        else if (op[0] == 'R')
        {
            getchar();
            getline(cin, book_name);
            list<Book>::iterator it;
            for (it = borrow.begin(); it != borrow.end(); ++it)
            {
                if (it->name == book_name)
                {
                    return_pq.push(*it);
                    break;
                }
            }
            borrow.erase(it);
        }
        else if (op[0] == 'S')
        {
            while (!return_pq.empty())
            {
                Book t = return_pq.top();
                return_pq.pop();
                list<Book>::iterator it;
                for (it = books.begin(); it != books.end(); ++it)
                {
                    if (t < *it)
                    {
                        break;
                    }
                }
                if (it == books.begin())
                {
                    cout << "Put " << t.name << " First" << endl;
                    books.push_front(t);
                }
                else
                {
                    cout << "Put " << t.name << " After " << (--it)->name << endl;
                    books.insert(++it, t);
                }
            }
            cout << "END" << endl;
        }
    }

    return 0;
}

