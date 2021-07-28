#include "binary_search_tree.h"


Position FindFromBinSearchTree(ElementType x, BinTree p) {
    while(p) {
        if (p->Data < x) {
            p = p->Right;
        } else if (p->Data > x) {
            p = p->Left;
        } else {
            return p; // 查找到 返回指针。
        }
    }
    return NULL; // empty tree;
}
Position FindMinFromBinSearchTree(BinTree p) {
    if (!p) {
        return p;
    } else if (!p->Left) {
        return p->Left;
    } else {
        return FindMinFromBinSearchTree(p->Left);
    }
}


// 最大元素一定在最右子树的端节点
Position FindMaxFromBinSearchTree(BinTree p) {
    if (p) {
        while (p->Right) {
            p = p->Right;
        }
    }
    return p;
}

BinTree InsertXToBinSearchTree(BinTree p, ElementType x) {
    if (!p) {
        // 数为空，
        p = createBinTreeNode(x);
    } else {
        if (x < p->Data) {
            //向左子树插入元素
            p->Left = InsertXToBinSearchTree(p->Left, x);
        } else if (x > p->Data) {
            //向右子树插入元素
            p->Left = InsertXToBinSearchTree(p->Right, x);
        } else {
            printf("该元素已存在，不进行插入操作\n");
        }
    }
    return p;
}



BinTree DeleteFromBinSearchTree(BinTree p, ElementType x) {
    Position tempTreeNode;
    if (!p) {
        printf("未找到元素\n");
    } else if (x < p->Data) {
        p->Left = DeleteFromBinSearchTree(p->Left, x);
    } else if (x > p->Data) {
        p->Right = DeleteFromBinSearchTree(p->Right, x);
    } else {
        // 找到了，x == p->data;
        if (p->Left && p->Right) {
            // 左右节点都存在
            // 右子树找最小节点填充要删除的节点
            tempTreeNode = FindMinFromBinSearchTree(p->Right);
            p->Data = tempTreeNode->Data;
            p->Right = DeleteFromBinSearchTree(p->Right, p->Data);
        } else {
            tempTreeNode = p;
            if (!p->Left) {
                p = p->Right;
            } else if (!p->Right) {
                p = p->Left;
            }
            free(tempTreeNode);
        }
    }
    return p;
}