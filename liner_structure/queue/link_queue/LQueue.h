#include "../../common/linerLib.h"

typedef struct _liner_queue_node *LQueue;
struct _liner_node
{
     ElementType Data;
     struct _liner_node *Next;
};

struct  _liner_queue_node
{
    struct  _liner_node *Front;
    struct  _liner_node *Rear;
};
typedef struct _liner_node *LNode;

LNode MakeEmptyLinerNode();

LQueue MakeEmptyLinerQueue();

int isLQueueEmpty(LQueue ptrl);

void addLinerNodeToQueue(LQueue ptrl, ElementType x);

ElementType deleteLinerQueue(LQueue ptrl);
