#pragma once
#define Sort_hpp
using namespace std;
class ver_class {
public:
	int Partition(int arr[], int low, int high);
	int RandomizedPartition(int arr[], int low, int high);
	void QuickSort(int arr[], int low, int high);
};