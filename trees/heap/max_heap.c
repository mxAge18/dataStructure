#include "max_heap.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_DATA 1000
MaxHeap Create(int MaxSize) {
    MaxHeap H = malloc(sizeof(struct MaxHeapStruct));
    H->Elements = malloc((MaxSize + 1)* sizeof(int)); // 从下标为1开始存
    H->Capacity = MaxSize;
    H->Size = 0;
    H->Elements[0] = MAX_DATA; //定义哨兵，大于所有可能值的数值，
    return H;
}
int IsFull(MaxHeap H) {
    int res = -1;
    if (H->Capacity == H->Size) {
        res = 1;
    }
    return res;
}
int IsEmpty(MaxHeap h) {
    int res = -1;
    if (h->Size == 0) res = 1;
    return res;
}

void Insert(MaxHeap H, int item) {
    // 将item插入到H中，H->elements[0]为哨兵
    int i;
    if (IsFull(H) > 0) return;
    H->Size++;
    i = H->Size;
    for (;H->Elements[i/2] < item; i /= 2) {
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = item;
}

int DeleteMax(MaxHeap h) {
    //删除element[1] 然后把element[size]移到1的位置。
    //然后1的元素与[2] [3]中较大值互换，i = 较大值下表，继续循环直到i的值比子节点的较大值打
    if (IsEmpty(h) > 0) return -1;
    int maxItem, temp; // 堆的值
    int posParent, posChild; // 堆的key
    maxItem = h->Elements[1];
    temp = h->Elements[h->Size];
    h->Size--;
    for (posParent = 1; posParent*2 <= h->Size;posParent = posChild) {
        posChild = posParent * 2;
        if ((posChild != h->Size) && (h->Elements[posChild] < h->Elements[posChild + 1])) {
            posChild += 1;
        }
        if (temp < h->Elements[posChild]) {
            h->Elements[posParent] = h->Elements[posChild];
        } else {
            break;
        }

    }
    h->Elements[posParent] = temp;
    return maxItem;
}

/*建立最大堆 
 方法1 先建立一个空堆，然后一个一个插入（O(nlog^n)）

 方法2 将N个元素先按顺序存储，先建立完全二叉树
      然后调整元素顺序，得到一个最大堆
*/

// 方法2：
void PerDown(MaxHeap h, int position) {
    // 将h->elements[postion]为根节点的树调整为最大堆。
    int temp;
    int child, parent;
    temp = h->Elements[position];
    for (parent = position; parent * 2 <= h->Size; parent = child) {
        child = parent * 2;
        if ((h->Elements[child] < h->Elements[child + 1]) && (h->Size != child)) {
            // 左儿子比右儿子小
            child += 1;
        }
        // 比较父节点和大儿子的值
        if (temp > h->Elements[child]) {
            break;
        } else {
            h->Elements[parent] = h->Elements[child];
        }

    }
    h->Elements[parent] = temp;
}

void BuildTree(MaxHeap h) {
    //假设数据已存到h->elements[]中，需要调整位置构造最大堆
    int i;
    for (i =  h->Size/2; i>0; i--) {
        PerDown(h, i);
    }
}