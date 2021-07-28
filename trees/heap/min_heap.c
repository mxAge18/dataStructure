#include "min_heap.h"
#include <stdio.h>
#include <stdlib.h>
MinHeap Create(int MaxSize) {
    MinHeap h = malloc(sizeof(struct MinHeapStruct));
    h->Size = 0;
    h->Capacity = 1000;
    h->Elements = malloc(1001 * sizeof(int));
    return h;
}
int IsFull(MinHeap H) {
    int res = 1;
    if (H->Size == H->Capacity) res = 1;
    return res;
}
int IsEmpty(MinHeap H) {
    int res = 1;
    if (H->Size == 0) res = 1;
    return res;
}
void Insert(MinHeap H, int item) {
    if (IsFull(H) > 0) return;
    int i;
    H->Size++;
    i = H->Size;
    for (;H->Elements[i/2] > item; i /= 2) {
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = item;
}
int DeleteMin(MinHeap h) {
    int parent, child;
    int temp, min;
    if (IsEmpty(h) > 0) return -1;
    min = h->Elements[1];
    temp = h->Elements[h->Size];
    h->Size--;
    for (parent = 1; parent * 2 <= h->Size; parent = child) {
        child = parent * 2;
        if ((h->Elements[child] > h->Elements[child + 1]) && (h->Size != child)) {
            child++;
        }
        if (temp > h->Elements[child]) {
            h->Elements[parent] = h->Elements[child];
        } else {
            break;
        }
    }
    h->Elements[parent] = temp;
    return min;
}

void PerDown(MinHeap h, int position);

// 方法2：
void PerMinDown(MinHeap h, int position) {
    // 将h->elements[postion]为根节点的树调整为最小堆。
    int temp;
    int child, parent;
    temp = h->Elements[position];
    for (parent = position; parent * 2 <= h->Size; parent = child) {
        child = parent * 2;
        if ((h->Elements[child] > h->Elements[child + 1]) && (h->Size != child)) {
            // 左儿子比右儿子大
            child += 1;
        }
        // 比较父节点和小儿子的值
        if (temp < h->Elements[child]) {
            break;
        } else {
            h->Elements[parent] = h->Elements[child];
        }

    }
    h->Elements[parent] = temp;
}

void BuildMinTree(MinHeap h) {
    //假设数据已存到h->elements[]中，需要调整位置构造最小堆
    int i;
    for (i =  h->Size/2; i>0; i--) {
        PerMinDown(h, i);
    }
}