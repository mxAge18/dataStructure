#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define ERROR -100
#include "../binary_tree.h"


typedef struct _liner_queue_node *LQueue;
struct _liner_node
{
     BinTree Data;
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

void addLinerNodeToQueue(LQueue ptrl, BinTree x);

BinTree deleteLinerQueue(LQueue ptrl);
