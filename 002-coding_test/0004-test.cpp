#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main() {
        char *str;
        str = malloc(1000 * sizeof(char));
        int num[4] = {0};
        //sprintf(str, "%s.%s.%s.%s", "192", "168", "1", "1");
        sprintf(str, "%d.%d.%d.%d", 192, 168, 1, 1);
        printf("%s\n", str);

        sscanf(str,"%d.%d.%d.%d", &num[0], &num[1], &num[2], &num[3]);
        //注意，一定要添加 “.” 方便后续的分割
        for (int i = 0; i < 4; i++) {
                printf("%d\n", num[i]);
        }

        return 0;
}
