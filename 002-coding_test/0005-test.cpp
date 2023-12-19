#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main() {
        FILE *fp = fopen("./test.txt", "w"); //w写入创建, 且是FILE, 请尝试将w换成a+ 体会什么是追加
        fprintf(fp, "ip = %d.%d.%d.%d\n", 192,168,1,1);
        fprintf(fp, "fjafjhfeg i\njsjfs;     \n     a\n   a   \n");
        fclose(fp);

        char str[1005];
        int k = 0;
        int temp;
        FILE *fp1 = fopen("./test.txt", "r");
        //读取每行使用的是fgets
        //fgets 是 C 语言中用于从文件中读取一行文本的函数。用法 fgets(buffer, size, file_pointer)，buffer 是存储读取内容的数组，size 是数组的大小，file_pointer 是指向文件的指针
        while(fgets(str, 1005, fp1)) {
                printf("%s", str);      //文件里面有\n。所以输出程序里面就不用添加\n了
        }
        /*
        while(temp = fscanf(fp1, "%[^\n]s", &str) != EOF ) {
                printf("temp = %d\n", temp);
                for(int i = 0; i < 1005; i++) {
                        for(int j = 0; j < 1005; j++) {
                                printf("%s\n", str[i][j]);
                        }
                }
        }*/
        fclose(fp1);
        return 0;
}
