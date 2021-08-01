#include "recursive.h"

void hanoiRecursive(int n, char src, char mid, char dest) {
   if (n == 1) {
       // 只有一个盘子，直接将盘子从src 到 dest
       printf("从%c-> %c\n", src , dest);
       return;
    }
    // 先将n - 1移动到mid n 移动到dest
    hanoiRecursive(n - 1, src, dest, mid); 
    // 
    printf("从%c-> %c\n", src , dest);

    hanoiRecursive(n - 1, mid, src, dest); 
}

void Hanoi() {
    printf("Hanoi\n");
    int n;
    scanf("%d", &n);
    hanoiRecursive(n, 'A', 'B', 'C');
}

int QueenNumber;
int QueenPostion[100];

void q_queen_recursive(int k) {
    // k - 1以前的全部摆好，摆第N个皇后
    if (k == QueenNumber) {
        // 所有的queen都摆好了，直接输出结果
        for (int i = 0; i < QueenNumber; i++) {
            printf("%d ", QueenPostion[i] + 1);
        }
        printf("\n");
    }
    // 对第k个皇后进行排位置
    for (int i = 0; i < QueenNumber; i++) {
        // 从第1列一直到N列，为k寻找合适的位置
        int j;
        for (j = 0; j < k; j++) {
            // 看0 - k-1 有没有与i作为第k个queen的position相矛盾的位置
            if ((QueenPostion[j] == i) || abs(QueenPostion[j] - i) == abs(k - j)) {
                break;
            }
        }

        // 如果找到了一个合适的位置，满足条件，递归的执行k+1获取下一个queen合适的位置。
        // 上面的循环执行完了，没有发生break;就算找到了合适位置
        if (j == k) {
            QueenPostion[k] = i;
            q_queen_recursive(k+1);
        }
      
    }
}

void NQueen() {
    printf("NQUEEN\n Please input number of the queen");
    scanf("%d", &QueenNumber);
    q_queen_recursive(0); // 从第0行开始算皇后的位置
}




double Exp() {
    char s[20];
    scanf("%s", s);
    switch (s[0])
    {
        case '+':return Exp() + Exp();
        case '-':return Exp() - Exp();
        case '*':return Exp() * Exp();
        case '/':return Exp() / Exp();
        default:
            return atof(s);
            break;
    }

}



char exp_s[30];
void delete_first_char() {
    int l = strlen(exp_s);
    for (int i = 0; i < l;i++) {
        if (i == l - 1) {
            exp_s[i] = '\0';
        } else {
             exp_s[i] = exp_s[i+1];
        }
    }
}
int fact_val() {
    int res = 0;
    char c = exp_s[0];
    if (c == '(') {
        delete_first_char();
        res = exp_val();
        delete_first_char();
    } else {
        while (isdigit(c))
        {
           res = 10 * res + c - '0'; 
           delete_first_char();
            c = exp_s[0];
        }

    }
    return res;
}
int term_val() {
    int res = fact_val();

    int isContinue = 1;
    while (isContinue) {
        // 第一项的值已经求完，看第exp中第一个字符，如果是 + - 就计算按
        if (exp_s[0] == '*' || exp_s[0] == '/') {
            char c = exp_s[0];
            delete_first_char();
            if (c == '*') {
                res *= fact_val();
            } else {
                res /= fact_val();
            }
        } else {
            isContinue = 0;
        }  
    }
    return res;
}

int exp_val() {
    int result = term_val(); // 表达式第一项的值作为结果的初始值
    int isContinue = 1;
    while (isContinue) {
        // 第一项的值已经求完，看第exp中第一个字符，如果是 + - 就计算按
        if (exp_s[0] == '+' || exp_s[0] == '-') {
            char c = exp_s[0];
            delete_first_char();
            if (c == '+') {
                result += term_val();
            } else {
                result -= term_val();
            }
        } else {
            isContinue = 0;
        }  
    }
    return result;
}
void ExperessionVal() {
    printf("输入表达式：");
    scanf("%s", exp_s);
    int res = exp_val();
    printf("结果：%d\n", res);
}


int stairs_options(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    return stairs_options(n-1) + stairs_options(n-2);
}

void Stairs() {
    int n;
    printf("请输入n\n");
    scanf("%d", &n);
    int options = stairs_options(n);
    printf("结果是：%d\n", options);
}

int get_apple_options(int m, int n) {
    if (m < n) {
        return get_apple_options(m,m);
    }
    if (m == 0) return 1;
    if (n == 0) return 0;
    return get_apple_options(m, n - 1) + get_apple_options(m - n, n);
}
void SetApple() {
    int t,m,n;
    printf("请输入数据样本组数：\n");
    scanf("%d", &t);
    while (t--)
    {
        printf("请输入苹果数量：");
        scanf("%d", &m);
        printf("\n");
        printf("请输入盘子数量：");
        scanf("%d", &n);
        printf("%d", get_apple_options(m, n));
    }
}
int main() {
    // Hanoi();
    // NQueen();

    // ExperessionVal();

    // Stairs();

    SetApple();
    return 0;
}