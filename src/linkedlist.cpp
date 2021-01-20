
#include <exception>
#include <iostream>

#include "linkedlist.h"

namespace linkedlist
{

	void LinkedList::print() noexcept
	{
		if (m_head == NULL)
		{
			std::cout << "Empty List..." << std::endl;
			return;
		}

		Node* traverser = m_head;

		std::cout << traverser->value;
		while (traverser->next != NULL)
		{
			std::cout << " -> " << traverser->next->value;
			traverser = traverser->next;
		}
		std::cout << std::endl;
	}

	unsigned int LinkedList::size() noexcept
	{
		int size = 0;
		if (m_head == NULL)
		{
			return size;
		}
		else
		{
			size++;
		}
		
		Node* traverser = m_head;
		while (traverser != NULL && traverser->next != NULL)
		{
			size++;
			traverser = traverser->next;
		}

		return size;
	}

	bool LinkedList::empty() noexcept
	{
		return m_head == NULL;
	}

	void LinkedList::add(int value) noexcept
	{
		push_back(value);
	}

	Node* LinkedList::at(unsigned int index)
	{
		if (m_head == NULL)
		{
			throw std::out_of_range("empty list!");
		}

		Node* traverser = m_head;

		while (traverser != NULL && index != 0)
		{
			traverser = traverser->next;
			index--;
		}

		if (index != 0)
		{
			throw std::out_of_range("index is out of bound!");
		}

		return traverser;
	}

	int LinkedList::value_at(unsigned int index)
	{
		Node* item = at(index);

		return item->value;
	}

	void LinkedList::push_front(int value) noexcept
	{
		Node* newNode = new Node(value);

		if (m_head != NULL) // list is NOT empty!
		{
			newNode->next = m_head;
		}
		
		m_head = newNode;
	}

	void LinkedList::pop_front()
	{
		if (m_head == NULL)
		{
			throw std::underflow_error("list is already empty!");
		}
		else
		{
			m_head = m_head->next;
		}
	}

	void LinkedList::push_back(int value) noexcept
	{
		Node* newNode = new Node(value);

		if (m_head == NULL) // list is empty
		{
			m_head = newNode;
		}
		else
		{
			Node* lastNode = at(size() - 1);

			lastNode->next = newNode;
		}
	}

	void LinkedList::pop_back()
	{
		if (m_head == NULL)
		{
			throw std::underflow_error("list is already empty!");
		}
		else if (m_head->next == NULL)
		{
			m_head = NULL;
		}
		else
		{
			Node* traverser = m_head;

			while (traverser->next->next != NULL)
			{
				traverser = traverser->next;
			}

			traverser->next = NULL;
		}
	}

	int LinkedList::front()
	{
		if (m_head == NULL)
		{
			throw std::underflow_error("list is already empty!");
		}

		return m_head->value;
	}

	int LinkedList::back()
	{
		if (m_head == NULL)
		{
			throw std::underflow_error("list is already empty!");
		}

		Node* traverser = m_head;

		while (traverser->next != NULL)
		{
			traverser = traverser->next;
		}

		return traverser->value;
	}

	void LinkedList::insert(unsigned int index, int value) // may fire couple of exceptions (Ex: OUT_OF_BOUND, ALREADY_EMPTY, etc.)
	{
		Node* item = at(index);
		
		item->value = value;
	}

	void LinkedList::push_before(unsigned int index, int value)
	{
		if (index == 0)
		{
			push_front(value);
		}
		else
		{
			Node* prevNode = at(index - 1); // find the previous node to insert the new node
			
			Node* newNode = new Node(value, prevNode->next);
			prevNode->next = newNode;
		}
	}

	void LinkedList::push_after(unsigned int index, int value)
	{
		Node* item = at(index);

		if (item != NULL)
		{
			Node* newNode = new Node(value, item->next);
			item->next = newNode;
		}
	}

	void LinkedList::erase(unsigned int index)
	{
		if (index == 0)
		{
			pop_front();
			return;
		}

		index--;
		Node* traverser = m_head;
		while (traverser->next != NULL && index > 0)
		{
			index--;
			traverser = traverser->next;
		}

		if (traverser->next == NULL)
		{
			throw std::out_of_range("index is out of bound!");
		}
		else
		{
			traverser->next = traverser->next->next;
		}
	}
	
	void LinkedList::reverse() noexcept
	{
		if(m_head == NULL)
		{
			return;
		}

		Node* current = m_head;
		Node* oldPrev = NULL;
		while(current != NULL)
		{
			Node* oldNext = current->next;

			current->next = oldPrev;

			oldPrev = current;
			current = oldNext;
		}

		m_head = oldPrev;
	}

	void LinkedList::remove_value(int value)
	{
		if (m_head == NULL)
		{
			throw std::underflow_error("list is already empty!");
		}

		Node* traverser = m_head;
		while (traverser->next != NULL)
		{
			if (traverser->next->value == value)
			{
				break;
			}

			traverser = traverser->next;
		}

		if (traverser->next == NULL)
		{
			throw std::out_of_range("item not found!");
		}
		else
		{
			traverser->next = traverser->next->next;
		}
	}

}
