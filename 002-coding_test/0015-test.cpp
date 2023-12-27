#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
//输入一个数字，判断其是否是回文数，就是数字反转看看 是不是和原来一样
//请使用CPU分支预判
int huiWen(int);

int main() {
        int n;
        while(scanf("%d", &n) != EOF) {
                printf("%d\n",huiWen(n));
        }
        return 0;
}

int huiWen(int num) {
        //if(num < 0) return -1;
        if(__builtin_expect(!!(num < 0), 0)) return -1;
        int temp = 0;
        while(num != 0) {
                temp = 10 * temp + (num % 10);
                num /= 10;
        }
        return temp;
}
