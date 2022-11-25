#include "DSU.h"
#include <iostream>
using namespace std;

int p[100000];
int rk[100000];

void init_dsu() {
    for (int i = 0; i < 100000; i++) {
        p[i] = i;
        rk[i] = 1;
    }
}

int set_find(int v) {
    if (p[v] == v) {
        return v;
    }
    else {
        return p[v] = set_find(p[v]);
    }
}

bool set_union(int v1, int v2) {
    int rv1 = set_find(v1), rv2 = set_find(v2);

    if (rv1 == rv2) {
        return false;
    }
    else {
        if (rk[rv1] < rk[rv2]) {
            p[rv1] = rv2;
        }
        else if (rk[rv2] < rk[rv1]) {
            p[rv2] = rv1;
        }
        else {
            p[rv1] = rv2;
            rk[rv2]++;
        }

        return true;
    }
}

struct edge {
    int v1, v2, len;

    bool operator<(const edge& other) {
        return len < other.len;
    }
};
