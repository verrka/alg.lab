// Lab1_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../Trree/Trree/Trree.h"
#include "../../Trree/Trree/Trree.cpp"
#include <iostream>

    void BST::inorderTreeWalk(NodePtr x)
    {
        if (x != NIL)
        {
            inorderTreeWalk(x->left);
            cout << x->key << " ";
            inorderTreeWalk(x->right);
        }
    }

    
    void BST::PrintTree()
    {
        cout << "Tree elements in order:\n";
        inorderTreeWalk(root);
        cout << "\n\n";
    }

   
    void BST::ShowTree(NodePtr x, int depth)
    {
        if (x != NIL) {
            ShowTree(x->right, depth + 1);
            cout << setw(depth * 6 + 4) << x->key << endl;
            ShowTree(x->left, depth + 1);
        }
    }


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
