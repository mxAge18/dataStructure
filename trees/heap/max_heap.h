
typedef struct MaxHeapStruct *MaxHeap;
struct  MaxHeapStruct
{
    /* data */
    int *Elements; //存放堆的数组
    int Size; // 当前堆的元素个数
    int Capacity; // 堆的最大的容量
};

MaxHeap Create(int MaxSize);
int IsFull(MaxHeap H);
void Insert(MaxHeap H, int item);
int DeleteMax(MaxHeap h);

void PerDown(MaxHeap h, int position);
void BuildTree(MaxHeap h);