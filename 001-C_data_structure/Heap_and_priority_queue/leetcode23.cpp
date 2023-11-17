#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

typedef struct Data {
    struct ListNode *p;
    int ind;
} Data;

typedef struct Heap {
    Data *data;
    int size, n;
} Heap;

Heap *init(int k) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->size = k + 1;
    h->n = 0;
    h->data = (Data *)malloc(sizeof(Data) * (k + 1));
    return h;
}

#define V(x) h->data[x].p->val
#define IND(x) h->data[x].ind

void push(Heap *h, struct ListNode *d, int i) {
    Data data = {d, i};
    h->data[++(h->n)] = data;
    int ind = h->n;
    while (ind != 1 && V(ind) < V(ind >> 1)) {
        swap(h->data[ind], h->data[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

Data top(Heap *h) {
    return h->data[1];
}

int empty(Heap *h) {
    return h->n == 0;
}

void pop(Heap *h) {
    if (empty(h)) return ;
    h->data[1] = h->data[h->n];
    (h->n)--;
    int ind = 1;
    while ((ind << 1) <= h->n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (V(l) < V(temp)) temp = l;
        if (r <= h->n && V(r) < V(temp)) temp = r;
        if (temp == ind) break;
        swap(h->data[temp], h->data[ind]);
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    //函数首先创建一个堆h，并通过init函数进行初始化。然后，使用循环遍历链表数组，将每个链表的头节点插入堆中，并将对应链表的指针后移一位。这样可以将每个链表的头节点按照值的大小进行排序。
    Heap *h = init(listsSize);
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] == NULL) continue;
        push(h, lists[i], i);
        lists[i] = lists[i]->next;
    }

	//接下来，创建一个新的链表ret和指针p，用于存储合并后的结果。然后，进入一个循环，直到堆为空。在每次循环中，从堆中取出堆顶元素d，并将其指向的节点添加到结果链表中。然后，将指针p后移一位，并将其next指针设置为NULL。如果对应链表还有剩余节点，则将下一个节点插入堆中，并将对应链表的指针后移一位。
    struct ListNode ret, *p;
    ret.next = NULL;
    p = &ret;
    while (!empty(h)) {
        Data d = top(h);
        pop(h);
        p->next = d.p;
        p = p->next;
        p->next = NULL;
        if (lists[d.ind]) {
            push(h, lists[d.ind], d.ind);
            lists[d.ind] = lists[d.ind]->next;
        }
    }
    clear(h);
    return ret.next;
}
