//Aufgabe 4 Klausur 02.Februar 2007

//Funktionsdekleration
int fcopyChars(char *, char *);

//Funktionsdefinition
int fcopyChars(char *q, char *z)
{
    int b, Erg = 0;
    FILE *quelle = NULL, *Ziel = NULL;
    quelle = fopen(q, "r");
    if (!quelle)
    {
        return -1;
    }
    Ziel = fopen(z, "w");
    if (!Ziel)
    {
        fclose(quelle);
        return -2;
    }
    fseek(quelle, 0, SEEK_SET);
    fseek(quelle, 0, SEEK_SET);

    while(feof(quelle))
    {
        b = fscanf(quelle);
        if((b >= 'a' && b < 'z') && (b >= 'A' && b < 'Z'))
        {
            fputs(b, Ziel);
            Erg++;
        }
    }
}




