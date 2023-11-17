#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

typedef struct {
    int *data;
    int cnt, size;
} KthLargest;

//用了一个循环来进行下沉操作，直到满足堆的性质为止。
void downUpdate(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] < arr[temp]) temp = l;
        if (r <= n && arr[r] < arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

//用了一个循环来进行上升操作，直到满足堆的性质为止
void upUpdate(int *arr, int ind) {
    while (ind >> 1) {
        if (arr[ind] >= arr[ind >> 1]) break;
        swap(arr[ind], arr[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

//方法首先判断数据流中的元素数量是否已经达到了KthLargest对象中指定的大小。如果是，则判断当前值是否大于堆顶元素，如果是，则将堆顶元素替换为当前值，并下沉该元素以维护堆的性质。否则，不做任何操作。
//如果数据流中的元素数量还没有达到指定大小，则将当前值添加到堆中，并使用上升操作维护堆的性质。
//我们的目的就是将第val大得元素调整到堆顶
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->cnt == obj->size) {
        if (val > obj->data[1]) {
            obj->data[1] = val;
            downUpdate(obj->data, obj->size, 1);
        }
    } else {
        obj->cnt += 1;
        obj->data[obj->cnt] = val;
        upUpdate(obj->data, obj->cnt);
    }
    return obj->data[1];
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *p = (KthLargest *)malloc(sizeof(KthLargest));
    p->data = (int *)malloc(sizeof(int) * (k + 1));
    p->size = k;
    p->cnt = k - 1;
    memcpy(p->data + 1, nums, sizeof(int) * (k - 1));
    for (int i = (k - 1) >> 1; i >= 1; --i) {
        downUpdate(p->data, k - 1, i);
    }
    for (int i = k - 1; i < numsSize; i++) {
        kthLargestAdd(p, nums[i]);
    }
    return p;
}

void kthLargestFree(KthLargest* obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}
