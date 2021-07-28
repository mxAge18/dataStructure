// 链表实现
#include "LNode.h"
// struct LNode L;
// List Ptrl;

List MakeEmpty() {
    List Ptrl = (List)malloc(sizeof(struct _liner_table_node));
    Ptrl->Data = -100;
    Ptrl->Next = NULL;
    return Ptrl;
}
// 长度
int Length(List Ptrl) {
    List p = Ptrl;
    int j = 0;
    while (p) {
        p = p->Next;
        j++;
    }
    return j - 1;
}

//查找第K个元素
List FindKth(int K, List Ptrl)
{
    List p = Ptrl;
    int j = 1;
    while (p != NULL || j < K)
    {
        p = p->Next;
        j++;
    }
    if (j == K) {
        return p;
    } else {
        return NULL;
    }
}

List Find(ElementType X, List Ptrl)
{
    List p = Ptrl;
    while (p != NULL || p->Data != X)
    {
        p = p->Next;
    }
    return p;
}

// 插入
/*
在第i-1个节点后插入一个值为X的元素
1 构造一个节点，用s指向
2 找到第i-1个节点，用p指向
3 修改指正，插入节点，p指向s，s指向原来的p->next;
*/
List Insert(int i,ElementType X, List Ptrl)
{
    List p,s;
    if (i == 1) {
        s = (List)malloc(sizeof(struct _liner_table_node));
        s->Next = Ptrl;
        s->Data = X;
        return s;
    }

    p = FindKth(i-1, Ptrl);
    if (p == NULL) {
        printf("参数i错误");
        return NULL;
    } else {
        s = (List)malloc(sizeof(struct _liner_table_node));
        s->Next = p->Next;
        s->Data = X;
        p->Next = s;
        return Ptrl;
    }

}

// 删除(删除第i个位置上的节点， i取值为1——N)
/*
1 先找到第i-1个位置的指针p
2 s指向p->next p->next 
3 s
*/

List Delete(int i, List Ptrl)
{
    List p,s;
    if (i == 1) {
        s = Ptrl;
        if (Ptrl != NULL) {
            Ptrl = Ptrl->Next;
        } else {
            return NULL;
        }
        free(s);
        return Ptrl;
    } else {
        p = FindKth(i - 1, Ptrl);
        if (p == NULL) {
            printf("第%d个节点不存在", i - 1);
            return NULL;
        } else if (p->Next == NULL) {
            printf("第%d个节点不存在", i);
            return NULL;
        } else {
            s = p->Next;
            p->Next = s->Next;
            free(s);
            return Ptrl;
        }
    }
}

void PrintData(List Ptrl) {
    printf("链表所存取的数据:\n");
    while (Ptrl->Next != NULL) {
        printf("->%d\n", Ptrl->Data);
        Ptrl = Ptrl->Next;
    }
    free(Ptrl);
}

List InitLinerTable(List Ptrl) {
    int v;
    char c;
    printf("初始化链表，请以空格输入多个数字，存入链表中!\n");
    do {
        scanf("%d", &v);
        // fflush(stdin);
        c = getchar();
        Ptrl = Insert(1,v,Ptrl);
        if (c == '\n') {
            break;
        }
    } while (1);
    return Ptrl;

}

List SortLinerTabel(List Ptrl) {
    return Ptrl;
}


// 链表中m 到 n的元素进行翻转
// 1<=m<=n<=len(ptrl)
/*
    1 输入链表的头指针，
    2 以头指针为起点进行翻转
    3 返回翻转后的头结点
*/
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
// head

//   1 -> reverse(2 -> 3 -> 4 -> 5 -> NULL)
// head


// 对链表所有元素进行翻转
List Reverse(List head) {
    // 头节点->next如果不空，递归调用函数翻转
    // 头节点->next变为null，翻转后的尾节点指向头结点
    if (head->Next == NULL) return head;
    List last = Reverse(head->Next);
    head->Next->Next = head; // 变换后的尾巴节点指向head
    head->Next = NULL;       // head->next变为null, 成为新的尾节点
    return last;
}

// 对链表前N个节点进行翻转
List successor = NULL; //后驱节点
List ReverseN(List head, int i) {
    // 翻转以head为开头的n个节点，返回新的头结点
    // 前N个节点翻转，原来的头节点变成前N个节点的尾节点，
    // 原来的头节点指向未翻转的节点第一个节点
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 i = 3;
    // 3 -> 2 -> 1 -> 4 -> 5 -> 6
    if (i == 1) {
        successor = head->Next;
        return head;
    }
    // 以head->next为起点，反转前n-1个节点
    List last = ReverseN(head->Next, i - 1);

    head->Next->Next = head;
    // 翻转后的head节点与后面的节点连接起来。
    head->Next = successor; 
    return last;
}

List ReverseBetween(List head, int m, int n) {
    if (m == 1) {
        return ReverseN(head, n);
    }
    // m ！= 1 ,把链表的起点跳过，从head->next找需要翻转的元素，
    // 向前挪动一位，要翻转的位置就都 - 1
    head->Next = ReverseBetween(head->Next, m - 1, n - 1);
    return head;
}