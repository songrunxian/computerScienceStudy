#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

//按照固定格式的子函数声明，完成二分查找, 在数组arr里面寻找数字x, 数组长度是n
//在此基础上进行改进，如下：
//【1】 1111111000000    寻找第一个1
//【2】 0000000111111    寻找最后一个1
//这其实是一个模型，1 当成真，寻找第一个符合条件的相， 和寻找最后一个符合条件的相

int binary_search(int *arr, int x, int n);
//这个函数用来寻找 00000011111中第一个1，通过书写理解虚拟位，和关于二分的取舍
int binary_search1(int *arr, int n);
//这个函数用来寻找 11111100000中最后一个1
int binary_search2(int *arr, int n);

int main() {
        int n;
        int *arr;
        while ( ~scanf("%d", &n) ) {
                arr = malloc(n*sizeof(int));
                for (int i = 0; i < n; i++) {
                        scanf("%d", &arr[i]);
                }

                /*
                int x;
                scanf("%d", &x);
                printf("%d\n", binary_search(arr, x, n));

                for (int i = 0; i < n; i++) {
                        i && printf(" ");
                        printf("%d", arr[i]);
                }
                printf("\n");*/
                //printf("%d\n", binary_search1(arr, n));
                printf("%d\n", binary_search2(arr, n));
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

int binary_search1(int *arr, int n) {
        int l = 0, r = n, mid;
        while (l < r) {
                mid = (l + r) >> 1;
                if ( arr[mid] == 1 ) r = mid ; //这是因为mid可能是结果
                if ( arr[mid] == 0 ) l = mid + 1;
        }
        return (l == n) ? -1 : l;
}

//理解我为什么要上取整
int binary_search2(int *arr, int n) {
        int l = -1, r = n-1, mid;
        while ( l < r ) {
                mid = (l + r + 1) >> 1;
                if( arr[mid] == 1 ) l = mid;
                if( arr[mid] == 0 ) r = mid - 1;
        }
        return (l == -1) ? -1 : l;
}
