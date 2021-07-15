// Funktionsdekleration

int compareDate(TDate *date1, TDate *date2);
void writeFile(char *Filename, TDate *A, int Anz, char **Monthnames);



//Funktionsdefinition
int compareDate(TDate *date1, TDate *date2)
{
    int i;
    i = date->Year - date2->Year;

    if(i)
    {
        return i;
    }
    else
    {
        i = date1->Month - date2->Month;
        if(i)
        {
            return i;
        }
        else
        {
            return date1->Day - date2->Day;
        }
    }
}

void writeFile(char *Filename, TDate *A, int Anz, char **Monthnames);
{
    FILE * D = fopen(Filename, "w");
    if(!D)
    {
        fprintf(stderr, "failed to open file %s\n", Filename);
        return;
    }
    else
    {
        int i;
        fprintf(D, "%[^\n]", Anz);
        for(i = 0; i < Anz; i++)
        {
            fprintf(D, "%2i. %s %4i\n", (A + i)->Day, Monthnames[((A + i)->Month)-1], (A + i)->Year);
        }
        fclose(D);
    }
}
