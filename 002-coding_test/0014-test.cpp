#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

int check(int y, int m, int d) {
        if(m < 1 || d < 1) return 0;
        if(m > 12 || d > 31) return 0;
        int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if((y % 4 == 0 && y % 100) || y % 400 == 0) month[2] += 1;
        return d <= month[m];
}

int main() {
        int y, m, d;
        while(~scanf("%d%d%d", &y, &m, &d)) {
                printf("%s\n", check(y,m,d)? "right":"wrong");
        }
        return 0;
}
