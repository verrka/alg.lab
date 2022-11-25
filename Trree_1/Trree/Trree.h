#pragma once
#ifndef BST_H
#define BST_H

using namespace std;

#define NULL 0
#define NIL 0

typedef int KeyType;

typedef class Node* NodePtr;

class Node {
public:
	KeyType key;
	NodePtr p;
	NodePtr left;
	NodePtr right;

	// Constructor
	Node(KeyType k = 0) : key(k), p(NIL), left(NIL), right(NIL) {}
};

class BST {
	void Transplant(NodePtr u, NodePtr v);
	void inorderTreeWalk(NodePtr x);

public:
	NodePtr root;

	// Constructor
	BST() : root(NIL) {}

	void BSTinsert(NodePtr z);
	void BSTdelete(NodePtr z);
	NodePtr BSTsearch(NodePtr x, KeyType key);

	NodePtr BSTminimum(NodePtr x);
	NodePtr BSTsuccessor(NodePtr x);

	void ShowTree(NodePtr x, int depth);
	void PrintTree();
};

#endif
