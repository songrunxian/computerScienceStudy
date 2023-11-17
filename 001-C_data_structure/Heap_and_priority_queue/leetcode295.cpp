/**
 * 双堆求中位数
算法描述：

1、创建两个堆（一个小根堆、一个大根堆），堆大小至少为给定数据个数的一半，向上取整；

2、假定变量mid用来保存中位数，取定第一个元素，赋值给mid，即作为初始的中位数；

3、依次遍历后面的每一个数据，如果比mid小，则插入大根堆；否则插入小根堆；

4、如果大根堆和小根堆上的数据个数相差为2，则将mid插入到元素个数较少的堆中，然后从元素个数较多的堆中删除根节点，并将跟节点赋值给mid；

5、重复步骤3和4，直到所有的数据遍历结束；

此时，mid保存了一个数，再加上两个堆中保存的数，就构成了给定数据的集合。

如果两个堆中元素个数相等，则mid即为最终的中位数；否则，元素较多的堆的根节点元素与mid的和求平均值，即为最终的中位数。
*/
typedef struct Heap {
    int *data;
    int n, size;
} Heap;

//扩大堆的容量
void expandHeap(Heap *h) {
    h->data = realloc(h->data, 2 * h->size * sizeof(int));
    h->size *= 2;
    return ;
}

#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

#define pushHeap(h, val, comp) { \
    if (h->size == h->n + 1) { \
        expandHeap(h); \
    } \
    h->data[++(h->n)] = val; \
    int ind = h->n; \
    while (ind != 1 && h->data[ind] comp h->data[ind >> 1]) { \
        swap(h->data[ind], h->data[ind >> 1]); \
        ind >>= 1; \
    } \
}

#define popHeap(h, comp) do { \
    if (h->n == 0) break; \
    h->data[1] = h->data[(h->n)--]; \
    int ind = 1; \
    while (ind << 1 <= h->n) { \
        int temp = ind, l = ind << 1, r = ind << 1 | 1; \
        if (h->data[l] comp h->data[temp]) temp = l; \
        if (r <= h->n && h->data[r] comp h->data[temp]) temp = r; \
        if (temp == ind) break; \
        swap(h->data[temp], h->data[ind]); \
        ind = temp; \
    } \
} while(0);

Heap *creatHeap() {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->size = 100;
    h->data = (int *)malloc(sizeof(int) * h->size);
    h->n = 0;
    return h;
}

void clearHeap(Heap *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h);
    return ;
}

typedef struct {
    Heap *min_heap, *max_heap;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* m = (MedianFinder*)malloc(sizeof(MedianFinder));
    m->min_heap = creatHeap();
    m->max_heap = creatHeap();
    return m;
}

void medianFinderAddNum(MedianFinder* m, int num) {
    //判断当前元素是否大于等于最小堆的堆顶元素，如果是，则将元素添加到最小堆中，否则将元素添加到最大堆中
    if (m->min_heap->n == 0 || num >= m->min_heap->data[1]) {
        pushHeap(m->min_heap, num, <);
    } else {
        pushHeap(m->max_heap, num, >);
    }
    if (m->min_heap->n - m->max_heap->n == 2) {
        pushHeap(m->max_heap, m->min_heap->data[1], >);
        popHeap(m->min_heap, <);
    }
    if (m->max_heap->n - m->min_heap->n == 2) {
        pushHeap(m->min_heap, m->max_heap->data[1], <);
        popHeap(m->max_heap, >);
    }
    return ;
}

double medianFinderFindMedian(MedianFinder* m) {
    switch (m->min_heap->n - m->max_heap->n) {
        case -1: return m->max_heap->data[1];
        case 0: return 1.0 * (m->min_heap->data[1] + m->max_heap->data[1]) / 2.0;
        case 1: return m->min_heap->data[1];
    }
    return 0.0;
}

void medianFinderFree(MedianFinder* obj) {
    if (obj == NULL) return ;
    clearHeap(obj->min_heap);
    clearHeap(obj->max_heap);
    free(obj);
    return ;
}

