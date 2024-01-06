#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

//本例为递归模式的扩展欧几里得

void ex_gcd(int, int, int *, int *);

int main() {
        int a, b , x, y;
        while(~scanf("%d%d", &a, &b)) {
                ex_gcd(a, b, &x, &y);
                printf("%d*%d + %d*%d = %d", a, x, b, y, a*x + b*y);
        }
        return 0;
}

void ex_gcd(int a, int b, int *x, int *y) {
        int xx, yy;
        if(!b) {
                *y = 0;
                *x = 1;
                return ;
        }
        ex_gcd(b, a%b, &xx, &yy);
        *x = yy;
        *y = xx - a / b * yy;
        printf("x = %d, y = %d\n", *x, *y);
}
