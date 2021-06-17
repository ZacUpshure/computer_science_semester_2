#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "datastructure.h"

#include "tools.h"

#include "datetime.h"

void saveTeam(FILE * , sTeam);
void savePlayer(FILE * , sPlayer);
void loadTeam(FILE * );
void loadPlayer(FILE * , sPlayer * );
// um den Compiler zu beruhigen

sTeam Teams[MAXTEAMS];

void save() //wird von der main aufgerufen
{
  int i;
  FILE * Datei;
  Datei = fopen("C:\\Uni\\Informatik\\teams.xml", "w");

  if (Datei != 0) {
    fprintf(Datei, "<Daten>\n");
    //printf("\noeffnen hat geklappt");

    for (i = 0; i < TeamCounter; i++)
      saveTeam(Datei, Teams[i]);
    fprintf(Datei, "</Daten>\n");
  }
  fclose(Datei);

}

void saveTeam(FILE * Datei, sTeam Teamtosave) // Speichern der Team Daten
{
  int i;

  fprintf(Datei, "    <Team>\n");

  fprintf(Datei, "       <Name>%s</Name>\n", Teamtosave.teamname);

  fprintf(Datei, "       <Trainer>%s</Trainer>\n", Teamtosave.trainername);

  for (i = 0; i < Teamtosave.numberofplayer; i++)
    savePlayer(Datei, Teamtosave.Player[i]); // in Schleife save Player aufrufen um Spieler zu speichern

  fprintf(Datei, "   </Team>\n");

}

void savePlayer(FILE * Datei, sPlayer Playertosave) // speichern der Spielerdaten
{
  //for(i = 0; i > number; i++)
  //{
  fprintf(Datei, "         <Player>\n");

  fprintf(Datei, "             <Name>%s</Name>\n", Playertosave.Playernames);

  fprintf(Datei, "             <Birthday>%02u.%02u.%04i</Birthday>\n", Playertosave.dateofbirth -> Day, Playertosave.dateofbirth -> Month, Playertosave.dateofbirth -> Year);

  fprintf(Datei, "             <TricotNr>%i</TricotNr>\n", Playertosave.jerseynumber);

  fprintf(Datei, "             <Goals>%i</Goals>\n", Playertosave.goals);

  fprintf(Datei, "        </Player>\n");
  //}

  return;

}
int load() {
  char Zeile[101];

  /**  Anfangszeichen entfernen   ***/
  char * Zeilenanfang;
  Zeilenanfang = Zeile;
  while (( * Zeilenanfang == ' ') || ( * Zeilenanfang == 9))
    Zeilenanfang++;
  /** Datei oeffnen ***/
  FILE * Quelle;
  Quelle = fopen("C:\\Uni\\Informatik\\teams.xml", "r");
  /** Dateioeffnung ueberpruefen **/
  if (Quelle != NULL) {
    do /*** lesen der Zeilen bis Tag-Ende erreicht wurde ***/ {
       /**** Text aus Quelle in Zeichenanfang schreiben ****/
      fscanf(Quelle, "%100[^\n]\n", Zeile); // [^\n] = alle Zeichen außer \n werden berücksichtigt
      //printf("%s\n", Zeile);
      /**** Tag ermitteln und Auswerten ***************/
      if (strncmp(Zeilenanfang, "<Team>", 6) == 0) // deswegen müssen Leerzeichen beseitigt werden damit das mit den 6 Zeichen hinhaut
      {
        loadTeam(Quelle);
        //printf("\n%s\n", Zeilenanfang);
      }

      //if(feof(Quelle != NULL)) // Abfrage ob man am Datei ende ist (Notausgang damit man keeine Endlosschleife hat)
      //return 0;

    } while (strncmp(Zeile, "</Daten>", 8) != 0);

  }

  fclose(Quelle);
  //free(all);

  return 1;
}



