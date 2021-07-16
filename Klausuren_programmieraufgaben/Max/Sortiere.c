

void BubbleSort(String *Array, int Anzahl, int (*Vergleich)(String, String))
{
     int i, j;
     char temp[MAXLEN];
     for (i = 1; i < Anzahl; i++)
     for (j = Anzahl - 1; j >= i; j--)
     if (Vergleich(*(Array + j), *(Array + j - 1)) < 0)
     {
        strcpy(temp, *(Array + j));
        strcpy(*(Array + j), *(Array + j - 1));
        strcpy(*(Array + j - 1), temp);
     }
}


/***********************************************************
Die Funktion sortiere soll das angegebene Array von Zeichenketten mittels der
BubbleSort- und der Vergleichsfunktion sortieren.
Schließlich muss noch die Vergleichsfunktion erstellt werden, die zwei Zeichenketten
erhält und diese miteinander vergleicht (z.B. mit strcmp).
***********************************************************/

void sortiere(String *ArrayZeiger)
{
    BubbleSort(ArrayZeiger, MAX, vergleichsfunktion); // Anzahl = wie viele Elemente werden sortiert -> MAX
}


void sortiere(char **K)
{
    BubbleSort(K, MAX,Vergleich);
}




 
/***********************************************************
*    Labor Aufgaben
* QuickSort Funktion mit Aufruf
***********************************************************/
void tausche(sPlayer *e1, sPlayer *e2)
{
    sPlayer temp;

    temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

int partition(sPlayer *Array, int ui, int oi, int (*cmpfct)(sPlayer *, sPlayer *))
{
    sPlayer *comp = Array + ui; // Zeiger auf Grenzwert
    int i = ui + 1, j = oi; // Laufinidizes

    while (i <= j)
    {
        //n�chstes Element > *comp von links suchen (im linken Teil)
        while( (i <= j) && (cmpfct(Array + i, comp) <= 0))
            i++;
        //n�chstes Element < *comp von rechts suchen (im rechten Teil)
        while( (j >= i) && (cmpfct(Array + j, comp) >= 0))
            j--;
        if(i < j)
        {
            tausche(Array + i, Array + j); // ZEIGER BLEIBEN !!!!
            i++;
            j--;
        }
    }
    i--;
    //setze Grenzwert zwischen beide Teile
    tausche(comp, Array + i);

    return i; // Position des Grenzwertes zur�ckgeben
}


void qusort (sPlayer *Array, int ui, int oi, int(*cmpfct)(sPlayer *, sPlayer *)) // (Array, begin array sortierung, ende..., cmpfct)
{
    int idx; // Grenzwert einer Zerlegung

    if (ui >= oi) // Abbruchbedingung der Rekursion
        return;
    else
    {
        idx = partition(Array, ui, oi, cmpfct);
        qusort(Array, ui, idx - 1, cmpfct); //linken Teil rekusriv sortieren
        qusort(Array, idx + 1, oi, cmpfct); //rechten Teil rekusrsiv sortieren
    }
}

void QuickSort(int(*cmpfct)(sPlayer *, sPlayer *))
{
    sTeam *currentTeamtoSort;

    for(currentTeamtoSort = FirstTeam; currentTeamtoSort != NULL; currentTeamtoSort = currentTeamtoSort->Next)
    {
            listOneTeamname(currentTeamtoSort);
            qusort(currentTeamtoSort -> Player, 0, (currentTeamtoSort -> numberofplayer) - 1, cmpfct);
    }
}





void sort(TAdresse **Adr, int Anz, int (*cmpFkt)(TAdresse*,TAdresse*))
{
    int i, j;
    TAdresse *tmp;

    for (i = 1; i < Anz; i++)
    {
        for(j = Anz - 1; j >= i; j--)
        {
            if(cmpFkt(*(Adr + j), *(Adr + j-1)) < 0)
            {
                tmp = *(Adr + j);
                *(Adr + j) = *(Adr + j);
                *(Adr + j - 1) = tmp;
            }
        }
    }

}







//QuickSort(sortnames);

/*
for(i=0; i<TeamCounter; i++)
    {
            sTeam *currentTeamtoSort = Teams + i;
            listOneTeamname(currentTeamtoSort);
            qusort(currentTeamtoSort -> Player, 0, (currentTeamtoSort -> numberofplayer) - 1, cmpfct);
    }
*/




