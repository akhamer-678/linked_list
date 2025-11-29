// implementation file
#include "list.h"
#include <iostream>
using namespace std;

list::list() { head = cursor = prev = NULL; } // default constructor
list::~list() { makelistempty(); }            // destructor

bool list::listisempty() const
{
    return (head == NULL);
}

bool list::currisempty() const
{
    return (cursor == NULL);
}

void list::tofirst() { cursor = head; }

bool list::atfirst() const
{
    if (listisempty())
    {
        if (currisempty())
        {
            return true;
        }
    }
    else
        return (cursor == head);
};
void list::advance()
{
    prev = cursor;
    cursor = cursor->next;
};
void list::toend()
{

    if (!listisempty())
    {
        tofirst();
        while (cursor->next != NULL)
        {
            advance();
        }
    }
}
bool list::atend() const
{
    if (listisempty())
    {
        if (currisempty())
        {
            return true;
        }
    }
    else
        return (cursor->next == NULL);
};
int list::listsize()
{
    int count = 0;
    node *q;
    q = head;
    while (q != NULL)
    {
        count++;
        q = q->next;
    }
    return count;
}
void list::updatedata(char d)
{
    cursor->data = d;
}
void list::updatekey(int k)
{
    cursor->key = k;
}

void list::retrivedata(char &x)
{
    x = cursor->data;
}
void list::insertfirst(int k, char d)
{
    node *p;
    p = new node;
    p->key = k;
    p->data = d;
    p->next = head;
    head = p;
    cursor = head;
    prev = NULL;
}
void list::insertafter(int k, char d)
{
    node *p;
    p = new node;
    p->key = k;
    p->data = d;
    p->next = cursor->next;
    cursor->next = p;
    prev = cursor;
    cursor = p;
}
void list::insertbefor(int k, char d)
{
    node *p;
    p = new node;
    p->key = k;
    p->data = d;
    p->next = cursor;
    prev->next = p;
    cursor = p;
}
void list::insertend(int k, char d)
{
    if (listisempty())
    {
        insertfirst(k, d);
    }
    else
    {
        toend();
        insertafter(k, d);
    }
}
void list::deletenode()
{
    node *q;
    if (!currisempty())
    {
        if (atfirst()) // delete head node
        {
            q = head;
            head = head->next;
            cursor = head;
            prev = NULL;
            delete q;
        }
        else // delete non-head node
        {
            q = cursor;
            cursor = cursor->next;
            prev->next = cursor;
            delete q;
        }
    }
}
void list::deletefirst()
{
    if (!listisempty())
    {
        tofirst();
        deletenode();
    }
}
void list::deleteend()
{
    if (!listisempty())
    {
        toend();
        deletenode();
    }
}
void list::makelistempty()
{

    while (!listisempty())
    {
        tofirst();
        deletenode();
    }
}
void list::search(const char d)
{
    tofirst();
    while (!currisempty() && cursor->data != d)
    {
        advance();
    }
    if (!currisempty())
    {
        cout << "yes , we found  " << cursor->data << " in node id : " << cursor->key<<endl;
    }
    else
        cout << d << " is not found\n"<<endl;
};
bool list::search(const int k)
{
    bool found = false;
    tofirst();
    while ((!found) && (cursor != NULL))
        if (k == cursor->key)
            found = true;
        else
            advance();
    return found;
}
void list::orderinsert(int k, char d)
{
    tofirst();
    while ((cursor != NULL) && (k > cursor->key))
        advance();
    if (prev == NULL)
    {
        insertfirst(k, d);
    }
    else
        insertbefor(k, d);
}
void list::traverse()
{
    tofirst();
    while (!currisempty())
    {
        cout << cursor->data << " - " << cursor->key << endl;
        advance();
    }
}
