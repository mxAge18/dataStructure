#include "LQueue.h"
// 链表做队列 A->B->C->D; A做插入和删除都方便， D做插入可以，删除找不到上一个节点。
// 所以 A做头部 D做队列的尾
// 初始状态只有A节点, front and rear both point to A，
// 插入B后，ptrl->front不变，把A->next = B，然后把ptrl->rear = B;
LNode MakeEmptyLinerNode() {
    LNode node_point = (LNode)malloc(sizeof(struct _liner_node));
    node_point->Data = 0;
    node_point->Next = NULL;
    return node_point;
}

LQueue MakeEmptyLinerQueue() {
    LQueue ptrl = (LQueue)malloc(sizeof(struct _liner_queue_node));
    ptrl->Front = NULL;
    ptrl->Rear = NULL;
    return ptrl;
}

int isLQueueEmpty(LQueue ptrl) {
    if (ptrl->Rear == ptrl->Front) {
        return 1;
    } else {
        return -1;
    }
}

void addLinerNodeToQueue(LQueue ptrl, ElementType x) {
    LNode tempElement = MakeEmptyLinerNode();
    tempElement->Data = x;
    if (ptrl->Front == NULL) {
        // 队列为空，插入node后，front end均指向新的node
        ptrl->Front = tempElement;
        ptrl->Rear = tempElement;
    } else {
        // 队列不空，把新node插入到链表，rear指向新node;
        ptrl->Rear->Next = tempElement;
        ptrl->Rear = tempElement;
    }
}

ElementType deleteLinerQueue(LQueue ptrl) {
    LNode front_cell = ptrl->Front;
    ElementType res;
    if (front_cell == NULL) {
        printf("队列为空\n");
        res = -100;
    } else {
        res = front_cell->Data;
        ptrl->Front = front_cell->Next;
        if (ptrl->Front == ptrl->Rear) {
            // 只有一个元素，出队后front reat都指向null
            ptrl->Rear = NULL;
        }
        free(front_cell);
        return res;
    }
    return res;
}
