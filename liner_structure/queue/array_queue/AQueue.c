#include "AQueue.h"

AQueue MakeEmptyArrayQueue() {
    AQueue ptrl = (AQueue)malloc(sizeof(struct _array_queue_node));
    ptrl->Data = (ElementType *)malloc(MAX_SIZE * sizeof(ElementType));
    ptrl->Top = ptrl->Bottom = 0;
    ptrl->MaxSize = MAX_SIZE;
    return ptrl;
}

int isAQueueFull(AQueue ptrl) {
    if (((ptrl->Bottom + 1) % MAX_SIZE) == ptrl->Top) {
        return 1;
    } else {
        return -1;
    }
}

int isAQueueEmpty(AQueue ptrl) {
    if (ptrl->Top == ptrl->Bottom) {
        return 1;
    } else {
        return -1;
    }
}

void addArrayQueue(AQueue ptrl, ElementType x) {
    if (isAQueueFull > 0) {
        printf("队列满，不能入队");
    } else {
        // bottom++,把元素插入到data[]中
        ptrl->Bottom = (ptrl->Bottom + 1) % ptrl->MaxSize;
        ptrl->Data[ptrl->Bottom] = x;
    }
    return;
}   

ElementType deleteArrayQueue(AQueue ptrl) {
    ElementType res;
    if (isAQueueEmpty(ptrl) > 0) {
        printf("队列空，不能出队");
        return -100;
    } else {
        ptrl->Top = (ptrl->Top + 1) % ptrl->MaxSize;
        res = ptrl->Data[ptrl->Top];
    }
    return res;
}