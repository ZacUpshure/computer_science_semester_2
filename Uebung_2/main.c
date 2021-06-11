#include <stdio.h>

#include <stdlib.h>

#include "tools.h"

#include "datastructure.h"

#include "menu.h"

#include "team.h"
// String Deklaration für die Menüberschrift
     char menutitel[] = "Mannschaftsverwaltung V0.2";
 // String Deklaration für die Menüpunkte
     char menu[9][24] = {
         "leer",

        "Neue Mannschaft anlegen"
      ,
        "Spieler hinzufuegen"
      ,
        "Spieler loeschen"
      ,
        "Mannschaft loeschen"
      ,
        "Suchen"
      ,
        "Sortieren"
      ,
        "Auflisten"
      ,
        "Programm beenden"

    };


int main() {



  do {
    getMenu();
    //switch case Verzweigung

    switch (choice) {

    case 1:
      createTeam();
    break;
      //return choice;

    case 2:
      deleteTeam();

       break;

    case 3:
      addPLayer();

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
      printf("Programm wird beendet\n");
      waitForEnter();

      break;

    default:
      printf("Bitte eine der vorgebenen Menuepunkte waehlen\n");
      waitForEnter();
      break;
    }

  } while (choice != 8);
  return 0;
}
