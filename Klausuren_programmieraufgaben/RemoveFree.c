
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