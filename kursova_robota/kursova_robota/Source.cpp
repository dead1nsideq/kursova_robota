#include <iostream>
#include "MyVector.h"
#include <list>


using namespace std;

/*
	Курсова робота
	Варіант 23
*/

int main() {
	list<string> l{ "stirng1","string22","string333","string4444"};
	MyVector<string> vector;
	
	vector.add("10");
	vector.add("20");
	cout << vector.sizeOfVector() << endl;
	cout << vector.capacityOfVector() << endl;
	vector.remove_by_index(0);
	cout << vector.sizeOfVector() << endl;
	cout << vector.capacityOfVector() << endl;
	vector.remove("20");
	vector.add_list(l,true);
	vector.remove_by_index(0);
	vector.print();
	cout << vector.isHere("string") << endl;
	vector.print_reverse();
	vector.sort(true);
	vector.print();
	vector.inverse();
	vector.print();



	
}

