#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

int getText (char *Prompt, unsigned int MaxLen, char **Pointer, int AllowEmpty);

int getNumber (char *Prompt, int *Pointer, int von, int bis);

void clearScreen();

void clearBuffer();

void waitForEnter();

int askYesOrNo(char *Question);

void printLine(char x, int d);

int inputDate();


#endif // TOOLS_H_INCLUDED
