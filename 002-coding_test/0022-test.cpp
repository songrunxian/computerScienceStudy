#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

int gcd(int , int);

int main () {
        int a, b;
        while ( ~scanf("%d%d", &a, &b)) {
                printf("%d\n", gcd(a, b));
        }
        return 0;
}

/*
int gcd (int a, int b) {
        if(a < 0 || b < 0 ) return -1;
        if( b == 0 ) return a;
        else return gcd(b, a%b);
}*/
// gcd 代码优化
int gcd (int a, int b) {
        if( a < 0 || b < 0 ) return -1;
        return (b ? gcd(b, a%b): a);
}
