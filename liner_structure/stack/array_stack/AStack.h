#include <stdio.h>
#include <stdlib.h>
#include "../../common/linerLib.h"

typedef struct _array_stack_node *AStack;
typedef int Position;
struct _array_stack_node
{
    /* data */
    ElementType Data[MAX_SIZE];
    Position Top;
};



AStack MakeEmptyArrayStack();

int IsAStackFull(AStack ptrl);

int IsAStackEmpty(AStack ptrl);

void AStackPush(AStack ptrl, ElementType x);

ElementType AStackPop(AStack ptrl);

void PrintElement(AStack ptrl);