#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main() {
        int a;
        char c;
        //这样的操作可能出现失误，请尝试
        //example 1 ：123 a
        //example 2 : 123 [这是123空格]
        scanf("%d%c", &a, &c);
        printf("%d\n%c\n", a, c);
        return 0;
}
