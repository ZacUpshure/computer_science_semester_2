#ifndef DATABASE_H
#define DATABASE_H

void save();

void saveTeam(FILE *Datei, sTeam Teamtosave);

void savePlayer(FILE *Datei, sPlayer Playertosave);

int load();

void loadTeam(FILE *);

void loadPlayer(FILE *, sPlayer *);

#endif // DATABASE_H
