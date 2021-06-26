#ifndef EINFACHVERKETTETELISTE_H_INCLUDED
#define EINFACHVERKETTETELISTE_H_INCLUDED

typedef struct sLE
{
    int Index;
    double Value;
    struct sLE *Next;
}ListElement;

extern ListElement *First, *Last;

//dekleration von Funktionen:
ListElement *createListElement(int, double);
void appendListElement(ListElement *);
void insertListElement(ListElement *, int (*) (ListElement *, ListElement *));
ListElement *removeListElement(ListElement *, int (*) (ListElement *, ListElement *));
ListElement *getFirstElement();

#endif // EINFACHVERKETTETELISTE_H_INCLUDED
