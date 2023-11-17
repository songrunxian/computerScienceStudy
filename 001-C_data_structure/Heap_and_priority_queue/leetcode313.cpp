#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

typedef struct Heap {
    long long *data;
    int n, size;
} Heap;

Heap *init(int n) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->n = 0;
    h->size = n + 1;
    h->data = (long long *)malloc(sizeof(long long) * h->size);
    return h;
}

int empty(Heap *h) {
    return h->n == 0;
}

#define V(x) h->data[x]

void push(Heap *h, long long val) {
    V(++(h->n)) = val;
    int ind = h->n;
    while (ind > 1 && V(ind) < V(ind >> 1)) {
        swap(V(ind), V(ind >> 1));
        ind >>= 1;
    }
    return ;
}

long long top(Heap *h) { return V(1); }

void pop(Heap *h) {
    if (empty(h)) return ;
    V(1) = V((h->n)--);
    int ind = 1;
    while ((ind << 1) <= h->n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (V(l) < V(temp)) temp = l;
        if (r <= h->n && V(r) < V(temp)) temp = r;
        if (temp == ind) break;
        swap(V(temp), V(ind));
        ind = temp;
    }
    return ;
}

void clear(Heap *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h);
    return ;
}

/*
 在寻找超级丑数的过程中使用堆排序是为了保证生成的丑数是按照大小有序的。

超级丑数是由给定的质数数组中的元素相乘得到的，因此在生成超级丑数的过程中，我们需要按照一定规则计算出下一个丑数。堆排序可以帮助我们维护一个有序的丑数序列。

具体来说，我们使用一个堆来存储当前生成的丑数，并保持堆顶元素为最小的丑数。在每次循环中，我们取出堆顶元素作为当前的丑数，并根据质数数组中的元素计算出下一个丑数，并将其插入堆中。这样，堆中的元素始终是按照大小有序的。

使用堆排序的好处是可以高效地找到下一个最小的丑数，并且确保生成的丑数序列是有序的。这样，我们可以在O(nlog(k))的时间复杂度内找到第n个超级丑数，其中n是要找到的超级丑数的位置，k是质数数组的大小。
*/

int nthSuperUglyNumber(int n, int* primes, int primesSize){
    int k = primesSize;
    Heap *h = init(n * primesSize);
    push(h, 1);
    long long ans = 0;
    while (n--) {
        ans = top(h);
        pop(h);
        int i = k - 1;
        for (; i > 0; i--) {
            if (ans % primes[i]) continue;
            break;
        }
        for (int j = i; j < k; j++) {
            push(h, ans * primes[j]);
        }
    }
    clear(h);
    return ans;
}
