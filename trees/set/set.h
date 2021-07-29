#include <stdlib.h>
#include <stdio.h>

typedef struct set
{
    /* data */
    int Data;
    int Parent;
}SetType;

int Find(SetType S[], int X);
