#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "tools.h"

#include "datastructure.h"

#include "menu.h"

#include "team.h"

#include "database.h"


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
        //nächstes Element > *comp von links suchen (im linken Teil)
        while( (i <= j) && (cmpfct(Array + i, comp) <= 0))
            i++;
        //nächstes Element < *comp von rechts suchen (im rechten Teil)
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

    return i; // Position des Grenzwertes zurückgeben
}


void qusort (sPlayer *Array, int ui, int oi, int(*cmpfct)(sPlayer *, sPlayer *))
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
    int i;

    for(i=0; i<TeamCounter; i++)
    {
            sTeam *currentTeamtoSort = Teams + i;
            listOneTeamname(currentTeamtoSort);
            qusort(currentTeamtoSort -> Player, 0, (currentTeamtoSort -> numberofplayer) - 1, cmpfct);
    }
}
/*
int main()
{
    int i;
    int Zahlen[5] = {12, 5, 3, 7, 23};
    QuickSort(Zahlen, 5);
    for(i = 0; i < 5; i++)
    printf("%i\n", Zahlen[i]);
    return 0;
}

int aufwärts(int *e1, int *e2)
{
    return *e1 - *e2;
}

int abwärts(int *e1, int *e2)
{
    return *e2 - *e1;
}
*/
