// lab_3_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../DSU/DSU/DSU.h"
#include "../../DSU/DSU/DSU.cpp"
#include <iostream>
#include <vector>
int main() {

        vector<edge> edges;
        

        sort(edges.begin(), edges.end());

        int mst_weight = 0;

        init_dsu();

        for (edge e : edges) {
            if (set_union(e.v1, e.v2)) {      
                mst_weight += e.len;    
            }
        }

        cout << "Minimum spanning tree weight: " << mst_weight << endl;
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
