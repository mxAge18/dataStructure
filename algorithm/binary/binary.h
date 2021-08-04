#include <stdio.h>
#include <stdlib.h>

/** 1 二分查找算法
 * 
 */
int BinarySearch(int a[], int size, int p);


/**
 * 写一个函数LowerBound
 * 在包含size个元素的、从小到大排序的int数组a里查找比给定整数p小的，下标最大的元素。
 * 找到则返回其下标，找不到则返回-1
 * */
int LowerBound(int a[], int size, int p);