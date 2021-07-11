#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**********************************************************/
/**********************************************************/
void clearScreen()
{
//   system("clear"); // Linux
   system("CLS");   // Windows
}

/**********************************************************/
/**********************************************************/
void clearBuffer()
{
   char Dummy;

   do
   {
      scanf("%c", &Dummy);
   } while (Dummy != '\n');
}

/**********************************************************/
/**********************************************************/
void waitForEnter()
{
   printf("\nBitte Eingabetaste druecken ...");
   clearBuffer();
}

/**********************************************************/
/**********************************************************/
int askYesOrNo(char *Question)
{
   char Input;

   do
   {
      printf("%s", Question);
      scanf("%c", &Input);
      if (Input != '\n')
         clearBuffer();
   } while ((Input != 'j') && (Input != 'J') && (Input != 'n') && (Input != 'N'));
   return ((Input == 'j') || (Input == 'J'));
}
/**********************************************************/
/**********************************************************/
void printLine(char x, int d)
{

int i;

    for(i=1; i<d; i++){
    printf("%c",x);
    }
   printf("%c",x);

return;
}
/***********************************************************************/

//bsp wie man auf die zeiger zugreift
//char *Rufname

//getText("Geben sie bitte ihren Rufnamen ein: ", 15, &Rufnahme, 0);


int getText (char *Prompt, unsigned int MaxLen, char **Pointer, int AllowEmpty)
{
    char *Input;  // char Input[MaxLen +1] auch möglich
    char Format[20]; // zeile 84
    unsigned int Len = 0; //Länge wird auf 0 gesetzt
    int ok = 0; // zur Überprüfung ob auch leere char möglich sind

    if ((Pointer == NULL) || (MaxLen == 0)) //Speicherzugriffsfehler vermeiden || MaxLen ob man überhaupt was eingeben kann
        return 0;

    *Pointer = NULL; //angegebener Pointer im Hauptprogramm auf NULL gesetzt

    Input = malloc(MaxLen + 1); //Zeichenkette dynamisch erzeugt aka Input variable ist maximal so lang wie angegeben
    if (Input != 0) // Überprüfung ob Speicherplatz reservierung geklappt hat
    {
        sprintf(Format, "%%%i[^\n]",MaxLen); // %% werden als formatierung gesehen also wird nur eins ausgeben -> %%%
        //scanf("%[^\n]", Input); kein s, da ein Leerzeichen sofort scanf abbricht [^\n] = alle Zeichen außer \n werden berücksichtigt

        do
        {
            printf("%s", Prompt); // printf (Prompt) geht auch
            *Input = '\0'; // sollte der benutzer nur die EIngabetaste drücken wird die Input variable nicht verändert \0 steht an erster stelle
            scanf(Format, Input); //format = maximale scanf länge
            clearBuffer();
            Len = strlen(Input); //len = Länge des Strings als int
            if(Len > 0) // if (*Input != 0) = Abfrage nach erstem Zeichen ob es != 0 ist
            {           // wird durch die ASbfrage nach der Länge ersetzt da es wenn nur Leerezeichen eingeben wurde Len = 0
                *Pointer = malloc(Len + 1); // Speicherplatz Reservirung da Len jetzt die Länge der Eingabe der Zeichen durch strlen hat
                                  // muss in *Pointer abgelegt werden da *pointer Variable ist für die der Speicherplatz reserviert werden soll
                if (*Pointer != 0) // Abfrage ob Reservieren geklappt hat
                {
                    strncpy(*Pointer, Input, Len + 1); // strncopy gibt an wie viele Zeichen kopiert werden sollen
                  //strncopy(Ziel in das kopiert wird, Zeichenkette die kopiert wird, wie viele zeichen solln maximal kopiert werden
                    ok = 1;
                }
            }

        else if  (AllowEmpty)
            ok = 1;

        }while (ok != 1);
        //printf("Eingegeben wurde %s\n",*Pointer);
        free(Input); // nachdem input reservierung nicht mehr gebraucht wird speicherplatz wieder freigeben
    }
    else
        return 0;
}

int getNumber (char *Prompt, int *Pointer, int von, int bis)
{
  char Input[5];
  int MaxLen = 5;
  unsigned int Len = 0;
  int userInputasNumber;
  char Format[20];

    if ((Pointer == NULL)) // nötig?
        return 0;

    //*Pointer = NULL; // nötig?

    sprintf(Format, "%%%i[^\n]", MaxLen);

    do {
    printf("%s", Prompt);
    scanf(Format, Input);
    clearBuffer();
    Len = strlen(Input);
    if (Len > 0)
        userInputasNumber = atoi(Input);

} while(userInputasNumber < von || userInputasNumber > bis);

//c = (char)Input;
//strncpy(*Pointer, Input, 99);

*Pointer = userInputasNumber;
//printf("%i wurde eingeben\n\n", *Pointer);
return 1;
}

