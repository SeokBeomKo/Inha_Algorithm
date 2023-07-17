#pragma once
#include <iostream>

using namespace std;

struct Node {
	string data;
	int next;
	int Fnext;
};

class ArrayLinkedList
{
private:
	Node* list;
	int head;
	int max;
	int deleted;
	int crnt;
public:
	void Init(int _size);

	int GetIndex();
	void DeleteIndex(int _index);

	void AddFront(string _data);
	void AddNear(string _data);

	void RemoveFront();
	void RemoveNear();
	void RemoveCurrent();

	void Clear();
	void PrintCurrent();
	void Print();
};

