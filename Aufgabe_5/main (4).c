#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "tools.h"

#include "datastructure.h"

#include "menu.h"

#include "team.h"

#include "database.h"

#include "sort.h"



int main() {

    int selection;
    char const * const title = "Mannschaftsverwaltung V 0.5";

    unsigned int const numMenuPoints = 8;
    char const * aMenuPoints[numMenuPoints];
    aMenuPoints[0] = "Neue Mannschaft anlegen";
    aMenuPoints[1] = "Teams laden";
    aMenuPoints[2] = "Spieler loeschen";
    aMenuPoints[3] = "Mannschaft loeschen";
    aMenuPoints[4] = "Suchen";
    aMenuPoints[5] = "Sortieren";
    aMenuPoints[6] = "Auflisten";
    aMenuPoints[7] = "Programm beenden";


  do {
    selection = getMenu(title, aMenuPoints, numMenuPoints);
    //switch case Verzweigung

    switch (selection) {

    case 1:
      createTeam();
    break;
      //return choice;

    case 2:
     // addPlayer();
     //load();
     if(load()!=0)
     {
     printf("Teams werden geladen\n");
     printf("zum Auflisten bitte Menupunkt 7 nutzen\n");
     }
     else
     {
         printf("Teams konnten nicht geladen werden");
     }
     waitForEnter();
       break;

    case 3:
      deleteTeam();

       break;

    case 4:
      deletePlayer();

       break;

    case 5:
      searchPlayer();

       break;

    case 6:
        sortTeams();

        break;

    case 7:
      listTeams();

       break;

    case 8:
        if(askYesOrNo("moechten sie das aktuelle Programm speichern?"))
        save();
        freeTeams();
        printf("Programm wird beendet\n");
        waitForEnter();

      break;

    default:
      printf("Bitte eine der vorgebenen Menuepunkte waehlen\n");
      waitForEnter();
      break;
    }

  } while (selection != 8);
  return 0;
}
