#include "Sort.h"
#include <iostream>
using namespace::std;

void my_class::merge(int a[], int low, int mid, int high)
{
    int b[10] = { 0 };
    int k = 0;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i];
            i++;
        }
        else {
            b[k++] = a[j];
            j++;
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= high)
    {
        b[k++] = a[j++];

    }
   
    for (int i = low ; i <= high; i++)
    {
        a[i] = b[i-low];
    }


}
void my_class::mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = ((low + high)  / 2);
    }
    

    mergesort(a, low,mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}