#include<iostream>
#include"LinkedList.h"

using namespace std;

int main()
{
	LinkedList list;
	cout << "addToHead // extractHead" << endl;
	list.addToHead(1);
	cout << list << endl;
	list.addToHead(2);
	cout << list << endl;
	list.addToHead(3);
	cout << list << endl;
	cout << list.extractHead() << " ";
	cout << list.extractHead() << " ";
	cout << list.extractHead() << " ";
	cout << list.extractHead() << " " << endl;
	cout << list << endl << endl;


	cout << "addToTail // extractTail" << endl;
	list.addToTail(1);
	cout << list << endl;
	list.addToTail(2);
	cout << list << endl;
	list.addToTail(3);
	cout << list << endl;
	cout << list.extractTail() << " ";
	cout << list.extractTail() << " ";
	cout << list.extractTail() << " ";
	cout << list.extractTail() << " " << endl;
	cout << list << endl << endl;


	cout << "add // extract" << endl;
	list.add(0, 1);
	cout << list << endl;
	list.add(1, 5);
	cout << list << endl;
	list.add(1, 3);
	cout << list << endl;
	cout << list.extract(2) << " ";
	cout << list.extract(0) << " ";
	cout << list.extract(0) << " ";
	cout << list << endl << endl;

	cout << "swap" << endl;
	list[0] = 0;
	list[1] = 1;
	list[2] = 2;
	cout << list << endl;
	list.swap(0, 0);
	cout << list << endl;
	list.swap(2, 0);
	cout << list << endl;

	return 0;
}