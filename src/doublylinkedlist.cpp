#include <stdexcept>
#include <iostream>

#include "doublylinkedlist.h"

namespace doublylinkedlist
{
	void DoublyLinkedList::print() noexcept
	{
		if (empty())
		{
			std::cout << "Empty List..." << std::endl;
			return;
		}

		Node* traverser = m_head;

		std::cout << "(NULL)," << traverser->value;
		if (traverser->next != NULL)
		{
			std::cout << ",(" << traverser->next->value << ")";
		}

		while (traverser->next != NULL)
		{
			std::cout << " <=> " << "(" << traverser->next->prev->value << ")," << traverser->next->value;
			if (traverser->next->next != NULL)
			{
				std::cout << ",(" << traverser->next->next->value << ")";
			}
			else
			{
				std::cout << ",(NULL)";
			}
			traverser = traverser->next;
		}
		std::cout << std::endl;
	}

	unsigned int DoublyLinkedList::size() noexcept
	{
		int size = 0;
		Node* traverser = m_head;

		while (traverser != NULL)
		{
			size++;
			traverser = traverser->next;
		}

		return size;
	}

	bool DoublyLinkedList::empty() noexcept
	{
		return m_head == NULL;
	}

	void DoublyLinkedList::add(int value) noexcept
	{
		push_back(value);
	}

	Node* DoublyLinkedList::at(unsigned int index)
	{
		if (empty())
		{
			throw std::out_of_range("empty list!");
		}
		else if (size() <= index)
		{
			throw std::out_of_range("index is out of bound!");
		}

		Node* traverser = m_head;

		while (index != 0)
		{
			traverser = traverser->next;
			index--;
		}

		return traverser;
	}

	int DoublyLinkedList::value_at(unsigned int index)
	{
		Node* item = at(index);

		return item->value;
	}

	void DoublyLinkedList::push_front(int value) noexcept
	{
		Node* newNode = new Node(value, m_head);

		if (!empty()) // list is NOT empty!
		{
			m_head->prev = newNode;
		}
		else
		{
			m_tail = newNode; //first item in the list! So, head = item
		}

		m_head = newNode;
	}

	Node* DoublyLinkedList::pop_front()
	{
		if (empty())
		{
			throw std::underflow_error("list is already empty!");
		}

		Node* poppedItem = m_head;

		m_head = m_head->next; // remove the head from the list
		m_head->prev = NULL;

		return poppedItem; // return the old head!
	}

	void DoublyLinkedList::push_back(int value) noexcept
	{
		Node* newNode = new Node(value, NULL, m_tail);

		if (empty()) // list is empty
		{
			m_head = newNode;
		}
		else
		{
			m_tail->next = newNode;
		}

		m_tail = newNode; // set the new tail!
	}

	Node* DoublyLinkedList::pop_back()
	{
		Node* poppedItem = NULL;
		unsigned int listSize = size();

		if (listSize == 0) // m_tail == NULL
		{
			throw std::underflow_error("list is already empty!");
		}
		else if (listSize == 1)
		{
			poppedItem = m_tail;
			m_head = NULL;
			m_tail = NULL;
		}
		else
		{
			Node* newTail = m_tail->prev;
			poppedItem = m_tail;
			newTail->next = NULL;
			m_tail = newTail;
		}

		return poppedItem;
	}

	int DoublyLinkedList::front()
	{
		if (empty())
		{
			throw std::underflow_error("list is already empty!");
		}

		return m_head->value;
	}

	int DoublyLinkedList::back()
	{
		if (empty())
		{
			throw std::underflow_error("list is already empty!");
		}

		return m_tail->value;
	}

	void DoublyLinkedList::insert(unsigned int index, int value)
	{
		Node* item = at(index);

		item->value = value;
	}

	void DoublyLinkedList::push_before(unsigned int index, int value)
	{
		if (empty())
		{
			push_front(value);
		}
		else
		{
			Node* itemAtIndex = at(index);

			Node* newItem = new Node(value, itemAtIndex, itemAtIndex->prev);

			itemAtIndex->prev->next = newItem;
			itemAtIndex->prev = newItem;
		}
	}

	void DoublyLinkedList::push_after(unsigned int index, int value)
	{
		if (index == size() - 1)
		{
			push_back(value);
		}
		else
		{
			Node* itemAtIndex = at(index);

			Node* newItem = new Node(value, itemAtIndex->next, itemAtIndex);

			itemAtIndex->next->prev = newItem;

			itemAtIndex->next = newItem;
		}
	}

	void DoublyLinkedList::erase(unsigned int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else if (index == size() - 1)
		{
			pop_back();
		}
		else
		{
			Node* toBeDeleted = at(index);
			toBeDeleted->prev->next = toBeDeleted->next;
			toBeDeleted->next->prev = toBeDeleted->prev;
		}
	}

	void DoublyLinkedList::reverse() noexcept
	{
		Node* newTailPrev = m_head->next;
		Node* traverser = m_tail;

		while (traverser != NULL)
		{
			Node* newPrev = traverser->next;
			traverser->next = traverser->prev;

			// first we need to move one item, then re-assign the "prev" variable!
			traverser = traverser->prev;
			if (traverser != NULL)
			{
				traverser->next->prev = newPrev;
			}
		}

		Node* newTail = m_head;

		m_head = m_tail;
		m_tail = newTail;
		m_tail->prev = newTailPrev;
	}

	void DoublyLinkedList::remove_value(int value)
	{
		Node* foundItem = find(value);

		if (foundItem == NULL)
		{
			throw std::underflow_error("item not found!");
		}
		else if (foundItem == m_head) // only item will be removed
		{
			pop_front();
		}
		else if (foundItem == m_tail)
		{
			pop_back();
		}
		else
		{
			foundItem->prev->next = foundItem->next;
			foundItem->next->prev = foundItem->prev;
		}
	}

	Node* DoublyLinkedList::find(int value) noexcept
	{
		Node* traverser = m_head;

		while (traverser != NULL)
		{
			if (traverser->value == value)
			{
				break;
			}
			traverser = traverser->next;
		}

		return traverser; // will return NULL if item not found!
	}


}