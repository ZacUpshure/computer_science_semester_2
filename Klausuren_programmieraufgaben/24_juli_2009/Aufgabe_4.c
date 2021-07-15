#include <stdio.h>
// Das folgende definiert "Funktionszeiger" als ein Zeiger auf
// eine Funktion, die ein char erhält und ein char zurückgibt:
typedef char (*Funktionszeiger)(char);
Funktionszeiger getFPtr(int);
void druckeZeichen(Funktionszeiger FPtr, char, int);
int main()
{
 Funktionszeiger FktPtr = NULL;
 druckeZeichen(getFPtr(1), 'A', 0);
 druckeZeichen(getFPtr(4), 'A', 17);
 druckeZeichen(getFPtr(2), 'b', 4);
 druckeZeichen(getFPtr(1), 'u', -1);
 druckeZeichen(getFPtr(0), 'f', -3);
 druckeZeichen(getFPtr(2), 'x', -3);
 druckeZeichen(getFPtr(3), 'x', 7);
 printf("\n");
 return 0;
}
char nextChar(char c) { return c + 1; }
char prevChar(char c) { return c - 1; }
char firstChar(char c) { return 'a'; }
Funktionszeiger getFPtr(int FktNr)
{
 switch (FktNr)
 {
 case 1: return nextChar;
 case 2: return prevChar;
 case 3: return firstChar;
 }
 return NULL;
}
void druckeZeichen(Funktionszeiger FPtr, char Zeichen, int Offset)
{
 if (FPtr)
 printf("%c", FPtr(Zeichen) + Offset);
}
