#pragma once
#include <list>
#include <iostream>

using namespace std;

#define SIZE 13

struct ChainHashNode
{
	int iData;
	int iKey;
};

class ChainHashTable
{
private:
	list<ChainHashNode>* pTable;
	int iAdrress;

	int Hash(int key)
	{
		// ³ª´°¼À ¹ý
		return key % SIZE;
	}
public:
	ChainHashTable();
	~ChainHashTable();

	void Add(ChainHashNode _node);
	void Remove(int _key);

	void Print();

	bool Find(list<ChainHashNode> _pTable, int _key);
	bool Search(int _key);
};

