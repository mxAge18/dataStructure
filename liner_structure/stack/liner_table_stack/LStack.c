#include "LStack.h"
//链栈 栈的插入删除在栈顶，ptrl->Top = null 时为空栈，A->B->C->D A为NUll, B为栈顶，D为栈底
LStack MakeEmptyLinerStack() {
    LStack ptrl;
    ptrl = (LStack)malloc(sizeof(struct _liner_stack_node));
    ptrl->Next = NULL;
    ptrl->Data = -100;
    return ptrl;
}

int IsLStackEmpty(LStack ptrl) {
    int res;
    if (ptrl->Next == NULL) {
        res = 1;
    } else {    
        res = -1;
    }
    return res;
}

LStack LStackPush(LStack ptrl, ElementType x) {
    // 链表头ptrl->next为栈顶元素，进栈时新的数据指向原来的栈顶元素，链表头指向新的元素。
    // 也就是newElement-> next = ptrl->next; ptrl->next = newElement
    LStack nesElement = MakeEmptyLinerStack();
    nesElement->Data = x;
    nesElement->Next = ptrl->Next;
    ptrl->Next = nesElement;
    return ptrl;
}

ElementType LStackPop(LStack ptrl) {
    // 链表头ptrl->next为栈顶元素，进栈时新的数据指向原来的栈顶元素，链表头指向新的元素。
    // 也就是newElement-> next = ptrl->next; ptrl->next = newElement
    LStack firstCell;
    if (IsLStackEmpty(ptrl) > 0) {
        printf("堆栈已空，不能pop\n");
        return ERROR;
    } else {
        firstCell = ptrl->Next;
        ElementType res = firstCell->Data;
        ptrl->Next = firstCell->Next;
        free(firstCell);
        return res;
    }

}

void PrintLinerStackElement(LStack ptrl) {
    if (ptrl->Next != NULL) {
        printf("%d\n",ptrl->Data);
        ptrl = ptrl->Next;
    }
}