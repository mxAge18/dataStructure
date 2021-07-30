#include "enumeration.h"

void perfect_cube() {
    int N;
    printf("输入N:");
    scanf("%d", &N);
    int a, b, c, d;
    for (a = 2; a <= N; a++) {
        for (b = 2; b < a; b++) {
            for (c = b; c < a; c++) {
                for (d = c; d < a; d++) {
                    if (a*a*a == (b*b*b + c*c*c + d*d*d)) {
                        printf("cube = %d, triple = (%d %d %d)\n", a, b, c, d);
                    }
                }
            }
        }
    }
}




void physiological_cycles() {
    int p,e,i;
    int d;
    // 从d+1开始，直到21252，求同时是p e i的日子
    printf("请按顺序分别输入p e i d的值（体力高峰 情感高峰 智力高峰，给定日子）\n");
    scanf("%d %d %d %d", &p, &e, &i, &d);
    int k;
    for(k = d + 1; (k - p) % 23 != 0; k++);
    for(;(k - e) % 28 != 0; k += 23);
    for(;(k - i) % 33 != 0; k += 23 * 28);
    printf("下一个三高峰是一天的日子为：%d", k - d);
}

char left[3][7];
char right[3][7];
char result[3][7];

int isFake(char c,int light) {
    // 假设c是轻的。
    for(int i = 0; i < 3; i++) {
        char *ptrLeft;
        char *ptrRight; // 指向天平两侧的字符串
        if (light > 0) {
            ptrLeft = left[i];
            ptrRight = right[i];
        } else {
            ptrLeft = right[i];
            ptrRight = left[i];
        }
        switch (result[i][0]) {
            case 'u':
            // 右端的硬币轻
                if (strchr(ptrRight, c) == NULL) {
                    // 如果右侧不存在假设的假币c 说明假设错误，返回结果
                    return 0;
                }
                break;
            case 'd':
            // 左端的硬币轻
                if (strchr(ptrLeft, c) == NULL) {
                    // 如果右侧不存在假设的假币c 说明假设错误，返回结果
                    return 0;
                }
                break;
            case 'e':
              // 相同重量
                if (strchr(ptrRight, c) != NULL || strchr(ptrLeft, c) != NULL) {
                    // 如果c在其中一边就说明假设不成立
                    return 0;
                }
                break;
            default:
                break;
        }
    }
    return 1;
}

void fake_coin() {

    printf("请输入三次称量结果:\n");
    for(int i = 0; i < 3; i++) {
        scanf("%s %s %s", left[i], right[i], result[i]);
    }
    for (char c = 'A'; c <= 'L'; c++) {//题目中共12枚硬币
        if (isFake(c, 1) > 0) {
            printf("%c is fake coin, it is light.\n", c);
            break;
        } else if (isFake(c, 0) > 0) {
              printf("%c is fake coin, it is heavy.\n", c);
            break;
        }
    } 
}




char original_lights[5];
char lights[5];
char open_result[5];
int GetBit(char c, int i) {
    return (c >> i) & 1;
}
char SetBit(char c, int i, int v) {
    if (v) {
        c |= (1 << i);
    }
     else {
         c &= ~(1 << i);
     }
    return c;
}

char FlipBit(char c, int i) {
    c ^= (1 << i);
    return c;
}
void OutputRes(int t, char result[]) {
    printf("PUZZLE #%d\n", t);
    for (int i = 0; i < 5; ++i) {
        
        for (int j = 0; j < 6; j++) {
            printf("%d",GetBit(result[i], j));
            if (j < 5) {
                printf(" ");
            } else {
                printf("\t\n");
            }
        }
    }
}
void close_lights() {
    int t;
    printf("请输入测试数据的组数：");
    scanf("%d", &t);
    for (int times = 1; times <= t; times++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                int s;
                scanf("%d", &s);
                original_lights[i] = SetBit(original_lights[i], j, s);
            }
        }
    }
    //开始枚举第一行所有开关状态，1到64（0~63）
    for (int n = 0; n < 64; n++) {
        memcpy(lights, original_lights, sizeof(original_lights));
        char switchs = n;
        for (int i = 0; i < 5; i++) {
            // 处理第i行的开关状态
            open_result[i]= switchs;
            for (int j = 0; j < 6; j++) {
                // 第i行所有开关的状态枚举
                if (GetBit(open_result[i], j)) {
                    // 开关是开的，影响本行及下一行的数据
                    if (j > 0) {
                        lights[i] = FlipBit(lights[i], j-1);
                    }
                    if (j < 5) {
                         lights[i] = FlipBit(lights[i], j+1);
                    }
                     lights[i] = FlipBit(lights[i], j);
                }
            }
            if (i < 4) {
                lights[i+1] ^= switchs;
                // 确定第i+1行的开关的状态。
                switchs = lights[i];
            }
        }

        // 看最后一行的灯是否全灭
        if (lights[4] == 0) {
            OutputRes(t, open_result);
            break;
        }
    }
}