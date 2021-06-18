#include<stdio.h>
#include"liner_structure/link_table/LNode.h"
#include"liner_structure/stack/array_stack/AStack.h"
void mainMap() {
    printf("hello plese input number to choose func!\n");
    printf("1 means: liner table!\n");
    printf("2 means: stack test!\n");
}

void LinerTabelFunc() {
    printf("hello plese input number to choose func!\n");
    printf("1 means: sort this liner table!\n");
    printf("2 means: delete element!\n");
    printf("3 means: find KTh element!\n");
    printf("4 means: find element by data!\n");
}
 int main(void) {
    int key, res;
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
                Ptrl = InitLinerTable(Ptrl);
                int lengthOfLNode = Length(Ptrl);
                printf("链表长度为%d\n", lengthOfLNode);
                PrintData(Ptrl);
                LinerTabelFunc();
                int key2;
                printf("请您输入操作的值:\n");
                fflush(stdout);
                scanf("%d", &key2);
                fflush(stdin);
  
                switch (key2) {
                    case 1/* constant-expression */:
                        /* code */
                        break;
                    
                    default:
                        break;
                }
                loop = -1;
                break;
            case 2:
                /* code */
                printf("开始使用堆栈!\n");
                AStack ptrl = MakeEmptyArrayStack();
                AStackPush(ptrl, 1);
                AStackPush(ptrl, 12);
                AStackPush(ptrl, 123);
                AStackPop(ptrl);
                PrintElement(ptrl);
                AStackPush(ptrl, 1233);
                AStackPush(ptrl, 1234);
                AStackPush(ptrl, 1235);

                PrintElement(ptrl);
                AStackPush(ptrl, 1235);
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

