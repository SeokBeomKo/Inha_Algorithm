#include "ChainHashTable.h"

ChainHashTable::ChainHashTable()
{
	pTable = new list<ChainHashNode>[SIZE];
	iAdrress = 0;
}

ChainHashTable::~ChainHashTable()
{
	delete[] pTable;
}

void ChainHashTable::Add(ChainHashNode _node)
{
	iAdrress = Hash(_node.iKey);

	if (Find(pTable[iAdrress], _node.iKey))
	{
		cout << "이미 존재하는 키 값" << endl;
		return;
	}

	pTable[iAdrress].push_front(_node);
}

void ChainHashTable::Remove(int _key)
{
	iAdrress = Hash(_key);

	if (!Find(pTable[iAdrress], _key))
	{
		cout << "존재하지않는 키 값" << endl;
		return;
	}

	list<ChainHashNode>::iterator iter = pTable[iAdrress].begin();

	while (iter != pTable[iAdrress].end())
	{
		if (iter->iKey == _key)
		{
			pTable[iAdrress].erase(iter);
			return;
		}
		++iter;
	}
}

void ChainHashTable::Print()
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << i;
		for (ChainHashNode _node : pTable[i])
		{
			cout << " : " << "(" << _node.iKey << ")" << _node.iData;
		}
		cout << endl;
	}
}

bool ChainHashTable::Find(list<ChainHashNode> _pTable, int _key)
{
	for (ChainHashNode _node : _pTable)
	{
		if (_node.iKey == _key) return true;
	}
	return false;
}

bool ChainHashTable::Search(int _key)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (ChainHashNode _node : pTable[i])
		{
			if (_node.iKey == _key) return true;
		}
	}return false;
}
