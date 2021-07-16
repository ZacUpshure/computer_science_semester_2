#include <stdio.h>

// Platz für Ihre Funktionsdeklarationen (6 Punkte):

fcopyChars(char *, char *);


int main()
{
    int Erg;

    Erg = fcopyChars("E://Google//Studium//Informatik//Informatik II//Klausur//Aufgaben//Quelle.txt", "E://Google//Studium//Informatik//Informatik II//Klausur//Aufgaben//Ziel.txt");
    //Erg = fcopyChars("Datei1.txt", "Datei2.txt");

    switch(Erg)
    {
        case -1:
            printf("Die Quell-Datei konnte nicht geoeffnet werden!\n");
            break;
        case -2:
            printf("Die Ziel-Datei konnte nicht geoeffnet werden!\n");
            break;
        case 0:
            printf("Die Quell-Datei is leer / beinhaltet keine Buchstaben!\n");
            break;
        default:
            printf("%i Buchstaben von Quell- nach Zieldatei!\n", Erg);
            break;
    }

    return 0;
}



// Platz für Ihre Funktionsdefinitionen (24 Punkte):

fcopyChars(char *q, char *z) {
    int b, Erg = 0;
    int i = 0;

    FILE *Quelle = NULL, *Ziel = NULL;
    Quelle = fopen(q, "r");
    Ziel = fopen(z, "w");

    if (!Quelle) {
        return -1;
    }
    if (!Ziel) {
        return -2;
    }

    b = fgetc(Quelle);
    while ((b != EOF) && (b != '\0'))
    {
        //int i = 0;

        if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
        {
            fputc(b, Ziel);
            Erg++;
        }
        b = fgetc(Quelle);
    }
    fclose(Quelle);
    fclose(Ziel);
    return Erg;
}



void Trim(char T[])
{

    int i = 0;

    while (T[i])
    {
        i++;
    }
    i--;

    while ((T[i] == ' ') && (i >= 0))
    {
        T[i] = '\0';
        i--;

    }
}



int countSpaces(char Array[10][50])
{
    int i;
    int j;
    int Anzahl = 0;

    for (i = 0; i < 10; i++)
    {
        for(j=0; j < 50; j++)
        {
            if(Array[i][j] == ' ')
            {
                Anzahl++;
            }
        }
    }
    return Anzahl;
}



