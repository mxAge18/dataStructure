# 集合的表示

- 集合运算：交 并 补 差，判定一个元素是否属于一个集合；
- 并查集：集合**并、查**某元素是否属于一个集合；
- 并查集中集合存储如何实现？
- 用数标识，节点标识集合元素

## 集合的并操作

- 分别查找x1 x2两个元素所在集合树的根节点
- 如果不同根，将其中一个集合的根节点的父节点的指针设置成另一个根节点的数组下标。
