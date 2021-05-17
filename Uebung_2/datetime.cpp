#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"

/***********************************************
 *  Funktion: isLeapYear
 *  prüft ob ein Schaltjahr ist
/***********************************************/

int isLeapYear(int year) {
  if ( year % 4 == 0 && year % 100 != 0 || year % 400 == 0 )
    return 1;
  else
    return 0;
}

/***********************************************
 *  Funktion: isDateValid
 *  prüft ob ein eingebens Datum gültig ist
/***********************************************/

int isDateValid (int day, int month, int year)
{

  //int day,month,year;

    if(year>=1800 && year<=9999)
    {
        if(month>=1 && month<=12)
        {
            //check days
            if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
                return 1;
            else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11))
                return 1;
            else if((day>=1 && day<=28) && (month==2))
                return 1;
            else if(day==29 && month==2 && (isLeapYear(year) == 1))
                return 1;
            else
               return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

    return 0;
}
/**********************************************
 * Funktion: getDateFromString

/**********************************************/

int getDateFromString(char* Input, sDate* Date)

{
    char *pday = NULL, *pmonth = NULL, *pyear = NULL;
    int i = 0;
    pday = Input;

    while (*(Input + i) != '\0')
    {
        if (*(Input + i) == '.')
        {
            if (pmonth == NULL)
                pmonth = Input + i + 1;
            else
            {
                pyear = Input + i + 1;
                break;
            }
        }
        i++;
    }

    short day = atoi (pday);
    short month = atoi (pmonth); //atoi = zeichenketten in ganze Zahlen umwandeln
    int year = atoi (pyear);



    if (isDateValid(day,month,year))
    {
        Date -> Day = day;
        Date -> Month = month;
        Date -> Year = year;
        return 1;

    }
    else
    {
        return 0;
    }

}
