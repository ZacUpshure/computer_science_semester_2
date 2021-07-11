#ifndef TEAMS_H_INCLUDED
#define TEAMS_H_INCLUDED
#include "datastructure.h"
int createTeam ();

int deleteTeam();

int addPLayer(sPlayer *);

int deletePlayer();

int searchPlayer();

int sortTeams();

int listTeams();

void listOneTeam(sTeam);

void freeOnePlayer(sPlayer *);

void freeTeams();

void listOneTeamname(sTeam *);

int sortgoals(sPlayer *, sPlayer *);

int sortjerseynumber(sPlayer *, sPlayer *);

int sortbirthday(sPlayer *, sPlayer *);

int sortnames(sPlayer *, sPlayer *);

void listOneTeamname(sTeam *);

#endif // TEAMS_H_INCLUDED
