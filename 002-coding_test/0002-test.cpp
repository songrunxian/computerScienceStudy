#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main() {
        char str1[1000];
        char *str2;
        while(scanf("%s", &str1)) {
                str2 = (char *)malloc(10000*sizeof(char));
                printf("%d\n", sprintf(str2, "%s", str1));
        }
        return 0;
}
