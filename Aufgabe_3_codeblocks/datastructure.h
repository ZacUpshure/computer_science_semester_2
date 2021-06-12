#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

#define MAXPLAYER 23
#define MAXTEAMS 10

// Struktur f�r datetime

typedef struct {
  short Day;
  short Month;
  int Year;
}
sDate;

// Erweiterung f�r �bung 2

typedef struct {
  char * Playernames;
  sDate * dateofbirth;
  int jerseynumber;
  int goals;
}
sPlayer;

// Erweiterung f�r �bung 2

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
extern int PlayerCounter;
extern sTeam Teams[MAXTEAMS];
extern int TeamCounter;
#endif // DATASTRUCTURE_H_INCLUDED
