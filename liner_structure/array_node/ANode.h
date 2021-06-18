#include <stdio.h>
#include <stdlib.h>
#include "../common/linerLib.h"

// 1 定义单链表结构体 AList _array_node的指针
typedef struct _array_node *AList;
typedef int Position;

struct _array_node {
    /* data */
    ElementType Data[MAX_SIZE];
    Position Last;
};

AList MakeEmptyAList();

int AListInsert(ElementType X, AList Ptrl, Position Pos);

int AListLenght(AList Ptrl);

int AListFind(ElementType X, AList Ptrl);

void AListDelete(int i, AList Ptrl);

