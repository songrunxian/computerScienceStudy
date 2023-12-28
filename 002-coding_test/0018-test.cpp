#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
//输入n 计算n 的阶乘
int factorial(int);

int main() {
        int n;
        while(scanf("%d", &n) != EOF) {
                printf("%d\n", factorial(n));
        }
        return 0;
}

int factorial(int num) {
        int result = 1;
        __builtin_expect(!!(num == 0), 1);
        while(num > 0) {
                result *= num;
                num--;
        }
        return result;
}
