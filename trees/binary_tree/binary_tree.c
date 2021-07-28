#include "binary_tree.h"
#include "./stacklib/array_stack.h"
#include "./queuelib/liner_queue.h"


BinTree createBinTreeNode(ElementType x) {
    BinTree ptr;
    ptr = (BinTree)malloc(sizeof(struct _tree_node));
    ptr->Left = ptr->Right = NULL;
    ptr->Data = x;
    return ptr;
}
// 先序遍历 先访问根节点 然后访问左子树 然后访问右子树
void PreOrderTransferRecursive(BinTree ptr) {
    if (ptr) {
        printf("%d\n", ptr->Data);
        PreOrderTransfer(ptr->Left);
        PreOrderTransfer(ptr->Right);
    }
}

// 先序遍历 先访问根节点 然后访问左子树 然后访问右子树
void PreOrderTransfer(BinTree ptr) {
    BinTree tempTree = ptr;
    AStack ptrS = MakeEmptyArrayStack();
    while (tempTree || IsAStackEmpty(ptrS) < 0)
    {
        while (tempTree)
        {   
            printf("%d\n", tempTree->Data);
            AStackPush(ptrS, tempTree);
            tempTree = tempTree->Left;
        }
        if (IsAStackEmpty(ptrS) < 0) {
            tempTree =  AStackPop(ptrS);
            tempTree = tempTree->Right;
        }
    }
    

}
// 中序遍历 先访问左子树 然后访问根节点 然后访问右子树
void InOrderTransferRecursive(BinTree ptr) {
    if (ptr) {
        PreOrderTransfer(ptr->Left);
        printf("%d\n", ptr->Data);
        PreOrderTransfer(ptr->Right);
    }
}

// 中序遍历用堆栈处理遍历 先访问左子树 然后访问根节点 然后访问右子树
void InOrderTransfer(BinTree ptr) {
    BinTree tempTree = ptr;
    AStack ptrS = MakeEmptyArrayStack();
    while (tempTree || IsAStackEmpty(ptrS) < 0)
    {
        while (tempTree)
        {
            AStackPush(ptrS, tempTree);
            tempTree = tempTree->Left;
        }
        if (IsAStackEmpty(ptrS) < 0) {
            tempTree =  AStackPop(ptrS);
            printf("%d\n", tempTree->Data);
            tempTree = tempTree->Right;
        }
    }
}

// 后序遍历 先访问左子树 然后访问右子树 然后访问根节点
void PostOrderTransferRecursive(BinTree ptr) {
    if (ptr) {
        PreOrderTransfer(ptr->Left);
        PreOrderTransfer(ptr->Right);
        printf("%d\n", ptr->Data);
    }
}

// 中序遍历用堆栈处理遍历 先访问左子树 然后访问根节点 然后访问右子树
void PostOrderTransfer(BinTree ptr) {
    BinTree tempTree = ptr;
    BinTree lastVisit;
    AStack ptrS = MakeEmptyArrayStack();
    while (tempTree || IsAStackEmpty(ptrS) < 0)
    {
        while (tempTree)
        {
            AStackPush(ptrS, tempTree);
            tempTree = tempTree->Left;
        }
        if (IsAStackEmpty(ptrS) < 0) {
            // 堆栈非空，出栈

            tempTree =  AStackPop(ptrS);
            if (tempTree->Right == NULL || lastVisit == tempTree) {
                 printf("%d\n", tempTree->Data);
                 lastVisit = tempTree;
                 tempTree = NULL;
            } else {
                AStackPush(ptrS, tempTree);
                lastVisit = tempTree;
                tempTree = tempTree->Right;
            }
        }
    }
}

// 层序遍历，一层一层遍历得到数中的元素
    // 利用队列进行存储
    // 从根节点开始，先把根节点存入队列中，
    // 出队，printA,遍历出队元素A访问左子树B和右子树C，
    // B C 存入队列
    // B出队 printB,遍历B的左子树和右子树存入队列
    // 一直执行出队操作，知道队列为空。
void LevelOrderTransfer(BinTree ptr) {
    if (!ptr) {
        printf("空树\n");
        return;
    }
    LQueue liner_queue_point = MakeEmptyLinerQueue();
    BinTree tempBTree;
    addLinerNodeToQueue(liner_queue_point, ptr);
    while(isLQueueEmpty(liner_queue_point) > 0) {
        tempBTree = deleteLinerQueue(liner_queue_point);
        printf("%d\n", tempBTree->Data);
        if (tempBTree->Left != NULL) {
            addLinerNodeToQueue(liner_queue_point, tempBTree->Left);
        }
        if (tempBTree->Right != NULL) {
            addLinerNodeToQueue(liner_queue_point, tempBTree->Right);
        }
    }
    free(tempBTree);
    free(liner_queue_point);
    return;
}

int PostOrderGetBinTreeHeight(BinTree ptr) {
    int length_left,length_right, length;
    if (ptr) {
        length_left = PostOrderGetBinTreeHeight(ptr->Left);
        length_right = PostOrderGetBinTreeHeight(ptr->Right);
        length = length_left > length_right ? length_left : length_right;
        return length + 1;
    } else {
        return 0;
    }
}