#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

//生成5个随机数判断，里面奇数的个数
//使用逻辑运算符去优化，尽量减少if的使用

int main() {
        int cnt = 0;
        srand(time(0)); //设定随机种子，time(0)表示当前时间戳
        for(int i = 0; i < 5; i++) {
                int tmp = rand() % 100; //生成大小在0-99的随机整数
                cnt += (tmp & 1);
                i && printf(" ");
                printf("%d", tmp);
        }
        printf("\n");
        printf("%d\n", cnt);
        return 0;
}
