#pragma once

struct BinNode 
{
	int			iData;

	BinNode*	pParent = nullptr;
	BinNode*	pLeft	= nullptr;
	BinNode*	pRight	= nullptr;
};

class BinaryTree
{
private:
	BinNode*	pRoot;

	BinNode*	pPre;
	BinNode*	pCur;
public:
	BinaryTree();
	~BinaryTree();

	void Add(int _data);
	void Remove(int _data);

	bool Search(int _data);
	void Print(BinNode* _node);
	bool Empty();
	bool Compare(BinNode* _node, int _data);

	BinNode* GetRoot();

	void Free();
};

