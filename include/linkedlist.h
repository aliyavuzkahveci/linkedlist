
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <string>
#include <stdlib.h>

namespace linkedlist
{

struct Node {

	Node(int value)
	{
		this->value = value;
		this->next = NULL;
	}

	Node(int value, Node* next)
	{
		this->value = value;
		this->next = next;
	}

	int value;
	Node* next;
};

class LinkedList {
public:
	LinkedList() = default;

	virtual ~LinkedList() = default;

	void print() noexcept;

	unsigned int size() noexcept;

	bool empty() noexcept;

	void add(int value) noexcept;

	Node* at(unsigned int index); // may fire OUT_OF_BOUND exception !!!

	int value_at(unsigned int index);

	void push_front(int value) noexcept;

	void pop_front(); // may fire ALREADY_EMPTY exception !!!

	void push_back(int value) noexcept;

	void pop_back(); // may fire ALREADY_EMPTY exception !!!

	int front(); // may fire ALREADY_EMPTY exception !!!

	int back(); // may fire ALREADY_EMPTY exception !!!

	void insert(unsigned int index, int value); // may fire couple of exceptions (Ex: OUT_OF_BOUND, ALREADY_EMPTY, etc.)

	void push_before(unsigned int index, int value);
	
	void push_after(unsigned int index, int value);

	void erase(unsigned int index);

	void reverse() noexcept;

	void remove_value(int value); // may fire ITEM_NOT_FOUND exception	

private:
	Node* m_head = NULL;

};

}

#endif // LINKED_LIST_H_
