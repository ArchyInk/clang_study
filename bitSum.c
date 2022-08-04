//
// Created by htq on 2022/8/4.
//

//给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。
//
//示例 1:
//
//输入: num = 38
//输出: 2
//解释: 各位相加的过程为：
//38 --> 3 + 8 --> 11
//11 --> 1 + 1 --> 2
//由于2 是一位数，所以返回 2。
//示例 1:
//
//输入: num = 0
//输出: 0
//
//进阶：你可以不使用循环或者递归，在 O(1) 时间复杂度内解决这个问题吗？
//来源：力扣（LeetCode）
//链接：https://leetcode.cn/problems/add-digits
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include "stdio.h"

int addDigits(int num) {
    while (num >= 10) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num = num / 10;
        }
        num = sum;
    }
    return num;
//    数学方法
//    return (num - 1) % 9 + 1;
}


int main() {
    int useCase[] = {1, 10, 998, 19998, 299998};
    int expect[] = {1, 1, 8, 9, 1};

    for (int i = 0; i < sizeof(useCase) / sizeof(useCase[0]); i++) {
        printf("测试用例：%d\n", useCase[i]);
        int result = addDigits(useCase[i]);
        printf("结果: %d\n", result);
        printf("预期答案：%d\n", expect[i]);
        printf(expect[i] == result ? "测试通过\n" : "测试未通过\n");
    }
    return 0;
}

