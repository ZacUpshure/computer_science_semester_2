/******************************************************************************
 * Erzeugt einen neuen Spieler. Dazu wird für den Spieler Speicher reserviert
 * und die Daten des Spielers (Parameter) in diesen Speicher kopiert
 * Parameter: Name - Name des Spielers
 * Goals - Anzahl der geschossenen Tore
 * Teamname - Name der Mannschaft
 * Ergebnis: Zeiger auf den reservierten Speicherbereich, in dem die Daten des
 * Spielers hineinkopiert wurden; NULL-Zeiger, wenn kein Speicher
 * reserviert werden konnte.
 ******************************************************************************/
TPlayer *createPlayer(char *Name, int Goals, char *Teamname)
{
 TPlayer *Neu = malloc(sizeof(TPlayer)); // zuletzt löschen
 if (Neu)
 {
 Neu->Name = malloc(strlen(Name) + 1); // Zuerst löschen
 if (Neu->Name)
 strcpy(Neu->Name, Name);
 Neu->Goals = Goals;
 Neu->Teamname = malloc(strlen(Teamname) + 1); // als 2tes löschen
 if (Neu->Teamname)
 strcpy(Neu->Teamname, Teamname);
 }
 return Neu;
}

/***********************************************************
*    Labor Aufgaben
***********************************************************/

void createTeam() {
  printf("\ncreateTeam\n\n");
  //sTeam *Team = Teams + TeamCounter;
  sTeam *Team;
  Team = malloc(sizeof(sTeam));
  Team->Next = NULL;
  Team->Prev = NULL;


     Team->numberofplayer = 0;
     getText("Geben sie bitte den Teamnamen ein\n->", 50, &(Team->teamname), 0);
     getText("Geben sie bitte den Trainernamen ein\n->", 50, &(Team->trainername), 1);

   do
    {
        addPLayer(Team->Player + Team->numberofplayer);
        Team->Player->goals = 0;
        Team->numberofplayer++;

    }while(askYesOrNo("Moechten Sie einen weiteren Spieler anlegen?"));
    TeamCounter++;
    insertListElement(Team, sortTeam);

  return;
}