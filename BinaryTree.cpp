#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
	pRoot	= nullptr;
	pCur	= nullptr;
	pPre	= nullptr;
}

BinaryTree::~BinaryTree()
{
	Free();
}

bool BinaryTree::Search(int _data)
{
	// 비어있는 경우
	if (Empty())
	{
		return false;
	}

	pCur = pRoot;

	while (nullptr != pCur)
	{
		// 데이터 중복인 경우
		if (Compare(pCur, _data))	return true;

		// 왼쪽 노드로
		if (pCur->iData > _data)
		{
			pCur = pCur->pLeft;
		}
		// 오른쪽 노드로
		else
		{
			pCur = pCur->pRight;
		}
	}
	return false;
}

void BinaryTree::Add(int _data)
{
	// 데이터 셋
	pCur = pRoot;
	pPre = pCur;
	BinNode* tempNode = new BinNode;
	tempNode->iData = _data;

	// 비어있는 경우
	if (Empty())
	{
		pRoot = tempNode;
		return;
	}

	while (nullptr != pCur)
	{
		// 데이터 중복인 경우
		if (Compare(pCur, _data))	return;

		pPre = pCur;
		// 왼쪽 노드로
		if (pCur->iData > _data)
		{
			pCur = pCur->pLeft;
		}
		// 오른쪽 노드로
		else
		{
			pCur = pCur->pRight;
		}
	}
	pCur = tempNode;

	if (pPre->iData > pCur->iData)	pPre->pLeft		= pCur;
	else 							pPre->pRight	= pCur;
}

void BinaryTree::Remove(int _data)
{
	// 비어있는 경우
	if (Empty())
	{
		return;
	}

	// 데이터 셋
	pCur = pRoot;
	pPre = pCur;

	while (true)
	{
		if (nullptr == pCur)	return;
		// 데이터 중복인 경우
		if (Compare(pCur, _data))	break;

		pPre = pCur;
		// 왼쪽 노드로
		if (pCur->iData > _data)
		{
			pCur = pCur->pLeft;
		}
		// 오른쪽 노드로
		else
		{
			pCur = pCur->pRight;
		}
	}

	// 1. 자식 노드가 없는 경우
	if (nullptr == pCur->pLeft && nullptr == pCur->pRight)
	{
		if (pPre->iData > pCur->iData)	pPre->pLeft		= nullptr;
		else 							pPre->pRight	= nullptr;
	}
	// 2. 자식 노드가 1개인 경우
	else if (nullptr == pCur->pLeft || nullptr == pCur->pRight)
	{
		if (pPre->iData > pCur->iData)	pPre->pLeft = nullptr;
		else 							pPre->pRight = nullptr;
	}
	// 3. 자식 노드가 2개인 경우
	else
	{

	}

	delete pCur;
}

void BinaryTree::Print(BinNode* _node)
{
	if (_node != nullptr)
	{
		Print(_node->pLeft);
		cout << _node->iData;
		Print(_node->pRight);
	}
}

bool BinaryTree::Empty()
{
	return nullptr == pRoot;
}

bool BinaryTree::Compare(BinNode* _node, int _data)
{
	return _node->iData == _data;
}

BinNode* BinaryTree::GetRoot()
{
	return pRoot;
}

void BinaryTree::Free()
{
}
