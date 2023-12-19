#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
/*
 重新理解fscanf fprintf 这次我们不再使用getchar(),改用fgetc()
 */
int main() {

        FILE *fp = fopen("./test.txt", "w");
        fprintf(fp, "\nip=123.7.8.9\nhhsfheufhuhgb\t]tdjfhsfeu\t\t1\n\n111\n");
        fclose(fp);

        char str[10005][10005];
        int k = 0;
        FILE *fp1 = fopen("./test.txt", "r");
        while( fscanf(fp1, "%[^\n]s", &str[k++]) != EOF ) {
                fgetc(fp1); //是一个C语言函数，用于从指定的文件中读取一个字符。fp1 是一个文件指针，指向要读取的文件。
        }
        for (int i = 0; i < k;i++) {
                printf("%s\n", str[i]);
        }
        fclose(fp1);

        char str1[100005];
        FILE *fp2 = fopen("./test.txt", "r");
        while( ~fscanf(fp2, "%c", &str1[k++])) ; //注意这么需要循环输入
        printf("%s\n", str1);
        fclose(fp2);

        return 0;
}
