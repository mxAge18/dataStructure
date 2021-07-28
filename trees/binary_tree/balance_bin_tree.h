// 平衡因子 balance factor:BF = height(l) - height(r)
// balanced binary tree : AVL tree
// BF <= 1;

// n(h) is minimum node number of a balanced binary tree which height is h;
// n(h) = n(h-2) + n(h-1) + 1

// 平衡树也是binary_search_tree; 插入数据后需要保持平衡及搜索树的特点，则需要对插入后的数据进行旋转
// RR旋：当向树右子树的右边节点插入数据，需要进行RR旋转保持tree的平衡
// LL旋：当向树左子树的左边节点插入数据，需要进行LL旋转保持tree的平衡
// LR旋：当向树左子树的右边节点插入数据，需要进行LR旋转保持tree的平衡
// RL旋：当向树右子树的左边节点插入数据，需要进行RL旋转保持tree的平衡
