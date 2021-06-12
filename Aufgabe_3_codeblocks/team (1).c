#include <stdio.h>

#include "tools.h"

#include "datastructure.h"

#include "datetime.h"

void addPLayer(sPlayer *);

// Globale Variablen (in struct hinzugefügt)

 int TeamCounter = 0;

 sTeam Teams[MAXTEAMS];

// Funktionen für das Menü

/*
Teams ist ein Array das eine maximal Anzahl von MAXTEAMS = 10 aufnehmen kann
durch Deklarieurng werden für jedes Element die verscheidenen Variablen dem Element hinzugefügt
*/

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
  waitForEnter();
  return;
}

void listOnePlayer(sPlayer playertoprint)
{

        printf("  (Trikotnummer: %i) ", playertoprint.jerseynumber);
        printf("\nGeburtstag: %02u.%02u.%04i;  ", playertoprint.dateofbirth->Day, playertoprint.dateofbirth->Month, playertoprint.dateofbirth->Year);
        printf("\nTore: %i\n", playertoprint.goals);
}
void listOneTeam(sTeam Team)
{

    char *Name         = "\nName : ";
    char *trainer      = "\nTrainer        :";
    char *anzahlplayer = "\nAnzahl Spieler :";
    char *pPlayer      = "\nSpieler        :\n";
    int i;

    printf("%s%s", Name, Team.teamname);
    if (Team.trainername == NULL)
    {
        printf("%s <dieser Posten ist vakant>", trainer);
        printf("%s%i", anzahlplayer, Team.numberofplayer);
        printf("%s", pPlayer);
    }

    else
    {
        printf("%s%s", trainer, Team.trainername);
        printf("%s%i", anzahlplayer, Team.numberofplayer);
        printf("%s", pPlayer);
    }

    //Spieler Ausgabe
    for(i = 0; i < Team.numberofplayer; i++)
    {
        printf("%02i.%s\n", i+1, Team.Player[i]);
        listOnePlayer(Team.Player[i]);
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
        listOneTeam(Teams[j]);
  }

  waitForEnter();
  return;
}
