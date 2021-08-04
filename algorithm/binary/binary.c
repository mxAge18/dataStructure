#include "binary.h"

/** 1 BinarySearch
 * 数组元素从小到大排列
 * 查找p 在数组a中的位置，返回数组下标。
 */
int BinarySearch(int a[], int size, int p) {
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == p) {
            return mid;
        } else if (a[mid] > p) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

/** 2 LowerBound
 * 写一个函数LowerBound
 * 在包含size个元素的、从小到大排序的int数组a里查找比给定整数p小的，下标最大的元素。
 * 找到则返回其下标，找不到则返回-1
 * */
int LowerBound(int a[], int size, int p) {
    int left = 0;
    int right = size - 1;
    int pos = -1;
    while (left <= right)
    {
        /* code */
        int mid = left + (right - left) / 2;
        if (a[mid] >= p) {
            right = mid - 1;
        } else {
            pos = mid;
            left = mid + 1;
        }
    }
    return pos;
    
}