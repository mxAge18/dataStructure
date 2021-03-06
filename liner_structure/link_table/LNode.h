#include <stdio.h>
#include <stdlib.h>
#include "../common/linerLib.h"

// 1 定义单链表结构体 List为 LNode的指针
typedef struct _liner_table_node *List;
struct _liner_table_node {
    /* data */
    ElementType Data;
    struct _liner_table_node *Next;
};

// 2 声明初始化一个空链表的函数
List MakeEmpty();

// 3 声明一个链表长度的函数，输入LNode结构体的指针，返回int值
int Length(List Ptrl);

// 4 声明返回链表第K个结构的指针的函数
List FindKth(int K, List Ptrl);

// 5 声明查找结构体对应数值的结构体的指针的函数
List Find(ElementType X, List Ptrl);

// 6 声明插入一个数值为X的结构体到链表第i个位置的函数
List Insert(int i,ElementType X, List Ptrl);

// 7 声明删除链表第i个结构的函数
List Delete(int i, List Ptrl);

// 8 声明一个按链表顺序打印的函数
void PrintData(List Ptrl);

// 9 声明一个初始化链表的函数
List InitLinerTable();

List SortLinerTabel(List Ptrl);

// 翻转一个链表
List Reverse(List head);

// 对链表前N个节点进行翻转
List ReverseN(List head, int i);

// 对链表的第m 到 n进行翻转
List ReverseBetween(List head, int m, int n);