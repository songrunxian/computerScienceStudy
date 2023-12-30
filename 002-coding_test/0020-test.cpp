#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

int binary_search(int *arr, int x, int n);

int main() {
        int n;
        scanf("%d", &n);
        int *str = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
                scanf("%d", &str[i]);
        }

        for (int i = 0; i < n; i++) {
                i && printf(" ");
                printf("%d", str[i]);
        }
        printf("\n");

        int m;
        while ( ~scanf("%d", &m) ) {
                printf("%d\n", binary_search(str, m, n));
        }

        return 0;
}

int binary_search(int *arr, int x, int n) {
        int l = 0, r = n-1;
        int mid = (l+r)>>1;
        while(l <= r) {
//              printf("%d %d %d\n", l, r, mid);
                if (arr[mid] == x) return 1;
                else if (arr[mid] > x ) {
                        r = mid - 1;
                        mid = (l+r) >> 1;
                } else {
                        l = mid + 1;
                        mid = (l+r) >> 1;
                }
        }
        return 0;
}
