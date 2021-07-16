


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