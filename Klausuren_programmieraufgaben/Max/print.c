/******************************************************************************
 * Ermittelt den Torschützenkönig und gibt diesen auf dem Bildschirm aus. Sind
 * mehrere Spieler Torschützenkönig, wird nur der erste Spieler ausgegeben.
 * Parameter: keine
 * Ergebnis: keins
 ******************************************************************************/
void printTopscorer()
{
 int i;
 TPlayer *Topscorer = NULL;
 int MaxTore = 0;
 for (i = 0; i < Anzahl; i++)
 {
     if ((*(Spieler + i))->Goals > MaxTore)
     {
     MaxTore = (*(Spieler + i))->Goals;
     Topscorer = *(Spieler + i);
     }
 }
 if (Topscorer != NULL)
 {

     printf("Torschuetzenkoenig: %s ", Topscorer->Name);
     printf("mit %i Toren\n\n", Topscorer->Goals);
 }
 else
    printf("Keinen Torschuetzenkoenig gefunden!\n\n");
}
/*****************************************************************************
Die Funktion printTeam soll eine Liste von allen Spielern einer Mannschaft auf
dem Bildschirm ausgeben (siehe Beispielausgabe). Als Parameter wird die 
gewünschte Mannschaft als Zeichenkette übergeben.
******************************************************************************/
void printTeam(char *teamname)
{
    int Anz = 0;
    int i;
    printf("Mannschaftsliste : %s\n", teamname);
    for (i = 0; i < Anzahl; i++)
    {
		//Vergleich zwischen Teamnamen welcher im Spieler[Array] liegt und übergebenen Parameter
        if(strcmp((*(Spieler + i))->Teamname, teamname)== 0) 
        {
			// "->" hat höhere Priorität als "*" deswegen *(Spieler + i))->Teamname
            Anz++;
            printf("%02i :%s (Tore: %i)\n",Anz ,(*(Spieler + i))->Name, (*(Spieler + i))->Goals);
        }
    }
    if(Anz == 0)
    {
        printf("keine Spieler gefunden\n");
    }
    printf("\n");
}

/***********************************************************
*    Labor Aufgaben
***********************************************************/

void listOnePlayer(sPlayer *playertoprint)
{
        printf("%s\n", playertoprint->Playernames);
        printf("  (Trikotnummer: %i) ", playertoprint->jerseynumber);
        printf("\nGeburtstag: %02u.%02u.%04i;  ", playertoprint->dateofbirth->Day, playertoprint->dateofbirth->Month, playertoprint->dateofbirth->Year);
        printf("\nTore: %i\n", playertoprint->goals);
        printLine('_', 30);
        printf("\n");
}
void listOneTeam(sTeam *Team)
{

    char *Name         = "\nName : ";
    char *trainer      = "\nTrainer        :";
    char *anzahlplayer = "\nAnzahl Spieler :";
    char *pPlayer      = "\nSpieler        :\n";
    int i;

    printf("%s%s", Name, Team->teamname);
    if (Team->trainername == NULL)
    {
        printf("%s <dieser Posten ist vakant>", trainer);

    }

    else
    {
        printf("%s%s", trainer, Team->trainername);

    }
     printf("%s%i", anzahlplayer, Team->numberofplayer);
     printf("%s", pPlayer);

    //Spieler Ausgabe
    for(i = 0; i < Team -> numberofplayer; i++)
    {
        printf("%02i. ", i+1);
        listOnePlayer(Team->Player + i);
    }
}


for(listingTeam = FirstTeam; listingTeam != NULL; listingTeam = listingTeam->Next)
      {
          char *Team = "Team";
          printf("\n%s: %i\n", Team, i+1);
          printLine('-', 20);
          listOneTeam(listingTeam);
          i++;
      }




void showOrdner(Schrank *S, int ONr) // ONr: Ordnernr.
{
    Akte *Temp = NULL;
    if ((S != NULL) && (ONr >= 1) && (ONr <= MAXORDNER))
    {
        printf("Alle Akten anzeigen:\n");
        printf("====================\n");
        printf("Schrank-Nr.: %i\n", S->SchrankNr);
        printf("Ordner-Nr.: %i\n", ONr);
        Temp = S->OA[ONr - 1].E;
        while (Temp != NULL)
        {
            printf("Belegnr. %i: %s\n", Temp->BelegNr, Temp->Betreff);
            Temp = Temp->Next;
        }
    }
    else
        printf("Es wurde kein gültiger Schrank angegeben!\n");
}




void printMesswert()
{
    TMesswert *temp = First;
    printf("Tagestemperaturen\n");

    if(temp == NULL)
        printf("Es liegen keine Messwerte vor!\n");
    else
        while(temp)
        {
            printf("%02i:00 Uhr: %4.1f°C\n", temp->Stunde,temp->Temperatur);
            temp = temp->Next;
        }
}



void printMesswert()
{
    TMesswert *temp = First;
    printf("Tagestemperaturen\n");

    if(temp == NULL)
        printf("Es liegen keine Messwerte vor!\n");
    else
        while(temp)
        {
            printf("%02i:00 Uhr: %4.1f°C\n", temp->Stunde,temp->Temperatur);
            temp = temp->Next;
        }
}

void printTeam(char *TN)
{
    int i;
    int Anz = 0;

    for (i = 0; i < Anzahl; i++)
    {
        if (strcmp((*(Spieler + i))->Teamname, TN) == 0)
        {
            Anz++;
            printf("%02i: %s (Tore %i)\n", Anz, (*(Spieler + i))->Name, (*(Spieler + i))->Goals);
        }
    }
    if(Anz == 0)
    {
        printf("Keine Spieler gefunden!\n");
        printf("\n");
    }
}


void printMesswert()
{
    TMesswert *temp = First;
    printf("Tagestemperaturen\n");

    if(temp == NULL)
        printf("Es liegen keine Messwerte vor!\n");
    else
        while(temp)
        {
            printf("%02i:00 Uhr: %4.1f°C\n", temp->Stunde,temp->Temperatur);
            temp = temp->Next;
        }
}





void printMesswert()
{
    TMesswert *temp = First;
    printf("Tagestemperaturen\n");

    if(temp == NULL)
        printf("Es liegen keine Messwerte vor!\n");
    else
        while(temp)
        {
            printf("%02i:00 Uhr: %4.1f°C\n", temp->Stunde,temp->Temperatur);
            temp = temp->Next;
        }
}










