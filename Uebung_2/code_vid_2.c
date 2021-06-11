//  Beispiele für Dynamische Speicherverwaltung
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clearBuffer.h"

int getText (char *, unsigned, char **, int);       // gibt einen wahrheitswert zurück, also wird sie als intiger deklariert
                                                    // 4 Parameter 1. Eingabe aufforderung, 2. maximale Eingabelänge,
                                                    // 3. Zeiger auf Zeiger auf char, 4. Ist eine leere Eingabe erlaubt oder nicht ?    
int main()
{
    char *Rufnamen;
    char *Vornamen;
    char *Nachnamen;

    getText("Geben sie bitte Ihren Rufnahmen ein : ", 15, &Rufnamen, 0);
    getText("Geben sie bitte Ihren weiteren Vornamen ein : ", 50, &Vornamen, 1);
    getText("Geben sie bitte Ihren Nachnamen ein : ", 35, &Nachnamen, 0);

    printf("Aha, sie heißen also %s ", Rufnamen);

    if (Vornamen != NULL)
    {
        printf("%s", Vornamen);
        printf("%s.\n", Nachnamen);
    }

    free(Rufnamen);
    free(Vornamen);
    free(Nachnamen);

    return 0;
} 

int getText(char *Promt, unsigned MaxLen, char **Pointer, int AllowEmpty)
{
    char *Input;                // oder direkt "char *Input[MaxLen + 1]"
    char Format[20];
    unsigned Len = 0;
    int ok = 0;

    if ((Pointer == NULL) && (MaxLen == 0))
    {
        return 0;
    }

    *Pointer = NULL;

    Input = malloc(MaxLen + 1);
    if (Input)
    {
        sprintf(Format, "%%%i[^\n]", MaxLen);
        do
        {
            printf(Promt);
            *Input = '\0';
            scanf(/*Format*/ "%[^\n]", Input);
            clearBuffer();
            Len = strlen(Input);
            if (Len > 0)
            {
                *Pointer = malloc(Len + 1);
                if (*Pointer)
                {
                    strncpy(*Pointer, Input, Len + 1);
                    {
                        ok = 1;
                    }
                }
                else if (AllowEmpty)
                {
                    ok = 1;
                }
            }
        } while (ok != 1 /* condition */);
        
        free(Input);
        return 1;
    }
    else
    {
        return 0;
    } 
}


//leist eine Zeichenkette ein und berügsichtigt dabei alles Zeichen außer,
//die Zeichen die in der Eckigen klammer liegen
