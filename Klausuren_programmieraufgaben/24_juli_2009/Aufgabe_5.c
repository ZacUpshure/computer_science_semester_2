//Funktionsdekleration

void showOrdner(Schrank *S, int O);
void appendAkte(Schrank *S, int O, int bn, char *bet);

//Funktionsdefinition

void showOrdner(Schrank *S, int O)
{
    Akte *a;
    printf("Schrank %4i Ordner %4i\n", S->SchrankNr, 0);
    a = S->oA[0-1].E;
    while(a)
    {
        printf("Belegnr. %3i : %s\n", a->BelegNr, a->Betreff);
        a = a->Next;
    }
}

void appendAkte(Schrank *S, int O, int bn, char *bet)
{
    Akte *a = malloc(sizeof(Akte));
    Akte *aptr = S->OA[0-1].E;
    if(!aptr)
    {
        S->OA[0-1].E = S->OA[0-1].L = a;
    }
    else
    {
        if(aptr->Next != NULL)
        {
            while(aptr->Next != S->OA[0-1].L)
            {
                aptr = aptr->Next;
                aptr->Next = a;
                S->OA[0-1].L = a;
            }
            a->Next = NULL;
            a->BelegNr = bn;
            a->Betreff = malloc(sizeof(char) *strlen(bet));
            strcpy(bet.a->Betreff);
        }
    }
}
