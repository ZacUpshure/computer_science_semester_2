#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "tools.h"

#include "sort.h"

#include "menu.h"

#include "datastructure.h"

#include "datetime.h"

#include "database.h"

void addPLayer(sPlayer *);

// Globale Variablen (in struct hinzugefügt)

 int TeamCounter = 0;

 sTeam Teams[MAXTEAMS];

// Funktionen für das Menü

/*
Teams ist ein Array das eine maximal Anzahl von MAXTEAMS = 10 aufnehmen kann
durch Deklarieurng werden für jedes Element die verscheidenen Variablen dem Element hinzugefügt
*/
int sortjerseynumber(sPlayer *e1, sPlayer *e2)
{
    //int i;
    //for(i=0; i < Team->numberofplayer; i++)
        //void QuickSort(playertosort->jerseynumber, Team->numberofplayer);
        return e1->jerseynumber - e2->jerseynumber;

}

int sortnames(sPlayer *e1, sPlayer *e2)
{
    if(strcmp(e1->Playernames, e2->Playernames) != 0)
        return strcmp(e1->Playernames, e2->Playernames);
    else
        return sortjerseynumber(e1, e2);
}

int sortbirthday(sPlayer *e1, sPlayer *e2)
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


int sortgoals(sPlayer *e1, sPlayer *e2) // sPlayer *e1, sPlayer *e2
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

void createTeam() {
  printf("\ncreateTeam\n\n");
  sTeam *Team = Teams + TeamCounter;

 /* if(TeamCounter > MAXTEAMS)
  printf("Die maximale Teamgrenze ist erreicht");  warum klappt das nicht?
  return;

  */

     Team->numberofplayer = 0;
     getText("Geben sie bitte den Teamnamen ein\n->", 50, &(Team->teamname), 0);
     getText("Geben sie bitte den Trainernamen ein\n->", 50, &(Team->trainername), 1);

   do
    {
        /*
        if(Team->numberofplayer > MAXPLAYER)
        printf("die maximale Spieleranzahl ist erreicht"); warum klappt das nicht?
            return;
            */


        addPLayer(Team->Player + Team->numberofplayer); //Player Variable wird mit der Anzahl der Spieler (um auf das jeweilige Element zuzugreifen) als Parameter an addPlayer übergeben
        Team->numberofplayer++;

    }while(askYesOrNo("Moechten Sie einen weiteren Spieler anlegen?"));
    TeamCounter++;

  return;
}

void deleteTeam() {
  printf("deleteTeam");
  save();
  waitForEnter();
  return;
}

void addPLayer(sPlayer *Player) {
  printf("\naddPLayer\n\n");

  getText("Geben sie bitte den Spielernamen ein\n->", 50, &(Player->Playernames), 0);
  getDate("Geben sie das Geburtstagsdatum des Spielers an\n->", &(Player->dateofbirth));
  getNumber("Geben sie bitte die Trikotnr. ein\n->", &(Player->jerseynumber), 1 , 50);

  return;
}

void listOneTeamname(sTeam *Team)
{
    printf("Spieler der Mannschafft %s werden sortiert ...... ok\n", Team->teamname);
}

void deletePlayer() {
  printf("deletePlayer");
  waitForEnter();
  return;
}

void searchPlayer() {
  printf("searchPlayer");
  waitForEnter();
  return;
}

void sortTeams() {
  printf("sortTeams\n\n");
    int bselection;
    char const * const btitle = "Sortieren";
    unsigned int const bnumMenuPoints = 5;
    char const * bMenuPoints[bnumMenuPoints];


        bMenuPoints[0] = "Spieler nach Namen sortieren";
        bMenuPoints[1] = "Spieler nach Geburtstag (Alter) sortieren";
        bMenuPoints[2] = "Spieler nach Trikotnr. sortieren";
        bMenuPoints[3] = "Spieler nach ANzahl geschossener Tore sortieren";
        bMenuPoints[4] = "zurueck zum Hauptmenue";
        bselection = getMenu(btitle, bMenuPoints, bnumMenuPoints);
        switch(bselection){
        case 1:
            //sortnames();// Parameter des zu  sortierenden Teams übergeben
            //void QuickSort(Player, numberofplayer, int(sortnames)(sPlayer *, sPlayer *));
            QuickSort(sortnames);

            break;
        case 2:
            //sortbirthday();
            //void QuickSort(Player, numberofplayer, int(sortbirthday)(sPlayer *, sPlayer *));
            QuickSort(sortbirthday);

            break;
        case 3:
            //void QuickSort(Player, numberofplayer, int(sortjerseynumber)(sPlayer *, sPlayer *));
            QuickSort(sortjerseynumber);
            break;
        case 4:
            //void QuickSort(Player, numberofplayer, int(sortgoals)(sPlayer *, sPlayer *));
            //sortgoals();
            QuickSort(sortgoals);
            break;
        }
      //sortTeams();

  waitForEnter();
  return;
}

void listOnePlayer(sPlayer *playertoprint)
{
        printf("%s\n", playertoprint->Playernames);
        printf("  (Trikotnummer: %i) ", playertoprint->jerseynumber);
        printf("\nGeburtstag: %02u.%02u.%04i;  ", playertoprint->dateofbirth->Day, playertoprint->dateofbirth->Month, playertoprint->dateofbirth->Year);
        printf("\nTore: %i\n", playertoprint->goals);
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
                // *(pointer +1) = es wird auf nächstes element in *pArray zugegriffen
}


void listTeams() {
  printf("listTeams\n\n");
  int j;
  for(j = 0; j < TeamCounter; j++)
  {
        printf("\nTeam %i\n", j+1);
        printLine('-',15);
        listOneTeam(Teams + j);
  }

  waitForEnter();
  return;
}

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
    int j;
    for(j = 0; j < TeamCounter; j++)
    {
        freeOneTeam(Teams + j);
    }


}



