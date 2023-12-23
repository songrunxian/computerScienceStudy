#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define swap(a, b) { \
        __typeof(a) __temp = a; \
        a = b; \
        b = __temp; \
}

int main() {
        int a, b;
        scanf("%d%d", &a, &b);
        swap(a,b);
        printf("a = %d, b = %d\n", a, b);
        return 0;
}
