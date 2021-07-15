//Funktionsdekleration

void printMesswerte();
int appendMesswert(TMesswert *);
TMesswert *removeMesswert(int);

//Funktionsdefinition

void printMesswerte()
{
    TMesswerte *temp = First;
    printf("Tagestemperaturen");
    if (temp == NULL)
    {
        printf("Es liegen keine Messwerte vor!\n");
    }
    while(temp)
    {
        printf("%02i : 00_uhr : %4.1f^c\n", temp->Stunde, temp->Temperatur);
        temp = temp->Next;
    }
}

int appendMesswert(TMesswert *M)
{
    if(M)
    {
        if(First == NULL)
        {
            First = Last = M;
        }
        else
        {
            Last = Last->Next = M;
        }
        M->Next=NULL;
        return 1;
    }
    return 0;
}

TMesswert *removeMesswet(int S)
{
    TMesswert *temp = First;
    Tmesswert *prev = First;
    if(First == NULL)
    {
        return NULL;
    }
    if(First->Stunde == S)
    {
        temp = First;
        if (First == Last)
        {
            Last = NULL;
        }
        First = First->Next
        return temp;
    }
    temp=First->Next;
    while(temp != NULL)
    {
        if(temp->Stunde == S)
        {
            prev->Next = temp->Next;
            if(temp == Last)
            {
                Last = Prev;
            }
            return temp;
        }
        prev = temp;
        temp = temp->Next;
    }
    return NULL;
}
