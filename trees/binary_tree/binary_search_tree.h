// 左子树的所有键值小于根节点 右子树所有键值大于根节点 子树均为二叉搜索树。
#include "binary_tree.h"

Position Find(ElementType x, BinTree p);
Position FindMin(BinTree p);
Position FindMax(BinTree p);
Position InsertXToBinSearchTree(BinTree p, ElementType x);
BinTree DeleteFromBinSearchTree(BinTree p, ElementType x);