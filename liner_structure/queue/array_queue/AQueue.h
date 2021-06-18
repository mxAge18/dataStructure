#include "../../common/linerLib.h"

typedef struct _array_queue_node *AQueue;
typedef int Position;
// 队列的头、尾分别从0开始，max_size -1 结束，数组存max_size - 1个元素，留一个空的位置，否则需要另加一个size标识是否满队列
struct  _array_queue_node
{
    ElementType *Data;
    Position Top;
    Position Bottom;
    int MaxSize;           /* 队列最大容量 */
};

AQueue MakeEmptyArrayQueue();

int isAQueueFull(AQueue ptrl);

int isAQueueEmpty(AQueue ptrl);

void addArrayQueue(AQueue ptrl, ElementType x);

ElementType deleteArrayQueue(AQueue ptrl);