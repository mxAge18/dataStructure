#include<stdio.h>
#include"liner_structure/link_table/LNode.h"
void mainMap() {
    printf("hello plese input number to choose func!\n");
    printf("1 means: liner table!\n");
    printf("2 means: array!\n");
}
 int main(void) {
    int key;
    while (1) {
        mainMap();
        scanf("%d\n", &key);
        switch (key) {
        case 1:
            /* code */
            printf("开始使用线性链表!\n");
            List Ptrl = MakeEmpty();
            int lengthOfLNode = Length(Ptrl);
            printf("链表长度为%d\n", lengthOfLNode);
            break;
        
        default:
            printf("你的输入有误，请重新输入\n");
            break;
        }
     }

     return 0;
 }