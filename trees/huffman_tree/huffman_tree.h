#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *HuffmanTree;
struct  TreeNode
{
    int Weight;
    HuffmanTree Left,Right;
};

typedef struct MinHeapStruct *MinHeap;
struct  MinHeapStruct
{
    /* data */
    HuffmanTree *Elements; //存放堆的数组
    int Size; // 当前堆的元素个数
    int Capacity; // 堆的最大的容量
};

MinHeap Create(int MaxSize);
int IsFull(MinHeap H);
void Insert(MinHeap H, HuffmanTree item);
HuffmanTree DeleteMin(MinHeap h);
void PerMinDown(MinHeap h, int position);
void BuildMinTree(MinHeap h);


HuffmanTree Huffman(MinHeap h);