#ifdef TREE_H
#define TREE_H
#include <iostream>
using namespace std;
#include <assert.h>
#include "Tree.h"

template<class NODETYPE>
class Tree
{
public:
    Tree();
    void insertNode(const NODETYPE&);
    void PrefixOrderTraversal() const;
    void InfixOrderTraversal() const;
    void PostfixOrderTraversal() const;
private:
    TreeNode<NODETYPE>* rootPtr;
    void insertNodeHelper(TreeNode<NODETYPE>**, const NODETYPE&);
    void PrefixOrder(TreeNode<NODETYPE>*) const;
    void InfixOrder(TreeNode<NODETYPE>*) const;
    void PostfixOrder(TreeNode<NODETYPE>*) const;
};
template<class NODETYPE>
Tree<NODETYPE>::Tree() { rootPtr = 0; }

template<class NODETYPE>
void Tree<NODETYPE>::insertNode(const NODETYPE Evalue)
{
    insertNodeHelper(&rootPtr, value);
}
template<class NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE>** ptr, const NODETYPE& value)
{
    if (*ptr == 0)
    {
        *ptr = new TreeNode<NODETYPE>(value);
        assert(*ptr != 0);
    }
    else
        if (value < (*ptr)->data)
            insertNodeHelper(&((*ptr)->leftPtr), value);
        else
            if (value > (*ptr)->data)
                insertNodeHelper(&((*ptr)->rightPtr), value);
            else
                cout << value << "DYBL'" << endl;
}

template<class NODETYPE>
void Tree<NODETYPE>::PrefixOrderTraversal() const
{
    PrefixOrder(rootPtr);
}

template<class NODETYPE>
void Tree<NODETYPE>::PrefixOrder(TreeNode <NODETYPE>* ptr) const
{
    if (ptr != 0)
    {
        cout << ptr->data << " ";
        PrefixOrder(ptr->leftPtr);
        PrefixOrder(ptr->rightPtr);
    }
}
template<class NODETYPE>
void Tree<NODETYPE>::InfixOrderTraversal() const
{
    InfixOrder(rootPtr);
}

template<class NODETYPE>
void Tree<NODETYPE>::InfixOrder(TreeNode <NODETYPE>* ptr) const
{
    if (ptr != 0)
    {
        InfixOrder(ptr->leftPtr);
        cout << ptr->data << " ";
        InfixOrder(ptr->rightPtr);
    }
}
template<class NODETYPE>
void Tree<NODETYPE>::PostfixOrderTraversal() const
{
    PostfixOrder(rootPtr);
}

template<class NODETYPE>
void Tree<NODETYPE>::PostfixOrder(TreeNode <NODETYPE>* ptr) const
{
    if (ptr != 0)
    {
        PostfixOrder(ptr->leftPtr);
        PostfixOrder(ptr->rightPtr);
        cout << ptr->data << " ";
    }
}
#endif
