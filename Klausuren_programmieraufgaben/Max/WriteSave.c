


void schreibeDatei(String Name, String *AZ)//String Name ist char *; String *AZ ist char **;
{
     FILE *D;
     int i;
     D = fopen(Name, "w");

     if (D != NULL)
         for (i = 0; i < MAX; i++)
            fprintf(D, "%s\n", *(AZ + i));
     free(AZ);
     fclose(D);
}

void schreibeDatei(char *Name, char **Array, int Anz)
{
    FILE *D;
    int i;
    D = fopen(Name, "w");
    if (D != NULL)
    {
        for (i = 0; i < Anz; i++)
        if (Array + i)
			fprintf(D, "%s\n", *(Array + i));
        fclose(D);
    }
}

void writeFile(char* Filename, TDate *A, int Anz, char **Monthname)
{
    FILE *D = fopen(Filename, "w");
    if(!D)
    {
        fprintf(stderr, "failed to open file %s\n", Filename);
        return;
    }
    else
    {
        int i;
        fprintf(D, "%i\n", Anz);
        for(i = 0; i < Anz; i++)
        {
            fprintf(D, "%2i %s %4i\n", (A+i)->Day, Monthname[((A+i)->Month)-1], (A + i)->Year);
        }
        fclose(D);
    }
}


int saveAdressen(char *Name)
{
    int i = 0;
    FILE *D = NULL;
    D = fopen(Name, "w");

    if(!D)
    {
        printf("Die Datei kann nicht geöffnet werden!\n");
        return 0;
    }
    fprintf(D,"Adressen:\n");
    for(i=0; i<AnzAdressen; i++)
    {
        fprintf(D,"%s", (*(Adressen + i))->Name);
        fprintf(D, "(* %02i 0%02i.%04i)\n", ((*(Adressen + i))->Birthday->Day, (*(Adressen + i))->Birthday->Month),(*(Adressen + i))->Birthday->Year);
        //fprintf(D, "(* %02i.%02i.%04i\n", (*(Adressen + i))->Birthday, (*(Adressen + i))->Month, (*(Adressen + i))->Year);
    }
    fclose(D);
    return 1;
}


