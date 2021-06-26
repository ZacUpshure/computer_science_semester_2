#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

void tausche(int *e1, int *e2);
int partition(int *Array, int ui, int oi, int (*cmpfct) (int *, int *));
void qsorting(int *Array, int ui, int oi, int (*cmpfct) (int *, int*));
void QuickSorting(int *Array, int Anzahl, int (*cmpfct) (int *, int*));
int aufwaerts(int *e1, int *e2);
int abwaerts(int *e1, int *e2);

#endif // QUICKSORT_H_INCLUDED
