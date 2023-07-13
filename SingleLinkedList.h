#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int m_num;
	string m_name;

	Node* pNext;
};

class SingleLinkedList
{
private:
	Node* pHead;
	Node* pTail;
	int m_size;
public:
	SingleLinkedList();
	~SingleLinkedList();

	void push_back(Node* node);
	void push_front(Node* node);

	void pop_back();
	void pop_front();
	void pop_num(int num);

	int size();
	bool empty();

	void print();
};