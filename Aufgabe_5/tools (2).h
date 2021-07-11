#ifndef TOOLS_H
#define TOOLS_H

void clearScreen();

void clearBuffer();

void waitForEnter();

int askYesOrNo(char *Question);

void printLine(char x, int d);

int getText (char *Prompt, unsigned int MaxLen, char **Pointer, int AllowEmpty);

int getNumber (char *Prompt, int *Pointer, int von, int bis);

#endif

