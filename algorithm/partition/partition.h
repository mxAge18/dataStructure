#include <stdlib.h>
#include <stdio.h>

/** 1 归并排序
 * 1）数组长度为n，先将数组分为两部分
 * 2）两部分分别排序，
 * 3）分组排序后的两个数组组合到一起
 * 4）分成的两部分中，数组长度为1时停止分组
 * 
 * */
void merge_two_array();

void MergeSort(int a[], int start, int end, int tmp[]);

// void swap(int *a, int *b); // 交换a b的值
 
// void QuickSort(int *a,int s,int e); // 快速排序