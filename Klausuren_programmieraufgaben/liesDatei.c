/***********************************************************
Die Funktion liesDatei soll die Textdatei mit dem angegebenen Dateinamen einlesen und
in dem angegebenen Array von Zeichenketten (übergeben wird die Adresse
vom Zeiger auf das Array von Zeichenketten) ablegen. Der Speicherbereich für das
Array sowie für die einzelnen Zeichenketten muss zuvor noch reserviert werden. Es
kann eine korrekt-formatierte Textdatei vorausgesetzt werden!
***********************************************************/

void liesDatei(char *DateiName, String **pArrayZeiger)
{
    int i;
    char Dummy;
    FILE *D = fopen(DateiName, "r"); // öffnen einer Datei -> Dateihandle

    if(D) //Abfrage ob Datei erfolgreich geöffnet wurde WICHTIG!!!
    {
        *pArrayZeiger = calloc(MAX, sizeof(String)); //Speicherplatz Reservierung für den StringZeiger auf char oben (also Speicherplatz Reservierung für char *)
        if(*pArrayZeiger)
            for(i = 0; i < MAX; i++)// Es sind MAX Elemente im Array auf das der Arrayzeiger zeigt
            {
                *(*pArrayZeiger + i) = calloc(MAXLEN, sizeof(char));// MAXLEN ersetzbar durch strlen(Z +1) (+1 wegen /0)
                if(*(*pArrayZeiger + i))
                {
                    fscanf(D, "%[^\n]%c", *(*pArrayZeiger + i), &Dummy);// (woher kommt das zu lesene,-- wie wird es gescannt,-- wo soll es rein,-- Dummy für Zeilenumbruch)
                }
            }
        fclose(D);// schließen des Dateihandle WICHTIG!!!
    }


}

/***********************************************************
*    Labor Aufgaben
***********************************************************/
int load() {

  char Zeile[101];
  char * Zeilenanfang;
  char Dummy;
  /** Datei oeffnen ***/
  FILE *Quelle = NULL;
  Quelle = fopen("C://Users//mschi//Desktop//Informatik//teams.xml", "r");
  /** Dateioeffnung ueberpruefen **/
  if (Quelle != NULL) 
   {
		do 
		{
			while(fscanf(Quelle, "%100[^\n]%c", Zeile, &Dummy)!= EOF) // "Zeile" wird Zeilenweise eingelesen
			{
				Zeilenanfang = Zeile;

				while (( * Zeilenanfang == ' ') || ( * Zeilenanfang == 9)) // Beseitigung der Leerzeichen am anfang
				{
					Zeilenanfang++; // [^\n] = alle Zeichen außer "\n" werden berücksichtigt
				}
					/**** Tag ermitteln und Auswerten ***************/
				if (strncmp(Zeilenanfang, "<Team>", 6) == 0) // deswegen müssen Leerzeichen beseitigt werden damit das mit den 6 Zeichen hinhaut
				{
					sTeam *Team = calloc(1, sizeof(sTeam));
					loadTeam(Quelle, Team);
					insertListElement(Team, sortTeam);
				}
			}

		}while (strncmp(Zeilenanfang, "</Daten>", 8) != 0);

   }
  else
  {
      return 0;
  }

  fclose(Quelle);

  return 1;
}