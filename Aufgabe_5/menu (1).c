#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "team.h"

#include "tools.h"

#include "datastructure.h"
/*
int choice;

int getMenu() {


  do {

    clearScreen();

    printf("%s", menutitel);

    printLine('-', 50);
    //printf("\n");


    for (int i = 1;i < 9; i++)
    {
        printf("\n%d. %s\n", i, menu[i]);
    }


    printf("\n");
    printf("Bitte geben sie den gewuenschten Menupunkt ein \n");
    printf("\n");
    printf("Ihre Wahl:");



{
    scanf("%i", &choice);
    clearBuffer();
}



  } while (choice > 8 && choice < 1);
  return choice;
}
*/

int getMenu(char const *title, char const **aMenuPoints, unsigned short numMenuPoints)
{
    unsigned short i; // Z�hlvariable
    unsigned short input; // Benutzereingabe
    int scanfRet = 0;


    do
    {
        clearScreen();
        printf("%s\n", title);
        printLine('=', strlen(title));
        printf("\n");

        for (i = 0; i < numMenuPoints; ++i)
            printf("%2u. %s\n", i + 1, aMenuPoints[i]);

        printf("\nIhre Wahl: ");
        scanfRet = scanf("%hu", &input);
        clearBuffer();
    } while (scanfRet != 1 || input < 1 || input > numMenuPoints);

    return input;
}
