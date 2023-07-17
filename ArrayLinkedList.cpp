#include "ArrayLinkedList.h"

void ArrayLinkedList::Init(int _size)
{
	list	= new Node[_size];
	head	= NULL;
	max		= NULL;
	deleted = NULL;
	crnt	= NULL;
}

int ArrayLinkedList::GetIndex()
{
	if (NULL == deleted)	return ++max;
	else
	{
		int temp = deleted;
		deleted = list[temp].Fnext;
		return temp;
	}
}

void ArrayLinkedList::DeleteIndex(int _index)
{
	if (NULL == deleted)
	{
		deleted = _index;
		list[_index].Fnext = NULL;
	}
	else
	{
		int temp = deleted;
		deleted = _index;
		list[_index].Fnext = temp;
	}
}

void ArrayLinkedList::AddFront(string _data)
{
	int temp = head;
	head = crnt = GetIndex();

	list[head].data = _data;
	list[head].next = temp;
}

void ArrayLinkedList::AddNear(string _data)
{
	if (NULL == head)	AddFront(_data);
	else
	{
		int temp = head;
		while (list[temp].next != NULL)
		{
			temp = list[temp].next;
		}
		list[temp].next = crnt = GetIndex();

		list[list[temp].next].data = _data;
		list[list[temp].next].next = NULL;
	}
}

void ArrayLinkedList::RemoveFront()
{
	if (NULL == head)	return;

	int temp = list[head].next;
	DeleteIndex(head);
	head = crnt = temp;
}

void ArrayLinkedList::RemoveNear()
{
	if (NULL == head)	return;

	if (NULL == list[head].next)	RemoveFront();

	int temp_ptr = head;
	int temp_pre = NULL;

	while (NULL != list[temp_ptr].next)
	{
		temp_pre = temp_ptr;
		temp_ptr = list[temp_ptr].next;
	}
	list[temp_pre].next = NULL;
	DeleteIndex(temp_ptr);
	crnt = temp_pre;
}

void ArrayLinkedList::RemoveCurrent()
{
	if (NULL == head)	return;

	if (crnt == list[head].next)	RemoveFront();

	int temp = head;
	while (list[temp].next != crnt)
	{
		temp = list[temp].next;
	}
	list[temp].next = list[crnt].next;
	DeleteIndex(crnt);
	crnt = temp;
}

void ArrayLinkedList::Clear()
{
	while (NULL != head)
	{
		RemoveFront();
	}
	crnt = NULL;
}

void ArrayLinkedList::PrintCurrent()
{
	if (NULL == crnt)	return;

	cout << list[crnt].data << endl;
}

void ArrayLinkedList::Print()
{
	if (head == NULL) cout << "X" << endl;
	else
	{
		int temp = head;
		while (temp != NULL)
		{
			cout << list[temp].data << endl;
			temp = list[temp].next;
		}
	}
}
