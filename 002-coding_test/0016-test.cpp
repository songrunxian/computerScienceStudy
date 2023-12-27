#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
//使用&& || 去取缔if,这是一种比较优美的写法
int main() {
        //method1:
        printf("method1:\n");
        for (int i = 0; i < 5; i++) {
                if(i != 0) printf(" ");
                printf("%d", i);
        }
        printf("\n");

        //method2:
        printf("method2:\n");
        for(int i = 0; i < 5; i++) {
                i && printf(" "); //利用了短路
                printf("%d", i);
        }
        printf("\n");

        return 0;
}
