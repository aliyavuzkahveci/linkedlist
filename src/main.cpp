// LinkedLists.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include "linkedlist.h"

using namespace linkedlist;

int main()
{
	LinkedList linkedList;

	linkedList.print();
	std::cout << "is linkedlist empty=" << std::boolalpha << linkedList.empty() << std::endl;

	linkedList.add(3);
	linkedList.add(1);
	linkedList.add(5);
	linkedList.add(7);
	linkedList.add(13);
	linkedList.print();

	linkedList.remove_value(5);
	linkedList.print();

	linkedList.push_before(2, 31);
	linkedList.print();

	linkedList.push_after(1, 17);
	linkedList.print();

	std::cout << "is linkedlist empty=" << std::boolalpha << linkedList.empty() << std::endl;

	linkedList.erase(4);
	linkedList.print();

	std::cout << "First: " << linkedList.front() << " --- Last: " << linkedList.back() << std::endl;

	try
	{
		//linkedList.remove_value(23);
		Node* node = linkedList.at(7);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception catched: " << e.what() << std::endl;
	}

	return 0;
}

