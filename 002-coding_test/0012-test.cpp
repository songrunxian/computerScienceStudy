#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

//分支优化练习，登记学生成绩

int main() {
        int n ;
        while( ~scanf("%d", &n) ) {
                if(!n) {
                        printf("FOOLISH\n");
                } else if ( n < 60 ) {
                        printf("FAIL\n");
                } else if ( n < 75 ) {
                        printf("MEDIUM\n");
                } else {
                        printf("GOOD\n");
                }
        }
        return 0;
}
