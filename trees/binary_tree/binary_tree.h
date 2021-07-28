#include "../../common/commonLib.h"
typedef struct _tree_node *BinTree;
struct _tree_node {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
typedef BinTree Position;

BinTree createBinTreeNode(ElementType x);

/**四种遍历方法
*/
// 先序遍历 先访问根节点 然后访问左子树 然后访问右子树
void PreOrderTransferRecursive(BinTree ptr);
void PreOrderTransfer(BinTree ptr);

void InOrderTransferRecursive(BinTree ptr);
void InOrderTransfer(BinTree ptr);

void PostOrderTransferRecursive(BinTree ptr);
void PostOrderTransfer(BinTree ptr);

void LevelOrderTransfer(BinTree ptr);

int PostOrderGetBinTreeHeight(BinTree ptr);