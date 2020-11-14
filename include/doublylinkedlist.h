
#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include <string>
#include <stdlib.h>

namespace doublylinkedlist
{
	struct Node
	{
		Node(int value)
		{
			this->value = value;
			this->next = NULL;
			this->prev = NULL;
		}

		Node(int value, Node* next)
		{
			this->value = value;
			this->next = next;
			this->prev = NULL;
		}

		Node(int value, Node* next, Node* prev)
		{
			this->value = value;
			this->next = next;
			this->prev = prev;
		}

		int value;
		Node* next;
		Node* prev;
	};

	class DoublyLinkedList
	{
	public:
		DoublyLinkedList() = default;

		virtual ~DoublyLinkedList() = default;

		void print() noexcept;

		unsigned int size() noexcept;

		bool empty() noexcept;

		void add(int value) noexcept;

		Node* at(unsigned int index); // may fire OUT_OF_BOUND exception !!!

		int value_at(unsigned int index);

		void push_front(int value) noexcept;

		// removes from front and returns the Node
		Node* pop_front(); // may fire ALREADY_EMPTY exception !!!

		void push_back(int value) noexcept;

		// removes from back and returns the Node
		Node* pop_back(); // may fire ALREADY_EMPTY exception !!!

		int front(); // may fire ALREADY_EMPTY exception !!!

		int back(); // may fire ALREADY_EMPTY exception !!!

		void insert(unsigned int index, int value); // may fire couple of exceptions (Ex: OUT_OF_BOUND, ALREADY_EMPTY, etc.)

		void push_before(unsigned int index, int value);

		void push_after(unsigned int index, int value);

		void erase(unsigned int index);

		void reverse() noexcept;

		void remove_value(int value); // may fire ITEM_NOT_FOUND exception

		Node* find(int value) noexcept; // find the first Node having the provided value

	private:
		Node* m_head = NULL;
		Node* m_tail = NULL;
	};
}

#endif // DOUBLY_LINKED_LIST_H_
