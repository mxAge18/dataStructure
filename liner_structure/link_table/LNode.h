#include <stdio.h>
#include <stdlib.h>
#include "../common/linerLib.h"

// 1 定义单链表结构体 List为 LNode的指针
typedef struct LNode {
    /* data */
    ElementType Data;
    struct LNode *Next;
}*List;

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
