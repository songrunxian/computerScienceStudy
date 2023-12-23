#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
//通过位运算判断奇数偶数
int main() {
        int a ;
        scanf("%d", &a);
        if(a % 2 == 1) {
                printf("method1 : a is odd\n");
        }
        if(a & 1 == 1) {
                printf("method2 : a is odd\n");
        }
        return 0;
}
