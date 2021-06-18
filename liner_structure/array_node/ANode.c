#include "ANode.h"

AList MakeEmptyAList() {
    AList Ptrl;
    Ptrl = (AList)malloc(sizeof(struct _array_node));
    Ptrl->Last = -1;
    return Ptrl;
}

int AListLenght(AList Ptrl) {
    return Ptrl->Last + 1;
}

//查找某个元素并返回第一次出现的位置，-1为未找到。
int AListFind(ElementType X, AList Ptrl) {
    Position i = 0;
    while (i <= Ptrl->Last && X!= Ptrl->Data[i]) {
        i++;
    }
    if (i > Ptrl->Last) {
        return -1;
    } else {
        return i;
    }
}

void AListDelete(Position i, AList Ptrl) {
    if (i < 1 || i > Ptrl->Last + 1) {
        printf("不存在第%d个元素\n", i);
        return;
    }
    Position j;
    // 第I个元素删除，Array[i-1]开始，后面的元素替换掉前面的。
    for (j = i; j < Ptrl->Last;j++) {
        Ptrl->Data[j - 1] = Ptrl->Data[j];
    }
    Ptrl->Last--;
    return;
}

int AListInsert(ElementType X, AList Ptrl, Position P) {
    /* 在L的指定位置P前插入一个新元素X */
    Position i;
    if (Ptrl->Last >= MAX_SIZE - 1) {
        //数组满，不能插入
        printf("表满");
        return -1;
    }
    if (P < 0 || P > Ptrl->Last + 1) {
        //插入位置不合法
        printf("插入位置不合法");
        return -1;
    }

    // 将x插入到位置p,p以后的元素后移
    for(i = Ptrl->Last; i >= P; i--) {
        Ptrl->Data[i+1] =  Ptrl->Data[i];
    }
    Ptrl->Data[P] = X;
    Ptrl->Last++;
    return 1;
}