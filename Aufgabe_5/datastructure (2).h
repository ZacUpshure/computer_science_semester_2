#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

#define MAXPLAYER 23
#define MAXTEAMS 10
//#define ENDTAG_END  "</Daten>"
//#define ENDTAG_TEAM   " </Team>"
//#define ENDTAG_TEAM_NAME "</Name>"


// Struktur für datetime

typedef struct {
  short Day;
  short Month;
  int Year;
}
sDate;

// Erweiterung für Übung 2

typedef struct {
  char * Playernames;
  char * jerseychar;
  char * dateofbirthchar;
  sDate * dateofbirth;
  int jerseynumber;
  int goals;
  char *goalschar;
}
sPlayer;

// Erweiterung für Übung 2

typedef struct {
  char * teamname;
  char * trainername;
  int numberofplayer;
  sPlayer Player[MAXPLAYER];
}
sTeam;

extern char menutitel[];
extern char menu[][24];
extern int choice;
extern int TeamCounter;
extern sTeam Teams[MAXTEAMS];
#endif // DATASTRUCTURE_H_INCLUDED