void loadTeam(FILE * Quelle) {
  char Zeile[101];
  int len;
  sTeam * Team = Teams + TeamCounter;

  /*** Anfangszeichen entfernen *****/
  char * Zeilenanfang;
  Zeilenanfang = Zeile;
  while (( * Zeilenanfang == ' ') || ( * Zeilenanfang == 9)) {
    Zeilenanfang++;
  }
    Team -> numberofplayer = 0;
  do {
    fscanf(Quelle, "%100[^\n]\n", Zeile);
    if (strncmp(Zeilenanfang, "<Player>", 6) == 0) // deswegen müssen Leerzeichen beseitigt werden damit das mit den 6 Zeichen hinhaut
    {
      loadPlayer(Quelle, Team -> Player + Team -> numberofplayer);
      Team -> numberofplayer++;
    }

    /** lesen der Zeilen bis Tag-Ende erreicht wurde **/

    /** Text aus Quelle in Zeichenanfang schreiben **/


    if (strncmp(Zeilenanfang, "<Name>", 6) == 0) {

      len = strlen(Zeilenanfang + 6) - 7; // 7 abziehen wegen <\Name> am Zeilenende

      if (strncmp(Zeilenanfang + 6 + len, "</Name>", 7) == 0) // vergleich von Anfang der Zeile (|<Name>) + 6 Zeichen ([<Name>]) + Länge der daten zwischen den tag (len)
      { // mit dem Ende Tag (</Name>) und davon 7 Zeichen (weil </Name> 7 Zeichen lang ist)
        (Team -> teamname) = calloc(len + 1, sizeof(char)); // Team Zeiger der auf das entsprechende Element zeigt // Speichereservierung nach länge des speichers +1 weil \0
        //printf("test");
        // falls Zahl Speichereservierung durch atoi ersetzen
        // falls Datum getDateFromString Datum drauß machen und entsprechend der datumstruktur Speicherplatz reservieren und reinschreiben
        if ( & (Team -> teamname)) {
          strncpy((Team -> teamname), Zeilenanfang + 6, len);
          //printf("%s\n", Team->teamname);

        }
      }

    }

    if (strncmp(Zeilenanfang, "<Trainer>", 9) == 0) {

      len = strlen(Zeilenanfang + 9) - 10; // 7 abziehen wegen <\Name> am Zeilenende
      // len ist die Länge der Daten zwischen den Tags
      //printf("%s", Zeilenanfang);
      //printf("%i\n", len);

      if (strncmp(Zeilenanfang + 9 + len, "</Trainer>", 10) == 0) // vergleich von Anfang der Zeile (|<Name>) + 6 Zeichen ([<Name>]) + Länge der daten zwischen den tag (len)
      { // mit dem Ende Tag (</Name>) und davon 7 Zeichen (weil </Name> 7 Zeichen lang ist)
        (Team -> trainername) = calloc(len + 1, sizeof(char)); // Team Zeiger der auf das entsprechende Element zeigt // Speichereservierung nach länge des speichers +1 weil \0
        //printf("test");
        // falls Zahl Speichereservierung durch atoi ersetzen
        // falls Datum getDateFromString Datum drauß machen und entsprechend der datumstruktur Speicherplatz reservieren und reinschreiben
        if ( & (Team -> trainername)) {
          strncpy((Team -> trainername), Zeilenanfang + 9, len);
          //printf(" %s", Team->trainername);

        }
      }

    }

    //if(feof(Teamtoload != NULL))                              // Abfrage ob man am Datei ende ist (Notausgang damit man keeine Endlosschleife hat)
    //break;

  } while (strncmp(Zeile, "</Team>", 7) != 0);
  //free(Team -> teamname);
  //free(Team -> trainername);
  TeamCounter++;
}

