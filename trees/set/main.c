// 将一系列数字存入minHeap, 然后对于给定的任意下标i,打印从h[i]到根的路径
#include <stdlib.h>
#include <stdio.h>
#define MAXN 1000
#define MINH -10001

int H[MAXN];
int size;
void Create() {
    size = 0;
    H[0] = MINH;
}
void Insert(int X) {
    int i;
    size += 1;
    i = size;
    for (;(H[i/2] > X && i > 0); i/=2) {
        // 插入的值从最后一个节点的父节点开始比较，如果父节点比x大，则把父节点下移动，并且数组下表变为父节点，直到找到一个位置，x比父节点的位置大
        H[i] = H[i/2];
    }
    H[i] = X;
}
int main() {
    // 读入n,m //节点个数，打印次数
    int n,m,x,i,j;
    scanf("%d %d", &n, &m);
    Create();
    //读入n个节点
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        Insert(x);
    }
    // 读入m个节点并打印从节点到根节点的路径
    for (i = 0; i < m; j++) {
        scanf("%d", &j); //读入下标；
        printf("开始读取:\n%d\n", H[j]);
        while(j > 0) {
            j = j / 2;
            if (j > 0)  printf("%d\n", H[j]);
           
        }
    }

}