// Dynamischer Speicher
#include <stdio.h>
#include <stdlib.h>
// - Funktionen:
void *malloc(size_t);   // Zeiger auf reservierten Speicherbereich. 
void *calloc(size_t count, size_t size);    // speicherbereich wird auf 0 gesetzt.

// mit c++ compiler ist eine explizite Typumwandlung notwendig

// Beispiel 1 :
int main()
{
    int i;
    double *p = malloc(10 * sizeof(double));    // 10 Speicherplaetze reserviert,
                                                // zeiger p zugewiesen.

    if (p != NULL)      // kann mit "if (p)" abgekürzt werden.
    {
        for (i = 0; i < 10; i++)
            *(p + 1) = 1 * 3.1415296;
    }
    else
    {    
        printf("Nicht genuegend Speicher vorhanden!\n");
    }
    return 0;   
}

// Speicherbereich aendern mit realloc :
void *realloc(void *old, size_t newsize);

// "newsize = o" entspricht freigabe
// "*old = Null" entspricht (Malloc)

// Beispiel 2 :
int main()
{
    int i;
    double *p = malloc(10 * sizeof(double));

    if (p)
    {
        for (i = 0; i < 10; i++)
        {
            *(p + i) = i * 3.1415296;
        }
        p = realloc(p, 5 * sizeof(double));

        if (p)
        {
            for(i = 0; i < 5; i++)
                printf("%f\n", *(p + i));
        }
        else
        {
            printf("Nicht genuegend Speicher");
        }
    }
    return 0;
}

// Speicherbereich am ende wieder freigeben :
void free(void * mem);
//==> Beipiel
int main()
{
    double *p = calloc(10, sizeof(double));
    free(p);

    return 0;
}


