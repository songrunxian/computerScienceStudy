#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

//一个简单的堆调整过程
void downUpdate(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {	//如果该位置下标*2 还在这个数组范围内
        int temp = ind, l = ind << 1, r = ind << 1 | 1; //设定左右孩子
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    //通过 arr -= 1; 这一操作，将指针向前移动了一位，使得数组的第一个元素可以通过 arr[1] 访问到。这样就符合了堆排序算法对数组下标的要求。
    arr -= 1;	//满足堆的形式，让首ind为1
    for (int i = n >> 1; i >= 1; i--) {	//首先，通过循环调用 downUpdate 函数，从最后一个非叶子节点开始，逐个向上构建一个大顶堆。
        downUpdate(arr, n, i);
    }
    //通过循环将堆顶元素与当前未排序部分的最后一个元素交换，并调用 downUpdate 函数对剩余部分进行调整，直到所有元素都被排序
    for (int i = n; i > 1; i--) {	
        swap(arr[i], arr[1]);
        downUpdate(arr, i - 1, 1);
    }
    return ;
}

void output(int *arr, int n) {
    printf("arr(%d) = [", n);
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    int *arr = (int *)malloc(sizeof(int) * max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        arr[i] = val;
    }
    output(arr, max_op);
    heap_sort(arr, max_op);
    output(arr, max_op);
    free(arr);
    return 0;
}
