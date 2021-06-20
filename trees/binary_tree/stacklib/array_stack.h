#include <stdio.h>
#include <stdlib.h>
#include "../binary_tree.h"

typedef struct _array_stack_node *AStack;
typedef int PositionTop;
struct _array_stack_node
{
    /* data */
    BinTree Data[100];
    PositionTop Top;
};



AStack MakeEmptyArrayStack();

int IsAStackFull(AStack ptrl);

int IsAStackEmpty(AStack ptrl);

void AStackPush(AStack ptrl, BinTree x);

BinTree AStackPop(AStack ptrl);

void PrintElement(AStack ptrl);