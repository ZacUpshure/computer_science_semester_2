#include <stdio.h>
#include <stdlib.h>
#include "einfachverketteteliste.h"

int compareIndex(ListElement *LE1, ListElement *LE2)
{
    return (LE1->Index - LE2->Index);
}

int main()
{
    ListElement *tmp = NULL;

    insertListElement(createListElement(5, 17.3), compareIndex);
    insertListElement(createListElement(2, 24.7), compareIndex);
    insertListElement(createListElement(4, 3.9 ), compareIndex);
    insertListElement(createListElement(1, 31.4), compareIndex);
    insertListElement(createListElement(3, 53.1), compareIndex);
    insertListElement(createListElement(6, 49.6), compareIndex);

    tmp = getFirstElement();
    printf("Liste der Daten\n");
    printf("===============\n");
    while(tmp)
    {
        printf("%3i | %5.lf\n", tmp->Index, tmp->Value);
        tmp = tmp->Next;
    }
    while(tmp = getFirstElement())
    {
        free(removeListElement(tmp, compareIndex));
    }
    return 0;
}
/*
int compareIndex(ListElement *LE1, ListElement *LE2)
{
    return (LE1->Index - LE2->Index);
}

int compareValue(ListElement *LE1, ListElement *LE2)
{
    return (LE1->Value - LE2->Value);
}

int main()
{
    ListElement *tmp = NULL;
    ListElement Loeschen;
    int i;

    insertListElement(createListElement(5, 17.3), compareValue);
    insertListElement(createListElement(2, 24.7), compareValue);
    insertListElement(createListElement(4, 3.9), compareValue);
    insertListElement(createListElement(1, 31.4), compareValue);
    insertListElement(createListElement(3, 53.1), compareValue);
    insertListElement(createListElement(6, 49.6), compareValue);

    tmp = getFirstElement();
    printf("Liste der Daten\n");
    printf("===============\n");
    while (tmp)
    {
        printf("%3i | %5.1f\n", tmp->Index, tmp->Value);
        tmp = tmp->Next;
    }
    for (i = 1; i <= 6; i++)
    {
        Loeschen.Index = i;
        free(removeListElement(&Loeschen, compareIndex));
    }
    return 0;
}*/
