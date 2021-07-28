#include "array_stack.h"
AStack MakeEmptyArrayStack(){
    AStack Ptrl;
    Ptrl = (AStack)malloc(sizeof(struct _array_stack_node));
    Ptrl->Top = -1;
    return Ptrl;
}

int IsAStackFull(AStack ptrl) {
    if (ptrl->Top == 100 - 1) {
        return 1;
    } else {
        return -1;
    }
}

int IsAStackEmpty(AStack ptrl) {
    if (ptrl->Top == -1) {
        return 1;
    } else {
        return -1;
    }
}

void AStackPush(AStack ptrl, BinTree x) {
    int isFull = IsAStackFull(ptrl);
    if (isFull > 0) {
        printf("堆栈已满，不能插入%d\n", x->Right);
    } else {
        ptrl->Data[ptrl->Top + 1] = x;
        ptrl->Top++;
    }
    return;
}

BinTree AStackPop(AStack ptrl) {
    int isEmpty = IsAStackEmpty(ptrl);
     BinTree data;
    if (isEmpty > 0) {
        data = NULL;
        printf("堆栈已空，不能出栈\n");
    } else {
        data = ptrl->Data[ptrl->Top];
        ptrl->Data[ptrl->Top] = NULL;
        ptrl->Top--;
    }
    return data;
}


void PrintElement(AStack ptrl) {
    for (int i = 0; i < 100; i++) {
        printf("%d\n", ptrl->Data[i]->Data);
    }
    printf("堆栈当前top：%d\n", ptrl->Top);
    return;
}