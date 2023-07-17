#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList()
{
	m_size	= 0;
	pHead	= nullptr;
	pTail	= nullptr;
}

SingleLinkedList::~SingleLinkedList()
{
}

void SingleLinkedList::push_back(Node* node)
{
	if (m_size > 0)
	{
		pTail->pNext = node;
		pTail = node;
	}
	else
	{
		pHead = node;
		pTail = node;
	}
	m_size++;
}

void SingleLinkedList::push_front(Node* node)
{
	if (m_size > 0)
	{
		node->pNext = pHead;
		pHead = node;
	}
	else
	{
		pHead = node;
		pTail = node;
	}
	m_size++;
}

void SingleLinkedList::pop_back()
{
	if (0 == m_size)	return;

	m_size--;

	if (1 == m_size)
	{
		pHead = nullptr;
		pTail = nullptr;
		return;
	}

	Node* preIter = pHead;
	Node* curIter = pHead->pNext;
	while (NULL != curIter->pNext)
	{
		preIter = curIter;
		curIter = curIter->pNext;
	}
	pTail = preIter;
}

void SingleLinkedList::pop_front()
{
	if (0 != m_size)
	{
		pHead = pHead->pNext;
	}
	else
	{
		return;
	}
	m_size--;
}

void SingleLinkedList::pop_num(int num)
{
	Node* preIter = pHead;
	Node* curIter = pHead;

	if (pHead->m_num == num)
	{
		pHead = pHead->pNext;
		m_size--;
		return;
	}

	for (int i = 0; i < m_size; i++)
	{
		if (curIter->m_num == num)
		{
			preIter->pNext = curIter->pNext;
			m_size--;
			break;
		}
		else
		{
			preIter = curIter;
			curIter = curIter->pNext;
		}
	}
}

int SingleLinkedList::size()
{
	return m_size;
}

bool SingleLinkedList::empty()
{
	return 0 == m_size;
}

void SingleLinkedList::print()
{
	Node* iter = pHead;

	if (0 == m_size)	return;

	for (int i = 0; i < m_size; i++)
	{
		cout << iter->m_num << " ¹ø : " << iter->m_name << endl;
		iter = iter->pNext;
	}
}
