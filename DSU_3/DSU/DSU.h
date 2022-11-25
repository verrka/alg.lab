#pragma once
#ifndef DSU_H
#define DSU_H
using namespace std;

class DSU {
public:
	int p;
	int rk;
	void init_dsu();
	int set_find(int v);
	bool set_union(int v1, int v2);
};

#endif