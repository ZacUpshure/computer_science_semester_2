

int vergleichsfunktion(String T1, String T2)
{
    return strcmp(T1, T2);

}

/***********************************************************
*    Labor Aufgaben
***********************************************************/

int sortjerseynumber(sPlayer *e1, sPlayer *e2) // einfache Zahlen Sortierung
{
        return e1->jerseynumber - e2->jerseynumber;
}

int sortnames(sPlayer *e1, sPlayer *e2) // nach Namen sortieren ansonsten nach jerseynumber
{
    if(strcmp(e1->Playernames, e2->Playernames) != 0)
        return strcmp(e1->Playernames, e2->Playernames);
    else
        return sortjerseynumber(e1, e2);
}

int sortbirthday(sPlayer *e1, sPlayer *e2) // Datumsstruktur sortieren (Jahr, Monat, Tag)
{
    if((e1->dateofbirth->Year - e2->dateofbirth->Year) != 0)
        return e1->dateofbirth->Year - e2->dateofbirth->Year;
    else if((e1->dateofbirth->Month - e2->dateofbirth->Month) != 0)
        return e1->dateofbirth->Month - e2->dateofbirth->Month;
    else if((e1->dateofbirth->Day - e2->dateofbirth->Day) != 0)
        return e1->dateofbirth->Day - e2->dateofbirth->Day;
    else
        return sortnames(e1, e2);
}



int compareDate(TDate *date1, TDate *date2)
{
    int i;
    i = date1->Year-date2->Year;
    if(i)
    {
        return i;
    }
    else
    {
        i = date1->Month-date2->Month;
        if(i)
        {
            return i;
        }
        else
        {
            return date1->Day-date2->Day;
        }
    }
}



int compareBirthday(TAdresse* A1, TAdresse* A2)
{
    int i = 0;
    if(A1->Birthday && A2->Birthday)
    {
        i=(A1->Birthday->Year-A2->Birthday->Year);
        if(i == 0)
        {
            i = (A1->Birthday->Day-A2 ->Birthday->Month);
            if(i=0)
            {
                i=(A1->Birthday->Day-A2->Birthday->Day);
            }
        }
    }
    return i;
}





int sortgoals(sPlayer *e1, sPlayer *e2) // sortieren nach tordiff ansonsten nach names
{
    int tordiff = e1->goals - e2->goals;

    if(tordiff != 0)
    {
        return tordiff;
    }
    else
    {
        return sortnames(e1, e2);
    }
}