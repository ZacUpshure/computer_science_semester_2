#include<stdio.h>
#include<stdlib.h>
#include"quicksort.h"

int main()
{
    int Zahlen[12] = {27, 59, 3, 17, 41, 45, 12, 13, 86, 33, 67, 1};
    QuickSorting(Zahlen, 12, aufwaerts);
    QuickSorting(Zahlen, 12, abwaerts);

    return 0;
}


