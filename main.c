#include<stdio.h>
#include"liner_structure/link_table/LNode.h"
void mainMap() {
    printf("hello plese input number to choose func!\n");
    printf("1 means: liner table!\n");
    printf("2 means: array!\n");
}
 int main(void) {
    int key, v, res;
    int loop = 1;
    do {
        mainMap();
        printf("请您输入key的值:\n");
        fflush(stdout);
        scanf("%d", &key);
        fflush(stdin);
        switch (key) {
            case 1:
                /* code */
                printf("开始使用线性链表!\n");
                List Ptrl = MakeEmpty();
                printf("初始化链表，请以空格输入多个数字，存入链表中!\n");
                do {
                    scanf("%d", &v);
                    // fflush(stdin);
                    char c = getchar();
                    Ptrl = Insert(1,v,Ptrl);
                    if (c == '\n') {
                        break;
                    }
                } while (1);
                int lengthOfLNode = Length(Ptrl);
                printf("链表长度为%d\n", lengthOfLNode);
                while (Ptrl->Next != NULL) {
                    printf("链表所存取的数据：%d\n", Ptrl->Data);
                    Ptrl = Ptrl->Next;
                }
                loop = -1;
                break;
        
            default:
                printf("你的输入有误，请重新输入\n");
                loop = 1;
                break;
        }
    } while (loop > 0);
     return 0;
 }

