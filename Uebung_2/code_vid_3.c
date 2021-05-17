// Geschachtelte Strukturen

typedef struct Inner /*Name*/  
{
    /* data */
    int value;
    char sign;
}sInner/*Feld*/;

typedef struct Outer
{
    int value;
    sInner In;
}sOuter;

int main()
{
    sOuter A;

    A.value    = 1;
    A.In.value = 2;
    A.In.sign  = '-';
}

// Konstante => Ausdruck mit namen und wert aber ohne speicher 
// z.b :
    #define MAX 100
// oder 
    enum { MAX = 100 };
// üblicherweise großgeschrieben als erkennungsmerkmal

// Variablen deklarieren mit "extern"
    extern int count;
    extern char Text[];
// dekleration ohne definition (kein speicher wird belegt)
// daher keine initialisierung möglich.
// bei arrays muss keine größe angegeben werden.
// müssen aber an einem anderen ort definiert werden.
    int count = 0;
    char Text[20];
    
