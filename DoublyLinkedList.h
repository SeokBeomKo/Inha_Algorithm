#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T			m_data;
	Node<T>* pPrev;
	Node<T>* pNext;
};

template <typename T>
class DoublyLinkedList
{
private:
	Node<T>* pHead;
	Node<T>* pTail;

	Node<T>* pCurNode;
	int			m_size;

public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void push_front(const T& _data);
	void push_back(const T& _data);

	void pop_front();
	void pop_back();

	void print();
	void printreverse();

	int size();
	bool search(const T& data);
	bool empty();
	void clear();
};

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
	pHead		= nullptr;
	pTail		= nullptr;
	pCurNode	= nullptr;

	m_size		= 0;
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}

template<typename T>
inline void DoublyLinkedList<T>::push_front(const T& _data)
{
	Node<T>* tempNode = new Node<T>();
	tempNode->m_data = _data;

	if (empty())
	{
		pHead = tempNode;
		pTail = tempNode;
	}
	else
	{
		tempNode->pNext = pHead;
		pHead->pPrev = tempNode;
		pHead = tempNode;
	}

	m_size++;
}

template<typename T>
inline void DoublyLinkedList<T>::push_back(const T& _data)
{
	Node<T>* tempNode = new Node<T>();
	tempNode->m_data = _data;

	if (empty())
	{
		pHead = tempNode;
		pTail = tempNode;
	}
	else
	{
		tempNode->pPrev = pTail;
		pTail->pNext = tempNode;
		pTail = tempNode;
	}

	m_size++;
}

template<typename T>
inline void DoublyLinkedList<T>::pop_front()
{
	if (empty())	return;

	if (1 == m_size)
	{
		Node<T>* tempNode = pHead;
		pHead = nullptr;
		pTail = nullptr;
		delete tempNode;
	}
	else
	{
		Node<T>* tempNode = pHead;
		pHead = pHead->pNext;
		pHead->pPrev = nullptr;
		delete tempNode;
	}

	m_size--;
}

template<typename T>
inline void DoublyLinkedList<T>::pop_back()
{
	if (empty())	return;

	if (1 == m_size)
	{
		Node<T>* tempNode = pTail;
		pHead = nullptr;
		pTail = nullptr;
		delete tempNode;
	}
	else
	{
		Node<T>* tempNode = pTail;
		pTail = pTail->pPrev;
		pTail->pNext = nullptr;
		delete tempNode;
	}

	m_size--;
}

template<typename T>
inline void DoublyLinkedList<T>::print()
{
	if (empty())	return;

	pCurNode = pHead;
	while (nullptr != pCurNode)
	{
		cout << pCurNode->m_data << endl;
		pCurNode = pCurNode->pNext;
	} 
}

template<typename T>
inline void DoublyLinkedList<T>::printreverse()
{
	if (empty())	return;

	pCurNode = pTail;
	while (nullptr != pCurNode)
	{
		cout << pCurNode->m_data << endl;
		pCurNode = pCurNode->pPrev;
	}
}

template<typename T>
inline bool DoublyLinkedList<T>::search(const T& data)
{
	if (empty())	return false;

	pCurNode = pHead;

	while (nullptr != pCurNode)
	{
		if (pCurNode->m_data == data)
		{
			return true;
		}
		pCurNode = pCurNode->pNext;
	}

	return false;
}

template<typename T>
inline int DoublyLinkedList<T>::size()
{
	return m_size;
}

template<typename T>
inline bool DoublyLinkedList<T>::empty()
{
	return 0 == m_size;
}

template<typename T>
inline void DoublyLinkedList<T>::clear()
{
	while (!empty())
	{
		pop_back();
	}
}
