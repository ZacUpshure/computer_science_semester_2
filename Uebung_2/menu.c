#include <stdio.h>

#include "team.h"

#include "tools.h"

#include "datastructure.h"
int choice;

int getMenu() {


  do {

    clearScreen();

    printf("%s\n", menutitel);

    printLine('-', 50);
    printf("\n");


    for (int i = 1;i < 9; i++)
	{
		printf("%d. %s\n", i, menu[i]);
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
