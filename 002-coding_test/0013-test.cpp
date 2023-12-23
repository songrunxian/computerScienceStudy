#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
int main() {
        int n;
        while( ~scanf("%d", &n) ) {
                switch(n) {
                        case 1:
                                printf("one\n");
                                break;
                        case 2:
                                printf("two\n");
                                break;
                        case 3:
                                printf("three\n");
                                break;
                        default:
                                printf("error\n");
                }
        }
        return 0;
}
