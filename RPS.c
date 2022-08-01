#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int RPS_core() {
    int input;

    printf("请输入剪刀(0),石头(1),布(2):\n");
    fflush(stdout);

    scanf("%d", &input);
    srand(time(NULL));

//    switch
    switch (input) {
        case 0:
            printf("你出的剪刀\n");
            break;
        case 1:
            printf("你出的石头\n");
            break;
        case 2:
            printf("你出的布\n");
            break;
        default:
            printf("输入错误,程序退出\n");
            return 1;
    }

    int RPS;
//    指针，后面学，主要展示相同的尽量提炼出来。
    char *RPS_str = "剪刀";
    RPS = rand() % 2;
    if (RPS == 0) {
        RPS_str = "剪刀";
    } else if (RPS == 1) {
        RPS_str = "石头";
    } else if (RPS == 2) {
        RPS_str = "布";
    }
    printf("电脑出的%s\n", RPS_str);

//    简单算法 找规律
//    剪刀 0 石头 1 布 2
//    剪刀 - 石头 = -1 输
//    剪刀 - 布 = -2 赢
//    布 - (剪刀 + 3) = -1 输
//    布 - (石头 + 3) = -2 赢
    int result = input > RPS ? input - (RPS + 3) : input - RPS;
//    三元表达式 判断式?{真}:{假}
    printf(result == 0 ? "平局\n" : result == -1 ? "输\n" : "赢\n");

    return 0;
}

int main() {
    int quit;
//    do while 循环里面的
    do {
//      函数，暂时不用管，主要是难得每次输入都要运行
        quit = RPS_core();
    } while (!quit);
}