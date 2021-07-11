#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

int getDateFromString(char* , sDate* );

void getDate(char *Datumsprompt, sDate **ReturnDate);

void printDate(sDate *pDate, char *Prompt);

void getDateLoadPrompt(char *loadprompt, sDate **ReturnDate);

#endif // DATETIME_H_INCLUDED


