#pragma once
#ifdef TREENODE_H
#define TREENODE_H

typedef struct Node {
	int value;
	struct Node* lNode;
	struct Node* rNode;
}BinaryTree;

template<class NODETYPE> class TreeNode
{
    friend class Tree<NODETYPE>;
public:
    TreeNode(const NODETYPE&);
    NODETYPE getData() const;
private:
    TreeNode* leftPtr;
    NODETYPE data;
    TreeNode* rightPtr;
};
template<class NODETYPE>
TreeNode<NODETYPE>::TreeNode(const NODETYPE& d)
{
    data = d;
    leftPtr = rightPtr = 0;
}
template<class NODETYPE>
NODETUPE TreeNode<NODETYPE>::getData() const
{
    return data;
}
#endif