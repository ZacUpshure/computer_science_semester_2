#include<stdio.h>
#include<stdlib.h>
#include "einfachverketteteliste.h"

ListElement *First = NULL, *Last = NULL;

ListElement *createListElement(int I, double V)
{
    ListElement *New = malloc(sizeof(ListElement));
    if(New)
    {
        New->Index = I;
        New->Value = V;
        New->Next = NULL;
    }
    return NULL;
}

void appendListElement(ListElement *New)
{
    if(New)
    {
        if(First == NULL)
        {
            First = Last = New;
        }
        else
        {
            Last = Last->Next;
        }
    }
}

void insertListElement(ListElement *New, int (*cmpfct) (ListElement *, ListElement *))
{
    ListElement *tmp = First;
    if(New)
    {
        if(First == 0)
        {
            First = Last = New;
        }
        else if(cmpfct(First, New) >= 0)
        {
            New->Next=First;
            First=New;
        }
        else if(cmpfct(Last, New) >= 0)
        {
            Last = Last->Next = New;
        }
        else
        {
            while(tmp->Next)
            {
                if(cmpfct(tmp->Next, New) > 0)
                {
                    New->Next = tmp->Next;
                    tmp->Next = New;
                    break;
                }
                tmp = tmp->Next;
            }
        }
    }
}

ListElement *removeListElement(ListElement *Remove, int (*cmpfct) (ListElement *, ListElement *))
{
    ListElement *prv = First, *tmp = NULL;
    if(Remove)
    {
        if(First == NULL)
        {
            ;
        }
        else if(cmpfct(First, Remove) == 0)
        {
            tmp = First;
            First = First->Next;
            if (First == NULL)
            {
                Last = NULL;
            }
            else
            {
                tmp = prv->Next;
                while(tmp)
                {
                    if(cmpfct(tmp, Remove) == 0)
                    {
                        prv->Next = tmp->Next;
                        if(prv->Next == NULL)
                        {
                            Last = prv;
                            break;
                        }
                        prv = prv->Next;
                        tmp = tmp->Next;
                    }
                }
                //return tmp;
            }
        }
    }
    return tmp;
}

ListElement *getFirstElement()
{
    return First;
}

