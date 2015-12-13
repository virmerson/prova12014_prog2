#include "QuickSort.h"
#include "MySet.h"


int partition (MySet *V, int p, int r)
{
    int x=V->data[p]; int i=p-1; int q=r+1; int temp;
    while (1) {
        do {  q--; } while (V->data[q] > x);
        do {  i++; } while (V->data[i] < x);
        if(i < q)  { temp = V->data[i];
            V->data[i] = V->data[q];
            V->data[q] = temp;
        }
        else return q;
    }
} 


void quickSort(MySet* V, int p, int r)
{
    if (p < r)
    {
        int q  = partition (V, p, r);
        quickSort(V, p, q);
        quickSort(V, q+1, r);
    }
}