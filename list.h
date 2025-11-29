#include <iostream>
using namespace std;

class list
{
    // Data member
private:
    class node
    {
    public:
        int key;
        char data;
        node *next;
    };
    node *head, *cursor, *prev;

public:      // function
    list();  // default constructor
    ~list(); // destructor
    bool listisempty() const;
    bool currisempty() const;
    void tofirst();
    bool atfirst() const;
    void advance();
    void toend();
    bool atend() const;
    int listsize();
    void updatedata(char);
    void updatekey(int);
    void retrivedata(char &);
    void insertfirst(int k, char d);
    void insertafter(int, char);
    void insertbefor(int, char);
    void insertend(int, char);
    void deletenode();
    void deletefirst();
    void deleteend();
    void makelistempty();
    void search(const char); // given(data) retern(key)
    bool search(const int);  // set cursor to the node and return True,
    void orderinsert(int, char);
    void traverse();
};