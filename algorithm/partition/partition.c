#include "partition.h"

void merge_two_array(int a[], int start, int mid, int end, int tmp[]) {
    // 将局部的从 a[s] 到 a[mid] 和a[mid + 1]到a[e]两部分进行合并
    // 利用另外的数组空间tmp
    // 保证这部分有序
    int temp_start = 0;
    int part_1 = start, part_2 = mid + 1;
    //第一部分和第二部分的数组下表从起始位置开始，先比较大小，小的存到tmp中，然后小的那个指针向后移动，
    while (part_1 <= mid && part_2 <= end)
    {
        /* code */
        if (a[part_1] < a[part_2]) {
            tmp[temp_start++] = a[part_1++];
        } else {
            tmp[temp_start++] = a[part_2++];
        }
    }
    // 执行到这一步，说明至少有一个指针到了终止的位置
    while (part_1 <= mid)
    {
        /* part 2 已经终止了，接下来把part 1 剩余的部分填到tmp对应位置 */
        tmp[temp_start++] = a[part_1++];
    }

    while (part_2 <= end)
    {
        /* part 1 已经终止了，接下来把part 2 剩余的部分填到tmp对应位置 */
        tmp[temp_start++] = a[part_2++];
    }
    // 到这一步，所有元素都存到tmp，把tmp0 到end - start + 1赋值到a[start] 到 a[end]
    for (int i = 0; i < end - start + 1; i++) {
        a[start+i] = tmp[i];
    }
}

void MergeSort(int a[], int start, int end, int tmp[]) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        MergeSort(a, start, mid, tmp);
        MergeSort(a, mid+1, end, tmp);
        merge_two_array(a, start, mid, end, tmp);
    }
}

// 交换a b的值
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
  
// 快速排序
void QuickSort(int a[],int s,int e) {
    // k = a[s] 把a按比k小和比k大划分到k的左右两边
    if (s >= e) return;
    int k = a[s];
    int i = s, j = e;
    while (i != j) {
        /* code */
        while (j > i && a[j] >= k ) {
            j--;
        }
        swap(&a[i], &a[j]);
        while (j > i && a[i] <= k ) {
            i++;
        }
        swap(&a[i], &a[j]); 
    }
    QuickSort(a, s, i - 1);
    QuickSort(a, i + 1, e);

}

int a[10] = {13,27,19,2,8,12,2,8,30,89};
int b[10];

int main() {
    int size = sizeof(a)/sizeof(int);
    QuickSort(a, 0, size-1);
    for(int i = 0;i < size; ++i) {
        printf("%d\t", a[i]);
    }
}