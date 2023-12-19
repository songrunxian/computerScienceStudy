#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main() {
        int n;
        while(~scanf("%d", &n)) { //这是循环读入的第二种经典写法
                //scanf("%d", &n) != EOF  是第一种写法，EOF是 -1，所以我们从-1的这个角度进行理解：
                //-1在64位操作系统中用二进制表示为32个1；
                //32个1 按位取反 就是0
                //因此当while遇见所谓的EOF -1 时候 就等价于遇见判断条件 0，因此自动退出
                printf("%d\n", n);
        }
        return 0;
}
