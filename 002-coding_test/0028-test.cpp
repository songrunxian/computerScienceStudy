#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

//使用二分去手动模拟实现math库里面的sqrt函数

double my_sqrt(double);

int main() {
        double x;
        while(scanf("%lf", &x) != EOF) {
                printf("my_sqrt is : %lf\n", my_sqrt(x));
                printf("math_sqrt is : %lf\n", sqrt(x));
        }
        return 0;
}

double my_sqrt (double x) {
        double l = 0, r = x, mid;
        #define EPLS 1e-6
        while (r - l > EPLS) {
                mid = (r + l) / 2.0;
                if (mid * mid < x) l = mid;
                else r = mid;
        }
        #undef EPLS
        mid = (l + x) / 2.0;
        return l;
}
