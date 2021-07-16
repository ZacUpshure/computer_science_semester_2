//Aufgabe 4 Klausur 05.juli 2013

//Funktionsdekleration
void Trim(char *);
int Leerzeichen(char *);

//Funktionsdefinition
void Trim(char *Z)
{
    int i;
    i = 50;

    while(i > 0)
    {
        if(*(2 + i) == " ")
        {
            *(2 + i) = "0";
            i--;
        }
        else
        {
            if(*(Z + i) > ' ')
            {
                return;
            }
        }
    }
}

int Leerzeichen(char **K)
{
    int leer = 0;
    int i = 0;
    int e = 0;

    while(i < 10)
    {
        while(e < 50)
        {
            if(K[i][e] == " ")
            {
                leer++;
                e++;
            }
            i++;
        }
        return leer;
    }
}





