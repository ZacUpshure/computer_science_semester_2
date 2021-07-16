
/**************************************************
Die Funktion deleteAllPlayer soll die reservierten 
Speicherbereiche der Spieler wieder freigeben  
Parameter und Ergebnis sind void.
**************************************************/

void deleteAllPlayers()
{
    // für doppelt verkette Liste angucken
    int i;
    for (i = 0; i < Anzahl; i++)
    {
        free((*(Spieler + i))->Name);
        free((*(Spieler + i))->Teamname);
        free(*(Spieler + i));

    }
}

// reset Funktion setzt Array Elemente auf NULL;

void resetArray(char **Array)
{
    int i;
    for (i = 0; i < MAX; i++)
        *(Array + i) = NULL;
}

/***********************************************************
*    Labor Aufgaben
***********************************************************/

void freeOnePlayer(sPlayer *Player)
{
    free(Player -> Playernames);
    free(Player -> dateofbirth);
}

void freeOneTeam(sTeam *Team)
{
    int j;
    free(Team -> teamname);
    free(Team -> trainername);
    for(j = 0; j < Team->numberofplayer; j++)
    {
        freeOnePlayer(Team -> Player + j);
    }

}

void freeTeams()
{
    sTeam *freeTeam;
    for(freeTeam = FirstTeam; freeTeam != NULL; freeTeam = freeTeam->Next)
    {
      freeOneTeam(freeTeam);
    }
}




void freeAdressen()
{
    int i;

    for(i = 0; i<AnzAdressen; i++)
    {
        free((*(Adressen + i))->Birthday);
        free(*(Adressen + i));
    }
}




TMesswert *removeMesswert(int S)
{
    TMesswert *temp = First;
    TMesswert *prev = First;
    if(First == NULL)
    {
        return NULL;
    }
    if(First->Stunde == S)
    {
        temp = First;
        if(First == Last)
        {
            Last = NULL;
        }
        First = First -> Next;
        return temp;
    }
    temp = First->Next;
    while(temp!=NULL)
    {
        if(temp->Stunde == S)
        {
            prev->Next=temp->Next;
            if(temp == Last)
            {
                Last = prev;
            }
            return temp;
        }
        prev = temp;
        temp = temp->Next;
    }
    return NULL;
}



void freeAdressen()
{
    int i;

    for(i = 0; i<AnzAdressen; i++)
    {
        free((*(Adressen + i))->Birthday);
        free(*(Adressen + i));
    }
}



