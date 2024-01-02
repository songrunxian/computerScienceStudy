#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

int binary_search(int *arr, int x, int l, int r);

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
                printf("%d\n", binary_search(str, m, 0, n-1));
        }

        return 0;
}

int binary_search(int *arr, int x, int l, int r) {
        while (l <= r) {
                int mid = (l+r)>>1;
                if(x == arr[mid]) return 1;
                else if (x < arr[mid]) return binary_search(arr, x, l, mid-1);
                else return binary_search(arr, x, mid+1, r);
        }
        return 0;
}
