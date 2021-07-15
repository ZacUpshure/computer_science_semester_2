//Aufgabe 4 Klausur 05.juli 2013

//Funktionsdekleration
TAdresse *createAdresse;(char *, int, int, int);
int saveAdressen(char *);
int compareBirthday(TAdresse *, TAdresse *);

//Funktionsdefinition
TAdresse *createAdresse;(char *Name, int D, int M, int Y)
{
    TAdresse *New = NULL;
    New = malloc(sizeof(TAdresse));
    if(New)
    {
        New->Birthday = malloc(sizeof(TDare));
        New->Name = malloc(strlen(Name)+1);
        if(New->Birthday && New->Name)
        {
            strcpy(New->Name, Name);
            New->Birthday->Day = D;
            New->Birthday->Month = M;
            New->Birthday->Year = Y;
        }
    }
    return New;
}

int saveAdressen(char *Name)
{
    int i = 0;
    FILE *D = NULL;
    D = fopen(name, "w");
    if(!D)
    {
        printf("datei konnte nicht geoffnet werden!");
        return 0;
    }
    for(i = 0; i < AnzAdressen; i++)
    {
        fprintf(D, "%s", *(Adressen)->Name);
        fprintf(D, "(%02i. %02i. %04i.)", *(Adressen)->Day,
                                            *(Adressen)->Month,
                                            *(Adressen)->Year);
    }
    fclose(D);
    return 1;
}

int compareBirthday(TAdresse *A1, Tadresse *A2)
{
    int i = 0;
    if(A1->Birthday && A2->Birthday)
    {
        i = (A1->Birthday->Year - A2->Birthday->Year);
        if(i == 0)
        {
            i = (A1->Birthday->Month - A2->Birthday->Month);
        }
    }
    return i;
}





