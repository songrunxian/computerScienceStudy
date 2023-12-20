#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define swap(a,b) { \
        if(&a != &b) { \
                a = a ^ b; \
                b = a ^ b; \
                a = a ^ b; \
        } \
}

/*
 * 宏 和 亦或交换
 * 宏定义中的异或操作交换方法有一个潜在的问题：当您尝试交换两个相同的内存位置时（例如 swap(a, a)），它会将该位置置零，因为任何值与自身异或的结果都是零，
 * 所以取了地址
 */

int main() {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("a = %d, b = %d\n", a, b);
        swap(a,b);
        printf("a = %d, b = %d\n", a, b);
        return 0;
}
