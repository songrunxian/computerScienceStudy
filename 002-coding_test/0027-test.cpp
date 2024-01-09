#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#define MAX_N 100000

//这是二分典型的 111110000的问题模型

int find_big(int *, int , int);

int main() {
        int m, n;
        //int data1[MAX_N + 5] = {0};
        int *data1;
        scanf("%d%d", &n, &m);
        data1 = malloc(m * sizeof(int));

        for (int i = 0; i < n; i++) {
                scanf("%d", &data1[i]);
        }
        for (int i = 0; i < m; i++) {
                int x;
                scanf("%d", &x);
                i && printf(" ");
                printf("%d", find_big(data1, n, x));
        }
        printf("\n");
        return 0;
}

int find_big(int *data1, int length, int x) {
        int l = 0, r = length-1;
        while (l < r) {
                int mid = (l + r + 1) >> 1;
                if( data1[mid] > x ) r = mid - 1;
                else l = mid ;
                //printf("l = %d; r = %d\n", l, r);
        }
        return data1[l];
}
