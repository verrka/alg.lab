// Lab_3_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<vector>
#include <queue>
using namespace std;

const int INF = 1e9 + 7;

vector<pair<int, int>> graph[100000];
bool used[100000];      

int main() {
   

    int min_e = 0;    

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

     q.push({ 0, 0});     

    while (!q.empty()) {
        pair<int, int> c = q.top();
        q.pop();

        int dst = c.first, v = c.second;

        if (used[v]) {      
            continue;
        }

        used[v] = true;
        min_e += dst;

        for (pair<int, int> e : graph[v]) {
            int u = e.first, len_vu = e.second;

            if (!used[u]) {
               q.push({ len_vu, u });    
            }
        }
    }

    cout << "Minimum spanning tree weight: " << min_e << endl;
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
