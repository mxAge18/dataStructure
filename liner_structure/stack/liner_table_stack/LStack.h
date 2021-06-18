#include <stdio.h>
#include <stdlib.h>
#include "../../common/linerLib.h"

typedef struct _liner_stack_node *LStack;
struct _liner_stack_node
{
    /* data */
    ElementType Data;
    struct _liner_stack_node *Next;
};



LStack MakeEmptyLinerStack();

int IsLStackEmpty(LStack ptrl);

LStack LStackPush(LStack ptrl, ElementType x);

ElementType LStackPop(LStack ptrl);

void PrintLinerStackElement(LStack ptrl);