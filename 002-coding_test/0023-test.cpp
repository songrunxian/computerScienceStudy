#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

int gcd(int , int);
int lcm(int , int);

int main () {
        int a, b;
        while ( ~scanf("%d%d", &a, &b)) {
                printf("%d\n", gcd(a, b));
                printf("%d\n", lcm(a, b));
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
//正常情况下的公式是 a * b / gcd(a , b), 这里写的技巧是防止 a * b直接超出界限
int lcm(int a, int b) {
        return a / gcd(a , b) * b;
}
