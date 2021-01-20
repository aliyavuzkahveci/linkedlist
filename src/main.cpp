
#include "iostream"

#include "linkedlist.h"
#include "doublylinkedlist.h"

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

	linkedList.reverse();
	std::cout << "After reversing the linked list" << std::endl;
	linkedList.print();

	linkedList.reverse();
	std::cout << "After reversing the linked list" << std::endl;
	linkedList.print();

	linkedList.erase(4);
	linkedList.print();

	std::cout << "First: " << linkedList.front() << " --- Last: " << linkedList.back() << std::endl;

	linkedList.reverse();
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
	

	doublylinkedlist::DoublyLinkedList dll;
	dll.print();
	std::cout << "is linkedlist empty=" << std::boolalpha << dll.empty() << std::endl;

	dll.add(3);
	dll.add(1);
	dll.add(5);
	dll.add(7);
	dll.add(13);
	dll.print();

	dll.remove_value(5);
	dll.print();

	dll.push_before(2, 31);
	dll.print();

	dll.push_after(1, 17);
	dll.print();

	std::cout << "is linkedlist empty=" << std::boolalpha << dll.empty() << std::endl;

	dll.erase(4);
	dll.print();

	std::cout << "First: " << dll.front() << " --- Last: " << dll.back() << std::endl;

	dll.reverse();
	dll.print();
	std::cout << "First: " << dll.front() << " --- Last: " << dll.back() << std::endl;

	try
	{
		//dll.remove_value(23);
		doublylinkedlist::Node* node = dll.at(7);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception catched: " << e.what() << std::endl;
	}

	return 0;
}
