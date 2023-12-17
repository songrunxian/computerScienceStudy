#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main() {
        char str1[1000];
        char *str2;
        while(scanf("%[^\n]s", &str1) != EOF) {   //如果像输入空格，那么就要利用正则表达式
                getchar(); //请理解为什么需要使用这个函数，从而体会输入数据流的原理，以及哨兵指针
                str2 = (char *)malloc(10000*sizeof(char));
                /*
                printf("%d\n", sprintf(str2, "%s", str1)); // %s可以读入1行，但是 空格 \n \t 会当成分隔符   %c可以读入所有字符但是容易失误操作
                */
                printf("%d\n", sprintf(str2, "%s", str1));
        }
        return 0;
}
