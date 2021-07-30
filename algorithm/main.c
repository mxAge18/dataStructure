#include <stdio.h>
#include "enumeration/enumeration.h"
void info() {
    printf("请输入要运行的代码\n");
    printf("1:perfect_cube\n");
    printf("2:physiological cycles\n");
    printf("3:fake coin\n");
    printf("4:close_lights\n");
}
int main() {
    int k;
    info();
    scanf("%d", &k);
    switch (k)
    {
    case 1:
        printf("perfect_cube\n");
        perfect_cube();
        break;
    case 2:
        printf("physiological cycles\n");
        physiological_cycles();
        break;
    case 3:
        printf("fake_coin\n");
        fake_coin();
        break;
    case 4:
        printf("close_lights\n");
        close_lights();
        break;
    default:
        break;
    }
    return 0;
}