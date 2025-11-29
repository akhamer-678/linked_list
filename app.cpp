
#include <iostream>
#include <string>
#include "list.h"
using namespace std;
using std::string;

int main()
{
	list L;
	// insert first testing //
	L.insertfirst(20, 'B');
	L.insertfirst(10, 'A');
	L.traverse();
	cout << "********\n";
	// insert end testing//
	L.toend();
	L.insertend(40, 'D');
	L.traverse();
	cout << "********\n";
	// insert befor testing //
	L.toend();
	L.insertbefor(30, 'C');
	L.traverse();
	cout << "********\n";
	// update first_node (key & data)
	L.tofirst();
	L.updatedata('a');
	L.updatekey(1);
	L.traverse();
	cout << "********\n";
	// search testing //
	L.search('C');
	L.search('R');
	cout << "********\n";
	// orderinsert testing //
	L.orderinsert(35, 'd');
	L.traverse();
	cout << "********\n";
	// list size //
	cout << "list size is : " << L.listsize() << endl;
	cout << "********\n";
	// make list is empty //
	L.~list();
	cout << "After makelistempty, list size is : " << L.listsize() << endl;
	cout << "********\n";

	return 0;
}
