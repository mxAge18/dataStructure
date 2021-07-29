#include "set.h"
#define MAXSIZE 100
int Find(SetType S[], int X) {
    int i;
    for (i = 0; i< MAXSIZE && S[i].Data != X; i++);
    if (i >= MAXSIZE) return -1;
    for (; S[i].Parent >= 0; i = S[i].Parent);
    return i;
}

void Union(SetType S[], int X1, int X2) {
    int root1, root2;
    root1 = Find(S, X1);
    root2 = Find(S, X2);
    if (root1 != root2) S[root2].Parent = root1;
}