void loadPlayer(FILE * Quelle, sPlayer * Playertoload) {
  char Zeile[101];
  int len;

  /*** Anfangszeichen entfernen *****/

  char * Zeilenanfang;
  Zeilenanfang = Zeile;

  while (( * Zeilenanfang == ' ') || ( * Zeilenanfang == 9)) {
    Zeilenanfang++;
  }
  do {
    fscanf(Quelle, "%100[^\n]\n", Zeile);
    if (strncmp(Zeilenanfang, "<Name>", 6) == 0) {

      len = strlen(Zeilenanfang + 6) - 7;
      //printf("%s", Zeilenanfang);
      //printf("%i\n", len);

      if (strncmp(Zeilenanfang + 6 + len, "</Name>", 7) == 0) // vergleich von Anfang der Zeile (|<Name>) + 6 Zeichen ([<Name>]) + Länge der daten zwischen den tag (len)
      { // mit dem Ende Tag (</Name>) und davon 7 Zeichen (weil </Name> 7 Zeichen lang ist)
        (Playertoload -> Playernames) = calloc(len + 1, sizeof(char)); // Team Zeiger der auf das entsprechende Element zeigt // Speichereservierung nach länge des speichers +1 weil \0
        //printf("test");
        // falls Zahl Speichereservierung durch atoi ersetzen
        // falls Datum getDateFromString Datum drauß machen und entsprechend der datumstruktur Speicherplatz reservieren und reinschreiben
        if ( & (Playertoload -> Playernames)) {
          strncpy((Playertoload -> Playernames), Zeilenanfang + 6, len);
          //printf(" %s", Playertoload->Playernames);

        }
      }
    }

    //sDate * pDate;

    if (strncmp(Zeilenanfang, "<Birthday>", 10) == 0) {

      len = strlen(Zeilenanfang + 10) - 11;
      //printf("%s", Zeilenanfang);
      //printf("%i\n", len);

      if (strncmp(Zeilenanfang + 10 + len, "</Birthday>", 11) == 0) {
        Playertoload -> dateofbirthchar = calloc(len + 1, sizeof(char));
        strncpy(Playertoload -> dateofbirthchar, Zeilenanfang + 10, len);
        //printf("%s", Playertoload->dateofbirthchar);

        getDateLoadPrompt(Playertoload -> dateofbirthchar, & (Playertoload -> dateofbirth));

      }

    }

    int Inputasnumber;

    if (strncmp(Zeilenanfang, "<TricotNr>", 10) == 0) {
      len = strlen(Zeilenanfang + 10) - 11;

      if (strncmp(Zeilenanfang + 10 + len, "</TricotNr>", 11) == 0) {
        (Playertoload -> jerseychar) = calloc(len + 1, sizeof(char));

        strncpy(Playertoload -> jerseychar, Zeilenanfang + 10, len);
        Inputasnumber = atoi(Playertoload -> jerseychar);
        //printf("%s\n", Playertoload->jerseychar);
        //printf("%i\n", Inputasnumber);
        (Playertoload -> jerseynumber) = Inputasnumber;
        //printf("\n%i\n", Playertoload -> jerseynumber);
        //free(Playertoload->jerseychar);

      }

    }


    if (strncmp(Zeilenanfang, "<Goals>", 7) == 0) {
      len = strlen(Zeilenanfang + 7) - 8;

      if (strncmp(Zeilenanfang + 7 + len, "</Goals>", 8) == 0) {
        (Playertoload -> goalschar) = calloc(len + 1, sizeof(char));

        strncpy(Playertoload -> goalschar, Zeilenanfang + 7, len);
        Inputasnumber = atoi(Playertoload -> goalschar);
        //printf("%i\n", Inputasnumber);
        (Playertoload -> goals) = Inputasnumber;

      }

    }



  } while (strncmp(Zeile, "</Player>", 7) != 0);
  free(Playertoload -> jerseychar);
  //free(Playertoload -> Playernames);
  free((Playertoload -> dateofbirthchar));
  //free(Playertoload -> goalschar);

}

