int appendVideoInList(TVideo *Neu)
{
    if(Neu)
    {
        if(First == NULL)
        {
            First = Last = Neu;
        }
        else
        {
            Last = Last->Next=Neu;
        }
        Neu->Next=NULL;
        return 1;
    }
    return 0;

}


int appendMesswerte(TMesswert *Neu)
{
    if(Neu)
    {
        if(First == NULL)
        {
            First = Last = Neu;
        }
        else
        {
            Last = Last->Next=Neu;
        }
        Neu->Next=NULL;
        return 1;
    }
    return 0;
}



void appendMesswerte(TMesswert *Neu)
{
    if (Neu)
    {
        Neu->Next = NULL;

        if (!First)
            First = Last = Neu;
        else
            Last = Last->Next = Neu;
    }
}

