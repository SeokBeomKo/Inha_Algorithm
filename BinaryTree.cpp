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
	// ����ִ� ���
	if (Empty())
	{
		return false;
	}

	pCur = pRoot;

	while (nullptr != pCur)
	{
		// ������ �ߺ��� ���
		if (Compare(pCur, _data))	return true;

		// ���� ����
		if (pCur->iData > _data)
		{
			pCur = pCur->pLeft;
		}
		// ������ ����
		else
		{
			pCur = pCur->pRight;
		}
	}
	return false;
}

void BinaryTree::Add(int _data)
{
	// ������ ��
	pCur = pRoot;
	pPre = pCur;
	BinNode* tempNode = new BinNode;
	tempNode->iData = _data;

	// ����ִ� ���
	if (Empty())
	{
		pRoot = tempNode;
		return;
	}

	while (nullptr != pCur)
	{
		// ������ �ߺ��� ���
		if (Compare(pCur, _data))	return;

		pPre = pCur;
		// ���� ����
		if (pCur->iData > _data)
		{
			pCur = pCur->pLeft;
		}
		// ������ ����
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
	// ����ִ� ���
	if (Empty())
	{
		return;
	}

	// ������ ��
	pCur = pRoot;
	pPre = pCur;

	while (true)
	{
		if (nullptr == pCur)	return;
		// ������ �ߺ��� ���
		if (Compare(pCur, _data))	break;

		pPre = pCur;
		// ���� ����
		if (pCur->iData > _data)
		{
			pCur = pCur->pLeft;
		}
		// ������ ����
		else
		{
			pCur = pCur->pRight;
		}
	}

	// 1. �ڽ� ��尡 ���� ���
	if (nullptr == pCur->pLeft && nullptr == pCur->pRight)
	{
		if (pPre->iData > pCur->iData)	pPre->pLeft		= nullptr;
		else 							pPre->pRight	= nullptr;
	}
	// 2. �ڽ� ��尡 1���� ���
	else if (nullptr == pCur->pLeft || nullptr == pCur->pRight)
	{
		if (pPre->iData > pCur->iData)	pPre->pLeft = nullptr;
		else 							pPre->pRight = nullptr;
	}
	// 3. �ڽ� ��尡 2���� ���
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
