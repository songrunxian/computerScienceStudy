#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
        int n ;
        char *str;
        while(scanf("%d",&n) != EOF) {       //EOF是隐藏文件描述符，十进制表示是 -1
                str = (char *)malloc(200 * sizeof(char));
                printf("%d\n", sprintf(str, "%d", n)); //在使用 sprintf 函数之前，需要为 str 分配足够的内存空间,不然str就是一个指针
        }
        return 0;
}
