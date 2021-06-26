#include<stdio.h>
#include<stdlib.h>
#include"quicksort.h"

void tausche(int *e1, int *e2)
{
    int temp;
    temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

int partition(int *Array, int ui, int oi, int (*cmpfct) (int *, int *))
{
    int *comp = Array + ui;
    int i = ui + 1, j = oi;

    while(i <= j)
    {
        while((i <= j) && (cmpfct(Array + i, comp) <= 0))
        {
            i++;
        }
        while((j >= i) && (cmpfct(Array + j, comp) >= 0))
        {
            j--;
        }
        if (j < i)
        {
            tausche(Array + i, Array + j);
            i++;
            j--;
        }
    }
    i--;
    tausche(comp, Array + 1);

    return 1;
}

void qsorting(int *Array, int ui, int oi, int (*cmpfct) (int *, int*))
{
    int idx;
    if(ui >= oi)
    {
        return;
    }
    else
    {
        idx = partition(Array, ui, oi, cmpfct);
        qsorting(Array, ui, idx - 1, cmpfct);
        qsorting(Array, idx + 1, oi, cmpfct);
    }
}

void QuickSorting(int *Array, int Anzahl, int (*cmpfct) (int *, int*))
{
    qsort(Array, 0, Anzahl - 1, cmpfct);
}


int aufwaerts(int *e1, int *e2)
{
    return *e1 - *e2;
}

int abwaerts(int *e1, int *e2)
{
    return *e2 - *e1;
}

