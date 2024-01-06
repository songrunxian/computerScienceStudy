#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

//按照固定格式的子函数声明，完成二分查找, 在数组arr里面寻找数字x, 数组长度是n

int binary_search(int *arr, int x, int n);

int main() {
        int n;
        int *arr;
        while ( ~scanf("%d", &n) ) {
                arr = malloc(n*sizeof(int));
                for (int i = 0; i < n; i++) {
                        scanf("%d", &arr[i]);
                }

                int x;
                scanf("%d", &x);
                printf("%d\n", binary_search(arr, x, n));

                for (int i = 0; i < n; i++) {
                        i && printf(" ");
                        printf("%d", arr[i]);
                }
                printf("\n");
        }
        return 0;
}

int binary_search(int *arr, int x, int n) {
        int l = 0, r = n-1;
        while (l <= r) {
                int mid = (l + r) >> 1;
                if( arr[mid] == x ) return mid;
                else if (arr[mid] < x) l = mid + 1;
                else r = mid -1;
        }
        return -1;
}
