#include "Trree.h"
#include <iostream>
#include <iomanip>


NodePtr BST::BSTminimum(NodePtr x)
{
    while (x->left != NIL)
        x = (x->left);
    return x;
}

NodePtr BST::BSTsuccessor(NodePtr x)
{
    NodePtr y;

    if (x->right != NIL)
    {
        return BSTminimum(x->right);
    }
    y = x->p;
    while (y != NIL && x == y->right)
    {
        x = y;
        y = y->p;
    }
    return y;
}

void BST::BSTinsert(NodePtr z)
{
    NodePtr y;
    NodePtr x;
    y = NIL;
    x = root;
    while (x != NIL)
    {
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }

    }
    z->p = y;
    if (y == NIL)
    {
        root = z;
    }
    else if (z->key < y->key)
    {
        y->left = z;
    }
    else
        y->right = z;
}

void BST::Transplant(NodePtr u, NodePtr v)
{
    if (u->p == NIL)
    {
        root = v;
    }
    else if (u == u->p->left)
    {
        u->p->left = v;
    }
    else
    {
        u->p->right = v;
    }
    if (v != NIL)
    {
        v->p = u->p;
    }
}

void BST::BSTdelete(NodePtr z)
{
    NodePtr y;
    if (z->left == NIL)
    {
        Transplant(z, z->right);
    }
    else if (z->right == NIL)
    {
        Transplant(z, z->left);
    }
    else
    {
        y = BSTminimum(z->right);
        if (y->p != z)
        {
            Transplant(y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        Transplant(z, y);
        y->left = z->left;
        y->left->p = y;
    }
}

NodePtr BST::BSTsearch(NodePtr x, KeyType k)
{
    if ((x == NIL) || (k == x->key))
    {
        return x;
    }
    if (k < x->key)
    {
        return BSTsearch(x->left, k);
    }
    else
    {
        return BSTsearch(x->right, k);
    }
}